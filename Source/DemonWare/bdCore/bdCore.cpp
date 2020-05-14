void bdCore::init(bool param_1) {
	if (!m_initialized) {
		if (param_1) {
			bdMemory::setAllocateFunc(bdMallocMemory::allocate);
			bdMemory::setAlignedAllocateFunc(bdMallocMemory::alignedAllocate);
			bdMemory::setDeallocateFunc(bdMallocMemory::alignedDeallocate);
			bdMemory::setAlignedDeallocateFunc(bdMallocMemory::alignedDeallocate);
			bdMemory::setReallocateFunc(bdMallocMemory::reallocate);
			bdMemory::setAlignedReallocateFunc(bdMallocMemory::alignedReallocate);
		}
		m_initialized = true; // Make sure init() is only called once
	} else {
		bdLogMessage(BD_LOG_WARNING, "warn/", "core", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdCore\\bdCore.cpp", "bdCore::init", 0x37, "init() has been called twice without an intermediate quit()");
	}
}
