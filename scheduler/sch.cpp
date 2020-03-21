#include<lbpch.h>
#include <thread>
#include <deque>
#include <atomic>
#include <map>
#include <mutex>
#include<api\scheduler\scheduler.h>
using std::function;
template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;
static int zero = 0;
static MainHandler mh;
LIGHTBASE_API tick_t ticknow;
LIGHTBASE_API taskid_t gtaskid;
inline static int getTID() {
	auto tid = std::this_thread::get_id();
	return *(int*)&tid;
}
static int mainid;
static tick_t _tick;
static std::multimap<tick_t, ITaskBase> tasks;
static std::deque<function<void()>> next_run;
static std::atomic<int> cas;
static std::atomic<bool> cas_nextrun;
MainHandler::MainHandler() {
	LocateS<MainHandler>::assign(*this);
	mainid = getTID();
	static_assert(cas.is_always_lock_free);
}
LIGHTBASE_API bool MainHandler::cancel(taskid_t id) {
	int myid=getTID();
	
	if (myid == mainid && cas.load() == mainid) {
		return __cancel(id);
	}
	while (!cas.compare_exchange_weak(zero, myid))
		;
	auto rv = __cancel(id);
	cas.store(0);
	return rv;
}
bool MainHandler::__cancel(taskid_t id) {
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		if (it->second.taskid == id) {
			tasks.erase(it);
			return true;
		}
	}
	return false;
}
LBAPI taskid_t MainHandler::schedule(ITaskBase&& task) {
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
taskid_t MainHandler::__schedule(ITaskBase&& task) {
	auto id = task.taskid;
	tasks.emplace(task.schedule_time, std::forward<ITaskBase>(task));
	return id;
}
LBAPI void MainHandler::scheduleNext(function<void()>&& fn) {
	bool lck = false;
	while (!cas_nextrun.compare_exchange_weak(lck, true))
		;
	next_run.emplace_back(std::forward<function<void()>>(fn));
	cas_nextrun.store(false);
}
void MainHandler::nextrun() {
	bool lck = false;
	while (!cas_nextrun.compare_exchange_weak(lck, true))
		;
	while (!next_run.empty()) {
		next_run.front()();
		next_run.pop_front();
	}
	cas_nextrun.store(false);
}
void MainHandler::tick() {
	nextrun();
	_tick++;
	if (_tick % 10 != 0)
		return;
	ticknow++;
	int myid=getTID();
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
	for (;it!=end;) {
		if (ticknow >= it->first) {
			it->second.cb();
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
THook(void, "?tick@Level@@UEAAXXZ", class Level* lv) {
	original(lv);
	mh.tick();
}