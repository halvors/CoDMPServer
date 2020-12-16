bool __cdecl Monkey_InitCommunication(char *param_1) {
	undefined extraout_AL;
	u_short uVar4;
	int iVar5;
	ulong uVar6;
	WSADATA local_1ac;
	int local_1c;
	uint local_18;
	ulong local_14;
	undefined4 local_10;
	undefined4 local_c;
	// uint local_8;

	// local_8 = __security_cookie ^ (uint)&stack0xfffffffc;

	if (g_MonkeyConnected != false) {
		return false;
	}

	if ((param_1 == NULL) || (*param_1 == '\0')) {
		return false;
	}
	iVar5 = WSAStartup(0x202, (LPWSADATA)&local_1ac);
	if (iVar5 == 0) {
		uVar6 = inet_addr(param_1);
		g_MonkeySock = socket(2, 1, 6);

		if (g_MonkeySock == 0xFFFFFFFF) {
			Com_Error(ERR_FATAL, "Error creating socket for monkey");
		} else {
			local_14 = 0;
			local_10 = 0;
			local_c = 0;
			local_18 = 2;
			uVar4 = htons(7000);
			local_18 = local_18 & 0xFFFF | (uint)uVar4 << 0x10;
			local_14 = uVar6;
			local_1c = connect(g_MonkeySock, (sockaddr *)&local_18, 0x10);

			if (local_1c == 0) {
				g_MonkeyConnected = true;
			} else {
				WSAGetLastError();
				Com_Error(ERR_FATAL, "Monkey could not open a connection to zookeeper \'%s\': WSAGetLastError returned %d");
			}
		}
	} else {
		Com_Error(ERR_FATAL, "Error at WSAStartup() for monkey");
	}

	// @__security_check_cookie@4(local_8 ^ (uint)&stack0xfffffffc);
	// return (bool)extraout_AL;
}

bool __cdecl Monkey_IsRunning(void) {
	return g_MonkeyIsRunning;
}

bool __cdecl Monkey_Recv(char *param_1, int param_2, char *param_3, int param_4) {
	bool bVar1 = Monkey_RecvString(param_1, param_2);

	if ((bVar1 != false) && (bVar1 = Monkey_RecvString(param_3, param_4), bVar1 != false)) {
		return true;
	}

	return false;
}
