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
private["_types","_data","_config","_cfg","_locations","_directions","_type","_houses","_index","_hData","_vehicles","_bikeLimit","_housesOrdered","_houses","_lIndex","_v","_vDir","_posagl","_posasl","_tv","_hitpoints","_value"];

DS_var_Vehicles = [];
DS_var_VehicleUUIDS = [];


_dbSpawnData = ["getObjects"] call DS_fnc_dbRequest;
_numVtoSpawn = (["NumVehicles"] call DS_fnc_getCfgValue);

_len = count(_dbSpawnData);

_tvs = [];
diag_log "Spawning DB objects";
{
	_data = _x call DS_fnc_spawnFromDB;
	_object = _data select 0;
	_tvs pushBack _object;
	_priority = _data select 1;
	_oUUID = _data select 2;
	
	DS_var_Vehicles pushback _object;
	DS_var_VehicleUUIDS pushback _oUUID;
	
	if(_priority >= 10000) then {
		_numVtoSpawn = _numVtoSpawn - 1;
	};
	diag_log ("Spawned object #" + str(_forEachIndex+1) + " of " + str(_len));
} forEach _dbSpawnData;
diag_log "DONE";
if(_numVtoSpawn <= 0) exitWith {
	diag_log "No more vehicles need to be spawned";
	uiSleep 3;
	{	
		_x enableSimulationGlobal false;
	} forEach _tvs;
	diag_log "Done spawning vehicles";
	[] spawn DS_fnc_vehicleMonitor;
};
diag_log ("Spawning " + str(_numVtoSpawn) + " more vehicles.");

_types = [];
_data = [];

diag_log "Scanning for house data";

_config = configFile >> "CfgVehicleSpawns" >> "Buildings";
for "_i" from 0 to count(_config)-1 do {
	_cfg = _config select _i;
	if(isClass _cfg) then {
		_locations = getArray(_cfg >> "locations");
		_directions = getArray(_cfg >> "directions");
		_type = configName _cfg;
		_types pushBack tolower _type;
		_data pushBack [_locations,_directions,[]];

	};
};
diag_log format["found %1 types of houses", count(_types)];

diag_log "Scanning for vehicle data";

_config = configFile >> "CfgVehicleSpawns" >> "Vehicles";
for "_i" from 0 to count(_config)-1 do {
	_cfg = _config select _i;
	if(isClass _cfg) then {
		_houses = getArray(_cfg >> "buildings");
		_type = configName _cfg;

		{
			_index = _types find tolower _x;
			if(_index != -1) then {
				_hData = _data select _index;
				_vehicles = _hData select 2;
				_vehicles pushBack _type;
				_hData set[2,_vehicles];
				_data  set[_index,_hData];
			};
		} forEach _houses;
	};
};

diag_log format["Getting all houses on map (%1)",diag_tickTime];


_bikeLimit = call compile (["MaxBikes","DS"] call BASE_fnc_getCfgValue); //--- temp, to be loaded from config (TODO)

//--- get all houses on the map that can spawn vehicles in them

_housesOrdered = [];
for "_x" from 0 to ceil(worldsize/5000) do {
	for "_y" from 0 to ceil(worldsize/5000) do {
		_housesOrdered = _housesOrdered + (nearestObjects [[_x*5000,_y*5000],_types,6000]);
	};
};
_houses = [_housesOrdered] call DS_fnc_shuffleArray; //--- randomize the order of which houses are spawned (effectively randomizes vehicle spawning locations)
diag_log format["Got all houses (%1)",diag_tickTime];


diag_log format["Spawning vehicles @ %1 houses",count(_houses)];

{
	if !(_x getVariable ["SpawnedV",false]) then {
		_x setVariable ["SpawnedV",true];
		if(_numVtoSpawn == 0) exitWith {};
		_type = tolower typeof _x;
		_index = _types find _type;
		if(_index != -1) then {
			_hData = _data select _index;
			_locations = _hData select 0;
			_directions = _hData select 1;
			_vehicles = _hData select 2;

			if(_bikeLimit == 0) then {_vehicles = _vehicles - ["MMT_Civ"];}; //---vehicles is case sensitive

			_lIndex = floor(random(count(_locations))); //--- get location index

			_v = _vehicles select floor(random(count(_vehicles))); //--- get vehicle type we are spawning
			if(!isNil {_v}) then {

				if(toLower(_v) == "mmt_civ") then {_bikeLimit = _bikeLimit - 1;};

				_location = _locations select _lIndex; //--- get offset of the spawn position
				_direction = _directions select _lIndex; //--- get vehicle direction additive

				_vDir = (getdir _x) + _direction;

				_posagl = _x modelToWorld _location;
				_posasl = AGLtoASL _posagl;

				_tv = _v createVehicle _posagl;
				clearItemCargo _tv;
				_hitpoints = (getAllHitPointsDamage _tv) select 0;
				{
					if(_x != "" && _x != "HitFuel" && _x != "HitFuelTank" && _x != "HitBody") then {
						_value = random(1);
						_tv setHitPointDamage [_x,_value];
					};
					if(_x == "HitBody") then {
						_value = random(0.4);
						_tv setHitPointDamage [_x,_value];
					};
				} forEach _hitpoints;
				
				_tv setdir _vDir;
				_tv setposasl _posasl;
				
				_tvs pushBack _tv;
				_numVtoSpawn = _numVtoSpawn - 1;
				["spawnVehicle","",[_tv]] call DS_fnc_dbRequest;
				
				_oUUID = _tv getVariable ["oUUID",""];
				
				DS_var_Vehicles pushback _tv;
				DS_var_VehicleUUIDS pushback _oUUID;
				
			};
		};
	};
} forEach _houses;
diag_log ("Spawned" + str(count(_tvs)) + " vehicle(s)");
uiSleep 3;
{
	_x enableSimulationGlobal false;
} forEach _tvs;
diag_log "Done spawning vehicles";
[] spawn DS_fnc_vehicleMonitor;