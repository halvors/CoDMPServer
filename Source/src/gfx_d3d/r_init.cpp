void R_InitSceneNullRenderTarget_PC(void) {
	int iVar1;
	_D3DFORMAT nullFormat;
	IDirect3DSurface9 *nullTextureSurface;
	HRESULT hr;
	_D3DFORMAT adapterFormat;
	nullTextureSurface = NULL;
	dx.supportsSceneNullRenderTarget = false;
	if ((((dx.vendorId != 0x1002) && (r_allow_null_rt->current[0] != 0)) && (iVar1 = (**(code **)((int)*dx.d3d9 + 0x28))(dx.d3d9, dx.adapterIndex, 1, 0x16, 1, 1, 0x4C4C554E, 0x4C4C554E), iVar1 == 0)) && (iVar1 = (**(code **)((int)*dx.d3d9 + 0x30))(dx.d3d9, dx.adapterIndex, 1, 0x16, 0x4C4C554E, dx.depthStencilFormat), iVar1 == 0)) {
		R_AssertDXDeviceOwnership();
		iVar1 = (**(code **)((int)*dx.device + 0x70))(dx.device, (uint)DAT_0b50e878, (uint)DAT_0b50e87a, 0x4C4C554E, dx.multiSampleType, dx.multiSampleQuality, 0, &nullTextureSurface, 0);
		if (iVar1 == 0) {
			dx.supportsSceneNullRenderTarget = true;
			R_ShareRenderTarget_ReplaceColor(3, 4, nullTextureSurface);
			(**(code **)((int)*nullTextureSurface + 8))(nullTextureSurface);
		}
	}
	return;
}

void __cdecl R_ResizeWindow(void) {
	code *pcVar1;
	IDirect3DSwapChain9 *hWnd;
	uint uVar2;
	HWND__ *hwnd;
	ulong exStyle;
	ulong style;
	GfxWindowParms wndParms;
	tagRECT rc;
	Dvar_MakeLatchedValueCurrent(r_aspectRatio);
	Dvar_MakeLatchedValueCurrent(r_mode);
	Dvar_MakeLatchedValueCurrent(r_fullscreen);
	Dvar_MakeLatchedValueCurrent(r_aaSamples);
	Dvar_MakeLatchedValueCurrent(r_vsync);
	Dvar_MakeLatchedValueCurrent(r_fullscreen);
	Dvar_MakeLatchedValueCurrent(r_displayRefresh);
	R_SetWndParms(&wndParms);
	R_StoreWindowSettings(&wndParms);
	hWnd = dx.windows[0].swapChain;
	if (dx.windows[0].swapChain == NULL) {
		return;
	}
	R_SetWndParms(&wndParms);
	dx.windows[0].height = wndParms.displayWidth;
	dx.flushGpuQuery = (IDirect3DQuery9 *)wndParms.displayHeight;
	if (wndParms.fullscreen == false) {
		exStyle = 0;
		style = 0xc80000;
	} else {
		exStyle = 8;
		style = 0x80000000;
	}
	rc.left = 0;
	rc.right = wndParms.displayWidth;
	rc.top = 0;
	rc.bottom = wndParms.displayHeight;
	AdjustWindowRectEx((LPRECT)&rc,style,0,exStyle);
	SetWindowLongA((HWND)hWnd,-0x10,style);
	SetWindowPos((HWND)hWnd,(HWND)((uint)(wndParms.fullscreen != false) - 2),wndParms.x,wndParms.y,rc.right - rc.left,rc.bottom - rc.top,0x60);
	if (wndParms.fullscreen == false) {
		Com_Printf(8,"Resizing %i x %i window at (%i, %i)\n",wndParms.displayWidth,wndParms.displayHeight,wndParms.x,wndParms.y);
	} else {
		Com_Printf(8,"Resizing %i x %i fullscreen at (%i, %i)\n",wndParms.displayWidth,wndParms.displayHeight,wndParms.x,wndParms.y);
	}
	return;
}
