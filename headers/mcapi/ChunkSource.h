#pragma once
#include "Core.h"
class ChunkSource {
public:
	MCINLINE void clearDeletedEntities() { Call("?clearDeletedEntities@ChunkSource@@UEAAXXZ", void, ChunkSource const*)(this); }
	MCINLINE void compact() { Call("?compact@ChunkSource@@UEAAXXZ", void, ChunkSource const*)(this); }
	MCINLINE void flushPendingWrites() { Call("?flushPendingWrites@ChunkSource@@UEAAXXZ", void, ChunkSource const*)(this); }
};