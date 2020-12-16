#include "msg_mp.h"

void MSG_BeginReading(msg_t *msg) {
	msg->overflowed = 0;
	msg->readcount = 0;
	msg->bit = 0;
}

void MSG_CheckForDuplicateOffsets() {
	unsigned int j; // [esp+0h] [ebp-8h]
	unsigned int i; // [esp+4h] [ebp-4h]

	for (i = 0; i < 22; ++i) {
		MSG_LoopThroughFields(&s_entityNetFieldList[i]);
	}

	for (j = 0; j < 6; ++j) {
		MSG_LoopThroughFields(&s_otherNetFieldList[j]);
	}
}

void MSG_ClearLastReferencedEntity(msg_t *msg) {
	msg->lastEntityRef = -1;
}

void __cdecl MSG_Discard(msg_t *msg) {
	msg->overflowed = 1;
	msg->cursize = msg->readcount;
	msg->splitSize = 0;
}

void MSG_Embed(msg_t *dest, msg_t *src) {
	int padBits; // ST0C_4

	if (dest->maxsize - dest->cursize >= src->cursize + 1) {
		padBits = (5 - dest->bit) & 7;
		MSG_WriteBits(dest, padBits, 3);
		MSG_WriteBits(dest, 0, padBits);
		memcpy(&dest->data[dest->cursize], src->data, src->cursize);
		dest->bit = src->bit + 8 * dest->cursize;
		dest->cursize += src->cursize;
	} else {
		dest->overflowed = 1;
	}
}

int MSG_GetByte(msg_t *msg, int where) {
	if (where < msg->cursize) {
		return (unsigned __int8)msg->data[where];
	}

	ASSERT(msg->splitData);

	return (unsigned __int8)msg->splitData[where - msg->cursize];
}

void MSG_WriteBit0(msg_t *msg) {
	ASSERT(!msg->readOnly);

	if (!(msg->bit & 7)) {
		if (msg->cursize >= msg->maxsize) {
			msg->overflowed = 1;
			return;
		}

		msg->bit = 8 * msg->cursize;
		msg->data[msg->cursize++] = 0;
	}

	++msg->bit;
}

void MSG_WriteBit1(msg_t *msg) {
	int bit; // [esp+4h] [ebp-4h]

	ASSERT(!msg->readOnly);

	bit = msg->bit & 7;

	if (!bit) {
		if (msg->cursize >= msg->maxsize) {
			msg->overflowed = 1;
			return;
		}

		msg->bit = 8 * msg->cursize;
		msg->data[msg->cursize++] = 0;
	}

	msg->data[msg->bit >> 3] |= 1 << bit;
	++msg->bit;
}

void MSG_WriteBits(msg_t *msg, int value, int bits) {
	int bit; // [esp+4h] [ebp-4h]

	ASSERT((unsigned)bits <= 32);
	ASSERT(!msg->readOnly);

	if (msg->maxsize - msg->cursize >= 4) {
		while (bits) {
			--bits;
			bit = msg->bit & 7;

			if (!bit) {
				msg->bit = 8 * msg->cursize;
				msg->data[msg->cursize++] = 0;
			}

			if (value & 1) {
				msg->data[msg->bit >> 3] |= 1 << bit;
			}

			++msg->bit;
			value >>= 1;
		}
	} else {
		msg->overflowed = 1;
	}
}

void MSG_WriteByte(msg_t *msg, int c) {
	ASSERT(!msg->readOnly);

	if (msg->cursize >= msg->maxsize) {
		msg->overflowed = 1;
	} else {
		msg->data[msg->cursize++] = c;
	}
}

void MSG_WriteData(msg_t *buf, const void *data, int length) {
	// TODO: Check if param "data" is actually a const char *.
	int newsize; // [esp+0h] [ebp-4h]

	ASSERT(!buf->readOnly);
	newsize = length + buf->cursize;

	if (newsize > buf->maxsize) {
		buf->overflowed = 1;
	} else {
		memcpy(&buf->data[buf->cursize], (char *)data, length);
		buf->cursize = newsize;
	}
}

void MSG_WritePosition(msg_t *msg, vec3_t *origin) {
	// TODO: Double check if this is correct.
	MSG_WriteBits(msg, *(_DWORD *)origin.x, 32);
	MSG_WriteBits(msg, *((_DWORD *)origin.y), 32);
	MSG_WriteBits(msg, *((_DWORD *)origin.z), 32);
}

void MSG_WriteQuat(msg_t *msg, float *quat) {
	// it's float * because we don't currently have a class for quats.
	MSG_WriteByte(msg, (signed int)(float)(*quat * 128.0) + 128);
	MSG_WriteByte(msg, (signed int)(float)(quat[1] * 128.0) + 128);
	MSG_WriteByte(msg, (signed int)(float)(quat[2] * 128.0) + 128);
	MSG_WriteByte(msg, (signed int)(float)(quat[3] * 128.0) + 128);
}

void MSG_WriteShort(msg_t *msg, int c) {
	int newsize; // [esp+0h] [ebp-4h]

	ASSERT(!msg->readOnly);

	newsize = msg->cursize + 2;

	if (newsize > msg->maxsize) {
		msg->overflowed = 1;
	} else {
		*(_WORD *)&msg->data[msg->cursize] = c;
		msg->cursize = newsize;
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
