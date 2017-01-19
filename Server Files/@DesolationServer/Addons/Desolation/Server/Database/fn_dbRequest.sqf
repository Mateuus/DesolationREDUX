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
#include "constants.hpp"


params["_type",["_callback",""],["_callbackParam",[]]];

_return = "";
switch(_type)do{
	// Player Databasing
	
	//--- called on spawn request
	case "spawnPlayer":{
		_playerObj = _callbackParam select 0;
		
		_nickName = name _playerObj;
		_steamID = getPlayerUid _playerObj;
		
		_request = [PROTOCOL_DBCALL_FUNCTION_LOAD_PLAYER,[[PROTOCOL_DBCALL_ARGUMENT_NICKNAME,_nickName],[PROTOCOL_DBCALL_ARGUMENT_STEAMID,_steamID]]] call DB_fnc_buildDBRequest;
		_response = [_request] call DB_fnc_sendRequest;
		
		_playeruuid = _response select 0;
		_dpvaruuid = _response select 1;
		_friendlist = _response select 2;
		_kickableData = _response select 3;
		_kickable = _kickableData select 0;
		_kickReason = _kickableData select 1;


		if (_kickable) exitWith {
			[_kickReason] remoteExecCall ["DS_fnc_notWhitelisted", _playerObj];
		};
		
		_playerObj setVariable ["pUUID",_playeruuid];
		
		_request = [PROTOCOL_DBCALL_FUNCTION_LOAD_CHAR,[[PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID,_playeruuid]]] call DB_fnc_buildDBRequest;
		_response = [_request] call DB_fnc_sendRequest;
		
		_callbackParam = [_playeruuid,_response] + _callbackParam; //--- _playeruuid should be tied to the spawned unit, this is handled in the callback so we need to add it to the _callbackParam
		
		if(_response isEqualTo []) then {
			["fresh", _callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
		} else {
			["load", _callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
		};
	};
	//--- called on logout or disconnect
	case "savePlayer": {
		_playerObj = _callbackParam select 0;
		
		_playeruuid = _playerObj getVariable ["pUUID",""];
		_charuuid = _playerObj getVariable ["cUUID",""];
		if(_playeruuid == "" || _charuuid == "") exitWith {diag_log "INTERNAL ERROR | FATAL > PlayerUUID or CharUUID not on the targeted unit!";};

		_posATL = getPosATL _playerObj;
		_loadout = getUnitLoadout _playerObj;
		_vars = allVariables _playerObj;
		_textures = []; //--- fix for escape sequence error
		
		_nonpersvars = [];
		_persvars = [];
		{
			if(toLower(_x) find "svar_" == 0) then {
				_nonpersvars pushback [_x,_playerObj getVariable [_x,""]];
			};
			if(tolower(_x) find "pvar_" == 0) then {
				_persvars pushback [_x,_playerObj getVariable [_x,""]];
			};
		} forEach _vars;
		
		if((_loadout select 3) isEqualTo []) then {
			_loadout set[3,["",[]]];
		};
		if((_loadout select 4) isEqualTo []) then {
			_loadout set[4,["",[]]];
		};
		if((_loadout select 5) isEqualTo []) then {
			_loadout set[5,["",[]]];
		};
		
		_request = [PROTOCOL_DBCALL_FUNCTION_UPDATE_CHAR,[
			[PROTOCOL_DBCALL_ARGUMENT_CHARUUID,_charuuid],
			[PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE,animationState _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_DIRECTION, getdir _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE, 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONX,_posATL select 0],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONY,_posATL select 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONZ,_posATL select 2],
			[PROTOCOL_DBCALL_ARGUMENT_CLASSNAME,typeof _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_HITPOINTS,getAllHitPointsDamage _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_VARIABLES,_nonpersvars],
			[PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES,_persvars],
			[PROTOCOL_DBCALL_ARGUMENT_TEXTURES,_textures],
			
			[PROTOCOL_DBCALL_ARGUMENT_INVENTORYUNIFORM, (_loadout select 3) select 1],
			[PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST, (_loadout select 4) select 1],
			[PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK, (_loadout select 5) select 1],
			[PROTOCOL_DBCALL_ARGUMENT_UNIFORM, (_loadout select 3) select 0],
			[PROTOCOL_DBCALL_ARGUMENT_VEST, (_loadout select 4) select 0],
			[PROTOCOL_DBCALL_ARGUMENT_BACKPACK, (_loadout select 5) select 0],
			[PROTOCOL_DBCALL_ARGUMENT_HEADGEAR, _loadout select 6],
			[PROTOCOL_DBCALL_ARGUMENT_GOOGLES, _loadout select 7],
			[PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON, _loadout select 0],
			[PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON, _loadout select 1],
			[PROTOCOL_DBCALL_ARGUMENT_HANDGUN, _loadout select 2],
			[PROTOCOL_DBCALL_ARGUMENT_TOOLS, [_loadout select 8,_loadout select 9]],
			[PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON, currentWeapon _playerObj]
		]] call DB_fnc_buildDBRequest;
		[_request] call DB_fnc_sendRequest;
	};
	//--- called on death
	case "killPlayer": {
		_playerObj = _callbackParam select 0;
		_killerObj = _callbackParam select 1;
		
		_killType = 0;
		if(!isNull _killerObj && isPlayer _killerObj && _killerObj != _playerObj) then {
			_killType = 1;
		};
		if(!isNull _killerObj && isPlayer _killerObj && _killerObj == _playerObj) then {
			_killType = 2;
		};
		
		_deadCharUUID = _playerObj getVariable ["cUUID",""];
		_killerPlayerUUID = "";
		_type = "Unknown";
		_weapon = "";
		_distance = 0;
		
		switch(_killType) do {
			case 1: {
				_killerPlayerUUID = _killerObj getVariable ["pUUID",""];
				_weapon = "TODO: get weapon"; 
				_distance = _killerObj distance _playerObj;
				_type = "Killed";
			};
			case 2: {
				_type = "Suicide";
			};
		};
		_request = [PROTOCOL_DBCALL_FUNCTION_DECLARE_CHAR_DEATH,[
			[PROTOCOL_DBCALL_ARGUMENT_CHARUUID,_deadCharUUID],
			[PROTOCOL_DBCALL_ARGUMENT_ATTACKER,_killerPlayerUUID],
			[PROTOCOL_DBCALL_ARGUMENT_TYPE,_type],
			[PROTOCOL_DBCALL_ARGUMENT_WEAPON,_weapon],
			[PROTOCOL_DBCALL_ARGUMENT_DISTANCE,_distance]
		]] call DB_fnc_buildDBRequest;
		[_request] call DB_fnc_sendRequest;
	};
	//--- called on fresh spawn finishing
	case "createPlayer": {
		_playerObj = _callbackParam select 0;
		
		_playeruuid = _playerObj getVariable ["pUUID",""];
		if(_playeruuid == "") exitWith {diag_log "INTERNAL ERROR | FATAL > PlayerUUID not on the targeted unit when creating!";};

		_posATL = getPosATL _playerObj;
		_loadout = getUnitLoadout _playerObj;
		_vars = allVariables _playerObj;
		_textures = []; //getObjectTextures _playerObj; // escape sequence error (maybe replace \ with \\)
		
		_nonpersvars = [];
		_persvars = [];
		{
			if(_x find "SVAR_" == 0) then {
				_nonpersvars pushback [_x,_playerObj getVariable [_x,""]];
			};
			if(_x find "PVAR_" == 0) then {
				_persvars pushback [_x,_playerObj getVariable [_x,""]];
			};
		} forEach _vars;
		
		if((_loadout select 3) isEqualTo []) then {
			_loadout set[3,["",[]]];
		};
		if((_loadout select 4) isEqualTo []) then {
			_loadout set[4,["",[]]];
		};
		if((_loadout select 5) isEqualTo []) then {
			_loadout set[5,["",[]]];
		};
		
		_request = [PROTOCOL_DBCALL_FUNCTION_CREATE_CHAR,[
			[PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID,_playeruuid],
			[PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE,animationState _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_DIRECTION, getdir _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE, 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONX,_posATL select 0],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONY,_posATL select 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONZ,_posATL select 2],
			[PROTOCOL_DBCALL_ARGUMENT_CLASSNAME,typeof _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_HITPOINTS,getAllHitPointsDamage _playerObj],
			[PROTOCOL_DBCALL_ARGUMENT_VARIABLES,_nonpersvars],
			[PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES,_persvars],
			[PROTOCOL_DBCALL_ARGUMENT_TEXTURES,_textures],
			
			[PROTOCOL_DBCALL_ARGUMENT_INVENTORYUNIFORM, (_loadout select 3) select 1],
			[PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST, (_loadout select 4) select 1],
			[PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK, (_loadout select 5) select 1],
			[PROTOCOL_DBCALL_ARGUMENT_UNIFORM, (_loadout select 3) select 0],
			[PROTOCOL_DBCALL_ARGUMENT_VEST, (_loadout select 4) select 0],
			[PROTOCOL_DBCALL_ARGUMENT_BACKPACK, (_loadout select 5) select 0],
			[PROTOCOL_DBCALL_ARGUMENT_HEADGEAR, _loadout select 6],
			[PROTOCOL_DBCALL_ARGUMENT_GOOGLES, _loadout select 7],
			[PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON, _loadout select 0],
			[PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON, _loadout select 1],
			[PROTOCOL_DBCALL_ARGUMENT_HANDGUN, _loadout select 2],
			[PROTOCOL_DBCALL_ARGUMENT_TOOLS, [_loadout select 8,_loadout select 9]],
			[PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON, currentWeapon _playerObj]
		]] call DB_fnc_buildDBRequest;
		_response = [_request] call DB_fnc_sendRequest;
		_playerObj setVariable ["cUUID",_response];
	};
	
	case "getObjects": {
		_request = [PROTOCOL_DBCALL_FUNCTION_DUMP_OBJECTS,[]] call DB_fnc_buildDBRequest;
		_return = [_request] call DB_fnc_sendRequest;
	};
	
	// Vehicle Databasing
	//--- called on new vehicle spawn
	case "spawnVehicle": {
		_vehicle = _callbackParam select 0;
		
		_className = typeof _vehicle;
		_priority = 10001;
		_accesscode = "";
		_locked = 0;
		_visible = 1;
		_player_uuid = "";
		_hitpoints = getAllHitPointsDamage _vehicle;
		_damage = damage _vehicle;
		_fuel = fuel _vehicle;
		_fuelcargo = getFuelCargo _vehicle;
		if(isNil {_fuelcargo}) then {_fuelcargo = 0;};
		if(str(_fuelcargo) find "-1" == 0) then {
			_fuelcargo = 0;
		};
		_repaircargo = getRepairCargo _vehicle;
		if(isNil {_repaircargo}) then {_repaircargo = 0;};
		if(str(_repaircargo) find "-1" == 0) then {
			_repaircargo = 0;
		};
		_items = [];  //todo
		_magazines = [];  //todo
		_weapons = []; // todo
		_backpacks = []; // todo
		_magazinesturrent = []; // todo
		_variables = [vectorUp _vehicle];
		_animation_sources = [];
		_textures = [];
		_direction = getDir _vehicle;
		_positionType = 1;
		_position = getPosATL _vehicle;
		
		_request = [PROTOCOL_DBCALL_FUNCTION_RETURN_UUID,[]] call DB_fnc_buildDBRequest;
		_objectUUID = [_request] call DB_fnc_sendRequest;
		_vehicle setVariable ["oUUID",_objectUUID];
		
		_request = [PROTOCOL_DBCALL_FUNCTION_QUIET_CREATE_OBJECT,[
			[PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID,_objectUUID],
			[PROTOCOL_DBCALL_ARGUMENT_CLASSNAME,_className],
			[PROTOCOL_DBCALL_ARGUMENT_PRIORITY,_priority],
			[PROTOCOL_DBCALL_ARGUMENT_VISIBLE,_visible],
			[PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE, _accesscode],
			[PROTOCOL_DBCALL_ARGUMENT_LOCKED,_locked],
			[PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID,_player_uuid],
			[PROTOCOL_DBCALL_ARGUMENT_HITPOINTS,_hitpoints],
			[PROTOCOL_DBCALL_ARGUMENT_DAMAGE,_damage],
			[PROTOCOL_DBCALL_ARGUMENT_FUEL,_fuel],
			[PROTOCOL_DBCALL_ARGUMENT_FUELCARGO,_fuelcargo],
			[PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO,_repaircargo],
			[PROTOCOL_DBCALL_ARGUMENT_ITEMS,_items],
			[PROTOCOL_DBCALL_ARGUMENT_MAGAZINES,_magazines],
			[PROTOCOL_DBCALL_ARGUMENT_WEAPONS, _weapons],
			[PROTOCOL_DBCALL_ARGUMENT_BACKPACKS, _backpacks],
			[PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET, _magazinesturrent],
			[PROTOCOL_DBCALL_ARGUMENT_VARIABLES, _variables],
			[PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE, _animation_sources],
			[PROTOCOL_DBCALL_ARGUMENT_TEXTURES, _textures],
			[PROTOCOL_DBCALL_ARGUMENT_DIRECTION, _direction],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE, _positionType],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONX, _position select 0],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONY, _position select 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONZ, _position select 2]
		]] call DB_fnc_buildDBRequest;
		[_request] spawn DB_fnc_sendRequest;
	};
	//--- called on vehicle save
	case "updateVehicle": {
		_vehicle = _callbackParam select 0;
		//--- request a locality switch from the owning client & transfer back upon completion? (maybe needed)
		_object_uuid = _vehicle getVariable ["oUUID",""];
		_className = typeof _vehicle;
		_priority = 10001;
		_visible = 1;
		_accesscode = "";
		_locked = 0;
		_player_uuid = "";
		_hitpoints = getAllHitPointsDamage _vehicle;
		_damage = damage _vehicle;
		_fuel = fuel _vehicle;
		_fuelcargo = getFuelCargo _vehicle;
		if(isNil {_fuelcargo}) then {_fuelcargo = 0;};
		if(str(_fuelcargo) find "-1" == 0) then {
			_fuelcargo = 0;
		};
		_repaircargo = getRepairCargo _vehicle;
		if(isNil {_repaircargo}) then {_repaircargo = 0;};
		if(str(_repaircargo) find "-1" == 0) then {
			_repaircargo = 0;
		};
		_items = [];  //todo
		_magazines = [];  //todo
		_weapons = []; // todo
		_backpacks = []; // todo
		_magazinesturrent = []; // todo
		_variables = [vectorUp _vehicle];
		_animation_sources = [];
		_textures = [];
		_direction = getDir _vehicle;
		_positionType = 1;
		_position = getPosATL _vehicle;
		
		_request = [PROTOCOL_DBCALL_FUNCTION_UPDATE_OBJECT,[
			[PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID,_object_uuid],
			[PROTOCOL_DBCALL_ARGUMENT_CLASSNAME,_className],
			[PROTOCOL_DBCALL_ARGUMENT_PRIORITY,_priority],
			[PROTOCOL_DBCALL_ARGUMENT_VISIBLE,_visible],
			[PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE, _accesscode],
			[PROTOCOL_DBCALL_ARGUMENT_LOCKED,_locked],
			[PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID,_player_uuid],
			[PROTOCOL_DBCALL_ARGUMENT_HITPOINTS,_hitpoints],
			[PROTOCOL_DBCALL_ARGUMENT_DAMAGE,_damage],
			[PROTOCOL_DBCALL_ARGUMENT_FUEL,_fuel],
			[PROTOCOL_DBCALL_ARGUMENT_FUELCARGO,_fuelcargo],
			[PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO,_repaircargo],
			[PROTOCOL_DBCALL_ARGUMENT_ITEMS,_items],
			[PROTOCOL_DBCALL_ARGUMENT_MAGAZINES,_magazines],
			[PROTOCOL_DBCALL_ARGUMENT_WEAPONS, _weapons],
			[PROTOCOL_DBCALL_ARGUMENT_BACKPACKS, _backpacks],
			[PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET, _magazinesturrent],
			[PROTOCOL_DBCALL_ARGUMENT_VARIABLES, _variables],
			[PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE, _animation_sources],
			[PROTOCOL_DBCALL_ARGUMENT_TEXTURES, _textures],
			[PROTOCOL_DBCALL_ARGUMENT_DIRECTION, _direction],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE, _positionType],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONX, _position select 0],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONY, _position select 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONZ, _position select 2]
		]] call DB_fnc_buildDBRequest;
		[_request] call DB_fnc_sendRequest;
	};
	//--- called on vehicle death
	case "destroyVehicle": {
		_object_uuid = _callbackParam select 0;	
		_killerObj = _callbackParam select 1;
		
		_killerUUID = "";
		_type = "Unknown";
		_weapon = "";
		_distance = 0;
		
		if(!isNull _killerObj && isPlayer _killerObj) then {
			_killerUUID = _killerObj getVariable ["cUUID",""];
			_weapon = "TODO: get weapon"; 
			_distance = _killerObj distance _playerObj;
			_type = "Killed";
		};
		
		
		_request = [PROTOCOL_DBCALL_FUNCTION_DECLARE_OBJECT_DEATH,[
			[PROTOCOL_DBCALL_ARGUMENT_OBJECTUUID,_object_uuid],
			[PROTOCOL_DBCALL_ARGUMENT_ATTACKER,_killerUUID],
			[PROTOCOL_DBCALL_ARGUMENT_TYPE,_type],
			[PROTOCOL_DBCALL_ARGUMENT_WEAPON,_weapon],
			[PROTOCOL_DBCALL_ARGUMENT_DISTANCE,_distance]
		]] call DB_fnc_buildDBRequest;
		[_request] call DB_fnc_sendRequest;
	};
	
	// Building Databasing
	//--- TODO
	case "spawnBuilding": {
		_building = _callbackParam select 0;
		
		_className = typeof _vehicle;
		_priority = 1001;
		_visible = 1;
		_accesscode = "";
		_locked = 0;
		_player_uuid = "";
		_hitpoints = getAllHitPointsDamage _vehicle;
		_damage = damage _vehicle;
		_fuel = fuel _vehicle;
		_fuelcargo = getFuelCargo _vehicle;
		if(isNil {_fuelcargo}) then {_fuelcargo = 0;};
		if(str(_fuelcargo) find "-1" == 0) then {
			_fuelcargo = 0;
		};
		_repaircargo = getRepairCargo _vehicle;
		if(isNil {_repaircargo}) then {_repaircargo = 0;};
		if(str(_repaircargo) find "-1" == 0) then {
			_repaircargo = 0;
		};
		_items = [];  //todo
		_magazines = [];  //todo
		_weapons = []; // todo
		_backpacks = []; // todo
		_magazinesturrent = []; // todo
		_variables = [vectorUp _vehicle];
		_animation_sources = [];
		_textures = [];
		_direction = getDir _vehicle;
		_positionType = 1;
		_position = getPosATL _vehicle;
		
		_request = [PROTOCOL_DBCALL_FUNCTION_QUIET_CREATE_OBJECT,[
			[PROTOCOL_DBCALL_ARGUMENT_CLASSNAME,_className],
			[PROTOCOL_DBCALL_ARGUMENT_PRIORITY,_priority],
			[PROTOCOL_DBCALL_ARGUMENT_VISIBLE,_visible],
			[PROTOCOL_DBCALL_ARGUMENT_ACCESSCODE, _accesscode],
			[PROTOCOL_DBCALL_ARGUMENT_LOCKED,_locked],
			[PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID,_player_uuid],
			[PROTOCOL_DBCALL_ARGUMENT_HITPOINTS,_hitpoints],
			[PROTOCOL_DBCALL_ARGUMENT_DAMAGE,_damage],
			[PROTOCOL_DBCALL_ARGUMENT_FUEL,_fuel],
			[PROTOCOL_DBCALL_ARGUMENT_FUELCARGO,_fuelcargo],
			[PROTOCOL_DBCALL_ARGUMENT_REPAIRCARGO,_repaircargo],
			[PROTOCOL_DBCALL_ARGUMENT_ITEMS,_items],
			[PROTOCOL_DBCALL_ARGUMENT_MAGAZINES,_magazines],
			[PROTOCOL_DBCALL_ARGUMENT_WEAPONS, _weapons],
			[PROTOCOL_DBCALL_ARGUMENT_BACKPACKS, _backpacks],
			[PROTOCOL_DBCALL_ARGUMENT_MAGAZINESTURRET, _magazinesturrent],
			[PROTOCOL_DBCALL_ARGUMENT_VARIABLES, _variables],
			[PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE, _animation_sources],
			[PROTOCOL_DBCALL_ARGUMENT_TEXTURES, _textures],
			[PROTOCOL_DBCALL_ARGUMENT_DIRECTION, _direction],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE, _positionType],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONX, _position select 0],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONY, _position select 1],
			[PROTOCOL_DBCALL_ARGUMENT_POSITIONZ, _position select 2]
		]] call DB_fnc_buildDBRequest;
		[_request] call DB_fnc_sendRequest;
	};
};
_return;