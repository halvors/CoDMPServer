void MSG_WriteBits(msg_t *msg, int bitCount, int bits) {
	unsigned int uVar2;
	int bit;

	if ((unsigned int)bits > 32) {
		return;
	}

	if (msg->readOnly) {
		return;
	}

	if (msg->maxsize - msg->cursize < 4) {
		msg->overflowed = true;
		return;
	} else {
		while (bits != 0) {
			bits--;
			uVar2 = msg->bit & 7;

			if (uVar2 == 0) {
				msg->bit = msg->cursize << 3;
				msg->data[msg->cursize] = '\0';
				msg->cursize++;
			}

			if ((bitCount & 1U) != 0) {
				msg->data[msg->bit >> 3] = msg->data[msg->bit >> 3] | (byte)(1 << (sbyte)uVar2);
			}

			msg->bit++;
			bitCount >>= 1;
		}
	}
}

void MSG_WriteBit1(msg_t *msg) {
	int bit;

	if (msg->readOnly) {
		return;
	}

	unsigned int uVar2 = msg->bit & 7;

	if (uVar2 == 0) {
		if (msg->maxsize <= msg->cursize) {
			msg->overflowed = 1;
			return;
		}

		msg->bit = msg->cursize << 3;
		msg->data[msg->cursize] = '\0';
		msg->cursize++;
	}

	msg->data[msg->bit >> 3] = msg->data[msg->bit >> 3] | (byte)(1 << (sbyte)uVar2);
	msg->bit++;
}

void MSG_WriteByte(msg_t *msg, unsigned char byte) {
	if (msg->readOnly) {
		return;
	}

	if (msg->cursize < msg->maxsize) {
		msg->data[msg->cursize] = byte;
		msg->cursize++;
	} else {
		msg->overflowed = 1;
		return;
	}
}

void MSG_WriteLong(msg_t *msg, int len) {
	if (msg->readOnly) {
		return;
	}

	int newsize = msg->cursize + 4;

	if (msg->maxsize < newsize) {
		msg->overflowed = 1;
	} else {
		*(int *)(msg->data + msg->cursize) = len;
		msg->cursize = msglenAligned;
	}
}

int MSG_ReadBits(msg_t *msg, int bits) {
	if (bits <= 32) {
		return -1;
	}

	int byte;
	int msgByte;
	int value = 0;
	int i = 0;

	while (true) {
		if (bits <= i) {
			return value;
		}

		byte = msg->bit & 7; // 1 byte = 7 bits

		if (byte == 0) {
			if (msg->cursize + msg->splitSize <= msg->readcount) {
				msg->overflowed = 1;
				return -1;
			}

			msg->bit = msg->readcount << 3;
			msg->readcount++;
		}

		msgByte = MSG_GetByte(msg, msg->bit >> 3);
		value = (msgByte >> (sbyte)byte & 1) << ((byte)i & 32) | value;

		msg->bit++;
		i++;
	}
}
