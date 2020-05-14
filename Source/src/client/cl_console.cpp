
// WARNING: Variable defined which should be unmapped: font
// void __cdecl Con_DrawMiniConsole(int,int,int,float)

void __cdecl Con_DrawMiniConsole(int param_1,int param_2,int param_3,float param_4)

{
    code *pcVar1;
    Font_s *pFVar2;
    uint uVar3;
    Font_s *font;
    float msgwndScale;
    float color [4];

    pFVar2 = UI_GetFontHandle((ScreenPlacement *)(&scrPlaceView + param_1 * 0x1e),0,1.00000000);
    if ((*(int *)(DAT_00fa8168 + 0x18) < 0) || (100 < *(int *)(DAT_00fa8168 + 0x18))) {
        uVar3 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\client\\cl_console.cpp",0xc12,0,"%s\n\t(con_miniconlines->current.integer) = %i","(con_miniconlines->current.integer >= 0 && con_miniconlines->current.integer <= 100)",*(undefined4 *)(DAT_00fa8168 + 0x18),pFVar2,0x3f800000);
        if ((uVar3 & 0xff) == 0) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
        }
    }
    if (DAT_00fa6f68 != *(int *)(DAT_00fa8168 + 0x18)) {
        DAT_00fa6f68 = *(int *)(DAT_00fa8168 + 0x18);
        Con_ClearMiniConsole(param_1);
    }
    color[0] = 1.00000000;
    color[1] = 1.00000000;
    color[2] = 1.00000000;
    color[3] = param_4;
    Con_DrawMessageWindow(param_1,&DAT_00fa6f58 + param_1 * 0x3ea4,param_2,param_3,0xc,1,1,pFVar2,color,3,0x3f800000,0,4);
    return;
}
