bool Sys_StartRemoteDebugServer()
{
	if (!g_debugServer)
	{
		return false;
	}
	g_debugServer = true;
	return true;
}
