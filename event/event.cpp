#include "pch.h"
static int LID;
LIGHTBASE_API int newListenerID() {
	return ++LID;
}
#define EXPORT_EVENT(T) \
template<> \
	LIGHTBASE_API std::list<CallBackStorage<T>> EventCaller<T>::listener = { {} }
EXPORT_EVENT(PlayerPreJoinEvent);
EXPORT_EVENT(PlayerJoinEvent);
EXPORT_EVENT(PlayerLeftEvent);
EXPORT_EVENT(PlayerChatEvent);
EXPORT_EVENT(PlayerCMDEvent);
EXPORT_EVENT(PlayerDestroyEvent);
EXPORT_EVENT(PlayerUseItemOnEvent);
EXPORT_EVENT(PlayerUseItemOnEntityEvent);
EXPORT_EVENT(PlayerUseItemEvent);

EXPORT_EVENT(ServerStartedEvent);
EXPORT_EVENT(PostInitEvent);


EXPORT_EVENT(MobDeathEvent);
EXPORT_EVENT(ActorHurtedEvent);
EXPORT_EVENT(LevelExplodeEvent);

static struct exec_now {
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
