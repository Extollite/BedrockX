#pragma once
#include "Core.h"
MCCLS class Dimension {
public:
	MCAPI Dimension(class Level&, class AutomaticID<class Dimension, int>, short, class Scheduler&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>);
	MCAPI float distanceToNearestPlayerSqr2D(class Vec3);
	MCAPI class Actor* fetchEntity(struct ActorUniqueID, bool);
	MCAPI class Player* fetchNearestAttackablePlayer(class Actor&, float);
	MCAPI class Player* fetchNearestAttackablePlayer(class BlockPos, float, class Actor*);
	MCAPI class Player* fetchNearestPlayer(class Actor&, float);
	MCAPI class Player* fetchNearestPlayer(float, float, float, float, bool);
	MCAPI class Player* findPlayer(class std::function<bool>) const;
	MCAPI void forEachPlayer(class std::function<bool>);
	MCAPI void forEachPlayer(class std::function<bool>) const;
	MCAPI float getMoonBrightness(void) const;
	MCAPI int getMoonPhase(void) const;
	MCAPI float getTimeOfDay(float) const;
	MCAPI void sendPacketForEntity(class Actor const&, class Packet const&, class Player const*);
	MCAPI void sendPacketForPosition(class BlockPos const&, class Packet const&, class Player const*);
	MCAPI void transferEntity(class Vec3 const&, class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>>);
	MCAPI void transferEntityToUnloadedChunk(class Vec3 const&, class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>>);
	MCAPI void tryGarbageCollectStructures(void);
	MCINLINE void _tickEntityChunkMoves() { Call("?_tickEntityChunkMoves@Dimension@@AEAAXXZ", void, Dimension const*)(this); }
	MCINLINE void deserialize(class CompoundTag const& a0) { Call("?deserialize@Dimension@@UEAAXAEBVCompoundTag@@@Z", void, Dimension const*, class CompoundTag const&)(this, a0); }
	MCINLINE float getClearColorScale() { return Call("?getClearColorScale@Dimension@@UEAAMXZ", float, Dimension const*)(this); }
	MCINLINE float getCloudHeight() const { return Call("?getCloudHeight@Dimension@@UEBAMXZ", float, Dimension const*)(this); }
	MCINLINE int getDefaultBiome() const { return Call("?getDefaultBiome@Dimension@@UEBAHXZ", int, Dimension const*)(this); }
	MCINLINE float getMaxFogEnd() const { return Call("?getMaxFogEnd@Dimension@@UEBAMXZ", float, Dimension const*)(this); }
	MCINLINE float getMaxFogStart() const { return Call("?getMaxFogStart@Dimension@@UEBAMXZ", float, Dimension const*)(this); }
	MCINLINE int getSpawnYPosition() const { return Call("?getSpawnYPosition@Dimension@@UEBAHXZ", int, Dimension const*)(this); }
	MCINLINE float getSunIntensity(float a0, class Vec3 const& a1, float a2) const { return Call("?getSunIntensity@Dimension@@UEBAMMAEBVVec3@@M@Z", float, Dimension const*, float, class Vec3 const&, float)(this, a0, a1, a2); }
	MCINLINE float getTimeOfDay(int a0, float a1) const { return Call("?getTimeOfDay@Dimension@@MEBAMHM@Z", float, Dimension const*, int, float)(this, a0, a1); }
	MCINLINE bool hasBedrockFog() { return Call("?hasBedrockFog@Dimension@@UEAA_NXZ", bool, Dimension const*)(this); }
	MCINLINE bool hasGround() const { return Call("?hasGround@Dimension@@UEBA_NXZ", bool, Dimension const*)(this); }
	MCINLINE void init() { Call("?init@Dimension@@UEAAXXZ", void, Dimension const*)(this); }
	MCINLINE bool isDay() const { return Call("?isDay@Dimension@@UEBA_NXZ", bool, Dimension const*)(this); }
	MCINLINE bool isFoggyAt(int a0, int a1) const { return Call("?isFoggyAt@Dimension@@UEBA_NHH@Z", bool, Dimension const*, int, int)(this, a0, a1); }
	MCINLINE bool isNaturalDimension() const { return Call("?isNaturalDimension@Dimension@@UEBA_NXZ", bool, Dimension const*)(this); }
	MCINLINE bool isValidSpawn(int a0, int a1) const { return Call("?isValidSpawn@Dimension@@UEBA_NHH@Z", bool, Dimension const*, int, int)(this, a0, a1); }
	MCINLINE bool mayRespawn() const { return Call("?mayRespawn@Dimension@@UEBA_NXZ", bool, Dimension const*)(this); }
	MCINLINE void onBlockChanged(class BlockSource& a0, class BlockPos const& a1, unsigned int a2, class Block const& a3, class Block const& a4, int a5, struct ActorBlockSyncMessage const* a6) { Call("?onBlockChanged@Dimension@@UEAAXAEAVBlockSource@@AEBVBlockPos@@IAEBVBlock@@2HPEBUActorBlockSyncMessage@@@Z", void, Dimension const*, class BlockSource&, class BlockPos const&, unsigned int, class Block const&, class Block const&, int, struct ActorBlockSyncMessage const*)(this, a0, a1, a2, a3, a4, a5, a6); }
	MCINLINE void onBlockEvent(class BlockSource& a0, int a1, int a2, int a3, int a4, int a5) { Call("?onBlockEvent@Dimension@@UEAAXAEAVBlockSource@@HHHHH@Z", void, Dimension const*, class BlockSource&, int, int, int, int, int)(this, a0, a1, a2, a3, a4, a5); }
	MCINLINE void onChunkLoaded(class LevelChunk& a0) { Call("?onChunkLoaded@Dimension@@UEAAXAEAVLevelChunk@@@Z", void, Dimension const*, class LevelChunk&)(this, a0); }
	MCINLINE void onLevelDestruction() { Call("?onLevelDestruction@Dimension@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z", void, Dimension const*)(this); }
	MCINLINE void onNewChunk(class BlockSource& a0, class LevelChunk& a1) { Call("?onNewChunk@Dimension@@UEAAXAEAVBlockSource@@AEAVLevelChunk@@@Z", void, Dimension const*, class BlockSource&, class LevelChunk&)(this, a0, a1); }
	MCINLINE void sendBroadcast(class Packet const& a0, class Player* a1) { Call("?sendBroadcast@Dimension@@UEAAXAEBVPacket@@PEAVPlayer@@@Z", void, Dimension const*, class Packet const&, class Player*)(this, a0, a1); }
	MCINLINE void serialize(class CompoundTag& a0) const { Call("?serialize@Dimension@@UEBAXAEAVCompoundTag@@@Z", void, Dimension const*, class CompoundTag&)(this, a0); }
	MCINLINE bool showSky() const { return Call("?showSky@Dimension@@UEBA_NXZ", bool, Dimension const*)(this); }
	MCINLINE void startLeaveGame() { Call("?startLeaveGame@Dimension@@UEAAXXZ", void, Dimension const*)(this); }
	MCINLINE void tick() { Call("?tick@Dimension@@UEAAXXZ", void, Dimension const*)(this); }
	MCINLINE void tickRedstone() { Call("?tickRedstone@Dimension@@UEAAXXZ", void, Dimension const*)(this); }
	MCINLINE void updateLightRamp() { Call("?updateLightRamp@Dimension@@UEAAXXZ", void, Dimension const*)(this); }
	MCINLINE void upgradeOldLimboEntity(class CompoundTag& a0, enum LimboEntitiesVersion a1) { Call("?upgradeOldLimboEntity@Dimension@@AEAAXAEAVCompoundTag@@W4LimboEntitiesVersion@@@Z", void, Dimension const*, class CompoundTag&, enum LimboEntitiesVersion)(this, a0, a1); }
	class BlockPos getSpawnPos() {
		BlockPos rv;
		Call("?getSpawnPos@Dimension@@UEBA?AVBlockPos@@XZ", void, Dimension*, class BlockPos&)(this, rv);
		return rv;
	}
};

