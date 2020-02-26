#pragma once
#include "../serviceLocate.h"
#include <api/lightbase.h>
#include <map>
#include <functional>
#include <mutex>
using std::function;
typedef unsigned long long tick_t;
typedef unsigned int taskid_t;
extern LIGHTBASE_API tick_t ticknow;
extern LIGHTBASE_API taskid_t gtaskid;
struct DelayedTask {
	tick_t exec_time;
	taskid_t taskid;
	function<void(void)> cb;
	DelayedTask(function<void(void)>&& fn, tick_t time_diff) : cb(std::forward<function<void(void)>>(fn)) {
		taskid = ++gtaskid;
		exec_time = ticknow + time_diff;
	}
};
#ifdef LIGHTBASE_EXPORTS
struct MainHandler {
	std::multimap<tick_t, DelayedTask> tasks;
	std::mutex _lock;
	LIGHTBASE_API bool cancel(taskid_t id);
	LIGHTBASE_API void schedule(DelayedTask&& task);
	void tick();
	MainHandler();
};
#else
struct MainHandler {
	LIGHTBASE_API bool cancel(taskid_t id);
	LIGHTBASE_API void schedule(DelayedTask&& task);
}

#endif