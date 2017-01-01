/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */
private["_buildingTypes","_MinPiles","_DoRespawn","_RespawnTimeS","_Config_Options","_lChance","_sChance","_tChance","_gChance","_data","_all_buildings","_cfg","_name","_buildingsToSpawn","_buildingsToDespawn","_buildingsNotToDespawn","_houses","_nearest_building","_nearest_building_type","_last_nearest","_hasVar","_isSpawned","_savedLoot","_spawnTime","_doFreshSpawn","_x"];

if !(["SpawnLoot"] call DS_fnc_getCfgValue) exitWith {diag_log "<Loot Manager>: Loot spawning turned off";};

diag_log "<Loot Manager>: Parsing config entries";

//--- Parse config entries
_buildingTypes = getArray(configFile >> "CfgItemSpawns" >> "buildingTypes");
//--- Parse User Defined Config Entries
_MinPiles = ["MinPiles"] call DS_fnc_getCfgValue;

_DoRespawn = ["RespawnLoot"] call DS_fnc_getCfgValue;
_RespawnTimeS = (["RespawnTime"] call DS_fnc_getCfgValue)*60;


_Config_Options = [];
{
	_lChance = call compile ([_x + "_lootChance","DS"] call BASE_fnc_getCfgValue);
	_sChance = call compile ([_x + "_spawnChance","DS"] call BASE_fnc_getCfgValue);
	_tChance = call compile ([_x + "_typeChance","DS"] call BASE_fnc_getCfgValue);
	_gChance = call compile ([_x + "_gearChance","DS"] call BASE_fnc_getCfgValue);
	_data = [_lChance,_sChance,_tChance,_gChance];
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
DS_var_finishedLoot = true;
call DS_fnc_checkServerLock;
diag_log "<Loot Manager>: Loot Manager Running!";

while{true} do {

	_buildingsToSpawn = [];
	_buildingsToDespawn = [];
	_buildingsNotToDespawn = [];

	{
		//--- TODO: check if they've spawned in
		if(alive _x) then {
			//--- get house im standing on, fixes bug with some houses despawning loot when im in them
			_houses = lineIntersectsObjs [(AGLtoASL (_x modelToWorld [0,0,0])),(AGLtoASL(_x modelToWorld [0,0,-0.5])),objNull,_x,true];
			_nearest_building = objNull;
			if(count(_houses) > 0) then {
				_nearest_building = _houses select (count(_houses)-1);
			};
			
			if !(toLower(typeof(_nearest_building)) in _all_buildings) then {
				_houses = nearestObjects [_x,_all_buildings,50];
				_nearest_building = objNull;
				{
					if(isNull _nearest_building) then {
						_nearest_building = _x;
					} else {
						if((player distance _x) < (player distance _nearest_building)) then {
							_nearest_building = _x;
						};
					};
				} forEach _houses;
			};
			//--- near building check (fixes bug with lamps being called "houses" rofl)
			if !(toLower(typeof(_nearest_building)) in _all_buildings) then {
				_nearest_building = nearestBuilding _x;
			};


			if(!isNull _nearest_building) then { /// near a building
			
				_buildingsNotToDespawn pushBack _nearest_building; /// mark this building as not despawnable
				if !(_nearest_building in _buildingsToSpawn) then {
					
					_nearest_building_type = toLower(typeof _nearest_building);

					_last_nearest = _x getVariable ["LastNearestBuilding",objNull];
					if(_last_nearest != _nearest_building) then { /// nearest building has changed

						if(!isNull _last_nearest) then {
							if(_last_nearest getVariable ["SpawnedLoot",false]) then {
								if !(_last_nearest in _buildingsToDespawn) then {
									_buildingsToDespawn pushback _last_nearest; /// if we were at a previous building, mark it as despawnable
								};
							};
						};

						_x setVariable ["LastNearestBuilding",_nearest_building]; /// update our previous building to this new one

						if(_nearest_building_type in _all_buildings) then { /// if this building can contain loot
							
							_buildingsToSpawn pushBack _nearest_building; /// mark this building as "Spawn loot here"

						};
					};
				};
			};
		};
	} forEach allPlayers;

	{

		_hasVar = _x getVariable ["SpawnedLoot",false];
		_isSpawned = _x getVariable ["IsSpawnedLoot",false];
		_savedLoot = _x getVariable ["SavedLoot",[]];
		_spawnTime = _x getVariable ["SpawnedTime",0];
		_lootPiles = _x getVariable ["LOOT_PILES",[]];

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
		
		if(count(_lootPiles) == 0) then {
			if(_doFreshSpawn) then {
				_x setVariable ["SpawnedLoot",true];
				_x setVariable ["SpawnedTime",diag_tickTime];
				_x setVariable ["SavedLoot",[]];
				_x setVariable ["IsSpawnedLoot",true];
				[_x,_MinPiles,_buildingTypes,_Config_Options,[]] remoteExecCall ["DS_fnc_spawnLoot",2]; //temp: we need to get DS_fnc_spawnLoot into a non-schedueled environment
			} else {
				if(!_isSpawned) then {
					[_x,_MinPiles,_buildingTypes,_Config_Options,_savedLoot] remoteExecCall ["DS_fnc_spawnLoot",2];
				};
			};
		};
	} forEach _buildingsToSpawn;
	{
		if !(_x in _buildingsNotToDespawn) then {
			_x setVariable ["IsSpawnedLoot",false];
			[_x] remoteExecCall ["DS_fnc_despawnLoot",2];
		};
	} forEach _buildingsToDespawn;

};
