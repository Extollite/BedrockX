#pragma once
#include<lbpch.h>
#define MCAPI __declspec(dllimport)
#define MCINLINE inline
#define MCCLS
#include"mass.h"
#include<stl/Bstream.h>
enum ActorType : int;
enum class AbilitiesIndex : int;
class Vec3 {
public:
	float x, y, z;
	string toString() {
		return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
	}
	template<typename _TP>
	void pack(WBStreamImpl<_TP>& ws) const {
		ws.apply(x, y, z);
	}
	void unpack(RBStream& rs) {
		rs.apply(x, y, z);
	}
};
class BlockPos {
public:
	int x, y, z;
	template<typename _TP>
	void pack(WBStreamImpl<_TP>& ws) const {
		ws.apply(x, y, z);
	}
	void unpack(RBStream& rs) {
		rs.apply(x, y, z);
	}
};
template <typename A, typename T>
class AutomaticID {
	T id;
public:
	AutomaticID() {
		id = 0;
	}
	AutomaticID(T x) {
		id = x;
	}
	operator T() {
		return id;
	}
};
struct Tick {
	unsigned long long t;
};
struct ActorUniqueID {
	unsigned long long id;
public:
	ActorUniqueID() {
		id = -1;
	}
	ActorUniqueID(unsigned long long i) {
		id = i;
	}
	auto get() {
		return id;
	}
	operator unsigned long long() {
		return id;
	}
};
class ActorRuntimeID {
	unsigned long long id;

public:
	ActorRuntimeID() {
		id = -1;
	}
	ActorRuntimeID(unsigned long long i) {
		id = i;
	}
	auto get() {
		return id;
	}
	operator unsigned long long() {
		return id;
	}
};

class ActorDamageSource {
private:
	char filler[0x10];

public:
	virtual void destruct1(unsigned int) = 0;
	virtual bool isEntitySource() const = 0;
	virtual bool isChildEntitySource() const = 0;

private:
	virtual void* unk0() = 0;
	virtual void* unk1() = 0; //death msg
	virtual void* unk2() = 0; //is creative
	virtual void* unk3() = 0; //?
public:
	virtual ActorUniqueID getEntityUniqueID() const = 0;
	virtual int getEntityType() const = 0;

private:
	virtual int getEntityCategories() const = 0;
};

class ChunkPos {
public:
	int x, z;
};

constexpr const int SAFE_PADDING = 0;