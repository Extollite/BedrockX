#pragma once
#include "Core.h"
MCCLS class Level {
public:
	MCAPI Level(class SoundPlayer&, class std::unique_ptr<class LevelStorage, struct std::default_delete<class LevelStorage>>, class IMinecraftEventing&, bool, class Scheduler&, class StructureManager&, class ResourcePackManager&, class IEntityRegistryOwner&, class std::unique_ptr<class BlockComponentFactory, struct std::default_delete<class BlockComponentFactory>>, class std::unique_ptr<class BlockDefinitionGroup, struct std::default_delete<class BlockDefinitionGroup>>);
	MCAPI void addListener(class LevelListener&);
	MCAPI class Particle* addParticle(enum ParticleType, class Vec3 const&, class Vec3 const&, int, class CompoundTag const*, bool);
	MCAPI void addTerrainParticleEffect(class BlockPos const&, class Block const&, class Vec3 const&, float, float, float);
	MCAPI void broadcastBossEvent(enum BossEventUpdateType);
	MCAPI void broadcastDimensionEvent(class BlockSource&, enum LevelEvent, class Vec3 const&, int, class Player*);
	MCAPI void broadcastEntityEvent(class Actor*, enum ActorEvent, int);
	MCAPI void broadcastLevelEvent(enum LevelEvent, class CompoundTag const&, class Player*);
	MCAPI void broadcastLevelEvent(enum LevelEvent, class Vec3 const&, int, class Player*);
	MCAPI void broadcastSoundEvent(class BlockSource&, enum LevelSoundEvent, class Vec3 const&, int, struct ActorDefinitionIdentifier const&, bool, bool);
	MCAPI bool checkAndHandleMaterial(class AABB const&, enum MaterialType, class Actor*);
	MCAPI bool copyAndLockMap(struct ActorUniqueID, struct ActorUniqueID);
	MCAPI class Dimension& createDimension(class AutomaticID<class Dimension, int>);
	MCAPI class MapItemSavedData& createMapSavedData(struct ActorUniqueID const&, class BlockPos const&, class AutomaticID<class Dimension, int>, int);
	MCAPI void denyEffect(class Vec3 const&);
	MCAPI bool destroyBlock(class BlockSource&, class BlockPos const&, bool);
	MCAPI void entityChangeDimension(class Actor&, class AutomaticID<class Dimension, int>);
	MCAPI struct ActorUniqueID expandMapByID(struct ActorUniqueID, bool);
	MCAPI void explode(class BlockSource&, class Actor*, class Vec3 const&, float, bool, bool, float, bool);
	MCAPI bool extinguishFire(class BlockSource&, class BlockPos const&, unsigned char);
	MCAPI class Actor* fetchEntity(struct ActorUniqueID, bool) const;
	MCAPI class Player* findPlayer(class std::function<bool>) const;
	MCAPI void forEachDimension(class std::function<bool>);
	MCAPI void forEachPlayer(class std::function<bool>);
	MCAPI void forEachPlayer(class std::function<bool>) const;
	MCAPI void forceRemoveEntity(class Actor&);
	MCAPI struct AdventureSettings& getAdventureSettings(void);
	MCAPI enum Difficulty getDifficulty(void) const;
	MCINLINE class Dimension* getDimension(int a0) const {
		return Call("?getDimension@Level@@QEBAPEAVDimension@@V?$AutomaticID@VDimension@@H@@@Z", class Dimension*, void const*,int)(this,a0);
	};
	MCAPI class GameRules& getGameRules(void);
	MCAPI class MapItemSavedData* getMapSavedData(struct ActorUniqueID);
	MCAPI int getNewPlayerId(void) const;
	MCAPI class Color getPlayerColor(class Player const&) const;
	MCAPI class Player* getPrimaryLocalPlayer(void) const;
	MCAPI class Player* getRandomPlayer(void);
	MCAPI class Actor* getRuntimeEntity(class ActorRuntimeID, bool) const;
	MCAPI float getSpecialMultiplier(class AutomaticID<class Dimension, int>);
	MCAPI bool hasCommandsEnabled(void) const;
	MCAPI bool hasExperimentalGameplayEnabled(void) const;
	MCAPI bool isPlayerSuspended(class Player&) const;
	MCAPI void onChunkDiscarded(class LevelChunk&);
	MCAPI void playSound(class BlockSource&, enum LevelSoundEvent, class Vec3 const&, int, struct ActorDefinitionIdentifier const&, bool, bool);
	MCAPI void playSound(enum LevelSoundEvent, class Vec3 const&, int, struct ActorDefinitionIdentifier const&, bool, bool);
	MCAPI void playSynchronizedSound(class BlockSource&, enum LevelSoundEvent, class Vec3 const&, int, struct ActorDefinitionIdentifier const&, bool, bool);
	MCAPI void potionSplash(class Vec3 const&, class Color const&, bool);
	MCAPI void removeListener(class LevelListener&);
	MCAPI void requestMapInfo(struct ActorUniqueID);
	MCAPI void requestPlayerChangeDimension(class Player&, class std::unique_ptr<class ChangeDimensionRequest, struct std::default_delete<class ChangeDimensionRequest>>);
	MCAPI void save(void);
	MCAPI void saveBiomeData(void);
	MCAPI void saveDirtyChunks(void);
	MCAPI void saveGameData(void);
	MCAPI void saveLevelData(void);
	MCAPI void saveVillages(void);
	MCAPI void setDefaultGameType(enum GameType);
	MCAPI void spawnParticleEffect(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class Vec3 const&, class Dimension*);
	MCAPI void tickEntities(void);
	MCAPI void unregisterTemporaryPointer(class _TickPtr&);
	MCAPI void updateWeather(float, int, float, int);
	MCINLINE void _cleanupDisconnectedPlayers() { Call("?_cleanupDisconnectedPlayers@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE class MapItemSavedData& _createMapSavedData(struct ActorUniqueID const& a0) { return Call("?_createMapSavedData@Level@@AEAAAEAVMapItemSavedData@@AEBUActorUniqueID@@@Z", class MapItemSavedData&, Level const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE void _handleChangeDimensionRequests() { Call("?_handleChangeDimensionRequests@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE void _handlePlayerSuspension() { Call("?_handlePlayerSuspension@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE void _loadAutonomousEntities() { Call("?_loadAutonomousEntities@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE void _loadBiomeData() { Call("?_loadBiomeData@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE class MapItemSavedData* _loadMapData(struct ActorUniqueID const& a0) { return Call("?_loadMapData@Level@@AEAAPEAVMapItemSavedData@@AEBUActorUniqueID@@@Z", class MapItemSavedData*, Level const*, struct ActorUniqueID const&)(this, a0); }
	MCINLINE bool _playerChangeDimension(class Player* a0, class ChangeDimensionRequest& a1) { return Call("?_playerChangeDimension@Level@@AEAA_NPEAVPlayer@@AEAVChangeDimensionRequest@@@Z", bool, Level const*, class Player*, class ChangeDimensionRequest&)(this, a0, a1); }
	MCINLINE void _saveAutonomousEntities() { Call("?_saveAutonomousEntities@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE void _saveSomeChunks() { Call("?_saveSomeChunks@Level@@AEAAXXZ", void, Level const*)(this); }
	MCINLINE void _syncTime(int a0) { Call("?_syncTime@Level@@AEAAXH@Z", void, Level const*, int)(this, a0); }
	MCINLINE class Actor* addAutonomousEntity(class BlockSource& a0) { return Call("?addAutonomousEntity@Level@@UEAAPEAVActor@@AEAVBlockSource@@V?$unique_ptr@VActor@@U?$default_delete@VActor@@@std@@@std@@@Z", class Actor*, Level const*, class BlockSource&)(this, a0); }
	MCINLINE class Actor* addEntity(class BlockSource& a0) { return Call("?addEntity@Level@@UEAAPEAVActor@@AEAVBlockSource@@V?$unique_ptr@VActor@@U?$default_delete@VActor@@@std@@@std@@@Z", class Actor*, Level const*, class BlockSource&)(this, a0); }
	MCINLINE void addEntryToTagCache() { Call("?addEntryToTagCache@Level@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Level const*)(this); }
	MCINLINE class Actor* addGlobalEntity(class BlockSource& a0) { return Call("?addGlobalEntity@Level@@UEAAPEAVActor@@AEAVBlockSource@@V?$unique_ptr@VActor@@U?$default_delete@VActor@@@std@@@std@@@Z", class Actor*, Level const*, class BlockSource&)(this, a0); }
	MCINLINE void addPlayer() { Call("?addPlayer@Level@@UEAAXV?$unique_ptr@VPlayer@@U?$default_delete@VPlayer@@@std@@@std@@@Z", void, Level const*)(this); }
	MCINLINE void clearTagCache() { Call("?clearTagCache@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void decrementTagCache() { Call("?decrementTagCache@Level@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVTagRegistry@@@Z", void, Level const*)(this); }
	MCINLINE void directTickEntities(class BlockSource& a0) { Call("?directTickEntities@Level@@UEAAXAEAVBlockSource@@@Z", void, Level const*, class BlockSource&)(this, a0); }
	MCINLINE void dropEntryFromTagCache() { Call("?dropEntryFromTagCache@Level@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Level const*)(this); }
	MCINLINE class BiomeComponentFactory& getBiomeComponentFactory() { return Call("?getBiomeComponentFactory@Level@@UEAAAEAVBiomeComponentFactory@@XZ", class BiomeComponentFactory&, Level const*)(this); }
	MCINLINE class BiomeComponentFactory const& getBiomeComponentFactory() const { return Call("?getBiomeComponentFactory@Level@@UEBAAEBVBiomeComponentFactory@@XZ", class BiomeComponentFactory const&, Level const*)(this); }
	MCINLINE class BiomeRegistry& getBiomeRegistry() { return Call("?getBiomeRegistry@Level@@UEAAAEAVBiomeRegistry@@XZ", class BiomeRegistry&, Level const*)(this); }
	MCINLINE class BiomeRegistry const& getBiomeRegistry() const { return Call("?getBiomeRegistry@Level@@UEBAAEBVBiomeRegistry@@XZ", class BiomeRegistry const&, Level const*)(this); }
	MCINLINE class BlockPalette& getBlockPalette() { return Call("?getBlockPalette@Level@@UEAAAEAVBlockPalette@@XZ", class BlockPalette&, Level const*)(this); }
	MCINLINE class BlockPalette const& getBlockPalette() const { return Call("?getBlockPalette@Level@@UEBAAEBVBlockPalette@@XZ", class BlockPalette const&, Level const*)(this); }
	MCINLINE class ResourcePackManager* getClientResourcePackManager() const { return Call("?getClientResourcePackManager@Level@@UEBAPEAVResourcePackManager@@XZ", class ResourcePackManager*, Level const*)(this); }
    MCINLINE class FeatureRegistry& getFeatureRegistry() { return Call("?getFeatureRegistry@Level@@UEAAAEAVFeatureRegistry@@XZ", class FeatureRegistry&, Level const*)(this); }
	MCINLINE class FeatureRegistry const& getFeatureRegistry() const { return Call("?getFeatureRegistry@Level@@UEBAAEBVFeatureRegistry@@XZ", class FeatureRegistry const&, Level const*)(this); }
	MCINLINE class FeatureTypeFactory& getFeatureTypeFactory() { return Call("?getFeatureTypeFactory@Level@@UEAAAEAVFeatureTypeFactory@@XZ", class FeatureTypeFactory&, Level const*)(this); }
	MCINLINE class FeatureTypeFactory const& getFeatureTypeFactory() const { return Call("?getFeatureTypeFactory@Level@@UEBAAEBVFeatureTypeFactory@@XZ", class FeatureTypeFactory const&, Level const*)(this); }
	MCINLINE class JigsawStructureRegistry& getJigsawStructureRegistry() { return Call("?getJigsawStructureRegistry@Level@@UEAAAEAVJigsawStructureRegistry@@XZ", class JigsawStructureRegistry&, Level const*)(this); }
	MCINLINE class JigsawStructureRegistry const& getJigsawStructureRegistry() const { return Call("?getJigsawStructureRegistry@Level@@UEBAAEBVJigsawStructureRegistry@@XZ", class JigsawStructureRegistry const&, Level const*)(this); }
	MCINLINE class ResourcePackManager* getServerResourcePackManager() const { return Call("?getServerResourcePackManager@Level@@UEBAPEAVResourcePackManager@@XZ", class ResourcePackManager*, Level const*)(this); }
	MCINLINE class StructureManager& getStructureManager() { return Call("?getStructureManager@Level@@UEAAAEAVStructureManager@@XZ", class StructureManager&, Level const*)(this); }
	MCINLINE class StructureManager const& getStructureManager() const { return Call("?getStructureManager@Level@@UEBAAEBVStructureManager@@XZ", class StructureManager const&, Level const*)(this); }
	MCINLINE class SurfaceBuilderRegistry& getSurfaceBuilderRegistry() { return Call("?getSurfaceBuilderRegistry@Level@@UEAAAEAVSurfaceBuilderRegistry@@XZ", class SurfaceBuilderRegistry&, Level const*)(this); }
	MCINLINE class SurfaceBuilderRegistry const& getSurfaceBuilderRegistry() const { return Call("?getSurfaceBuilderRegistry@Level@@UEBAAEBVSurfaceBuilderRegistry@@XZ", class SurfaceBuilderRegistry const&, Level const*)(this); }
	MCINLINE class TagRegistry& getTagRegistry() { return Call("?getTagRegistry@Level@@UEAAAEAVTagRegistry@@XZ", class TagRegistry&, Level const*)(this); }
	MCINLINE class TradeTables* getTradeTables() { return Call("?getTradeTables@Level@@UEAAPEAVTradeTables@@XZ", class TradeTables*, Level const*)(this); }
	MCINLINE void incrementTagCache() { Call("?incrementTagCache@Level@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVTagRegistry@@@Z", void, Level const*)(this); }
	MCINLINE bool initialize() { return Call("?initialize@Level@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVLevelSettings@@PEAVLevelData@@PEBV23@@Z", bool, Level const*)(this); }
	MCINLINE void loadFunctionManager() { Call("?loadFunctionManager@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void onChunkLoaded(class LevelChunk& a0) { Call("?onChunkLoaded@Level@@UEAAXAEAVLevelChunk@@@Z", void, Level const*, class LevelChunk&)(this, a0); }
	MCINLINE void onNewChunk(class BlockSource& a0, class LevelChunk& a1) { Call("?onNewChunk@Level@@UEAAXAEAVBlockSource@@AEAVLevelChunk@@@Z", void, Level const*, class BlockSource&, class LevelChunk&)(this, a0, a1); }
	MCINLINE void onNewChunkFor(class Player& a0, class LevelChunk& a1) { Call("?onNewChunkFor@Level@@UEAAXAEAVPlayer@@AEAVLevelChunk@@@Z", void, Level const*, class Player&, class LevelChunk&)(this, a0, a1); }
	MCINLINE void onPlayerDeath(class Player& a0, class ActorDamageSource const& a1) { Call("?onPlayerDeath@Level@@UEAAXAEAVPlayer@@AEBVActorDamageSource@@@Z", void, Level const*, class Player&, class ActorDamageSource const&)(this, a0, a1); }
	MCINLINE void onSourceCreated(class BlockSource& a0) { Call("?onSourceCreated@Level@@UEAAXAEAVBlockSource@@@Z", void, Level const*, class BlockSource&)(this, a0); }
	MCINLINE void onSourceDestroyed(class BlockSource& a0) { Call("?onSourceDestroyed@Level@@UEAAXAEAVBlockSource@@@Z", void, Level const*, class BlockSource&)(this, a0); }
	MCINLINE void queueEntityRemoval() { Call("?queueEntityRemoval@Level@@UEAAX$$QEAV?$unique_ptr@VActor@@U?$default_delete@VActor@@@std@@@std@@_N@Z", void, Level const*)(this); }
	MCINLINE void removeEntityReferences(class Actor& a0, bool a1) { Call("?removeEntityReferences@Level@@UEAAXAEAVActor@@_N@Z", void, Level const*, class Actor&, bool)(this, a0, a1); }
	MCINLINE void runCommand(class HashedString const& a0, class CommandOrigin& a1, enum CommandOriginSystem a2, enum CurrentCmdVersion a3) { Call("?runCommand@Level@@UEAAXAEBVHashedString@@AEAVCommandOrigin@@W4CommandOriginSystem@@W4CurrentCmdVersion@@@Z", void, Level const*, class HashedString const&, class CommandOrigin&, enum CommandOriginSystem, enum CurrentCmdVersion)(this, a0, a1, a2, a3); }
	MCINLINE void saveAdditionalData() { Call("?saveAdditionalData@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void setCommandsEnabled(bool a0) { Call("?setCommandsEnabled@Level@@UEAAX_N@Z", void, Level const*, bool)(this, a0); }
	MCINLINE void setDifficulty(enum Difficulty a0) { Call("?setDifficulty@Level@@UEAAXW4Difficulty@@@Z", void, Level const*, enum Difficulty)(this, a0); }
	MCINLINE void setFinishedInitializing() { Call("?setFinishedInitializing@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void setWorldTemplateOptionsUnlocked() { Call("?setWorldTemplateOptionsUnlocked@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void startLeaveGame() { Call("?startLeaveGame@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void tick() { Call("?tick@Level@@UEAAXXZ", void, Level const*)(this); }
	MCINLINE void updateSleepingPlayerList() { Call("?updateSleepingPlayerList@Level@@UEAAXXZ", void, Level const*)(this); }
#if 0
/* std || und args */
	/* bad retval */
	MCINLINE class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > _getValidatedPlayerName(){ return Call("?_getValidatedPlayerName@Level@@AEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@@Z",class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > ,Level const*)(this);}
	MCINLINE struct Tick const getCurrentServerTick()const { return Call("?getCurrentServerTick@Level@@UEBA?BUTick@@XZ",struct Tick const ,Level const*)(this);}
#endif
};
#pragma once
#include "Core.h"
MCCLS class ServerLevel : public Level {
public:
	MCAPI ServerLevel(class SoundPlayer&, class std::unique_ptr<class LevelStorage, struct std::default_delete<class LevelStorage>>, class IMinecraftEventing&, class ResourcePackManager&, class ResourcePackManager&, class StructureManager&, class MinecraftCommands&, class Scheduler&, class IEntityRegistryOwner&, class std::unique_ptr<class BlockComponentFactory, struct std::default_delete<class BlockComponentFactory>>, class std::unique_ptr<class BlockDefinitionGroup, struct std::default_delete<class BlockDefinitionGroup>>);
	MCINLINE void addEntryToTagCache() { Call("?addEntryToTagCache@ServerLevel@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, ServerLevel const*)(this); }
	MCINLINE void clearTagCache() { Call("?clearTagCache@ServerLevel@@UEAAXXZ", void, ServerLevel const*)(this); }
	MCINLINE void decrementTagCache() { Call("?decrementTagCache@ServerLevel@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVTagRegistry@@@Z", void, ServerLevel const*)(this); }
	MCINLINE void dropEntryFromTagCache() { Call("?dropEntryFromTagCache@ServerLevel@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, ServerLevel const*)(this); }
	MCINLINE class ResourcePackManager* getClientResourcePackManager() const { return Call("?getClientResourcePackManager@ServerLevel@@UEBAPEAVResourcePackManager@@XZ", class ResourcePackManager*, ServerLevel const*)(this); }
	MCINLINE class LevelEventCoordinator& getLevelEventCoordinator() { return Call("?getLevelEventCoordinator@ServerLevel@@UEAAAEAVLevelEventCoordinator@@XZ", class LevelEventCoordinator&, ServerLevel const*)(this); }
	MCINLINE class ResourcePackManager* getServerResourcePackManager() const { return Call("?getServerResourcePackManager@ServerLevel@@UEBAPEAVResourcePackManager@@XZ", class ResourcePackManager*, ServerLevel const*)(this); }
	MCINLINE class TradeTables* getTradeTables() { return Call("?getTradeTables@ServerLevel@@UEAAPEAVTradeTables@@XZ", class TradeTables*, ServerLevel const*)(this); }
	MCINLINE void incrementTagCache() { Call("?incrementTagCache@ServerLevel@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVTagRegistry@@@Z", void, ServerLevel const*)(this); }
	MCINLINE bool initialize() { return Call("?initialize@ServerLevel@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVLevelSettings@@PEAVLevelData@@PEBV23@@Z", bool, ServerLevel const*)(this); }
	MCINLINE void loadFunctionManager() { Call("?loadFunctionManager@ServerLevel@@UEAAXXZ", void, ServerLevel const*)(this); }
	MCINLINE void runCommand(class HashedString const& a0, class CommandOrigin& a1, enum CommandOriginSystem a2, enum CurrentCmdVersion a3) { Call("?runCommand@ServerLevel@@UEAAXAEBVHashedString@@AEAVCommandOrigin@@W4CommandOriginSystem@@W4CurrentCmdVersion@@@Z", void, ServerLevel const*, class HashedString const&, class CommandOrigin&, enum CommandOriginSystem, enum CurrentCmdVersion)(this, a0, a1, a2, a3); }
	MCINLINE void saveAdditionalData() { Call("?saveAdditionalData@ServerLevel@@UEAAXXZ", void, ServerLevel const*)(this); }
	MCINLINE void setCommandsEnabled(bool a0) { Call("?setCommandsEnabled@ServerLevel@@UEAAX_N@Z", void, ServerLevel const*, bool)(this, a0); }
	MCINLINE void setDifficulty(enum Difficulty a0) { Call("?setDifficulty@ServerLevel@@UEAAXW4Difficulty@@@Z", void, ServerLevel const*, enum Difficulty)(this, a0); }
	MCINLINE void setWorldTemplateOptionsUnlocked() { Call("?setWorldTemplateOptionsUnlocked@ServerLevel@@UEAAXXZ", void, ServerLevel const*)(this); }
	MCINLINE void tick() { Call("?tick@ServerLevel@@UEAAXXZ", void, ServerLevel const*)(this); }
	MCINLINE void updateSleepingPlayerList() { Call("?updateSleepingPlayerList@ServerLevel@@UEAAXXZ", void, ServerLevel const*)(this); }
#if 0
/* std || und args */
	/* bad retval */
#endif
};
class LevelStorage {
public:
	MCINLINE void freeCaches() { Call("?freeCaches@LevelStorage@@UEAAXXZ", void, LevelStorage const*)(this); }
};