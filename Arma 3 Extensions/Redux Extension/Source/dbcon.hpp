#ifndef SOURCE_DBCON_HPP_
#define SOURCE_DBCON_HPP_

#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/thread/thread.hpp>
#include "constants.hpp"

class dbcon {
public:
	dbcon(unsigned int threadcount);
	dbcon() : dbcon(DEFAULT_THREAD_COUNT) {};
	//dbcon();
	~dbcon();
	std::string processDBCall(boost::property_tree::ptree &dbcall);

private:
	typedef boost::function<
			std::string(boost::property_tree::ptree &dbarguments)> DB_FUNCTION;
	typedef std::map<std::string, DB_FUNCTION> DB_FUNCTIONS;
	DB_FUNCTIONS dbfunctions;

	//boost::asio::io_service DBioService;
	boost::thread_group threadpool;

	std::string getUUID(boost::property_tree::ptree &dbarguments);
	std::string echo(boost::property_tree::ptree &dbarguments);

};

#endif /* SOURCE_DBCON_HPP_ */
