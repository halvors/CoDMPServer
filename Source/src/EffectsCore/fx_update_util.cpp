void __cdecl FX_OrientationPosFromWorldPos(orientation_t *param_1, float *pos, float *out) {
	float dir[3];
	if (pos == out) {
		return;
	}
	dir[0] = *pos - param_1->origin[0];
	dir[1] = pos[1] - param_1->origin[1];
	dir[2] = pos[2] - param_1->origin[2];
	*out = dir[0] * param_1->axis[0] + dir[1] * param_1->axis[1] + dir[2] * param_1->axis[2];
	out[1] = dir[0] * param_1->axis[3] + dir[1] * param_1->axis[4] + dir[2] * param_1->axis[5];
	out[2] = dir[0] * param_1->axis[6] + dir[1] * param_1->axis[7] + dir[2] * param_1->axis[8];
}
