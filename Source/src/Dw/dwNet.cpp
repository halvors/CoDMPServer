
// void __cdecl dwNetStart(bool)

void __cdecl dwNetStart(bool param_1)

{
    code *pcVar1;
    bool bVar2;
    int iVar3;
    uint uVar4;
    bdInetAddr *extraout_EAX;
    bdString local_70;
    bdString local_6c;
    bdString local_68;
    bdString local_64;
    bdInetAddr local_60;
    bool local_5c [8];
    bdArray<class_bdString> local_54 [16];
    bdArray<class_bdInetAddr> local_44 [16];
    float local_34;
    undefined4 local_10;
    bdNetImpl *local_c;
    bool restart;

    restart = true;
    if (g_dwNetOnlineFailed != false) {
        param_1 = false;
    }
    switch(g_dwNetStatus) {
    case DW_NET_ERROR_START_FAILED:
    case DW_NET_ERROR_NO_LOCAL_IP:
    case DW_NET_NOT_STARTED:
    // Symbol Ref: No symbol: $LN21
        restart = true;
        break;
    case DW_NET_STARTING_LAN:
    // Symbol Ref: No symbol: $LN20
        restart = param_1 != false;
        break;
    case DW_NET_STARTED_LAN:
    // Symbol Ref: No symbol: $LN17
        restart = param_1 != false;
        break;
    case DW_NET_STARTING_ONLINE:
    // Symbol Ref: No symbol: $LN14
        restart = param_1 == false;
        break;
    case DW_NET_STARTED_ONLINE:
    // Symbol Ref: No symbol: $LN11
        restart = false;
    }
    // PDB: Start of Block
    if (restart != false) {
        iVar3 = dwGetNumAddrHandles();
        restart = (bool)('\x01' - (iVar3 != 0));
        local_10 = 1;
        local_c = bdSingleton<class_bdNetImpl>::getInstance();
        if ((local_c == NULL) && (uVar4 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\Dw\\dwNet.cpp",0x23a,0,"%s","net"), (uVar4 & 0xff) == 0)) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    // PDB: Start of Block
        if (local_c == NULL) {
            if (g_dwNetStatus != DW_NET_ERROR_NO_LOCAL_IP) {
                Com_Printf(0x10,"Could not obtain local IP address.\n");
                g_dwNetStatus = DW_NET_ERROR_NO_LOCAL_IP;
            }
        }
        else {
            dwNetStop();
            bdNetStartParams::bdNetStartParams((bdNetStartParams *)local_5c);
            iVar3 = dwPlatformInit((bdNetStartParams *)local_5c);
            if (iVar3 != 0) {
                bdInetAddr::bdInetAddr(&local_60,"127.0.0.1");
                bdArray<class_bdInetAddr>::pushBack(local_44,extraout_EAX);
                bdInetAddr::~bdInetAddr(&local_60);
            }
            bdArray<class_bdString>::clear(local_54);
            bdString::bdString(&local_64,"cod7-stun.us.demonware.net");
            bdArray<class_bdString>::pushBack(local_54,&local_64);
            bdString::~bdString(&local_64);
            bdString::bdString(&local_68,"cod7-stun.eu.demonware.net");
            bdArray<class_bdString>::pushBack(local_54,&local_68);
            bdString::~bdString(&local_68);
            bdString::bdString(&local_6c,"cod7-stun.jp.demonware.net");
            bdArray<class_bdString>::pushBack(local_54,&local_6c);
            bdString::~bdString(&local_6c);
            bdString::bdString(&local_70,"cod7-stun.au.demonware.net");
            bdArray<class_bdString>::pushBack(local_54,&local_70);
            bdString::~bdString(&local_70);
            local_5c[0] = param_1;
            local_34 = 1.00000000;
            bVar2 = bdNetImpl::start(local_c,(bdNetStartParams *)local_5c);
            if (bVar2 == false) {
                if (g_dwNetStatus != DW_NET_ERROR_START_FAILED) {
                    Com_Printf(0x10,"Failed to start network system.\n");
                    g_dwNetStatus = DW_NET_ERROR_START_FAILED;
                }
            }
            else {
                if (param_1 == false) {
                    g_dwNetStatus = DW_NET_STARTING_LAN;
                }
                else {
                    g_dwNetStatus = DW_NET_STARTING_ONLINE;
                }
            }
            bdNetStartParams::~bdNetStartParams((bdNetStartParams *)local_5c);
        }
    }
    return;
}
