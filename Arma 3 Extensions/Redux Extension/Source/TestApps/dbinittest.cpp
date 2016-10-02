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
    const char function[] = "{ \"dllfunction\": \"initdb\", \"dllarguments\": {  \"poolsize\": 4, \"worlduuid\": \"11e66ac33a4ccd1c82c510bf48883ace\" } }";
    const char function2[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"dbVersion\", \"dbarguments\": {  } } }";
    const char function3[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"dbgCall\", \"dbarguments\": {  } } }";
    const char function4[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"dumpObjects\", \"dbarguments\": {  } } }";
    const char function5[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"loadPlayer\", \"dbarguments\": { \"nickname\": \"Lego\", \"steamid\": \"76561198025362180\"  } } }";
    const char function6[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"loadAvChars\", \"dbarguments\": { \"playeruuid\": \"11e66abc1942138d82c510bf48883ace\" } } }";
    const char function7[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"loadChar\", \"dbarguments\": { \"playeruuid\": \"11e66abc1942138d82c510bf48883ace\" } } }";
    const char function8[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"updateChar\", \"dbarguments\": { \"objectuuid\": \"11e66ac3076d214682c510bf48883ace\", \"animationstate\": \"VAR_ANIMATIONSTATE\",  \"direction\": \"23.5\", \"positiontype\": \"0\", \"positionx\": \"21.42\", \"positiony\": \"666.9\", \"positionz\": \"133.7\", \"classname\": \"sampleclass\", \"hitpoints\": \"[]\", \"variables\": \"[]\", \"persistentvariables\": \"[]\", \"textures\": \"[]\", \"inventoryuniform\": \"[]\", \"inventoryvest\": \"[]\", \"inventorybackpack\": \"[]\", \"uniform\": \"someuniform\", \"vest\": \"somevest\", \"backpack\": \"somebackpack\", \"headgear\": \"someheadgear\", \"googles\": \"somegoogles\", \"primaryweapon\": \"[\\\"someprimaryweapon\\\", [\\\"someattachment\\\"]]\", \"secondaryweapon\": \"[\\\"somesecondaryweapon\\\", [\\\"someattachment\\\"]]\", \"handgun\": \"[\\\"somehandgunweapon\\\", [\\\"someattachment\\\"]]\", \"tools\": \"[]\", \"currentweapon\": \"someprimaryweapon\" } } }";
    const char function9[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"locupdateChar\", \"dbarguments\": { \"objectuuid\": \"11e66ac3076d25dc82c510bf48883ace\", \"animationstate\": \"VAR_ANIMATIONSTATE\",  \"direction\": \"23.5\", \"positiontype\": \"0\", \"positionx\": \"21.42\", \"positiony\": \"666.9\", \"positionz\": \"133.7\"  } } }";
    const char function10[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"loadObject\", \"dbarguments\": { \"objectuuid\": \"11e66b045d8ced8aab0c10bf48883ace\" } } }";
    const char function11[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"updateObject\", \"dbarguments\": { \"objectuuid\": \"11e66b045d8ced8aab0c10bf48883ace\" } } }";
    const char function12[] = "{ \"dllfunction\": \"dbcall\", \"dllarguments\": {  \"dbfunction\": \"locupdateObject\", \"dbarguments\": { \"objectuuid\": \"11e66b045d8ced8aab0c10bf48883ace\" } } }";
    std::cout << "trying to spawn 4 threads" << std::endl;
    std::cout << function << std::endl;
    RVExtension(output, 1024, function);
    std::cout << output << std::endl;

    usleep(500);

    std::cout << "trying to spawn threads again! (should fail)" << std::endl;
    RVExtension(output, 1024, function);
    std::cout << output << std::endl;

    std::cout << "trying to get db version several times" << std::endl;
    std::cout << function2 << std::endl;
    for (int i = 0; i < 8; i++) {
    	RVExtension(output, 1024, function2);
    	std::cout << output << std::endl;
    }

    usleep(500);

    std::cout << "executing an debug call" << std::endl;
    std::cout << function3 << std::endl;
	RVExtension(output, 1024, function3);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << "executing dumpObjects" << std::endl;
	std::cout << function4 << std::endl;
	RVExtension(output, 1024, function4);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << "loading player data" << std::endl;
	std::cout << function5 << std::endl;
	RVExtension(output, 1024, function5);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function6 << std::endl;
	RVExtension(output, 1024, function6);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function7 << std::endl;
	RVExtension(output, 1024, function7);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function8 << std::endl;
	RVExtension(output, 1024, function8);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function9 << std::endl;
	RVExtension(output, 1024, function9);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function10 << std::endl;
	RVExtension(output, 1024, function10);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function11 << std::endl;
	RVExtension(output, 1024, function11);
	std::cout << output << std::endl;

	usleep(500);

	std::cout << function12 << std::endl;
	RVExtension(output, 1024, function12);
	std::cout << output << std::endl;

	usleep(500);


    return 0;
}
