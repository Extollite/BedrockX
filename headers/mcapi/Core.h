#pragma once
#define MCAPI __declspec(dllimport)
#define MCINLINE inline
#define MCCLS 
#include <api/Loader.h>
#include<api/serviceLocate.h>
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
	static MCRESULT _runcmd(void* origin,string const& cmd,int unk1,bool unk2) {
		MCRESULT rv;
		Call("?requestCommandExecution@MinecraftCommands@@QEBA?AUMCRESULT@@V?$unique_ptr@VCommandOrigin@@U?$default_delete@VCommandOrigin@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@4@H_N@Z", void,MinecraftCommands*,MCRESULT*,void**,string const&,int,bool)(LocateS<MinecraftCommands>()._srv,&rv,&origin,cmd,unk1,unk2);
		return rv;
	}
};