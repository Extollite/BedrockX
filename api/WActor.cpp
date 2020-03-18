#include <lbpch.h>
#include<api\types\types.h>
static uintptr_t poff_dim;
LBAPI WDim WActor::getDim() {
	if (!poff_dim) {
		char filler[256];
		Call("??0ActorCommandOrigin@@QEAA@AEAVActor@@@Z", void, char*, Actor*)(filler, v);
		void* get=Call("?getDimension@ActorCommandOrigin@@UEBAPEAVDimension@@XZ",void*,char*)(filler);
		void** myMEM = (void**)v;
		for (int i = 96; i < 116; ++i) {
			if (myMEM[i] == get) {
				if (poff_dim) {
					printf("wtf actor %lld %d\n", poff_dim, i * 8);
				}
				poff_dim = i * 8;
			}
		}
	}
	uintptr_t ptr = (uintptr_t)v;
	ptr += poff_dim;
	return WDim(**(Dimension**)ptr);
}
LBAPI int WActor::getDimID() {
	return v->getDimensionId();
}
LBAPI void WActor::teleport(Vec3 to, int dimid) {
	if (getDimID()!=dimid)
		Call("?teleport@TeleportCommand@@AEBAXAEAVActor@@VVec3@@PEAV3@V?$AutomaticID@VDimension@@H@@@Z", void, void*, Actor*, Vec3, Vec3*, int)(NULL, v, to, &to, dimid);
	Call("?teleport@TeleportCommand@@AEBAXAEAVActor@@VVec3@@PEAV3@V?$AutomaticID@VDimension@@H@@@Z", void, void*, Actor*, Vec3, Vec3*, int)(NULL,v,to,&to,dimid);
}
