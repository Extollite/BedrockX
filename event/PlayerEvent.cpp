#include "pch.h"
/*
EXPORT_EVENT(PlayerPreJoinEvent);
EXPORT_EVENT(PlayerJoinEvent);
EXPORT_EVENT(PlayerLeftEvent);
EXPORT_EVENT(PlayerChatEvent);
EXPORT_EVENT(PlayerCMDEvent);

EXPORT_EVENT(PlayerDestroyEvent);

EXPORT_EVENT(PlayerUseItemOnEvent);
EXPORT_EVENT(PlayerUseItemOnEntityEvent);
*/
THook(void, "?_onClientAuthenticated@ServerNetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVCertificate@@@Z", void* snh, NetworkIdentifier& neti, Certificate& cert) {
	original(snh, neti, cert);
	PlayerPreJoinEvent::_call(cert, neti);
}
THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVSetLocalPlayerAsInitializedPacket@@@Z", ServerNetworkHandler& thi, NetworkIdentifier const& b, unsigned char* pk) {
	original(thi, b, pk);
	ServerPlayer* sp = thi._getServerPlayer(b, pk[16]);
	if (sp)
		PlayerJoinEvent::_call(*sp);
}
THook(void, "?_onPlayerLeft@ServerNetworkHandler@@AEAAXPEAVServerPlayer@@_N@Z", void* snh, ServerPlayer* sp, bool unk) {
	if (sp)
		PlayerLeftEvent::_call(*sp);
	original(snh, sp, unk);
}
THook(void, "?_displayGameMessage@ServerNetworkHandler@@AEAAXAEBVPlayer@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void* snh, ServerPlayer& sp, string& msg) {
	if (PlayerChatEvent::_call(sp, msg))
		original(snh, sp, msg);
}
THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVCommandRequestPacket@@@Z", ServerNetworkHandler* snh, NetworkIdentifier& neti, char* pk) {
	ServerPlayer* sp = snh->_getServerPlayer(neti, pk[16]);
	if (!sp)
		return;
	auto& cmd = dAccess<string, 40>(pk);
	if (PlayerCMDEvent::_call(*sp, cmd))
		original(snh, neti, pk);
}
THook(bool, "?destroyBlock@GameMode@@UEAA_NAEBVBlockPos@@E@Z", void* thi, BlockPos& pos, uchar unk) {
	if (PlayerDestroyEvent::_call(*dAccess<ServerPlayer*, 8>(thi), pos))
		return original(thi, pos, unk);
	return false;
}
/*ServerPlayer& sp, BlockPos& _pos,WItem _item, uchar _side*/
THook(bool, "?useItemOn@GameMode@@UEAA_NAEAVItemStack@@AEBVBlockPos@@EAEBVVec3@@PEBVBlock@@@Z", void* thi, ItemStack& a2, BlockPos& a3_pos, unsigned char side, void * a5, void* a6_block) {
	if (PlayerUseItemOnEvent::_call(*dAccess<ServerPlayer*, 8>(thi), a3_pos, a2, side))
		return original(thi, a2, a3_pos, side, a5, a6_block);
	return false;
}
THook(bool, "?useItem@GameMode@@UEAA_NAEAVItemStack@@@Z", void* thi, ItemStack& a2) {
	if (PlayerUseItemEvent::_call(*dAccess<ServerPlayer*, 8>(thi), a2))
		return original(thi, a2);
	return false;
}
THook(int, "?handle@ItemUseOnActorInventoryTransaction@@UEBA?AW4InventoryTransactionError@@AEAVPlayer@@_N@Z", void* thi, ServerPlayer& sp, bool unk) {
	if(PlayerUseItemOnEntityEvent::_call(sp, dAccess<ActorRuntimeID,104>(thi))) //WARNING:HARDCODED OFFSET
		return original(thi, sp, unk);
	return 0;
}