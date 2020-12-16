void __cdecl MatrixTransformVector44(float *vec, float *param_2, float *out) {
    if (vec == out) {
		return;
    }
	
    *out = *vec * *param_2 + vec[1] * param_2[4] + vec[2] * param_2[8] + vec[3] * param_2[12];
    out[1] = *vec * param_2[1] + vec[1] * param_2[5] + vec[2] * param_2[9] + vec[3] * param_2[13];
    out[2] = *vec * param_2[2] + vec[1] * param_2[6] + vec[2] * param_2[10] + vec[3] * param_2[14];
    out[3] = *vec * param_2[3] + vec[1] * param_2[7] + vec[2] * param_2[11] + vec[3] * param_2[15];
}
