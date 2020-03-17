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
struct RakAddr_t {
	char filler[0x90];
	string toString() {
		char buf[256];
		Call("?ToString_New@SystemAddress@RakNet@@AEBAX_NPEADD@Z", void, void*, bool, char*, char)(this,true,buf,':');
		return buf;
	}
};
struct RakPeer_t {
	RakPeer_t(RakPeer_t const&) = delete;
	RakPeer_t(RakPeer_t&&) = delete;
	RakAddr_t getAdr(NetworkIdentifier const& ni) {
		RakAddr_t rv;
		Call("?GetSystemAddressFromGuid@RakPeer@RakNet@@UEBA?AUSystemAddress@2@URakNetGUID@2@@Z", void, void*, RakAddr_t*, NetworkIdentifier const*)(this,&rv,&ni);
		return rv;
	}
};
constexpr const int SAFE_PADDING = 0;