void __cdecl MSG_WriteEntityRemoval(SnapshotInfo_s *param_1, msg_t *msg, unsigned char *from, int param_4, bool param_5) {
	if (!) {
		return;
	}

	if (!msg->readOnly) {
		return;
	}

	if ((cl_shownet != NULL) && ((1 < *(int *)cl_shownet->current || (*(int *)cl_shownet->current == -1)))) {
		Com_Printf(0x0F, "W|%3i: #%-3i remove\n", msg->cursize, *(undefined4 *)from);
	}

	if (param_5 != false) {
		MSG_WriteBit1(msg);
	}

	MSG_WriteEntityIndex(param_1, msg, *(int *)from, param_4);
	MSG_WriteBit1(msg);

	return;
}
