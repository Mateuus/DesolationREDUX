#include <iostream>
#include <sstream>
#include <string>

void RVExtension(char *output, int outputSize, const char *function);

int main(int argc, char *argv[])
{
    char output[1024];
    const char function[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"uid\", \"dbarguments\": {  \"lool\": \"lustig\" } } }";
    RVExtension(output, 1024, function);
    std::cout << output << std::endl;

    const char function2[] = "{ \"dllfunction\": \"dall\", \"dllarguments\": {  \"dbfunction\": \"uid\", \"dbarguments\": {  \"lool\": \"lustig\" } } }";
    RVExtension(output, 1024, function2);
    std::cout << output << std::endl;

    return 0;
}
