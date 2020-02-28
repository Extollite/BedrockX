#pragma once
#include"Loader.h"
#include"lightbase.h"
/*class Level {

};
class BlockPos {
public:
	int x, y, z;
};
class ServerPlayer{
public:
	void sendNetworkPacket(class Packet& pk){
		Call("?sendNetworkPacket@ServerPlayer@@UEBAXAEAVPacket@@@Z",void, decltype(this), class Packet&)(this, pk);
	}
};
*/
#include<mcapi/Core.h>
#include<mcapi/Player.h>
#include<mcapi/Level.h>
#include<mcapi/BlockSource.h>
#include<mcapi/Dimension.h>
#include<mcapi/Item_Block.h>
#include<mcapi/Actor.h>
class ServerPlayer;
class NetworkIdentifier;
class ServerNetworkHandler {
public:
	//class ServerPlayer * __ptr64 __cdecl ServerNetworkHandler::_getServerPlayer(class NetworkIdentifier const & __ptr64,unsigned char)
	ServerPlayer* _getServerPlayer(NetworkIdentifier const& a0, unsigned char a1) {
		return Call("?_getServerPlayer@ServerNetworkHandler@@AEAAPEAVServerPlayer@@AEBVNetworkIdentifier@@E@Z", ServerPlayer*, decltype(this), decltype(a0), decltype(a1))(this, a0, a1);
	}
	MCAPI void disconnectClient(class NetworkIdentifier const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, bool);
	MCINLINE void onDisconnect(class NetworkIdentifier const& a0) { Call("?onDisconnect@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N1@Z", void, ServerNetworkHandler const*, class NetworkIdentifier const&)(this, a0); }
};
class Minecraft {
public:
	MCAPI class Level* __ptr64 __cdecl getLevel(void)const;
	MCAPI ServerNetworkHandler* __ptr64 __cdecl getServerNetworkHandler(void);
};