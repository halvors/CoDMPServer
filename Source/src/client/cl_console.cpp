
// WARNING: Variable defined which should be unmapped: font
// void __cdecl Con_DrawMiniConsole(int,int,int,float)

void __cdecl Con_DrawMiniConsole(int param_1, int param_2, int param_3, float param_4) {
	Font_s *font;
	float msgwndScale;
	float color[4];

	Font_s *fontHandle = UI_GetFontHandle((ScreenPlacement *)(&scrPlaceView + param_1 * 0x1E), 0, 1.00000000);

	// _Assert_MyHandler((con_miniconlines->current.integer >= 0 && con_miniconlines->current.integer <= 100));

	if (DAT_00FA6F68 != *(int *)(DAT_00FA8168 + 0x18)) {
		DAT_00FA6F68 = *(int *)(DAT_00FA8168 + 0x18);
		Con_ClearMiniConsole(param_1);
	}

	color[0] = 1.00000000;
	color[1] = 1.00000000;
	color[2] = 1.00000000;
	color[3] = param_4;
	Con_DrawMessageWindow(param_1, &DAT_00FA6F58 + param_1 * 0x3EA4, param_2, param_3, 0x0C, 1, 1, fontHandle, color, 3, 0x3F800000, 0, 4);
	return;
}
