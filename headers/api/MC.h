#pragma once
#include"Loader.h"
#include"lightbase.h"

#include<mcapi/Core.h>
#include<mcapi/Player.h>
#include<mcapi/Level.h>
#include<mcapi/BlockSource.h>
#include<mcapi/Dimension.h>
#include<mcapi/Item_Block.h>
#include<mcapi/Actor.h>
#include<mcapi/Command/Command.h>
#include<mcapi/VanillaBlocks.h>
class ServerPlayer;
class ServerNetworkHandler {
public:
	//class ServerPlayer * __ptr64 __cdecl ServerNetworkHandler::_getServerPlayer(class NetworkIdentifier const & __ptr64,unsigned char)
	ServerPlayer* _getServerPlayer(NetworkIdentifier const& a0, unsigned char a1) {
		return Call("?_getServerPlayer@ServerNetworkHandler@@AEAAPEAVServerPlayer@@AEBVNetworkIdentifier@@E@Z", ServerPlayer*, decltype(this), decltype(a0), decltype(a1))(this, a0, a1);
	}
	MCINLINE void disconnectClient(class NetworkIdentifier const& a, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& b, bool c) {
		return Call("?disconnectClient@ServerNetworkHandler@@QEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z", void, void*, class NetworkIdentifier const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, bool)(this,a,b,c);
	}
	MCINLINE void onDisconnect(class NetworkIdentifier const& a0) { Call("?onDisconnect@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N1@Z", void, ServerNetworkHandler const*, class NetworkIdentifier const&)(this, a0); }
};
class Minecraft {
public:
	MCINLINE class Level* getLevel() {
		class Level* (Minecraft::*rv)();
		*((void**)&rv) = dlsym("?getLevel@Minecraft@@QEBAPEAVLevel@@XZ");
		return (this->*rv)();
	}
	MCINLINE class ServerNetworkHandler* getServerNetworkHandler() {
		class ServerNetworkHandler* (Minecraft::*rv)();
		*((void**)&rv) = dlsym("?getServerNetworkHandler@Minecraft@@QEAAPEAVServerNetworkHandler@@XZ");
		return (this->*rv)();
	}
};