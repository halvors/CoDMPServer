
// void __cdecl R_HW_SetBlend(struct IDirect3DDevice9 *,bool,unsigned int,unsigned int)

void __cdecl R_HW_SetBlend(IDirect3DDevice9 *param_1,bool param_2,uint param_3,uint param_4)

{
    int iVar1;
    int iVar2;
    char *pcVar3;

    if (param_2 == false) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_ALPHABLENDENABLE, 1 )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0x1b,1);
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_ALPHABLENDENABLE, 1 ) failed: %s\n",0x1c1,pcVar3);
        }
    }
    if ((param_3 & 0x700) != 0) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_BLENDOP, s_blendOpTable[(stateBits0 >> GFXS0_BLENDOP_RGB_SHIFT) & GFXS_BLENDOP_MASK] )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0xab,*(undefined4 *)(&DAT_00d92b14 + (param_4 >> 8 & 7) * 4));
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_BLENDOP, s_blendOpTable[(stateBits0 >> GFXS0_BLENDOP_RGB_SHIFT) & GFXS_BLENDOP_MASK] ) failed: %s\n",0x1c4,pcVar3);
        }
    }
    if ((param_3 & 0xf) != 0) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_SRCBLEND, s_blendTable[(stateBits0 >> GFXS0_SRCBLEND_RGB_SHIFT) & GFXS_BLEND_MASK] )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0x13,*(undefined4 *)(&DAT_00d92ae8 + (param_4 & 0xf) * 4));
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_SRCBLEND, s_blendTable[(stateBits0 >> GFXS0_SRCBLEND_RGB_SHIFT) & GFXS_BLEND_MASK] ) failed: %s\n",0x1c7,pcVar3);
        }
    }
    if ((param_3 & 0xf0) != 0) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_DESTBLEND, s_blendTable[(stateBits0 >> GFXS0_DSTBLEND_RGB_SHIFT) & GFXS_BLEND_MASK] )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0x14,*(undefined4 *)(&DAT_00d92ae8 + (param_4 >> 4 & 0xf) * 4));
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_DESTBLEND, s_blendTable[(stateBits0 >> GFXS0_DSTBLEND_RGB_SHIFT) & GFXS_BLEND_MASK] ) failed: %s\n",0x1ca,pcVar3);
        }
    }
    if ((param_3 & 0x7000000) != 0) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_BLENDOPALPHA, s_blendOpTable[(stateBits0 >> GFXS0_BLENDOP_ALPHA_SHIFT) & GFXS_BLENDOP_MASK] )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0xd1,*(undefined4 *)(&DAT_00d92b14 + (param_4 >> 0x18 & 7) * 4));
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_BLENDOPALPHA, s_blendOpTable[(stateBits0 >> GFXS0_BLENDOP_ALPHA_SHIFT) & GFXS_BLENDOP_MASK] ) failed: %s\n",0x1cd,pcVar3);
        }
    }
    if ((param_3 & 0xf0000) != 0) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_SRCBLENDALPHA, s_blendTable[(stateBits0 >> GFXS0_SRCBLEND_ALPHA_SHIFT) & GFXS_BLEND_MASK] )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0xcf,*(undefined4 *)(&DAT_00d92ae8 + (param_4 >> 0x10 & 0xf) * 4));
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_SRCBLENDALPHA, s_blendTable[(stateBits0 >> GFXS0_SRCBLEND_ALPHA_SHIFT) & GFXS_BLEND_MASK] ) failed: %s\n",0x1d0,pcVar3);
        }
    }
    if ((param_3 & 0xf00000) != 0) {
    // PDB: Start of Block
        R_AssertDXDeviceOwnership();
    // PDB: Start of Block
        if ((r_logFile != NULL) && (*(int *)r_logFile->current != 0)) {
            RB_LogPrint("device->SetRenderState( D3DRS_DESTBLENDALPHA, s_blendTable[(stateBits0 >> GFXS0_DSTBLEND_ALPHA_SHIFT) & GFXS_BLEND_MASK] )\n");
        }
        iVar1 = R_AcquireDXDeviceOwnership(NULL);
        iVar2 = (**(code **)((int)*param_1 + 0xe4))(param_1,0xd0,*(undefined4 *)(&DAT_00d92ae8 + (param_4 >> 0x14 & 0xf) * 4));
        if (iVar1 != 0) {
            R_ReleaseDXDeviceOwnership();
        }
        if (iVar2 < 0) {
            g_disableRendering += 1;
            pcVar3 = R_ErrorDescription(iVar2);
            Com_Error(ERR_FATAL,"c:\\projects_pc\\cod\\codsrc\\src\\gfx_d3d\\r_setstate_d3d.h (%i) device->SetRenderState( D3DRS_DESTBLENDALPHA, s_blendTable[(stateBits0 >> GFXS0_DSTBLEND_ALPHA_SHIFT) & GFXS_BLEND_MASK] ) failed: %s\n",0x1d3,pcVar3);
        }
    }
    return;
}
