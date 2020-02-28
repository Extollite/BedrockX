#pragma once
#define MCAPI __declspec(dllimport)
#define MCINLINE inline
#define MCCLS 
#include <api/Loader.h>
#include <vector>
#include <memory>
#include <functional>
enum ActorType:int {

};
class Vec3 {
public:
	float x, y, z;
};
class BlockPos {
public:
	int x, y, z;
};
template <typename A, typename T>
class AutomaticID {
	T id;
	AutomaticID() {
		id = 0;
	}
	operator T() {
		return id;
	}
};
struct Tick {
	unsigned long t;
};
struct ActorUniqueID {
	long id;
	ActorUniqueID() {
		id = -1;
	}
};
class Certificate;
