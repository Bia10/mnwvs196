#include "WvsLogin.h"
#include <thread>
#include <iostream>
#include <functional>
#include "..\WvsLib\Net\OutPacket.h"
#include "..\WvsLib\Task\AsnycScheduler.h"
#include "..\WvsLib\Logger\WvsLogger.h"
#include "..\WvsLib\Constants\ConfigLoader.hpp"
#include "..\WvsLib\Constants\ServerConstants.hpp"

WvsLogin::WvsLogin()
{
}


WvsLogin::~WvsLogin()
{
}

int WvsLogin::GetCenterCount() const
{
	return m_nCenterCount;
}

void WvsLogin::SetCenterOpened(int nCenterIdx, bool bConnecting)
{ 
	aIsConnecting[nCenterIdx] = bConnecting;
}

bool WvsLogin::IsCenterOpened(int nCenterIdx) const
{
	return aIsConnecting[nCenterIdx];
}

std::shared_ptr<Center>& WvsLogin::GetCenter(int idx)
{
	return aCenterList[idx];
}

void WvsLogin::ConnectToCenter(int nCenterIdx)
{
	try 
	{
		aCenterServerService[nCenterIdx].reset(new asio::io_service());
		aCenterList[nCenterIdx] = std::make_shared<Center>(*aCenterServerService[nCenterIdx]);
		aCenterList[nCenterIdx]->SetDisconnectedNotifyFunc(&Center::OnNotifyCenterDisconnected);
		aCenterList[nCenterIdx]->SetCenterIndex(nCenterIdx);
		WvsLogger::LogRaw(WvsLogger::LEVEL_WARNING, "�}��Connection\n");
		aCenterList[nCenterIdx]->OnConnectToCenter(
			ConfigLoader::GetInstance()->StrValue("Center" + std::to_string(nCenterIdx) + "_IP"),
			ConfigLoader::GetInstance()->IntValue("Center" + std::to_string(nCenterIdx) + "_Port")
		);
		asio::io_service::work work(*aCenterServerService[nCenterIdx]);
		std::error_code ec;
		aCenterServerService[nCenterIdx]->run(ec);
	}
	catch (std::exception& e) 
	{
		printf("Exception occurred : %s\n", e.what());
	}
}

void WvsLogin::CenterAliveMonitor(int i)
{
	if (IsCenterOpened(i))
		return;
	SetCenterOpened(i, true);
	try 
	{
		WvsLogger::LogRaw(WvsLogger::LEVEL_WARNING, "=================�w���ˬdCenter Server�s�u�{��=================\n");
		int centerSize = ConfigLoader::GetInstance()->IntValue("CenterCount");
		if (aCenterList[i] && aCenterList[i]->IsConnectionFailed())
		{
			aCenterList[i].reset();
			aCenterServerService[i]->stop();
			WvsLogger::LogFormat("Center Server %d �s�u���ѡA���խ��s�s�u�C\n", i);
			/*if (aCenterWorkThread[i])
			{
				aCenterWorkThread[i]->detach();
				*aCenterWorkThread[i] = std::thread(&WvsLogin::ConnectToCenter, this, i);
			}
			else*/
			aCenterWorkThread[i]->detach();
			aCenterWorkThread[i].reset(new std::thread(&WvsLogin::ConnectToCenter, this, i)); 
		}
	}
	catch (std::exception& e) 
	{
	}
}

void WvsLogin::InitializeCenter()
{
	m_nCenterCount = ConfigLoader::GetInstance()->IntValue("CenterCount");
	for (int i = 0; i < m_nCenterCount; ++i)
	{
		SetCenterOpened(i, false);
		aCenterWorkThread[i].reset(new std::thread(&WvsLogin::ConnectToCenter, this, i));
		auto holderFunc = std::bind(&WvsLogin::CenterAliveMonitor, this, i);
		auto aliveHolder = AsnycScheduler::CreateTask(holderFunc, 10 * 100, true);
		aliveHolder->Start();
	}
}

void WvsLogin::OnNotifySocketDisconnected(SocketBase *pSocket)
{
}