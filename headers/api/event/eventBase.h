#pragma once
#include<lbpch.h>
#include<variant>
#include<api/types/types.h>
using std::string, std::function,std::variant;
enum class EvPrio:int
{
	LOW = 0,
	MEDUIM = 1,
	HIGH = 2
};
LIGHTBASE_API int newListenerID();
template<typename T>
struct LInfo {
	int id=-1;
};
class ICancellableEvent {
	bool cancelled;
public:
	bool isCancelled() {
		return cancelled;
	}
	operator bool() {
		return !isCancelled();
	}
	void setCancelled(bool c = true) {
		cancelled = c;
	}
	ICancellableEvent() :cancelled(false) {}
};
template<class T>
struct CallBackStorage {
	variant<int, function<void(T&)>> data;
	LInfo<T> id;
	operator bool() {
		return data.index()==1;
	}
	void operator()(T& arg) {
		if (data.index() == 1) {
			std::get<function<void(T&)>>(data)(arg);
		}
	}
	CallBackStorage() {
		data = 1;
	}
	CallBackStorage(function<void(T&)>&& fun,LInfo<T> lf):data(std::forward< function<void(T&)>>(fun)),id(lf) {
	}
};
template<class T>
class EventCaller {
	LIGHTBASE_API static std::list<CallBackStorage<T>> listener;
public:
	template<typename... P>
	static auto _call(P&&... args) {
		//printf("call event %s\n", typeid(T).name());
		T ev(std::forward<P>(args)...);
			for (auto& i : EventCaller<T>::listener) {
				try {
					i(ev);
				}
				catch (std::exception e) {
					printf("error [%s] in event %s\n", e.what(), typeid(T).name());
				}
				catch (string e) {
					printf("error [%s] in event %s\n", e.c_str(), typeid(T).name());
				}
				catch (...) {
					printf("error [unknow error] in event %s\n", typeid(T).name());
				}
				if (ev.isAborted()) break;
			}
		if constexpr (std::is_base_of<ICancellableEvent, T>())
			return !ev.isCancelled();
		else
			return;
	}
	static void _removeall() {
		listener.clear();
	}
	static LInfo<T> _reg(function<void(T&)>&& cb, EvPrio prio) {
		LInfo<T> lf;
		lf.id = newListenerID();
		if (prio == EvPrio::HIGH) {
			listener.emplace_front(std::forward< function<void(T&)>>(cb),lf);
			return lf;
		}
		if (prio == EvPrio::LOW) {
			listener.emplace_back(std::forward< function<void(T&)>>(cb), lf);
			return lf;
		}
		for (auto it = listener.begin(); it != listener.end(); ++it) {
			if (!(*it)) {
				//flag
				listener.emplace(it, std::forward<function<void(T&)>>(cb), lf);
				return lf;
			}
		}
		return { -1 };
	}
	static auto _remove(LInfo<T> lf) {
		return listener.remove_if([lf](auto& elem)->bool {return elem.id.id == lf.id; });
	}
	static void _cleanup() {
		listener.remove_if([](auto& elem)->bool {return !elem; });
	}
};

class IAbortableEvent {
	bool aborted;
public:
	void setAborted(bool c = true) {
		aborted = c;
	}
	bool isAborted() {
		return aborted;
	}
	IAbortableEvent() :aborted(false) {}
};
class ServerPlayer;
class IPlayerEvent {
	WPlayer sp;
public:
	WPlayer getPlayer() {
		return sp;
	}
	IPlayerEvent(ServerPlayer& s) :sp(s) {}
};
class IActorEvent {
	WActor sp;

public:
	WActor getActor() {
		return sp;
	}
	IActorEvent(Actor& s) : sp(s) {}
};
class IMobEvent {
	WMob sp;

public:
	WMob getMob() {
		return sp;
	}
	IMobEvent(Mob& s) : sp(s) {}
};
template<typename T>
class IEventBase :public EventCaller<T>, public IAbortableEvent {

};
template<class T>
class IGenericEvent :public IEventBase<T>, public ICancellableEvent {};
template<class T>
class IGenericPlayerEvent :public IGenericEvent<T>, public IPlayerEvent {
public:
	IGenericPlayerEvent(ServerPlayer& sp) :IPlayerEvent(sp) {}
};

template<class T>
class IGenericActorEvent : public IGenericEvent<T>, public IActorEvent {
public:
	IGenericActorEvent(Actor& sp) : IActorEvent(sp) {}
};

template<class T>
class INotifyEvent :public IEventBase<T> {};
template<class T>
class INotifyPlayerEvent :public INotifyEvent<T>, public IPlayerEvent {
public:
	INotifyPlayerEvent(ServerPlayer& sp) :IPlayerEvent(sp) {}
};


template<class T>
LInfo<T> addListener(function<void(T&)>&& fn, EvPrio prio = EvPrio::MEDUIM) {
	return T::_reg(std::forward<function<void(T&)>>(fn), prio);
}
template<class T>
void removeListener(LInfo<T> lf) {
	T::_remove(lf);
}
template<typename T>
auto addListener(T&& fn, EvPrio prio = EvPrio::MEDUIM) {
	return addListener(function(std::forward<T>(fn)), prio);
}