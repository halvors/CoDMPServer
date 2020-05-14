void __cdecl MSG_WriteEntityRemoval(SnapshotInfo_s *param_1,msg_t *param_2,uchar *param_3,int param_4,bool param_5)

{
    code *pcVar1;
    uint uVar2;

    if (param_3 == NULL) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\qcommon\\sv_msg_write.cpp",0x93f,0,"%s","from");
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (param_2->readOnly != 0) {
        uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\qcommon\\sv_msg_write.cpp",0x940,0,"%s","!msg->readOnly");
        if ((uVar2 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if ((cl_shownet != NULL) && ((1 < *(int *)cl_shownet->current || (*(int *)cl_shownet->current == -1)))) {
        Com_Printf(0xf,"W|%3i: #%-3i remove\n",param_2->cursize,*(undefined4 *)param_3);
    }
    if (param_5 != false) {
        MSG_WriteBit1(param_2);
    }
    MSG_WriteEntityIndex(param_1,param_2,*(int *)param_3,param_4);
    MSG_WriteBit1(param_2);
    return;
}
