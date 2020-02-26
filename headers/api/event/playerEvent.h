#pragma once
#include "eventBase.h"

class PlayerChatEvent : public IGenericPlayerEvent<PlayerChatEvent> {
	string& _chat;
	string& _name;

public:
	PlayerChatEvent(ServerPlayer& sp, string& chat, string& name) : IGenericPlayerEvent(sp), _chat(chat), _name(name) {}
	const string& getChat() {
		return _chat;
	}
	const string& getName() {
		return _name;
	}
};
class PlayerJoinEvent : public IEventBase<PlayerJoinEvent>, public IPlayerEvent {
public:
	PlayerJoinEvent(ServerPlayer& sp) : IPlayerEvent(sp) {}
};
class PlayerLeftEvent : public IEventBase<PlayerLeftEvent>, public IPlayerEvent {
public:
	PlayerLeftEvent(ServerPlayer& sp) : IPlayerEvent(sp) {}
};

class PlayerDestroyEvent : public IGenericPlayerEvent<PlayerDestroyEvent> {
	BlockPos& pos;
	PlayerDestroyEvent(ServerPlayer& sp, BlockPos& _pos) : IGenericPlayerEvent(sp), pos(_pos) {}
	const BlockPos& getPos() {
		return pos;
	}
};
class PlayerUseItemOnEvent : public IGenericPlayerEvent<PlayerUseItemOnEvent> {
	BlockPos& pos;
	uchar side;

public:
	PlayerUseItemOnEvent(ServerPlayer& sp, BlockPos& _pos, uchar _side) : IGenericPlayerEvent(sp), pos(_pos), side(_side) {}
	BlockPos getPos() {
		return pos;
	}
	BlockPos getPlacePos() {
		const int Z[] = { 0, 0, -1, 1, 0, 0 };
		const int X[] = { 0, 0, 0, 0, -1, 1 };
		const int Y[] = { -1, 1, 0, 0, 0, 0 };
		BlockPos dpos = { pos.x + X[side], pos.y + Y[side], pos.z + Z[side] };
		return dpos;
	}
	uchar getSide() {
		return side;
	}
};
