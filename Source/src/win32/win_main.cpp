
// WARNING: Removing unreachable block (ram,0x007db6ce)
// WARNING: Removing unreachable block (ram,0x007db736)
// WARNING: Variable defined which should be unmapped: SCRIPT_DEBUGGER_SMOKE_TEST_SUCCESS_EXIT_CODE
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int WinMain(bool param_1, HINSTANCE__ *param_1_00, int param_2, char *param_3) {
    code *pcVar1;
    bool bVar2;
    int iVar3;
    uint uVar4;
    char *pcVar5;
    undefined4 uVar6;
    gentity_s *unaff_EBP;
    weaponParms *unaff_retaddr;
    int SCRIPT_DEBUGGER_SMOKE_TEST_SUCCESS_EXIT_CODE;
    iVar3 = StartingDedicatedServer(param_3);
    if ((iVar3 != 0) || (uVar4 = CheckRemoteSession(), (uVar4 & 0xff) == 0)) {
        g_allowMature = true;
        pcVar5 = I_stristr(param_3, "minidump");
        if (pcVar5 == NULL) {
            pcVar5 = I_stristr(param_3, "nodump");
            if (pcVar5 == NULL) {
                Sys_StartMiniDump(true);
            } else {
                SetUnhandledExceptionFilter(PrivateUnhandledExceptionFilter);
            }
        } else {
            Sys_StartMiniDump(true);
        }
        Sys_InitializeCriticalSections();
        Sys_InitMainThread();
        PMem_Init();
        track_init();
        Win_InitLocalization();
        iVar3 = I_strnicmp(param_3,"allowdupe",9);
        if (((iVar3 != 0) || (' ' < param_3[9])) && (pcVar5 = _strstr(param_3,"g_connectpaths 3"), pcVar5 == NULL)) {
            Sys_GetSemaphoreFileName();
            iVar3 = Sys_CheckCrashOrRerun();
            if (iVar3 == 0) {
                Win_ShutdownLocalization();
                track_shutdown(0);
                return 0;
            }
        }
        pcVar5 = I_stristr(param_3,"nosnd");
        _DAT_09b6fed8 = (uint)(pcVar5 != NULL);
        if (param_2 == 0) {
            Com_InitParse();
            Dvar_Init();
            InitTiming();
            Sys_FindInfo();
            g_wv.hInstance = param_1_00;
            I_strncpyz(&DAT_09b65a50,param_3,0x400);
            if (DAT_09b65e50 != '\0') {
                I_strncat(&DAT_09b65a50,0x400," +set r_open_automate 1 +set com_introPlayed 1 +set ui_autoContinue 1 +devmap ");
                I_strncat(&DAT_09b65a50,0x400,&DAT_09b65e50);
            }
            Win_RegisterClass();
            SetErrorMode(1);
            Sys_Milliseconds();
            Weapon_Flamethrower_UpdateSound(param_1,unaff_EBP,unaff_retaddr);
            tlPrintf("Hello from the wonderful world of TL\n");
            Sys_SetupTLCallbacks(0x900000);
            bVar2 = Sys_IsMainThread();
            if (bVar2 == false)) {
				return 0;
            }
            Com_Init(&DAT_09b65a50,false);
            PrintWorkingDir();
            SetFocus((HWND)g_wv.hWnd);
            if (com_script_debugger_smoke_test->current[0] != 0) {
                _exit(0x7ab7);
            }
            do {
                do {
                    Sleep(5);
                    Com_Frame();
                    bVar2 = Dvar_GetBool("onlinegame");
                } while (bVar2 == false);
                PbServerProcessEvents();
            } while (true);
        }
        Win_ShutdownLocalization();
        track_shutdown(0);
    }
    return 0;
}