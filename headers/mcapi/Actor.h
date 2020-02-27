#pragma once
#include "Core.h"
class Actor {
public:
	MCAPI Actor(class Level&);
	MCAPI Actor(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&);
	MCAPI class Vec3 _randomHeartPos(void);
	MCAPI void _sendDirtyActorData(void);
	MCAPI bool _tryPlaceAt(class Vec3 const&);
	MCAPI void addEffect(class MobEffectInstance const&);
	MCAPI bool addTag(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
	MCAPI int calculateAttackDamage(class Actor&);
	MCAPI bool canBeginOrContinueClimbingLadder(bool) const;
	MCAPI bool canCurrentlySwim(void) const;
	MCAPI void dropLeash(bool, bool);
	MCAPI void dropTowards(class ItemStack const&, class Vec3);
	MCAPI class std::vector<struct DistanceSortedActor, class std::allocator<struct DistanceSortedActor>> fetchNearbyActorsSorted(class Vec3 const&, enum ActorType);
	MCAPI void forEachLeashedActor(class std::function<void>);
	MCAPI enum PaletteColor getColor2(void) const;
	MCAPI enum PaletteColor getColor(void) const;
	MCAPI int getControllingSeat(void);
	MCAPI class MobEffectInstance const* getEffect(class MobEffect const&) const;
	MCAPI class std::vector<struct ActorLink, class std::allocator<struct ActorLink>> getLinks(void) const;
	MCAPI int getMarkVariant(void) const;
	MCAPI class Mob* getOwner(void) const;
	MCAPI struct ActorUniqueID const getOwnerId(void) const;
	MCAPI class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> getPersistingTradeOffers(void);
	MCAPI class Player* getPlayerOwner(void) const;
	MCAPI class Actor* getRideRoot(void) const;
	MCAPI int getRiderIndex(class Actor&) const;
	MCAPI int getSkinID(void) const;
	MCAPI bool getStatusFlag(enum ActorFlags) const;
	MCAPI int getStrength(void) const;
	MCAPI int getStructuralIntegrity(void) const;
	MCAPI class Actor* getTarget(void) const;
	MCAPI class ITickingArea* getTickingArea(void);
	MCAPI class MerchantRecipeList* getTradeOffers(void);
	MCAPI class Player* getTradingPlayer(void) const;
	MCAPI struct ActorUniqueID const& getUniqueID(void) const;
	MCAPI int getVariant(void) const;
	MCAPI class Vec3 getViewVector(float) const;
	MCAPI bool hasEffect(class MobEffect const&) const;
	MCAPI bool hasPlayerRider(void) const;
	MCAPI bool hasRestriction(void) const;
	MCAPI bool hasSubBBInLava(void) const;
	MCAPI bool hasTag(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&) const;
	MCAPI bool hasTickingArea(void) const;
	MCAPI bool hurt(class ActorDamageSource const&, int, bool, bool);
	MCAPI void initEntity(class EntityRegistryOwned&);
	MCAPI bool isControlledByLocalInstance(void) const;
	MCAPI bool isFireImmune(void) const;
	MCAPI bool isInsideBorderBlock(float) const;
	MCAPI bool isRider(class Actor const&) const;
	MCAPI bool isRiding(void) const;
	MCAPI bool isUnderWaterfall(void) const;
	MCAPI bool isWithinRestriction(class BlockPos const&) const;
	MCAPI void loadEntityFlags(class CompoundTag const&, class DataLoadHelper&);
	MCAPI void moveBBs(class Vec3 const&);
	MCAPI bool moveChunks(void);
	MCAPI void moveTo(class Vec3 const&, class Vec2 const&);
	MCAPI bool onLadder(bool) const;
	MCAPI void pickUpItem(class ItemActor&, int);
	MCAPI void playSound(enum LevelSoundEvent, class Vec3 const&, int);
	MCAPI void positionAllRiders(void);
	MCAPI bool pullInEntity(class Actor&);
	MCAPI void pushBackActionEventToActionQueue(class ActionEvent);
	MCAPI void reload(void);
	MCAPI void removeAllEffects(void);
	MCAPI void removeAllRiders(bool, bool);
	MCAPI void removeEffect(int);
	MCAPI void removeEffectParticles(void);
	MCAPI void saveEntityFlags(class CompoundTag&);
	MCAPI class std::unique_ptr<class ListTag, struct std::default_delete<class ListTag>> saveLinks(void) const;
	MCAPI void savePersistingTrade(class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>>, int);
	MCAPI void sendActorDefinitionEventTriggered(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
	MCAPI void sendMotionToServer(void);
	MCAPI void setBaseDefinition(struct ActorDefinitionIdentifier const&, bool, bool);
	MCAPI void setCanClimb(bool);
	MCAPI void setCanFly(bool);
	MCAPI void setColor2(enum PaletteColor);
	MCAPI void setColor(enum PaletteColor);
	MCAPI void setHurtDir(int);
	MCAPI void setHurtTime(int);
	MCAPI void setInLove(class Actor*);
	MCAPI void setInvisible(bool);
	MCAPI void setJumpDuration(int);
	MCAPI void setLeashHolder(struct ActorUniqueID);
	MCAPI void setLimitedLife(int);
	MCAPI void setMarkVariant(int);
	MCAPI void setPersistent(void);
	MCAPI void setPreviousPosRot(class Vec3 const&, class Vec2 const&);
	MCAPI void setSeatDescription(class Vec3 const&, struct SeatDescription const&);
	MCAPI void setSkinID(int);
	MCAPI bool setStatusFlag(enum ActorFlags, bool);
	MCAPI void setStrength(int);
	MCAPI void setStrengthMax(int);
	MCAPI void setStructuralIntegrity(int);
	MCAPI void setTradingPlayer(class Player*);
	MCAPI void setVariant(int);
	MCAPI bool shouldOrphan(class BlockSource&);
	MCAPI void spawnBalloonPopParticles(void);
	MCAPI void spawnDeathParticles(void);
	MCAPI void spawnDustParticles(int);
	MCAPI void spawnEatParticles(class ItemStack const&, int);
	MCAPI void spawnTamingParticles(bool);
	MCAPI void teleportRidersTo(class Vec3 const&, int, int);
	MCAPI void testForCollidableMobs(class BlockSource&, class AABB const&, class std::vector<class AABB, class std::allocator<class AABB>>&);
	MCAPI bool tick(class BlockSource&);
	MCAPI void transferTickingArea(class Dimension&);
	MCAPI void updateBBFromDescription(void);
	MCAPI void updateDescription(void);
	MCAPI void updateInBubbleColumnState(void);
	MCAPI void updateInvisibilityStatus(void);
	MCAPI void updateTickingData(void);
	MCINLINE bool _countFood(int a0) { return Call("?_countFood@Actor@@AEAA_NH@Z", bool, Actor const*, int)(this, a0); }
	MCINLINE void _doAutoAttackOnTouch(class Actor& a0) { Call("?_doAutoAttackOnTouch@Actor@@EEAAXAEAV1@@Z", void, Actor const*, class Actor&)(this, a0); }
	MCINLINE bool _hurt(class ActorDamageSource const& a0, int a1, bool a2, bool a3) { return Call("?_hurt@Actor@@MEAA_NAEBVActorDamageSource@@H_N1@Z", bool, Actor const*, class ActorDamageSource const&, int, bool, bool)(this, a0, a1, a2, a3); }
	MCINLINE void _initializeLeashRopeSystem() { Call("?_initializeLeashRopeSystem@Actor@@AEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool _makeFlySound() const { return Call("?_makeFlySound@Actor@@MEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE void _manageRiders(class BlockSource& a0) { Call("?_manageRiders@Actor@@AEAAXAEAVBlockSource@@@Z", void, Actor const*, class BlockSource&)(this, a0); }
	MCINLINE void _onSizeUpdated() { Call("?_onSizeUpdated@Actor@@EEAAXXZ", void, Actor const*)(this); }
	MCINLINE void _playFlySound(class BlockPos const& a0, class Block const& a1) { Call("?_playFlySound@Actor@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z", void, Actor const*, class BlockPos const&, class Block const&)(this, a0, a1); }
	MCINLINE void _playStepSound(class BlockPos const& a0, class Block const& a1) { Call("?_playStepSound@Actor@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z", void, Actor const*, class BlockPos const&, class Block const&)(this, a0, a1); }
	MCINLINE void _removeRider(struct ActorUniqueID const& a0, bool a1, bool a2) { Call("?_removeRider@Actor@@MEAAXAEBUActorUniqueID@@_N1@Z", void, Actor const*, struct ActorUniqueID const&, bool, bool)(this, a0, a1, a2); }
	MCINLINE void _sendLinkPacket(struct ActorLink const& a0) const { Call("?_sendLinkPacket@Actor@@AEBAXAEBUActorLink@@@Z", void, Actor const*, struct ActorLink const&)(this, a0); }
	MCINLINE void _serializeComponents(class CompoundTag& a0) { Call("?_serializeComponents@Actor@@AEAAXAEAVCompoundTag@@@Z", void, Actor const*, class CompoundTag&)(this, a0); }
	MCINLINE void _spawnPukeParticles() { Call("?_spawnPukeParticles@Actor@@AEAAXXZ", void, Actor const*)(this); }
	MCINLINE void _spawnTreasureHuntingParticles() { Call("?_spawnTreasureHuntingParticles@Actor@@AEAAXXZ", void, Actor const*)(this); }
	MCINLINE void _tryPlantWitherRose() { Call("?_tryPlantWitherRose@Actor@@AEAAXXZ", void, Actor const*)(this); }
	MCINLINE void _updateOwnerChunk() { Call("?_updateOwnerChunk@Actor@@AEAAXXZ", void, Actor const*)(this); }
	MCINLINE void actuallyHurt(int a0, class ActorDamageSource const* a1, bool a2) { Call("?actuallyHurt@Actor@@UEAAXHPEBVActorDamageSource@@_N@Z", void, Actor const*, int, class ActorDamageSource const*, bool)(this, a0, a1, a2); }
	MCINLINE bool add(class ItemStack& a0) { return Call("?add@Actor@@UEAA_NAEAVItemStack@@@Z", bool, Actor const*, class ItemStack&)(this, a0); }
	MCINLINE void addAdditionalSaveData(class CompoundTag& a0) { Call("?addAdditionalSaveData@Actor@@MEAAXAEAVCompoundTag@@@Z", void, Actor const*, class CompoundTag&)(this, a0); }
	MCINLINE void addRider(class Actor& a0) { Call("?addRider@Actor@@UEAAXAEAV1@@Z", void, Actor const*, class Actor&)(this, a0); }
	MCINLINE void adjustDamageAmount(int& a0) const { Call("?adjustDamageAmount@Actor@@UEBAXAEAH@Z", void, Actor const*, int&)(this, a0); }
	MCINLINE void animateHurt() { Call("?animateHurt@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool attack(class Actor& a0) { return Call("?attack@Actor@@UEAA_NAEAV1@@Z", bool, Actor const*, class Actor&)(this, a0); }
	MCINLINE void awardKillScore(class Actor& a0, int a1) { Call("?awardKillScore@Actor@@UEAAXAEAV1@H@Z", void, Actor const*, class Actor&, int)(this, a0, a1); }
	MCINLINE void baseTick() { Call("?baseTick@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void blockedByShield(class ActorDamageSource const& a0, class Actor& a1) { Call("?blockedByShield@Actor@@UEAAXAEBVActorDamageSource@@AEAV1@@Z", void, Actor const*, class ActorDamageSource const&, class Actor&)(this, a0, a1); }
	MCINLINE bool breaksFallingBlocks() const { return Call("?breaksFallingBlocks@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE void buildDebugInfo() const { Call("?buildDebugInfo@Actor@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Actor const*)(this); }
	MCINLINE bool canAddRider(class Actor& a0) const { return Call("?canAddRider@Actor@@UEBA_NAEAV1@@Z", bool, Actor const*, class Actor&)(this, a0); }
	MCINLINE bool canAttack(class Actor* a0, bool a1) const { return Call("?canAttack@Actor@@UEBA_NPEAV1@_N@Z", bool, Actor const*, class Actor*, bool)(this, a0, a1); }
	MCINLINE bool canBeAffected(class MobEffectInstance const& a0) const { return Call("?canBeAffected@Actor@@UEBA_NAEBVMobEffectInstance@@@Z", bool, Actor const*, class MobEffectInstance const&)(this, a0); }
	MCINLINE bool canBeAffected(int a0) const { return Call("?canBeAffected@Actor@@UEBA_NH@Z", bool, Actor const*, int)(this, a0); }
	MCINLINE bool canBeAffectedByArrow(class MobEffectInstance const& a0) const { return Call("?canBeAffectedByArrow@Actor@@UEBA_NAEBVMobEffectInstance@@@Z", bool, Actor const*, class MobEffectInstance const&)(this, a0); }
	MCINLINE bool canBePulledIntoVehicle() const { return Call("?canBePulledIntoVehicle@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canChangeDimensions() const { return Call("?canChangeDimensions@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canDestroyBlock(class Block const& a0) const { return Call("?canDestroyBlock@Actor@@UEBA_NAEBVBlock@@@Z", bool, Actor const*, class Block const&)(this, a0); }
	MCINLINE bool canExistInPeaceful() const { return Call("?canExistInPeaceful@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canMakeStepSound() const { return Call("?canMakeStepSound@Actor@@MEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canPowerJump() const { return Call("?canPowerJump@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canSee(class Actor const& a0) const { return Call("?canSee@Actor@@UEBA_NAEBV1@@Z", bool, Actor const*, class Actor const&)(this, a0); }
	MCINLINE bool canSee(class Vec3 const& a0) const { return Call("?canSee@Actor@@UEBA_NAEBVVec3@@@Z", bool, Actor const*, class Vec3 const&)(this, a0); }
	MCINLINE bool canSeeInvisible() const { return Call("?canSeeInvisible@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canShowNameTag() const { return Call("?canShowNameTag@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool canSynchronizeNewEntity() const { return Call("?canSynchronizeNewEntity@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE void causeFallDamage(float a0) { Call("?causeFallDamage@Actor@@UEAAXM@Z", void, Actor const*, float)(this, a0); }
	MCINLINE void changeDimension(class ChangeDimensionPacket const& a0) { Call("?changeDimension@Actor@@UEAAXAEBVChangeDimensionPacket@@@Z", void, Actor const*, class ChangeDimensionPacket const&)(this, a0); }
	MCINLINE void changeDimension() { Call("?changeDimension@Actor@@UEAAXV?$AutomaticID@VDimension@@H@@_N@Z", void, Actor const*)(this); }
	MCINLINE void checkBlockCollisions(class AABB const& a0) { Call("?checkBlockCollisions@Actor@@UEAAXAEBVAABB@@@Z", void, Actor const*, class AABB const&)(this, a0); }
	MCINLINE void checkBlockCollisions() { Call("?checkBlockCollisions@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void checkFallDamage(float a0, bool a1) { Call("?checkFallDamage@Actor@@UEAAXM_N@Z", void, Actor const*, float, bool)(this, a0, a1); }
	MCINLINE void checkInsideBlocks(float a0) { Call("?checkInsideBlocks@Actor@@MEAAXM@Z", void, Actor const*, float)(this, a0); }
	MCINLINE void chorusFruitTeleport(class Vec3& a0) { Call("?chorusFruitTeleport@Actor@@UEAAXAEAVVec3@@@Z", void, Actor const*, class Vec3&)(this, a0); }
	MCINLINE bool consumeTotem() { return Call("?consumeTotem@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE void despawn() { Call("?despawn@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void die(class ActorDamageSource const& a0) { Call("?die@Actor@@UEAAXAEBVActorDamageSource@@@Z", void, Actor const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE bool doFireHurt(int a0) { return Call("?doFireHurt@Actor@@UEAA_NH@Z", bool, Actor const*, int)(this, a0); }
	MCINLINE void doWaterSplashEffect() { Call("?doWaterSplashEffect@Actor@@MEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool drop(class ItemStack const& a0, bool a1) { return Call("?drop@Actor@@UEAA_NAEBVItemStack@@_N@Z", bool, Actor const*, class ItemStack const&, bool)(this, a0, a1); }
	MCINLINE void feed(int a0) { Call("?feed@Actor@@UEAAXH@Z", void, Actor const*, int)(this, a0); }
	MCINLINE void filterFormattedNameTag(class UIProfanityContext const& a0) { Call("?filterFormattedNameTag@Actor@@UEAAXAEBVUIProfanityContext@@@Z", void, Actor const*, class UIProfanityContext const&)(this, a0); }
	MCINLINE class Actor* findAttackTarget() { return Call("?findAttackTarget@Actor@@UEAAPEAV1@XZ", class Actor*, Actor const*)(this); }
	MCINLINE void flagRiderToRemove(class Actor& a0) { Call("?flagRiderToRemove@Actor@@UEAAXAEAV1@@Z", void, Actor const*, class Actor&)(this, a0); }
	MCINLINE bool getAlwaysShowNameTag() const { return Call("?getAlwaysShowNameTag@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE class AnimationComponent& getAnimationComponent() { return Call("?getAnimationComponent@Actor@@UEAAAEAVAnimationComponent@@XZ", class AnimationComponent&, Actor const*)(this); }
	MCINLINE class ItemStack const& getArmor(enum ArmorSlot a0) const { return Call("?getArmor@Actor@@UEBAAEBVItemStack@@W4ArmorSlot@@@Z", class ItemStack const&, Actor const*, enum ArmorSlot)(this, a0); }
	MCINLINE float getArmorColorInSlot(enum ArmorSlot a0, int a1) const { return Call("?getArmorColorInSlot@Actor@@UEBAMW4ArmorSlot@@H@Z", float, Actor const*, enum ArmorSlot, int)(this, a0, a1); }
	MCINLINE enum ArmorTextureType getArmorMaterialTextureTypeInSlot(enum ArmorSlot a0) const { return Call("?getArmorMaterialTextureTypeInSlot@Actor@@UEBA?AW4ArmorTextureType@@W4ArmorSlot@@@Z", enum ArmorTextureType, Actor const*, enum ArmorSlot)(this, a0); }
	MCINLINE enum ArmorMaterialType getArmorMaterialTypeInSlot(enum ArmorSlot a0) const { return Call("?getArmorMaterialTypeInSlot@Actor@@UEBA?AW4ArmorMaterialType@@W4ArmorSlot@@@Z", enum ArmorMaterialType, Actor const*, enum ArmorSlot)(this, a0); }
	MCINLINE class AttributeInstance const& getAttribute(class Attribute const& a0) const { return Call("?getAttribute@Actor@@UEBAAEBVAttributeInstance@@AEBVAttribute@@@Z", class AttributeInstance const&, Actor const*, class Attribute const&)(this, a0); }
	MCINLINE float getBrightness(float a0) const { return Call("?getBrightness@Actor@@UEBAMM@Z", float, Actor const*, float)(this, a0); }
	MCINLINE float getCameraOffset() const { return Call("?getCameraOffset@Actor@@UEBAMXZ", float, Actor const*)(this); }
	MCINLINE class ItemStack const& getCarriedItem() const { return Call("?getCarriedItem@Actor@@UEBAAEBVItemStack@@XZ", class ItemStack const&, Actor const*)(this); }
	MCINLINE int getChestSlots() const { return Call("?getChestSlots@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE enum CommandPermissionLevel getCommandPermissionLevel() const { return Call("?getCommandPermissionLevel@Actor@@UEBA?AW4CommandPermissionLevel@@XZ", enum CommandPermissionLevel, Actor const*)(this); }
	MCINLINE int getDeathTime() const { return Call("?getDeathTime@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE void getDebugText() { Call("?getDebugText@Actor@@UEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z", void, Actor const*)(this); }
	MCINLINE class LootTable* getDefaultLootTable() { return Call("?getDefaultLootTable@Actor@@MEAAPEAVLootTable@@XZ", class LootTable*, Actor const*)(this); }
	MCINLINE float getDeletionDelayTimeSeconds() const { return Call("?getDeletionDelayTimeSeconds@Actor@@UEBAMXZ", float, Actor const*)(this); }
	MCINLINE enum ActorType getEntityTypeId() const { return Call("?getEntityTypeId@Actor@@UEBA?AW4ActorType@@XZ", enum ActorType, Actor const*)(this); }
	MCINLINE int getEquipSlots() const { return Call("?getEquipSlots@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE int getEquipmentCount() const { return Call("?getEquipmentCount@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE class ItemStack const& getEquippedTotem() const { return Call("?getEquippedTotem@Actor@@UEBAAEBVItemStack@@XZ", class ItemStack const&, Actor const*)(this); }
	MCINLINE bool getInteraction(class Player& a0, class ActorInteraction& a1, class Vec3 const& a2) { return Call("?getInteraction@Actor@@UEAA_NAEAVPlayer@@AEAVActorInteraction@@AEBVVec3@@@Z", bool, Actor const*, class Player&, class ActorInteraction&, class Vec3 const&)(this, a0, a1, a2); }
	MCINLINE float getInterpolatedBodyRot(float a0) const { return Call("?getInterpolatedBodyRot@Actor@@UEBAMM@Z", float, Actor const*, float)(this, a0); }
	MCINLINE float getInterpolatedBodyYaw(float a0) const { return Call("?getInterpolatedBodyYaw@Actor@@UEBAMM@Z", float, Actor const*, float)(this, a0); }
	MCINLINE float getInterpolatedHeadRot(float a0) const { return Call("?getInterpolatedHeadRot@Actor@@UEBAMM@Z", float, Actor const*, float)(this, a0); }
	MCINLINE float getInterpolatedWalkAnimSpeed(float a0) const { return Call("?getInterpolatedWalkAnimSpeed@Actor@@UEBAMM@Z", float, Actor const*, float)(this, a0); }
	MCINLINE int getInventorySize() const { return Call("?getInventorySize@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE int getLifeSpan() const { return Call("?getLifeSpan@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE class LootTable* getLootTable() { return Call("?getLootTable@Actor@@MEAAPEAVLootTable@@XZ", class LootTable*, Actor const*)(this); }
	MCINLINE float getMapDecorationRotation() const { return Call("?getMapDecorationRotation@Actor@@UEBAMXZ", float, Actor const*)(this); }
	MCINLINE class AttributeInstance* getMutableAttribute(class Attribute const& a0) { return Call("?getMutableAttribute@Actor@@UEAAPEAVAttributeInstance@@AEBVAttribute@@@Z", class AttributeInstance*, Actor const*, class Attribute const&)(this, a0); }
	MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& getNameTag() const { return Call("?getNameTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ", class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, Actor const*)(this); } MCINLINE unsigned __int64 getNameTagAsHash() const {
		return Call("?getNameTagAsHash@Actor@@UEBA_KXZ", unsigned __int64, Actor const*)(this);
	}
	MCINLINE int getOnDeathExperience() { return Call("?getOnDeathExperience@Actor@@UEAAHXZ", int, Actor const*)(this); }
	MCINLINE int getOutputSignal() const { return Call("?getOutputSignal@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE enum ActorType getOwnerEntityType() { return Call("?getOwnerEntityType@Actor@@UEAA?AW4ActorType@@XZ", enum ActorType, Actor const*)(this); }
	MCINLINE float getPickRadius() { return Call("?getPickRadius@Actor@@UEAAMXZ", float, Actor const*)(this); }
	MCINLINE int getPortalCooldown() const { return Call("?getPortalCooldown@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE int getPortalWaitTime() const { return Call("?getPortalWaitTime@Actor@@UEBAHXZ", int, Actor const*)(this); }
	MCINLINE class Vec3 const& getPos() const { return Call("?getPos@Actor@@UEBAAEBVVec3@@XZ", class Vec3 const&, Actor const*)(this); }
	MCINLINE class Vec3 const& getPosOld() const { return Call("?getPosOld@Actor@@UEBAAEBVVec3@@XZ", class Vec3 const&, Actor const*)(this); }
	MCINLINE float getRiderYRotation(class Actor const& a0) const { return Call("?getRiderYRotation@Actor@@UEBAMAEBV1@@Z", float, Actor const*, class Actor const&)(this, a0); }
	MCINLINE float getRidingHeight() { return Call("?getRidingHeight@Actor@@UEAAMXZ", float, Actor const*)(this); }
	MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& getScoreTag() const { return Call("?getScoreTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ", class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, Actor const*)(this); } MCINLINE float getShadowHeightOffs() {
		return Call("?getShadowHeightOffs@Actor@@UEAAMXZ", float, Actor const*)(this);
	}
	MCINLINE float getShadowRadius() const { return Call("?getShadowRadius@Actor@@UEBAMXZ", float, Actor const*)(this); }
	MCINLINE float getYHeadRot() const { return Call("?getYHeadRot@Actor@@UEBAMXZ", float, Actor const*)(this); }
	MCINLINE float getYawSpeedInDegreesPerSecond() const { return Call("?getYawSpeedInDegreesPerSecond@Actor@@UEBAMXZ", float, Actor const*)(this); }
	MCINLINE void handleEntityEvent(enum ActorEvent a0, int a1) { Call("?handleEntityEvent@Actor@@UEAAXW4ActorEvent@@H@Z", void, Actor const*, enum ActorEvent, int)(this, a0, a1); }
	MCINLINE void handleFallDistanceOnServer(float a0, bool a1) { Call("?handleFallDistanceOnServer@Actor@@UEAAXM_N@Z", void, Actor const*, float, bool)(this, a0, a1); }
	MCINLINE void handleInsidePortal(class BlockPos const& a0) { Call("?handleInsidePortal@Actor@@UEAAXAEBVBlockPos@@@Z", void, Actor const*, class BlockPos const&)(this, a0); }
	MCINLINE bool hasEnteredWater() const { return Call("?hasEnteredWater@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool hasOutputSignal(unsigned char a0) const { return Call("?hasOutputSignal@Actor@@UEBA_NE@Z", bool, Actor const*, unsigned char)(this, a0); }
	MCINLINE void heal(int a0) { Call("?heal@Actor@@UEAAXH@Z", void, Actor const*, int)(this, a0); }
	MCINLINE bool inCaravan() const { return Call("?inCaravan@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool interactPreventDefault() { return Call("?interactPreventDefault@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool intersects(class Vec3 const& a0, class Vec3 const& a1) const { return Call("?intersects@Actor@@UEBA_NAEBVVec3@@0@Z", bool, Actor const*, class Vec3 const&, class Vec3 const&)(this, a0, a1); }
	MCINLINE bool isAdventure() const { return Call("?isAdventure@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isAlive() const { return Call("?isAlive@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isBlocking() const { return Call("?isBlocking@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isCreative() const { return Call("?isCreative@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isCreativeModeAllowed() { return Call("?isCreativeModeAllowed@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isDamageBlocked(class ActorDamageSource const& a0) const { return Call("?isDamageBlocked@Actor@@UEBA_NAEBVActorDamageSource@@@Z", bool, Actor const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE bool isEnchanted() const { return Call("?isEnchanted@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isFishable() const { return Call("?isFishable@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isFree(class Vec3 const& a0) { return Call("?isFree@Actor@@UEAA_NAEBVVec3@@@Z", bool, Actor const*, class Vec3 const&)(this, a0); }
	MCINLINE bool isFree(class Vec3 const& a0, float a1) { return Call("?isFree@Actor@@UEAA_NAEBVVec3@@M@Z", bool, Actor const*, class Vec3 const&, float)(this, a0, a1); }
	MCINLINE bool isImmersedInWater() const { return Call("?isImmersedInWater@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isImmobile() const { return Call("?isImmobile@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInLava() const { return Call("?isInLava@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInWall() const { return Call("?isInWall@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInWater() const { return Call("?isInWater@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInWaterOrRain() const { return Call("?isInWaterOrRain@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInvertedHealAndHarm() const { return Call("?isInvertedHealAndHarm@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInvisible() const { return Call("?isInvisible@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isInvulnerableTo(class ActorDamageSource const& a0) const { return Call("?isInvulnerableTo@Actor@@UEBA_NAEBVActorDamageSource@@@Z", bool, Actor const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE bool isJumping() const { return Call("?isJumping@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isLeashableType() { return Call("?isLeashableType@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isOnFire() const { return Call("?isOnFire@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isOnHotBlock() const { return Call("?isOnHotBlock@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isOverWater() const { return Call("?isOverWater@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isPickable() { return Call("?isPickable@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isShootable() { return Call("?isShootable@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isSilent() { return Call("?isSilent@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isSkyLit(float a0) { return Call("?isSkyLit@Actor@@UEAA_NM@Z", bool, Actor const*, float)(this, a0); }
	MCINLINE bool isSleeping() const { return Call("?isSleeping@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isSneaking() const { return Call("?isSneaking@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isSurfaceMob() const { return Call("?isSurfaceMob@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isTargetable() const { return Call("?isTargetable@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool isUnderLiquid(enum MaterialType a0) const { return Call("?isUnderLiquid@Actor@@UEBA_NW4MaterialType@@@Z", bool, Actor const*, enum MaterialType)(this, a0); }
	MCINLINE bool isValidTarget(class Actor* a0) const { return Call("?isValidTarget@Actor@@UEBA_NPEAV1@@Z", bool, Actor const*, class Actor*)(this, a0); }
	MCINLINE bool isWorldBuilder() { return Call("?isWorldBuilder@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE void kill() { Call("?kill@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void killed(class Actor& a0) { Call("?killed@Actor@@UEAAXAEAV1@@Z", void, Actor const*, class Actor&)(this, a0); }
	MCINLINE void lerpMotion(class Vec3 const& a0) { Call("?lerpMotion@Actor@@UEAAXAEBVVec3@@@Z", void, Actor const*, class Vec3 const&)(this, a0); }
	MCINLINE void lerpTo(class Vec3 const& a0, class Vec2 const& a1, int a2) { Call("?lerpTo@Actor@@UEAAXAEBVVec3@@AEBVVec2@@H@Z", void, Actor const*, class Vec3 const&, class Vec2 const&, int)(this, a0, a1, a2); }
	MCINLINE bool load(class CompoundTag const& a0, class DataLoadHelper& a1) { return Call("?load@Actor@@UEAA_NAEBVCompoundTag@@AEAVDataLoadHelper@@@Z", bool, Actor const*, class CompoundTag const&, class DataLoadHelper&)(this, a0, a1); }
	MCINLINE void loadLinks(class CompoundTag const& a0) { Call("?loadLinks@Actor@@UEAAXAEBVCompoundTag@@AEAV?$vector@UActorLink@@V?$allocator@UActorLink@@@std@@@std@@AEAVDataLoadHelper@@@Z", void, Actor const*, class CompoundTag const&)(this, a0); }
	MCINLINE void makeStuckInBlock(float a0) { Call("?makeStuckInBlock@Actor@@UEAAXM@Z", void, Actor const*, float)(this, a0); }
	MCINLINE void markHurt() { Call("?markHurt@Actor@@MEAAXXZ", void, Actor const*)(this); }
	MCINLINE void move(class Vec3 const& a0) { Call("?move@Actor@@UEAAXAEBVVec3@@@Z", void, Actor const*, class Vec3 const&)(this, a0); }
	MCINLINE void moveRelative(float a0, float a1, float a2, float a3) { Call("?moveRelative@Actor@@UEAAXMMMM@Z", void, Actor const*, float, float, float, float)(this, a0, a1, a2, a3); }
	MCINLINE void normalTick() { Call("?normalTick@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void onAboveBubbleColumn(bool a0) { Call("?onAboveBubbleColumn@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void onBounceStarted(class BlockPos const& a0, class Block const& a1) { Call("?onBounceStarted@Actor@@UEAAXAEBVBlockPos@@AEBVBlock@@@Z", void, Actor const*, class BlockPos const&, class Block const&)(this, a0, a1); }
	MCINLINE void onEffectAdded(class MobEffectInstance& a0) { Call("?onEffectAdded@Actor@@UEAAXAEAVMobEffectInstance@@@Z", void, Actor const*, class MobEffectInstance&)(this, a0); }
	MCINLINE void onEffectRemoved(class MobEffectInstance& a0) { Call("?onEffectRemoved@Actor@@UEAAXAEAVMobEffectInstance@@@Z", void, Actor const*, class MobEffectInstance&)(this, a0); }
	MCINLINE void onEffectUpdated(class MobEffectInstance const& a0) { Call("?onEffectUpdated@Actor@@UEAAXAEBVMobEffectInstance@@@Z", void, Actor const*, class MobEffectInstance const&)(this, a0); }
	MCINLINE void onFailedTame() { Call("?onFailedTame@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void onInsideBubbleColumn(bool a0) { Call("?onInsideBubbleColumn@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void onLightningHit() { Call("?onLightningHit@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void onOrphan() { Call("?onOrphan@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void onSynchedDataUpdate(int a0) { Call("?onSynchedDataUpdate@Actor@@UEAAXH@Z", void, Actor const*, int)(this, a0); }
	MCINLINE void onTame() { Call("?onTame@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void openContainerComponent(class Player& a0) { Call("?openContainerComponent@Actor@@UEAAXAEAVPlayer@@@Z", void, Actor const*, class Player&)(this, a0); }
	MCINLINE void outOfWorld() { Call("?outOfWorld@Actor@@MEAAXXZ", void, Actor const*)(this); }
	MCINLINE void performRangedAttack(class Actor& a0, float a1) { Call("?performRangedAttack@Actor@@UEAAXAEAV1@M@Z", void, Actor const*, class Actor&, float)(this, a0, a1); }
	MCINLINE void playSynchronizedSound(enum LevelSoundEvent a0, class Vec3 const& a1, class Block const& a2, bool a3) { Call("?playSynchronizedSound@Actor@@UEAAXW4LevelSoundEvent@@AEBVVec3@@AEBVBlock@@_N@Z", void, Actor const*, enum LevelSoundEvent, class Vec3 const&, class Block const&, bool)(this, a0, a1, a2, a3); }
	MCINLINE void playSynchronizedSound(enum LevelSoundEvent a0, class Vec3 const& a1, int a2, bool a3) { Call("?playSynchronizedSound@Actor@@UEAAXW4LevelSoundEvent@@AEBVVec3@@H_N@Z", void, Actor const*, enum LevelSoundEvent, class Vec3 const&, int, bool)(this, a0, a1, a2, a3); }
	MCINLINE void playerTouch(class Player& a0) { Call("?playerTouch@Actor@@UEAAXAEAVPlayer@@@Z", void, Actor const*, class Player&)(this, a0); }
	MCINLINE void positionRider(class Actor& a0, float a1) { Call("?positionRider@Actor@@UEAAXAEAV1@M@Z", void, Actor const*, class Actor&, float)(this, a0, a1); }
	MCINLINE void pushOutOfBlocks(class Vec3 const& a0) { Call("?pushOutOfBlocks@Actor@@MEAAXAEBVVec3@@@Z", void, Actor const*, class Vec3 const&)(this, a0); }
	MCINLINE class HashedString const& queryEntityRenderer() const { return Call("?queryEntityRenderer@Actor@@UEBAAEBVHashedString@@XZ", class HashedString const&, Actor const*)(this); }
	MCINLINE void readAdditionalSaveData(class CompoundTag const& a0, class DataLoadHelper& a1) { Call("?readAdditionalSaveData@Actor@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z", void, Actor const*, class CompoundTag const&, class DataLoadHelper&)(this, a0, a1); }
	MCINLINE void reloadLootTable(struct EquipmentTableDescription const* a0) { Call("?reloadLootTable@Actor@@UEAAXPEBUEquipmentTableDescription@@@Z", void, Actor const*, struct EquipmentTableDescription const*)(this, a0); }
	MCINLINE void reloadLootTable() { Call("?reloadLootTable@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void remove() { Call("?remove@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void renderDebugServerState(class Options const& a0) { Call("?renderDebugServerState@Actor@@UEAAXAEBVOptions@@@Z", void, Actor const*, class Options const&)(this, a0); }
	MCINLINE void reset() { Call("?reset@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void rideJumped() { Call("?rideJumped@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void rideLanded(class Vec3 const& a0, class Vec3 const& a1) { Call("?rideLanded@Actor@@UEAAXAEBVVec3@@0@Z", void, Actor const*, class Vec3 const&, class Vec3 const&)(this, a0, a1); }
	MCINLINE void rideTick() { Call("?rideTick@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool save(class CompoundTag& a0) { return Call("?save@Actor@@UEAA_NAEAVCompoundTag@@@Z", bool, Actor const*, class CompoundTag&)(this, a0); }
	MCINLINE void saveWithoutId(class CompoundTag& a0) { Call("?saveWithoutId@Actor@@UEAAXAEAVCompoundTag@@@Z", void, Actor const*, class CompoundTag&)(this, a0); }
	MCINLINE void sendMotionPacketIfNeeded() { Call("?sendMotionPacketIfNeeded@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void setArmor(enum ArmorSlot a0, class ItemStack const& a1) { Call("?setArmor@Actor@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z", void, Actor const*, enum ArmorSlot, class ItemStack const&)(this, a0, a1); }
	MCINLINE void setAuxValue(int a0) { Call("?setAuxValue@Actor@@UEAAXH@Z", void, Actor const*, int)(this, a0); }
	MCINLINE void setCanPowerJump(bool a0) { Call("?setCanPowerJump@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void setCarriedItem(class ItemStack const& a0) { Call("?setCarriedItem@Actor@@UEAAXAEBVItemStack@@@Z", void, Actor const*, class ItemStack const&)(this, a0); }
	MCINLINE void setDamageNearbyMobs(bool a0) { Call("?setDamageNearbyMobs@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void setEquippedSlot(enum ArmorSlot a0, class ItemStack const& a1) { Call("?setEquippedSlot@Actor@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z", void, Actor const*, enum ArmorSlot, class ItemStack const&)(this, a0, a1); }
	MCINLINE void setEquippedSlot(enum ArmorSlot a0, int a1, int a2) { Call("?setEquippedSlot@Actor@@UEAAXW4ArmorSlot@@HH@Z", void, Actor const*, enum ArmorSlot, int, int)(this, a0, a1, a2); }
	MCINLINE void setNameTag() { Call("?setNameTag@Actor@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Actor const*)(this); }
	MCINLINE void setNameTagVisible(bool a0) { Call("?setNameTagVisible@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void setOffhandSlot(class ItemStack const& a0) { Call("?setOffhandSlot@Actor@@UEAAXAEBVItemStack@@@Z", void, Actor const*, class ItemStack const&)(this, a0); }
	MCINLINE void setOnFire(int a0) { Call("?setOnFire@Actor@@UEAAXH@Z", void, Actor const*, int)(this, a0); }
	MCINLINE void setPos(class Vec3 const& a0) { Call("?setPos@Actor@@UEAAXAEBVVec3@@@Z", void, Actor const*, class Vec3 const&)(this, a0); }
	MCINLINE void setRot(class Vec2 const& a0) { Call("?setRot@Actor@@UEAAXAEBVVec2@@@Z", void, Actor const*, class Vec2 const&)(this, a0); }
	MCINLINE void setScoreTag() { Call("?setScoreTag@Actor@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Actor const*)(this); }
	MCINLINE void setSitting(bool a0) { Call("?setSitting@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void setSize(float a0, float a1) { Call("?setSize@Actor@@UEAAXMM@Z", void, Actor const*, float, float)(this, a0, a1); }
	MCINLINE void setSneaking(bool a0) { Call("?setSneaking@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void setStanding(bool a0) { Call("?setStanding@Actor@@UEAAX_N@Z", void, Actor const*, bool)(this, a0); }
	MCINLINE void setTarget(class Actor* a0) { Call("?setTarget@Actor@@UEAAXPEAV1@@Z", void, Actor const*, class Actor*)(this, a0); }
	MCINLINE bool shouldRender() const { return Call("?shouldRender@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE bool shouldTick() const { return Call("?shouldTick@Actor@@UEBA_NXZ", bool, Actor const*)(this); }
	MCINLINE class ItemActor* spawnAtLocation(class Block const& a0, int a1) { return Call("?spawnAtLocation@Actor@@UEAAPEAVItemActor@@AEBVBlock@@H@Z", class ItemActor*, Actor const*, class Block const&, int)(this, a0, a1); }
	MCINLINE class ItemActor* spawnAtLocation(class Block const& a0, int a1, float a2) { return Call("?spawnAtLocation@Actor@@UEAAPEAVItemActor@@AEBVBlock@@HM@Z", class ItemActor*, Actor const*, class Block const&, int, float)(this, a0, a1, a2); }
	MCINLINE class ItemActor* spawnAtLocation(class ItemStack const& a0, float a1) { return Call("?spawnAtLocation@Actor@@UEAAPEAVItemActor@@AEBVItemStack@@M@Z", class ItemActor*, Actor const*, class ItemStack const&, float)(this, a0, a1); }
	MCINLINE class ItemActor* spawnAtLocation(int a0, int a1) { return Call("?spawnAtLocation@Actor@@UEAAPEAVItemActor@@HH@Z", class ItemActor*, Actor const*, int, int)(this, a0, a1); }
	MCINLINE class ItemActor* spawnAtLocation(int a0, int a1, float a2) { return Call("?spawnAtLocation@Actor@@UEAAPEAVItemActor@@HHM@Z", class ItemActor*, Actor const*, int, int, float)(this, a0, a1, a2); }
	MCINLINE void spawnTrailBubbles() { Call("?spawnTrailBubbles@Actor@@MEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool startRiding(class Actor& a0) { return Call("?startRiding@Actor@@UEAA_NAEAV1@@Z", bool, Actor const*, class Actor&)(this, a0); }
	MCINLINE void startSpinAttack() { Call("?startSpinAttack@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void startSwimming() { Call("?startSwimming@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void stopRiding(bool a0, bool a1, bool a2) { Call("?stopRiding@Actor@@UEAAX_N00@Z", void, Actor const*, bool, bool, bool)(this, a0, a1, a2); }
	MCINLINE void stopSpinAttack() { Call("?stopSpinAttack@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void stopSwimming() { Call("?stopSwimming@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void swing() { Call("?swing@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE void teleportTo(class Vec3 const& a0, bool a1, int a2, int a3) { Call("?teleportTo@Actor@@UEAAXAEBVVec3@@_NHH@Z", void, Actor const*, class Vec3 const&, bool, int, int)(this, a0, a1, a2, a3); }
	MCINLINE void tickLeash() { Call("?tickLeash@Actor@@UEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool tryTeleportTo(class Vec3 const& a0, bool a1, bool a2, int a3, int a4) { return Call("?tryTeleportTo@Actor@@UEAA_NAEBVVec3@@_N1HH@Z", bool, Actor const*, class Vec3 const&, bool, bool, int, int)(this, a0, a1, a2, a3, a4); }
	MCINLINE void updateEntitySpecificMolangVariables(class RenderParams& a0) { Call("?updateEntitySpecificMolangVariables@Actor@@MEAAXAEAVRenderParams@@@Z", void, Actor const*, class RenderParams&)(this, a0); }
	MCINLINE void updateInsideBlock() { Call("?updateInsideBlock@Actor@@MEAAXXZ", void, Actor const*)(this); }
	MCINLINE bool updateWaterState() { return Call("?updateWaterState@Actor@@MEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE void useItem(class ItemStack& a0, enum ItemUseMethod a1, bool a2) { Call("?useItem@Actor@@UEAAXAEAVItemStack@@W4ItemUseMethod@@_N@Z", void, Actor const*, class ItemStack&, enum ItemUseMethod, bool)(this, a0, a1, a2); }
	MCINLINE bool wasHurt() { return Call("?wasHurt@Actor@@UEAA_NXZ", bool, Actor const*)(this); }
	MCINLINE void wobble() { Call("?wobble@Actor@@UEAAXXZ", void, Actor const*)(this); }

	MCINLINE int getDimensionId() const { 
		int rv;
		Call("?getDimensionId@Actor@@UEBA?AV?$AutomaticID@VDimension@@H@@XZ", void, Actor const*,int&)(this,rv); 
		return rv;
	}
#if 0
/* std || und args */
	MCINLINE void setOwner(struct ActorUniqueID a0){ Call("?setOwner@Actor@@UEAAXUActorUniqueID@@@Z",void ,Actor const*,struct ActorUniqueID)(this,a0);}
	/* bad retval */
	MCINLINE class std::unique_ptr<class Packet,struct std::default_delete<class Packet> > getAddPacket(){ return Call("?getAddPacket@Actor@@UEAA?AV?$unique_ptr@VPacket@@U?$default_delete@VPacket@@@std@@@std@@XZ",class std::unique_ptr<class Packet,struct std::default_delete<class Packet> > ,Actor const*)(this);}
	MCINLINE class Vec3 getAttachPos(enum ActorLocation a0,float a1)const { return Call("?getAttachPos@Actor@@UEBA?AVVec3@@W4ActorLocation@@M@Z",class Vec3 ,Actor const*,enum ActorLocation,float)(this,a0,a1);}
	MCINLINE struct ActorUniqueID getControllingPlayer()const { return Call("?getControllingPlayer@Actor@@UEBA?AUActorUniqueID@@XZ",struct ActorUniqueID ,Actor const*)(this);}
	MCINLINE class AutomaticID<class Dimension,int> getDimensionId()const { return Call("?getDimensionId@Actor@@UEBA?AV?$AutomaticID@VDimension@@H@@XZ",class AutomaticID<class Dimension,int> ,Actor const*)(this);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getExitTip()const { return Call("?getExitTip@Actor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@W4InputMode@@@Z",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,Actor const*)(this);}
	MCINLINE class Vec3 getFiringPos()const { return Call("?getFiringPos@Actor@@UEBA?AVVec3@@XZ",class Vec3 ,Actor const*)(this);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getFormattedNameTag()const { return Call("?getFormattedNameTag@Actor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,Actor const*)(this);}
	MCINLINE class AABB getHandleWaterAABB()const { return Call("?getHandleWaterAABB@Actor@@UEBA?AVAABB@@XZ",class AABB ,Actor const*)(this);}
	MCINLINE class Vec3 getHeadLookVector(float a0){ return Call("?getHeadLookVector@Actor@@UEAA?AVVec3@@M@Z",class Vec3 ,Actor const*,float)(this,a0);}
	MCINLINE class Vec3 getInterpolatedRidingOffset(float a0)const { return Call("?getInterpolatedRidingOffset@Actor@@UEBA?AVVec3@@M@Z",class Vec3 ,Actor const*,float)(this,a0);}
	MCINLINE class Vec3 getInterpolatedRidingPosition(float a0)const { return Call("?getInterpolatedRidingPosition@Actor@@UEBA?AVVec3@@M@Z",class Vec3 ,Actor const*,float)(this,a0);}
	MCINLINE class Vec3 const getPosExtrapolated(float a0)const { return Call("?getPosExtrapolated@Actor@@UEBA?BVVec3@@M@Z",class Vec3 const ,Actor const*,float)(this,a0);}
	MCINLINE struct ActorUniqueID getSourceUniqueID()const { return Call("?getSourceUniqueID@Actor@@UEBA?AUActorUniqueID@@XZ",struct ActorUniqueID ,Actor const*)(this);}
#endif
};
class Mob:public Actor {
public:
	MCAPI Mob(class Level&);
	MCAPI Mob(class ActorDefinitionGroup*, struct ActorDefinitionIdentifier const&);
	MCAPI void _updateMobTravel(void);
	MCAPI bool checkTotemDeathProtection(class ActorDamageSource const&);
	MCAPI void frostWalk(void);
	MCAPI int getCaravanSize(void) const;
	MCAPI class Mob* getFirstCaravanHead(void);
	MCAPI void resetAttributes(void);
	MCAPI void setEatCounter(int);
	MCAPI void setIsPregnant(bool);
	MCAPI bool shouldApplyWaterGravity(void);
	MCINLINE bool _allowAscendingScaffolding() const { return Call("?_allowAscendingScaffolding@Mob@@MEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE void _endJump() { Call("?_endJump@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE float _getWalkTargetValue(class BlockPos const& a0) { return Call("?_getWalkTargetValue@Mob@@UEAAMAEBVBlockPos@@@Z", float, Mob const*, class BlockPos const&)(this, a0); }
	MCINLINE bool _hurt(class ActorDamageSource const& a0, int a1, bool a2, bool a3) { return Call("?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@H_N1@Z", bool, Mob const*, class ActorDamageSource const&, int, bool, bool)(this, a0, a1, a2, a3); }
	MCINLINE bool _initHardCodedComponents() { return Call("?_initHardCodedComponents@Mob@@AEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool _isHeadInWater() { return Call("?_isHeadInWater@Mob@@AEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE void _onSizeUpdated() { Call("?_onSizeUpdated@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void _playStepSound(class BlockPos const& a0, class Block const& a1) { Call("?_playStepSound@Mob@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z", void, Mob const*, class BlockPos const&, class Block const&)(this, a0, a1); }
	MCINLINE void _removeRider(struct ActorUniqueID const& a0, bool a1, bool a2) { Call("?_removeRider@Mob@@MEAAXAEBUActorUniqueID@@_N1@Z", void, Mob const*, struct ActorUniqueID const&, bool, bool)(this, a0, a1, a2); }
	MCINLINE void _serverAiMobStep() { Call("?_serverAiMobStep@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE bool _tryApplyingLevitation(class Vec3& a0) const { return Call("?_tryApplyingLevitation@Mob@@AEBA_NAEAVVec3@@@Z", bool, Mob const*, class Vec3&)(this, a0); }
	MCINLINE void _verifyAttributes() { Call("?_verifyAttributes@Mob@@AEAAXXZ", void, Mob const*)(this); }
	MCINLINE void actuallyHurt(int a0, class ActorDamageSource const* a1, bool a2) { Call("?actuallyHurt@Mob@@UEAAXHPEBVActorDamageSource@@_N@Z", void, Mob const*, int, class ActorDamageSource const*, bool)(this, a0, a1, a2); }
	MCINLINE void addAdditionalSaveData(class CompoundTag& a0) { Call("?addAdditionalSaveData@Mob@@MEAAXAEAVCompoundTag@@@Z", void, Mob const*, class CompoundTag&)(this, a0); }
	MCINLINE void addRider(class Actor& a0) { Call("?addRider@Mob@@UEAAXAEAVActor@@@Z", void, Mob const*, class Actor&)(this, a0); }
	MCINLINE void aiStep() { Call("?aiStep@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void animateHurt() { Call("?animateHurt@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void applyFinalFriction(float a0, bool a1) { Call("?applyFinalFriction@Mob@@UEAAXM_N@Z", void, Mob const*, float, bool)(this, a0, a1); }
	MCINLINE void ascendLadder() { Call("?ascendLadder@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void ascendScaffolding() { Call("?ascendScaffolding@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void ate() { Call("?ate@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE bool attack(class Actor& a0) { return Call("?attack@Mob@@UEAA_NAEAVActor@@@Z", bool, Mob const*, class Actor&)(this, a0); }
	MCINLINE void attackAnimation(class Actor* a0, float a1) { Call("?attackAnimation@Mob@@UEAAXPEAVActor@@M@Z", void, Mob const*, class Actor*, float)(this, a0, a1); }
	MCINLINE void baseTick() { Call("?baseTick@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void blockedByShield(class ActorDamageSource const& a0, class Actor& a1) { Call("?blockedByShield@Mob@@UEAAXAEBVActorDamageSource@@AEAVActor@@@Z", void, Mob const*, class ActorDamageSource const&, class Actor&)(this, a0, a1); }
	MCINLINE void buildDebugInfo() const { Call("?buildDebugInfo@Mob@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Mob const*)(this); }
	MCINLINE bool canBeControlledByRider() { return Call("?canBeControlledByRider@Mob@@UEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool canBePulledIntoVehicle() const { return Call("?canBePulledIntoVehicle@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool canExistWhenDisallowMob() const { return Call("?canExistWhenDisallowMob@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool canPowerJump() const { return Call("?canPowerJump@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE void causeFallDamage(float a0) { Call("?causeFallDamage@Mob@@MEAAXM@Z", void, Mob const*, float)(this, a0); }
	MCINLINE bool checkSpawnObstruction() const { return Call("?checkSpawnObstruction@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool checkSpawnRules(bool a0) { return Call("?checkSpawnRules@Mob@@UEAA_N_N@Z", bool, Mob const*, bool)(this, a0); }
	MCINLINE int clearEquipment() { return Call("?clearEquipment@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE void containerChanged(int a0) { Call("?containerChanged@Mob@@UEAAXH@Z", void, Mob const*, int)(this, a0); }
	MCINLINE bool createAIGoals() { return Call("?createAIGoals@Mob@@UEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE void descendScaffolding() { Call("?descendScaffolding@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void die(class ActorDamageSource const& a0) { Call("?die@Mob@@UEAAXAEBVActorDamageSource@@@Z", void, Mob const*, class ActorDamageSource const&)(this, a0); }
	MCINLINE bool doFireHurt(int a0) { return Call("?doFireHurt@Mob@@UEAA_NH@Z", bool, Mob const*, int)(this, a0); }
	MCINLINE bool doHurtTarget(class Actor* a0) { return Call("?doHurtTarget@Mob@@UEAA_NPEAVActor@@@Z", bool, Mob const*, class Actor*)(this, a0); }
	MCINLINE void dropBags() { Call("?dropBags@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void dropContainer() { Call("?dropContainer@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void dropEquipment(class ActorDamageSource const& a0, int a1) { Call("?dropEquipment@Mob@@MEAAXAEBVActorDamageSource@@H@Z", void, Mob const*, class ActorDamageSource const&, int)(this, a0, a1); }
	MCINLINE void dropEquipment() { Call("?dropEquipment@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>> getAllArmor() const { return Call("?getAllArmor@Mob@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ", class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>>, Mob const*)(this); } MCINLINE class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>> getAllEquipment() const {
		return Call("?getAllEquipment@Mob@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ", class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>>, Mob const*)(this);
	} MCINLINE class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>> getAllHand() const { return Call("?getAllHand@Mob@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ", class std::vector<class ItemStack const*, class std::allocator<class ItemStack const*>>, Mob const*)(this); } MCINLINE enum LevelSoundEvent getAmbientSound() {
		return Call("?getAmbientSound@Mob@@UEAA?AW4LevelSoundEvent@@XZ", enum LevelSoundEvent, Mob const*)(this);
	}
	MCINLINE int getAmbientSoundPostponeTicks() { return Call("?getAmbientSoundPostponeTicks@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE float getArmorColorInSlot(enum ArmorSlot a0, int a1) const { return Call("?getArmorColorInSlot@Mob@@UEBAMW4ArmorSlot@@H@Z", float, Mob const*, enum ArmorSlot, int)(this, a0, a1); }
	MCINLINE float getArmorCoverPercentage() const { return Call("?getArmorCoverPercentage@Mob@@UEBAMXZ", float, Mob const*)(this); }
	MCINLINE enum ArmorTextureType getArmorMaterialTextureTypeInSlot(enum ArmorSlot a0) const { return Call("?getArmorMaterialTextureTypeInSlot@Mob@@UEBA?AW4ArmorTextureType@@W4ArmorSlot@@@Z", enum ArmorTextureType, Mob const*, enum ArmorSlot)(this, a0); }
	MCINLINE enum ArmorMaterialType getArmorMaterialTypeInSlot(enum ArmorSlot a0) const { return Call("?getArmorMaterialTypeInSlot@Mob@@UEBA?AW4ArmorMaterialType@@W4ArmorSlot@@@Z", enum ArmorMaterialType, Mob const*, enum ArmorSlot)(this, a0); }
	MCINLINE int getArmorTypeHash() { return Call("?getArmorTypeHash@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE int getArmorValue() { return Call("?getArmorValue@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE float getAttackAnim(float a0) { return Call("?getAttackAnim@Mob@@UEAAMM@Z", float, Mob const*, float)(this, a0); }
	MCINLINE int getAttackTime() { return Call("?getAttackTime@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE int getDamageAfterArmorAbsorb(class ActorDamageSource const& a0, int a1) { return Call("?getDamageAfterArmorAbsorb@Mob@@MEAAHAEBVActorDamageSource@@H@Z", int, Mob const*, class ActorDamageSource const&, int)(this, a0, a1); }
	MCINLINE int getDamageAfterEnchantReduction(class ActorDamageSource const& a0, int a1) { return Call("?getDamageAfterEnchantReduction@Mob@@MEAAHAEBVActorDamageSource@@H@Z", int, Mob const*, class ActorDamageSource const&, int)(this, a0, a1); }
	MCINLINE int getDamageAfterMagicAbsorb(class ActorDamageSource const& a0, int a1) { return Call("?getDamageAfterMagicAbsorb@Mob@@UEAAHAEBVActorDamageSource@@H@Z", int, Mob const*, class ActorDamageSource const&, int)(this, a0, a1); }
	MCINLINE int getDeathTime() const { return Call("?getDeathTime@Mob@@UEBAHXZ", int, Mob const*)(this); }
	MCINLINE float getInterpolatedBodyRot(float a0) const { return Call("?getInterpolatedBodyRot@Mob@@UEBAMM@Z", float, Mob const*, float)(this, a0); }
	MCINLINE float getInterpolatedBodyYaw(float a0) const { return Call("?getInterpolatedBodyYaw@Mob@@UEBAMM@Z", float, Mob const*, float)(this, a0); }
	MCINLINE float getInterpolatedHeadRot(float a0) const { return Call("?getInterpolatedHeadRot@Mob@@UEBAMM@Z", float, Mob const*, float)(this, a0); }
	MCINLINE struct TextureUVCoordinateSet const* getItemInHandIcon(class ItemStack const& a0, int a1) { return Call("?getItemInHandIcon@Mob@@UEAAPEBUTextureUVCoordinateSet@@AEBVItemStack@@H@Z", struct TextureUVCoordinateSet const*, Mob const*, class ItemStack const&, int)(this, a0, a1); }
	MCINLINE int getItemUseDuration() { return Call("?getItemUseDuration@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE float getItemUseIntervalProgress() { return Call("?getItemUseIntervalProgress@Mob@@UEAAMXZ", float, Mob const*)(this); }
	MCINLINE float getItemUseStartupProgress() { return Call("?getItemUseStartupProgress@Mob@@UEAAMXZ", float, Mob const*)(this); }
	MCINLINE int getItemuseIntervalAxis() { return Call("?getItemuseIntervalAxis@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE float getJumpPower() const { return Call("?getJumpPower@Mob@@UEBAMXZ", float, Mob const*)(this); }
	MCINLINE class Mob* getLastHurtByMob() { return Call("?getLastHurtByMob@Mob@@UEAAPEAV1@XZ", class Mob*, Mob const*)(this); }
	MCINLINE class Player* getLastHurtByPlayer() { return Call("?getLastHurtByPlayer@Mob@@UEAAPEAVPlayer@@XZ", class Player*, Mob const*)(this); }
	MCINLINE class Mob* getLastHurtMob() { return Call("?getLastHurtMob@Mob@@UEAAPEAV1@XZ", class Mob*, Mob const*)(this); }
	MCINLINE float getMaxHeadXRot() { return Call("?getMaxHeadXRot@Mob@@UEAAMXZ", float, Mob const*)(this); }
	MCINLINE int getMeleeKnockbackBonus() { return Call("?getMeleeKnockbackBonus@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE int getMeleeWeaponDamageBonus(class Mob* a0) { return Call("?getMeleeWeaponDamageBonus@Mob@@UEAAHPEAV1@@Z", int, Mob const*, class Mob*)(this, a0); }
	MCINLINE float getSpeed() const { return Call("?getSpeed@Mob@@UEBAMXZ", float, Mob const*)(this); }
	MCINLINE int getTimeAlongSwing() { return Call("?getTimeAlongSwing@Mob@@UEAAHXZ", int, Mob const*)(this); }
	MCINLINE float getYHeadRot() const { return Call("?getYHeadRot@Mob@@UEBAMXZ", float, Mob const*)(this); }
	MCINLINE float getYawSpeedInDegreesPerSecond() const { return Call("?getYawSpeedInDegreesPerSecond@Mob@@UEBAMXZ", float, Mob const*)(this); }
	MCINLINE void goDownInWater() { Call("?goDownInWater@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void handleEntityEvent(enum ActorEvent a0, int a1) { Call("?handleEntityEvent@Mob@@UEAAXW4ActorEvent@@H@Z", void, Mob const*, enum ActorEvent, int)(this, a0, a1); }
	MCINLINE bool hasCaravanTail() const { return Call("?hasCaravanTail@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE void hurtArmor(int a0) { Call("?hurtArmor@Mob@@UEAAXH@Z", void, Mob const*, int)(this, a0); }
	MCINLINE bool hurtEffects(class ActorDamageSource const& a0, int a1, bool a2, bool a3) { return Call("?hurtEffects@Mob@@UEAA_NAEBVActorDamageSource@@H_N1@Z", bool, Mob const*, class ActorDamageSource const&, int, bool, bool)(this, a0, a1, a2, a3); }
	MCINLINE bool inCaravan() const { return Call("?inCaravan@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isAlive() const { return Call("?isAlive@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isAlliedTo(class Mob* a0) { return Call("?isAlliedTo@Mob@@UEAA_NPEAV1@@Z", bool, Mob const*, class Mob*)(this, a0); }
	MCINLINE bool isBlocking() const { return Call("?isBlocking@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isImmobile() const { return Call("?isImmobile@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isJumping() const { return Call("?isJumping@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isLookingAtAnEntity() { return Call("?isLookingAtAnEntity@Mob@@UEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isPickable() { return Call("?isPickable@Mob@@UEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isShootable() { return Call("?isShootable@Mob@@UEAA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isSleeping() const { return Call("?isSleeping@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isSprinting() const { return Call("?isSprinting@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE bool isSurfaceMob() const { return Call("?isSurfaceMob@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE void joinCaravan(class Mob* a0) { Call("?joinCaravan@Mob@@UEAAXPEAV1@@Z", void, Mob const*, class Mob*)(this, a0); }
	MCINLINE void jumpFromGround() { Call("?jumpFromGround@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void kill() { Call("?kill@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void knockback(class Actor* a0, int a1, float a2, float a3, float a4, float a5, float a6) { Call("?knockback@Mob@@UEAAXPEAVActor@@HMMMMM@Z", void, Mob const*, class Actor*, int, float, float, float, float, float)(this, a0, a1, a2, a3, a4, a5, a6); }
	MCINLINE void leaveCaravan() { Call("?leaveCaravan@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void lerpTo(class Vec3 const& a0, class Vec2 const& a1, int a2) { Call("?lerpTo@Mob@@UEAAXAEBVVec3@@AEBVVec2@@H@Z", void, Mob const*, class Vec3 const&, class Vec2 const&, int)(this, a0, a1, a2); }
	MCINLINE void lookAt(class Actor* a0, float a1, float a2) { Call("?lookAt@Mob@@UEAAXPEAVActor@@MM@Z", void, Mob const*, class Actor*, float, float)(this, a0, a1, a2); }
	MCINLINE void newServerAiStep() { Call("?newServerAiStep@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void normalTick() { Call("?normalTick@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void onBorn(class Actor& a0, class Actor& a1) { Call("?onBorn@Mob@@UEAAXAEAVActor@@0@Z", void, Mob const*, class Actor&, class Actor&)(this, a0, a1); }
	MCINLINE void outOfWorld() { Call("?outOfWorld@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void playAmbientSound() { Call("?playAmbientSound@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void playerTouch(class Player& a0) { Call("?playerTouch@Mob@@UEAAXAEAVPlayer@@@Z", void, Mob const*, class Player&)(this, a0); }
	MCINLINE void pushActors() { Call("?pushActors@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void readAdditionalSaveData(class CompoundTag const& a0, class DataLoadHelper& a1) { Call("?readAdditionalSaveData@Mob@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z", void, Mob const*, class CompoundTag const&, class DataLoadHelper&)(this, a0, a1); }
	MCINLINE void renderDebugServerState(class Options const& a0) { Call("?renderDebugServerState@Mob@@UEAAXAEBVOptions@@@Z", void, Mob const*, class Options const&)(this, a0); }
	MCINLINE void resolveDeathLoot(int a0, class ActorDamageSource const& a1) { Call("?resolveDeathLoot@Mob@@UEAAXHAEBVActorDamageSource@@@Z", void, Mob const*, int, class ActorDamageSource const&)(this, a0, a1); }
	MCINLINE void rideTick() { Call("?rideTick@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void sendArmor() { Call("?sendArmor@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void sendInventory(bool a0) { Call("?sendInventory@Mob@@UEAAX_N@Z", void, Mob const*, bool)(this, a0); }
	MCINLINE void setEquippedSlot(enum ArmorSlot a0, class ItemStack const& a1) { Call("?setEquippedSlot@Mob@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z", void, Mob const*, enum ArmorSlot, class ItemStack const&)(this, a0, a1); }
	MCINLINE void setEquippedSlot(enum ArmorSlot a0, int a1, int a2) { Call("?setEquippedSlot@Mob@@UEAAXW4ArmorSlot@@HH@Z", void, Mob const*, enum ArmorSlot, int, int)(this, a0, a1, a2); }
	MCINLINE bool setItemSlot(enum EquipmentSlot a0, class ItemStack const& a1) { return Call("?setItemSlot@Mob@@UEAA_NW4EquipmentSlot@@AEBVItemStack@@@Z", bool, Mob const*, enum EquipmentSlot, class ItemStack const&)(this, a0, a1); }
	MCINLINE void setLastHurtByMob(class Mob* a0) { Call("?setLastHurtByMob@Mob@@UEAAXPEAV1@@Z", void, Mob const*, class Mob*)(this, a0); }
	MCINLINE void setLastHurtByPlayer(class Player* a0) { Call("?setLastHurtByPlayer@Mob@@UEAAXPEAVPlayer@@@Z", void, Mob const*, class Player*)(this, a0); }
	MCINLINE void setLastHurtMob(class Actor* a0) { Call("?setLastHurtMob@Mob@@UEAAXPEAVActor@@@Z", void, Mob const*, class Actor*)(this, a0); }
	MCINLINE void setOnFire(int a0) { Call("?setOnFire@Mob@@UEAAXH@Z", void, Mob const*, int)(this, a0); }
	MCINLINE void setSleeping(bool a0) { Call("?setSleeping@Mob@@UEAAX_N@Z", void, Mob const*, bool)(this, a0); }
	MCINLINE void setSpeed(float a0) { Call("?setSpeed@Mob@@UEAAXM@Z", void, Mob const*, float)(this, a0); }
	MCINLINE void setSprinting(bool a0) { Call("?setSprinting@Mob@@UEAAX_N@Z", void, Mob const*, bool)(this, a0); }
	MCINLINE void setTarget(class Actor* a0) { Call("?setTarget@Mob@@UEAAXPEAVActor@@@Z", void, Mob const*, class Actor*)(this, a0); }
	MCINLINE void setTransitioningSitting(bool a0) { Call("?setTransitioningSitting@Mob@@UEAAX_N@Z", void, Mob const*, bool)(this, a0); }
	MCINLINE bool shouldDespawn() const { return Call("?shouldDespawn@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
	MCINLINE void spawnAnim() { Call("?spawnAnim@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE bool startRiding(class Actor& a0) { return Call("?startRiding@Mob@@UEAA_NAEAVActor@@@Z", bool, Mob const*, class Actor&)(this, a0); }
	MCINLINE void stopRiding(bool a0, bool a1, bool a2) { Call("?stopRiding@Mob@@UEAAX_N00@Z", void, Mob const*, bool, bool, bool)(this, a0, a1, a2); }
	MCINLINE void swing() { Call("?swing@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void teleportTo(class Vec3 const& a0, bool a1, int a2, int a3) { Call("?teleportTo@Mob@@UEAAXAEBVVec3@@_NHH@Z", void, Mob const*, class Vec3 const&, bool, int, int)(this, a0, a1, a2, a3); }
	MCINLINE void tickDeath() { Call("?tickDeath@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void travel(float a0, float a1, float a2) { Call("?travel@Mob@@UEAAXMMM@Z", void, Mob const*, float, float, float)(this, a0, a1, a2); }
	MCINLINE void updateAi() { Call("?updateAi@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void updateEntitySpecificMolangVariables(class RenderParams& a0) { Call("?updateEntitySpecificMolangVariables@Mob@@MEAAXAEAVRenderParams@@@Z", void, Mob const*, class RenderParams&)(this, a0); }
	MCINLINE void updateEquipment() { Call("?updateEquipment@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE void updateGliding() { Call("?updateGliding@Mob@@MEAAXXZ", void, Mob const*)(this); }
	MCINLINE void updateWalkAnim() { Call("?updateWalkAnim@Mob@@UEAAXXZ", void, Mob const*)(this); }
	MCINLINE bool useNewAi() const { return Call("?useNewAi@Mob@@UEBA_NXZ", bool, Mob const*)(this); }
#if 0
/* std || und args */
	/* bad retval */
	MCINLINE class std::vector<int,class std::allocator<int> > getAllArmorID()const { return Call("?getAllArmorID@Mob@@UEBA?AV?$vector@HV?$allocator@H@std@@@std@@XZ",class std::vector<int,class std::allocator<int> > ,Mob const*)(this);}
	MCINLINE struct ActorUniqueID getCaravanHead()const { return Call("?getCaravanHead@Mob@@UEBA?AUActorUniqueID@@XZ",struct ActorUniqueID ,Mob const*)(this);}
	MCINLINE class std::unique_ptr<class BodyControl,struct std::default_delete<class BodyControl> > initBodyControl(){ return Call("?initBodyControl@Mob@@MEAA?AV?$unique_ptr@VBodyControl@@U?$default_delete@VBodyControl@@@std@@@std@@XZ",class std::unique_ptr<class BodyControl,struct std::default_delete<class BodyControl> > ,Mob const*)(this);}
#endif
};
class BlockActor {
public:
	MCAPI BlockActor(enum BlockActorType, class BlockPos const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
	MCAPI void setCustomName(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&);
	MCINLINE void clearCache() { Call("?clearCache@BlockActor@@UEAAXXZ", void, BlockActor const*)(this); }
	MCINLINE class Container* getContainer() { return Call("?getContainer@BlockActor@@UEAAPEAVContainer@@XZ", class Container*, BlockActor const*)(this); }
	MCINLINE class BlockActor* getCrackEntity(class BlockSource& a0, class BlockPos const& a1) { return Call("?getCrackEntity@BlockActor@@UEAAPEAV1@AEAVBlockSource@@AEBVBlockPos@@@Z", class BlockActor*, BlockActor const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& getCustomName() const { return Call("?getCustomName@BlockActor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ", class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, BlockActor const*)(this); } MCINLINE void getDebugText() {
		Call("?getDebugText@BlockActor@@UEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@AEBVBlockPos@@@Z", void, BlockActor const*)(this);
	}
	MCINLINE float getDeletionDelayTimeSeconds() const { return Call("?getDeletionDelayTimeSeconds@BlockActor@@UEBAMXZ", float, BlockActor const*)(this); }
	MCINLINE class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& getFilteredCustomName(class UIProfanityContext const& a0) { return Call("?getFilteredCustomName@BlockActor@@UEAAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVUIProfanityContext@@@Z", class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, BlockActor const*, class UIProfanityContext const&)(this, a0); } MCINLINE class PistonBlockActor* getOwningPiston(class BlockSource& a0) {
		return Call("?getOwningPiston@BlockActor@@UEAAPEAVPistonBlockActor@@AEAVBlockSource@@@Z", class PistonBlockActor*, BlockActor const*, class BlockSource&)(this, a0);
	}
	MCINLINE int getRepairCost() const { return Call("?getRepairCost@BlockActor@@UEBAHXZ", int, BlockActor const*)(this); }
	MCINLINE float getShadowRadius(class BlockSource& a0) const { return Call("?getShadowRadius@BlockActor@@UEBAMAEAVBlockSource@@@Z", float, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE bool hasAlphaLayer() const { return Call("?hasAlphaLayer@BlockActor@@UEBA_NXZ", bool, BlockActor const*)(this); }
	MCINLINE bool isCustomNameSaved() { return Call("?isCustomNameSaved@BlockActor@@UEAA_NXZ", bool, BlockActor const*)(this); }
	MCINLINE bool isFinished() { return Call("?isFinished@BlockActor@@UEAA_NXZ", bool, BlockActor const*)(this); }
	MCINLINE bool isMovable(class BlockSource& a0) { return Call("?isMovable@BlockActor@@UEAA_NAEAVBlockSource@@@Z", bool, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE void load(class Level& a0, class CompoundTag const& a1, class DataLoadHelper& a2) { Call("?load@BlockActor@@UEAAXAEAVLevel@@AEBVCompoundTag@@AEAVDataLoadHelper@@@Z", void, BlockActor const*, class Level&, class CompoundTag const&, class DataLoadHelper&)(this, a0, a1, a2); }
	MCINLINE void loadBlockData(class CompoundTag const& a0, class BlockSource& a1, class DataLoadHelper& a2) { Call("?loadBlockData@BlockActor@@UEAAXAEBVCompoundTag@@AEAVBlockSource@@AEAVDataLoadHelper@@@Z", void, BlockActor const*, class CompoundTag const&, class BlockSource&, class DataLoadHelper&)(this, a0, a1, a2); }
	MCINLINE void onChanged(class BlockSource& a0) { Call("?onChanged@BlockActor@@UEAAXAEAVBlockSource@@@Z", void, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE void onChunkLoaded(class LevelChunk& a0) { Call("?onChunkLoaded@BlockActor@@UEAAXAEAVLevelChunk@@@Z", void, BlockActor const*, class LevelChunk&)(this, a0); }
	MCINLINE void onChunkUnloaded(class LevelChunk& a0) { Call("?onChunkUnloaded@BlockActor@@UEAAXAEAVLevelChunk@@@Z", void, BlockActor const*, class LevelChunk&)(this, a0); }
	MCINLINE void onCustomTagLoadDone(class BlockSource& a0) { Call("?onCustomTagLoadDone@BlockActor@@UEAAXAEAVBlockSource@@@Z", void, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE void onMove() { Call("?onMove@BlockActor@@UEAAXXZ", void, BlockActor const*)(this); }
	MCINLINE void onNeighborChanged(class BlockSource& a0, class BlockPos const& a1) { Call("?onNeighborChanged@BlockActor@@UEAAXAEAVBlockSource@@AEBVBlockPos@@@Z", void, BlockActor const*, class BlockSource&, class BlockPos const&)(this, a0, a1); }
	MCINLINE void onPlace(class BlockSource& a0) { Call("?onPlace@BlockActor@@UEAAXAEAVBlockSource@@@Z", void, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE void onRemoved(class BlockSource& a0) { Call("?onRemoved@BlockActor@@UEAAXAEAVBlockSource@@@Z", void, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE void onUpdatePacket(class CompoundTag const& a0, class BlockSource& a1) { Call("?onUpdatePacket@BlockActor@@UEAAXAEBVCompoundTag@@AEAVBlockSource@@@Z", void, BlockActor const*, class CompoundTag const&, class BlockSource&)(this, a0, a1); }
	MCINLINE bool save(class CompoundTag& a0) const { return Call("?save@BlockActor@@UEBA_NAEAVCompoundTag@@@Z", bool, BlockActor const*, class CompoundTag&)(this, a0); }
	MCINLINE void saveBlockData(class CompoundTag& a0, class BlockSource& a1) const { Call("?saveBlockData@BlockActor@@UEBAXAEAVCompoundTag@@AEAVBlockSource@@@Z", void, BlockActor const*, class CompoundTag&, class BlockSource&)(this, a0, a1); }
	MCINLINE bool saveItemInstanceData(class CompoundTag& a0) { return Call("?saveItemInstanceData@BlockActor@@UEAA_NAEAVCompoundTag@@@Z", bool, BlockActor const*, class CompoundTag&)(this, a0); }
	MCINLINE void tick(class BlockSource& a0) { Call("?tick@BlockActor@@UEAAXAEAVBlockSource@@@Z", void, BlockActor const*, class BlockSource&)(this, a0); }
	MCINLINE void triggerEvent(int a0, int a1) { Call("?triggerEvent@BlockActor@@UEAAXHH@Z", void, BlockActor const*, int, int)(this, a0, a1); }
#if 0
/* std || und args */
	/* bad retval */
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getImmersiveReaderText(class BlockSource & a0){ return Call("?getImmersiveReaderText@BlockActor@@UEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVBlockSource@@@Z",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,BlockActor const*,class BlockSource &)(this,a0);}
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > getName()const { return Call("?getName@BlockActor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,BlockActor const*)(this);}
	MCINLINE class std::unique_ptr<class Packet,struct std::default_delete<class Packet> > getUpdatePacket(class BlockSource & a0){ return Call("?getUpdatePacket@BlockActor@@UEAA?AV?$unique_ptr@VPacket@@U?$default_delete@VPacket@@@std@@@std@@AEAVBlockSource@@@Z",class std::unique_ptr<class Packet,struct std::default_delete<class Packet> > ,BlockActor const*,class BlockSource &)(this,a0);}
#endif
};
