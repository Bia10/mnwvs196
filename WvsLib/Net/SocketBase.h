#pragma once
#include "..\Net\asio.hpp"
#include "..\Memory\MemoryPoolMan.hpp"
#include "..\Logger\WvsLogger.h"

class OutPacket;
class InPacket;

class SocketBase : public std::enable_shared_from_this<SocketBase>
{
private:
	static unsigned int SocketCount;
	unsigned char nServerType;
	unsigned int nSocketID;

	asio::ip::tcp::socket mSocket;
	unsigned char* aRecvIV, *aSendIV;
	//std::unique_ptr<unsigned char, ArenaUniquePtrDeleter> aRecivedPacket;

	//Note : this flag indicate what this socket is for, when the flag is true, that means the socket is for local server.
	//You should note that local server won't encrypt and decrypt packets, and won't send game server info.
	bool bIsLocalServer = false;

	void(*OnNotifySocketDisconnected)(SocketBase *pSocket);

	void EncodeHandShakeInfo(OutPacket *oPacket);

	//�Ω�����ʥ]��Buffer�귽 (�Ӹ귽�D�g��Arena�t�m)
	void OnSendPacketFinished(const std::error_code &ec, std::size_t bytes_transferred, unsigned char *buffer, void *pPacket);
	void OnReceive(const std::error_code &ec, std::size_t bytes_transferred, unsigned char* buffer);
	void ProcessPacket(const std::error_code &ec, std::size_t bytes_transferred, unsigned char* buffer);

protected:
	void OnWaitingPacket();
	virtual void OnClosed() = 0;

public:
	SocketBase(asio::io_service& serverService, bool isLocalServer = false);
	virtual ~SocketBase();

	void SetDisconnectedNotifyFunc(void(*FUNC)(SocketBase *))
	{
		OnNotifySocketDisconnected = FUNC;
	}

	void SetServerType(unsigned char type)
	{
		nServerType = type;
	}

	unsigned char GetServerType()
	{
		return nServerType;
	}

	unsigned int GetSocketID() const;
	void Init();
	void SendPacket(OutPacket *iPacket, bool handShakePacket = false);
	void OnDisconnect();
	virtual void OnPacket(InPacket *iPacket) = 0;

	asio::ip::tcp::socket& GetSocket();
};