int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow) {
	// wait a minute, why are both of these said to be in EAX? god damnit ida.
	int result;	// eax
	int v5;		// eax
	jpeg_decompress_struct *SCRIPT_DEBUGGER_SMOKE_TEST_SUCCESS_EXIT_CODE; // [esp+0h] [ebp-4h]

	if (!StartingDedicatedServer(lpCmdLine) && CheckRemoteSession()) {
		return 0;
	}

	g_allowMature = 1;

	if (I_stristr(lpCmdLine, "minidump")) {
		Sys_StartMiniDump(1);
	} else if (I_stristr(lpCmdLine, "nodump")) {
		SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)PrivateUnhandledExceptionFilter);
	} else {
		Sys_StartMiniDump(1);
	}

	Sys_InitializeCriticalSections();
	Sys_InitMainThread();
	PMem_Init();
	track_init();
	Win_InitLocalization();

	if (!I_strnicmp(lpCmdLine, "allowdupe", 9) && lpCmdLine[9] <= 32 || (strstr(lpCmdLine, "g_connectpaths 3"), v5) || (Sys_GetSemaphoreFileName(), Sys_CheckCrashOrRerun())) {
		s_nosnd = I_stristr(lpCmdLine, "nosnd") != 0;

		if (!hPrevInstance) {
			Com_InitParse();
			Dvar_Init();
			InitTiming();
			Sys_FindInfo();
			g_wv.hInstance = hInstance;
			I_strncpyz(sys_cmdline, lpCmdLine, 1024);

			if (g_open_automate_benchmark[0]) {
				I_strncat(sys_cmdline, 1024, " +set r_open_automate 1 +set com_introPlayed 1 +set ui_autoContinue 1 +devmap ");
				I_strncat(sys_cmdline, 1024, g_open_automate_benchmark);
			}

			Win_RegisterClass();
			SetErrorMode(1u);
			Sys_Milliseconds();
			BG_EvalVehicleName(SCRIPT_DEBUGGER_SMOKE_TEST_SUCCESS_EXIT_CODE);
			tlPrintf("Hello from the wonderful world of TL\n");
			Sys_SetupTLCallbacks((int)&off_900000);

			ASSERT(Sys_IsMainThread());

			Com_Init(sys_cmdline, 0);
			PrintWorkingDir();
			SetFocus(g_wv.hWnd);

			if (com_script_debugger_smoke_test->current.enabled) {
				exit(31415);
			}

			while (1) {
				do {
					Sleep(5u);
					Com_Frame();
				} while (!Dvar_GetBool("onlinegame"));

				PbServerProcessEvents();
			}
		}

		Win_ShutdownLocalization();
		track_shutdown(0);
		result = 0;
	} else {
		Win_ShutdownLocalization();
		track_shutdown(0);
		result = 0;
	}

	return result;
}
