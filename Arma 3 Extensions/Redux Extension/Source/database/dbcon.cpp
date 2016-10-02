#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>

#include "database/dbcon.hpp"
#include "utils/uuid.hpp"

dbcon::dbcon() {
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_UUID),
					std::make_tuple(boost::bind(&dbcon::getUUID, this, _1, _2), HANDLELESS_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING),
					std::make_tuple(boost::bind(&dbcon::echo, this, _1, _2), HANDLELESS_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_DB_VERSION),
					std::make_tuple(boost::bind(&dbcon::dbVersion, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_DEBUG_CALL),
					std::make_tuple(boost::bind(&dbcon::debugCall, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_LOAD_PLAYER),
					std::make_tuple(boost::bind(&dbcon::loadPlayer, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_AV_CHARS),
					std::make_tuple(boost::bind(&dbcon::loadAvChars, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_LINK_CHARS),
					std::make_tuple(boost::bind(&dbcon::linkChars, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_LOAD_CHAR),
					std::make_tuple(boost::bind(&dbcon::loadChar, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_CREATE_CHAR),
					std::make_tuple(boost::bind(&dbcon::createChar, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_UPDATE_CHAR),
					std::make_tuple(boost::bind(&dbcon::updateChar, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_LOCATIONUPDATE_CHAR),
					std::make_tuple(boost::bind(&dbcon::locupdateChar, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_LOAD_OBJECT),
					std::make_tuple(boost::bind(&dbcon::loadObject, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_CREATE_OBJECT),
					std::make_tuple(boost::bind(&dbcon::createObject, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_UPDATE_OBJECT),
					std::make_tuple(boost::bind(&dbcon::updateObject, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_DUMP_OBJECTS),
					std::make_tuple(boost::bind(&dbcon::dumpObjects, this, _1, _2), SYNC_MAGIC)));

	boost::asio::io_service::work work(DBioService);

	return;
}

dbcon::~dbcon() {
	asyncthreadpool.join_all();
	return;
}

int dbcon::spawnHandler(unsigned int poolsize, std::string worlduuid) {
	if (poolsize < 1) {
		poolsize = 1;
	}

	if (!poolinitialized) {
		int i;
		std::string hostname;
		std::string user;
		std::string password;
		std::string database;
		unsigned int port = 0;
		db_handler *syncdbhandler;
		boost::property_tree::ptree configtree;
		boost::property_tree::ini_parser::read_ini("redex.ini", configtree);

		hostname = configtree.get<std::string>("dbhostname");
		user = configtree.get<std::string>("dbuser");
		password = configtree.get<std::string>("dbpassword");
		database = configtree.get<std::string>("database");
		port = configtree.get<unsigned int>("dbport");

		if (!syncdbhandlerpool.is_lock_free()) {
			throw std::runtime_error("syncdbhandlerpool is not lock free");
		}

		syncdbhandlerpool.reserve(poolsize + 1);
		for (i = 0; i < poolsize; i++) {
			syncdbhandler = new (db_handler);
			syncdbhandler->connect(hostname, user, password, database, port, worlduuid);
			syncdbhandlerpool.bounded_push((intptr_t) syncdbhandler);
		}

		// tempsyncdbhandler.connect(hostname, user, password, database, port, worlduuid);

		/* commented until async is needed
		DBioService.set_dbinfos(hostname, user, password, database, port, worlduuid);
		for (i = 0; i < poolsize; i++) {
			asyncthreadpool.create_thread(
					boost::bind(&dbcon_io_service::run, &DBioService)
			);
		}
		*/
		poolinitialized = true;
	} else {
		throw std::runtime_error("Threads already spawned");
	}

	return asyncthreadpool.size();
}

std::string dbcon::processDBCall(boost::property_tree::ptree &dbcall) {
	std::string returnString;

	std::string dbfunction = dbcall.get<std::string>("dbfunction");
	boost::property_tree::ptree &dbarguments = dbcall.get_child("dbarguments");

	DB_FUNCTIONS::iterator it = dbfunctions.find(dbfunction);
	if (it != dbfunctions.end()) {
		DB_FUNCTION_INFO funcinfo = it->second;

		switch (std::get<1>(funcinfo))
		{
		case SYNC_MAGIC:
			returnString = syncCall(funcinfo, dbarguments);
			break;

		case ASYNC_MAGIC:
			returnString = asyncCall(funcinfo, dbarguments);
			break;

		case HANDLELESS_MAGIC:
			returnString = handlelessCall(funcinfo, dbarguments);
			break;

		default:
			throw std::runtime_error("unknown function class");
		}
	} else {
		throw std::runtime_error("Don't know dbfunction: " + dbfunction);
	}

	return returnString;
}

std::string dbcon::syncCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments) {
	const DB_FUNCTION &func(std::get<0>(funcinfo));
	std::string returnString;

	intptr_t syncdbhandlerpointer;
	db_handler *syncdbhandler;

	std::string version;

	if (poolinitialized) {

		// try to get an db handler
		while (!syncdbhandlerpool.pop(syncdbhandlerpointer)) {
			printf("i am in a loop! :( \n");
		}
		try {
			//	syncdbhandler = &tempsyncdbhandler;
			syncdbhandler = (db_handler*) syncdbhandlerpointer;

			returnString = func(dbarguments, syncdbhandler);

			// return handler to the pool
			syncdbhandlerpool.bounded_push(syncdbhandlerpointer);
		} catch (std::exception const& e) {
			// allways return the handler
			syncdbhandlerpool.bounded_push(syncdbhandlerpointer);
			throw std::runtime_error(e.what());
		}
	} else {
		throw std::runtime_error("db handler pool not initialized");
	}

	return returnString;
}

std::string dbcon::asyncCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments) {
	return this->syncCall(funcinfo, dbarguments);
}

std::string dbcon::handlelessCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments) {
	const DB_FUNCTION &func(std::get<0>(funcinfo));
	return func(dbarguments, NULL);
}

std::string dbcon::getUUID(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + orderedUUID() + "\"]";
}

std::string dbcon::echo(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string echostring = dbarguments.get<std::string>("echostring");
	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + echostring + "\"]";
}

std::string dbcon::debugCall(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string matrix;
	bool placecommaone = false;
	bool placecommatwo = false;

	//std::vector< std::vector<std::string> > resultmatrix = dbhandler->verbosetest("SELECT hex(uuid), classname, priority, timelastused, timecreated, visible, accesscode, locked, hex(player_uuid), hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz FROM `object` WHERE player_uuid = CAST(0x11E66B045F432626B28510BF48883ACE AS BINARY) OR player_uuid = CAST(0x11E66ABC1942138D82C510BF48883ACE AS BINARY)");
	std::vector< std::vector<std::string> > resultmatrix = dbhandler->verbosetest("SELECT hex(uuid), classname, priority, UNIX_TIMESTAMP(timelastused), UNIX_TIMESTAMP(timecreated), visible, accesscode, locked, hex(player_uuid), hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz FROM `object`");
	matrix = "[";
	for (auto& row : resultmatrix) {
		matrix += "[";
		if (placecommaone) {
			matrix += ",";
		}
		placecommatwo = false;
		for (auto& value : row) {
			if (placecommatwo) {
				matrix += ", ";
			}
			//matrix += "\"" + value + "\"";
			matrix += value;
			placecommatwo = true;
		}
		matrix += "]";
		placecommaone = true;
	}
	matrix += "]";

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", " + matrix + "]";
}


std::string dbcon::dbVersion(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string version;

	version = dbhandler->querydbversion();

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + version + "\"]";
}



std::string dbcon::loadPlayer(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string nickname = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_NICKNAME);
	std::string steamid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_STEAMID);
	std::string playerinfo = dbhandler->loadPlayer(nickname, steamid);

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", " + playerinfo + "]";
}

std::string dbcon::loadAvChars(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string playeruuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PLAYERUUID);

	std::string result = dbhandler->loadAvChars(playeruuid);

	return result;
}

std::string dbcon::linkChars(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string playeruuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PLAYERUUID);
	std::string variabuuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VARIABUUID);

	std::string result = dbhandler->linkChars(playeruuid, variabuuid);

	return result;
}

std::string dbcon::loadChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string playeruuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PLAYERUUID);

	std::string result = dbhandler->loadChar(playeruuid);

	return result;
}

