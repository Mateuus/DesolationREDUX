#ifndef SOURCE_DBCON_HPP_
#define SOURCE_DBCON_HPP_

#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/tss.hpp>

#include "database/mysql.hpp"
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

	boost::asio::io_service DBioService;
	boost::thread_group threadpool;
	boost::mutex dbmutex;
	boost::thread_specific_ptr<int> threadpointer;

	std::string getUUID(boost::property_tree::ptree &dbarguments);
	std::string echo(boost::property_tree::ptree &dbarguments);

};

class db_io_service : public boost::asio::io_service
  {
    boost::thread_specific_ptr<db_handler> driver;

    std::size_t run()
    {
      if(driver.get() == 0)
    	  driver.reset(new db_handler);

      return boost::asio::io_service::run();
    }
  };

#endif /* SOURCE_DBCON_HPP_ */
