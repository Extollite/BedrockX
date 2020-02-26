#include "pch.h"
static MainHandler mh;
LIGHTBASE_API tick_t ticknow;
LIGHTBASE_API taskid_t gtaskid;
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
	std::lock_guard<std::mutex> lck(_lock);
	tasks.emplace(task.exec_time, std::forward<DelayedTask>(task));
}
void MainHandler::tick() {
	ticknow++;
	std::lock_guard<std::mutex> lck(_lock);
	auto it = tasks.begin();
	auto end = tasks.end();
	for (; it != end;) {
		if (ticknow >= it->second.exec_time) {
			it->second.cb();
			tasks.erase(it++);
		}
		else {
			break;
		}
	}
}
THook(void, "?tick@Level@@UEAAXXZ", Level* lv) {
	mh.tick();
	original(lv);
}