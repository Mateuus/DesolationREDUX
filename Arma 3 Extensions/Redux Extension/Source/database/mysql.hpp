#ifndef SOURCE_MYSQL_HPP_
#define SOURCE_MYSQL_HPP_

#include <string>
#include <mysql.h>
#include <map>
#include <queue>
#include <vector>

class db_handler {
	// https://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
public:
	db_handler();
	~db_handler();

	void connect(std::string hostname, std::string user, std::string password, std::string database, unsigned int port, std::string worlduuid);
	void rawquery(std::string query);
	void rawquery(std::string query, MYSQL_RES **result);
	std::string querydbversion();
	std::vector< std::vector<std::string> > verbosetest(std::string query);
	std::vector< std::vector<std::string> > dumpObjects();
	std::string loadPlayer(std::string nickname, std::string steamid);

private:
		MYSQL *connection;
		std::string hostname;
		std::string user;
		std::string password;
		std::string database;
		unsigned int port;
		std::string socket;
		unsigned long int flag;
		std::string worlduuid;
};

#endif /* SOURCE_MYSQL_HPP_ */
