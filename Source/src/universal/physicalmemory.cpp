void PMem_InitPhysicalMemory(PhysicalMemory *pmem, char *name, unsigned char *memory, unsigned int size) {
	if (pmem == NULL || memory == NULL) {
		return;
	}

	_memset(pmem, 0, 0x22C); // int(0x22C) = 556

	pmem->name = name;
	pmem->buf = memory;
	pmem->prim[1].pos = size;
	pmem->size = size;
}

void PMem_BeginAlloc(char *param_1, unsigned int param_2, EMemTrack param_3) {
	// TODO: Reverse PMem_BeginAlloc()
}

void PMem_BeginAllocInPrim(PhysicalMemoryPrim *prim, char *allocName, EMemTrack memTrack) {
	if (!prim->allocName || prim->allocListCount < MAX_PHYSICAL_ALLOCATIONS) {
		return;
	}

	prim->allocName = allocName;
	prim->memTrack = memTrack;

	unsigned int allocListCount = prim->allocListCount;

	prim->allocListCount++;
	prim->allocList[allocListCount].name = allocName;
	prim->allocList[allocListCount].pos = prim->pos;
}

void PMem_EndAlloc(char *allocName, uint allocListCount) {
	if (allocListCount > PHYS_ALLOC_COUNT) {
		return;
	}

	PMem_EndAllocInPrim(&DAT_09B163E8 + allocListCount * 0x110, allocName);
}

void PMem_EndAllocInPrim(PhysicalMemoryPrim *prim, char *name) {
	if (I_stricmp(prim->allocName, name) == 0) {
		return;
	}

	prim->allocName = NULL;
}

void PMem_FreeIndex(int *param_1, int param_2, int param_3) {
	// TODO: Reverse PMem_FreeIndex()
}
