#include "pch.h"
#include "api/MC.h"

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
	printf("%p %p\n", lvl.v, LocateS<Minecraft>()->getLevel());
	LocateS<WLevel>::assign(lvl);
	LocateS<ServerNetworkHandler>::assign(*LocateS<Minecraft>()->getServerNetworkHandler());
	printf("level %p neth %p\n", LocateS<Level>()._srv, LocateS<ServerNetworkHandler>()._srv);
	ServerStartedEvent::_call();
	ServerStartedEvent::_removeall();
}
THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVSetLocalPlayerAsInitializedPacket@@@Z", ServerNetworkHandler& thi, NetworkIdentifier const& b, unsigned char* pk) {
	original(thi, b, pk);
	ServerPlayer* sp = thi._getServerPlayer(b, pk[16]);
	if (sp)
		PlayerJoinEvent::_call(*sp);
}