#include <lbpch.h>
#include<api\types\types.h>
#include<api\myPacket.h>
#include<stl\varint.h>
#include<api\refl\playerMap.h>
#include<mcapi/Player.h>
#include<mcapi/Certificate.h>
LBAPI void WPlayer::sendText(string_view text, TextType tp) {
	WBStream txtpkws;
	txtpkws.data.reserve(8 + text.size());
	txtpkws.apply((char)tp, (char)0, MCString(text));
	MyPkt<9> pk{ txtpkws.data };
	v->sendNetworkPacket(pk);
}
static uintptr_t poff_neti, poff_pcert;
THook(void*, "??0ServerPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H@Z", class Player* a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6, void* a7, __int64 a8, __int64 a9, void* a10_uuid, __int64 a11, void** a12, __int64 a13) {
	void* pCert = *a12;
	auto rv = original(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10_uuid, a11, a12, a13);
	if (poff_neti)
		return rv;
	void* pNeti = a7;
	uintptr_t thi = (uintptr_t)a1;
	for (uintptr_t off = 8; off <= 4000; off += 8) {
		if (*(void**)(thi + off) == pCert) {
			if (poff_pcert) {
				LOG.p<LOGLVL::Error>("[WPlayer] wtf_cert", poff_pcert, off);
				printf("wtf_cert %lld %lld\n", poff_pcert, off);
			}
			poff_pcert = off;
			continue;
		}
		if (memcmp((void*)(thi + off), pNeti, 144) == 0) {
			if (poff_neti) {
				LOG.p<LOGLVL::Error>("[WPlayer] wtf_neti", poff_neti, off);
			}
			poff_neti = off;
		}
	}
	LOG("[WPlayer] get net",poff_neti,"cert", poff_pcert);
	return rv;
}
LBAPI NetworkIdentifier* WPlayer::_getNI() {
	auto ptr = (uintptr_t)v;
	ptr += poff_neti;
	return (NetworkIdentifier*)ptr;
}
LBAPI Certificate* WPlayer::_getCert() {
	auto ptr = (uintptr_t)v;
	ptr += poff_pcert;
	return *(Certificate**)ptr;
}
LBAPI void WPlayer::kick(const string& reason) {
	LocateS<ServerNetworkHandler>()->disconnectClient(*_getNI(), reason, false);
}
LBAPI void WPlayer::forceKick() {
	LocateS<ServerNetworkHandler>()->onDisconnect(*_getNI());
}
static xuid_t getXuid_real(WPlayer wp) {
	auto xuid = ExtendedCertificate::getXuid(*wp._getCert());
	return xuid.size() > 1 ? std::stoull(xuid) : 114514;
}
static string getName_real(WPlayer wp) {
	return ExtendedCertificate::getIdentityName(*wp._getCert());
}
struct xuidStorage {
	xuid_t val;
	string name;
	xuidStorage(ServerPlayer& sp) {
		val = getXuid_real({ sp });
		name = getName_real({ sp });
	}
	operator xuid_t() {
		return val;
	}
	operator const string&() {
		return name;
	}
};
static playerMap<xuidStorage> xuid_cache;
LBAPI xuid_t WPlayer::getXuid() {
	return xuid_cache[v];
}
LBAPI const string& WPlayer::getName() {
	return xuid_cache[v];
}
LBAPI string WPlayer::getRealName() {
	return ExtendedCertificate::getIdentityName(*_getCert());
}
LBAPI permlvl_t WPlayer::getPermLvl() {
	return v->getCommandPermissionLevel()&0xff;
}
LBAPI string WPlayer::getIP() {
	return (LocateS<RakPeer_t>()->getAdr(*_getNI()).toString());
}