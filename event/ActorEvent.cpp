#include"pch.h"
THook(void, "?die@Mob@@UEAAXAEBVActorDamageSource@@@Z", Mob* thi, ActorDamageSource* src) {
	MobDeathEvent::_call(*thi, src);
	return original(thi, src);
}
