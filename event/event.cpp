#include"pch.h"
static int LID;
LIGHTBASE_API int newListenerID() {
	return ++LID;
}
//template<class T>
#define EXPORT_EVENT(T) \
LIGHTBASE_API std::list<CallBackStorage<T>> EventCaller<T>::listener={{}}
EXPORT_EVENT(PlayerJoinEvent);
EXPORT_EVENT(PlayerLeftEvent);
EXPORT_EVENT(PlayerChatEvent);
EXPORT_EVENT(PlayerDestroyEvent);
EXPORT_EVENT(PlayerUseItemOnEvent);
EXPORT_EVENT(ServerStartedEvent);
EXPORT_EVENT(PostInitEvent);
static struct exec_now{
	exec_now() {
		addListener([](PostInitEvent&) {
			#define OPTIMIZE_EVENT(x) x::_cleanup();
			OPTIMIZE_EVENT(PlayerJoinEvent);
			OPTIMIZE_EVENT(PlayerLeftEvent);
			OPTIMIZE_EVENT(PlayerChatEvent);
			OPTIMIZE_EVENT(PlayerDestroyEvent);
			OPTIMIZE_EVENT(PlayerUseItemOnEvent);
			OPTIMIZE_EVENT(ServerStartedEvent);
			});
	}
} __exec_now;
