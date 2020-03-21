#include <lbpch.h>
#include<api\event\event_pch.h>
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

EXPORT_EVENT(RegisterCommandEvent);

EXPORT_EVENT(ServerStartedEvent);
EXPORT_EVENT(PostInitEvent);


EXPORT_EVENT(MobDeathEvent);
EXPORT_EVENT(MobHurtedEvent);
EXPORT_EVENT(LevelExplodeEvent);

static struct exec_now {
	exec_now() {
		addListener([](ServerStartedEvent&) {
#define OPTIMIZE_EVENT(x) x::_cleanup();
			OPTIMIZE_EVENT(PlayerPreJoinEvent);
			OPTIMIZE_EVENT(PlayerJoinEvent);
			OPTIMIZE_EVENT(PlayerLeftEvent);
			OPTIMIZE_EVENT(PlayerChatEvent);
			OPTIMIZE_EVENT(PlayerCMDEvent);
			OPTIMIZE_EVENT(PlayerDestroyEvent);
			OPTIMIZE_EVENT(PlayerUseItemOnEvent);
			OPTIMIZE_EVENT(PlayerUseItemOnEntityEvent);
			OPTIMIZE_EVENT(PlayerUseItemEvent);

			OPTIMIZE_EVENT(RegisterCommandEvent);

			OPTIMIZE_EVENT(MobDeathEvent);
			OPTIMIZE_EVENT(MobHurtedEvent);
			OPTIMIZE_EVENT(LevelExplodeEvent);
		});
	}
} __exec_now;
