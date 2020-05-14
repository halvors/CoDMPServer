unsigned int __cdecl GetVariableName(scriptInstance_t param_1, unsigned int param_2) {
	scrVarGlob_t *psVar1;
	code *pcVar2;
	unsigned int uVar3;
	psVar1 = (&gScrVarGlob)[param_1 * 0x20];
	if (((unsigned int)(&psVar1->variableList + (param_2 + 0x8000) * 7)[4] & 0x60) == 0) {
		uVar3 = _Assert_MyHandler("c:\\projects_pc\\cod\\codsrc\\src\\clientscript\\scr_variable.h", 0x143, 0, "%s", "(entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE");
		if ((uVar3 & 0xff) == 0) {
			pcVar2 = (code *)swi(3);
			uVar3 = (*pcVar2)();
			return uVar3;
		}
	}
	if (0xc < ((unsigned int)(&psVar1->variableList + (param_2 + 0x8000) * 7)[4] & 0x1f)) {
		uVar3 = _Assert_MyHandler("c:\\projects_pc\\cod\\codsrc\\src\\clientscript\\scr_variable.h", 0x2ad, 0, "%s", "!IsObject(&gScrVarGlob[inst].variableList[VARIABLELIST_CHILD_BEGIN(inst) + id])");
		if ((uVar3 & 0xff) == 0) {
			pcVar2 = (code *)swi(3);
			uVar3 = (*pcVar2)();
			return uVar3;
		}
	}
	return *(unsigned int *)(&(&gScrVarGlob)[param_1 * 0x20]->field_0x10 + (param_2 + 0x8000) * 0x1c) >> 8;
}