std::string dbcon::createChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string playeruuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PLAYERUUID);
	std::string animationstate = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE);
	float direction = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DIRECTION);
	int positiontype = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE);
	float positionx = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONX);
	float positiony = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONY);
	float positionz = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONZ);
	std::string classname = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CLASSNAME);
	std::string hitpoints = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_HITPOINTS);
	std::string variables = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VARIABLES);
	std::string persistentvariables = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES);
	std::string textures = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_TEXTURES);
	std::string inventoryuniform = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_INVENTORYUNIFORM);
	std::string inventoryvest = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST);
	std::string inventorybackpack = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK);
	std::string uniform = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_UNIFORM);
	std::string vest = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VEST);
	std::string backpack = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_BACKPACK);
	std::string headgear = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_HEADGEAR);
	std::string googles = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_GOOGLES);
	std::string primaryweapon = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON);
	std::string secondaryweapon = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON);
	std::string tools = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_TOOLS);
	std::string currentweapon = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON);

	std::string result = dbhandler->createChar(playeruuid, animationstate, direction, positiontype, positionx,
			positiony, positionz, classname, hitpoints, variables, persistentvariables, textures, inventoryuniform,
			inventoryvest, inventorybackpack, uniform, vest, backpack, headgear, googles, primaryweapon,
			secondaryweapon, tools, currentweapon);

	return result;
}

