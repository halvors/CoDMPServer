bool __thiscall bdNetImpl::start(bdNetImpl *this, bdNetStartParams *startParams) {
	float fVar1;
	undefined *puVar2;
	undefined *puVar3;
	bool bVar4;
	ushort gamePort;
	bdSocket *extraout_EAX;
	bdSocketRouter *extraout_EAX_00;
	bdGetHostByName *extraout_EAX_01;
	int extraout_EAX_02;
	undefined4 extraout_EAX_03;
	bdConnectionStoreConfig *extraout_EAX_04;
	bdReference<class_bdCommonAddr> extraout_CL;
	int **in_FS_OFFSET;
	char *pcVar5;
	char *path;
	char *func;
	bdUPnPRunMode bVar6;
	uint uVar7;
	bdReference<class_bdCommonAddr> bVar8;
	char *pcVar9;
	undefined uVar10;
	undefined uVar11;
	undefined2 uVar12;
	uint uStack272;
	undefined *local_10c;
	undefined4 local_108;
	undefined4 local_104;
	int local_100;
	bool local_f9;
	bdGetHostByName *local_f4;
	bdSocketRouter *local_f0;
	bdSocket *socket;
	bdNetImpl *implementation;
	undefined *local_c4;
	int local_c0;
	int local_bc;
	bdInetAddr *local_a0;
	uint local_9c;
	bdECCKey *local_94;
	bdConnectionStoreConfig local_90;
	undefined *local_84;
	bdSocketRouterConfig local_80;
	bdCommonAddr *local_74;
	int local_70;
	bool local_69;
	undefined *local_68;
	bdGetHostByName *local_64;
	bdGetHostByName *local_60;
	bdSocketRouter *local_5c;
	bdSocketRouter *local_58;
	bdSocket *socketAlloc;
	bdSocket *local_50;
	bdAddr local_4c;
	uint local_44;
	undefined4 local_40;
	undefined4 local_3c;
	undefined4 local_38;
	bdAddr local_34;
	int local_2c;
	bool local_27;
	bool local_26;
	undefined local_25;
	int local_24;
	char local_1d;
	bdAddr local_1c;
	bool local_12;
	bool success;
	int *local_10;
	undefined *puStack12;
	undefined4 local_8;

	local_8 = 0xffffffff;
	puStack12 = &LAB_00c43594;
	local_10 = *in_FS_OFFSET;
	uStack272 = ___security_cookie ^ (uint)&stack0xfffffffc;
	*(int ***)in_FS_OFFSET = &local_10;
	success = true;
	implementation = this;
	if (this->m_status == BD_NET_STOPPED) {
		bdNetStartParams::operator=(&this->m_params, startParams);
		bdAddr::bdAddr(&local_1c);
		local_8 = 0;
		local_12 = bdNetImpl::getBindAddr(implementation, &local_1c);
		if (local_12 == false) {
			bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x2d);
			implementation->m_status = BD_NET_PARAMS_CONFIG_ERROR;
		}
		else {
			bVar4 = bdNetImpl::findFreePort(implementation, &local_1c);
			if (bVar4 == false) {
				bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0xa3);
				implementation->m_status = BD_NET_BIND_FAILED;
				success = false;
			}
			else {
				local_1d = '\x01';
				if ((implementation->m_params).m_socket == NULL) {
					socketAlloc = (bdSocket *)bdMemory::allocate(8);
					local_8._0_1_ = 1;
					if (socketAlloc == NULL) {
						socket = NULL;
					}
					else {
						bdSocket::bdSocket(socketAlloc);
						socket = extraout_EAX;
					}
					local_50 = socket;
					local_8 = (uint)local_8._1_3_ << 8;
					(implementation->m_params).m_socket = socket;
					local_25 = 0;
					local_1d = (**(code **)(*(int *)(implementation->m_params).m_socket + 4))();
				}
				local_24 = (**(code **)(*(int *)(implementation->m_params).m_socket + 8))();
				if (local_24 == 1) {
					gamePort = bdAddr::getPort(&local_1c);
					(implementation->m_params).m_gamePort = gamePort;
					bVar6 = 0x45;
					func = "bdNetImpl::start";
					path = "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp";
					pcVar5 = "bdNet/net";
					bdLogMessage(BD_LOG_INFO, "info/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x45, "Requested port %u,  using port %u");
					if (local_1d == '\0') {
						bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x4a);
						implementation->m_status = BD_NET_BIND_FAILED;
						success = false;
					}
					else {
						local_5c = (bdSocketRouter *)bdMemory::allocate(0x198);
						local_8._0_1_ = 2;
						if (local_5c == NULL) {
							local_f0 = NULL;
						}
						else {
							bdSocketRouter::bdSocketRouter(local_5c);
							local_f0 = extraout_EAX_00;
						}
						local_58 = local_f0;
						local_8._0_1_ = 0;
						uVar10 = (undefined)local_8;
						local_8._0_1_ = 0;
						implementation->m_socketRouter = local_f0;
						if ((implementation->m_params).m_onlineGame == false) {
							implementation->m_status = BD_NET_DONE;
							if ((implementation->m_params).m_localAddresses.m_size == 0) {
								local_8._0_1_ = uVar10;
								bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x80);
								local_69 = false;
								local_8 = 0xffffffff;
								bdInetAddr::~bdInetAddr((bdInetAddr *)&local_1c);
								goto LAB_00b723f5;
							}
							local_38 = 0;
							local_3c = 0;
							local_40 = 0;
							local_8._0_1_ = 4;
							local_44 = 0;
							while (local_9c = (implementation->m_params).m_localAddresses.m_size,  local_44 < local_9c) {
								local_a0 = (implementation->m_params).m_localAddresses.m_data + local_44;
								gamePort = (implementation->m_params).m_gamePort;
								bdAddr::bdAddr(&local_4c, local_a0, gamePort & 0xff | (ushort)(byte)((uint)gamePort >> 8) << 8);
								local_8._0_1_ = 5;
								bdArray<class_bdAddr>::pushBack((bdArray<class_bdAddr> *)&local_40, &local_4c);
								local_8._0_1_ = 4;
								bdInetAddr::~bdInetAddr((bdInetAddr *)&local_4c);
								local_44 += 1;
							}
							bdAddr::bdAddr(&local_34);
							local_8._0_1_ = 6;
							local_74 = (bdCommonAddr *)bdMemory::allocate(0x28);
							local_8._0_1_ = 7;
							if (local_74 == NULL) {
								local_100 = 0;
							}
							else {
								bdCommonAddr::bdCommonAddr(local_74, (bdArray<class_bdAddr> *)&local_40, &local_34, BD_NAT_OPEN);
								local_100 = extraout_EAX_02;
							}
							local_70 = local_100;
							local_8._0_1_ = 6;
							local_2c = local_100;
							if (local_100 != 0) {
								local_bc = local_100;
								InterlockedIncrement((LONG *)(local_100 + 4));
								local_104 = *(undefined4 *)(local_bc + 4);
							}
							local_8 = CONCAT31(local_8._1_3_, 8);
							bdSocketRouterConfig::bdSocketRouterConfig(&local_80);
							uVar10 = (undefined)extraout_EAX_03;
							uVar11 = (undefined)((uint)extraout_EAX_03 >> 8);
							uVar12 = (undefined2)((uint)extraout_EAX_03 >> 0x10);
							local_84 = &stack0xfffffee8;
							local_c4 = &stack0xfffffee8;
							puVar2 = &stack0xfffffee8;
							puVar3 = &stack0xfffffee8;
							bVar8 = extraout_CL;
							if (local_2c != 0) {
								local_c0 = local_2c;
								InterlockedIncrement((LONG *)(local_2c + 4));
								local_108 = *(undefined4 *)(local_c0 + 4);
								puVar2 = local_c4;
								puVar3 = local_84;
							}
							local_84 = puVar3;
							local_c4 = puVar2;
							local_10c = local_c4;
							bdSocketRouter::init(implementation->m_socketRouter, (implementation->m_params).m_socket, bVar8, (bdSocketRouterConfig *)CONCAT22(uVar12, CONCAT11(uVar11, uVar10)));
							bdConnectionStoreConfig::bdConnectionStoreConfig(&local_90);
							bdConnectionStore::init(&implementation->m_connectionStore, implementation->m_socketRouter, extraout_EAX_04);
							local_8._0_1_ = 6;
							bdReference<class_bdCommonAddr>::~bdReference<class_bdCommonAddr>((bdReference<class_bdCommonAddr> *)&local_2c);
							local_8._0_1_ = 4;
							bdInetAddr::~bdInetAddr((bdInetAddr *)&local_34);
							local_8 = (uint)local_8._1_3_ << 8;
							bdArray<class_bdAddr>::clear((bdArray<class_bdAddr> *)&local_40);
						}
						else {
							implementation->m_status = BD_NET_PENDING;
							implementation->m_currentNatTravAddrIndex = 0;
							implementation->m_currentNatTravHostIndex = 0;
							local_64 = (bdGetHostByName *)bdMemory::allocate(0x38);
							local_8._0_1_ = 3;
							if (local_64 == NULL) {
								local_f4 = NULL;
							}
							else {
								bdGetHostByName::bdGetHostByName(local_64);
								local_f4 = extraout_EAX_01;
							}
							local_60 = local_f4;
							local_8 = (uint)local_8._1_3_ << 8;
							implementation->m_getHostByName = local_f4;
							local_94 = (bdECCKey *)((implementation->m_params).m_natTravHosts.m_data + implementation->m_currentNatTravHostIndex);
							fVar1 = (implementation->m_params).m_hostNameLookupConfig.m_timeout;
							uVar10 = SUB41(fVar1, 0);
							uVar11 = (undefined)((uint)fVar1 >> 8);
							uVar12 = (undefined2)((uint)fVar1 >> 0x10);
							pcVar9 = (char *)bdECCKey::getStatus(local_94);
							uVar7 = 0xb7202c;
							local_26 = bdGetHostByName::start(implementation->m_getHostByName, pcVar9, (bdGetHostByNameConfig)CONCAT22(uVar12, CONCAT11(uVar11, uVar10)));
							if (local_26 == false) {
								bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x68);
								implementation->m_status = BD_NET_INIT_FAILED;
								success = false;
							}
							else {
								local_68 = &stack0xfffffed4;
								bdUPnPConfig::bdUPnPConfig((bdUPnPConfig *)&stack0xfffffed4, &(implementation->m_params).m_UPnPConfig);
								local_f9 = bdUPnP::init(&implementation->m_UPnP, (implementation->m_params).m_gamePort, (bdArray<class_bdInetAddr> *)&(implementation->m_params).m_localAddresses, (bdUPnPConfig)CONCAT226(uVar12, CONCAT125(uVar11, CONCAT124(uVar10, CONCAT420(pcVar9, CONCAT416(uVar7, CONCAT412(bVar6, CONCAT48(func, CONCAT44(path, pcVar5)))))))));
								local_27 = local_f9;
								if (local_f9 == false) {
									bdLogMessage(BD_LOG_ERROR, "err/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x75);
								}
							}
						}
					}
				} else {
					bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x9d);
					implementation->m_status = BD_NET_BIND_FAILED;
				}
			}
		}
		local_8 = 0xffffffff;
		bdInetAddr::~bdInetAddr((bdInetAddr *)&local_1c);
		local_69 = success;
	} else {
		bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::start", 0x21);
		success = false;
		local_69 = success;
	}
