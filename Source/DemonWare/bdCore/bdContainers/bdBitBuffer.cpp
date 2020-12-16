// TODO: Use IDA you cheap fuck.

class bdBitBuffer {
private:
	bdFastArray<unsigned char> m_data;
	unsigned int m_writePosition;
	unsigned int m_maxWritePosition;
	unsigned int m_readPosition;
	bool m_failedRead;
	bool m_typeChecked;

public:
	bdBitBuffer(unsigned int a2, bool typeChecked) {
		bdFastArray<unsigned char> *data;	// ST10_4
		char v6;							// [esp+12h] [ebp-Eh]
		char v7;							// [esp+13h] [ebp-Dh]
		int v8;								// [esp+1Ch] [ebp-4h]

		vfptr = (bdReferencableVtbl *)&bdReferencable::`vftable';

		m_refCount = 0;
		v8 = 0;

		vfptr = (bdReferencableVtbl *)&bdBitBuffer::`vftable';

		data = &m_data;
		data->m_data = 0;
		data->m_capacity = ((a2 & 7) != 0) + (a2 >> 3);
		data->m_size = 0;

		if (m_data.m_capacity) {
			m_data.m_data = (char *)bdMemory::allocate(m_data.m_capacity);
		}

		LOBYTE(v8) = 1;
		m_writePosition = 0;
		m_maxWritePosition = 0;
		m_readPosition = 0;
		m_failedRead = 0;
		m_typeChecked = typeChecked;

		if (m_typeChecked) {
			v7 = -1;
			writeBits(this, &v7, 1u);
		} else {
			v6 = 0;
			writeBits(this, &v6, 1u);
		}

		m_readPosition = 1;

		return this;
	}

	~bdBitBuffer() {
		bdFastArray<unsigned char> *data; // ST0C_4

		this->vfptr = (bdReferencableVtbl *)&bdBitBuffer::`vftable';
		data = &m_data;
		bdMemory::deallocate(m_data.m_data);
		data->m_data = 0;
		data->m_size = 0;
		data->m_capacity = 0;
		bdReferencable::~bdReferencable(this);
	}

	void writeBits(const void *a2, unsigned int a3) {
		#if 0
			unsigned int v3; // [esp+0h] [ebp-6Ch]
			unsigned int v4; // [esp+4h] [ebp-68h]
			char v6; // [esp+2Bh] [ebp-41h]
			unsigned int v7; // [esp+2Ch] [ebp-40h]
			unsigned int v8; // [esp+30h] [ebp-3Ch]
			unsigned int v9; // [esp+34h] [ebp-38h]
			unsigned int v11; // [esp+3Ch] [ebp-30h]
			char v12; // [esp+42h] [ebp-2Ah]
			char v13; // [esp+43h] [ebp-29h]
			char v15; // [esp+4Ah] [ebp-22h]
			unsigned __int8 v16; // [esp+4Bh] [ebp-21h]
			int v17; // [esp+4Ch] [ebp-20h]
			char v18; // [esp+53h] [ebp-19h]
			int v19; // [esp+54h] [ebp-18h]
			unsigned __int8 v20; // [esp+5Bh] [ebp-11h]
			unsigned int v21; // [esp+5Ch] [ebp-10h]
			_BYTE *v22; // [esp+60h] [ebp-Ch]
			unsigned int v23; // [esp+64h] [ebp-8h]
			unsigned int v24; // [esp+68h] [ebp-4h]

			v23 = (m_writePosition + a3 - 1) >> 3;
			if ( v23 >= m_data.m_size ) {
				v6 = 0;
				bdFastArray<unsigned char>::setGrow(v23, &v6);
			}
			v24 = a3;
			v22 = a2;

			while (v24) {
				v7 = m_writePosition & 7;
				v10 = 8 - (m_writePosition & 7);

				if (v24 >= 8 - (m_writePosition & 7)) {
					v4 = 8 - (m_writePosition & 7);
				} else {
					v4 = v24;
				}

				v8 = v4;
				v13 = (255 >> (8 - (m_writePosition & 7))) | (255 << (v7 + v4));
				v15 = v13 & m_data.m_data[m_writePosition >> 3];
				v21 = a3 - v24;
				v19 = ((_BYTE)a3 - (_BYTE)v24) & 7;
				v17 = 8 - v19;
				v9 = (a3 - v24) >> 3;
				v20 = v22[v9];
				v16 = 0;
				v11 = (a3 - 1) >> 3;

				if (v11 > v9) {
					v16 = v22[v9 + 1];
				}

				v20 = (v16 << v17) | ((signed int)v20 >> v19);
				v12 = ~v13;
				v18 = ~v13 & (v20 << v7);
				m_data.m_data[m_writePosition >> 3] = v18 | v15;
				m_writePosition += v8;
				v24 -= v8;

				if (m_maxWritePosition <= m_writePosition) {
					v3 = m_writePosition;
				} else {
					v3 = m_maxWritePosition;
				}

				m_maxWritePosition = v3;
			}
		#endif
	}

	bool readUByte8(unsigned char *a2) {
		return bdBitBuffer::readDataType(this, BD_BB_UNSIGNED_CHAR8_TYPE) && bdBitBuffer::readBits(this, a2, 8u);
	}

	bool getTypeCheck() {
		return m_typeChecked;
	}
};
