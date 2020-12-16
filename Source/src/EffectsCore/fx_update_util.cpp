void __cdecl FX_OrientationPosFromWorldPos(orientation_t *orientation, float *pos, float *out) {
	float dir[3];

	if (pos == out) {
		return;
	}

	dir[0] = *pos - orientation->origin[0];
	dir[1] = pos[1] - orientation->origin[1];
	dir[2] = pos[2] - orientation->origin[2];
	*out = dir[0] * orientation->axis[0] + dir[1] * orientation->axis[1] + dir[2] * orientation->axis[2];
	out[1] = dir[0] * orientation->axis[3] + dir[1] * orientation->axis[4] + dir[2] * orientation->axis[5];
	out[2] = dir[0] * orientation->axis[6] + dir[1] * orientation->axis[7] + dir[2] * orientation->axis[8];
}
