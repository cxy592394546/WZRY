#include "TCP.h"

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
using namespace Net;
using namespace std;

Net::TCP::TCP()
{
	m_clientProc.func = NULL;
	m_clientProc.Param = NULL;
	m_recvThread = nullptr;
}

TCP::TCP(ClientFunc clientProc, LPVOID Param)
{
	m_clientProc.func = clientProc;
	m_clientProc.Param = Param;
	m_recvThread = nullptr;
}

TCP::~TCP()
{
	WSACleanup();
	closesocket(m_sockServer);
	m_isClose = true;
	if (m_recvThread != nullptr)
	{
		m_recvThread->join();
		delete m_recvThread;
		m_recvThread = nullptr;
	}
}

bool Net::TCP::ConnectSever(std::string ServerIp, unsigned long port)
{
	m_isClose = false;
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		m_Error = "Fail to initialize network.";
		return false;
	}
	m_sockServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sockServer == INVALID_SOCKET)
	{
		m_Error = "Fail to get socket.";
		return false;
	}
	SOCKADDR_IN sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.S_un.S_addr = inet_addr(ServerIp.c_str());
	sockAddr.sin_port = htons(port);
	if (connect(m_sockServer, (SOCKADDR*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
	{
		m_Error = "Fail to connect to server.";
		return false;
	}
	m_recvThread = new thread{ &TCP::DoServerMsg,this };
	return true;
}

bool Net::TCP::SendMsg(const char * buff, unsigned int len)
{
	if (send(m_sockServer, buff, len, 0) == SOCKET_ERROR)
	{
		m_Error = "Fail to send message to server.";
		return false;
	}
	else
	{
		return true;
	}
}

const std::string & Net::TCP::GetLastError()
{
	return m_Error;
}

void Net::TCP::DoServerMsg()
{
	while (true)
	{
		if (m_isClose == true)
		{
			break;
		}
		char buff[BUF_SIZE] = { 0 };
		int iRet = recv(m_sockServer, buff, sizeof(buff), 0);
		if (iRet == 0 || iRet == SOCKET_ERROR)
		{
			printf("Connection lost.");
			if (m_clientProc.func != NULL)
			{
				m_clientProc.func(CLOSE_MESSAGE, this, m_clientProc.Param);
			}
			break;
		}
		else
		{
			if (m_clientProc.func != NULL)
			{
				m_clientProc.func(buff, this, m_clientProc.Param);
			}
		}
	}
}