LAB_00b723f5:
	*in_FS_OFFSET = local_10;
	return local_69;
}

void __thiscall bdNetImpl::stop(bdNetImpl *this) {
	bdSocket *Socket;
	bdIPDiscoveryClient *IPDiscoveryClient;
	bdNATTypeDiscoveryClient *NATTypeDiscoveryClient;
	char cVar1;
	bdECCKeyStatus ECCKeyStatus;
	bdNATType NATType;
	bool bVar2;
	float fVar3;
	bool loop;
	bdStopwatch Stopwatch;
	ECCKeyStatus = bdECCKey::getStatus((bdECCKey *)&this->m_UPnP);
	if (ECCKeyStatus != BD_ECC_KEY_UNINITIALIZED) {
		bdUPnP::startShutdown(&this->m_UPnP, BD_UPNP_DEVICE_SHUTDOWN_ELEGANT);
	}
	bdConnectionStore::startShutdown(&this->m_connectionStore, BD_CONNECTION_STORE_SHUTDOWN_ELEGANT);
	bdStopwatch::bdStopwatch(&Stopwatch);
	bdStopwatch::start(&Stopwatch);
	loop = true;
	while (loop) {
		NATType = bdCommonAddr::getNATType((bdCommonAddr *)&this->m_connectionStore);
		if (NATType != 0) {
			bdNetImpl::receiveAll(this);
			bdNetImpl::dispatchAll(this);
			bdNetImpl::sendAll(this);
		}
		ECCKeyStatus = bdECCKey::getStatus((bdECCKey *)&this->m_UPnP);
		if (ECCKeyStatus != BD_ECC_KEY_UNINITIALIZED) {
			bdUPnP::pump(&this->m_UPnP);
		}
		loop = ECCKeyStatus != BD_ECC_KEY_UNINITIALIZED || NATType != 0;
		fVar3 = bdStopwatch::getElapsedTimeInSeconds(&Stopwatch);
		bVar2 = (ushort)((ushort)(fVar3 < 1.00000000) << 8 | (ushort)(fVar3 == 1.00000000) << 0xe) == 0;
		if (bVar2) {
			bdConnectionStore::startShutdown(&this->m_connectionStore, BD_CONNECTION_STORE_SHUTDOWN_IMMEDIATE);
			bdUPnP::startShutdown(&this->m_UPnP, BD_UPNP_DEVICE_SHUTDOWN_IMMEDIATE);
		}
		loop = !bVar2 && loop;
		bdPlatformTiming::sleep(0x14);
	}
	if (this->m_socketRouter != NULL) {
		(**(code **)(*(int *)this->m_socketRouter + 0x10))();
		if (this->m_socketRouter != NULL) {
			(***(code ***)this->m_socketRouter)(1);
		}
		this->m_socketRouter = NULL;
	}
	if ((this->m_params).m_socket != NULL) {
		cVar1 = (**(code **)(*(int *)(this->m_params).m_socket + 0x18))();
		if (cVar1 == '\0') {
			bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::stop", 0x22a, "Game socket failed to close with an error");
		}
		Socket = (this->m_params).m_socket;
		if (Socket != NULL) {
			(***(code ***)Socket)(1);
		}
		(this->m_params).m_socket = NULL;
	}
	if (this->m_ipDiscClient != NULL) {
		bdIPDiscoveryClient::quit(this->m_ipDiscClient);
		IPDiscoveryClient = this->m_ipDiscClient;
		if (IPDiscoveryClient != NULL) {
			bdIPDiscoveryClient::~bdIPDiscoveryClient(IPDiscoveryClient);
			bdMemory::deallocate(IPDiscoveryClient);
		}
		this->m_ipDiscClient = NULL;
	}
	if (this->m_natTypeDiscClient != NULL) {
		bdNATTypeDiscoveryClient::quit(this->m_natTypeDiscClient);
		NATTypeDiscoveryClient = this->m_natTypeDiscClient;
		if (NATTypeDiscoveryClient != NULL) {
			bdNATTypeDiscoveryClient::~bdNATTypeDiscoveryClient(NATTypeDiscoveryClient);
			bdMemory::deallocate(NATTypeDiscoveryClient);
		}
		this->m_natTypeDiscClient = NULL;
	}
	if (this->m_getHostByName != NULL) {
		bdGetHostByName::quit(this->m_getHostByName);
		if (this->m_getHostByName != NULL) {
			(***(code ***)this->m_getHostByName)(1);
		}
		this->m_getHostByName = NULL;
	}
	this->m_status = BD_NET_STOPPED;
	this->m_currentNatTravAddrIndex = 0;
	this->m_currentNatTravHostIndex = 0;
	bdArray<class_bdInetAddr>::clear((bdArray<class_bdInetAddr> *)&(this->m_params).m_localAddresses);
	bdArray<class_bdString>::clear((bdArray<class_bdString> *)&(this->m_params).m_natTravHosts);
	bdArray<class_bdAddr>::clear((bdArray<class_bdAddr> *)&this->m_natTravAddrs);
}

