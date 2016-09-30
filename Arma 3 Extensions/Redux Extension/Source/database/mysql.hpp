#ifndef SOURCE_MYSQL_HPP_
#define SOURCE_MYSQL_HPP_

#include <string>
#include <mysql.h>

class db_handler {
	// https://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
public:
	db_handler();
	~db_handler();

	void connect(std::string hostname, std::string user, std::string password, std::string database, unsigned int port);
	void rawquery(std::string query, MYSQL_RES **result);
	std::string querydbversion();

private:
		MYSQL *connection;
		const char *hostname;
		const char *user;
		const char *password;
		const char *database;
		unsigned int port;
		const char *socket;
		unsigned long int flag;
};

#endif /* SOURCE_MYSQL_HPP_ */
