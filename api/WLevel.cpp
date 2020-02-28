#include"pch.h"
LBAPI array_view<WPlayer> WLevel::getUsers() {
	uintptr_t ptr = (uintptr_t)this->v;
	return array_view<WPlayer>(*(WPlayer**)(ptr + 88), *(WPlayer**)(ptr + 96));
}
LBAPI WPlayer WLevel::getPlayer(string_view name) {
	auto view = getUsers();
	auto sz = view.size();
	for (decltype(sz) i = 0; i < sz; ++i) {
		if (view[i].getName() == name)
			return view[i];
	}
	return WPlayer(*(ServerPlayer*)0);
}