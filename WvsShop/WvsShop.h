#pragma once
#include "Center.h"
#include "..\WvsLib\Net\WvsBase.h"
class User;

class WvsShop : public WvsBase
{
	int m_nExternalPort = 0;
	int m_aExternalIP[4];

	std::shared_ptr<Center> aCenterList;
	asio::io_service* m_pCenterServerService;
	std::thread* aCenterWorkThread;

	std::mutex m_mUserLock;
	std::map<int, std::shared_ptr<User>> m_mUserMap;

	//����Center instance�O�_���b�s�u�A�Ω��קK���s�����`
	bool aIsConnecting;

	void ConnectToCenter();
	void CenterAliveMonitor();

public:
	WvsShop();
	~WvsShop();

	void SetExternalIP(const std::string& ip);
	void SetExternalPort(short nPort);
	int* GetExternalIP() const;
	short GetExternalPort() const;

	std::shared_ptr<Center>& GetCenter();
	void InitializeCenter(); 

	void OnUserConnected(std::shared_ptr<User> &pUser);
	void OnNotifySocketDisconnected(SocketBase *pSocket);

	//�]�wCenter instance���s�u���p
	void SetCenterConnecting(bool bConnecting);

	//���oCenter instance���s�u���p
	bool IsCenterConnecting() const;
};

