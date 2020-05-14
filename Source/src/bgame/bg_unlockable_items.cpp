
// WARNING: Removing unreachable block (ram,0x0044c199)
// WARNING: Removing unreachable block (ram,0x0044c1c2)

void BG_UnlockablesEquipClassCmd(void)

{
    code *pcVar1;
    bool bVar2;
    int iVar3;
    char *pcVar4;
    char *pcVar5;
    uint uVar6;
    char *customClassName;
    int controllerIndex;
    char *itemName;
    int itemIndex;

    iVar3 = Cmd_Argc();
    if (iVar3 < 3) {
        Com_PrintError(0xf,"equipclass usage: equipclass <customclassname> <item>\n");
    }
    else {
        pcVar4 = Cmd_Argv(1);
        pcVar5 = Cmd_Argv(2);
        iVar3 = BG_UnlockablesGetItemIndexFromName(pcVar5);
        if (iVar3 == -1) {
            pcVar5 = va("Item %s not found",pcVar5);
            uVar6 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\bgame\\bg_unlockable_items.cpp",0xc46,0,"%s\n\t%s","itemIndex != ENTRY_NOT_FOUND",pcVar5);
            if ((uVar6 & 0xff) == 0) {
                pcVar1 = (code *)swi(3);
                (*pcVar1)();
                return;
            }
        }
        if ((iVar3 != -1) && (bVar2 = BG_UnlockablesIsItemPurchased(0,iVar3), bVar2 != false)) {
            BG_UnlockablesEquipClass(0,pcVar4,iVar3);
        }
    }
    return;
}
