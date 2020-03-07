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
struct ITaskBase {
	tick_t schedule_time;
	tick_t interval;
	taskid_t taskid;
	function<void(void)> cb;
	ITaskBase(function<void(void)>&& fn, tick_t time_diff, tick_t interval, taskid_t tid) : schedule_time(ticknow + time_diff), interval(interval), taskid(tid), cb(std::move(fn)) {}
};
struct DelayedTask:ITaskBase {
	DelayedTask(function<void(void)>&& fn, tick_t time_diff) : ITaskBase(std::move(fn),time_diff,0,++gtaskid) {}
};
struct RepeatingTask : ITaskBase {
	RepeatingTask(function<void(void)>&& fn, tick_t interval) : ITaskBase(std::move(fn), 0, interval, ++gtaskid) {}
};
struct DelayedRepeatingTask : ITaskBase {
	DelayedRepeatingTask(function<void(void)>&& fn, tick_t time_diff, tick_t interval) : ITaskBase(std::move(fn), time_diff, interval, ++gtaskid) {}
};
#ifdef LIGHTBASE_EXPORTS
struct MainHandler {
	LIGHTBASE_API bool cancel(taskid_t id);
	bool __cancel(taskid_t id);
	LIGHTBASE_API taskid_t schedule(ITaskBase&& task);
	taskid_t __schedule(ITaskBase&& task);
	void tick();
	MainHandler();
};
#else
struct MainHandler {
	LIGHTBASE_API bool cancel(taskid_t id);
	LIGHTBASE_API taskid_t schedule(ITaskBase&& task);
};
#endif