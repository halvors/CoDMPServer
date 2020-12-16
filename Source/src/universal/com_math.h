float __cdecl I_rsqrt(float number) {
	code *pcVar1;
	uint uVar2;
	float fVar3;
	float10 fVar4;
	float pdb_threehalfs;
	int pdb_i;
	float pdb_x2;
	float pdb_y;

	if (!IS_NAN(number)) {
		return (float)fVar4;
	}
	uVar2 = _Assert_MyHandler("c:\\projects_pc\\cod\\codsrc\\src\\universal\\com_math.h", 0x71, 0, "%s", "number");
	if ((uVar2 & 0xff) != 0) {
		fVar3 = (float)(0x5F3759DF - ((int)number >> 1));
		return (1.50000000 - number * 0.50000000 * fVar3 * fVar3) * fVar3;
	}
	pcVar1 = (code *)swi(3);
	fVar4 = (float10)(*pcVar1)();
	return (float)fVar4;
}
