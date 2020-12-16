
class bdAddressMap {
private:
	// TODO: Reverse class members.
	/* data */

public:
	bdAddressMap() {
		bdReference<bdAddrHandle> *v1;
		m_addrHandles.m_data = NULL;
		m_addrHandles.m_capacity = 0;
		m_addrHandles.m_size = 0;

		if (m_addrHandles.m_capacity != 0) {
			v1 = (bdReference<bdAddrHandle> *)bdMemory::allocate(m_addrHandles.m_capacity << 2);
			m_addrHandles.m_data = v1;
		}
	}

	~bdAddressMap() {
		bdArray<class_bdReference<class_bdCommonAddr>>::clear((bdArray<class_bdReference<class_bdCommonAddr>> *)this);
	}

	bool getAddrHandle(bdReference<class_bdCommonAddr> a2, bdSecurityID &a3, bdReference<class_bdAddrHandle> &a4) {
		// TODO: Reverse getAddrHandle()
	}
};
