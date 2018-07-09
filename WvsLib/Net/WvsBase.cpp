#include "WvsBase.h"
#include <mutex>
#include "..\Logger\WvsLogger.h"

std::map<unsigned int, SocketBase*> WvsBase::aSocketList;
WvsBase* WvsBase::pInstance;

WvsBase::WvsBase()
{
}

WvsBase::~WvsBase()
{
}

asio::io_service& WvsBase::GetIOService()
{
	return mIOService;
}

SocketBase * WvsBase::GetSocket(int nSocketID)
{
	auto findIter = aSocketList.find(nSocketID);
	return findIter == aSocketList.end() ? nullptr : findIter->second;
}

void WvsBase::Init()
{

}

void WvsBase::CreateAcceptor(short nPort)
{
	WvsLogger::LogFormat(WvsLogger::LEVEL_INFO, "[WvsBase::CreateAcceptor]���\��Port %d�إ�Wvs���A���{�ǡC\n", nPort);
	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), nPort);
	mAcceptor = new asio::ip::tcp::acceptor(mIOService, endpoint);
}

void WvsBase::OnSocketConnected(SocketBase *pSocket)
{
	aSocketList.insert({ pSocket->GetSocketID(), pSocket });
	pSocket->SetDisconnectedNotifyFunc(WvsBase::OnSocketDisconnected);
}

void WvsBase::OnSocketDisconnected(SocketBase *pSocket)
{
	//printf("OnSocketDisconnected called!\n ");
	/*static std::mutex localLock;
	std::lock_guard<std::mutex> lock(localLock);*/
	auto findIter = aSocketList.find(pSocket->GetSocketID());
	if (findIter == aSocketList.end())
		return;
	WvsLogger::LogFormat(WvsLogger::LEVEL_WARNING, "[WvsBase::OnSocketDisconnected]�������ݳs�uSocket����ASocket ID = %d\n", pSocket->GetSocketID());
	pInstance->OnNotifySocketDisconnected(pSocket);
	aSocketList.erase(pSocket->GetSocketID());
}

void WvsBase::OnNotifySocketDisconnected(SocketBase *pSocket)
{
	//WvsBase is an ADT, so won't become recursive call.
	this->OnNotifySocketDisconnected(pSocket);
}