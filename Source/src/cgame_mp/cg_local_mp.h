cg_s *CG_GetLocalClientGlobals(int localClientNum) {
	if (!localClientNum) {
		return 0;
	}
	return cgArray[localClientNum];
}
