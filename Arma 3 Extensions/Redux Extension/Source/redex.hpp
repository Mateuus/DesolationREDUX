#ifndef SOURCE_REDEX_HPP_
#define SOURCE_REDEX_HPP_

#include <string>
#include <map>
#include <queue>
#include <mutex>
#include <boost/property_tree/ptree.hpp>
#include <boost/function.hpp>
#include "constants.hpp"
#include "dbcon.hpp"

class redex {
public:
	redex();
	~redex();
	std::string processCallExtension(const char *function, int outputSize);

private:
	typedef boost::function<
			std::string(boost::property_tree::ptree &dbarguments)> DLL_FUNCTION;
	typedef std::map<std::string, DLL_FUNCTION> DLL_FUNCTIONS;
	DLL_FUNCTIONS dllfunctions;
	dbcon dbconnection;

	std::mutex msgmutex;
	typedef std::map<PROTOCOL_IDENTIFIER_DATATYPE, std::queue<std::string>> MESSAGE_MAP;
	MESSAGE_MAP msgmap;

	std::string dbcall(boost::property_tree::ptree &dllarguments);
	std::string rcvmsg(boost::property_tree::ptree &dllarguments);
	std::string chkmsg(boost::property_tree::ptree &dllarguments);

	std::string multipartMSGGenerator(std::string returnString, int outputSize);
};

#endif /* SOURCE_REDEX_HPP_ */
