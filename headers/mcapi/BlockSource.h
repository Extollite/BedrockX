#pragma once
#include "Core.h"
#include"ChunkSource.h"
MCCLS class BlockSource {
private:
	char filler[224];
public : 
	MCAPI BlockSource(class Level&, class Dimension&, class ChunkSource&, bool, bool);
	MCAPI void addListener(class BlockSourceListener&);
	MCAPI void addToRandomTickingQueue(class BlockPos const&, class Block const&, int, int);
	MCAPI void addToTickingQueue(class BlockPos const&, class Block const&, int, int);
	MCAPI bool areChunksFullyLoaded(class BlockPos const&, int);
	MCAPI void blockEvent(class BlockPos const&, int, int);
	MCAPI bool canSeeSky(class BlockPos const&) const;
	MCAPI bool canSeeSky(int, int, int) const;
	MCAPI bool canSeeSkyFromBelowWater(class BlockPos const&);
	MCAPI bool checkBlockDestroyPermissions(class Actor&, class BlockPos const&, class ItemStack const&, bool);
	MCAPI bool checkBlockPermissions(class Actor&, class BlockPos const&, unsigned char, class ItemStack const&, bool);
	MCAPI class HitResult clip(class Vec3 const&, class Vec3 const&, bool, bool, int, bool, bool);
	MCAPI bool containsAnyBlockOfType(class BlockPos const&, class BlockPos const&, class Block const&);
	MCAPI bool containsAnyLiquid(class AABB const&);
	MCAPI bool containsAnySolidBlocking(class AABB const&);
	MCAPI bool containsFireBlock(class AABB const&);
	MCAPI bool containsLiquid(class AABB const&, enum MaterialType);
	MCAPI bool containsMaterial(class AABB const&, enum MaterialType);
	MCAPI class std::vector<class AABB, class std::allocator<class AABB>>& fetchAABBs(class AABB const&, bool);
	MCAPI class std::vector<class Actor*, class std::allocator<class Actor*>> const& fetchActors(struct ActorDefinitionIdentifier const&, class AABB const&);
	MCAPI void fetchBlockEntities(class AABB const&, class std::vector<class BlockActor*, class std::allocator<class BlockActor*>>&);
	MCAPI class std::vector<class AABB, class std::allocator<class AABB>>& fetchCollisionShapes(class AABB const&, float*, bool, class Actor*);
	MCAPI class std::vector<class Actor*, class std::allocator<class Actor*>> const& fetchEntities2(enum ActorType, class AABB const&, bool);
	MCAPI class std::vector<class Actor*, class std::allocator<class Actor*>> const& fetchEntities(class Actor*, class AABB const&);
	MCAPI class std::vector<class Actor*, class std::allocator<class Actor*>> const& fetchEntities(enum ActorType, class AABB const&, class Actor*);
	MCAPI class Actor* fetchNearestEntityOfType(class Actor*, class AABB const&, enum ActorType);
	MCAPI bool findNextSpawnBlockUnder(class BlockPos&, enum MaterialType);
	MCAPI bool findNextTopSolidBlockAbove(class BlockPos&);
	MCAPI bool findNextTopSolidBlockUnder(class BlockPos&);
	MCAPI void fireBlockChanged(class BlockPos const&, unsigned int, class Block const&, class Block const&, int, struct ActorBlockSyncMessage const*);
	MCAPI void fireBlockEntityAboutToBeRemoved(class std::shared_ptr<class BlockActor>);
	MCAPI void fireBlockEntityChanged(class BlockActor&);
	MCAPI class AABB generateUnloadedChunkAABB(class ChunkPos const&);
	MCAPI short getAboveTopSolidBlock(class BlockPos const&, bool, bool);
	MCAPI class Biome& getBiome(class BlockPos const&);
	MCAPI class Block const& getBlock(class BlockPos const&) const;
	MCAPI class Block const& getBlock(int, int, int) const;
	MCAPI class BlockActor* getBlockEntity(class BlockPos const&);
	MCAPI class BlockActor* getBlockEntity(int, int, int);
	MCAPI float getBrightness(class BlockPos const&) const;
	MCAPI struct BrightnessPair getBrightnessPair(class BlockPos const&) const;
	MCAPI class LevelChunk* getChunk(class ChunkPos const&) const;
	MCAPI class Biome const& getConstBiome(class BlockPos const&) const;
	MCAPI class Block const& getExtraBlock(class BlockPos const&) const;
	MCAPI short getHeightmap(int, int);
	MCAPI short getHeightmap(class BlockPos const&) const;
	MCAPI class Block const& getLiquidBlock(class BlockPos const&) const;
	MCAPI class Material const& getMaterial(int, int, int) const;
	MCAPI bool getNextTickUpdateForPos(class BlockPos const&, enum TickingQueueType, struct Tick&) const;
	MCAPI struct Brightness getRawBrightness(class BlockPos const&, bool, bool) const;
	MCAPI float getSeenPercent(class Vec3 const&, class AABB const&);
	MCAPI float getVisualLiquidHeight(class Vec3 const&);
	MCAPI bool hasBlock(class BlockPos const&) const;
	MCAPI bool hasBorderBlock(class BlockPos);
	MCAPI bool hasChunksAt(struct Bounds const&) const;
	MCAPI bool hasChunksAt(class AABB const&) const;
	MCAPI bool hasChunksAt(class BlockPos const&, class BlockPos const&) const;
	MCAPI bool hasChunksAt(class BlockPos const&, int) const;
	MCAPI bool hasTickInCurrentTick(class BlockPos const&, enum TickingQueueType) const;
	MCAPI bool hasTickInPendingTicks(class BlockPos const&) const;
	MCAPI bool hasTickInPendingTicks(class BlockPos const&, enum TickingQueueType) const;
	MCAPI bool isConsideredSolidBlock(class BlockPos const&);
	MCAPI bool isEmptyBlock(int, int, int);
	MCAPI bool isInWall(class Vec3 const&);
	MCAPI class Block const* isOnTopOfBlock(class AABB const&, class std::function<bool>);
	MCAPI bool isPositionUnderLiquid(class Vec3 const&, enum MaterialType);
	MCAPI bool isSolidBlockingBlock(int, int, int) const;
	MCAPI bool isTouchingMaterial(class BlockPos const&, enum MaterialType) const;
	MCAPI bool isUnderWater(class Vec3 const&, class Block const&) const;
	MCAPI bool isUnobstructedByEntities(class AABB const&, class Actor*);
	MCAPI bool mayPlace(class Block const&, class BlockPos const&, unsigned char, class Actor*, bool);
	MCAPI void neighborChanged(class BlockPos const&, class BlockPos const&);
	MCAPI bool removeBlock(class BlockPos const&);
	MCAPI bool setBlock(class BlockPos const&, class Block const&, int, struct ActorBlockSyncMessage const*);
	MCAPI bool setBlock(class BlockPos const&, class Block const&, int, class std::shared_ptr<class BlockActor>, struct ActorBlockSyncMessage const*);
	MCAPI bool setBlock(int, int, int, class Block const&, int);
	MCAPI bool setBlockNoUpdate(int, int, int, class Block const&);
	MCAPI bool setExtraBlock(class BlockPos const&, class Block const&, int);
	MCAPI class Biome* tryGetBiome(class BlockPos const&) const;
	MCAPI void updateNeighborsAt(class BlockPos const&);
	MCAPI void updateNeighborsAtExceptFromFacing(class BlockPos const&, class BlockPos const&, int);
	MCINLINE bool _getBlockPermissions(class BlockPos const& a0, bool a1) { return Call("?_getBlockPermissions@BlockSource@@AEAA_NAEBVBlockPos@@_N@Z", bool, BlockSource const*, class BlockPos const&, bool)(this, a0, a1); }
	MCINLINE float _getLiquidHeight(class BlockPos const& a0, enum MaterialType a1, bool a2) { return Call("?_getLiquidHeight@BlockSource@@AEAAMAEBVBlockPos@@W4MaterialType@@_N@Z", float, BlockSource const*, class BlockPos const&, enum MaterialType, bool)(this, a0, a1, a2); }
	MCINLINE class BlockTickingQueue* _getTickingQueue(class BlockPos const& a0, enum TickingQueueType a1) const { return Call("?_getTickingQueue@BlockSource@@AEBAPEAVBlockTickingQueue@@AEBVBlockPos@@W4TickingQueueType@@@Z", class BlockTickingQueue*, BlockSource const*, class BlockPos const&, enum TickingQueueType)(this, a0, a1); }
	MCINLINE void _removeFromTickingQueue(class BlockPos const& a0, class Block const& a1, enum TickingQueueType a2) { Call("?_removeFromTickingQueue@BlockSource@@AEAAXAEBVBlockPos@@AEBVBlock@@W4TickingQueueType@@@Z", void, BlockSource const*, class BlockPos const&, class Block const&, enum TickingQueueType)(this, a0, a1, a2); }
	MCINLINE ~BlockSource() {
		Call("??1BlockSource@@UEAA@XZ",void, void*)(this);
	}
#if 0
/* std || und args */
	/* bad retval */
#endif
};
