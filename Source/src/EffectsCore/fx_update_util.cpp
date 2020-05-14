void __cdecl FX_OrientationPosFromWorldPos(orientation_t *param_1, float *param_2, float *param_3) {
	code *pcVar1;
	unsigned int uVar2;
	float fVar3;
	float fVar4;
	float fVar5;
	float dir[3];
	if (param_2 == param_3) {
		uVar2 = _Assert_MyHandler("C:\\projects_pc\\cod\\codsrc\\src\\EffectsCore\\fx_update_util.cpp", 0x16b, 0, "%s", "pos != out");
		if ((uVar2 & 0xff) == 0) {
			pcVar1 = (code *)swi(3);
			(*pcVar1)();
			return;
		}
	}
	fVar3 = *param_2 - param_1->origin[0];
	fVar4 = param_2[1] - param_1->origin[1];
	fVar5 = param_2[2] - param_1->origin[2];
	*param_3 = fVar3 * param_1->axis[0] + fVar4 * param_1->axis[1] + fVar5 * param_1->axis[2];
	param_3[1] = fVar3 * param_1->axis[3] + fVar4 * param_1->axis[4] + fVar5 * param_1->axis[5];
	param_3[2] = fVar3 * param_1->axis[6] + fVar4 * param_1->axis[7] + fVar5 * param_1->axis[8];
}
