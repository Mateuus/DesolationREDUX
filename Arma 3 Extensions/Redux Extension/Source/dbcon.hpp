#ifndef SOURCE_DBCON_HPP_
#define SOURCE_DBCON_HPP_

#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <boost/mem_fn.hpp>

class dbcon {
public:
	dbcon();
	~dbcon();
	std::string processDBCall(boost::property_tree::ptree &dbcall);

private:
	typedef boost::function<
			std::string(boost::property_tree::ptree &dbarguments)> DB_FUNCTION;
	typedef std::map<std::string, DB_FUNCTION> DB_FUNCTIONS;
	DB_FUNCTIONS dbfunctions;

	std::string getUUID(boost::property_tree::ptree &dbarguments);

};

#endif /* SOURCE_DBCON_HPP_ */
