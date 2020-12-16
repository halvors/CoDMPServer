void bdCore::init(bool allocFunc) {
	if (!m_initialized) {
		if (allocFunc) { /// ???
			bdMemory::setAllocateFunc(bdMallocMemory::allocate);
			bdMemory::setAlignedAllocateFunc(bdMallocMemory::alignedAllocate);
			bdMemory::setDeallocateFunc(bdMallocMemory::alignedDeallocate);
			bdMemory::setAlignedDeallocateFunc(bdMallocMemory::alignedDeallocate);
			bdMemory::setReallocateFunc(bdMallocMemory::reallocate);
			bdMemory::setAlignedReallocateFunc(bdMallocMemory::alignedReallocate);
		}

		// Make sure init() is only called once
		m_initialized = true;
	} else {
		bdLogMessage(BD_LOG_WARNING, "warn/", "core", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdCore\\bdCore.cpp", "bdCore::init", 0x37, "init() has been called twice without an intermediate quit()");
	}
}
