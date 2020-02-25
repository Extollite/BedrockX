#include"pch.h"
#include"api/MC.h"

template<class T>
LIGHTBASE_API T* LocateS<T>::_srv;

THook(void,"?initAsDedicatedServer@Minecraft@@QEAAXXZ",Minecraft* mc) {
	LocateS<Minecraft>::assign(*mc);
	printf("MC %p\n", mc);
	original(mc);
}
THook(void, "?startServerThread@ServerInstance@@QEAAXXZ", void* a) {
	original(a);
	LocateS<Level>::assign(*LocateS<Minecraft>()->getLevel());
	LocateS<ServerNetworkHandler>::assign(*LocateS<Minecraft>()->getServerNetworkHandler());
	printf("level %p neth %p\n",LocateS<Level>()._srv, LocateS<ServerNetworkHandler>()._srv);
	ServerStartedEvent::_call();
}
THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVSetLocalPlayerAsInitializedPacket@@@Z", ServerNetworkHandler& thi, NetworkIdentifier const& b, unsigned char* pk) {
	original(thi, b, pk);
	ServerPlayer* sp = thi._getServerPlayer(b, pk[16]);
	if(sp)
	PlayerJoinEvent::_call(*sp);
}