void dwLobbyPump(int localControllerIndex) {
	bdLobbyService *this;
	bdContentStreamingBase *this_00;
	Status lobbyStatus;
	bdLobbyService *lobby;

	// isMainThread = Sys_IsMainThread();

	if (!Sys_IsMainThread()) {
		return;
	}

	if (localControllerIndex != 0) {
		return;
	}

	this = dwGetLobby(localControllerIndex);

	if (this != NULL) {
		dwEnterDeferredCritsec();
		bdLobbyService::pump(this);
		dwLeaveDeferredCritsec();
		dwUpdateMessaging(localControllerIndex);

		this_00 = (bdContentStreamingBase *)bdLobbyService::getContentStreaming(this);

		if (this_00 != NULL) {
			bdContentStreamingBase::pump(this_00);
		}

		this_00 = (bdContentStreamingBase *)bdLobbyService::getPooledStorage(this);

		if (this_00 != NULL) {
			bdContentStreamingBase::pump(this_00);
			bdContentStreamingBase::enableProgressMeter(this_00, true);
		}

		lobbyStatus = bdLobbyService::getStatus(this);

		if (lobbyStatus == BD_CONNECTED) {
			*(undefined4 *)(&DAT_033267D4 + localControllerIndex * 0x54) = 0x13;

			if (Dvar_GetBool("dw_connectafterlogin")) {
				Dvar_SetBoolByName("dw_connectafterlogin", false);
				CL_ConnectHackDW();
			}
		}

		if (lobbyStatus != BD_CONNECTED) {
			*(undefined4 *)(&DAT_033267D4 + localControllerIndex * 0x54) = 1;
		}
	}
}
