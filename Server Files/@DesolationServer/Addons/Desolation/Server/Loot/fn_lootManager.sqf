/*
	Desolation Redux loot manager
	by: @_Lystic

	Description: Handles loot spawning for the server & parses the config values
*/


_getCFGValue = {
	params["_entry"];
	(call compile ([_entry,"DS"] call BASE_fnc_getCfgValue));
};

if !(["SpawnLoot"] call _getCFGValue) exitWith {diag_log "<Loot Manager>: Loot spawning turned off";};


//--- Parse config entries
_buildingTypes = getArray(configFile >> "CfgItemSpawns" >> "buildingTypes");

//--- Parse User Defined Config Entries
_MinPiles = ["MinPiles"] call _getCFGValue;
_Config_Options = [];
{
	_lChance = _x + "_lootChance";
	_sChance = _x + "_spawnChance";
	_tChance = _x + "_typeChance";
	_gChance = _x + "_gearChance";
	_Config_Options pushBack [_lChance,_sChance,_tChance,_gChance];
} forEach _buildingTypes;

// TODO: Loot manager (we need to decide what kind of loot spawning we want (urbanwarfare or dayz-like))
