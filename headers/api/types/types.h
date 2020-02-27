#pragma once
#include <api/MC.h>
#include <stl/views.h>
#define LBAPI LIGHTBASE_API
template <typename T>
struct Wrapped {
	T& v;
	Wrapped(T& x) : v(x) {}
	Wrapped(T* x) : v(*x) {}
	operator T&() {
		return v;
	}
	operator T*() {
		return &v;
	}
	T& get() {
		return v;
	}
	T* operator->() {
		return &v;
	}
};
struct WActor : Wrapped<Actor> {
	WActor(Actor& x) : Wrapped<Actor>(x) {}
};
struct WPlayer : Wrapped<ServerPlayer> {
	WPlayer(ServerPlayer& x) : Wrapped<ServerPlayer>(x) {}
	LBAPI string const& getName();
};
/*
struct Item *__fastcall Item::setAllowOffhand(Item *this)
{
  *((_BYTE *)this + 258) |= 0x40u;
  return this;
}
*/
struct WDim : Wrapped<Dimension> {
	WDim(Dimension& x) : Wrapped<Dimension>(x) {}
	LBAPI BlockPos getSpawnPos();
	LBAPI float getTime();
};
struct WLevel : Wrapped<ServerLevel> {
	WLevel(ServerLevel& x) : Wrapped<ServerLevel>(x) {}
	LBAPI array_view<ServerPlayer&> getUsers();
	LBAPI array_view<ServerPlayer&> getPlayer(string_view name);
	LBAPI WActor* getEntity(unsigned long entid);
	LBAPI WActor* getRuntimeEntity(unsigned long rtid); //?
	LBAPI WDim* getDim(int dimid);
};