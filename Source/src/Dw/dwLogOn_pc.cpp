
// void __cdecl dwLobbyPump(int)

void __cdecl dwLobbyPump(int localControllerIndex)

{
    code *pcVar1;
    bool isMainThread;
    uint uVar2;
    bdLobbyService *this;
    bdContentStreamingBase *this_00;
    Status lobbyStatus;
    bdLobbyService *lobby;

    isMainThread = Sys_IsMainThread();
    if (isMainThread == false) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\Dw\\dwLogOn_pc.cpp",0x5e2,0,"%s","Sys_IsMainThread()");
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (localControllerIndex != 0) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\Dw\\dwLogOn_pc.cpp",0x5e4,0,"%s","0 == localControllerIndex");
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    this = dwGetLobby(localControllerIndex);
    if (this != NULL) {
    // PDB: Start of Block
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
            bdContentStreamingBase::enableProgressMeter(this_00,true);
        }
        lobbyStatus = bdLobbyService::getStatus(this);
        if (lobbyStatus == BD_CONNECTED) {
            *(undefined4 *)(&DAT_033267d4 + localControllerIndex * 0x54) = 0x13;
            isMainThread = Dvar_GetBool("dw_connectafterlogin");
            if (isMainThread != false) {
                Dvar_SetBoolByName("dw_connectafterlogin",false);
                CL_ConnectHackDW();
            }
        }
        if (lobbyStatus != BD_CONNECTED) {
            *(undefined4 *)(&DAT_033267d4 + localControllerIndex * 0x54) = 1;
        }
    }
    return;
}
