#include "database/mysql.hpp"

db_handler::db_handler() {
	driver = get_driver_instance();
	connection = 0;
	statement = 0;
	result = 0;
}

db_handler::~db_handler() {
	return;
}

void db_handler::connect(std::string hostname, std::string user, std::string password, std::string database) {
	if (connection == 0) {
		connection = driver->connect(hostname, user, password);
		connection->setSchema(database);
	} else {
		if (!connection->isValid()) {
			connection->reconnect();
		}
	}
}
