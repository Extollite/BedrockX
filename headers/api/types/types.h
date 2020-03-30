#pragma once
#include<lbpch.h>
//#include <api/MC.h>
#include <stl/views.h>
#include<api/types/helper.h>
#include<stl/optional.h>
#define LBAPI LIGHTBASE_API
typedef unsigned long long xuid_t;
typedef unsigned char permlvl_t;
enum TextType : char {
	RAW = 0,
	POPUP = 3,
	JUKEBOX_POPUP = 4,
	TIP = 5
};
template <typename T>
struct Wrapped {
	T* v;
	Wrapped(T const& x) : v((T*)&x) {}
	Wrapped(T* x) : v(x) {}
	Wrapped() {
		v = nullptr;
	}
	operator T&() {
		return *v;
	}
	operator T*() {
		return v;
	}
	T& get() {
		return *v;
	}
	T* operator->() {
		return v;
	}
	operator bool() {
		return v;
	}
};
struct WPlayer;
struct WActor;
class Dimension;
class BlockSource;
class Block;
class Level;
class ServerLevel;
class Actor;
class Mob;
class Player;
class BlockActor;
class ItemStack;
struct WDim : Wrapped<Dimension> {
	WDim(Dimension& x) : Wrapped<Dimension>(x) {}
	LBAPI class BlockSource& getBlockSource_();
	LBAPI void setBlock(int x, int y, int z, Block const& blk);
	LBAPI struct WBlock getBlock(int x, int y, int z);
	LBAPI int getID();
};
struct WLevel : Wrapped<ServerLevel> {
	WLevel() : Wrapped<ServerLevel>() {}
	WLevel(ServerLevel& x) : Wrapped<ServerLevel>(x) {}
	LBAPI array_view<WPlayer> getUsers();
	LBAPI optional<WPlayer> getPlayer(string_view name);
	LBAPI void broadcastText(string_view text, TextType type = RAW);
};
struct WActor : Wrapped<Actor> {
	WActor(Actor& x) : Wrapped<Actor>(x) {}
	LBAPI void teleport(Vec3 to, int dimid);
	LBAPI int getDimID();
	LBAPI WDim getDim();
};
struct WMob : Wrapped<Mob> {
	WMob(Mob& x) : Wrapped<Mob>(x) {}
	WActor* actor() {
		return (WActor*)this;
	}
	LBAPI void kill();
};
struct WPlayer : Wrapped<ServerPlayer> {
	WPlayer() : Wrapped<ServerPlayer>() {}
	WPlayer(Player& x) : Wrapped<ServerPlayer>(*(ServerPlayer*)&x) {}
	WPlayer(ServerPlayer& x) : Wrapped<ServerPlayer>(x) {}
	WActor* actor() {
		return (WActor*)this;
	}
	WMob* mob() {
		return (WMob*)this;
	}
	LBAPI string const& getName();
	LBAPI xuid_t getXuid();
	LBAPI string getRealName();
	LBAPI permlvl_t getPermLvl();
	LBAPI class BlockSource& getBlockSource_();
	void teleport(Vec3 to, int dimid) {
		actor()->teleport(to, dimid);
	}
	auto getDimID() {
		return actor()->getDimID();
	}
	auto getDim() {
		return actor()->getDim();
	}
	LBAPI void sendText(string_view text, TextType type = RAW);
	LBAPI void kick(string const& reason);
	LBAPI void forceKick();
	LBAPI void kill() {
		mob()->kill();
	}
	LBAPI bool runcmd(string const& str) {
		return BDX::runcmdAs(*this, str);
	}
	LBAPI class NetworkIdentifier* _getNI();
	LBAPI class Certificate* _getCert();
	string getIP() {
		return BDX::getIP(*_getNI());
	}
};
struct WItem : Wrapped<ItemStack> {
	WItem(ItemStack& is) : Wrapped<ItemStack>(is) {}
	LBAPI unsigned char getCount() const;
};
struct WBlock : Wrapped<Block> {
	WBlock(Block const& i) : Wrapped<Block>(i) {}
};
struct WBlockActor : Wrapped<BlockActor> {
	WBlockActor(BlockActor& i) : Wrapped<BlockActor>(i) {}
};
struct WBlockSource:Wrapped<BlockSource> {
	WBlockSource(BlockSource& x) : Wrapped<BlockSource>(x) {}
	LBAPI WDim getDim();
};
struct WExplosion {
	WBlockSource bs;
	float rad;
	Actor* cause;
	Vec3* pos;
	char breaking;
	char firing;
};

/*
?setAllowOffhand@Item@@QEAAAEAV1@_N@Z
struct Item *__fastcall Item::setAllowOffhand(Item *this)
{
  *((_BYTE *)this + 258) |= 0x40u;
  return this;
}
*/
