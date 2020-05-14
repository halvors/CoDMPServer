void __cdecl MemFile_WriteCString(MemoryFile *param_1,char *param_2)

{
    char cVar1;
    code *pcVar2;
    uint uVar3;
    char *local_c;
    int len;

    if (param_2 == NULL) {
        uVar3 = _Assert_MyHandler("c:\\projects_pc\\cod\\codsrc\\src\\effectscore\\../universal/memfile.h",0x90,0,"%s","string");
        if ((uVar3 & 0xff) == 0) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
        }
    }
    local_c = param_2;
    do {
        cVar1 = *local_c;
        local_c = local_c + 1;
    } while (cVar1 != '\0');
    MemFile_WriteData(param_1,(int)(local_c + (1 - (int)(param_2 + 1))),param_2);
    return;
}
