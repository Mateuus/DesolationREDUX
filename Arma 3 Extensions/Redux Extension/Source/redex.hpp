#ifndef SOURCE_REDEX_HPP_
#define SOURCE_REDEX_HPP_

#include <string>
#include "dbcon.hpp"

class redex
{
  public:
	redex();
	~redex();
	std::string processCallExtension(const char *function);

  private:
	std::string returnStringGenerator();
	dbcon dbconnection;

};

#endif /* SOURCE_REDEX_HPP_ */
