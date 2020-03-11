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
public:
	long id;
	ActorUniqueID() {
		id = -1;
	}
	ActorUniqueID(long i) {
		id = i;
	}
};
class ActorRuntimeID {
public:
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
	static MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getXuid(class Certificate const& a0) {
		class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> (*rv)(class Certificate const&);
		*((void**)&rv) = dlsym("?getXuid@ExtendedCertificate@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVCertificate@@@Z");
		return (*rv)(a0);
	} 
	static MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getIdentityName(class Certificate const& a0) {
		class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> (*rv)(class Certificate const&);
		*((void**)&rv) = dlsym("?getIdentityName@ExtendedCertificate@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVCertificate@@@Z");
		return (*rv)(a0);
	}
};
namespace mce {
	class UUID;
};
class NetworkIdentifier {
	char filler[144];
};
namespace Util
{
	class HashString;
};
namespace Json {
	class Value;
}

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

constexpr const int SAFE_PADDING = 0;