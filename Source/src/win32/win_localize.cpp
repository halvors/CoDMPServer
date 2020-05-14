
// char const * __cdecl Win_LocalizeRef(char const *)

char * __cdecl Win_LocalizeRef(char *param_1)

{
    byte bVar1;
    code *pcVar2;
    char *pcVar3;
    uint uVar4;
    bool bVar5;
    int local_20;
    byte *local_18;
    byte *local_14;
    char *strings;
    int useRef;
    char *token;

    Com_BeginParseSession("localization");
    strings = DAT_09b64a44;
    do {
        local_18 = (byte *)Com_Parse(&strings);
        if (*local_18 == 0) {
            Com_EndParseSession();
            pcVar3 = va("unlocalized: %s",param_1);
            uVar4 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\win32\\win_localize.cpp",0x70,0,pcVar3);
            if ((uVar4 & 0xff) != 0) {
                pcVar3 = (char *)Win_CopyLocalizationString(param_1);
                return pcVar3;
            }
            pcVar2 = (code *)swi(3);
            pcVar3 = (char *)(*pcVar2)();
            return pcVar3;
        }
        local_14 = (byte *)param_1;
        do {
            bVar1 = *local_18;
            bVar5 = bVar1 < *local_14;
            if (bVar1 != *local_14) {
LAB_007d928e:
                local_20 = (1 - (uint)bVar5) - (uint)(bVar5 != false);
                goto LAB_007d9296;
            }
            if (bVar1 == 0) break;
            bVar1 = local_18[1];
            bVar5 = bVar1 < local_14[1];
            if (bVar1 != local_14[1]) goto LAB_007d928e;
            local_18 = local_18 + 2;
            local_14 = local_14 + 2;
        } while (bVar1 != 0);
        local_20 = 0;
LAB_007d9296:
        pcVar3 = Com_Parse(&strings);
        if (*pcVar3 == '\0') {
            Com_EndParseSession();
            pcVar3 = va("missing value: %s",param_1);
            uVar4 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\win32\\win_localize.cpp",0x79,0,pcVar3);
            if ((uVar4 & 0xff) != 0) {
                pcVar3 = (char *)Win_CopyLocalizationString(param_1);
                return pcVar3;
            }
            pcVar2 = (code *)swi(3);
            pcVar3 = (char *)(*pcVar2)();
            return pcVar3;
        }
        if (local_20 == 0) {
            Com_EndParseSession();
            pcVar3 = (char *)Win_CopyLocalizationString(pcVar3);
            return pcVar3;
        }
    } while( true );
}
