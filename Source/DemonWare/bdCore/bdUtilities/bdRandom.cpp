class bdRandom {
private:
	unsigned int m_val;

public:
	bdRandom() {
		__uint64 timeStamp = bdPlatformTiming::getHiResTimeStamp();
		bdRandom::setSeed(this, (unsigned int)timeStamp);
	}

	unsigned int nextUInt() {
		// TODO: Clean this trash.
		unsigned int next;

		next = (this->m_val % 0x1F31D) * 0x41A7 + (this->m_val / 0x1F31D) * -0xB14;

		if ((int)next < 1) {
			next += 0x7FFFFFFF;
		}

		this->m_val = next;
		return this->m_val;
	}

	void nextUBytes(unsigned char *bytes, int byteCount) {
		unsigned int nextUInt;
		unsigned char nextUByte;

		for (int i = 0; i < byteCount; i++) {
			nextUInt = bdRandom::nextUInt(this);
			nextUByte = (unsigned char)nextUInt;
			bytes[i] = nextUByte;
		}
	}

	void setSeed(unsigned int seed) {
		this->m_val = seed;

		if (seed == 0) {
			bdLogMessage(BD_LOG_WARNING, "warn/", "random", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdCore\\bdUtilities\\bdRandom.cpp", "bdRandom::setSeed", 0x40, "Shouldn\'t use 0 for seed. 12,195,257 used instead.");
			this->m_val = 0xBA15B9;
		}
	}
};
