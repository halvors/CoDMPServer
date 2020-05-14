void Sys_UnlockRead(FastCriticalSection *critSect)
{
	if (param_1->readCount < 1)
	{
		return;
	}
	__asm { LOCK };
	critSect->readCount = critSect->readCount + -1;
}
