#pragma once
#include "Core.h"
class BlockLegacy {
public:
	MCINLINE bool mayPlace(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?mayPlace@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE int getDirectSignal(class BlockSource& a0, class BlockPos const& a1, int a2) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, int);
		*((void**)&rv) = dlsym("?getDirectSignal@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@H@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int getExtraRenderLayers() {
		int (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getExtraRenderLayers@BlockLegacy@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE int getColorAtPos(class BlockSource& a0, class BlockPos const& a1) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?getColorAtPos@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class ItemActor* popResource(class BlockSource& a0, class BlockPos const& a1, class ItemInstance const& a2) {
		class ItemActor* (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class ItemInstance const&);
		*((void**)&rv) = dlsym("?popResource@BlockLegacy@@QEBAPEAVItemActor@@AEAVBlockSource@@AEBVBlockPos@@AEBVItemInstance@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool mayPick() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?mayPick@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void createBlockPermutations(unsigned int a0) {
		void (BlockLegacy::*rv)(unsigned int);
		*((void**)&rv) = dlsym("?createBlockPermutations@BlockLegacy@@QEAAXI@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool canBeBuiltOver(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?canBeBuiltOver@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void setVisualShape(class AABB const& a0) {
		void (BlockLegacy::*rv)(class AABB const&);
		*((void**)&rv) = dlsym("?setVisualShape@BlockLegacy@@UEAAXAEBVAABB@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void playerDestroy(class Player& a0, class BlockPos const& a1, class Block const& a2) {
		void (BlockLegacy::*rv)(class Player&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?playerDestroy@BlockLegacy@@UEBAXAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE enum BlockRenderLayer getRenderLayer() {
		enum BlockRenderLayer (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getRenderLayer@BlockLegacy@@UEBA?AW4BlockRenderLayer@@XZ");
		return (this->*rv)();
	}
	MCINLINE bool canConnect(class Block const& a0, unsigned char a1, class Block const& a2) {
		bool (BlockLegacy::*rv)(class Block const&, unsigned char, class Block const&);
		*((void**)&rv) = dlsym("?canConnect@BlockLegacy@@UEBA_NAEBVBlock@@E0@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isSlabBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isSlabBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class BlockLegacy& setMinRequiredBaseGameVersion(class BaseGameVersion const& a0) {
		class BlockLegacy& (BlockLegacy::*rv)(class BaseGameVersion const&);
		*((void**)&rv) = dlsym("?setMinRequiredBaseGameVersion@BlockLegacy@@QEAAAEAV1@AEBVBaseGameVersion@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void forEachBlockPermutation() {
		void (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?forEachBlockPermutation@BlockLegacy@@QEBAXV?$function@$$A6A_NAEBVBlock@@@Z@std@@@Z");
		return (this->*rv)();
	}
	MCINLINE class BlockLegacy& addState(class ItemState const& a0, unsigned __int64 a1) {
		class BlockLegacy& (BlockLegacy::*rv)(class ItemState const&, unsigned __int64);
		*((void**)&rv) = dlsym("?addState@BlockLegacy@@UEAAAEAV1@AEBVItemState@@_K@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE float getShadeBrightness() {
		float (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getShadeBrightness@BlockLegacy@@UEBAMXZ");
		return (this->*rv)();
	}
	MCINLINE bool mayConsumeFertilizer(class BlockSource& a0) {
		bool (BlockLegacy::*rv)(class BlockSource&);
		*((void**)&rv) = dlsym("?mayConsumeFertilizer@BlockLegacy@@UEBA_NAEAVBlockSource@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool shouldConnectToRedstone(class BlockSource& a0, class BlockPos const& a1, int a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, int);
		*((void**)&rv) = dlsym("?shouldConnectToRedstone@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@H@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class BlockLegacy& setDestroyTime(float a0) {
		class BlockLegacy& (BlockLegacy::*rv)(float);
		*((void**)&rv) = dlsym("?setDestroyTime@BlockLegacy@@UEAAAEAV1@M@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class BlockLegacy& addProperty(enum BlockProperty a0) {
		class BlockLegacy& (BlockLegacy::*rv)(enum BlockProperty);
		*((void**)&rv) = dlsym("?addProperty@BlockLegacy@@UEAAAEAV1@W4BlockProperty@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void getDebugText(class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>& a0, class BlockPos const& a1) {
		void (BlockLegacy::*rv)(class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>&, class BlockPos const&);
		*((void**)&rv) = dlsym("?getDebugText@BlockLegacy@@QEBAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE int getColor(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?getColor@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void onExploded(class BlockSource& a0, class BlockPos const& a1, class Actor* a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor*);
		*((void**)&rv) = dlsym("?onExploded@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int getColor(class Block const& a0) {
		int (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?getColor@BlockLegacy@@UEBAHAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class Block const& sanitizeFillBlock(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) {
		class Block const& (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?sanitizeFillBlock@BlockLegacy@@UEBAAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@AEBV2@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class AABB const& getUIShape(class Block const& a0, class AABB& a1) {
		class AABB const& (BlockLegacy::*rv)(class Block const&, class AABB&);
		*((void**)&rv) = dlsym("?getUIShape@BlockLegacy@@UEBAAEBVAABB@@AEBVBlock@@AEAV2@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void updateEntityAfterFallOn(class Actor& a0) {
		void (BlockLegacy::*rv)(class Actor&);
		*((void**)&rv) = dlsym("?updateEntityAfterFallOn@BlockLegacy@@UEBAXAEAVActor@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void forEachItemStateInstance() {
		void (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?forEachItemStateInstance@BlockLegacy@@QEBAXV?$function@$$A6A_NAEBVItemStateInstance@@@Z@std@@@Z");
		return (this->*rv)();
	}
	MCINLINE class Block const* getNextBlockPermutation(class Block const& a0) {
		class Block const* (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?getNextBlockPermutation@BlockLegacy@@UEBAPEBVBlock@@AEBV2@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void getConnectedDirections(class Block const& a0, class BlockPos const& a1, class BlockSource& a2, bool& a3, bool& a4, bool& a5, bool& a6) {
		void (BlockLegacy::*rv)(class Block const&, class BlockPos const&, class BlockSource&, bool&, bool&, bool&, bool&);
		*((void**)&rv) = dlsym("?getConnectedDirections@BlockLegacy@@UEBAXAEBVBlock@@AEBVBlockPos@@AEAVBlockSource@@AEA_N333@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5, a6);
	}
	MCINLINE bool shouldStopFalling(class Actor& a0) {
		bool (BlockLegacy::*rv)(class Actor&);
		*((void**)&rv) = dlsym("?shouldStopFalling@BlockLegacy@@UEBA_NAEAVActor@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void tick(class BlockSource& a0, class BlockPos const& a1, class Random& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Random&);
		*((void**)&rv) = dlsym("?tick@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class BlockLegacy& addState(class ItemState const& a0) {
		class BlockLegacy& (BlockLegacy::*rv)(class ItemState const&);
		*((void**)&rv) = dlsym("?addState@BlockLegacy@@UEAAAEAV1@AEBVItemState@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isCraftingBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isCraftingBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class Vec3 randomlyModifyPosition(class BlockPos const& a0, int& a1) {
		class Vec3 (BlockLegacy::*rv)(class BlockPos const&, int&);
		*((void**)&rv) = dlsym("?randomlyModifyPosition@BlockLegacy@@UEBA?AVVec3@@AEBVBlockPos@@AEAH@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void entityInside(class BlockSource& a0, class BlockPos const& a1, class Actor& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor&);
		*((void**)&rv) = dlsym("?entityInside@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void onFallOn(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, float a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor*, float);
		*((void**)&rv) = dlsym("?onFallOn@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE class AABB const& getAABB(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, class AABB& a3, bool a4) {
		class AABB const& (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, class AABB&, bool);
		*((void**)&rv) = dlsym("?getAABB@BlockLegacy@@UEBAAEBVAABB@@AEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEAV2@_N@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE void onPlace(class BlockSource& a0, class BlockPos const& a1) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?onPlace@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool onFertilized(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, enum FertilizerType a3) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor*, enum FertilizerType);
		*((void**)&rv) = dlsym("?onFertilized@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@W4FertilizerType@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool isValidAuxValue(int a0) {
		bool (BlockLegacy::*rv)(int);
		*((void**)&rv) = dlsym("?isValidAuxValue@BlockLegacy@@UEBA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool mayPick(class BlockSource& a0, class Block const& a1, bool a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class Block const&, bool);
		*((void**)&rv) = dlsym("?mayPick@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlock@@_N@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int getComparatorSignal(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, unsigned char a3) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, unsigned char);
		*((void**)&rv) = dlsym("?getComparatorSignal@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@E@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool ignoreEntitiesOnPistonMove(class Block const& a0) {
		bool (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?ignoreEntitiesOnPistonMove@BlockLegacy@@UEBA_NAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void onRemove(class BlockSource& a0, class BlockPos const& a1) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?onRemove@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE int getColorForParticle(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?getColorForParticle@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool canContainLiquid() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?canContainLiquid@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isSignalSource() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isSignalSource@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isButtonBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isButtonBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE float getFlexibility(class BlockSource& a0, class BlockPos const& a1) {
		float (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?getFlexibility@BlockLegacy@@UEBAMAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool getCollisionShape(class AABB& a0, class Block const& a1, class BlockSource& a2, class BlockPos const& a3, class Actor* a4) {
		bool (BlockLegacy::*rv)(class AABB&, class Block const&, class BlockSource&, class BlockPos const&, class Actor*);
		*((void**)&rv) = dlsym("?getCollisionShape@BlockLegacy@@UEBA_NAEAVAABB@@AEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@PEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE bool isFenceGateBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isFenceGateBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class BlockLegacy& setCategory(enum CreativeItemCategory a0) {
		class BlockLegacy& (BlockLegacy::*rv)(enum CreativeItemCategory);
		*((void**)&rv) = dlsym("?setCategory@BlockLegacy@@QEAAAEAV1@W4CreativeItemCategory@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void movedByPiston(class BlockSource& a0, class BlockPos const& a1) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?movedByPiston@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class MobSpawnerData const* getMobToSpawn(class SpawnConditions const& a0, class BlockSource& a1) {
		class MobSpawnerData const* (BlockLegacy::*rv)(class SpawnConditions const&, class BlockSource&);
		*((void**)&rv) = dlsym("?getMobToSpawn@BlockLegacy@@UEBAPEBVMobSpawnerData@@AEBVSpawnConditions@@AEAVBlockSource@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class BlockLegacy& init() {
		class BlockLegacy& (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?init@BlockLegacy@@UEAAAEAV1@XZ");
		return (this->*rv)();
	}
	MCINLINE bool isStemBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isStemBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool liquidCanFlowIntoFromDirection(unsigned char a0, class std::function<class Block const&> const& a1, class BlockPos const& a2) {
		bool (BlockLegacy::*rv)(unsigned char, class std::function<class Block const&> const&, class BlockPos const&);
		*((void**)&rv) = dlsym("?liquidCanFlowIntoFromDirection@BlockLegacy@@UEBA_NEAEBV?$function@$$A6AAEBVBlock@@AEBVBlockPos@@@Z@std@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool canSpawnOn() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?canSpawnOn@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void onRedstoneUpdate(class BlockSource& a0, class BlockPos const& a1, int a2, bool a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, int, bool);
		*((void**)&rv) = dlsym("?onRedstoneUpdate@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@H_N@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool breaksFallingBlocks(class Block const& a0) {
		bool (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?breaksFallingBlocks@BlockLegacy@@UEBA_NAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE int getExperienceDrop(class Random& a0) {
		int (BlockLegacy::*rv)(class Random&);
		*((void**)&rv) = dlsym("?getExperienceDrop@BlockLegacy@@UEBAHAEAVRandom@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class Block const* tryLegacyUpgrade(unsigned short a0) {
		class Block const* (BlockLegacy::*rv)(unsigned short);
		*((void**)&rv) = dlsym("?tryLegacyUpgrade@BlockLegacy@@UEBAPEBVBlock@@G@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool tryToPlace(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, struct ActorBlockSyncMessage const* a3) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, struct ActorBlockSyncMessage const*);
		*((void**)&rv) = dlsym("?tryToPlace@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@PEBUActorBlockSyncMessage@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE class Block const* tryGetStateFromLegacyData(unsigned short a0) {
		class Block const* (BlockLegacy::*rv)(unsigned short);
		*((void**)&rv) = dlsym("?tryGetStateFromLegacyData@BlockLegacy@@QEBAPEBVBlock@@G@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void onFillBlock(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?onFillBlock@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isObstructingChests(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?isObstructingChests@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE float getThickness() {
		float (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getThickness@BlockLegacy@@UEBAMXZ");
		return (this->*rv)();
	}
	MCINLINE class Vec3 randomlyModifyPosition(class BlockPos const& a0) {
		class Vec3 (BlockLegacy::*rv)(class BlockPos const&);
		*((void**)&rv) = dlsym("?randomlyModifyPosition@BlockLegacy@@UEBA?AVVec3@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void transformOnFall(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, float a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor*, float);
		*((void**)&rv) = dlsym("?transformOnFall@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool mayPlaceOn(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?mayPlaceOn@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool isStairBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isStairBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool hasComparatorSignal() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?hasComparatorSignal@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE int getVariant(class Block const& a0) {
		int (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?getVariant@BlockLegacy@@UEBAHAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE float getExplosionResistance(class Actor* a0) {
		float (BlockLegacy::*rv)(class Actor*);
		*((void**)&rv) = dlsym("?getExplosionResistance@BlockLegacy@@UEBAMPEAVActor@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class BlockLegacy& addBlockProperty(enum BlockProperty a0) {
		class BlockLegacy& (BlockLegacy::*rv)(enum BlockProperty);
		*((void**)&rv) = dlsym("?addBlockProperty@BlockLegacy@@QEAAAEAV1@W4BlockProperty@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void destroy(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, class Actor* a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, class Actor*);
		*((void**)&rv) = dlsym("?destroy@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@PEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE unsigned char getPlacementFacingAllExceptAxisY(class Actor& a0, class BlockPos const& a1, float a2) {
		unsigned char (BlockLegacy::*rv)(class Actor&, class BlockPos const&, float);
		*((void**)&rv) = dlsym("?getPlacementFacingAllExceptAxisY@BlockLegacy@@SAEAEAVActor@@AEBVBlockPos@@M@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class BlockLegacy& setExperimental() {
		class BlockLegacy& (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?setExperimental@BlockLegacy@@QEAAAEAV1@XZ");
		return (this->*rv)();
	}
	MCINLINE bool isInteractiveBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isInteractiveBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE enum Flip getFaceFlip(unsigned char a0, class Block const& a1) {
		enum Flip (BlockLegacy::*rv)(unsigned char, class Block const&);
		*((void**)&rv) = dlsym("?getFaceFlip@BlockLegacy@@UEBA?AW4Flip@@EAEBVBlock@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class AABB const& getVisualShape(class Block const& a0, class AABB& a1, bool a2) {
		class AABB const& (BlockLegacy::*rv)(class Block const&, class AABB&, bool);
		*((void**)&rv) = dlsym("?getVisualShape@BlockLegacy@@UEBAAEBVAABB@@AEBVBlock@@AEAV2@_N@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void triggerEvent(class BlockSource& a0, class BlockPos const& a1, int a2, int a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, int, int);
		*((void**)&rv) = dlsym("?triggerEvent@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@HH@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE void onGraphicsModeChanged(bool a0, bool a1, bool a2) {
		void (BlockLegacy::*rv)(bool, bool, bool);
		*((void**)&rv) = dlsym("?onGraphicsModeChanged@BlockLegacy@@UEAAX_N00@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void onStepOn(class Actor& a0, class BlockPos const& a1) {
		void (BlockLegacy::*rv)(class Actor&, class BlockPos const&);
		*((void**)&rv) = dlsym("?onStepOn@BlockLegacy@@UEBAXAEAVActor@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class BlockLegacy& setNameId(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0) {
		class BlockLegacy& (BlockLegacy::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
		*((void**)&rv) = dlsym("?setNameId@BlockLegacy@@QEAAAEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool hasVariableLighting() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?hasVariableLighting@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool shouldDispense(class BlockSource& a0, class Container& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class Container&);
		*((void**)&rv) = dlsym("?shouldDispense@BlockLegacy@@UEBA_NAEAVBlockSource@@AEAVContainer@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void onMove(class BlockSource& a0, class BlockPos const& a1, class BlockPos const& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class BlockPos const&);
		*((void**)&rv) = dlsym("?onMove@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@1@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class Block const& getDefaultState() {
		class Block const& (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getDefaultState@BlockLegacy@@QEBAAEBVBlock@@XZ");
		return (this->*rv)();
	}
	MCINLINE bool spawnBurnResources(class BlockSource& a0, float a1, float a2, float a3) {
		bool (BlockLegacy::*rv)(class BlockSource&, float, float, float);
		*((void**)&rv) = dlsym("?spawnBurnResources@BlockLegacy@@UEBA_NAEAVBlockSource@@MMM@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool canBeSilkTouched() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?canBeSilkTouched@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class Block const& getPlacementBlock(class Actor& a0, class BlockPos const& a1, unsigned char a2, class Vec3 const& a3, int a4) {
		class Block const& (BlockLegacy::*rv)(class Actor&, class BlockPos const&, unsigned char, class Vec3 const&, int);
		*((void**)&rv) = dlsym("?getPlacementBlock@BlockLegacy@@UEBAAEBVBlock@@AEAVActor@@AEBVBlockPos@@EAEBVVec3@@H@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE bool canHaveExtraData() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?canHaveExtraData@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void handleRain(class BlockSource& a0, class BlockPos const& a1, float a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, float);
		*((void**)&rv) = dlsym("?handleRain@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@M@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool addAABB(class AABB const& a0, class AABB const* a1, class std::vector<class AABB, class std::allocator<class AABB>>& a2) {
		bool (BlockLegacy::*rv)(class AABB const&, class AABB const*, class std::vector<class AABB, class std::allocator<class AABB>>&);
		*((void**)&rv) = dlsym("?addAABB@BlockLegacy@@QEBA_NAEBVAABB@@PEBV2@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isAuxValueRelevantForPicking() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isAuxValueRelevantForPicking@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void setupRedstoneComponent(class BlockSource& a0, class BlockPos const& a1) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?setupRedstoneComponent@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE int telemetryVariant(class BlockSource& a0, class BlockPos const& a1) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?telemetryVariant@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class BlockLegacy& setFriction(float a0) {
		class BlockLegacy& (BlockLegacy::*rv)(float);
		*((void**)&rv) = dlsym("?setFriction@BlockLegacy@@UEAAAEAV1@M@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isRailBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isRailBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isWallBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isWallBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void spawnResources(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, float a3, int a4) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, float, int);
		*((void**)&rv) = dlsym("?spawnResources@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@MH@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE void neighborChanged(class BlockSource& a0, class BlockPos const& a1, class BlockPos const& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class BlockPos const&);
		*((void**)&rv) = dlsym("?neighborChanged@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@1@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool canSurvive(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?canSurvive@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class Block const& getStateFromLegacyData(unsigned short a0) {
		class Block const& (BlockLegacy::*rv)(unsigned short);
		*((void**)&rv) = dlsym("?getStateFromLegacyData@BlockLegacy@@UEBAAEBVBlock@@G@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class BlockLegacy& setMapColor(class Color const& a0) {
		class BlockLegacy& (BlockLegacy::*rv)(class Color const&);
		*((void**)&rv) = dlsym("?setMapColor@BlockLegacy@@UEAAAEAV1@AEBVColor@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isStrippable(class Block const& a0) {
		bool (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?isStrippable@BlockLegacy@@UEBA_NAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool mayPlace(class BlockSource& a0, class BlockPos const& a1, unsigned char a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, unsigned char);
		*((void**)&rv) = dlsym("?mayPlace@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@E@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isDoorBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isDoorBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isFenceBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isFenceBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE float calcGroundFriction(class Mob& a0, class BlockPos const& a1) {
		float (BlockLegacy::*rv)(class Mob&, class BlockPos const&);
		*((void**)&rv) = dlsym("?calcGroundFriction@BlockLegacy@@UEBAMAEAVMob@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class AABB const& getOutline(class BlockSource& a0, class BlockPos const& a1, class AABB& a2) {
		class AABB const& (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class AABB&);
		*((void**)&rv) = dlsym("?getOutline@BlockLegacy@@UEBAAEBVAABB@@AEAVBlockSource@@AEBVBlockPos@@AEAV2@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool operator==(class BlockLegacy const& a0) {
		bool (BlockLegacy::*rv)(class BlockLegacy const&);
		*((void**)&rv) = dlsym("??8BlockLegacy@@QEBA_NAEBV0@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool checkIsPathable(class Actor& a0, class BlockPos const& a1, class BlockPos const& a2) {
		bool (BlockLegacy::*rv)(class Actor&, class BlockPos const&, class BlockPos const&);
		*((void**)&rv) = dlsym("?checkIsPathable@BlockLegacy@@UEBA_NAEAVActor@@AEBVBlockPos@@1@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool playerWillDestroy(class Player& a0, class BlockPos const& a1, class Block const& a2) {
		bool (BlockLegacy::*rv)(class Player&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?playerWillDestroy@BlockLegacy@@UEBA_NAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool canHurtAndBreakItem() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?canHurtAndBreakItem@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class AABB const& getVisualShapeInWorld(class Block const& a0, class BlockSource& a1, class BlockPos const& a2, class AABB& a3, bool a4) {
		class AABB const& (BlockLegacy::*rv)(class Block const&, class BlockSource&, class BlockPos const&, class AABB&, bool);
		*((void**)&rv) = dlsym("?getVisualShapeInWorld@BlockLegacy@@UEBAAEBVAABB@@AEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@AEAV2@_N@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE bool attack(class Player* a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class Player*, class BlockPos const&);
		*((void**)&rv) = dlsym("?attack@BlockLegacy@@UEBA_NPEAVPlayer@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class BlockLegacy& setExplodeable(float a0) {
		class BlockLegacy& (BlockLegacy::*rv)(float);
		*((void**)&rv) = dlsym("?setExplodeable@BlockLegacy@@UEAAAEAV1@M@Z");
		return (this->*rv)(a0);
	}
	MCINLINE enum BlockProperty getRedstoneProperty(class BlockSource& a0, class BlockPos const& a1) {
		enum BlockProperty (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?getRedstoneProperty@BlockLegacy@@UEBA?AW4BlockProperty@@AEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE unsigned char getMappedFace(unsigned char a0, class Block const& a1) {
		unsigned char (BlockLegacy::*rv)(unsigned char, class Block const&);
		*((void**)&rv) = dlsym("?getMappedFace@BlockLegacy@@UEBAEEAEBVBlock@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool hasTag(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a3) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
		*((void**)&rv) = dlsym("?hasTag@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool canFillAtPos(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&);
		*((void**)&rv) = dlsym("?canFillAtPos@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int calcVariant(class BlockSource& a0, class BlockPos const& a1) {
		int (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?calcVariant@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool getSecondPart(class BlockSource& a0, class BlockPos const& a1, class BlockPos& a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class BlockPos&);
		*((void**)&rv) = dlsym("?getSecondPart@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAV3@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void executeEvent(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a3, class Actor& a4) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Block const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class Actor&);
		*((void**)&rv) = dlsym("?executeEvent@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE void animateTick(class BlockSource& a0, class BlockPos const& a1, class Random& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Random&);
		*((void**)&rv) = dlsym("?animateTick@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class BlockLegacy& setLightEmission(float a0) {
		class BlockLegacy& (BlockLegacy::*rv)(float);
		*((void**)&rv) = dlsym("?setLightEmission@BlockLegacy@@UEAAAEAV1@M@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool dealsContactDamage(class Actor const& a0, class Block const& a1, bool a2) {
		bool (BlockLegacy::*rv)(class Actor const&, class Block const&, bool);
		*((void**)&rv) = dlsym("?dealsContactDamage@BlockLegacy@@UEBA_NAEBVActor@@AEBVBlock@@_N@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool getLiquidClipVolume(class BlockSource& a0, class BlockPos const& a1, class AABB& a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class AABB&);
		*((void**)&rv) = dlsym("?getLiquidClipVolume@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVAABB@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isAttachedTo(class BlockSource& a0, class BlockPos const& a1, class BlockPos& a2) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class BlockPos&);
		*((void**)&rv) = dlsym("?isAttachedTo@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAV3@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void addAABBs(class Block const& a0, class BlockSource& a1, class BlockPos const& a2, class AABB const* a3, class std::vector<class AABB, class std::allocator<class AABB>>& a4) {
		void (BlockLegacy::*rv)(class Block const&, class BlockSource&, class BlockPos const&, class AABB const*, class std::vector<class AABB, class std::allocator<class AABB>>&);
		*((void**)&rv) = dlsym("?addAABBs@BlockLegacy@@UEBAXAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@PEBVAABB@@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE void setVisualShape(class Vec3 const& a0, class Vec3 const& a1) {
		void (BlockLegacy::*rv)(class Vec3 const&, class Vec3 const&);
		*((void**)&rv) = dlsym("?setVisualShape@BlockLegacy@@UEAAXAEBVVec3@@0@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class BlockLegacy& setAllowsRunes(bool a0) {
		class BlockLegacy& (BlockLegacy::*rv)(bool);
		*((void**)&rv) = dlsym("?setAllowsRunes@BlockLegacy@@UEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isCropBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isCropBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool addCollisionShapes(class Block const& a0, class BlockSource& a1, class BlockPos const& a2, class AABB const* a3, class std::vector<class AABB, class std::allocator<class AABB>>& a4, class Actor* a5) {
		bool (BlockLegacy::*rv)(class Block const&, class BlockSource&, class BlockPos const&, class AABB const*, class std::vector<class AABB, class std::allocator<class AABB>>&, class Actor*);
		*((void**)&rv) = dlsym("?addCollisionShapes@BlockLegacy@@UEBA_NAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@PEBVAABB@@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@PEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5);
	}
	MCINLINE bool waterSpreadCausesSpawn() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?waterSpreadCausesSpawn@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool getIgnoresDestroyPermissions(class Actor& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class Actor&, class BlockPos const&);
		*((void**)&rv) = dlsym("?getIgnoresDestroyPermissions@BlockLegacy@@UEBA_NAEAVActor@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE unsigned char getPlacementFacingAll(class Actor& a0, class BlockPos const& a1, float a2) {
		unsigned char (BlockLegacy::*rv)(class Actor&, class BlockPos const&, float);
		*((void**)&rv) = dlsym("?getPlacementFacingAll@BlockLegacy@@SAEAEAVActor@@AEBVBlockPos@@M@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isBounceBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isBounceBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isSeasonTinted(class Block const& a0, class BlockSource& a1, class BlockPos const& a2) {
		bool (BlockLegacy::*rv)(class Block const&, class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?isSeasonTinted@BlockLegacy@@UEBA_NAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isWaterBlocking() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isWaterBlocking@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isContainerBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isContainerBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isHurtableBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isHurtableBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool detachesOnPistonMove(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?detachesOnPistonMove@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE enum BlockRenderLayer getRenderLayer(class Block const& a0, class BlockSource& a1, class BlockPos const& a2) {
		enum BlockRenderLayer (BlockLegacy::*rv)(class Block const&, class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?getRenderLayer@BlockLegacy@@UEBA?AW4BlockRenderLayer@@AEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isThinFenceBlock() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?isThinFenceBlock@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool shouldRandomTick() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?shouldRandomTick@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void handleEntityInside(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, class Vec3& a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor*, class Vec3&);
		*((void**)&rv) = dlsym("?handleEntityInside@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@AEAVVec3@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE int getIconYOffset() {
		int (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getIconYOffset@BlockLegacy@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE void onProjectileHit(class BlockSource& a0, class BlockPos const& a1, class Actor const& a2) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, class Actor const&);
		*((void**)&rv) = dlsym("?onProjectileHit@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVActor@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool canSlide(class BlockSource& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&);
		*((void**)&rv) = dlsym("?canSlide@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class Block const& getStrippedBlock(class Block const& a0) {
		class Block const& (BlockLegacy::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?getStrippedBlock@BlockLegacy@@UEBAAEBVBlock@@AEBV2@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool canProvideSupport(class Block const& a0, unsigned char a1, enum BlockSupportType a2) {
		bool (BlockLegacy::*rv)(class Block const&, unsigned char, enum BlockSupportType);
		*((void**)&rv) = dlsym("?canProvideSupport@BlockLegacy@@UEBA_NAEBVBlock@@EW4BlockSupportType@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool pushesUpFallingBlocks() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?pushesUpFallingBlocks@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool use(class Player& a0, class BlockPos const& a1) {
		bool (BlockLegacy::*rv)(class Player&, class BlockPos const&);
		*((void**)&rv) = dlsym("?use@BlockLegacy@@UEBA_NAEAVPlayer@@AEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE class BlockLegacy& setCanBeExtraBlock(bool a0) {
		class BlockLegacy& (BlockLegacy::*rv)(bool);
		*((void**)&rv) = dlsym("?setCanBeExtraBlock@BlockLegacy@@QEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE int getResourceCount(class Random& a0, class Block const& a1, int a2) {
		int (BlockLegacy::*rv)(class Random&, class Block const&, int);
		*((void**)&rv) = dlsym("?getResourceCount@BlockLegacy@@UEBAHAEAVRandom@@AEBVBlock@@H@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool dispense(class BlockSource& a0, class Container& a1, int a2, class Vec3 const& a3, unsigned char a4) {
		bool (BlockLegacy::*rv)(class BlockSource&, class Container&, int, class Vec3 const&, unsigned char);
		*((void**)&rv) = dlsym("?dispense@BlockLegacy@@UEBA_NAEAVBlockSource@@AEAVContainer@@HAEBVVec3@@E@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE short getBlockItemId() {
		short (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?getBlockItemId@BlockLegacy@@QEBAFXZ");
		return (this->*rv)();
	}
	MCINLINE void spawnResources(class BlockSource& a0, class BlockPos const& a1, float a2, int a3) {
		void (BlockLegacy::*rv)(class BlockSource&, class BlockPos const&, float, int);
		*((void**)&rv) = dlsym("?spawnResources@BlockLegacy@@QEBAXAEAVBlockSource@@AEBVBlockPos@@MH@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool canBeOriginalSurface() {
		bool (BlockLegacy::*rv)();
		*((void**)&rv) = dlsym("?canBeOriginalSurface@BlockLegacy@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool canBeUsedInCommands(bool a0, class BaseGameVersion const& a1) {
		bool (BlockLegacy::*rv)(bool, class BaseGameVersion const&);
		*((void**)&rv) = dlsym("?canBeUsedInCommands@BlockLegacy@@UEBA_N_NAEBVBaseGameVersion@@@Z");
		return (this->*rv)(a0, a1);
	}

#if 0
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  buildDescriptionName(class Block const & a0){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (BlockLegacy::*rv)(class Block const &); *((void**)&rv) = dlsym("?buildDescriptionName@BlockLegacy@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlock@@@Z"); return (this->*rv)(a0);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  buildDescriptionId(class Block const & a0){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (BlockLegacy::*rv)(class Block const &); *((void**)&rv) = dlsym("?buildDescriptionId@BlockLegacy@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlock@@@Z"); return (this->*rv)(a0);}
//   bad fun  

	MCINLINE class ItemInstance  getSilkTouchItemInstance(class Block const & a0){
class ItemInstance (BlockLegacy::*rv)(class Block const &); *((void**)&rv) = dlsym("?getSilkTouchItemInstance@BlockLegacy@@UEBA?AVItemInstance@@AEBVBlock@@@Z"); return (this->*rv)(a0);}
	// ??0BlockLegacy@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@HAEBVMaterial@@@Z
	// BlockLegacy::BlockLegacy(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,int,class Material const &)
	MCINLINE class Color  getMapColor(class BlockSource & a0,class BlockPos const & a1){
class Color (BlockLegacy::*rv)(class BlockSource &,class BlockPos const &); *((void**)&rv) = dlsym("?getMapColor@BlockLegacy@@UEBA?AVColor@@AEAVBlockSource@@AEBVBlockPos@@@Z"); return (this->*rv)(a0,a1);}
	MCINLINE class HitResult  clip(class BlockSource & a0,class BlockPos const & a1,class Vec3 const & a2,class Vec3 const & a3,bool a4){
class HitResult (BlockLegacy::*rv)(class BlockSource &,class BlockPos const &,class Vec3 const &,class Vec3 const &,bool); *((void**)&rv) = dlsym("?clip@BlockLegacy@@UEBA?AVHitResult@@AEAVBlockSource@@AEBVBlockPos@@AEBVVec3@@2_N@Z"); return (this->*rv)(a0,a1,a2,a3,a4);}
	MCINLINE class WeakPtr<class BlockLegacy>  createWeakPtr(){
class WeakPtr<class BlockLegacy> (BlockLegacy::*rv)(); *((void**)&rv) = dlsym("?createWeakPtr@BlockLegacy@@QEAA?AV?$WeakPtr@VBlockLegacy@@@@XZ"); return (this->*rv)();}
	MCINLINE class ItemInstance  asItemInstance(class BlockSource & a0,class BlockPos const & a1,class Block const & a2){
class ItemInstance (BlockLegacy::*rv)(class BlockSource &,class BlockPos const &,class Block const &); *((void**)&rv) = dlsym("?asItemInstance@BlockLegacy@@UEBA?AVItemInstance@@AEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z"); return (this->*rv)(a0,a1,a2);}
	MCINLINE class Color  getMapColor(){
class Color (BlockLegacy::*rv)(); *((void**)&rv) = dlsym("?getMapColor@BlockLegacy@@UEBA?AVColor@@XZ"); return (this->*rv)();}
	MCINLINE struct Brightness  getLightEmission(class Block const & a0){
struct Brightness (BlockLegacy::*rv)(class Block const &); *((void**)&rv) = dlsym("?getLightEmission@BlockLegacy@@UEBA?AUBrightness@@AEBVBlock@@@Z"); return (this->*rv)(a0);}
	MCINLINE class BlockLegacy &  setLightBlock(struct Brightness a0){
class BlockLegacy & (BlockLegacy::*rv)(struct Brightness); *((void**)&rv) = dlsym("?setLightBlock@BlockLegacy@@UEAAAEAV1@UBrightness@@@Z"); return (this->*rv)(a0);}
	MCINLINE class ItemInstance  getResourceItem(class Random & a0,class Block const & a1,int a2){
class ItemInstance (BlockLegacy::*rv)(class Random &,class Block const &,int); *((void**)&rv) = dlsym("?getResourceItem@BlockLegacy@@UEBA?AVItemInstance@@AEAVRandom@@AEBVBlock@@H@Z"); return (this->*rv)(a0,a1,a2);}
	MCINLINE class HitResult  clip(class BlockSource & a0,class BlockPos const & a1,class Vec3 const & a2,class Vec3 const & a3,bool a4,class AABB const & a5){
class HitResult (BlockLegacy::*rv)(class BlockSource &,class BlockPos const &,class Vec3 const &,class Vec3 const &,bool,class AABB const &); *((void**)&rv) = dlsym("?clip@BlockLegacy@@QEBA?AVHitResult@@AEAVBlockSource@@AEBVBlockPos@@AEBVVec3@@2_NAEBVAABB@@@Z"); return (this->*rv)(a0,a1,a2,a3,a4,a5);}
#endif
};
#pragma once
#include "Core.h"
class Block {
public:
	MCINLINE class Block const& copyState(class Block const& a0, class ItemState const& a1) {
		class Block const& (Block::*rv)(class Block const&, class ItemState const&);
		*((void**)&rv) = dlsym("?copyState@Block@@QEBAAEBV1@AEBV1@AEBVItemState@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool isSolidBlockingBlockAndNotSignalSource() {
		bool (Block::*rv)();
		*((void**)&rv) = dlsym("?isSolidBlockingBlockAndNotSignalSource@Block@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class BlockLegacy const& getLegacyBlock() {
		class BlockLegacy const& (Block::*rv)();
		*((void**)&rv) = dlsym("?getLegacyBlock@Block@@QEBAAEBVBlockLegacy@@XZ");
		return (this->*rv)();
	}
	MCINLINE enum BlockRenderLayer getRenderLayer() {
		enum BlockRenderLayer (Block::*rv)();
		*((void**)&rv) = dlsym("?getRenderLayer@Block@@UEBA?AW4BlockRenderLayer@@XZ");
		return (this->*rv)();
	}
	MCINLINE class Block const& keepState(class ItemState const& a0) {
		class Block const& (Block::*rv)(class ItemState const&);
		*((void**)&rv) = dlsym("?keepState@Block@@QEBAAEBV1@AEBVItemState@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void spawnResources(class BlockSource& a0, class BlockPos const& a1, float a2, int a3) {
		void (Block::*rv)(class BlockSource&, class BlockPos const&, float, int);
		*((void**)&rv) = dlsym("?spawnResources@Block@@QEBAXAEAVBlockSource@@AEBVBlockPos@@MH@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE void buildSerializationId(unsigned int a0) {
		void (Block::*rv)(unsigned int);
		*((void**)&rv) = dlsym("?buildSerializationId@Block@@IEAAXI@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isSlabBlock() {
		bool (Block::*rv)();
		*((void**)&rv) = dlsym("?isSlabBlock@Block@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isSolidBlockingBlock() {
		bool (Block::*rv)();
		*((void**)&rv) = dlsym("?isSolidBlockingBlock@Block@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool hasState(class ItemState const& a0) {
		bool (Block::*rv)(class ItemState const&);
		*((void**)&rv) = dlsym("?hasState@Block@@QEBA_NAEBVItemState@@@Z");
		return (this->*rv)(a0);
	}

#if 0
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  toDebugString(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Block::*rv)(); *((void**)&rv) = dlsym("?toDebugString@Block@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
//   bad fun

#endif
};
#pragma once
#include "Core.h"
class ItemStackBase {
public:
	MCINLINE bool operator!=(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("??9ItemStackBase@@QEBA_NAEBV0@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool hasCustomHoverName() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?hasCustomHoverName@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void hurtAndBreak(int a0, class Actor* a1) {
		void (ItemStackBase::*rv)(int, class Actor*);
		*((void**)&rv) = dlsym("?hurtAndBreak@ItemStackBase@@QEAAXHPEAVActor@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void setCustomName(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0) {
		void (ItemStackBase::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
		*((void**)&rv) = dlsym("?setCustomName@ItemStackBase@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool updateComponent(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, class Json::Value const& a1) {
		bool (ItemStackBase::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class Json::Value const&);
		*((void**)&rv) = dlsym("?updateComponent@ItemStackBase@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE short getAuxValue() {
		short (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?getAuxValue@ItemStackBase@@QEBAFXZ");
		return (this->*rv)();
	}
	MCINLINE void setRepairCost(int a0) {
		void (ItemStackBase::*rv)(int);
		*((void**)&rv) = dlsym("?setRepairCost@ItemStackBase@@QEAAXH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool hasSameAuxValue(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?hasSameAuxValue@ItemStackBase@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void _makeChargedItemFromUserData() {
		void (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?_makeChargedItemFromUserData@ItemStackBase@@AEAAXXZ");
		return (this->*rv)();
	}
	MCINLINE bool isEnchanted() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isEnchanted@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void _setChargedItem(class ItemInstance const& a0) {
		void (ItemStackBase::*rv)(class ItemInstance const&);
		*((void**)&rv) = dlsym("?_setChargedItem@ItemStackBase@@AEAAXAEBVItemInstance@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void addCustomUserData(class BlockActor& a0, class BlockSource& a1) {
		void (ItemStackBase::*rv)(class BlockActor&, class BlockSource&);
		*((void**)&rv) = dlsym("?addCustomUserData@ItemStackBase@@QEAAXAEAVBlockActor@@AEAVBlockSource@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool isDamaged() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isDamaged@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE unsigned char getMaxStackSize() {
		unsigned char (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?getMaxStackSize@ItemStackBase@@QEBAEXZ");
		return (this->*rv)();
	}
	MCINLINE bool matches(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?matches@ItemStackBase@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void init(class Item const& a0, int a1, int a2, class CompoundTag const* a3) {
		void (ItemStackBase::*rv)(class Item const&, int, int, class CompoundTag const*);
		*((void**)&rv) = dlsym("?init@ItemStackBase@@IEAAXAEBVItem@@HHPEBVCompoundTag@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool matchesItem(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?matchesItem@ItemStackBase@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void init(class BlockLegacy const& a0, int a1) {
		void (ItemStackBase::*rv)(class BlockLegacy const&, int);
		*((void**)&rv) = dlsym("?init@ItemStackBase@@IEAAXAEBVBlockLegacy@@H@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE short getId() {
		short (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?getId@ItemStackBase@@QEBAFXZ");
		return (this->*rv)();
	}
	MCINLINE bool isExperimental() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isExperimental@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void setChargedItem(class ItemInstance const& a0, bool a1) {
		void (ItemStackBase::*rv)(class ItemInstance const&, bool);
		*((void**)&rv) = dlsym("?setChargedItem@ItemStackBase@@QEAAXAEBVItemInstance@@_N@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void _updateCompareHashes() {
		void (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?_updateCompareHashes@ItemStackBase@@AEAAXXZ");
		return (this->*rv)();
	}
	MCINLINE class Item const* getItem() {
		class Item const* (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?getItem@ItemStackBase@@QEBAPEBVItem@@XZ");
		return (this->*rv)();
	}
	MCINLINE bool isHorseArmorItem() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isHorseArmorItem@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isStackable(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?isStackable@ItemStackBase@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isWearableItem() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isWearableItem@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void _loadItem(class CompoundTag const& a0) {
		void (ItemStackBase::*rv)(class CompoundTag const&);
		*((void**)&rv) = dlsym("?_loadItem@ItemStackBase@@AEAAXAEBVCompoundTag@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void init(int a0, int a1, int a2) {
		void (ItemStackBase::*rv)(int, int, int);
		*((void**)&rv) = dlsym("?init@ItemStackBase@@IEAAXHHH@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int getIdAux() {
		int (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?getIdAux@ItemStackBase@@QEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE bool hasSameUserData(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?hasSameUserData@ItemStackBase@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void serializeComponents(class IDataOutput& a0) {
		void (ItemStackBase::*rv)(class IDataOutput&);
		*((void**)&rv) = dlsym("?serializeComponents@ItemStackBase@@QEBAXAEAVIDataOutput@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool _setItem(int a0) {
		bool (ItemStackBase::*rv)(int);
		*((void**)&rv) = dlsym("?_setItem@ItemStackBase@@IEAA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isPotionItem() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isPotionItem@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isBlock() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isBlock@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void saveEnchantsToUserData(class ItemEnchants const& a0) {
		void (ItemStackBase::*rv)(class ItemEnchants const&);
		*((void**)&rv) = dlsym("?saveEnchantsToUserData@ItemStackBase@@QEAAXAEBVItemEnchants@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isStackedByData() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isStackedByData@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void _read(class ReadOnlyBinaryStream& a0) {
		void (ItemStackBase::*rv)(class ReadOnlyBinaryStream&);
		*((void**)&rv) = dlsym("?_read@ItemStackBase@@QEAAXAEAVReadOnlyBinaryStream@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool sameItem(int a0, int a1) {
		bool (ItemStackBase::*rv)(int, int);
		*((void**)&rv) = dlsym("?sameItem@ItemStackBase@@QEBA_NHH@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void deserializeComponents(class IDataInput& a0) {
		void (ItemStackBase::*rv)(class IDataInput&);
		*((void**)&rv) = dlsym("?deserializeComponents@ItemStackBase@@QEAAXAEAVIDataInput@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void _write(class BinaryStream& a0) {
		void (ItemStackBase::*rv)(class BinaryStream&);
		*((void**)&rv) = dlsym("?_write@ItemStackBase@@QEBAXAEAVBinaryStream@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void setCustomLore(class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>> const& a0) {
		void (ItemStackBase::*rv)(class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>> const&);
		*((void**)&rv) = dlsym("?setCustomLore@ItemStackBase@@QEAAXAEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void set(int a0) {
		void (ItemStackBase::*rv)(int);
		*((void**)&rv) = dlsym("?set@ItemStackBase@@QEAAXH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool addComponents(class Json::Value const& a0, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>& a1) {
		bool (ItemStackBase::*rv)(class Json::Value const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>&);
		*((void**)&rv) = dlsym("?addComponents@ItemStackBase@@QEAA_NAEBVValue@Json@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void clearChargedItem() {
		void (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?clearChargedItem@ItemStackBase@@QEAAXXZ");
		return (this->*rv)();
	}
	MCINLINE void _loadComponents(class CompoundTag const& a0) {
		void (ItemStackBase::*rv)(class CompoundTag const&);
		*((void**)&rv) = dlsym("?_loadComponents@ItemStackBase@@AEAAXAEBVCompoundTag@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void setNull() {
		void (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?setNull@ItemStackBase@@QEAAXXZ");
		return (this->*rv)();
	}
	MCINLINE class ItemStackBase& operator=(class ItemStackBase const& a0) {
		class ItemStackBase& (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("??4ItemStackBase@@IEAAAEAV0@AEBV0@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool hasComponent(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0) {
		bool (ItemStackBase::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
		*((void**)&rv) = dlsym("?hasComponent@ItemStackBase@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isNull() {
		bool (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?isNull@ItemStackBase@@QEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void setUserData() {
		void (ItemStackBase::*rv)();
		*((void**)&rv) = dlsym("?setUserData@ItemStackBase@@QEAAXV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@@Z");
		return (this->*rv)();
	}
	MCINLINE bool sameItemAndAux(class ItemStackBase const& a0) {
		bool (ItemStackBase::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?sameItemAndAux@ItemStackBase@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}

#if 0
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  toString(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?toString@ItemStackBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getDescriptionId(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getDescriptionId@ItemStackBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> >  getNetworkUserData(){
class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getNetworkUserData@ItemStackBase@@QEBA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getRawNameId(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getRawNameId@ItemStackBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> >  save(){
class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?save@ItemStackBase@@QEBA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getName(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getName@ItemStackBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getHoverName(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getHoverName@ItemStackBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  _getHoverFormattingPrefix(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?_getHoverFormattingPrefix@ItemStackBase@@IEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getCustomName(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getCustomName@ItemStackBase@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
//   bad fun  

	// ??0ItemStackBase@@IEAA@AEBVItem@@H@Z
	// ItemStackBase::ItemStackBase(class Item const &,int)
	MCINLINE class ItemDescriptor  getDescriptor(){
class ItemDescriptor (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getDescriptor@ItemStackBase@@QEBA?AVItemDescriptor@@XZ"); return (this->*rv)();}
	// ??BItemStackBase@@QEBA_NXZ
	// ItemStackBase::operator bool(void)const 
	MCINLINE class ItemEnchants  getEnchantsFromUserData(){
class ItemEnchants (ItemStackBase::*rv)(); *((void**)&rv) = dlsym("?getEnchantsFromUserData@ItemStackBase@@QEBA?AVItemEnchants@@XZ"); return (this->*rv)();}
	// ??0ItemStackBase@@IEAA@AEBVItem@@@Z
	// ItemStackBase::ItemStackBase(class Item const &)
	// ??0ItemStackBase@@IEAA@AEBVItem@@HH@Z
	// ItemStackBase::ItemStackBase(class Item const &,int,int)
	// ??0ItemStackBase@@IEAA@AEBVBlock@@HPEBVCompoundTag@@@Z
	// ItemStackBase::ItemStackBase(class Block const &,int,class CompoundTag const *)
	// ??0ItemStackBase@@IEAA@AEBVBlockLegacy@@H@Z
	// ItemStackBase::ItemStackBase(class BlockLegacy const &,int)
	// ??0ItemStackBase@@IEAA@XZ
	// ItemStackBase::ItemStackBase(void)
	// ??0ItemStackBase@@IEAA@AEBV0@@Z
	// ItemStackBase::ItemStackBase(class ItemStackBase const &)
	// ??0ItemStackBase@@IEAA@AEBVItem@@HHPEBVCompoundTag@@@Z
	// ItemStackBase::ItemStackBase(class Item const &,int,int,class CompoundTag const *)
#endif
};
#pragma once
#include "Core.h"
class ItemStack : public ItemStackBase {
public:
	MCINLINE class ItemStack& operator=(class ItemStack const& a0) {
		class ItemStack& (ItemStack::*rv)(class ItemStack const&);
		*((void**)&rv) = dlsym("??4ItemStack@@QEAAAEAV0@AEBV0@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool sameItemAndAuxAndBlockData(class ItemStack const& a0) {
		bool (ItemStack::*rv)(class ItemStack const&);
		*((void**)&rv) = dlsym("?sameItemAndAuxAndBlockData@ItemStack@@QEBA_NAEBV1@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool useOn(class Actor& a0, int a1, int a2, int a3, unsigned char a4, float a5, float a6, float a7) {
		bool (ItemStack::*rv)(class Actor&, int, int, int, unsigned char, float, float, float);
		*((void**)&rv) = dlsym("?useOn@ItemStack@@QEAA_NAEAVActor@@HHHEMMM@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5, a6, a7);
	}
	MCINLINE void reinit(class BlockLegacy const& a0, int a1) {
		void (ItemStack::*rv)(class BlockLegacy const&, int);
		*((void**)&rv) = dlsym("?reinit@ItemStack@@UEAAXAEBVBlockLegacy@@H@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void useAsFuel() {
		void (ItemStack::*rv)();
		*((void**)&rv) = dlsym("?useAsFuel@ItemStack@@QEAAXXZ");
		return (this->*rv)();
	}
	MCINLINE void reinit(class Item const& a0, int a1, int a2) {
		void (ItemStack::*rv)(class Item const&, int, int);
		*((void**)&rv) = dlsym("?reinit@ItemStack@@MEAAXAEBVItem@@HH@Z");
		return (this->*rv)(a0, a1, a2);
	}

#if 0
//   bad fun  

	// ??0ItemStack@@QEAA@XZ
	// ItemStack::ItemStack(void)
	MCINLINE class ItemStack  fromTag(class CompoundTag const & a0,class Level & a1){
class ItemStack (ItemStack::*rv)(class CompoundTag const &,class Level &); *((void**)&rv) = dlsym("?fromTag@ItemStack@@SA?AV1@AEBVCompoundTag@@AEAVLevel@@@Z"); return (this->*rv)(a0,a1);}
	// ??0ItemStack@@QEAA@AEBVItem@@H@Z
	// ItemStack::ItemStack(class Item const &,int)
	MCINLINE class ItemStack  fromTag(class CompoundTag const & a0){
class ItemStack (ItemStack::*rv)(class CompoundTag const &); *((void**)&rv) = dlsym("?fromTag@ItemStack@@SA?AV1@AEBVCompoundTag@@@Z"); return (this->*rv)(a0);}
	MCINLINE class ItemStack  getStrippedNetworkItem(){
class ItemStack (ItemStack::*rv)(); *((void**)&rv) = dlsym("?getStrippedNetworkItem@ItemStack@@QEBA?AV1@XZ"); return (this->*rv)();}
#endif
};
#pragma once
#include "Core.h"
class Item {
public:
	MCINLINE class Item& setIcon(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, int a1) {
		class Item& (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, int);
		*((void**)&rv) = dlsym("?setIcon@Item@@UEAAAEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool inventoryTick(class ItemStack& a0, class Level& a1, class Actor& a2, int a3, bool a4) {
		bool (Item::*rv)(class ItemStack&, class Level&, class Actor&, int, bool);
		*((void**)&rv) = dlsym("?inventoryTick@Item@@UEBA_NAEAVItemStack@@AEAVLevel@@AEAVActor@@H_N@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE void _helpChangeInventoryItemInPlace(class Actor& a0, class ItemStack& a1, class ItemStack& a2, enum ItemAcquisitionMethod a3) {
		void (Item::*rv)(class Actor&, class ItemStack&, class ItemStack&, enum ItemAcquisitionMethod);
		*((void**)&rv) = dlsym("?_helpChangeInventoryItemInPlace@Item@@IEBAXAEAVActor@@AEAVItemStack@@1W4ItemAcquisitionMethod@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE bool isSameItem(class ItemStackBase const& a0, class ItemStackBase const& a1) {
		bool (Item::*rv)(class ItemStackBase const&, class ItemStackBase const&);
		*((void**)&rv) = dlsym("?isSameItem@Item@@UEBA_NAEBVItemStackBase@@0@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool canBeCharged() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?canBeCharged@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isExperimental(class ItemDescriptor const* a0) {
		bool (Item::*rv)(class ItemDescriptor const*);
		*((void**)&rv) = dlsym("?isExperimental@Item@@UEBA_NPEBVItemDescriptor@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool _useOn(class ItemInstance& a0, class Actor& a1, class BlockPos a2, unsigned char a3, float a4, float a5, float a6) {
		bool (Item::*rv)(class ItemInstance&, class Actor&, class BlockPos, unsigned char, float, float, float);
		*((void**)&rv) = dlsym("?_useOn@Item@@EEBA_NAEAVItemInstance@@AEAVActor@@VBlockPos@@EMMM@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5, a6);
	}
	MCINLINE class Item& setIcon(struct TextureUVCoordinateSet const& a0) {
		class Item& (Item::*rv)(struct TextureUVCoordinateSet const&);
		*((void**)&rv) = dlsym("?setIcon@Item@@UEAAAEAV1@AEBUTextureUVCoordinateSet@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool useOn(class ItemStack& a0, class Actor& a1, int a2, int a3, int a4, unsigned char a5, float a6, float a7, float a8) {
		bool (Item::*rv)(class ItemStack&, class Actor&, int, int, int, unsigned char, float, float, float);
		*((void**)&rv) = dlsym("?useOn@Item@@QEBA_NAEAVItemStack@@AEAVActor@@HHHEMMM@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
	}
	MCINLINE class Item& setExplodable(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setExplodable@Item@@UEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool initServer(class Json::Value& a0) {
		bool (Item::*rv)(class Json::Value&);
		*((void**)&rv) = dlsym("?initServer@Item@@QEAA_NAEAVValue@Json@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool canBeDepleted() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?canBeDepleted@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE class Item& setRequiresWorldBuilder(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setRequiresWorldBuilder@Item@@UEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE enum ItemUseMethod useTimeDepleted(class ItemInstance& a0, class Level* a1, class Player* a2) {
		enum ItemUseMethod (Item::*rv)(class ItemInstance&, class Level*, class Player*);
		*((void**)&rv) = dlsym("?useTimeDepleted@Item@@UEBA?AW4ItemUseMethod@@AEAVItemInstance@@PEAVLevel@@PEAVPlayer@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class Item& setMaxDamage(int a0) {
		class Item& (Item::*rv)(int);
		*((void**)&rv) = dlsym("?setMaxDamage@Item@@UEAAAEAV1@H@Z");
		return (this->*rv)(a0);
	}
	MCINLINE enum ItemUseMethod useTimeDepleted(class ItemStack& a0, class Level* a1, class Player* a2) {
		enum ItemUseMethod (Item::*rv)(class ItemStack&, class Level*, class Player*);
		*((void**)&rv) = dlsym("?useTimeDepleted@Item@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE class Item& setMaxUseDuration(int a0) {
		class Item& (Item::*rv)(int);
		*((void**)&rv) = dlsym("?setMaxUseDuration@Item@@UEAAAEAV1@H@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void hurtEnemy(class ItemInstance& a0, class Mob* a1, class Mob* a2) {
		void (Item::*rv)(class ItemInstance&, class Mob*, class Mob*);
		*((void**)&rv) = dlsym("?hurtEnemy@Item@@UEBAXAEAVItemInstance@@PEAVMob@@1@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE bool isTintable() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isTintable@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool mineBlock(class ItemStack& a0, class Block const& a1, int a2, int a3, int a4, class Actor* a5) {
		bool (Item::*rv)(class ItemStack&, class Block const&, int, int, int, class Actor*);
		*((void**)&rv) = dlsym("?mineBlock@Item@@UEBA_NAEAVItemStack@@AEBVBlock@@HHHPEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5);
	}
	MCINLINE class Item& setIsGlint(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setIsGlint@Item@@UEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE int getLevelDataForAuxValue(int a0) {
		int (Item::*rv)(int);
		*((void**)&rv) = dlsym("?getLevelDataForAuxValue@Item@@UEBAHH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void beginCreativeGroup(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, class Block const* a1, class CompoundTag const* a2) {
		void (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class Block const*, class CompoundTag const*);
		*((void**)&rv) = dlsym("?beginCreativeGroup@Item@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEBVBlock@@PEBVCompoundTag@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void beginCreativeGroup(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, class ItemInstance const& a1) {
		void (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class ItemInstance const&);
		*((void**)&rv) = dlsym("?beginCreativeGroup@Item@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE int getEnchantValue() {
		int (Item::*rv)();
		*((void**)&rv) = dlsym("?getEnchantValue@Item@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE class Item& setUseAnimation(enum UseAnimation a0) {
		class Item& (Item::*rv)(enum UseAnimation);
		*((void**)&rv) = dlsym("?setUseAnimation@Item@@UEAAAEAV1@W4UseAnimation@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class Item& setStackedByData(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setStackedByData@Item@@UEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE int getMaxUseDuration(class ItemStack const* a0) {
		int (Item::*rv)(class ItemStack const*);
		*((void**)&rv) = dlsym("?getMaxUseDuration@Item@@UEBAHPEBVItemStack@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void readAdditionalData(class ItemStackBase& a0, class CompoundTag const& a1) {
		void (Item::*rv)(class ItemStackBase&, class CompoundTag const&);
		*((void**)&rv) = dlsym("?readAdditionalData@Item@@UEBAXAEAVItemStackBase@@AEBVCompoundTag@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void writeUserData(class ItemStackBase const& a0, class IDataOutput& a1) {
		void (Item::*rv)(class ItemStackBase const&, class IDataOutput&);
		*((void**)&rv) = dlsym("?writeUserData@Item@@UEBAXAEBVItemStackBase@@AEAVIDataOutput@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool canDestroySpecial(class Block const& a0) {
		bool (Item::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?canDestroySpecial@Item@@UEBA_NAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE int getAnimationFrameFor(class Mob* a0, bool a1, class ItemStack const* a2, bool a3) {
		int (Item::*rv)(class Mob*, bool, class ItemStack const*, bool);
		*((void**)&rv) = dlsym("?getAnimationFrameFor@Item@@UEBAHPEAVMob@@_NPEBVItemStack@@_N@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE enum InHandUpdateType getInHandUpdateType(class Player const& a0, class ItemInstance const& a1, class ItemInstance const& a2, bool a3, bool a4) {
		enum InHandUpdateType (Item::*rv)(class Player const&, class ItemInstance const&, class ItemInstance const&, bool, bool);
		*((void**)&rv) = dlsym("?getInHandUpdateType@Item@@UEBA?AW4InHandUpdateType@@AEBVPlayer@@AEBVItemInstance@@1_N2@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE bool isFertilizer(int a0) {
		bool (Item::*rv)(int);
		*((void**)&rv) = dlsym("?isFertilizer@Item@@UEBA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool _calculatePlacePos(class ItemInstance& a0, class Actor& a1, unsigned char& a2, class BlockPos& a3) {
		bool (Item::*rv)(class ItemInstance&, class Actor&, unsigned char&, class BlockPos&);
		*((void**)&rv) = dlsym("?_calculatePlacePos@Item@@EEBA_NAEAVItemInstance@@AEAVActor@@AEAEAEAVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE class TextureAtlasItem const& getTextureItem(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0) {
		class TextureAtlasItem const& (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
		*((void**)&rv) = dlsym("?getTextureItem@Item@@SAAEBVTextureAtlasItem@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class Item& setCategory(enum CreativeItemCategory a0) {
		class Item& (Item::*rv)(enum CreativeItemCategory);
		*((void**)&rv) = dlsym("?setCategory@Item@@UEAAAEAV1@W4CreativeItemCategory@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool _useOn(class ItemStack& a0, class Actor& a1, class BlockPos a2, unsigned char a3, float a4, float a5, float a6) {
		bool (Item::*rv)(class ItemStack&, class Actor&, class BlockPos, unsigned char, float, float, float);
		*((void**)&rv) = dlsym("?_useOn@Item@@EEBA_NAEAVItemStack@@AEAVActor@@VBlockPos@@EMMM@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5, a6);
	}
	MCINLINE void releaseUsing(class ItemStack& a0, class Player* a1, int a2) {
		void (Item::*rv)(class ItemStack&, class Player*, int);
		*((void**)&rv) = dlsym("?releaseUsing@Item@@UEBAXAEAVItemStack@@PEAVPlayer@@H@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE struct TextureUVCoordinateSet const& getIconTextureUVSet(class TextureAtlasItem const& a0, int a1, int a2) {
		struct TextureUVCoordinateSet const& (Item::*rv)(class TextureAtlasItem const&, int, int);
		*((void**)&rv) = dlsym("?getIconTextureUVSet@Item@@SAAEBUTextureUVCoordinateSet@@AEBVTextureAtlasItem@@HH@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int getMaxUseDuration(class ItemInstance const* a0) {
		int (Item::*rv)(class ItemInstance const*);
		*((void**)&rv) = dlsym("?getMaxUseDuration@Item@@UEBAHPEBVItemInstance@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool dispense(class BlockSource& a0, class Container& a1, int a2, class Vec3 const& a3, unsigned char a4) {
		bool (Item::*rv)(class BlockSource&, class Container&, int, class Vec3 const&, unsigned char);
		*((void**)&rv) = dlsym("?dispense@Item@@UEBA_NAEAVBlockSource@@AEAVContainer@@HAEBVVec3@@E@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE void addCreativeItem(class Block const& a0) {
		void (Item::*rv)(class Block const&);
		*((void**)&rv) = dlsym("?addCreativeItem@Item@@SAXAEBVBlock@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isMultiColorTinted(class ItemStack const& a0) {
		bool (Item::*rv)(class ItemStack const&);
		*((void**)&rv) = dlsym("?isMultiColorTinted@Item@@UEBA_NAEBVItemStack@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isEmissive(int a0) {
		bool (Item::*rv)(int);
		*((void**)&rv) = dlsym("?isEmissive@Item@@UEBA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isArmor() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isArmor@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void saveAdditionalData(class ItemStackBase const& a0, class CompoundTag& a1) {
		void (Item::*rv)(class ItemStackBase const&, class CompoundTag&);
		*((void**)&rv) = dlsym("?saveAdditionalData@Item@@UEBAXAEBVItemStackBase@@AEAVCompoundTag@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE unsigned char getMaxStackSize(class ItemDescriptor const& a0) {
		unsigned char (Item::*rv)(class ItemDescriptor const&);
		*((void**)&rv) = dlsym("?getMaxStackSize@Item@@UEBAEAEBVItemDescriptor@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool uniqueAuxValues() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?uniqueAuxValues@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE int getArmorValue() {
		int (Item::*rv)();
		*((void**)&rv) = dlsym("?getArmorValue@Item@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE class Item& setAllowOffhand(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setAllowOffhand@Item@@QEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& getCommandName() {
		class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& (Item::*rv)();
		*((void**)&rv) = dlsym("?getCommandName@Item@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ");
		return (this->*rv)();
	} MCINLINE class Item& setIconAtlas(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, int a1) {
		class Item& (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, int);
		*((void**)&rv) = dlsym("?setIconAtlas@Item@@UEAAAEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool isThrowable() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isThrowable@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void readUserData(class ItemStackBase& a0, class IDataInput& a1, class ReadOnlyBinaryStream& a2) {
		void (Item::*rv)(class ItemStackBase&, class IDataInput&, class ReadOnlyBinaryStream&);
		*((void**)&rv) = dlsym("?readUserData@Item@@UEBAXAEAVItemStackBase@@AEAVIDataInput@@AEAVReadOnlyBinaryStream@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE float destroySpeedBonus(class ItemInstance const& a0) {
		float (Item::*rv)(class ItemInstance const&);
		*((void**)&rv) = dlsym("?destroySpeedBonus@Item@@IEBAMAEBVItemInstance@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void beginCreativeGroup(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, short a1, short a2, class CompoundTag const* a3) {
		void (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, short, short, class CompoundTag const*);
		*((void**)&rv) = dlsym("?beginCreativeGroup@Item@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@FFPEBVCompoundTag@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE enum BlockShape getBlockShape() {
		enum BlockShape (Item::*rv)();
		*((void**)&rv) = dlsym("?getBlockShape@Item@@UEBA?AW4BlockShape@@XZ");
		return (this->*rv)();
	}
	MCINLINE class Item& setHandEquipped() {
		class Item& (Item::*rv)();
		*((void**)&rv) = dlsym("?setHandEquipped@Item@@UEAAAEAV1@XZ");
		return (this->*rv)();
	}
	MCINLINE enum CooldownType getCooldownType() {
		enum CooldownType (Item::*rv)();
		*((void**)&rv) = dlsym("?getCooldownType@Item@@UEBA?AW4CooldownType@@XZ");
		return (this->*rv)();
	}
	MCINLINE int getCooldownTime() {
		int (Item::*rv)();
		*((void**)&rv) = dlsym("?getCooldownTime@Item@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE class Item& setMinRequiredBaseGameVersion(class BaseGameVersion const& a0) {
		class Item& (Item::*rv)(class BaseGameVersion const&);
		*((void**)&rv) = dlsym("?setMinRequiredBaseGameVersion@Item@@QEAAAEAV1@AEBVBaseGameVersion@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class Item& setShouldDespawn(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setShouldDespawn@Item@@UEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE class Item& setMaxStackSize(unsigned char a0) {
		class Item& (Item::*rv)(unsigned char);
		*((void**)&rv) = dlsym("?setMaxStackSize@Item@@UEAAAEAV1@E@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void playSoundIncrementally(class ItemStack const& a0, class Mob& a1) {
		void (Item::*rv)(class ItemStack const&, class Mob&);
		*((void**)&rv) = dlsym("?playSoundIncrementally@Item@@UEBAXAEBVItemStack@@AEAVMob@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void addCreativeItem(class ItemInstance const& a0) {
		void (Item::*rv)(class ItemInstance const&);
		*((void**)&rv) = dlsym("?addCreativeItem@Item@@SAXAEBVItemInstance@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE int getDamageChance(int a0) {
		int (Item::*rv)(int);
		*((void**)&rv) = dlsym("?getDamageChance@Item@@UEBAHH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool _checkUseOnPermissions(class Actor& a0, class ItemInstance& a1, unsigned char const& a2, class BlockPos const& a3) {
		bool (Item::*rv)(class Actor&, class ItemInstance&, unsigned char const&, class BlockPos const&);
		*((void**)&rv) = dlsym("?_checkUseOnPermissions@Item@@EEBA_NAEAVActor@@AEAVItemInstance@@AEBEAEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE float getDestroySpeed(class ItemInstance const& a0, class Block const& a1) {
		float (Item::*rv)(class ItemInstance const&, class Block const&);
		*((void**)&rv) = dlsym("?getDestroySpeed@Item@@UEBAMAEBVItemInstance@@AEBVBlock@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool showsDurabilityInCreative() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?showsDurabilityInCreative@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool mineBlock(class ItemInstance& a0, class Block const& a1, int a2, int a3, int a4, class Actor* a5) {
		bool (Item::*rv)(class ItemInstance&, class Block const&, int, int, int, class Actor*);
		*((void**)&rv) = dlsym("?mineBlock@Item@@UEBA_NAEAVItemInstance@@AEBVBlock@@HHHPEAVActor@@@Z");
		return (this->*rv)(a0, a1, a2, a3, a4, a5);
	}
	MCINLINE bool isDye() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isDye@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void fixupOnLoad(class ItemStackBase& a0) {
		void (Item::*rv)(class ItemStackBase&);
		*((void**)&rv) = dlsym("?fixupOnLoad@Item@@UEBAXAEAVItemStackBase@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isGlint(class ItemStackBase const& a0) {
		bool (Item::*rv)(class ItemStackBase const&);
		*((void**)&rv) = dlsym("?isGlint@Item@@UEBA_NAEBVItemStackBase@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE void playSoundIncrementally(class ItemInstance const& a0, class Mob& a1) {
		void (Item::*rv)(class ItemInstance const&, class Mob&);
		*((void**)&rv) = dlsym("?playSoundIncrementally@Item@@UEBAXAEBVItemInstance@@AEAVMob@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE struct TextureUVCoordinateSet const& getIcon(class ItemStackBase const& a0, int a1, bool a2) {
		struct TextureUVCoordinateSet const& (Item::*rv)(class ItemStackBase const&, int, bool);
		*((void**)&rv) = dlsym("?getIcon@Item@@UEBAAEBUTextureUVCoordinateSet@@AEBVItemStackBase@@H_N@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE int getIconYOffset() {
		int (Item::*rv)();
		*((void**)&rv) = dlsym("?getIconYOffset@Item@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE bool canDestroyInCreative() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?canDestroyInCreative@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isDestructive(int a0) {
		bool (Item::*rv)(int);
		*((void**)&rv) = dlsym("?isDestructive@Item@@UEBA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isComplex() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isComplex@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void addCreativeItem(class Item* a0, short a1) {
		void (Item::*rv)(class Item*, short);
		*((void**)&rv) = dlsym("?addCreativeItem@Item@@SAXPEAV1@F@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void hurtEnemy(class ItemStack& a0, class Mob* a1, class Mob* a2) {
		void (Item::*rv)(class ItemStack&, class Mob*, class Mob*);
		*((void**)&rv) = dlsym("?hurtEnemy@Item@@UEBAXAEAVItemStack@@PEAVMob@@1@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void releaseUsing(class ItemInstance& a0, class Player* a1, int a2) {
		void (Item::*rv)(class ItemInstance&, class Player*, int);
		*((void**)&rv) = dlsym("?releaseUsing@Item@@UEBAXAEAVItemInstance@@PEAVPlayer@@H@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE enum InHandUpdateType getInHandUpdateType(class Player const& a0, class ItemStack const& a1, class ItemStack const& a2, bool a3, bool a4) {
		enum InHandUpdateType (Item::*rv)(class Player const&, class ItemStack const&, class ItemStack const&, bool, bool);
		*((void**)&rv) = dlsym("?getInHandUpdateType@Item@@UEBA?AW4InHandUpdateType@@AEBVPlayer@@AEBVItemStack@@1_N2@Z");
		return (this->*rv)(a0, a1, a2, a3, a4);
	}
	MCINLINE bool isValidRepairItem(class ItemInstance const& a0, class ItemInstance const& a1) {
		bool (Item::*rv)(class ItemInstance const&, class ItemInstance const&);
		*((void**)&rv) = dlsym("?isValidRepairItem@Item@@UEBA_NAEBVItemInstance@@0@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void appendFormattedHovertext(class ItemStackBase const& a0, class Level& a1, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>& a2, bool a3) {
		void (Item::*rv)(class ItemStackBase const&, class Level&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>&, bool);
		*((void**)&rv) = dlsym("?appendFormattedHovertext@Item@@UEBAXAEBVItemStackBase@@AEAVLevel@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE void fixupOnLoad(class ItemStackBase& a0, class Level& a1) {
		void (Item::*rv)(class ItemStackBase&, class Level&);
		*((void**)&rv) = dlsym("?fixupOnLoad@Item@@UEBAXAEAVItemStackBase@@AEAVLevel@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE bool isHandEquipped() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isHandEquipped@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE int getEnchantSlot() {
		int (Item::*rv)();
		*((void**)&rv) = dlsym("?getEnchantSlot@Item@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE void setDamageValue(class ItemStackBase& a0, short a1) {
		void (Item::*rv)(class ItemStackBase&, short);
		*((void**)&rv) = dlsym("?setDamageValue@Item@@UEBAXAEAVItemStackBase@@F@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE int getAttackDamage() {
		int (Item::*rv)();
		*((void**)&rv) = dlsym("?getAttackDamage@Item@@UEBAHXZ");
		return (this->*rv)();
	}
	MCINLINE short getDamageValue(class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> const& a0) {
		short (Item::*rv)(class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> const&);
		*((void**)&rv) = dlsym("?getDamageValue@Item@@UEBAFAEBV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isPattern() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isPattern@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE void beginCreativeGroup(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a0, class Item* a1, short a2, class CompoundTag const* a3) {
		void (Item::*rv)(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class Item*, short, class CompoundTag const*);
		*((void**)&rv) = dlsym("?beginCreativeGroup@Item@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAV1@FPEBVCompoundTag@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE class ItemStack& use(class ItemStack& a0, class Player& a1) {
		class ItemStack& (Item::*rv)(class ItemStack&, class Player&);
		*((void**)&rv) = dlsym("?use@Item@@UEBAAEAVItemStack@@AEAV2@AEAVPlayer@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void tearDown() {
		void (Item::*rv)();
		*((void**)&rv) = dlsym("?tearDown@Item@@UEAAXXZ");
		return (this->*rv)();
	}
	MCINLINE bool isValidAuxValue(int a0) {
		bool (Item::*rv)(int);
		*((void**)&rv) = dlsym("?isValidAuxValue@Item@@UEBA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool isWearableThroughLootTable(class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> const& a0) {
		bool (Item::*rv)(class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> const&);
		*((void**)&rv) = dlsym("?isWearableThroughLootTable@Item@@UEBA_NAEBV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool requiresInteract() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?requiresInteract@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool isStackedByData() {
		bool (Item::*rv)();
		*((void**)&rv) = dlsym("?isStackedByData@Item@@UEBA_NXZ");
		return (this->*rv)();
	}
	MCINLINE bool _calculatePlacePos(class ItemStack& a0, class Actor& a1, unsigned char& a2, class BlockPos& a3) {
		bool (Item::*rv)(class ItemStack&, class Actor&, unsigned char&, class BlockPos&);
		*((void**)&rv) = dlsym("?_calculatePlacePos@Item@@EEBA_NAEAVItemStack@@AEAVActor@@AEAEAEAVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}
	MCINLINE class Item& setIsMirroredArt(bool a0) {
		class Item& (Item::*rv)(bool);
		*((void**)&rv) = dlsym("?setIsMirroredArt@Item@@QEAAAEAV1@_N@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool updateCustomBlockEntityTag(class BlockSource& a0, class ItemStack& a1, class BlockPos& a2) {
		bool (Item::*rv)(class BlockSource&, class ItemStack&, class BlockPos&);
		*((void**)&rv) = dlsym("?updateCustomBlockEntityTag@Item@@QEBA_NAEAVBlockSource@@AEAVItemStack@@AEAVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2);
	}
	MCINLINE void refreshedInContainer(class ItemStackBase& a0, class Level& a1) {
		void (Item::*rv)(class ItemStackBase&, class Level&);
		*((void**)&rv) = dlsym("?refreshedInContainer@Item@@UEBAXAEAVItemStackBase@@AEAVLevel@@@Z");
		return (this->*rv)(a0, a1);
	}
	MCINLINE void addCreativeItem(class ItemStack const& a0) {
		void (Item::*rv)(class ItemStack const&);
		*((void**)&rv) = dlsym("?addCreativeItem@Item@@SAXAEBVItemStack@@@Z");
		return (this->*rv)(a0);
	}
	MCINLINE short getMaxDamage() {
		short (Item::*rv)();
		*((void**)&rv) = dlsym("?getMaxDamage@Item@@UEBAFXZ");
		return (this->*rv)();
	}
	MCINLINE bool isLiquidClipItem(int a0) {
		bool (Item::*rv)(int);
		*((void**)&rv) = dlsym("?isLiquidClipItem@Item@@UEBA_NH@Z");
		return (this->*rv)(a0);
	}
	MCINLINE bool _checkUseOnPermissions(class Actor& a0, class ItemStack& a1, unsigned char const& a2, class BlockPos const& a3) {
		bool (Item::*rv)(class Actor&, class ItemStack&, unsigned char const&, class BlockPos const&);
		*((void**)&rv) = dlsym("?_checkUseOnPermissions@Item@@EEBA_NAEAVActor@@AEAVItemStack@@AEBEAEBVBlockPos@@@Z");
		return (this->*rv)(a0, a1, a2, a3);
	}

#if 0
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getSerializedName(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(); *((void**)&rv) = dlsym("?getSerializedName@Item@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  buildDescriptionId(class ItemDescriptor const & a0,class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> > const & a1){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(class ItemDescriptor const &,class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> > const &); *((void**)&rv) = dlsym("?buildDescriptionId@Item@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemDescriptor@@AEBV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@3@@Z"); return (this->*rv)(a0,a1);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  buildCategoryDescriptionName(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(); *((void**)&rv) = dlsym("?buildCategoryDescriptionName@Item@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  buildDescriptionName(class ItemStackBase const & a0){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(class ItemStackBase const &); *((void**)&rv) = dlsym("?buildDescriptionName@Item@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemStackBase@@@Z"); return (this->*rv)(a0);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getAuxValuesDescription(){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(); *((void**)&rv) = dlsym("?getAuxValuesDescription@Item@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ"); return (this->*rv)();}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  getInteractText(class Player const & a0){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(class Player const &); *((void**)&rv) = dlsym("?getInteractText@Item@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVPlayer@@@Z"); return (this->*rv)(a0);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >  buildEffectDescriptionName(class ItemStackBase const & a0){
class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (Item::*rv)(class ItemStackBase const &); *((void**)&rv) = dlsym("?buildEffectDescriptionName@Item@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemStackBase@@@Z"); return (this->*rv)(a0);}
//   bad fun  

	// ??0Item@@QEAA@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@F@Z
	// Item::Item(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,short)
	MCINLINE struct TextureUVCoordinateSet  getTextureUVCoordinateSet(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & a0,int a1){
struct TextureUVCoordinateSet (Item::*rv)(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const &,int); *((void**)&rv) = dlsym("?getTextureUVCoordinateSet@Item@@SA?AUTextureUVCoordinateSet@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z"); return (this->*rv)(a0,a1);}
	MCINLINE class Color  getColor(class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> > const & a0,class ItemDescriptor const & a1){
class Color (Item::*rv)(class std::unique_ptr<class CompoundTag,struct std::default_delete<class CompoundTag> > const &,class ItemDescriptor const &); *((void**)&rv) = dlsym("?getColor@Item@@UEBA?AVColor@@AEBV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBVItemDescriptor@@@Z"); return (this->*rv)(a0,a1);}
	MCINLINE class Color  getSecondaryColor(class ItemStack const & a0){
class Color (Item::*rv)(class ItemStack const &); *((void**)&rv) = dlsym("?getSecondaryColor@Item@@UEBA?AVColor@@AEBVItemStack@@@Z"); return (this->*rv)(a0);}
	MCINLINE class Color  getBaseColor(class ItemStack const & a0){
class Color (Item::*rv)(class ItemStack const &); *((void**)&rv) = dlsym("?getBaseColor@Item@@UEBA?AVColor@@AEBVItemStack@@@Z"); return (this->*rv)(a0);}
#endif
};
