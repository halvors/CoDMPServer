int Sys_GetThreadContext()
{
	int currentThreadId;
	currentThreadId = Sys_GetCurrentThreadId();
	// PDB: Start of Block
	for (int i = 0; i < 15; i++)
	{
		if (*(int *)(&DAT_0979C8F0 + i * 4) == currentThreadId)
		{
			return i;
		}
	}
	Com_Printf(1, "Current thread is not in thread table\n");
	return 0;
}

void Win_UnlockThreadAffinity()
{
	int iVar2;
	bool bVar4;
	if (s_cpuCount != 1)
	{
		LOCK();
		iVar2 = DAT_0979C988 - 1;
		bVar4 = DAT_0979C988 == 1;
		DAT_0979C988 = iVar2;
		if (bVar4)
		{
			if (s_cpuCount < 2)
			{
				return;
			}
			if (DAT_0979C938 != NULL)
			{
				SetThreadAffinityMask(DAT_0979C938, DAT_0979C994);
			}
			if (DAT_0979C93C != NULL)
			{
				SetThreadAffinityMask(DAT_0979C93C, DAT_0979C994);
			}
			if (DAT_0979C96C != NULL)
			{
				SetThreadAffinityMask(DAT_0979C96C, DAT_0979C994);
			}
			if (DAT_0979C940 != NULL)
			{
				SetThreadAffinityMask(DAT_0979C940, DAT_0979C994);
			}
			if (DAT_0979C944 != NULL)
			{
				SetThreadAffinityMask(DAT_0979C944, DAT_0979C994);
			}
		}
	}
}
