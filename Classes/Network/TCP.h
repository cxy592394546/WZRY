#ifndef TCP_H_
#define TCP_H_

#include<string>
#include<thread>
#include<WinSock2.h>
#include<exception>

char CLOSE_MESSAGE[16]= "~#@**close**@#~";

constexpr int PORT = 23333;
constexpr int BUF_SIZE = 1024;


namespace Net
{
	class TCP;
	typedef void(*ClientFunc)(const char* buff, TCP* pClient, LPVOID Param);

	typedef struct ClientSt
	{
		ClientFunc func;
		LPVOID Param;
	};

	class TCP
	{
	public:
		TCP();
		virtual ~TCP();
		explicit TCP(ClientFunc clientProc, LPVOID Param = NULL);
		TCP(const TCP& src) = delete;
		TCP& operator=(const TCP& src) = delete;
		bool ConnectSever(std::string ServerIp, unsigned long port = PORT);
		bool SendMsg(const char* buff, unsigned int len);
		const std::string& GetLastError();
	private:
		void DoServerMsg();
		SOCKET m_sockServer;
		std::string m_Error;
		ClientSt m_clientProc;
		std::thread* m_recvThread;
		bool m_isClose;
	};
}

#endif // !TCP_H_