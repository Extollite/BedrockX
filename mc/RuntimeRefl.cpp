#include "pch.h"
//PlayerMap.h
static std::vector<DePlayerCB> depcbs;
LIGHTBASE_API void _regDePlayerCB(DePlayerCB cb) {
	depcbs.emplace_back(cb);
}

THook(void, "??_EServerPlayer@@UEAAPEAXI@Z", ServerPlayer* thi, char a2) {
	for (auto& i : depcbs) {
		i(thi);
	}
	original(thi, a2);
}