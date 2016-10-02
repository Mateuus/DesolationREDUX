#ifndef SOURCE_DBCON_HPP_
#define SOURCE_DBCON_HPP_

#include <string>
#include <map>
#include <tuple>
#include <cstdint>
#include <boost/property_tree/ptree.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/tss.hpp>

#include "database/mysql.hpp"
#include "constants.hpp"

#include <stdio.h>

class dbcon_io_service: public boost::asio::io_service {
public:
	void set_dbinfos(std::string hostname, std::string user,
			std::string password, std::string database, unsigned int port, std::string worlduuid) {
		this->hostname = hostname;
		this->user = user;
		this->password = password;
		this->database = database;
		this->port = port;
		this->worlduuid = worlduuid;
	}

	std::size_t run() {
		if (handler.get() == 0) {
			handler.reset(new db_handler);
			handler->connect(hostname, user, password, database, port, worlduuid);
		}

		return boost::asio::io_service::run();
	}

private:
	boost::thread_specific_ptr<db_handler> handler;
	std::string hostname;
	std::string user;
	std::string password;
	std::string database;
	unsigned int port;
	std::string worlduuid;
};

class dbcon {
public:
	dbcon();
	~dbcon();
	int spawnHandler(unsigned int poolsize, std::string worlduuid);
	std::string processDBCall(boost::property_tree::ptree &dbcall);

private:
	typedef boost::function<std::string(boost::property_tree::ptree &dbarguments, db_handler *dbhandler)> DB_FUNCTION;
	typedef std::tuple<DB_FUNCTION, int> DB_FUNCTION_INFO;
	typedef std::map<std::string, DB_FUNCTION_INFO> DB_FUNCTIONS;
	DB_FUNCTIONS dbfunctions;

	bool poolinitialized = false;
	dbcon_io_service DBioService;
	boost::thread_group asyncthreadpool;
	boost::mutex dbmutex;
	boost::thread_specific_ptr<int> threadpointer;

	std::string getUUID(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string echo(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string dbVersion(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string debugCall(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);

	std::string loadPlayer(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string loadAvChars(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string linkChars(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string loadChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string createChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string updateChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string locupdateChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);

	std::string loadObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string createObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string updateObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string locupdateObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);
	std::string dumpObjects(boost::property_tree::ptree &dbarguments, db_handler *dbhandler);


	//db_handler tempsyncdbhandler;
	//boost::lockfree::queue<intptr_t, boost::lockfree::capacity<10>> syncdbhandlerpool;
	boost::lockfree::queue<intptr_t, boost::lockfree::fixed_sized<false>> syncdbhandlerpool{1};

	std::string syncCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments);
	std::string asyncCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments);
	std::string handlelessCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments);
};


#endif /* SOURCE_DBCON_HPP_ */