bool __thiscall bdNetImpl::sendAll(bdNetImpl *this) {
	bool success = bdConnectionStore::flushAll(&this->m_connectionStore);
	if (!success) {
		bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::sendAll", 600, "Failed to flush all connections in the connection store");
	}
	return success;
}

bool __thiscall bdNetImpl::receiveAll(bdNetImpl *this) {
	bool success = bdConnectionStore::receiveAll(&this->m_connectionStore);
	if (!success) {
		bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::receiveAll", 0x262, "Failed to receive data for all connections in the connection store");
	}
	return success;
}

bool __thiscall bdNetImpl::findFreePort(bdNetImpl *this, bdAddr *param_1) {
	bool bVar1;
	uint uVar2;
	bdInetAddr *extraout_EAX;
	bdSocketStatusCode bVar3;
	int **in_FS_OFFSET;
	ushort uVar4;
	undefined4 local_30;
	undefined4 local_2c;
	bool local_26;
	undefined local_25;
	bdSocket local_24;
	uint local_1c;
	undefined local_15;
	ushort local_14;
	int *local_10;
	undefined *puStack12;
	undefined4 local_8;
	local_8 = 0xffffffff;
	puStack12 = &LAB_00c437f0;
	local_10 = *in_FS_OFFSET;
	uVar2 = ___security_cookie ^ (uint)&stack0xfffffffc;
	*(int ***)in_FS_OFFSET = &local_10;
	local_14 = bdAddr::getPort(param_1);
	local_15 = 0;
	local_1c = 0;
	do {
		if (99 < local_1c) {
LAB_00b746ea:
			*in_FS_OFFSET = local_10;
			return (bool)local_15;
		}
		bdSocket::bdSocket(&local_24);
		local_8 = 0;
		local_25 = 0;
		local_26 = bdSocket::create(&local_24, false, true, true);
		if (local_26 == false) {
			bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::findFreePort", 0x2ba, "Create socket failed ", uVar2, this);
			local_8 = 0xffffffff;
			bdSocket::~bdSocket(&local_24);
			goto LAB_00b746ea;
		}
		uVar4 = local_14;
		bdTrulyRandomImpl::bdTrulyRandomImpl((bdTrulyRandomImpl *)param_1);
		bdAddr::bdAddr((bdAddr *)&local_30, extraout_EAX, uVar4);
		local_8 = CONCAT31(local_8._1_3_, 1);
		bVar3 = bdSocket::bind(&local_24, (bdAddr *)&local_30);
		if (bVar3 == BD_NET_SUCCESS) {
			bVar1 = bdSocket::close(&local_24);
			if (bVar1 == false) {
				bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::findFreePort", 0x2c7, "Socket failed to close with an error");
			}
			local_15 = 1;
			(param_1->m_address).m_addr.inUn = local_30;
			*(undefined4 *)&param_1->m_port = local_2c;
			local_8 &= 0xffffff00;
			bdInetAddr::~bdInetAddr((bdInetAddr *)&local_30);
			local_8 = 0xffffffff;
			bdSocket::~bdSocket(&local_24);
			goto LAB_00b746ea;
		}
		if (bVar3 == BD_NET_ADDRESS_IN_USE) {
			bVar1 = bdSocket::close(&local_24);
			if (bVar1 == true) {
				bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::findFreePort", 0x2d5, "Socket bind failed,  but subsequent close succeeded!");
			}
		} else {
			bVar1 = bdSocket::close(&local_24);
			if (bVar1 == false) {
				bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::findFreePort", 0x2dd, "Socket failed to close with an error");
			}
		}
		local_14 += 1;
		local_8 &= 0xffffff00;
		bdInetAddr::~bdInetAddr((bdInetAddr *)&local_30);
		local_8 = 0xffffffff;
		bdSocket::~bdSocket(&local_24);
		local_1c += 1;
	} while (true);
}

