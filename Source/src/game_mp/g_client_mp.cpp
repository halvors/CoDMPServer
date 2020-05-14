
// WARNING: Could not reconcile some variable overlaps
// void __cdecl ClientUserinfoChanged(int)

void __cdecl ClientUserinfoChanged(int param_1)

{
    code *pcVar1;
    uint uVar2;
    int iVar3;
    char *_Str;
    __uint64 *p_Var4;
    uint local_824;
    int local_820;
    gclient_s *client;
    char oldname [1024];
    char userinfo [1024];
    clientInfo_t *ci;
    gentity_s *ent;
    char *s;

    client = (gclient_s *)(&DAT_03cf2a84)[param_1 * 0xbe];
    if (0x1f < (uint)param_1) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\game_mp\\g_client_mp.cpp",0x13d,0,"clientNum doesn\'t index MAX_CLIENTS\n\t%i not in [0, %i)",param_1,0x20);
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    SV_GetUserinfo(param_1,userinfo,0x400);
    iVar3 = Info_Validate(userinfo);
    if (iVar3 == 0) {
        userinfo._0_4_ = 0x6d616e5c;
        userinfo._4_4_ = 0x61625c65;
        userinfo._8_4_ = 0x666e6964;
        userinfo._12_2_ = 0x6f;
    }
    iVar3 = SV_IsLocalClient(param_1);
    (client->sess).localClient = iVar3;
    _Str = Info_ValueForKey(userinfo,"cg_predictItems");
    iVar3 = _atoi(_Str);
    if (iVar3 == 0) {
        (client->sess).predictItemPickup = 0;
    }
    else {
        (client->sess).predictItemPickup = 1;
    }
    if (((client->sess).connected == CON_CONNECTED) && (level.manualNameChange != 0)) {
        _Str = Info_ValueForKey(userinfo,"name");
        ClientCleanName(_Str,(client->sess).newnetname,0x20);
    }
    else {
    // PDB: Start of Block
        I_strncpyz(oldname,(client->sess).cs.name,0x400);
        _Str = Info_ValueForKey(userinfo,"name");
        ClientCleanName(_Str,(client->sess).cs.name,0x20);
        I_strncpyz((client->sess).newnetname,(client->sess).cs.name,0x20);
        _Str = Info_ValueForKey(userinfo,"clanAbbrev");
        if (*_Str == '\0') {
            (client->sess).cs.clanAbbrev[0] = '\0';
        }
        else {
            I_strncpyz((client->sess).cs.clanAbbrev,_Str,8);
        }
        p_Var4 = (__uint64 *)&local_824;
        _Str = Info_ValueForKey(userinfo,"bdOnlineUserID");
        StringToXUID(_Str,p_Var4);
        if (((local_824 & 0xffffff00) == 0xffffff00) && (local_820 == -1)) {
            local_824 = param_1 & 0xffU | 0xffffff00;
            local_820 = -1;
        }
        *(uint *)&(client->sess).cs.field_0x78 = local_824;
        *(int *)((int)&(client->sess).cs.field_0x78 + 4) = local_820;
    }
    if (0x1f < (uint)param_1) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\game_mp\\g_client_mp.cpp",0x176,0,"clientNum doesn\'t index MAX_CLIENTS\n\t%i not in [0, %i)",param_1,0x20);
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    iVar3 = param_1 * 0x5c8;
    if (((clientInfo_t *)((int)level_bgs.clientinfo + iVar3))->infoValid == 0) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\game_mp\\g_client_mp.cpp",0x178,0,"%s","ci->infoValid");
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    *(int *)((int)level_bgs.clientinfo + iVar3 + 8) = param_1;
    I_strncpyz((char *)((int)level_bgs.clientinfo + iVar3 + 0xc),(client->sess).cs.name,0x20);
    *(team_t.conflict *)((int)level_bgs.clientinfo + iVar3 + 0x2c) = (client->sess).cs.team;
    if (*(int *)(&DAT_03cf2a8c + param_1 * 0x2f8) == 0) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\game_mp\\g_client_mp.cpp",0x181,0,"%s","ent->sentient");
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    *(team_t.conflict *)(*(int *)(&DAT_03cf2a8c + param_1 * 0x2f8) + 4) = (client->sess).cs.team;
    @__security_check_cookie@4();
    return;
}
