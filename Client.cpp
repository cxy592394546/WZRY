#include "Client.h"
Client::Client():io(),ep(ip::address::from_string("127.0.0.1"), 6688),message_ep(ip::address::from_string("127.0.0.1"), 5566),\
sock(nullptr),message_sock(nullptr){}
Client* Client::getInstance()
{
	if (instance == nullptr)
		instance = new Client();
	return instance;
}
bool Client::checkConnect()
{
	while (true)
	{
		if (sock->available()) {
			std::vector<command> buf(1);
			sock->read_some(buffer(buf));
			if (buf[0].command_type == connection && buf[0].connected == true) 
				return true;
			else return false;
		}
	}
}
bool Client::connectWithServer()
{
	try
	{
		if(sock==nullptr)
		sock = std::make_shared<ip::tcp::socket>(io);
		sock->connect(ep);
		if(message_sock==nullptr)
		message_sock = std::make_shared<ip::tcp::socket>(io);
		message_sock->connect(message_ep);
		isConnected = true;
		return true;
	}
	catch (std::exception& e)
	{
		sock = nullptr;
		message_sock = nullptr;
		isConnected = false;
		return false;
	}
}
void Client::sendOwnHero(int hero_role)
{
	std::vector<command> sends;
	command send;
	send.judge = true;
	send.command_type = 1;
	send.hero_type = hero_role;
	sends.push_back(send);
	sock->write_some(buffer(sends));
}
command Client::receiveHero()
{
	while (1)
	{
		if (sock->available()) {
			std::vector<command> buf(1);
			sock->read_some(buffer(buf));
			if (buf[0].command_type == heroInform ) return buf[0];
			else
			{
				command m;
				m.hero_type = -1;
				return m;
			}
		}
	}
}
void Client::sendAttack()
{
	std::vector<command> sends;
	command send;
	send.use_flag = true;
	send.command_type = 2;
	send.hero_attack = true;
	sends.push_back(send);
	sock->write_some(buffer(sends));
}
void Client::sendClickPos(float x,float y)
{
	std::vector<command> sends;
	command send;
	send.use_flag = true;
	send.command_type = 3;
	send.click_x = x;
	send.click_y = y;
	sends.push_back(send);
	sock->write_some(buffer(sends));
}
std::vector<command> Client::getCommands()
{
	std::vector<command> once_receives;
	if (sock->available())
	{

		std::vector<command> buf(sock->available() / sizeof(command));
		sock->read_some(buffer(buf));
		for (auto i = buf.begin(); i != buf.end(); ++i)
		{
			if (i->use_flag == false) break;
			once_receives.push_back(*i);
		}
	}
	return once_receives;
}
void Client::sendMessage(std::string &text)
{
	text += "\n";
	message_sock->write_some(buffer(text));
}
std::string Client::getMessage()
{
	auto text = std::string();
	if (message_sock->available())
	{
		
		auto buf = std::string(1, '\0');
		while (true)
		{
			message_sock->read_some(buffer(buf));
			if (*buf.begin() == '\n') break;
			text += buf;
		}
	}
	return text;
}
void Client::clear()
{
	std::vector<command> sends;
	command send;
	send.use_flag = true;
	send.command_type = 4;
	send.connection = false;
	sends.push_back(send);
	sock->write_some(buffer(sends));
	sock->close();
	sock = nullptr;
	message_sock = nullptr;
}
void Client::destory()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
