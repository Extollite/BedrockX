#include"pch.h"
THook(void, "?die@Mob@@UEAAXAEBVActorDamageSource@@@Z", Mob* thi, ActorDamageSource* src) {
	MobDeathEvent::_call(*thi, src);
	return original(thi, src);
}
THook(bool, "?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@H_N1@Z", Mob& ac, ActorDamageSource* src, int damage, bool unk1_1, bool unk2_0) {
	int dam = damage;
	if (MobHurtedEvent::_call(ac, src, dam))
		return original(ac, src, dam, unk1_1, unk2_0);
	return false;
}