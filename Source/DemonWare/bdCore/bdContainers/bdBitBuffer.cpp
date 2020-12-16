class bdBitBuffer {
private:
	bdFastArray<unsigned char> m_data;
	unsigned int m_writePosition;
	unsigned int m_maxWritePosition;
	unsigned int m_readPosition;
	bool m_failedRead;
	bool m_typeChecked;

public:
	bdBitBuffer(unsigned int param_1, bool param_2) {
		unsigned char *puVar1;
		int **in_FS_OFFSET;
		undefined local_12;
		undefined local_11;
		int *local_10;
		undefined *puStack12;
		undefined4 local_8;

		puStack12 = &LAB_00C45D03;
		local_10 = *in_FS_OFFSET;
		*(int ***)in_FS_OFFSET = &local_10;
		*(undefined4 *)this = 0xDACDDC;
		*(undefined4 *)&this->field_0x4 = 0;
		local_8 = 0;
		*(undefined4 *)this = 0xDB2BF8;

		(this->m_data).m_data = NULL;
		(this->m_data).m_capacity = (param_1 >> 3) + (uint)((param_1 & 7) != 0);
		(this->m_data).m_size = 0;

		if ((this->m_data).m_capacity != 0) {
			puVar1 = (unsigned char *)bdMemory::allocate((this->m_data).m_capacity);
			(this->m_data).m_data = puVar1;
		}

		local_8 = CONCAT31(local_8._1_3_, 1);

		this->m_writePosition = 0;
		this->m_maxWritePosition = 0;
		this->m_readPosition = 0;
		this->m_failedRead = false;
		this->m_typeChecked = param_2;

		if (this->m_typeChecked == false) {
			local_12 = 0;
			bdBitBuffer::writeBits(this, &local_12, 1);
		} else {
			local_11 = 0xFF;
			bdBitBuffer::writeBits(this, &local_11, 1);
		}

		this->m_readPosition = 1;
		*in_FS_OFFSET = local_10;
		return;
	}

	~bdBitBuffer() {
		int **in_FS_OFFSET;
		int *local_10;
		undefined *puStack12;
		undefined4 local_8;

		puStack12 = &LAB_00C45D58;
		local_10 = *in_FS_OFFSET;
		*(int ***)in_FS_OFFSET = &local_10;
		*(undefined4 *)this = 0xDB2BF8;
		local_8 = 0;
		bdMemory::deallocate((this->m_data).m_data);
		(this->m_data).m_data = NULL;
		(this->m_data).m_size = 0;
		(this->m_data).m_capacity = 0;
		local_8 = 0xFFFFFFFF;
		bdReferencable::~bdReferencable((bdReferencable *)this);
		*in_FS_OFFSET = local_10;
		return;
	}

	void writeBits(void *param_1, unsigned int param_2) {
		sbyte sVar1;
		byte bVar2;
		uint uVar3;
		byte bVar4;
		uint uVar5;
		uint local_70;
		uint local_6c;
		unsigned char local_45[32];
		char local_25;
		uint local_c;
		uint local_8;

		local_c = (this->m_writePosition - 1) + param_2 >> 3;

		if ((this->m_data).m_size <= local_c) {
			local_45[0] = '\0';
			bdFastArray<unsigned_char>::setGrow((bdFastArray<unsigned_char> *)&this->m_data, local_c, local_45);
		}

		local_8 = param_2;

		while (local_8 != 0) {
			uVar3 = this->m_writePosition & 7;
			uVar5 = 8 - uVar3;
			local_6c = uVar5;

			if (local_8 < uVar5) {
				local_6c = local_8;
			}

			sVar1 = (sbyte)uVar3;
			bVar4 = (byte)(0xFF << ((char)local_6c + sVar1 & 0x1FU)) | (byte)(0xFF >> ((byte)uVar5 & 0x1F));
			uVar3 = this->m_writePosition >> 3;
			bVar2 = (byte)(param_2 - local_8) & 7;
			uVar5 = param_2 - local_8 >> 3;
			local_25 = '\0';

			if (uVar5 < param_2 - 1 >> 3) {
				local_25 = *(char *)((int)param_1 + uVar5 + 1);
			}

			(this->m_data).m_data[uVar3] = (this->m_data).m_data[uVar3] & bVar4 | ((byte)((int)(uint)*(byte *)((int)param_1 + uVar5) >> bVar2) | local_25 << (8 - bVar2 & 0x1F)) << sVar1 & (bVar4 ^ 0xFF);
			this->m_writePosition = this->m_writePosition + local_6c;
			local_8 -= local_6c;

			if (this->m_maxWritePosition < this->m_writePosition || this->m_maxWritePosition == this->m_writePosition) {
				local_70 = this->m_writePosition;
			} else {
				local_70 = this->m_maxWritePosition;
			}

			this->m_maxWritePosition = local_70;
		}

		return;
	}

	bool readUByte8(unsigned char *param_1) {
		bool success = bdBitBuffer::readDataType(this, BD_BB_UNSIGNED_CHAR8_TYPE);

		if ((success != false) && (success = bdBitBuffer::readBits(this, param_1, 8), success != false)) {
			return true;
		}

		return false;
	}

	bool getTypeCheck() {
		return this->m_typeChecked;
	}
};
