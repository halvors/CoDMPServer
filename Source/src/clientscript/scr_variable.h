unsigned int __cdecl GetVariableName(scriptInstance_t inst, unsigned int param_2) {
	scrVarGlob_t *psVar1 = &gScrVarGlob[inst];

	_Assert_MyHandler((entryValue->w.status & VAR_STAT_MASK) != VAR_STAT_FREE);
	_Assert_MyHandler(!IsObject(&gScrVarGlob[inst].variableList[VARIABLELIST_CHILD_BEGIN(inst) + id]));

	return *(unsigned int *)(&(&gScrVarGlob)[inst]->field_0x10 + (param_2 + 0x8000) * 0x1c) >> 8;
}
