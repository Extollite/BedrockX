#pragma once
#include "Core.h"
#include"Actor.h"
MCCLS class Player : public Mob {
public:
	MCAPI bool canBeSeenOnMap(void) const;
	MCAPI bool canDestroy(class Block const&) const;
	MCAPI bool canUseAbility(enum AbilitiesIndex) const;
	MCAPI bool canUseOperatorBlocks(void) const;
	MCAPI void causeFoodExhaustion(float);
	MCAPI bool checkNeedAutoJump(float, float);
	MCAPI void clearRespawnPosition(void);
	MCAPI void eat(int, float);
	MCAPI class Agent* getAgent(void) const;
	MCAPI class ItemStack const& getCurrentActiveShield(void) const;
	MCAPI float getDestroyProgress(class Block const&) const;
	MCAPI float getDestroySpeed(class Block const&) const;
	MCAPI int getDirection(void) const;
	MCAPI class EnderChestContainer* getEnderChestContainer(void);
	MCAPI enum GameType getPlayerGameType(void) const;
	MCAPI class ItemStack const& getSelectedItem(void) const;
	MCAPI int getXpNeededForNextLevel(void) const;
	MCAPI void handleJumpEffects(void);
	MCAPI bool isHiddenFrom(class Mob&) const;
	MCAPI bool isInCreativeMode(void) const;
	MCAPI bool isInRaid(void) const;
	MCAPI bool isSurvival(void) const;
	MCAPI void recheckSpawnPosition(void);
	MCAPI void releaseUsingItem(void);
	MCAPI void resetPlayerLevel(void);
	MCAPI void setAgent(class Agent*);
	MCAPI void setBedRespawnPosition(class BlockPos const&);
	MCAPI void setContainerManager(class std::shared_ptr<class IContainerManager>);
	MCAPI void setPlayerUIItem(enum PlayerUISlot, class ItemStack const&);
	MCAPI void setRespawnPosition(class BlockPos const&, bool);
	MCAPI void startUsingItem(class ItemStack const&, int);
	MCAPI void stopGliding(void);
	MCAPI void stopUsingItem(void);
	MCAPI bool take(class Actor&, int, int);
	MCAPI void updateInventoryTransactions(void);
	MCAPI void updateSkin(class SerializedSkin const&, int);
	MCAPI void updateTeleportDestPos(void);
	MCAPI void updateTrackedBosses(void);
	MCINLINE void _addLevels(int a0) { Call("?_addLevels@Player@@AEAAXH@Z", void, Player const*, int)(this, a0); }
	MCINLINE bool _blockUsingShield(class ActorDamageSource const& a0, float a1) { return Call("?_blockUsingShield@Player@@AEAA_NAEBVActorDamageSource@@M@Z", bool, Player const*, class ActorDamageSource const&, float)(this, a0, a1); }
	MCINLINE void _crit(class Actor& a0) { Call("?_crit@Player@@UEAAXAEAVActor@@@Z", void, Player const*, class Actor&)(this, a0); }
	MCINLINE void _ensureSafeSpawnPosition(class Vec3& a0) { Call("?_ensureSafeSpawnPosition@Player@@AEAAXAEAVVec3@@@Z", void, Player const*, class Vec3&)(this, a0); }
	MCINLINE bool _findFallbackSpawnPosition(class Vec3& a0) { return Call("?_findFallbackSpawnPosition@Player@@AEAA_NAEAVVec3@@V?$vector@PEAVBlockSource@@V?$allocator@PEAVBlockSource@@@std@@@std@@I@Z", bool, Player const*, class Vec3&)(this, a0); }
	MCINLINE void _fireDimensionChanged() { Call("?_fireDimensionChanged@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void _fireWillChangeDimension() { Call("?_fireWillChangeDimension@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void _handleCarriedItemInteractText() { Call("?_handleCarriedItemInteractText@Player@@AEAAXXZ", void, Player const*)(this); }
	MCINLINE bool _hurt(class ActorDamageSource const& a0, int a1, bool a2, bool a3) { return Call("?_hurt@Player@@MEAA_NAEBVActorDamageSource@@H_N1@Z", bool, Player const*, class ActorDamageSource const&, int, bool, bool)(this, a0, a1, a2, a3); }
	MCINLINE void _onSizeUpdated() { Call("?_onSizeUpdated@Player@@EEAAXXZ", void, Player const*)(this); }
	MCINLINE void _registerElytraLoopSound() { Call("?_registerElytraLoopSound@Player@@AEAAXXZ", void, Player const*)(this); }
	MCINLINE void _sendShieldUpdatePacket(class ShieldItem const* a0, class ItemStack const& a1, class ItemStack const& a2, enum ContainerID a3, int a4) { Call("?_sendShieldUpdatePacket@Player@@AEAAXPEBVShieldItem@@AEBVItemStack@@1W4ContainerID@@H@Z", void, Player const*, class ShieldItem const*, class ItemStack const&, class ItemStack const&, enum ContainerID, int)(this, a0, a1, a2, a3, a4); }
	MCINLINE void actuallyHurt(int a0, class ActorDamageSource const* a1, bool a2) { Call("?actuallyHurt@Player@@UEAAXHPEBVActorDamageSource@@_N@Z", void, Player const*, int, class ActorDamageSource const*, bool)(this, a0, a1, a2); }
	MCINLINE bool add(class ItemStack& a0) { return Call("?add@Player@@UEAA_NAEAVItemStack@@@Z", bool, Player const*, class ItemStack&)(this, a0); }
	MCINLINE void addAdditionalSaveData(class CompoundTag& a0) { Call("?addAdditionalSaveData@Player@@MEAAXAEAVCompoundTag@@@Z", void, Player const*, class CompoundTag&)(this, a0); }
	MCINLINE void addExperience(int a0) { Call("?addExperience@Player@@UEAAXH@Z", void, Player const*, int)(this, a0); }
	MCINLINE void addLevels(int a0) { Call("?addLevels@Player@@UEAAXH@Z", void, Player const*, int)(this, a0); }
	MCINLINE void adjustDamageAmount(int& a0) const { Call("?adjustDamageAmount@Player@@UEBAXAEAH@Z", void, Player const*, int&)(this, a0); }
	MCINLINE void aiStep() { Call("?aiStep@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE bool attack(class Actor& a0) { return Call("?attack@Player@@UEAA_NAEAVActor@@@Z", bool, Player const*, class Actor&)(this, a0); }
	MCINLINE void awardKillScore(class Actor& a0, int a1) { Call("?awardKillScore@Player@@UEAAXAEAVActor@@H@Z", void, Player const*, class Actor&, int)(this, a0, a1); }
	MCINLINE bool canAddRider(class Actor& a0) const { return Call("?canAddRider@Player@@UEBA_NAEAVActor@@@Z", bool, Player const*, class Actor&)(this, a0); }
	MCINLINE bool canBePulledIntoVehicle() const { return Call("?canBePulledIntoVehicle@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool canExistWhenDisallowMob() const { return Call("?canExistWhenDisallowMob@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool canOpenContainerScreen() { return Call("?canOpenContainerScreen@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE bool canStartSleepInBed() { return Call("?canStartSleepInBed@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE void changeDimensionWithCredits() { Call("?changeDimensionWithCredits@Player@@UEAAXV?$AutomaticID@VDimension@@H@@@Z", void, Player const*)(this); }
	MCINLINE void checkMovementStats(class Vec3 const& a0) { Call("?checkMovementStats@Player@@UEAAXAEBVVec3@@@Z", void, Player const*, class Vec3 const&)(this, a0); }
	MCINLINE void completeUsingItem() { Call("?completeUsingItem@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE bool consumeTotem() { return Call("?consumeTotem@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE void deleteContainerManager() { Call("?deleteContainerManager@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void destroyRegion() { Call("?destroyRegion@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void die(class ActorDamageSource const& a0) { Call("?die@Player@@UEAAXAEBVActorDamageSource@@@Z", void, Player const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE void displayChatMessage() { Call("?displayChatMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z", void, Player const*)(this); }
	MCINLINE void displayClientMessage() { Call("?displayClientMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Player const*)(this); }
	MCINLINE void displayLocalizableMessage() { Call("?displayLocalizableMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@@Z", void, Player const*)(this); }
	MCINLINE void displayTextObjectMessage(class TextObjectRoot const& a0) { Call("?displayTextObjectMessage@Player@@UEAAXAEBVTextObjectRoot@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z", void, Player const*, class TextObjectRoot const&)(this, a0); }
	MCINLINE void displayWhisperMessage() { Call("?displayWhisperMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@000@Z", void, Player const*)(this); }
	MCINLINE bool drop(class ItemStack const& a0, bool a1) { return Call("?drop@Player@@UEAA_NAEBVItemStack@@_N@Z", bool, Player const*, class ItemStack const&, bool)(this, a0, a1); }
	MCINLINE void dropEquipment(class ActorDamageSource const& a0, int a1) { Call("?dropEquipment@Player@@UEAAXAEBVActorDamageSource@@H@Z", void, Player const*, class ActorDamageSource const&, int)(this, a0, a1); }
	MCINLINE void dropEquipment() { Call("?dropEquipment@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void feed(int a0) { Call("?feed@Player@@UEAAXH@Z", void, Player const*, int)(this, a0); }
	MCINLINE class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>> getAllEquipment() const { return Call("?getAllEquipment@Player@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ", class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>>, Player const*)(this); } MCINLINE class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>> getAllHand() const {
		return Call("?getAllHand@Player@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ", class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>>, Player const*)(this);
	} MCINLINE bool getAlwaysShowNameTag() const { return Call("?getAlwaysShowNameTag@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE class AnimationComponent& getAnimationComponent() { return Call("?getAnimationComponent@Player@@UEAAAEAVAnimationComponent@@XZ", class AnimationComponent&, Player const*)(this); }
	MCINLINE float getCameraOffset() const { return Call("?getCameraOffset@Player@@UEBAMXZ", float, Player const*)(this); }
	MCINLINE class ItemStack const& getCarriedItem() const { return Call("?getCarriedItem@Player@@UEBAAEBVItemStack@@XZ", class ItemStack const&, Player const*)(this); }
	MCINLINE enum CommandPermissionLevel getCommandPermissionLevel() const { return Call("?getCommandPermissionLevel@Player@@UEBA?AW4CommandPermissionLevel@@XZ", enum CommandPermissionLevel, Player const*)(this); }
	MCINLINE enum StructureFeatureType getCurrentStructureFeature() const { return Call("?getCurrentStructureFeature@Player@@UEBA?AW4StructureFeatureType@@XZ", enum StructureFeatureType, Player const*)(this); }
	MCINLINE enum ActorType getEntityTypeId() const { return Call("?getEntityTypeId@Player@@UEBA?AW4ActorType@@XZ", enum ActorType, Player const*)(this); }
	MCINLINE class ItemStack const& getEquippedTotem() const { return Call("?getEquippedTotem@Player@@UEBAAEBVItemStack@@XZ", class ItemStack const&, Player const*)(this); }
	MCINLINE class IMinecraftEventing* getEventing() const { return Call("?getEventing@Player@@UEBAPEAVIMinecraftEventing@@XZ", class IMinecraftEventing*, Player const*)(this); }
	MCINLINE int getItemCooldownLeft(enum CooldownType a0) const { return Call("?getItemCooldownLeft@Player@@UEBAHW4CooldownType@@@Z", int, Player const*, enum CooldownType)(this, a0); }
	MCINLINE int getItemUseDuration() { return Call("?getItemUseDuration@Player@@UEAAHXZ", int, Player const*)(this); }
	MCINLINE float getItemUseIntervalProgress() { return Call("?getItemUseIntervalProgress@Player@@UEAAMXZ", float, Player const*)(this); }
	MCINLINE float getItemUseStartupProgress() { return Call("?getItemUseStartupProgress@Player@@UEAAMXZ", float, Player const*)(this); }
	MCINLINE float getMapDecorationRotation() const { return Call("?getMapDecorationRotation@Player@@UEBAMXZ", float, Player const*)(this); }
	MCINLINE int getPortalCooldown() const { return Call("?getPortalCooldown@Player@@UEBAHXZ", int, Player const*)(this); }
	MCINLINE int getPortalWaitTime() const { return Call("?getPortalWaitTime@Player@@UEBAHXZ", int, Player const*)(this); }
	MCINLINE int getPreviousTickSleepTimer() const { return Call("?getPreviousTickSleepTimer@Player@@UEBAHXZ", int, Player const*)(this); }
	MCINLINE float getRidingHeight() { return Call("?getRidingHeight@Player@@UEAAMXZ", float, Player const*)(this); }
	MCINLINE int getSleepTimer() const { return Call("?getSleepTimer@Player@@UEBAHXZ", int, Player const*)(this); }
	MCINLINE float getSpeed() const { return Call("?getSpeed@Player@@UEBAMXZ", float, Player const*)(this); }
	MCINLINE class std::vector<class ChunkPos, class std::allocator<class ChunkPos>> const& getTickingOffsets() const { return Call("?getTickingOffsets@Player@@UEBAAEBV?$vector@VChunkPos@@V?$allocator@VChunkPos@@@std@@@std@@XZ", class std::vector<class ChunkPos, class std::allocator<class ChunkPos>> const&, Player const*)(this); } MCINLINE unsigned int getUserId() const {
		return Call("?getUserId@Player@@UEBAIXZ", unsigned int, Player const*)(this);
	}
	MCINLINE void handleEntityEvent(enum ActorEvent a0, int a1) { Call("?handleEntityEvent@Player@@UEAAXW4ActorEvent@@H@Z", void, Player const*, enum ActorEvent, int)(this, a0, a1); }
	MCINLINE bool hasResource(int a0) { return Call("?hasResource@Player@@UEAA_NH@Z", bool, Player const*, int)(this, a0); }
	MCINLINE void inventoryChanged(class Container& a0, int a1, class ItemStack const& a2, class ItemStack const& a3) { Call("?inventoryChanged@Player@@UEAAXAEAVContainer@@HAEBVItemStack@@1@Z", void, Player const*, class Container&, int, class ItemStack const&, class ItemStack const&)(this, a0, a1, a2, a3); }
	MCINLINE bool isAdventure() const { return Call("?isAdventure@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isAutoJumpEnabled() const { return Call("?isAutoJumpEnabled@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isBlocking() const { return Call("?isBlocking@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isCreative() const { return Call("?isCreative@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isCreativeModeAllowed() { return Call("?isCreativeModeAllowed@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isDamageBlocked(class ActorDamageSource const& a0) const { return Call("?isDamageBlocked@Player@@UEBA_NAEBVActorDamageSource@@@Z", bool, Player const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE bool isEntityRelevant(class Actor const& a0) { return Call("?isEntityRelevant@Player@@UEAA_NAEBVActor@@@Z", bool, Player const*, class Actor const&)(this, a0); }
	MCINLINE bool isHostingPlayer() const { return Call("?isHostingPlayer@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isImmobile() const { return Call("?isImmobile@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isInTrialMode() { return Call("?isInTrialMode@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isInvulnerableTo(class ActorDamageSource const& a0) const { return Call("?isInvulnerableTo@Player@@UEBA_NAEBVActorDamageSource@@@Z", bool, Player const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE bool isItemInCooldown(enum CooldownType a0) const { return Call("?isItemInCooldown@Player@@UEBA_NW4CooldownType@@@Z", bool, Player const*, enum CooldownType)(this, a0); }
	MCINLINE bool isJumping() const { return Call("?isJumping@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isLoading() const { return Call("?isLoading@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isLocalPlayer() const { return Call("?isLocalPlayer@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isPlayerInitialized() const { return Call("?isPlayerInitialized@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isPositionRelevant() { return Call("?isPositionRelevant@Player@@UEAA_NV?$AutomaticID@VDimension@@H@@AEBVBlockPos@@@Z", bool, Player const*)(this); }
	MCINLINE bool isShootable() { return Call("?isShootable@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isSleeping() const { return Call("?isSleeping@Player@@UEBA_NXZ", bool, Player const*)(this); }
	MCINLINE bool isWorldBuilder() { return Call("?isWorldBuilder@Player@@UEAA_NXZ", bool, Player const*)(this); }
	MCINLINE void jumpFromGround() { Call("?jumpFromGround@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void move(class Vec3 const& a0) { Call("?move@Player@@UEAAXAEBVVec3@@@Z", void, Player const*, class Vec3 const&)(this, a0); }
	MCINLINE void moveSpawnView(class Vec3 const& a0) { Call("?moveSpawnView@Player@@UEAAXAEBVVec3@@@Z", void, Player const*, class Vec3 const&)(this, a0); }
	MCINLINE void moveView() { Call("?moveView@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void normalTick() { Call("?normalTick@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void onBounceStarted(class BlockPos const& a0, class Block const& a1) { Call("?onBounceStarted@Player@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z", void, Player const*, class BlockPos const&, class Block const&)(this, a0, a1); }
	MCINLINE void onLinkedSlotsChanged() { Call("?onLinkedSlotsChanged@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void onMovePlayerPacketNormal(class Vec3 const& a0, class Vec2 const& a1, float a2) { Call("?onMovePlayerPacketNormal@Player@@MEAAXAEBVVec3@@AEBVVec2@@M@Z", void, Player const*, class Vec3 const&, class Vec2 const&, float)(this, a0, a1, a2); }
	MCINLINE void onSuspension() { Call("?onSuspension@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void onSynchedDataUpdate(int a0) { Call("?onSynchedDataUpdate@Player@@UEAAXH@Z", void, Player const*, int)(this, a0); }
	MCINLINE void openAnvil(class BlockPos const& a0) { Call("?openAnvil@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openBeacon(class BlockPos const& a0) { Call("?openBeacon@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openBlastFurnace(class BlockPos const& a0) { Call("?openBlastFurnace@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openBook(int a0, bool a1, int a2, class BlockActor* a3) { Call("?openBook@Player@@UEAAXH_NHPEAVBlockActor@@@Z", void, Player const*, int, bool, int, class BlockActor*)(this, a0, a1, a2, a3); }
	MCINLINE void openBrewingStand(class BlockPos const& a0) { Call("?openBrewingStand@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openCartographyTable(class BlockPos const& a0) { Call("?openCartographyTable@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openChalkboard(class ChalkboardBlockActor& a0, bool a1) { Call("?openChalkboard@Player@@UEAAXAEAVChalkboardBlockActor@@_N@Z", void, Player const*, class ChalkboardBlockActor&, bool)(this, a0, a1); }
	MCINLINE void openCommandBlock(class BlockPos const& a0) { Call("?openCommandBlock@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openCommandBlockMinecart(struct ActorUniqueID const& a0) { Call("?openCommandBlockMinecart@Player@@UEAAXAEBUActorUniqueID@@@Z", void, Player const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openCompoundCreator(class BlockPos const& a0) { Call("?openCompoundCreator@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openContainer(struct ActorUniqueID const& a0) { Call("?openContainer@Player@@UEAAXAEBUActorUniqueID@@@Z", void, Player const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openContainer(class BlockPos const& a0) { Call("?openContainer@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openDispenser(class BlockPos const& a0, bool a1) { Call("?openDispenser@Player@@UEAAXAEBVBlockPos@@_N@Z", void, Player const*, class BlockPos const&, bool)(this, a0, a1); }
	MCINLINE void openElementConstructor(class BlockPos const& a0) { Call("?openElementConstructor@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openEnchanter(class BlockPos const& a0) { Call("?openEnchanter@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openFurnace(class BlockPos const& a0) { Call("?openFurnace@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openGrindstone(class BlockPos const& a0) { Call("?openGrindstone@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openHopper(struct ActorUniqueID const& a0) { Call("?openHopper@Player@@UEAAXAEBUActorUniqueID@@@Z", void, Player const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openHopper(class BlockPos const& a0) { Call("?openHopper@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openHorseInventory(struct ActorUniqueID const& a0) { Call("?openHorseInventory@Player@@UEAAXAEBUActorUniqueID@@@Z", void, Player const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openInventory() { Call("?openInventory@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void openLabTable(class BlockPos const& a0) { Call("?openLabTable@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openLoom(class BlockPos const& a0) { Call("?openLoom@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openMaterialReducer(class BlockPos const& a0) { Call("?openMaterialReducer@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openNpcInteractScreen(class Actor& a0) { Call("?openNpcInteractScreen@Player@@UEAAXAEAVActor@@@Z", void, Player const*, class Actor&)(this, a0); }
	MCINLINE void openPortfolio() { Call("?openPortfolio@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void openSign(class BlockPos const& a0) { Call("?openSign@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openSmoker(class BlockPos const& a0) { Call("?openSmoker@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openStonecutter(class BlockPos const& a0) { Call("?openStonecutter@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openStructureEditor(class BlockPos const& a0) { Call("?openStructureEditor@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void openTrading(struct ActorUniqueID const& a0, bool a1) { Call("?openTrading@Player@@UEAAXAEBUActorUniqueID@@_N@Z", void, Player const*, struct ActorUniqueID const&, bool)(this, a0, a1); }
	MCINLINE void playEmote() { Call("?playEmote@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z", void, Player const*)(this); }
	MCINLINE void prepareRegion(class ChunkSource& a0) { Call("?prepareRegion@Player@@UEAAXAEAVChunkSource@@@Z", void, Player const*, class ChunkSource&)(this, a0); }
	MCINLINE void readAdditionalSaveData(class CompoundTag const& a0, class DataLoadHelper& a1) { Call("?readAdditionalSaveData@Player@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z", void, Player const*, class CompoundTag const&, class DataLoadHelper&)(this, a0, a1); }
	MCINLINE void remove() { Call("?remove@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void reportMovementTelemetry(enum MovementEventType a0) { Call("?reportMovementTelemetry@Player@@UEAAXW4MovementEventType@@@Z", void, Player const*, enum MovementEventType)(this, a0); }
	MCINLINE void resetPos(bool a0) { Call("?resetPos@Player@@UEAAX_N@Z", void, Player const*, bool)(this, a0); }
	MCINLINE void resetRot() { Call("?resetRot@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void respawn() { Call("?respawn@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void rideTick() { Call("?rideTick@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void sendEventPacket(class EventPacket& a0) const { Call("?sendEventPacket@Player@@UEBAXAEAVEventPacket@@@Z", void, Player const*, class EventPacket&)(this, a0); }
	MCINLINE void sendInventory(bool a0) { Call("?sendInventory@Player@@UEAAX_N@Z", void, Player const*, bool)(this, a0); }
	MCINLINE void sendMotionPacketIfNeeded() { Call("?sendMotionPacketIfNeeded@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void sendNetworkPacket(class Packet& a0) const { Call("?sendNetworkPacket@Player@@UEBAXAEAVPacket@@@Z", void, Player const*, class Packet&)(this, a0); }
	MCINLINE void setArmor(enum ArmorSlot a0, class ItemStack const& a1) { Call("?setArmor@Player@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z", void, Player const*, enum ArmorSlot, class ItemStack const&)(this, a0, a1); }
	MCINLINE void setCarriedItem(class ItemStack const& a0) { Call("?setCarriedItem@Player@@UEAAXAEBVItemStack@@@Z", void, Player const*, class ItemStack const&)(this, a0); }
	MCINLINE void setFieldOfViewModifier(float a0) { Call("?setFieldOfViewModifier@Player@@UEAAXM@Z", void, Player const*, float)(this, a0); }
	MCINLINE void setName() { Call("?setName@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Player const*)(this); }
	MCINLINE void setOffhandSlot(class ItemStack const& a0) { Call("?setOffhandSlot@Player@@UEAAXAEBVItemStack@@@Z", void, Player const*, class ItemStack const&)(this, a0); }
	MCINLINE void setPermissions(enum CommandPermissionLevel a0) { Call("?setPermissions@Player@@UEAAXW4CommandPermissionLevel@@@Z", void, Player const*, enum CommandPermissionLevel)(this, a0); }
	MCINLINE void setPlayerGameType(enum GameType a0) { Call("?setPlayerGameType@Player@@UEAAXW4GameType@@@Z", void, Player const*, enum GameType)(this, a0); }
	MCINLINE void setSleeping(bool a0) { Call("?setSleeping@Player@@UEAAX_N@Z", void, Player const*, bool)(this, a0); }
	MCINLINE void setSpeed(float a0) { Call("?setSpeed@Player@@UEAAXM@Z", void, Player const*, float)(this, a0); }
	MCINLINE void startCooldown(class Item const* a0) { Call("?startCooldown@Player@@UEAAXPEBVItem@@@Z", void, Player const*, class Item const*)(this, a0); }
	MCINLINE void startCrafting(class BlockPos const& a0, bool a1) { Call("?startCrafting@Player@@UEAAXAEBVBlockPos@@_N@Z", void, Player const*, class BlockPos const&, bool)(this, a0, a1); }
	MCINLINE void startDestroying() { Call("?startDestroying@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE enum BedSleepingResult startSleepInBed(class BlockPos const& a0) { return Call("?startSleepInBed@Player@@UEAA?AW4BedSleepingResult@@AEBVBlockPos@@@Z", enum BedSleepingResult, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void startSpinAttack() { Call("?startSpinAttack@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void startStonecutting(class BlockPos const& a0) { Call("?startStonecutting@Player@@UEAAXAEBVBlockPos@@@Z", void, Player const*, class BlockPos const&)(this, a0); }
	MCINLINE void startSwimming() { Call("?startSwimming@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void stopDestroying() { Call("?stopDestroying@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void stopLoading() { Call("?stopLoading@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void stopSleepInBed(bool a0, bool a1) { Call("?stopSleepInBed@Player@@UEAAX_N0@Z", void, Player const*, bool, bool)(this, a0, a1); }
	MCINLINE void stopSpinAttack() { Call("?stopSpinAttack@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void stopSwimming() { Call("?stopSwimming@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void suspendRegion() { Call("?suspendRegion@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void teleportTo(class Vec3 const& a0, bool a1, int a2, int a3) { Call("?teleportTo@Player@@UEAAXAEBVVec3@@_NHH@Z", void, Player const*, class Vec3 const&, bool, int, int)(this, a0, a1, a2, a3); }
	MCINLINE int tickWorld(struct Tick const& a0) { return Call("?tickWorld@Player@@UEAAHAEBUTick@@@Z", int, Player const*, struct Tick const&)(this, a0); }
	MCINLINE void travel(float a0, float a1, float a2) { Call("?travel@Player@@UEAAXMMM@Z", void, Player const*, float, float, float)(this, a0, a1, a2); }
	MCINLINE void updateAi() { Call("?updateAi@Player@@MEAAXXZ", void, Player const*)(this); }
	MCINLINE void updateGliding() { Call("?updateGliding@Player@@UEAAXXZ", void, Player const*)(this); }
	MCINLINE void useItem(class ItemStack& a0, enum ItemUseMethod a1, bool a2) { Call("?useItem@Player@@UEAAXAEAVItemStack@@W4ItemUseMethod@@_N@Z", void, Player const*, class ItemStack&, enum ItemUseMethod, bool)(this, a0, a1, a2); }
	MCINLINE bool useNewAi() const { return Call("?useNewAi@Player@@UEBA_NXZ", bool, Player const*)(this); }
#if 0
/* std || und args */
	MCINLINE void registerTrackedBoss(struct ActorUniqueID a0){ Call("?registerTrackedBoss@Player@@UEAAXUActorUniqueID@@@Z",void ,Player const*,struct ActorUniqueID)(this,a0);}
	MCINLINE void unRegisterTrackedBoss(struct ActorUniqueID a0){ Call("?unRegisterTrackedBoss@Player@@UEAAXUActorUniqueID@@@Z",void ,Player const*,struct ActorUniqueID)(this,a0);}
	/* bad retval */
	MCINLINE class std::unique_ptr<class Packet,struct std::default_delete<class Packet> > getAddPacket(){ return Call("?getAddPacket@Player@@UEAA?AV?$unique_ptr@VPacket@@U?$default_delete@VPacket@@@std@@@std@@XZ",class std::unique_ptr<class Packet,struct std::default_delete<class Packet> > ,Player const*)(this);}
	MCINLINE class Vec3 getAttachPos(enum ActorLocation a0,float a1)const { return Call("?getAttachPos@Player@@UEBA?AVVec3@@W4ActorLocation@@M@Z",class Vec3 ,Player const*,enum ActorLocation,float)(this,a0,a1);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getFormattedNameTag()const { return Call("?getFormattedNameTag@Player@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,Player const*)(this);}
	MCINLINE class std::unique_ptr<class BodyControl,struct std::default_delete<class BodyControl> > initBodyControl(){ return Call("?initBodyControl@Player@@EEAA?AV?$unique_ptr@VBodyControl@@U?$default_delete@VBodyControl@@@std@@@std@@XZ",class std::unique_ptr<class BodyControl,struct std::default_delete<class BodyControl> > ,Player const*)(this);}
#endif
};
MCCLS class ServerPlayer : public Player {
public:
	MCAPI void checkCheating(class Vec3 const&);
	MCAPI unsigned int findClientChunkRadius(unsigned int) const;
	MCAPI bool recoverR5LostInventoryAndXP(void);
	MCAPI void selectItem(class ItemStack const&, int const&);
	MCAPI void sendMobEffectPackets(void);
	MCAPI void setClientChunkRadius(unsigned int);
	MCINLINE void _removeNearbyEntities() { Call("?_removeNearbyEntities@ServerPlayer@@AEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void _scanForNearbyActors() { Call("?_scanForNearbyActors@ServerPlayer@@AEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void _setContainerManager() { Call("?_setContainerManager@ServerPlayer@@AEAAXV?$shared_ptr@VIContainerManager@@@std@@@Z", void, ServerPlayer const*)(this); }
	MCINLINE void _updateNearbyActors() { Call("?_updateNearbyActors@ServerPlayer@@AEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void aiStep() { Call("?aiStep@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE bool canChangeDimensions() const { return Call("?canChangeDimensions@ServerPlayer@@UEBA_NXZ", bool, ServerPlayer const*)(this); }
	MCINLINE void changeDimension() { Call("?changeDimension@ServerPlayer@@UEAAXV?$AutomaticID@VDimension@@H@@_N@Z", void, ServerPlayer const*)(this); }
	MCINLINE void changeDimensionWithCredits() { Call("?changeDimensionWithCredits@ServerPlayer@@UEAAXV?$AutomaticID@VDimension@@H@@@Z", void, ServerPlayer const*)(this); }
	MCINLINE void checkFallDamage(float a0, bool a1) { Call("?checkFallDamage@ServerPlayer@@UEAAXM_N@Z", void, ServerPlayer const*, float, bool)(this, a0, a1); }
	MCINLINE void checkMovementStats(class Vec3 const& a0) { Call("?checkMovementStats@ServerPlayer@@UEAAXAEBVVec3@@@Z", void, ServerPlayer const*, class Vec3 const&)(this, a0); }
	MCINLINE void deleteContainerManager() { Call("?deleteContainerManager@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void destroyRegion() { Call("?destroyRegion@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void die(class ActorDamageSource const& a0) { Call("?die@ServerPlayer@@UEAAXAEBVActorDamageSource@@@Z", void, ServerPlayer const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE void displayLocalizableMessage() { Call("?displayLocalizableMessage@ServerPlayer@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@@Z", void, ServerPlayer const*)(this); }
	MCINLINE void displayTextObjectMessage(class TextObjectRoot const& a0) { Call("?displayTextObjectMessage@ServerPlayer@@UEAAXAEBVTextObjectRoot@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z", void, ServerPlayer const*, class TextObjectRoot const&)(this, a0); }
	MCINLINE void displayWhisperMessage() { Call("?displayWhisperMessage@ServerPlayer@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@000@Z", void, ServerPlayer const*)(this); }
	MCINLINE void frameUpdate(class FrameUpdateContextBase& a0) { Call("?frameUpdate@ServerPlayer@@UEAAXAEAVFrameUpdateContextBase@@@Z", void, ServerPlayer const*, class FrameUpdateContextBase&)(this, a0); }
	MCINLINE enum InputMode getInputMode() const { return Call("?getInputMode@ServerPlayer@@UEBA?AW4InputMode@@XZ", enum InputMode, ServerPlayer const*)(this); }
	MCINLINE class MoveInputHandler* getMoveInputHandler() { return Call("?getMoveInputHandler@ServerPlayer@@UEAAPEAVMoveInputHandler@@XZ", class MoveInputHandler*, ServerPlayer const*)(this); }
	MCINLINE enum ClientPlayMode getPlayMode() const { return Call("?getPlayMode@ServerPlayer@@UEBA?AW4ClientPlayMode@@XZ", enum ClientPlayMode, ServerPlayer const*)(this); }
	MCINLINE class PlayerEventCoordinator& getPlayerEventCoordinator() { return Call("?getPlayerEventCoordinator@ServerPlayer@@UEAAAEAVPlayerEventCoordinator@@XZ", class PlayerEventCoordinator&, ServerPlayer const*)(this); }
	MCINLINE void handleEntityEvent(enum ActorEvent a0, int a1) { Call("?handleEntityEvent@ServerPlayer@@UEAAXW4ActorEvent@@H@Z", void, ServerPlayer const*, enum ActorEvent, int)(this, a0, a1); }
	MCINLINE void handleFallDistanceOnServer(float a0, bool a1) { Call("?handleFallDistanceOnServer@ServerPlayer@@UEAAXM_N@Z", void, ServerPlayer const*, float, bool)(this, a0, a1); }
	MCINLINE void hurtArmor(int a0) { Call("?hurtArmor@ServerPlayer@@UEAAXH@Z", void, ServerPlayer const*, int)(this, a0); }
	MCINLINE bool isEntityRelevant(class Actor const& a0) { return Call("?isEntityRelevant@ServerPlayer@@UEAA_NAEBVActor@@@Z", bool, ServerPlayer const*, class Actor const&)(this, a0); }
	MCINLINE bool isHostingPlayer() const { return Call("?isHostingPlayer@ServerPlayer@@UEBA_NXZ", bool, ServerPlayer const*)(this); }
	MCINLINE bool isLoading() const { return Call("?isLoading@ServerPlayer@@UEBA_NXZ", bool, ServerPlayer const*)(this); }
	MCINLINE bool isPlayerInitialized() const { return Call("?isPlayerInitialized@ServerPlayer@@UEBA_NXZ", bool, ServerPlayer const*)(this); }
	MCINLINE bool isPositionRelevant() { return Call("?isPositionRelevant@ServerPlayer@@UEAA_NV?$AutomaticID@VDimension@@H@@AEBVBlockPos@@@Z", bool, ServerPlayer const*)(this); }
	MCINLINE bool isTeacher() const { return Call("?isTeacher@ServerPlayer@@UEBA_NXZ", bool, ServerPlayer const*)(this); }
	MCINLINE bool isValidTarget(class Actor* a0) const { return Call("?isValidTarget@ServerPlayer@@UEBA_NPEAVActor@@@Z", bool, ServerPlayer const*, class Actor*)(this, a0); }
	MCINLINE void knockback(class Actor* a0, int a1, float a2, float a3, float a4, float a5, float a6) { Call("?knockback@ServerPlayer@@UEAAXPEAVActor@@HMMMMM@Z", void, ServerPlayer const*, class Actor*, int, float, float, float, float, float)(this, a0, a1, a2, a3, a4, a5, a6); }
	MCINLINE bool load(class CompoundTag const& a0, class DataLoadHelper& a1) { return Call("?load@ServerPlayer@@UEAA_NAEBVCompoundTag@@AEAVDataLoadHelper@@@Z", bool, ServerPlayer const*, class CompoundTag const&, class DataLoadHelper&)(this, a0, a1); }
	MCINLINE void normalTick() { Call("?normalTick@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void onEffectAdded(class MobEffectInstance& a0) { Call("?onEffectAdded@ServerPlayer@@MEAAXAEAVMobEffectInstance@@@Z", void, ServerPlayer const*, class MobEffectInstance&)(this, a0); }
	MCINLINE void onEffectRemoved(class MobEffectInstance& a0) { Call("?onEffectRemoved@ServerPlayer@@MEAAXAEAVMobEffectInstance@@@Z", void, ServerPlayer const*, class MobEffectInstance&)(this, a0); }
	MCINLINE void onEffectUpdated(class MobEffectInstance const& a0) { Call("?onEffectUpdated@ServerPlayer@@MEAAXAEBVMobEffectInstance@@@Z", void, ServerPlayer const*, class MobEffectInstance const&)(this, a0); }
	MCINLINE void onLinkedSlotsChanged() { Call("?onLinkedSlotsChanged@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void onSuspension() { Call("?onSuspension@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void openAnvil(class BlockPos const& a0) { Call("?openAnvil@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openBeacon(class BlockPos const& a0) { Call("?openBeacon@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openBlastFurnace(class BlockPos const& a0) { Call("?openBlastFurnace@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openBrewingStand(class BlockPos const& a0) { Call("?openBrewingStand@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openCommandBlock(class BlockPos const& a0) { Call("?openCommandBlock@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openCommandBlockMinecart(struct ActorUniqueID const& a0) { Call("?openCommandBlockMinecart@ServerPlayer@@UEAAXAEBUActorUniqueID@@@Z", void, ServerPlayer const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openCompoundCreator(class BlockPos const& a0) { Call("?openCompoundCreator@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openContainer(struct ActorUniqueID const& a0) { Call("?openContainer@ServerPlayer@@UEAAXAEBUActorUniqueID@@@Z", void, ServerPlayer const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openContainer(class BlockPos const& a0) { Call("?openContainer@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openDispenser(class BlockPos const& a0, bool a1) { Call("?openDispenser@ServerPlayer@@UEAAXAEBVBlockPos@@_N@Z", void, ServerPlayer const*, class BlockPos const&, bool)(this, a0, a1); }
	MCINLINE void openElementConstructor(class BlockPos const& a0) { Call("?openElementConstructor@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openEnchanter(class BlockPos const& a0) { Call("?openEnchanter@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openFurnace(class BlockPos const& a0) { Call("?openFurnace@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openGrindstone(class BlockPos const& a0) { Call("?openGrindstone@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openHopper(struct ActorUniqueID const& a0) { Call("?openHopper@ServerPlayer@@UEAAXAEBUActorUniqueID@@@Z", void, ServerPlayer const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openHopper(class BlockPos const& a0) { Call("?openHopper@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openHorseInventory(struct ActorUniqueID const& a0) { Call("?openHorseInventory@ServerPlayer@@UEAAXAEBUActorUniqueID@@@Z", void, ServerPlayer const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void openInventory() { Call("?openInventory@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void openLabTable(class BlockPos const& a0) { Call("?openLabTable@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openMaterialReducer(class BlockPos const& a0) { Call("?openMaterialReducer@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openNpcInteractScreen(class Actor& a0) { Call("?openNpcInteractScreen@ServerPlayer@@UEAAXAEAVActor@@@Z", void, ServerPlayer const*, class Actor&)(this, a0); }
	MCINLINE void openPortfolio() { Call("?openPortfolio@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE void openSmoker(class BlockPos const& a0) { Call("?openSmoker@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openStructureEditor(class BlockPos const& a0) { Call("?openStructureEditor@ServerPlayer@@UEAAXAEBVBlockPos@@@Z", void, ServerPlayer const*, class BlockPos const&)(this, a0); }
	MCINLINE void openTrading(struct ActorUniqueID const& a0, bool a1) { Call("?openTrading@ServerPlayer@@UEAAXAEBUActorUniqueID@@_N@Z", void, ServerPlayer const*, struct ActorUniqueID const&, bool)(this, a0, a1); }
	MCINLINE void prepareRegion(class ChunkSource& a0) { Call("?prepareRegion@ServerPlayer@@UEAAXAEAVChunkSource@@@Z", void, ServerPlayer const*, class ChunkSource&)(this, a0); }
	MCINLINE void refreshContainer(class IContainerManager& a0) { Call("?refreshContainer@ServerPlayer@@UEAAXAEAVIContainerManager@@@Z", void, ServerPlayer const*, class IContainerManager&)(this, a0); }
	MCINLINE void reportMovementTelemetry(enum MovementEventType a0) { Call("?reportMovementTelemetry@ServerPlayer@@UEAAXW4MovementEventType@@@Z", void, ServerPlayer const*, enum MovementEventType)(this, a0); }
	MCINLINE void sendComplexInventoryTransaction() const { Call("?sendComplexInventoryTransaction@ServerPlayer@@UEBAXV?$unique_ptr@VComplexInventoryTransaction@@U?$default_delete@VComplexInventoryTransaction@@@std@@@std@@@Z", void, ServerPlayer const*)(this); }
	MCINLINE void sendInventory(bool a0) { Call("?sendInventory@ServerPlayer@@UEAAX_N@Z", void, ServerPlayer const*, bool)(this, a0); }
	MCINLINE void sendInventoryTransaction(class InventoryTransaction const& a0) const { Call("?sendInventoryTransaction@ServerPlayer@@UEBAXAEBVInventoryTransaction@@@Z", void, ServerPlayer const*, class InventoryTransaction const&)(this, a0); }
	MCINLINE void sendNetworkPacket(class Packet& a0) const { Call("?sendNetworkPacket@ServerPlayer@@UEBAXAEAVPacket@@@Z", void, ServerPlayer const*, class Packet&)(this, a0); }
	MCINLINE void setArmor(enum ArmorSlot a0, class ItemStack const& a1) { Call("?setArmor@ServerPlayer@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z", void, ServerPlayer const*, enum ArmorSlot, class ItemStack const&)(this, a0, a1); }
	MCINLINE void setContainerData(class IContainerManager& a0, int a1, int a2) { Call("?setContainerData@ServerPlayer@@UEAAXAEAVIContainerManager@@HH@Z", void, ServerPlayer const*, class IContainerManager&, int, int)(this, a0, a1, a2); }
	MCINLINE void setPermissions(enum CommandPermissionLevel a0) { Call("?setPermissions@ServerPlayer@@UEAAXW4CommandPermissionLevel@@@Z", void, ServerPlayer const*, enum CommandPermissionLevel)(this, a0); }
	MCINLINE void setPlayerGameType(enum GameType a0) { Call("?setPlayerGameType@ServerPlayer@@UEAAXW4GameType@@@Z", void, ServerPlayer const*, enum GameType)(this, a0); }
	MCINLINE void slotChanged(class IContainerManager& a0, int a1, class ItemStack const& a2, class ItemStack const& a3, bool a4) { Call("?slotChanged@ServerPlayer@@UEAAXAEAVIContainerManager@@HAEBVItemStack@@1_N@Z", void, ServerPlayer const*, class IContainerManager&, int, class ItemStack const&, class ItemStack const&, bool)(this, a0, a1, a2, a3, a4); }
	MCINLINE void stopSleepInBed(bool a0, bool a1) { Call("?stopSleepInBed@ServerPlayer@@UEAAX_N0@Z", void, ServerPlayer const*, bool, bool)(this, a0, a1); }
	MCINLINE void suspendRegion() { Call("?suspendRegion@ServerPlayer@@UEAAXXZ", void, ServerPlayer const*)(this); }
	MCINLINE int tickWorld(struct Tick const& a0) { return Call("?tickWorld@ServerPlayer@@UEAAHAEBUTick@@@Z", int, ServerPlayer const*, struct Tick const&)(this, a0); }
#if 0
/* std || und args */
	/* bad retval */
	MCINLINE struct ActorUniqueID getControllingPlayer()const { return Call("?getControllingPlayer@ServerPlayer@@UEBA?AUActorUniqueID@@XZ",struct ActorUniqueID ,ServerPlayer const*)(this);}
#endif
};
