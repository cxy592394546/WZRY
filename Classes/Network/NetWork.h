#ifndef NETWORK_H_
#define NETWORK_H_
#include"HandleEvent.h"

using NetMsg = Json::Value;

class NetWorkManager
{
	GET_SINGLE_OBJECT(NetWorkManager);
public:
	NetWorkManager(const NetWorkManager&) = delete;
	NetWorkManager& operator=(const NetWorkManager&) = delete;

	Slot* add(const int& messageId, const EventHandler& evHandler);

	Slot* add(const int& messageId, const std::function<void(Json::Value&)>&);

	void dispatch(const int& messageId, Json::Value& message);

	void send(const int& messageId, const std::map<std::string, std::string>& msg);

	void send(const int& messageId, Json::Value& msg);
private:
	NetWorkManager() {}
	~NetWorkManager() {}
	std::map<int, Signal> m_signals;

	SINGLE_ATTRIBUTES(NetWorkManager);
};

#endif // !__NET_WORK_MANAGER_H__

