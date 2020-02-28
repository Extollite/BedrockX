#pragma once
#include <api/MC.h>
#include <stl/views.h>
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
	Wrapped(T& x) : v(&x) {}
	Wrapped(T* x) : v(x) {}
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
struct WDim : Wrapped<Dimension> {
	WDim(Dimension& x) : Wrapped<Dimension>(x) {}
	LBAPI BlockPos getSpawnPos();
	LBAPI float getTime();
	LBAPI void setBlock(int x, int y, int z, int blkid);
	LBAPI struct WBlock getBlock(int x, int y, int z);
	LBAPI BlockSource* _getBlockSource();
};
struct WLevel : Wrapped<ServerLevel> {
	WLevel(ServerLevel& x) : Wrapped<ServerLevel>(x) {}
	LBAPI array_view<WPlayer> getUsers();
	LBAPI WPlayer getPlayer(string_view name);
	LBAPI WActor getEntity(unsigned long entid);
	LBAPI WActor getRuntimeEntity(unsigned long rtid); //?
	LBAPI WDim getDim(int dimid);
	LBAPI void broadcastText(string_view text, TextType type = RAW);
};
struct WActor : Wrapped<Actor> {
	WActor(Actor& x) : Wrapped<Actor>(x) {}
	LBAPI void teleport(Vec3 to, int dimid);
	LBAPI Vec3 const& getPos();
	LBAPI string const& getNameTag();
	LBAPI enum ActorType getType();
	LBAPI struct ActorUniqueID const& getUniqueID();
	LBAPI int getDimID();
	LBAPI WDim getDim();
};
struct WMob : Wrapped<Mob> {
	WMob(Mob& x) : Wrapped<Mob>(x) {}
	WActor* actor() {
		return (WActor*)this;
	}
	LBAPI WPlayer getLastHurtByPlayer();
};
struct WPlayer : Wrapped<ServerPlayer> {
	WPlayer(ServerPlayer& x) : Wrapped<ServerPlayer>(x) {}
	WActor* actor() {
		return (WActor*)this;
	}
	WMob* mob() {
		return (WMob*)this;
	}
	LBAPI string const& getName();
	LBAPI xuid_t getXuid();
	LBAPI permlvl_t getPermLvl();
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
	LBAPI void kill();
	LBAPI NetworkIdentifier* _getNI();
	LBAPI Certificate* _getCert();
};
struct WItem : Wrapped<ItemStack> {
	WItem(ItemStack& is) : Wrapped<ItemStack>(is) {}
};
struct WBlock : Wrapped<Block> {
	WBlock(Block& i) : Wrapped<Block>(i) {}
};
struct WBlockActor : Wrapped<BlockActor> {
	WBlockActor(BlockActor& i) : Wrapped<BlockActor>(i) {}
};
class Explosion;
struct WExplosion : Wrapped<Explosion> {
	WExplosion(Explosion& i) : Wrapped<Explosion>(i) {}
	LBAPI Actor* getCause();
	LBAPI Vec3& getPos();
	LBAPI char& breaking();
	LBAPI char& firing();
};
/*
struct Item *__fastcall Item::setAllowOffhand(Item *this)
{
  *((_BYTE *)this + 258) |= 0x40u;
  return this;
}
*/
