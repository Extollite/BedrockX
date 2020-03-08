#pragma once
#define MCAPI __declspec(dllimport)
#define MCINLINE inline
#define MCCLS
#include <api/Loader.h>
#include <api/serviceLocate.h>
#include <vector>
#include <memory>
#include <functional>
#include"mass.h"
enum ActorType : int;
enum class AbilitiesIndex : int;
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
	unsigned long t;
};
struct ActorUniqueID {
	long id;
	ActorUniqueID() {
		id = -1;
	}
	ActorUniqueID(long i) {
		id = i;
	}
};
class ActorRuntimeID {
	long id;
	ActorRuntimeID() {
		id = -1;
	}
	ActorRuntimeID(long i) {
		id = i;
	}
};

class Certificate;
class ExtendedCertificate {
public:
	static MCAPI std::string getXuid(Certificate const&);
	static MCAPI std::string getIdentityName(Certificate const&);
};
namespace mce {
	class UUID;
};
class NetworkIdentifier {
	char filler[144];
};

constexpr const int SAFE_PADDING = 32;