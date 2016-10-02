#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "../constants.hpp"
#include "utils/uuid.hpp"
#include <unistd.h>
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

void RVExtension(char *output, int outputSize, const char *function);

std::string randomstring(int length) {
	std::stringstream returnstring;
	std::string chars("abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"1234567890");
	boost::random::random_device rng;
	boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);
	for (int i = 0; i < length; ++i) {
		returnstring << chars[index_dist(rng)];
	}

	return returnstring.str();
}

std::string randomsteamid() {
	std::stringstream returnstring;
	std::string chars("1234567890");
	boost::random::random_device rng;
	boost::random::uniform_int_distribution<> index_dist(0, chars.size() - 1);
	for (int i = 0; i < 17; ++i) {
		returnstring << chars[index_dist(rng)];
	}

	return returnstring.str();
}

int main(int argc, char *argv[])
{
	std::string uuid;
	std::string functionstring;
	std::string playeruuid;
    char output[1024];
    const char function[] = "{ 'dllfunction': 'initdb', 'dllarguments': {  'poolsize': 4, 'worlduuid': '11e66ac33a4ccd1c82c510bf48883ace' } }";

    std::cout << "trying to spawn 4 threads" << std::endl;
    std::cout << "JSON: " << function << std::endl;
    RVExtension(output, 1024, function);
    std::cout << output << std::endl  << std::endl << std::endl;

    usleep(500);

    functionstring = "{ 'dllfunction': 'dbcall', 'dllarguments': {  'dbfunction': 'loadPlayer', 'dbarguments': { 'nickname': '";
    functionstring += randomstring(6) + "', 'steamid': '";
    functionstring += randomsteamid() + "'  } } }";

	std::cout << "loading player data" << std::endl;
	std::cout << "JSON: " << functionstring.c_str() << std::endl;
	RVExtension(output, 1024, functionstring.c_str());
	std::cout << output << std::endl ;

	playeruuid = output;
	playeruuid = playeruuid.substr(10, 32);
	std::cout << "PLAYERUUID: " << playeruuid << std::endl  << std::endl << std::endl;

	usleep(500);

	functionstring = "{ 'dllfunction': 'dbcall', 'dllarguments': {  'dbfunction': 'createChar', 'dbarguments': { 'playeruuid': '";
	functionstring += playeruuid + "', 'animationstate': 'VAR_ANIMATIONSTATE',  'direction': '23.5', 'positiontype': '0', 'positionx': '21.42', 'positiony': '666.9', 'positionz': '133.7', 'classname': 'sampleclass', 'hitpoints': '[]', 'variables': '[]', 'persistentvariables': '[]', 'textures': '[]', 'inventoryuniform': '[]', 'inventoryvest': '[]', 'inventorybackpack': '[]', 'uniform': 'someuniform', 'vest': 'somevest', 'backpack': 'somebackpack', 'headgear': 'someheadgear', 'googles': 'somegoogles', 'primaryweapon': '[\"someprimaryweapon\", [\"someattachment\"]]', 'secondaryweapon': '[\"somesecondaryweapon\", [\"someattachment\"]]', 'handgun': '[\"somehandgunweapon\", [\"someattachment\"]]', 'tools': '[]', 'currentweapon': 'someprimaryweapon' } } }";

	std::cout << "loading player data" << std::endl;
	std::cout << "JSON: " << functionstring.c_str() << std::endl;
	RVExtension(output, 1024, functionstring.c_str());
	std::cout << output << std::endl ;

    return 0;
}
