#include <exception>
#include <stdexcept>
#include "database/mysql.hpp"

db_handler::db_handler() {
	this->hostname = NULL;
	this->user = NULL;
	this->password = NULL;
	this->database = NULL;
	this->port = 0;
	this->socket = NULL;
	this->flag = 0;

	connection = mysql_init(NULL);

	if (connection == NULL) {
		throw std::runtime_error("problem while initializing db_handler: " + std::string(mysql_error(connection)));
	}
}

db_handler::~db_handler() {
	mysql_close(connection);
	return;
}

void db_handler::connect(std::string hostname, std::string user, std::string password, std::string database, unsigned int port) {
	this->hostname = hostname.c_str();
	this->user = user.c_str();
	this->password = password.c_str();
	this->database = database.c_str();
	this->port = port;
//	this->socket = NULL;
//	this->flag = 0;

	if (mysql_real_connect(connection, this->hostname, this->user,
			this->password, this->database, this->port, this->socket, this->flag) == NULL) {
		throw std::runtime_error("connection problem while initializing db_handler: " + std::string(mysql_error(connection)));
		mysql_close(connection);
	} else {
		printf("created connection \n");
	}

	return;
}

void db_handler::rawquery(std::string query, MYSQL_RES **result) {
	if (mysql_query(connection, query.c_str())) {
		throw std::runtime_error(
				"error while executing query: "
						+ std::string(mysql_error(connection)));
	}

	*result = mysql_store_result(connection);

	if (*result == NULL) {
		throw std::runtime_error(
				"error while getting the result: "
						+ std::string(mysql_error(connection)));
	}

	printf("fieldcount %d \n", mysql_num_fields(*result));
	return;
}

std::string db_handler::querydbversion() {
	MYSQL_RES *result;
	MYSQL_ROW row = 0;
	std::string version;

	this->rawquery("SELECT VERSION()", &result);

	row = mysql_fetch_row(result);
	//fieldcount = mysql_num_fields(*result);
	version = row[0];

	mysql_free_result(result);

	return version;
}

