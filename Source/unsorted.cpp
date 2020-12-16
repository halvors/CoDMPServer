void R_CopyDebugStrings(trDebugString_t *param_1, int param_2, trDebugString_t *param_3, int param_4, int param_5) {
	DebugGlobals *dg;
	unsigned int copysize;
	trDebugString_t *dest;

	GfxBackEndData *pGVar1 = frontEndDataOut;
	(frontEndDataOut->debugGlobals).externStringCount = 0;

	if ((((param_1 == NULL) && (param_3 == NULL)) || ((pGVar1->debugGlobals).externStrings != NULL)) || (R_DebugAlloc(&(pGVar1->debugGlobals).externStrings, param_5 << 7, "R_CopyDebugStrings"), (pGVar1->debugGlobals).externStrings != NULL)) {
		dest = (pGVar1->debugGlobals).externStrings;

		if (param_1 != NULL) {
			_memcpy(dest, param_1, param_2 << 7);
			dest = dest + param_2;
		}

		if (param_3 != NULL) {
			_memcpy(dest, param_3, param_4 << 7);
		}

		(pGVar1->debugGlobals).externStringCount = param_2 + param_4;
	}
}

void Com_PrintStackTrace() {
	Assert_DoStackTrace(&stack, 1, 2, NULL);
	Com_Printf("STACKBEGIN -------------------------------------------------------------------\n");
	Com_Printf(&stack);
	Com_Printf("STACKEND ---------------------------------------------------------------------\n");
}

void Load_PackIndex(bool param_1) {
	FxEffectDef *pFVar1;
	Load_Stream(param_1, varPackIndex, 0x1C);
	DB_PushStreamPos(4);
	varXString = (char **)varPackIndex;
	Load_XString(false);

	if (!IsBadReadPtr(varPackIndex->entries)) {
		pFVar1 = AllocLoad_FxEffectDef();
		*(FxEffectDef **)&varPackIndex->entries = pFVar1;
		varPackIndexEntry = varPackIndex->entries;
		Load_PackIndexEntryArray(true, (varPackIndex->header).count);
	}

	DB_PopStreamPos();
}

void R_DestroyParticleCloudBuffer() {
	if (!IsBadReadPtr(gfxBuf.particleCloudVertexBuffer)) {
		R_FreeStaticVertexBuffer(gfxBuf.particleCloudVertexBuffer);
		gfxBuf.particleCloudVertexBuffer = NULL;
	}

	if (!IsBadReadPtr(gfxBuf.particleCloudIndexBuffer)) {
		R_FreeStaticIndexBuffer(gfxBuf.particleCloudIndexBuffer);
		gfxBuf.particleCloudIndexBuffer = NULL;
	}
}

void SV_FreeClientMemory(HunkUser *param_1, int param_2, int param_3) {
	if (!IsBadReadPtr(sv_ikBuf)) {
		Hunk_UserFree(param_1, sv_ikBuf);
		IK_AllocateLocalClientMemory(NULL, -1);
	}

	sv_ikBuf = NULL;

	if (!IsBadReadPtr(svs.clients)) {
		Hunk_UserFree(param_1, svs.clients);
	}

	svs.clients = NULL;

	if (!IsBadReadPtr(svs.snapshotMatchStates)) {
		Hunk_UserFree(param_1, svs.snapshotMatchStates);
	}

	svs.snapshotMatchStates = NULL;

	if (!IsBadReadPtr(svs.snapshotEntities)) {
		Hunk_UserFree(param_1, svs.snapshotEntities);
	}

	svs.snapshotEntities = NULL;

	if (!IsBadReadPtr(svs.snapshotClients)) {
		Hunk_UserFree(param_1, svs.snapshotClients);
	}

	svs.snapshotClients = NULL;

	if (!IsBadReadPtr(svs.cachedSnapshotFrames)) {
		Hunk_UserFree(param_1, svs.cachedSnapshotFrames);
	}

	svs.cachedSnapshotFrames = NULL;

	if (!IsBadReadPtr(svs.cachedSnapshotMatchStates)) {
		Hunk_UserFree(param_1, svs.cachedSnapshotMatchStates);
	}

	svs.cachedSnapshotMatchStates = NULL;

	if (!IsBadReadPtr(svs.cachedSnapshotEntities)) {
		Hunk_UserFree(param_1, svs.cachedSnapshotEntities);
	}

	svs.cachedSnapshotEntities = NULL;

	if (!IsBadReadPtr(svs.cachedSnapshotClients)) {
		Hunk_UserFree(param_1, svs.cachedSnapshotClients);
	}

	svs.cachedSnapshotClients = NULL;

	if (!IsBadReadPtr(svs.archivedSnapshotFrames)) {
		Hunk_UserFree(param_1, svs.archivedSnapshotFrames);
	}

	svs.archivedSnapshotFrames = NULL;

	if (!IsBadReadPtr(svs.archivedSnapshotBuffer)) {
		Hunk_UserFree(param_1, svs.archivedSnapshotBuffer);
	}

	svs.archivedSnapshotBuffer = NULL;
}

int __cdecl DynEnt_GetSurfaceType(DynEntityDef *param_1) {
	int surfaceFlags = 0;
	int surfaceType;

	if (param_1->xModel == NULL) {
		if (param_1->brushModel < cm.numSubModels) {
			surfaceFlags = CM_ModelSurfaceFlags((uint)param_1->brushModel);
		}
	} else {
		if (param_1->xModel->collSurfs != NULL) {
			surfaceFlags = param_1->xModel->collSurfs->surfFlags;
		}
	}

	return (int)(surfaceFlags & 0x3F00000) >> 0x14; // int(0x14) = 20
}
