#include<lbpch.h>
#include "api/MC.h"
#include<api/types/types.h>
#include<api/event/genericEvent.h>
#include<api/serviceLocate.h>
template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", Minecraft* mc) {
	LocateS<Minecraft>::assign(*mc);
	original(mc);
}
static WLevel wl;
THook(void, "?startServerThread@ServerInstance@@QEAAXXZ", void* a) {
	original(a);
	LocateS<Level>::assign(*LocateS<Minecraft>()->getLevel());
	wl.v = (ServerLevel*)LocateS<Minecraft>()->getLevel();
	LocateS<ServerLevel>::assign(*(ServerLevel*)LocateS<Minecraft>()->getLevel());
	LocateS<WLevel>::assign(wl);
	LocateS<ServerNetworkHandler>::assign(*LocateS<Minecraft>()->getServerNetworkHandler());
	ServerStartedEvent::_call();
	ServerStartedEvent::_removeall();
}
THook(void, "?initCoreEnums@MinecraftCommands@@QEAAX_NAEBVBaseGameVersion@@@Z", MinecraftCommands* a0, void* a1, void* a2) {
	original(a0, a1, a2);
	LocateS<MinecraftCommands>::assign(*a0);
}

THook(void*, "?loadServerPlayerData@LevelStorage@@QEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBVPlayer@@_N@Z", LevelStorage* a, void* b,void* c,void* d) {
	static bool inited = false;
	if (!inited)
		LocateS<LevelStorage>::assign(*a), inited = true;
	return original(a, b,c,d);
}
#if 0
THook(void*, "??0ChunkSource@@QEAA@V?$unique_ptr@VChunkSource@@U?$default_delete@VChunkSource@@@std@@@std@@@Z", ChunkSource* a1, void** a2) {
	LocateS<ChunkSource>::assign(*a1);
	return original(a1, a2);
}
#endif
THook(void*, "?activate@RakNetServerLocator@@AEAAXXZ", RakNetServerLocator* thi) {
	static bool inited = false;
	if (!inited)
		LocateS<RakNetServerLocator>::assign(*thi),inited=true;
	return original(thi);
}

THook(void*, "??0RakPeer@RakNet@@QEAA@XZ", RakPeer_t* p) {
	static bool inited = false;
	if (!inited) {
		inited = 1;
		LocateS<RakPeer_t>::assign(*p);
	}
	return original(p);
}