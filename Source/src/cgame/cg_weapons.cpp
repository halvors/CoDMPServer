void __cdecl CG_FreeWeapons(int param_1) {
	int iVar2;
	ViewModelInfo *viewModelInfo;
	int iVar5;
	ViewModelInfo *viewModelInfo;
	iVar5 = param_1;
	iVar2 = CG_WeaponDObjHandle(param_1);
	Com_SafeClientDObjFree(iVar2, iVar5);
	viewModelInfo = CG_GetLocalClientViewModelInfo(param_1);
	if ((viewModelInfo->tree != NULL) && (viewModelInfo->anims != viewModelInfo->tree->anims)) {
		return;
	}
	viewModelInfo->viewModelDObj = NULL;
	viewModelInfo->anims = NULL;
	if (viewModelInfo->tree != NULL) {
		if ((viewModelInfo->tree->anims != NULL) && (viewModelInfo->tree->anims->size != 0)) {
			XAnimFreeTree(viewModelInfo->tree, NULL, SCRIPTINSTANCE_SERVER);
		}
		viewModelInfo->tree = NULL;
	}
	_memset((&cg_weaponsArray)[param_1], 0, 0x12000);
}
