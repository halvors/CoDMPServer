void Sys_UnlockRead(FastCriticalSection *critSect) {
	if (critSect->readCount < 1) {
		return;
	}

	__asm { LOCK };
	critSect->readCount--;
}
