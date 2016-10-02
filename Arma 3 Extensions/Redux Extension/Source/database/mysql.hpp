#ifndef SOURCE_MYSQL_HPP_
#define SOURCE_MYSQL_HPP_

#include <string>
#include <mysql.h>
#include <map>
#include <queue>
#include <vector>

class db_handler {
	// https://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html
public:
	db_handler();
	~db_handler();

	void connect(std::string hostname, std::string user, std::string password, std::string database, unsigned int port,
			std::string worlduuid);
	void rawquery(std::string query);
	void rawquery(std::string query, MYSQL_RES **result);

	std::string querydbversion();
	std::vector<std::vector<std::string> > verbosetest(std::string query);

	std::string loadPlayer(std::string nickname, std::string steamid);
	std::string loadAvChars(std::string playeruuid);
	std::string linkChars(std::string playeruuid, std::string variabuuid);
	std::string loadChar(std::string playeruuid);
	std::string createChar(std::string playeruuid, std::string animationstate, float direction, int positiontype,
			float positionx, float positiony, float positionz, std::string classname, std::string hitpoints,
			std::string variables, std::string persistentvariables, std::string textures, std::string inventoryuniform,
			std::string inventoryvest, std::string inventorybackpack, std::string uniform, std::string vest,
			std::string backpack, std::string headgear, std::string googles, std::string primaryweapon,
			std::string secondaryweapon, std::string handgun, std::string tools, std::string currentweapon);
	std::string updateChar(std::string charuuid, std::string animationstate, float direction, int positiontype,
			float positionx, float positiony, float positionz, std::string classname, std::string hitpoints,
			std::string variables, std::string persistentvariables, std::string textures, std::string inventoryuniform,
			std::string inventoryvest, std::string inventorybackpack, std::string uniform, std::string vest,
			std::string backpack, std::string headgear, std::string googles, std::string primaryweapon,
			std::string secondaryweapon, std::string handgun, std::string tools, std::string currentweapon);
	std::string locupdateChar(std::string charuuid, std::string animationstate, float direction, int positiontype,
			float positionx, float positiony, float positionz);

	std::string loadObject(std::string objectuuid);
	std::string createObject(std::string classname, int priority, int visible, std::string accesscode, int locked,
			std::string player_uuid, std::string hitpoints, float damage, float fuel, float fuelcargo,
			float repaircargo, std::string items, std::string magazines, std::string weapons, std::string backpacks,
			std::string magazinesturret, std::string variables, std::string animationstate, std::string textures,
			float direction, int positiontype, float positionx, float positiony, float positionz);
	std::string updateObject(std::string objectuuid, std::string classname, int priority, int visible,
			std::string accesscode, int locked, std::string player_uuid, std::string hitpoints, float damage,
			float fuel, float fuelcargo, float repaircargo, std::string items, std::string magazines,
			std::string weapons, std::string backpacks, std::string magazinesturret, std::string variables,
			std::string animationstate, std::string textures, float direction, int positiontype, float positionx,
			float positiony, float positionz);
	std::vector<std::vector<std::string> > dumpObjects();

private:
		MYSQL *connection;
		std::string hostname;
		std::string user;
		std::string password;
		std::string database;
		unsigned int port;
		std::string socket;
		unsigned long int flag;
		std::string worlduuid;
};

#endif /* SOURCE_MYSQL_HPP_ */
