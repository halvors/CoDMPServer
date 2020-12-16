void CG_GetPoseOrigin(cpose_t *pose, float *origin) {
	if (!pose) {
		return;
	}
	
	*origin = pose->origin[0];
	origin[1] = pose->origin[1];
	origin[2] = pose->origin[2];
}
