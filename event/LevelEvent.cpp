#include <lbpch.h>
#include<api\event\levelEvent.h>
THook(void, "?explode@Level@@QEAAXAEAVBlockSource@@PEAVActor@@AEBVVec3@@M_N3M3@Z", void* thi, class BlockSource* a1, class Actor* a2, class Vec3* a3, float a4, bool a5, bool a6, float a7, bool a8) {
	WExplosion exp{ { *a1 } };
	exp.cause = a2;
	exp.pos = a3;
	exp.rad = a4;
	exp.breaking = a6;
	exp.firing = a5;
	auto rv = LevelExplodeEvent::_call(exp);
	if (rv) {
		a4 = exp.rad;
		a5 = exp.firing;
		a6 = exp.breaking;
		original(thi, a1, a2, a3, a4, a5, a6, a7, a8);
	}
}