#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "../constants.hpp"
#include <unistd.h>


void RVExtension(char *output, int outputSize, const char *function);

int main(int argc, char *argv[])
{
	std::string uuid;
	std::string functionstring;
    char output[1024];
    const char function[] = "{ \"dllfunction\": \"initdb\", \"dllarguments\": {  \"poolsize\": 4 } }";
    const char function2[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"dbVersion\", \"dbarguments\": {  } } }";
    std::cout << "trying to spawn 4 threads" << std::endl;
    RVExtension(output, 1024, function);
    std::cout << output << std::endl;

    usleep(200);

    std::cout << "trying to spawn threads again! (should fail)" << std::endl;
    RVExtension(output, 1024, function);
    std::cout << output << std::endl;

    std::cout << "trying to get db version several times" << std::endl;
    for (int i = 0; i < 8; i++) {
    	RVExtension(output, 1024, function2);
    	std::cout << output << std::endl;
    }

    return 0;
}
