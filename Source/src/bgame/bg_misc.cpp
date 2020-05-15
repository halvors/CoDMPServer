bool BG_ClipMoveToDobj(entityState_s *es) {
	if (!es) {
		return false;
	}
	if ((es->eType == 14) || (es->eType == 16)) {
		return true;
	} else if (((es->solid == 0xFFFFFF) || (es->eType == 17)) || (es->eType == 1)) {
		return false;
	} else {
		return true;
	}
	return false;
}
