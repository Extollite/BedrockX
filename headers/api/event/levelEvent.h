#pragma once
#include "eventBase.h"
class LevelExplodeEvent : public IEventBase<LevelExplodeEvent> {
public:
	WExplosion exp;
	LevelExplodeEvent(Explosion& _exp) : exp(_exp) {}
};