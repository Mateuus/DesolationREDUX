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
}
class CfgFunctions
{
	class DB
	{
		class Database 
		{
			file = "DesoDB\Database";
			isserver = 1;
			class sendRequest {};
		};
		class Functions 
		{
			file = "DesoDB\Functions";
			isserver = 1;
			class spawnCharacter {};
                        class spawnAllObjects {};
		};
	};
};