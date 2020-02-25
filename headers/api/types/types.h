#pragma once
#include<api/MC.h>
struct WPlayer {
	ServerPlayer& sp;
	WPlayer(ServerPlayer* _sp):sp(*_sp){}
	WPlayer(ServerPlayer& _sp):sp(_sp){}
	operator ServerPlayer&() {
		return sp;
	}
	operator ServerPlayer* () {
		return &sp;
	}
};