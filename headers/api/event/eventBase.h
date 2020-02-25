#pragma once
#include<api_pch.h>
#include<variant>
#include<api/types/types.h>
using std::string, std::function,std::variant;
enum EvPrio:int
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
	CallBackStorage(function<void(T&)>&& fun,LInfo<T> lf):id(lf) {
		data = std::move(fun);
	}
};
template<class T>
class EventCaller {
	LIGHTBASE_API static std::list<CallBackStorage<T>> listener;
public:
	template<typename... P>
	static auto _call(P&&... args) {
		T ev(std::forward<P>(args)...);
		for (auto& i : EventCaller<T>::listener) {
				i(ev);
				if (ev.isAborted()) break;
			}
		if constexpr (std::is_base_of<ICancellableEvent, T>())
			return !ev.isCancelled();
		else
			return;
	}
	static LInfo<T> _reg(function<void(T&)>&& cb, EvPrio prio) {
		LInfo<T> lf;
		lf.id = newListenerID();
		if (prio == HIGH) {
			listener.emplace_front(std::move(cb),lf);
			return lf;
		}
		if (prio == LOW) {
			listener.emplace_back(std::move(cb), lf);
			return lf;
		}
		for (auto it = listener.begin(); it != listener.end(); ++it) {
			if (!(*it)) {
				//flag
				listener.emplace(it, std::move(cb), lf);
			}
		}
		return lf;
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
class INotifyEvent :public IEventBase<T> {};
template<class T>
class INotifyPlayerEvent :public INotifyEvent<T>, public IPlayerEvent {
public:
	INotifyPlayerEvent(ServerPlayer& sp) :IPlayerEvent(sp) {}
};

template<class T>
LInfo<T> addListener(function<void(T&)>&& fn, EvPrio prio = MEDUIM) {
	return T::_reg(std::move(fn), prio);
}
template<class T>
void removeListener(LInfo<T> lf) {
	T::_remove(lf);
}

template<typename T>
auto addListener(T const& x, EvPrio prio = MEDUIM) {
	return addListener(function(x),prio);
}