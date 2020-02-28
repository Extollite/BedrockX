#include "pch.h"

template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;

static MainHandler mh;
LIGHTBASE_API tick_t ticknow;
LIGHTBASE_API taskid_t gtaskid;
static tick_t _tick;
MainHandler::MainHandler() {
	LocateS<MainHandler>::assign(*this);
}
LIGHTBASE_API bool MainHandler::cancel(taskid_t id) {
	std::lock_guard<std::mutex> lck(_lock);
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		if (it->second.taskid == id) {
			tasks.erase(it);
			return true;
		}
	}
	return false;
}
LIGHTBASE_API void MainHandler::schedule(DelayedTask&& task) {
	task.schedule_time = ticknow;
	std::lock_guard<std::mutex> lck(_lock);
	tasks.emplace(task.schedule_time + task.time, std::forward<DelayedTask>(task));
}
void MainHandler::tick() {
	_tick++;
	if (_tick % 10 != 0)
		return;
	ticknow++;
	std::lock_guard<std::mutex> lck(_lock);
	auto it = tasks.begin();
	auto end = tasks.end();
	for (; it != end;) {
		if (ticknow >= it->first) {
			it->second.cb();
			if (it->second.repeat) {
				it->second.schedule_time = ticknow;
				tasks.emplace(it->second.schedule_time + it->second.time, std::move(it->second));
			}
			tasks.erase(it++);
		}
		else {
			break;
		}
	}
}
THook(void, "?tick@Level@@UEAAXXZ", Level* lv) {
	original(lv);
	mh.tick();
}