bool __thiscall bdNetImpl::getBindAddr(bdNetImpl *this, bdAddr *param_1) {
	undefined4 uVar1;
	uint uVar2;
	undefined4 *extraout_EAX;
	bdInetAddr bVar3;
	undefined4 *extraout_EAX_00;
	int **in_FS_OFFSET;
	bdInetAddr local_28;
	bdAddr local_24;
	bdAddr local_1c;
	bool success;
	int *local_10;
	undefined *puStack12;
	undefined4 local_8;
	local_8 = 0xffffffff;
	puStack12 = &LAB_00c43818;
	local_10 = *in_FS_OFFSET;
	uVar2 = ___security_cookie ^ (uint)&stack0xfffffffc;
	*(int ***)in_FS_OFFSET = &local_10;
	success = false;
	if ((this->m_params).m_useAnyIP == false) {
		if (1 < (this->m_params).m_localAddresses.m_size) {
			bdLogMessage(BD_LOG_WARNING, "warn/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::getBindAddr", 0x2ef, "When binding to a specific IP,  entries in m_localAddresses other than the zeroth are ignored", uVar2);
		}
		if ((this->m_params).m_localAddresses.m_size == 0) {
			bdLogMessage(BD_LOG_ERROR, "err/", "bdNet/net", "C:\\projects_pc\\cod\\codsrc\\DemonWare\\bdNet\\bdNet.cpp", "bdNetImpl::getBindAddr", 0x2f9, "When binding to a specific IP,  m_localAddresses should not be empty", uVar2);
		} else {
			bdAddr::bdAddr(&local_1c, (this->m_params).m_localAddresses.m_data, (this->m_params).m_gamePort);
			uVar1 = extraout_EAX[1];
			(param_1->m_address).m_addr.inUn = *extraout_EAX;
			*(undefined4 *)&param_1->m_port = uVar1;
			bdInetAddr::~bdInetAddr((bdInetAddr *)&local_1c);
			success = true;
		}
	} else {
		bVar3 = bdInetAddr::Any();
		local_8 = 0;
		bdAddr::bdAddr(&local_24, (bdInetAddr *)bVar3, (this->m_params).m_gamePort);
		uVar1 = extraout_EAX_00[1];
		(param_1->m_address).m_addr.inUn = *extraout_EAX_00;
		*(undefined4 *)&param_1->m_port = uVar1;
		bdInetAddr::~bdInetAddr((bdInetAddr *)&local_24);
		local_8 = 0xffffffff;
		bdInetAddr::~bdInetAddr(&local_28);
		success = true;
	}
	*in_FS_OFFSET = local_10;
	return success;
}
