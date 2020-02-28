#pragma once
#include"eventBase.h"
class ActorDeathEvent : public IActorEvent, public IEventBase <ActorDeathEvent > {
	ActorDamageSource* src;
public:
	ActorDeathEvent(Actor& _ac, ActorDamageSource* _src) : src(_src),IActorEvent(_ac) {}
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