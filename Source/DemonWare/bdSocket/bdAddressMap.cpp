
class bdAddressMap {
private:
	/* data */

public:
	bdAddressMap() {
		bdReference<bdAddrHandle> *pbVar1;
		(this->m_addrHandles).m_data = NULL;
		(this->m_addrHandles).m_capacity = 0;
		(this->m_addrHandles).m_size = 0;

		if ((this->m_addrHandles).m_capacity != 0) {
			pbVar1 = (bdReference<bdAddrHandle> *)bdMemory::allocate((this->m_addrHandles).m_capacity << 2);
			(this->m_addrHandles).m_data = pbVar1;
		}
	}

	~bdAddressMap() {
		bdArray<class_bdReference<class_bdCommonAddr>>::clear((bdArray<class_bdReference<class_bdCommonAddr>> *)this);
	}

	bool getAddrHandle(bdReference<class_bdCommonAddr> param_1, bdSecurityID &param_2, bdReference<class_bdAddrHandle> &param_3) {
		// TODO: Reverse getAddrHandle()
	}
};
