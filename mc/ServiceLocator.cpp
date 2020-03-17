#include "pch.h"
#include "api/MC.h"

template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", Minecraft* mc) {
	LocateS<Minecraft>::assign(*mc);
	printf("MC %p\n", mc);
	original(mc);
}
static WLevel lvl(*(ServerLevel*)NULL);
THook(void, "?startServerThread@ServerInstance@@QEAAXXZ", void* a) {
	original(a);
	LocateS<Level>::assign(*LocateS<Minecraft>()->getLevel());
	lvl.v = ((ServerLevel*)(LocateS<Minecraft>()->getLevel()));
	LocateS<ServerLevel>::assign(*(ServerLevel*)LocateS<Minecraft>()->getLevel());
	LocateS<WLevel>::assign(lvl);
	LocateS<ServerNetworkHandler>::assign(*LocateS<Minecraft>()->getServerNetworkHandler());
	printf("level %p neth %p\n", LocateS<Level>()._srv, LocateS<ServerNetworkHandler>()._srv);
	ServerStartedEvent::_call();
	ServerStartedEvent::_removeall();
}
THook(void, "?initCoreEnums@MinecraftCommands@@QEAAX_NAEBVBaseGameVersion@@@Z", MinecraftCommands* a0, void* a1, void* a2) {
	original(a0, a1, a2);
	LocateS<MinecraftCommands>::assign(*a0);
}

THook(void, "??0DBStorage@@QEAA@UConfig@0@@Z", LevelStorage* a, void* b) {
	LocateS<LevelStorage>::assign(*a);
	printf("levelstorage %p\n", LocateS<LevelStorage>()._srv);
	original(a, b);
}
THook(void*, "??0ChunkSource@@QEAA@V?$unique_ptr@VChunkSource@@U?$default_delete@VChunkSource@@@std@@@std@@@Z", ChunkSource* a1, void** a2) {
	LocateS<ChunkSource>::assign(*a1);
	return original(a1, a2);
}
THook(void*, "?update@RakNetServerLocator@@QEAAXXZ", RakNetServerLocator* thi) {
	LocateS<RakNetServerLocator>::assign(*thi);
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