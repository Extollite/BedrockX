#include<lbpch.h>
#include <thread>
#include <deque>
#include <atomic>
#include <map>
#include <mutex>
#include<api\scheduler\scheduler.h>
using std::function;
namespace Handler {
	LIGHTBASE_API tick_t ticknow;
	LIGHTBASE_API taskid_t gtaskid;
	static int mainid;
	static tick_t _tick;
	static std::multimap<tick_t, ITaskBase> tasks;
	static std::deque<function<void()>> next_run;
	static std::atomic<int> cas;
	static std::atomic<bool> cas_nextrun;
	static int zero = 0;
	inline static int getTID() {
		auto tid = std::this_thread::get_id();
		return *(int*)&tid;
	}
	static void Init() {
		mainid = getTID();
		static_assert(cas.is_always_lock_free);
	}
	static inline bool __cancel(taskid_t id) {
		for (auto it = tasks.begin(); it != tasks.end(); ++it) {
			if (it->second.taskid == id) {
				tasks.erase(it);
				return true;
			}
		}
		return false;
	}
	LIGHTBASE_API bool cancel(taskid_t id) {
		int myid = getTID();

		if (myid == mainid && cas.load() == mainid) {
			return __cancel(id);
		}
		while (!cas.compare_exchange_weak(zero, myid))
			;
		auto rv = __cancel(id);
		cas.store(0);
		return rv;
	}
	inline static taskid_t __schedule(ITaskBase&& task) {
		auto id = task.taskid;
		tasks.emplace(task.schedule_time, std::forward<ITaskBase>(task));
		return id;
	}
	LBAPI taskid_t schedule(ITaskBase&& task) {
		int myid = getTID();
		if (myid == mainid && cas.load() == mainid) {
			return __schedule(std::forward<ITaskBase>(task));
		}
		while (!cas.compare_exchange_weak(zero, myid))
			;
		auto rv = __schedule(std::forward<ITaskBase>(task));
		cas.store(0);
		return rv;
	}
	LBAPI void scheduleNext(function<void()>&& fn) {
		bool lck = false;
		while (!cas_nextrun.compare_exchange_weak(lck, true))
			;
		next_run.emplace_back(std::forward<function<void()>>(fn));
		cas_nextrun.store(false);
	}
	inline static void nextrun() {
		bool lck = false;
		while (!cas_nextrun.compare_exchange_weak(lck, true))
			;
		while (!next_run.empty()) {
			try {
				next_run.front()();
			}
			catch (std::exception e) {
				printf("[Scheduler] exception when nextTask %s\n", e.what());
			}
			catch (...) {
				printf("[Scheduler] exception when nextTask\n");
			}
			next_run.pop_front();
		}
		cas_nextrun.store(false);
	}
	inline static void tick() {
		nextrun();
		_tick++;
		if (_tick % 10 != 0)
			return;
		ticknow++;
		int myid = getTID();
		bool locked = false;
		if (myid == mainid && cas.load() == mainid) {
		}
		else {
			while (!cas.compare_exchange_weak(zero, myid))
				;
			locked = true;
		}
		auto it = tasks.begin();
		auto end = tasks.end();
		for (; it != end;) {
			if (ticknow >= it->first) {
				try {
					it->second.cb();
				}
				catch (std::exception e) {
					printf("[Scheduler] exception when runTask %s\n", e.what());
				}
				catch (...) {
					printf("[Scheduler] exception when runTask\n");
				}
				if (it->second.interval != 0) {
					it->second.schedule_time = ticknow + it->second.interval;
					tasks.emplace(it->second.schedule_time, std::move(it->second));
				}
				tasks.erase(it++);
			}
			else {
				break;
			}
			if (locked)
				cas.store(0);
		}
	}
}
static bool inited = false;
THook(void, "?tick@Level@@UEAAXXZ", class Level* lv) {
	if (!inited)
		Handler::Init(), inited = true;
	original(lv);
	Handler::tick();
}