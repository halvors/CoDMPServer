void PM_DeadMove(ps_s *ps, int *param_2) {
	if (!ps) {
		return;
	}
	if (param_2->field_2c) { // TODO: reverse param_2
		float forward = Vec3Length(ps->velocity);
		forward -= 20;
		if (forward > 0) {
			Vec3Normalize(ps->velocity);
			ps->velocity[0] = forward * ps->velocity[0]; // *(float *)(ps + 0x30) = forward * *(float *)(ps + 0x30);
			ps->velocity[1] = forward * ps->velocity[1]; // *(float *)(ps + 0x34) = forward * *(float *)(ps + 0x34);
			ps->velocity[2] = forward * ps->velocity[2]; // *(float *)(ps + 0x38) = forward * *(float *)(ps + 0x38);
		} else {
			ps->velocity[0] = 0; // *(float *)(ps + 0x30) = 0;
			ps->velocity[1] = 0; // *(float *)(ps + 0x34) = 0;
			ps->velocity[2] = 0; // *(float *)(ps + 0x38) = 0;
		}
	}
}
