void __cdecl MatrixTransformVector44(float *vec, float *mat, float *out) {
	ASSERT(vec != out);

	*out = *vec * *mat + vec[1] * mat[4] + vec[2] * mat[8] + vec[3] * mat[12];
	out[1] = *vec * mat[1] + vec[1] * mat[5] + vec[2] * mat[9] + vec[3] * mat[13];
	out[2] = *vec * mat[2] + vec[1] * mat[6] + vec[2] * mat[10] + vec[3] * mat[14];
	out[3] = *vec * mat[3] + vec[1] * mat[7] + vec[2] * mat[11] + vec[3] * mat[15];
}
