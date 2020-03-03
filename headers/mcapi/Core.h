#pragma once
#define MCAPI __declspec(dllimport)
#define MCINLINE inline
#define MCCLS
#include <api/Loader.h>
#include <api/serviceLocate.h>
#include <vector>
#include <memory>
#include <functional>
enum ActorType : int {

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
class Certificate;
class ExtendedCertificate {
public:
	static MCAPI std::string getXuid(Certificate const&);
	static MCAPI std::string getIdentityName(Certificate const&);
};
struct MCRESULT {
	unsigned char filler[4];
	operator bool() {
		return filler[0];
	}
	bool isSuccess() {
		return operator bool();
	}
};
class MinecraftCommands {
public:
	static MCRESULT _runcmd(void* origin, string const& cmd, int unk1, bool unk2) {
		MCRESULT rv;
		Call("?requestCommandExecution@MinecraftCommands@@QEBA?AUMCRESULT@@V?$unique_ptr@VCommandOrigin@@U?$default_delete@VCommandOrigin@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@4@H_N@Z", void, MinecraftCommands*, MCRESULT*, void**, string const&, int, bool)(LocateS<MinecraftCommands>()._srv, &rv, &origin, cmd, unk1, unk2);
		return rv;
	}
};
class RakNetServerLocator {
public:
	MCINLINE void accounce(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& b, int c_type, int d, int e, bool f) {
		Call("?announceServer@RakNetServerLocator@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4GameType@@HH_N@Z", void, void*, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, int, int, int, bool)(this, a, b, c_type, d, e, f);
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
	virtual void* unk3() = 0;//?
	//no unk4???
public:
	virtual ActorUniqueID getEntityUniqueID() const = 0;
	virtual int getEntityType() const = 0;
private:
	virtual int getEntityCategories() const = 0;
};
class NetworkIdentifier {
private:
	char filler[144];
};
class Certificate;