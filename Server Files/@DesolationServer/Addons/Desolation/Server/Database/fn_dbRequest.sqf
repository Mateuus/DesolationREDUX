/*
	fn_dbRequest
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
#include "constants.hpp"


params["_type",["_callback",""],["_callbackParam",[]]];

switch(_type)do{
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
		
		_playerUUID = _playerObj getVariable ["cUUID",""];
		_killerUUID = "";
		_type = "Unknown";
		_weapon = "";
		_distance = 0;
		
		switch(_killType) do {
			case 1: {
				_killerUUID = _killerObj getVariable ["cUUID",""];
				_weapon = "TODO: get weapon"; 
				_distance = _killerObj distance _playerObj;
				_type = "Killed";
			};
			case 2: {
				_type = "Suicide";
			};
		};
		_request = [PROTOCOL_DBCALL_FUNCTION_DECLARE_CHAR_DEATH,[
			[PROTOCOL_DBCALL_ARGUMENT_CHARUUID,_playerUUID],
			[PROTOCOL_DBCALL_ARGUMENT_ATTACKER,_killerUUID],
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
};