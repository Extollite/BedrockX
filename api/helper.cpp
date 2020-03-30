#include <lbpch.h>
#include<api\types\types.h>
class ServerLevel;
namespace BDX {
	using std::string;
	static void dummy() {
	}
	struct SCO {
		char filler[0x48];
		void* fake_vtbl[26];
		SCO() {
			SymCall("??0ServerCommandOrigin@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVServerLevel@@W4CommandPermissionLevel@@@Z", void, void*, string const&, ServerLevel*, int)(this, "Server", LocateS<ServerLevel>()._srv, 5);
			void** vtbl = (*(void***)filler) - 1;
			memcpy(fake_vtbl, vtbl, sizeof(fake_vtbl));
			//vtbl: 0x0:RTTI info,0x8 D2Ev
			*(void**)filler = fake_vtbl + 1;
			fake_vtbl[1] = (void*)dummy;
		}
	};
	static SCO* pSCO;
	LBAPI bool runcmd(const string& cmd) {
		if (!pSCO)
			pSCO = new SCO();
		return MinecraftCommands::_runcmd(pSCO, cmd, 4, 1);
	}
	static void* FAKE_PORGVTBL[26];
	LBAPI bool runcmdAs(WPlayer wp, const string& cmd) {
		void** filler[5];
		SymCall("??0PlayerCommandOrigin@@QEAA@AEAVPlayer@@@Z", void, void*, ServerPlayer*)(filler, wp);
		if (FAKE_PORGVTBL[1] == NULL) {
			memcpy(FAKE_PORGVTBL, ((void**)filler[0])-1, sizeof(FAKE_PORGVTBL));
			FAKE_PORGVTBL[1] = (void*)dummy;
		}
		filler[0] = FAKE_PORGVTBL+1;
		return MinecraftCommands::_runcmd(filler, cmd, 4, 1);
	}
	LBAPI string getIP(class NetworkIdentifier& ni) {
		string rv = LocateS<RakPeer_t>()->getAdr(ni).toString();
		return rv.substr(0,rv.find('|'));
	}
};