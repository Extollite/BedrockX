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
