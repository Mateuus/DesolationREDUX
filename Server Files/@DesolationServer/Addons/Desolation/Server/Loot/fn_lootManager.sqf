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

diag_log "<Loot Manager>: Parsing config entries";

//--- Parse config entries
_buildingTypes = getArray(configFile >> "CfgItemSpawns" >> "buildingTypes");
diag_log "<Loot Manager>: Building types -> ";
diag_log str(_buildingTypes);
//--- Parse User Defined Config Entries
_MinPiles = ["MinPiles"] call _getCFGValue;
diag_log "<Loot Manager>: Minimum loot piles -> ";
diag_log str(_MinPiles);

_DoRespawn = ["RespawnLoot"] call _getCFGValue;
_RespawnTimeS = (["RespawnTime"] call _getCFGValue)*60;


_Config_Options = [];
{
	diag_log ("<Loot Manager>: Config options for " + _x + " buildings ->");
	_lChance = call compile ([_x + "_lootChance","DS"] call BASE_fnc_getCfgValue);
	_sChance = call compile ([_x + "_spawnChance","DS"] call BASE_fnc_getCfgValue);
	_tChance = call compile ([_x + "_typeChance","DS"] call BASE_fnc_getCfgValue);
	_gChance = call compile ([_x + "_gearChance","DS"] call BASE_fnc_getCfgValue);
	_data = [_lChance,_sChance,_tChance,_gChance];
	diag_log str(_data);
	_Config_Options pushBack _data;
} forEach _buildingTypes;


// TODO: Parse all lootable buildings
_all_buildings = [];
for "_i" from 0 to count(configFile >> "CfgItemSpawns" >> "Buildings")-1 do {
	_cfg = (configFile >> "CfgItemSpawns" >> "Buildings") select _i;
	if(isClass _cfg) then {
		_name = toLower(configName _cfg);
		_all_buildings pushBack _name;
	};
};
diag_log "<Loot Manager>: # of lootable buildings ->";
diag_log str(count(_all_buildings));

while{true} do {

	_buildingsToSpawn = [];
	_buildingsToDespawn = [];
	_buildingsNotToDespawn = [];

	{
		//--- TODO: check if they've spawned in
		if(alive _x) then {
			_nearest_building = nearestObject [_x,"House"];

			if(!isNull _nearest_building) then { /// near a building

				_nearest_building_type = toLower(typeof _nearest_building);

				_buildingsNotToDespawn pushBack _nearest_building; /// mark this building as not despawnable

				_last_nearest = _x getVariable ["LastNearestBuilding",objNull];
				if(_last_nearest != _nearest_building) then { /// nearest building has changed

					if(!isNull _last_nearest) then {
						_buildingsToDespawn pushback _last_nearest; /// if we were at a previous building, mark it as despawnable
					};

					_x setVariable ["LastNearestBuilding",_nearest_building]; /// update our previous building to this new one

					if(_nearest_building_type in _all_buildings) then { /// if this building can contain loot

						_buildingsToSpawn pushBack _nearest_building; /// mark this building as "Spawn loot here"

					};
				};
			};
		};
	} forEach allPlayers;

	{

		_hasVar = _x getVariable ["SpawnedLoot",false];
		_savedLoot = _x getVariable ["SavedLoot",[]];
		_spawnTime = _x getVariable ["SpawnedTime",0];

		_doFreshSpawn = false;

		if !(_hasVar) then {
			_doFreshSpawn = true;
		} else {
			if(_DoRespawn) then {
				if ((diag_tickTime - _spawnTime) >= _RespawnTimeS) then {
					_doFreshSpawn = true;
				};
			};
		};

		if(_doFreshSpawn) then {
			_x setVariable ["SpawnedLoot",true];
			_x setVariable ["SpawnedTime",diag_tickTime];
			_x setVariable ["SavedLoot",[]];
			[_x,_MinPiles,_buildingTypes,_Config_Options,[]] remoteExecCall ["DS_fnc_spawnLoot",2]; //temp: we need to get DS_fnc_spawnLoot into a non-schedueled environment
		} else {
			[_x,_MinPiles,_buildingTypes,_Config_Options,_savedLoot] remoteExecCall ["DS_fnc_spawnLoot",2];
		};
	} forEach _buildingsToSpawn;
	{
		if !(_x in _buildingsNotToDespawn) then {
				[_x] remoteExecCall ["DS_fnc_despawnLoot",2];  //temp: we need to get DS_fnc_despawnLoot into a non-schedueled environment
		};
	} forEach _buildingsToDespawn;

};
