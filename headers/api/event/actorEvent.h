#pragma once
#include"eventBase.h"
class MobDeathEvent : public IMobEvent, public IEventBase<MobDeathEvent> {
	ActorDamageSource* src;
public:
	MobDeathEvent(Mob& _ac, ActorDamageSource* _src) : src(_src), IMobEvent(_ac) {}
	ActorDamageSource& getSource() {
		return *src;
	}
};
class ActorHurtedEvent : public IGenericActorEvent<ActorHurtedEvent>{
	ActorDamageSource* src;
	int& damage;
public:
	ActorHurtedEvent(Actor& _ac, ActorDamageSource* _src,int& _dam) : src(_src), IGenericActorEvent<ActorHurtedEvent>(_ac),damage(_dam) {}
	ActorDamageSource& getSource() {
		return *src;
	}
	int& getDamage() {
		return damage;
	}
};