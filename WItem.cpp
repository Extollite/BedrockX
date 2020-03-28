#include <lbpch.h>
#include<api\types\types.h>
#include<api\event\genericEvent.h>
static uintptr_t icnt_off;
static bool inMagic;
unsigned char WItem::getCount() const {
	return *(unsigned char*)(((uintptr_t)v) + icnt_off);
}
THook(void*, "?_setItem@ItemStackBase@@IEAA_NH@Z", char* a, int b) {
	if (inMagic) {
		int hits = 0;
		for (uintptr_t i = 8; i <= 90; ++i) {
			if (a[i] == 114) {
				LOG("[WITEM]", "found offset", i);
				icnt_off = i;
				++hits;
			}
		}
		if (hits != 1) {
			LOG.p<LOGLVL::Fatal>("[WItem] Cant Find off!!!", icnt_off);
		}
		return nullptr;
	}
	return original(a, b);
}
#include<random>
static void procoff() {
	inMagic = true;
	char filler[700];
	memset(filler, 0xff, sizeof(filler));
	SymCall("?init@ItemStackBase@@IEAAXHHH@Z", void, void*, int, int, int)(filler, 0, 114, 0);
	inMagic = false;
}
struct determine_off {
	determine_off() {
		addListener([](ServerStartedEvent&) {
			procoff();
		});
	}
};
static determine_off __execnow;