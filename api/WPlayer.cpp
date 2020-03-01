#include "pch.h"
LBAPI const string& WPlayer::getName() {
	return this->v->getNameTag();
}
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
				printf("wtf_cert %d %d\n", poff_pcert, off);
			}
			poff_pcert = off;
			continue;
		}
		if (memcmp((void*)(thi + off), pNeti, 144) == 0) {
			if (poff_neti) {
				printf("wtf_neti %d %d\n", poff_neti, off);
			}
			poff_neti = off;
		}
	}
	printf("get net %d cert %d %s\n", poff_neti, poff_pcert, ExtendedCertificate::getIdentityName(*(Certificate*)pCert).c_str());
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
#include<sstream>
LBAPI xuid_t WPlayer::getXuid() {
	xuid_t rv=114514;
	auto str = ExtendedCertificate::getXuid(*_getCert());
	std::stringstream ss(str);
	ss >> rv;
	return rv;
}
LBAPI permlvl_t WPlayer::getPermLvl() {
	return v->getCommandPermissionLevel()&0xff;
}