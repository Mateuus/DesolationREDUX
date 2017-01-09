#include "constants.hpp"

class CfgPatches
{
	class DesoDB {};
};

class Plugins
{
	class DesoDB
	{
		name = "DesoDB";
		desc = "Desolation Redux's custom Database connection plugin";
		tag = "DB";
	};
};

class CfgFunctions
{
	class DB
	{
		class Core 
		{
			file = "DesoDB";
			isserver = 1;
			class initServer {};
		};
		class Database 
		{
			file = "DesoDB\Database";
			isserver = 1;
			class sendRequest {};
			class buildDLLRequest {};
			class buildDBRequest {};
			class buildIORequest {};
			class buildRequest {};
		};
		class Functions 
		{
			file = "DesoDB\Functions";
			isserver = 1;
			class getWorldUUID {};
			class getPoolSize {};
		};
	};
};