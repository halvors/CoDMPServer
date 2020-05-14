void SV_FreeClientScriptId(client_t *cl)
{
	if (*(unsigned int *)com_maxclients->current <= (unsigned int)((int)((int)cl - (int)svs.clients) / 0x84D00))
	{
		return;
	}
	Com_Printf(0xf,"SV_FreeClientScriptId: %d, %d -> 0\n", (int)((int)cl - (int)svs.clients) / 0x84D00, cl->scriptId);
	if (!cl->scriptId)
	{
		return;
	}
	Scr_FreeValue(SCRIPTINSTANCE_SERVER, cl->scriptId);
	cl->scriptId = 0;
}
