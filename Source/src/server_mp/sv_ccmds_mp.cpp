
// WARNING: Variable defined which should be unmapped: guid

int __thiscall SV_KickClient(undefined4 param_1,client_t *param_1_00,char *param_2,int param_3,char *param_4)

{
    code *pcVar1;
    uint uVar2;
    undefined4 uVar3;
    int iVar4;
    int guid;

    if (param_1_00 == NULL) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\server_mp\\sv_ccmds_mp.cpp",0x2f6,0,"%s","cl",param_1);
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            uVar3 = (*pcVar1)();
            return uVar3;
        }
    }
    if ((param_1_00->header).netchan.remoteAddress.type == NA_LOOPBACK) {
        SV_SendServerCommand(NULL,SV_CMD_CAN_IGNORE,"%c \"EXE_CANNOTKICKHOSTPLAYER\"",0x65);
        iVar4 = 0;
    }
    else {
        if (param_2 != NULL) {
            I_strncpyz(param_2,param_1_00->name,param_3);
            I_CleanStr(param_2);
        }
        iVar4 = param_1_00->guid;
        SV_DropClient(param_1_00,param_4,true,true);
        param_1_00->lastPacketTime = svs.time;
    }
    return iVar4;
}
