#pragma once
#include "eventBase.h"
class LevelExplodeEvent : public IEventBase<LevelExplodeEvent> {
public:
	WExplosion& exp;
	LevelExplodeEvent(WExplosion& _exp) : exp(_exp) {}
};