#include <pch.h>
static uintptr_t icnt_off;
static bool inMagic;
unsigned char WItem::getCount() const {
	return *(unsigned char*)(((uintptr_t)v) + icnt_off);
}
THook(void*, "?_setItem@ItemStackBase@@IEAA_NH@Z", void* a, int b) {
	if (inMagic)
		return nullptr;
	return original(a, b);
}
struct determine_off {
	determine_off() {
		addListener([](ServerStartedEvent&) {
			inMagic = true;
			char filler[700];
			memset(filler, 0xff, sizeof(filler));
			Call("?init@ItemStackBase@@IEAAXHHH@Z", void, void*, int, int, int)(filler, 0, 125, 0);
			inMagic = false;
			for (int i = 0; i < 512; ++i) {
				if (filler[i] == 125) {
					if (icnt_off) {
						printf("[WItem] Warning!!! last off %zu\n", icnt_off);
					}
					icnt_off = i;
				}
			}
			if (icnt_off == 0) {
				printf("[WItem] Error!!! bad off %zu\n", icnt_off);
			}
			else {
				printf("[WItem] Debug!!! off %zu\n", icnt_off);
			}	
		});
	}
};
static determine_off __execnow;