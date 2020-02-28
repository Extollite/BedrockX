#include"pch.h"
LBAPI array_view<WPlayer> WLevel::getUsers() {
	uintptr_t ptr = (uintptr_t)this->v;
	return array_view<WPlayer>(*(WPlayer**)(ptr + 88), *(WPlayer**)(ptr + 96));
}
LBAPI WPlayer WLevel::getPlayer(string_view name) {
	auto view = getUsers();
	for (auto i : view) {
		if (i.getName() == name)
			return i;
	}
	return WPlayer(*(ServerPlayer*)0);
}
LBAPI void WLevel::broadcastText(string_view text, TextType tp) {
	WBStream txtpkws;
	txtpkws.data.reserve(8 + text.size());
	txtpkws.apply((char)tp, (char)0, MCString(txtpkws, text));
	MyPkt<9> pk{ txtpkws.data };
	auto view = getUsers();
	for (auto i : view) {
		i->sendNetworkPacket(pk);
	}
}