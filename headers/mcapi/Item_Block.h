#pragma once
#include "Core.h"
class BlockLegacy {
public:
	MCAPI BlockLegacy(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, int, class Material const&);
	MCAPI bool operator==(class BlockLegacy const&) const;
	MCAPI bool addAABB(class AABB const&, class AABB const*, class std::vector<class AABB, class std::allocator<class AABB>>&) const;
	MCAPI class BlockLegacy& addBlockProperty(enum BlockProperty);
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> buildDescriptionName(class Block const&) const;
	MCAPI class HitResult clip(class BlockSource&, class BlockPos const&, class Vec3 const&, class Vec3 const&, bool, class AABB const&) const;
	MCAPI void createBlockPermutations(unsigned int);
	MCAPI void forEachBlockPermutation(class std::function<bool>) const;
	MCAPI void forEachItemStateInstance(class std::function<bool>) const;
	MCAPI short getBlockItemId(void) const;
	MCAPI void getDebugText(class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>>&, class BlockPos const&) const;
	MCAPI class Block const& getDefaultState(void) const;
	MCAPI class ItemActor* popResource(class BlockSource&, class BlockPos const&, class ItemInstance const&) const;
	MCAPI class BlockLegacy& setCanBeExtraBlock(bool);
	MCAPI class BlockLegacy& setCategory(enum CreativeItemCategory);
	MCAPI class BlockLegacy& setExperimental(void);
	MCAPI class BlockLegacy& setMinRequiredBaseGameVersion(class BaseGameVersion const&);
	MCAPI class BlockLegacy& setNameId(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
	MCAPI void spawnResources(class BlockSource&, class BlockPos const&, float, int) const;
	MCAPI class Block const* tryGetStateFromLegacyData(unsigned short) const;
	MCINLINE void addAABBs(class Block const& a0, class BlockSource& a1, class BlockPos const& a2, class AABB const* a3) const { Call("?addAABBs@BlockLegacy@@UEBAXAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@PEBVAABB@@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@@Z", void, BlockLegacy const*, class Block const&, class BlockSource&, class BlockPos const&, class AABB const*)(this, a0, a1, a2, a3); }
	MCINLINE bool addCollisionShapes(class Block const& a0, class BlockSource& a1, class BlockPos const& a2, class AABB const* a3) const { return Call("?addCollisionShapes@BlockLegacy@@UEBA_NAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@PEBVAABB@@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@PEAVActor@@@Z", bool, BlockLegacy const*, class Block const&, class BlockSource&, class BlockPos const&, class AABB const*)(this, a0, a1, a2, a3); }
	MCINLINE class BlockLegacy& addProperty(enum BlockProperty a0) { return Call("?addProperty@BlockLegacy@@UEAAAEAV1@W4BlockProperty@@@Z", class BlockLegacy&, BlockLegacy const*, enum BlockProperty)(this, a0); }
	MCINLINE class BlockLegacy& addState(class ItemState const& a0) { return Call("?addState@BlockLegacy@@UEAAAEAV1@AEBVItemState@@@Z", class BlockLegacy&, BlockLegacy const*, class ItemState const&)(this, a0); }
	MCINLINE class BlockLegacy& addState(class ItemState const& a0, unsigned __int64 a1) { return Call("?addState@BlockLegacy@@UEAAAEAV1@AEBVItemState@@_K@Z", class BlockLegacy&, BlockLegacy const*, class ItemState const&, unsigned __int64)(this, a0, a1); }
	MCINLINE void animateTick(class BlockSource& a0, class BlockPos const& a1, class Random& a2) const { Call("?animateTick@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Random&)(this, a0, a1, a2); }
	MCINLINE bool attack(class Player* a0, class BlockPos const& a1) const { return Call("?attack@BlockLegacy@@UEBA_NPEAVPlayer@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class Player*, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool breaksFallingBlocks(class Block const& a0) const { return Call("?breaksFallingBlocks@BlockLegacy@@UEBA_NAEBVBlock@@@Z", bool, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE float calcGroundFriction(class Mob& a0, class BlockPos const& a1) const { return Call("?calcGroundFriction@BlockLegacy@@UEBAMAEAVMob@@AEBVBlockPos@@@Z", float, BlockLegacy const*, class Mob&, class BlockPos const&)(this, a0, a1); }
	MCINLINE int calcVariant(class BlockSource& a0, class BlockPos const& a1) const { return Call("?calcVariant@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool canBeBuiltOver(class BlockSource& a0, class BlockPos const& a1) const { return Call("?canBeBuiltOver@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool canBeOriginalSurface() const { return Call("?canBeOriginalSurface@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool canBeSilkTouched() const { return Call("?canBeSilkTouched@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool canBeUsedInCommands(bool a0, class BaseGameVersion const& a1) const { return Call("?canBeUsedInCommands@BlockLegacy@@UEBA_N_NAEBVBaseGameVersion@@@Z", bool, BlockLegacy const*, bool, class BaseGameVersion const&)(this, a0, a1); }
	MCINLINE bool canConnect(class Block const& a0, unsigned char a1, class Block const& a2) const { return Call("?canConnect@BlockLegacy@@UEBA_NAEBVBlock@@E0@Z", bool, BlockLegacy const*, class Block const&, unsigned char, class Block const&)(this, a0, a1, a2); }
	MCINLINE bool canContainLiquid() const { return Call("?canContainLiquid@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool canFillAtPos(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { return Call("?canFillAtPos@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE bool canHaveExtraData() const { return Call("?canHaveExtraData@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool canHurtAndBreakItem() const { return Call("?canHurtAndBreakItem@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool canProvideSupport(class Block const& a0, unsigned char a1, enum BlockSupportType a2) const { return Call("?canProvideSupport@BlockLegacy@@UEBA_NAEBVBlock@@EW4BlockSupportType@@@Z", bool, BlockLegacy const*, class Block const&, unsigned char, enum BlockSupportType)(this, a0, a1, a2); }
	MCINLINE bool canSlide(class BlockSource& a0, class BlockPos const& a1) const { return Call("?canSlide@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool canSpawnOn() const { return Call("?canSpawnOn@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool canSurvive(class BlockSource& a0, class BlockPos const& a1) const { return Call("?canSurvive@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool checkIsPathable(class Actor& a0, class BlockPos const& a1, class BlockPos const& a2) const { return Call("?checkIsPathable@BlockLegacy@@UEBA_NAEAVActor@@AEBVBlockPos@@1@Z", bool, BlockLegacy const*, class Actor&, class BlockPos const&, class BlockPos const&)(this, a0, a1, a2); }
	MCINLINE bool dealsContactDamage(class Actor const& a0, class Block const& a1, bool a2) const { return Call("?dealsContactDamage@BlockLegacy@@UEBA_NAEBVActor@@AEBVBlock@@_N@Z", bool, BlockLegacy const*, class Actor const&, class Block const&, bool)(this, a0, a1, a2); }
	MCINLINE void destroy(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, class Actor* a3) const { Call("?destroy@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@PEAVActor@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&, class Actor*)(this, a0, a1, a2, a3); }
	MCINLINE bool detachesOnPistonMove(class BlockSource& a0, class BlockPos const& a1) const { return Call("?detachesOnPistonMove@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool dispense(class BlockSource& a0, class Container& a1, int a2, class Vec3 const& a3, unsigned char a4) const { return Call("?dispense@BlockLegacy@@UEBA_NAEAVBlockSource@@AEAVContainer@@HAEBVVec3@@E@Z", bool, BlockLegacy const*, class BlockSource&, class Container&, int, class Vec3 const&, unsigned char)(this, a0, a1, a2, a3, a4); }
	MCINLINE void entityInside(class BlockSource& a0, class BlockPos const& a1, class Actor& a2) const { Call("?entityInside@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVActor@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor&)(this, a0, a1, a2); }
	MCINLINE void executeEvent(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { Call("?executeEvent@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVActor@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE class AABB const& getAABB(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, class AABB& a3, bool a4) const { return Call("?getAABB@BlockLegacy@@UEBAAEBVAABB@@AEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEAV2@_N@Z", class AABB const&, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&, class AABB&, bool)(this, a0, a1, a2, a3, a4); }
	MCINLINE bool getCollisionShape(class AABB& a0, class Block const& a1, class BlockSource& a2, class BlockPos const& a3, class Actor* a4) const { return Call("?getCollisionShape@BlockLegacy@@UEBA_NAEAVAABB@@AEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@PEAVActor@@@Z", bool, BlockLegacy const*, class AABB&, class Block const&, class BlockSource&, class BlockPos const&, class Actor*)(this, a0, a1, a2, a3, a4); }
	MCINLINE int getColor(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { return Call("?getColor@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE int getColor(class Block const& a0) const { return Call("?getColor@BlockLegacy@@UEBAHAEBVBlock@@@Z", int, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE int getColorAtPos(class BlockSource& a0, class BlockPos const& a1) const { return Call("?getColorAtPos@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE int getColorForParticle(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { return Call("?getColorForParticle@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE int getComparatorSignal(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, unsigned char a3) const { return Call("?getComparatorSignal@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@E@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&, unsigned char)(this, a0, a1, a2, a3); }
	MCINLINE void getConnectedDirections(class Block const& a0, class BlockPos const& a1, class BlockSource& a2, bool& a3, bool& a4, bool& a5, bool& a6) const { Call("?getConnectedDirections@BlockLegacy@@UEBAXAEBVBlock@@AEBVBlockPos@@AEAVBlockSource@@AEA_N333@Z", void, BlockLegacy const*, class Block const&, class BlockPos const&, class BlockSource&, bool&, bool&, bool&, bool&)(this, a0, a1, a2, a3, a4, a5, a6); }
	MCINLINE int getDirectSignal(class BlockSource& a0, class BlockPos const& a1, int a2) const { return Call("?getDirectSignal@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@H@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&, int)(this, a0, a1, a2); }
	MCINLINE int getExperienceDrop(class Random& a0) const { return Call("?getExperienceDrop@BlockLegacy@@UEBAHAEAVRandom@@@Z", int, BlockLegacy const*, class Random&)(this, a0); }
	MCINLINE float getExplosionResistance(class Actor* a0) const { return Call("?getExplosionResistance@BlockLegacy@@UEBAMPEAVActor@@@Z", float, BlockLegacy const*, class Actor*)(this, a0); }
	MCINLINE int getExtraRenderLayers() const { return Call("?getExtraRenderLayers@BlockLegacy@@UEBAHXZ", int, BlockLegacy const*)(this); }
	MCINLINE enum Flip getFaceFlip(unsigned char a0, class Block const& a1) const { return Call("?getFaceFlip@BlockLegacy@@UEBA?AW4Flip@@EAEBVBlock@@@Z", enum Flip, BlockLegacy const*, unsigned char, class Block const&)(this, a0, a1); }
	MCINLINE float getFlexibility(class BlockSource& a0, class BlockPos const& a1) const { return Call("?getFlexibility@BlockLegacy@@UEBAMAEAVBlockSource@@AEBVBlockPos@@@Z", float, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE int getIconYOffset() const { return Call("?getIconYOffset@BlockLegacy@@UEBAHXZ", int, BlockLegacy const*)(this); }
	MCINLINE bool getIgnoresDestroyPermissions(class Actor& a0, class BlockPos const& a1) const { return Call("?getIgnoresDestroyPermissions@BlockLegacy@@UEBA_NAEAVActor@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class Actor&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool getLiquidClipVolume(class BlockSource& a0, class BlockPos const& a1, class AABB& a2) const { return Call("?getLiquidClipVolume@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVAABB@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class AABB&)(this, a0, a1, a2); }
	MCINLINE unsigned char getMappedFace(unsigned char a0, class Block const& a1) const { return Call("?getMappedFace@BlockLegacy@@UEBAEEAEBVBlock@@@Z", unsigned char, BlockLegacy const*, unsigned char, class Block const&)(this, a0, a1); }
	MCINLINE class MobSpawnerData const* getMobToSpawn(class SpawnConditions const& a0, class BlockSource& a1) const { return Call("?getMobToSpawn@BlockLegacy@@UEBAPEBVMobSpawnerData@@AEBVSpawnConditions@@AEAVBlockSource@@@Z", class MobSpawnerData const*, BlockLegacy const*, class SpawnConditions const&, class BlockSource&)(this, a0, a1); }
	MCINLINE class Block const* getNextBlockPermutation(class Block const& a0) const { return Call("?getNextBlockPermutation@BlockLegacy@@UEBAPEBVBlock@@AEBV2@@Z", class Block const*, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE class AABB const& getOutline(class BlockSource& a0, class BlockPos const& a1, class AABB& a2) const { return Call("?getOutline@BlockLegacy@@UEBAAEBVAABB@@AEAVBlockSource@@AEBVBlockPos@@AEAV2@@Z", class AABB const&, BlockLegacy const*, class BlockSource&, class BlockPos const&, class AABB&)(this, a0, a1, a2); }
	MCINLINE class Block const& getPlacementBlock(class Actor& a0, class BlockPos const& a1, unsigned char a2, class Vec3 const& a3, int a4) const { return Call("?getPlacementBlock@BlockLegacy@@UEBAAEBVBlock@@AEAVActor@@AEBVBlockPos@@EAEBVVec3@@H@Z", class Block const&, BlockLegacy const*, class Actor&, class BlockPos const&, unsigned char, class Vec3 const&, int)(this, a0, a1, a2, a3, a4); }
	MCINLINE enum BlockProperty getRedstoneProperty(class BlockSource& a0, class BlockPos const& a1) const { return Call("?getRedstoneProperty@BlockLegacy@@UEBA?AW4BlockProperty@@AEAVBlockSource@@AEBVBlockPos@@@Z", enum BlockProperty, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE enum BlockRenderLayer getRenderLayer(class Block const& a0, class BlockSource& a1, class BlockPos const& a2) const { return Call("?getRenderLayer@BlockLegacy@@UEBA?AW4BlockRenderLayer@@AEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@@Z", enum BlockRenderLayer, BlockLegacy const*, class Block const&, class BlockSource&, class BlockPos const&)(this, a0, a1, a2); }
	MCINLINE enum BlockRenderLayer getRenderLayer() const { return Call("?getRenderLayer@BlockLegacy@@UEBA?AW4BlockRenderLayer@@XZ", enum BlockRenderLayer, BlockLegacy const*)(this); }
	MCINLINE int getResourceCount(class Random& a0, class Block const& a1, int a2) const { return Call("?getResourceCount@BlockLegacy@@UEBAHAEAVRandom@@AEBVBlock@@H@Z", int, BlockLegacy const*, class Random&, class Block const&, int)(this, a0, a1, a2); }
	MCINLINE bool getSecondPart(class BlockSource& a0, class BlockPos const& a1, class BlockPos& a2) const { return Call("?getSecondPart@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAV3@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class BlockPos&)(this, a0, a1, a2); }
	MCINLINE float getShadeBrightness() const { return Call("?getShadeBrightness@BlockLegacy@@UEBAMXZ", float, BlockLegacy const*)(this); }
	MCINLINE class Block const& getStateFromLegacyData(unsigned short a0) const { return Call("?getStateFromLegacyData@BlockLegacy@@UEBAAEBVBlock@@G@Z", class Block const&, BlockLegacy const*, unsigned short)(this, a0); }
	MCINLINE class Block const& getStrippedBlock(class Block const& a0) const { return Call("?getStrippedBlock@BlockLegacy@@UEBAAEBVBlock@@AEBV2@@Z", class Block const&, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE float getThickness() const { return Call("?getThickness@BlockLegacy@@UEBAMXZ", float, BlockLegacy const*)(this); }
	MCINLINE class AABB const& getUIShape(class Block const& a0, class AABB& a1) const { return Call("?getUIShape@BlockLegacy@@UEBAAEBVAABB@@AEBVBlock@@AEAV2@@Z", class AABB const&, BlockLegacy const*, class Block const&, class AABB&)(this, a0, a1); }
	MCINLINE int getVariant(class Block const& a0) const { return Call("?getVariant@BlockLegacy@@UEBAHAEBVBlock@@@Z", int, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE class AABB const& getVisualShape(class Block const& a0, class AABB& a1, bool a2) const { return Call("?getVisualShape@BlockLegacy@@UEBAAEBVAABB@@AEBVBlock@@AEAV2@_N@Z", class AABB const&, BlockLegacy const*, class Block const&, class AABB&, bool)(this, a0, a1, a2); }
	MCINLINE class AABB const& getVisualShapeInWorld(class Block const& a0, class BlockSource& a1, class BlockPos const& a2, class AABB& a3, bool a4) const { return Call("?getVisualShapeInWorld@BlockLegacy@@UEBAAEBVAABB@@AEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@AEAV2@_N@Z", class AABB const&, BlockLegacy const*, class Block const&, class BlockSource&, class BlockPos const&, class AABB&, bool)(this, a0, a1, a2, a3, a4); }
	MCINLINE void handleEntityInside(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, class Vec3& a3) const { Call("?handleEntityInside@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@AEAVVec3@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor*, class Vec3&)(this, a0, a1, a2, a3); }
	MCINLINE void handleRain(class BlockSource& a0, class BlockPos const& a1, float a2) const { Call("?handleRain@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@M@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, float)(this, a0, a1, a2); }
	MCINLINE bool hasComparatorSignal() const { return Call("?hasComparatorSignal@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool hasTag(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { return Call("?hasTag@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE bool hasVariableLighting() const { return Call("?hasVariableLighting@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool ignoreEntitiesOnPistonMove(class Block const& a0) const { return Call("?ignoreEntitiesOnPistonMove@BlockLegacy@@UEBA_NAEBVBlock@@@Z", bool, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE class BlockLegacy& init() { return Call("?init@BlockLegacy@@UEAAAEAV1@XZ", class BlockLegacy&, BlockLegacy const*)(this); }
	MCINLINE bool isAttachedTo(class BlockSource& a0, class BlockPos const& a1, class BlockPos& a2) const { return Call("?isAttachedTo@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAV3@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class BlockPos&)(this, a0, a1, a2); }
	MCINLINE bool isAuxValueRelevantForPicking() const { return Call("?isAuxValueRelevantForPicking@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isBounceBlock() const { return Call("?isBounceBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isButtonBlock() const { return Call("?isButtonBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isContainerBlock() const { return Call("?isContainerBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isCraftingBlock() const { return Call("?isCraftingBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isCropBlock() const { return Call("?isCropBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isDoorBlock() const { return Call("?isDoorBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isFenceBlock() const { return Call("?isFenceBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isFenceGateBlock() const { return Call("?isFenceGateBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isHurtableBlock() const { return Call("?isHurtableBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isInteractiveBlock() const { return Call("?isInteractiveBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isObstructingChests(class BlockSource& a0, class BlockPos const& a1) const { return Call("?isObstructingChests@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool isRailBlock() const { return Call("?isRailBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isSeasonTinted(class Block const& a0, class BlockSource& a1, class BlockPos const& a2) const { return Call("?isSeasonTinted@BlockLegacy@@UEBA_NAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class Block const&, class BlockSource&, class BlockPos const&)(this, a0, a1, a2); }
	MCINLINE bool isSignalSource() const { return Call("?isSignalSource@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isSlabBlock() const { return Call("?isSlabBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isStairBlock() const { return Call("?isStairBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isStemBlock() const { return Call("?isStemBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isStrippable(class Block const& a0) const { return Call("?isStrippable@BlockLegacy@@UEBA_NAEBVBlock@@@Z", bool, BlockLegacy const*, class Block const&)(this, a0); }
	MCINLINE bool isThinFenceBlock() const { return Call("?isThinFenceBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isValidAuxValue(int a0) const { return Call("?isValidAuxValue@BlockLegacy@@UEBA_NH@Z", bool, BlockLegacy const*, int)(this, a0); }
	MCINLINE bool isWallBlock() const { return Call("?isWallBlock@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool isWaterBlocking() const { return Call("?isWaterBlocking@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool liquidCanFlowIntoFromDirection(unsigned char a0) const { return Call("?liquidCanFlowIntoFromDirection@BlockLegacy@@UEBA_NEAEBV?$function@$$A6AAEBVBlock@@AEBVBlockPos@@@Z@std@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, unsigned char)(this, a0); }
	MCINLINE bool mayConsumeFertilizer(class BlockSource& a0) const { return Call("?mayConsumeFertilizer@BlockLegacy@@UEBA_NAEAVBlockSource@@@Z", bool, BlockLegacy const*, class BlockSource&)(this, a0); }
	MCINLINE bool mayPick(class BlockSource& a0, class Block const& a1, bool a2) const { return Call("?mayPick@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlock@@_N@Z", bool, BlockLegacy const*, class BlockSource&, class Block const&, bool)(this, a0, a1, a2); }
	MCINLINE bool mayPick() const { return Call("?mayPick@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool mayPlace(class BlockSource& a0, class BlockPos const& a1) const { return Call("?mayPlace@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool mayPlace(class BlockSource& a0, class BlockPos const& a1, unsigned char a2) const { return Call("?mayPlace@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@E@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, unsigned char)(this, a0, a1, a2); }
	MCINLINE bool mayPlaceOn(class BlockSource& a0, class BlockPos const& a1) const { return Call("?mayPlaceOn@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void movedByPiston(class BlockSource& a0, class BlockPos const& a1) const { Call("?movedByPiston@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void neighborChanged(class BlockSource& a0, class BlockPos const& a1, class BlockPos const& a2) const { Call("?neighborChanged@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@1@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class BlockPos const&)(this, a0, a1, a2); }
	MCINLINE void onExploded(class BlockSource& a0, class BlockPos const& a1, class Actor* a2) const { Call("?onExploded@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor*)(this, a0, a1, a2); }
	MCINLINE void onFallOn(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, float a3) const { Call("?onFallOn@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor*, float)(this, a0, a1, a2, a3); }
	MCINLINE bool onFertilized(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, enum FertilizerType a3) const { return Call("?onFertilized@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@W4FertilizerType@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor*, enum FertilizerType)(this, a0, a1, a2, a3); }
	MCINLINE void onFillBlock(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { Call("?onFillBlock@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE void onGraphicsModeChanged(bool a0, bool a1, bool a2) { Call("?onGraphicsModeChanged@BlockLegacy@@UEAAX_N00@Z", void, BlockLegacy const*, bool, bool, bool)(this, a0, a1, a2); }
	MCINLINE void onMove(class BlockSource& a0, class BlockPos const& a1, class BlockPos const& a2) const { Call("?onMove@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@1@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class BlockPos const&)(this, a0, a1, a2); }
	MCINLINE void onPlace(class BlockSource& a0, class BlockPos const& a1) const { Call("?onPlace@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void onProjectileHit(class BlockSource& a0, class BlockPos const& a1, class Actor const& a2) const { Call("?onProjectileHit@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVActor@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor const&)(this, a0, a1, a2); }
	MCINLINE void onRedstoneUpdate(class BlockSource& a0, class BlockPos const& a1, int a2, bool a3) const { Call("?onRedstoneUpdate@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@H_N@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, int, bool)(this, a0, a1, a2, a3); }
	MCINLINE void onRemove(class BlockSource& a0, class BlockPos const& a1) const { Call("?onRemove@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void onStepOn(class Actor& a0, class BlockPos const& a1) const { Call("?onStepOn@BlockLegacy@@UEBAXAEAVActor@@AEBVBlockPos@@@Z", void, BlockLegacy const*, class Actor&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void playerDestroy(class Player& a0, class BlockPos const& a1, class Block const& a2) const { Call("?playerDestroy@BlockLegacy@@UEBAXAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z", void, BlockLegacy const*, class Player&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE bool playerWillDestroy(class Player& a0, class BlockPos const& a1, class Block const& a2) const { return Call("?playerWillDestroy@BlockLegacy@@UEBA_NAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z", bool, BlockLegacy const*, class Player&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE bool pushesUpFallingBlocks() const { return Call("?pushesUpFallingBlocks@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE class Block const& sanitizeFillBlock(class BlockSource& a0, class BlockPos const& a1, class Block const& a2) const { return Call("?sanitizeFillBlock@BlockLegacy@@UEBAAEBVBlock@@AEAVBlockSource@@AEBVBlockPos@@AEBV2@@Z", class Block const&, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&)(this, a0, a1, a2); }
	MCINLINE class BlockLegacy& setAllowsRunes(bool a0) { return Call("?setAllowsRunes@BlockLegacy@@UEAAAEAV1@_N@Z", class BlockLegacy&, BlockLegacy const*, bool)(this, a0); }
	MCINLINE class BlockLegacy& setDestroyTime(float a0) { return Call("?setDestroyTime@BlockLegacy@@UEAAAEAV1@M@Z", class BlockLegacy&, BlockLegacy const*, float)(this, a0); }
	MCINLINE class BlockLegacy& setExplodeable(float a0) { return Call("?setExplodeable@BlockLegacy@@UEAAAEAV1@M@Z", class BlockLegacy&, BlockLegacy const*, float)(this, a0); }
	MCINLINE class BlockLegacy& setFriction(float a0) { return Call("?setFriction@BlockLegacy@@UEAAAEAV1@M@Z", class BlockLegacy&, BlockLegacy const*, float)(this, a0); }
	MCINLINE class BlockLegacy& setLightEmission(float a0) { return Call("?setLightEmission@BlockLegacy@@UEAAAEAV1@M@Z", class BlockLegacy&, BlockLegacy const*, float)(this, a0); }
	MCINLINE class BlockLegacy& setMapColor(class Color const& a0) { return Call("?setMapColor@BlockLegacy@@UEAAAEAV1@AEBVColor@@@Z", class BlockLegacy&, BlockLegacy const*, class Color const&)(this, a0); }
	MCINLINE void setVisualShape(class AABB const& a0) { Call("?setVisualShape@BlockLegacy@@UEAAXAEBVAABB@@@Z", void, BlockLegacy const*, class AABB const&)(this, a0); }
	MCINLINE void setVisualShape(class Vec3 const& a0, class Vec3 const& a1) { Call("?setVisualShape@BlockLegacy@@UEAAXAEBVVec3@@0@Z", void, BlockLegacy const*, class Vec3 const&, class Vec3 const&)(this, a0, a1); }
	MCINLINE void setupRedstoneComponent(class BlockSource& a0, class BlockPos const& a1) const { Call("?setupRedstoneComponent@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool shouldConnectToRedstone(class BlockSource& a0, class BlockPos const& a1, int a2) const { return Call("?shouldConnectToRedstone@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@H@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, int)(this, a0, a1, a2); }
	MCINLINE bool shouldDispense(class BlockSource& a0, class Container& a1) const { return Call("?shouldDispense@BlockLegacy@@UEBA_NAEAVBlockSource@@AEAVContainer@@@Z", bool, BlockLegacy const*, class BlockSource&, class Container&)(this, a0, a1); }
	MCINLINE bool shouldRandomTick() const { return Call("?shouldRandomTick@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
	MCINLINE bool shouldStopFalling(class Actor& a0) const { return Call("?shouldStopFalling@BlockLegacy@@UEBA_NAEAVActor@@@Z", bool, BlockLegacy const*, class Actor&)(this, a0); }
	MCINLINE bool spawnBurnResources(class BlockSource& a0, float a1, float a2, float a3) const { return Call("?spawnBurnResources@BlockLegacy@@UEBA_NAEAVBlockSource@@MMM@Z", bool, BlockLegacy const*, class BlockSource&, float, float, float)(this, a0, a1, a2, a3); }
	MCINLINE void spawnResources(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, float a3, int a4) const { Call("?spawnResources@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@MH@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&, float, int)(this, a0, a1, a2, a3, a4); }
	MCINLINE int telemetryVariant(class BlockSource& a0, class BlockPos const& a1) const { return Call("?telemetryVariant@BlockLegacy@@UEBAHAEAVBlockSource@@AEBVBlockPos@@@Z", int, BlockLegacy const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void tick(class BlockSource& a0, class BlockPos const& a1, class Random& a2) const { Call("?tick@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Random&)(this, a0, a1, a2); }
	MCINLINE void transformOnFall(class BlockSource& a0, class BlockPos const& a1, class Actor* a2, float a3) const { Call("?transformOnFall@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Actor*, float)(this, a0, a1, a2, a3); }
	MCINLINE void triggerEvent(class BlockSource& a0, class BlockPos const& a1, int a2, int a3) const { Call("?triggerEvent@BlockLegacy@@UEBAXAEAVBlockSource@@AEBVBlockPos@@HH@Z", void, BlockLegacy const*, class BlockSource&, class BlockPos const&, int, int)(this, a0, a1, a2, a3); }
	MCINLINE class Block const* tryLegacyUpgrade(unsigned short a0) const { return Call("?tryLegacyUpgrade@BlockLegacy@@UEBAPEBVBlock@@G@Z", class Block const*, BlockLegacy const*, unsigned short)(this, a0); }
	MCINLINE bool tryToPlace(class BlockSource& a0, class BlockPos const& a1, class Block const& a2, struct ActorBlockSyncMessage const* a3) const { return Call("?tryToPlace@BlockLegacy@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@PEBUActorBlockSyncMessage@@@Z", bool, BlockLegacy const*, class BlockSource&, class BlockPos const&, class Block const&, struct ActorBlockSyncMessage const*)(this, a0, a1, a2, a3); }
	MCINLINE void updateEntityAfterFallOn(class Actor& a0) const { Call("?updateEntityAfterFallOn@BlockLegacy@@UEBAXAEAVActor@@@Z", void, BlockLegacy const*, class Actor&)(this, a0); }
	MCINLINE bool use(class Player& a0, class BlockPos const& a1) const { return Call("?use@BlockLegacy@@UEBA_NAEAVPlayer@@AEBVBlockPos@@@Z", bool, BlockLegacy const*, class Player&, class BlockPos const&)(this, a0, a1); }
	MCINLINE bool waterSpreadCausesSpawn() const { return Call("?waterSpreadCausesSpawn@BlockLegacy@@UEBA_NXZ", bool, BlockLegacy const*)(this); }
#if 0
/* std || und args */
	MCINLINE class BlockLegacy & setLightBlock(struct Brightness a0){ return Call("?setLightBlock@BlockLegacy@@UEAAAEAV1@UBrightness@@@Z",class BlockLegacy & ,BlockLegacy const*,struct Brightness)(this,a0);}
	/* bad retval */
	MCINLINE class ItemInstance asItemInstance(class BlockSource & a0,class BlockPos const & a1,class Block const & a2)const { return Call("?asItemInstance@BlockLegacy@@UEBA?AVItemInstance@@AEAVBlockSource@@AEBVBlockPos@@AEBVBlock@@@Z",class ItemInstance ,BlockLegacy const*,class BlockSource &,class BlockPos const &,class Block const &)(this,a0,a1,a2);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > buildDescriptionId(class Block const & a0)const { return Call("?buildDescriptionId@BlockLegacy@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlock@@@Z",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,BlockLegacy const*,class Block const &)(this,a0);}
	MCINLINE class HitResult clip(class BlockSource & a0,class BlockPos const & a1,class Vec3 const & a2,class Vec3 const & a3,bool a4)const { return Call("?clip@BlockLegacy@@UEBA?AVHitResult@@AEAVBlockSource@@AEBVBlockPos@@AEBVVec3@@2_N@Z",class HitResult ,BlockLegacy const*,class BlockSource &,class BlockPos const &,class Vec3 const &,class Vec3 const &,bool)(this,a0,a1,a2,a3,a4);}
	MCINLINE struct Brightness getLightEmission(class Block const & a0)const { return Call("?getLightEmission@BlockLegacy@@UEBA?AUBrightness@@AEBVBlock@@@Z",struct Brightness ,BlockLegacy const*,class Block const &)(this,a0);}
	MCINLINE class Color getMapColor(class BlockSource & a0,class BlockPos const & a1)const { return Call("?getMapColor@BlockLegacy@@UEBA?AVColor@@AEAVBlockSource@@AEBVBlockPos@@@Z",class Color ,BlockLegacy const*,class BlockSource &,class BlockPos const &)(this,a0,a1);}
	MCINLINE class Color getMapColor()const { return Call("?getMapColor@BlockLegacy@@UEBA?AVColor@@XZ",class Color ,BlockLegacy const*)(this);}
	MCINLINE class ItemInstance getResourceItem(class Random & a0,class Block const & a1,int a2)const { return Call("?getResourceItem@BlockLegacy@@UEBA?AVItemInstance@@AEAVRandom@@AEBVBlock@@H@Z",class ItemInstance ,BlockLegacy const*,class Random &,class Block const &,int)(this,a0,a1,a2);}
	MCINLINE class ItemInstance getSilkTouchItemInstance(class Block const & a0)const { return Call("?getSilkTouchItemInstance@BlockLegacy@@UEBA?AVItemInstance@@AEBVBlock@@@Z",class ItemInstance ,BlockLegacy const*,class Block const &)(this,a0);}
	MCINLINE class Vec3 randomlyModifyPosition(class BlockPos const & a0)const { return Call("?randomlyModifyPosition@BlockLegacy@@UEBA?AVVec3@@AEBVBlockPos@@@Z",class Vec3 ,BlockLegacy const*,class BlockPos const &)(this,a0);}
	MCINLINE class Vec3 randomlyModifyPosition(class BlockPos const & a0,int & a1)const { return Call("?randomlyModifyPosition@BlockLegacy@@UEBA?AVVec3@@AEBVBlockPos@@AEAH@Z",class Vec3 ,BlockLegacy const*,class BlockPos const &,int &)(this,a0,a1);}
#endif
};

class Block:public BlockLegacy {
public:
	MCAPI class Block const& copyState(class Block const&, class ItemState const&) const;
	MCAPI class BlockLegacy const& getLegacyBlock(void) const;
	MCAPI bool hasState(class ItemState const&) const;
	MCAPI bool isSlabBlock(void) const;
	MCAPI bool isSolidBlockingBlock(void) const;
	MCAPI bool isSolidBlockingBlockAndNotSignalSource(void) const;
	MCAPI class Block const& keepState(class ItemState const&) const;
	MCAPI void spawnResources(class BlockSource&, class BlockPos const&, float, int) const;
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> toDebugString(void) const;
	MCINLINE enum BlockRenderLayer getRenderLayer() const { return Call("?getRenderLayer@Block@@UEBA?AW4BlockRenderLayer@@XZ", enum BlockRenderLayer, Block const*)(this); }
#if 0
/* std || und args */
	/* bad retval */
#endif
};

class ItemStackBase {
public:
	MCAPI bool operator!=(class ItemStackBase const&) const;
	MCAPI operator bool(void) const;
	MCAPI void _read(class ReadOnlyBinaryStream&);
	MCAPI void _write(class BinaryStream&) const;
	MCAPI void addCustomUserData(class BlockActor&, class BlockSource&);
	MCAPI void clearChargedItem(void);
	MCAPI void deserializeComponents(class IDataInput&);
	MCAPI short getAuxValue(void) const;
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getCustomName(void) const;
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getDescriptionId(void) const;
	MCAPI class ItemDescriptor getDescriptor(void) const;
	MCAPI class ItemEnchants getEnchantsFromUserData(void) const;
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getHoverName(void) const;
	MCAPI short getId(void) const;
	MCAPI int getIdAux(void) const;
	MCAPI class Item const* getItem(void) const;
	MCAPI unsigned char getMaxStackSize(void) const;
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getName(void) const;
	MCAPI class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> getNetworkUserData(void) const;
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> getRawNameId(void) const;
	MCAPI bool hasComponent(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&) const;
	MCAPI bool hasCustomHoverName(void) const;
	MCAPI bool hasSameAuxValue(class ItemStackBase const&) const;
	MCAPI bool hasSameUserData(class ItemStackBase const&) const;
	MCAPI void hurtAndBreak(int, class Actor*);
	MCAPI bool isBlock(void) const;
	MCAPI bool isDamaged(void) const;
	MCAPI bool isEnchanted(void) const;
	MCAPI bool isExperimental(void) const;
	MCAPI bool isHorseArmorItem(void) const;
	MCAPI bool isNull(void) const;
	MCAPI bool isPotionItem(void) const;
	MCAPI bool isStackable(class ItemStackBase const&) const;
	MCAPI bool isStackedByData(void) const;
	MCAPI bool isWearableItem(void) const;
	MCAPI bool matches(class ItemStackBase const&) const;
	MCAPI bool matchesItem(class ItemStackBase const&) const;
	MCAPI bool sameItem(int, int) const;
	MCAPI bool sameItemAndAux(class ItemStackBase const&) const;
	MCAPI class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> save(void) const;
	MCAPI void saveEnchantsToUserData(class ItemEnchants const&);
	MCAPI void serializeComponents(class IDataOutput&) const;
	MCAPI void set(int);
	MCAPI void setChargedItem(class ItemInstance const&, bool);
	MCAPI void setCustomLore(class std::vector<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, class std::allocator<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>>> const&);
	MCAPI void setCustomName(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
	MCAPI void setNull(void);
	MCAPI void setRepairCost(int);
	MCAPI void setUserData(class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>>);
	MCAPI class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> toString(void) const;
	MCINLINE void _loadComponents(class CompoundTag const& a0) { Call("?_loadComponents@ItemStackBase@@AEAAXAEBVCompoundTag@@@Z", void, ItemStackBase const*, class CompoundTag const&)(this, a0); }
	MCINLINE void _loadItem(class CompoundTag const& a0) { Call("?_loadItem@ItemStackBase@@AEAAXAEBVCompoundTag@@@Z", void, ItemStackBase const*, class CompoundTag const&)(this, a0); }
	MCINLINE void _makeChargedItemFromUserData() { Call("?_makeChargedItemFromUserData@ItemStackBase@@AEAAXXZ", void, ItemStackBase const*)(this); }
	MCINLINE void _setChargedItem(class ItemInstance const& a0) { Call("?_setChargedItem@ItemStackBase@@AEAAXAEBVItemInstance@@@Z", void, ItemStackBase const*, class ItemInstance const&)(this, a0); }
	MCINLINE void _updateCompareHashes() { Call("?_updateCompareHashes@ItemStackBase@@AEAAXXZ", void, ItemStackBase const*)(this); }
#if 0
/* std || und args */
	/* bad retval */
#endif
};
class ItemStack:public ItemStackBase {
public:
	MCAPI ItemStack(class Item const&, int);
	MCAPI ItemStack(void);
	MCAPI class ItemStack& operator=(class ItemStack const&);
	MCAPI class ItemStack getStrippedNetworkItem(void) const;
	MCAPI bool sameItemAndAuxAndBlockData(class ItemStack const&) const;
	MCAPI void useAsFuel(void);
	MCAPI bool useOn(class Actor&, int, int, int, unsigned char, float, float, float);
	MCINLINE void reinit(class Item const& a0, int a1, int a2) { Call("?reinit@ItemStack@@MEAAXAEBVItem@@HH@Z", void, ItemStack const*, class Item const&, int, int)(this, a0, a1, a2); }
	MCINLINE void reinit(class BlockLegacy const& a0, int a1) { Call("?reinit@ItemStack@@UEAAXAEBVBlockLegacy@@H@Z", void, ItemStack const*, class BlockLegacy const&, int)(this, a0, a1); }
#if 0
/* std || und args */
	/* bad retval */
#endif
};