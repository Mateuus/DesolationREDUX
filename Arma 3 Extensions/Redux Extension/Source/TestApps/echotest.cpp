#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "../constants.hpp"

void RVExtension(char *output, int outputSize, const char *function);

int main(int argc, char *argv[])
{
	std::string uuid;
	std::string functionstring;
    char output[128];
    const char function[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"echo\", \"dbarguments\": {  \"echostring\": \"The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.\" } } }";
    RVExtension(output, 128, function);

    uuid = output;
    uuid = uuid.substr(11, 32);
    std::cout << "FOUND UUID: " << uuid << std::endl;

    std::cout << output << std::endl;

    while (strncmp(output, PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG, 20) != 0) {
    	functionstring = "{ \"dllfunction\": \"rcvmsg\", \"dllarguments\": {  \"msguuid\": \"";
    	functionstring += uuid;
		functionstring += "\" } }";
		RVExtension(output, 128, functionstring.c_str());
		std::cout << output << std::endl;
	}

    return 0;
}