std::string dbcon::updateChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string charuuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CHARUUID);
	std::string animationstate = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE);
	float direction = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DIRECTION);
	int positiontype = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE);
	float positionx = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONX);
	float positiony = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONY);
	float positionz = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONZ);
	std::string classname = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CLASSNAME);
	std::string hitpoints = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_HITPOINTS);
	std::string variables = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VARIABLES);
	std::string persistentvariables = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES);
	std::string textures = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_TEXTURES);
	std::string inventoryuniform = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_INVENTORYUNIFORM);
	std::string inventoryvest = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST);
	std::string inventorybackpack = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK);
	std::string uniform = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_UNIFORM);
	std::string vest = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VEST);
	std::string backpack = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_BACKPACK);
	std::string headgear = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_HEADGEAR);
	std::string googles = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_GOOGLES);
	std::string primaryweapon = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON);
	std::string secondaryweapon = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON);
	std::string tools = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_TOOLS);
	std::string currentweapon = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON);

	std::string result = dbhandler->updateChar(charuuid, animationstate, direction, positiontype, positionx,
				positiony, positionz, classname, hitpoints, variables, persistentvariables, textures, inventoryuniform,
				inventoryvest, inventorybackpack, uniform, vest, backpack, headgear, googles, primaryweapon,
				secondaryweapon, tools, currentweapon);

	return result;
}

std::string dbcon::locupdateChar(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string charuuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CHARUUID);
	std::string animationstate = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE);
	float direction = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DIRECTION);
	int positiontype = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE);
	float positionx = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONX);
	float positiony = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONY);
	float positionz = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONZ);

	std::string result = dbhandler->locupdateChar(charuuid, animationstate, direction, positiontype, positionx,
					positiony, positionz);

	return result;
}

std::string dbcon::loadObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string objectuuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID);

	std::string result = dbhandler->loadObject(objectuuid);

	return result;
}

std::string dbcon::createObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string classname = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CLASSNAME);
	int priority = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_PRIORITY);
	int visible = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_VISIBLE);
	std::string accesscode = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE);
	int locked = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_LOCKED);
	std::string player_uuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID);
	std::string hitpoints = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_HITPOINTS);
	float damage = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DAMAGE);
	float fuel = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_FUEL);
	float fuelcargo = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_FUELCARGO);
	float repaircargo = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO);
	std::string items = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ITEMS);
	std::string magazines = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_MAGAZINES);
	std::string weapons = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_WEAPONS);
	std::string backpacks = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_BACKPACKS);
	std::string magazinesturret = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET);
	std::string variables = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VARIABLES);
	std::string animationstate = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE);
	std::string textures = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_TEXTURES);
	float direction = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DIRECTION);
	int positiontype = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE);
	float positionx = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONX);
	float positiony = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONY);
	float positionz = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONZ);

	std::string result = dbhandler->createObject(classname, priority, visible, accesscode, locked, player_uuid,
			hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret,
			variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz);

	return result;
}

std::string dbcon::updateObject(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string objectuuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID);
	std::string classname = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_CLASSNAME);
	int priority = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_PRIORITY);
	int visible = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_VISIBLE);
	std::string accesscode = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE);
	int locked = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_LOCKED);
	std::string player_uuid = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID);
	std::string hitpoints = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_HITPOINTS);
	float damage = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DAMAGE);
	float fuel = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_FUEL);
	float fuelcargo = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_FUELCARGO);
	float repaircargo = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO);
	std::string items = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ITEMS);
	std::string magazines = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_MAGAZINES);
	std::string weapons = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_WEAPONS);
	std::string backpacks = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_BACKPACKS);
	std::string magazinesturret = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET);
	std::string variables = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_VARIABLES);
	std::string animationstate = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE);
	std::string textures = dbarguments.get<std::string>(PROTOCOL_DBCALL_ARGUMENT_TEXTURES);
	float direction = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_DIRECTION);
	int positiontype = dbarguments.get<int>(PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE);
	float positionx = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONX);
	float positiony = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONY);
	float positionz = dbarguments.get<float>(PROTOCOL_DBCALL_ARGUMENT_POSITIONZ);

	std::string result = dbhandler->updateObject(objectuuid, classname, priority, visible, accesscode, locked,
			player_uuid, hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks,
			magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony,
			positionz);

	return result;
}

std::string dbcon::dumpObjects(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
        std::string matrix;
        bool placecommaone = false;
        bool placecommatwo = false;

        //std::vector< std::vector<std::string> > resultmatrix = dbhandler->verbosetest("SELECT hex(uuid), classname, priority, timelastused, timecreated, visible, accesscode, locked, hex(player_uuid), hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz FROM `object` WHERE player_uuid = CAST(0x11E66B045F432626B28510BF48883ACE AS BINARY) OR player_uuid = CAST(0x11E66ABC1942138D82C510BF48883ACE AS BINARY)");
        std::vector< std::vector<std::string> > resultmatrix = dbhandler->dumpObjects();
        matrix = "[";
        for (auto& row : resultmatrix) {
                if (placecommaone) {
                        matrix += ",";
                }
                matrix += "[";
                placecommatwo = false;
                for (auto& value : row) {
                        if (placecommatwo) {
                                matrix += ", ";
                        }
                        //matrix += "\"" + value + "\"";
                        matrix += value;
                        placecommatwo = true;
                }
                matrix += "]";
                placecommaone = true;
        }
        matrix += "]";

        return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", " + matrix + "]";
}
