#pragma once
#include "Net\asio.hpp"
#include "Net\WvsBase.h"
#include "WvsLoginConstants.hpp"
#include "Center.h"
#include <thread>
#include <mutex>
#include <condition_variable>

class WvsLogin : public WvsBase
{
private:
	void ConnectToCenter(int nCenterIdx);

	std::shared_ptr<Center> aCenterList[WvsLoginConstants::kMaxNumberOfCenters];
	std::shared_ptr<asio::io_service> aCenterServerService[WvsLoginConstants::kMaxNumberOfCenters];
	std::shared_ptr<std::thread> aCenterWorkThread[WvsLoginConstants::kMaxNumberOfCenters];

	//����Center instance�O�_���b�s�u�A�Ω��קK���s�����`
	bool aIsConnecting[WvsLoginConstants::kMaxNumberOfCenters];
	void CenterAliveMonitor(int idx);

public:

	WvsLogin();
	~WvsLogin();

	int GetCenterCount() const;
	std::shared_ptr<Center>& GetCenter(int idx);
	void InitializeCenter();
	void OnNotifySocketDisconnected(SocketBase *pSocket);

	//�]�wCenter instance���s�u���p
	void SetCenterOpened(int nCenterIdx, bool bConnecting);

	//���oCenter instance���s�u���p
	bool IsCenterOpened(int nCenterIdx) const;
};

