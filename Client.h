#include <boost/asio.hpp>
#include <vector>
#include <string>
#include<thread>
using namespace boost::asio;
enum CommandType { connection , heroInform, attackInform, clickInform, exitConnect };
class command
{
public:
	bool judge;       
	int command_type;    
	bool connection;     
	int hero_type;       
	bool hero_attack;    
	float click_x;        
	float click_y;
	int player_type;    
	command() :use_flag(false), command_type(-1), connection(false), hero_type(-1), hero_attack(false), click_x(0.0), click_y(0.0), player_type(0) {}
};
#endif
class Client
{
private:
	Client();
	~Client();
	Client& operator=(const Client &) = delete;
	static Client *instance;
	io_service io;
	ip::tcp::endpoint ep; 
	std::shared_ptr<ip::tcp::socket> sock;  
public:
	bool isConnected; 
	static Client* getInstance(); 
	bool connectWithServer();
	bool checkConnect();   
	                     
	void sendOwnHero(int hero_role); 
	command receiveHero();   
	void sendAttack(); 
	void sendClickPos(float x, float y);
	std::vector<command> getCommands(); 
	void clear();         
	void destory();
};
#endif
