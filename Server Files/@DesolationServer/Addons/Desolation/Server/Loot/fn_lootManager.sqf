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
	_lChance = _x + "_lootChance";
	_sChance = _x + "_spawnChance";
	_tChance = _x + "_typeChance";
	_gChance = _x + "_gearChance";
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
	{
		//--- TODO: check if they've spawned in
		if(alive _x) then {
			_nearest_building = nearestObject [_x,"House"];

			if(!isNull _nearest_building) then {

				_last_nearest = _x getVariable ["LastNearestBuilding",objNull];
				if(_last_nearest != _nearest_building) then {
					if(!isNull _last_nearest) then {
						//--- despawn loot? (this may bug if multiple people are near a building so we may need a global check like simmanager)
					};
					_x setVariable ["LastNearestBuilding",_nearest_building];

					_nearest_building_type = toLower(typeof _nearest_building);

					if(_nearest_building_type in _all_buildings) then {
						_hasVar = _building getVariable ["SpawnedLoot",false];
						_savedLoot = _building getVariable ["SavedLoot",[]];
						_spawnTime = _building getVariable ["SpawnedTime",0];

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
							[_nearest_building,_MinPiles,_buildingTypes,_Config_Options,[]] remoteExecCall ["DS_fnc_spawnLoot",2]; //temp: we need to get DS_fnc_spawnLoot into a non-schedueled environment
						} else {
							[_nearest_building,_MinPiles,_buildingTypes,_Config_Options,_savedLoot remoteExecCall ["DS_fnc_spawnLoot",2];
						};
					};
				};
			};
		};
	} forEach allPlayers;
};
