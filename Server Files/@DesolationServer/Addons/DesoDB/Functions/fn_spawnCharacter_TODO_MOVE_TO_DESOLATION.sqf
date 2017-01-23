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

#include "..\constants.hpp"

params["_player"];
private["_request", "_response","_playeruuid", "_dpvaruuid","_friendlist","_doswitchloop","_innerdoloop"];


_request = [ "{ 'dllFunction': '", PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL, "', 'dllArguments': {  'dbfunction': '", PROTOCOL_DBCALL_FUNCTION_LOAD_PLAYER, 
             "', 'dbarguments': { '", PROTOCOL_DBCALL_ARGUMENT_NICKNAME, "': '", name _player,  "', '", PROTOCOL_DBCALL_ARGUMENT_STEAMID, "': '", getPlayerUID _player, "'  } } }" ] joinString "";

_response = _request call DS_fnc_Send_Request;

_playeruuid = _resonse select 0;
_dpvaruuid = _resonse select 1;
_friendlist = _resonse select 2;

/* to be implemented later */
/*
if (_dpvaruuid == "") then {
   _request = [ "{ 'dllFunction': '", PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL, "', 'dllArguments': {  'dbfunction': '", PROTOCOL_DBCALL_FUNCTION_AV_CHARS, 
                "', 'dbarguments': { '", PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID, "': '", _playeruuid, "' } } }" ] joinString "";
   _response = _request call DS_fnc_Send_Request;
   
   if (_resonse != []) {
   // send _response to client
   // wait for user answer, must be an uuid of the response of
   _variabuuid = "lol;
   _request = [ "{ 'dllFunction': '", PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL, "', 'dllArguments': {  'dbfunction': '", PROTOCOL_DBCALL_FUNCTION_LINK_CHARS, 
                "', 'dbarguments': { '", PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID, "': '", _playeruuid, "', '", PROTOCOL_DBCALL_ARGUMENT_VARIABUUID, "': '", _variabuuid, "' } } }" ] joinString "";
   _response = _request call DS_fnc_Send_Request;
   }
}
*/

_request = [ "{ 'dllFunction': '", PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL, "', 'dllArguments': {  'dbfunction': '", PROTOCOL_DBCALL_FUNCTION_LOAD_CHAR, 
             "', 'dbarguments': { '", PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID, "': '", _playeruuid, "' } } }" ] joinString "";
_response = _request call DS_fnc_Send_Request;

if (_response == []) {
    // do spawn location selection
    // get initial loadout
    _animationstate = "someani";
    _direction = 90;
    _positiontype = 0; // we need some rule to attach a meaning to this number, i should match if the coords are ASL, AGL or ATL
    _positionx = 0;
    _positiony = 0;
    _positionz = 0;
    _classname = "someclassname";
    _hitpoints = [];
    _variables = []; 
    _persistentvariables = []; 
    _textures = []; 
    _inventoryuniform = []; 
    _inventoryvest = []; 
    _inventorybackpack = [];
    _uniform = "someuniform";
    _vest = "somevest";
    _backpack = "somebackpack";
    _headgear = "someheadgear";
    _googles = "somegoogles";
    _primaryweapon = ["someprimaryweapon", ["someattachment"]];
    _secondaryweapon = ["somesecondaryweapon", ["someattachment"]];
    _handgun = ["somehandgunweapon", ["someattachment"]]; 
    _tools = [];
    _currentweapon = "someprimaryweapon"; 
    
    _request = [ "{ 'dllFunction': '", PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL, "', 'dllArguments': {  'dbfunction': '", PROTOCOL_DBCALL_FUNCTION_CREATE_CHAR, 
                 "', 'dbarguments': { '", PROTOCOL_DBCALL_ARGUMENT_PLAYER_UUID, "': '", _playeruuid, "', '", PROTOCOL_DBCALL_ARGUMENT_ANIMATIONSTATE, "': '", _animationstate, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_DIRECTION, "': '", _direction, "', '", PROTOCOL_DBCALL_ARGUMENT_POSITIONTYPE, "': '", _positiontype, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_POSITIONX , "': '", _positionx, "', '", PROTOCOL_DBCALL_ARGUMENT_POSITIONY , "': '", _positiony, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_POSITIONZ + "': '", _positionz, "', '", PROTOCOL_DBCALL_ARGUMENT_CLASSNAME, "': '", _classname, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_HITPOINTS, "': '", _hitpoints, "', '", PROTOCOL_DBCALL_ARGUMENT_VARIABLES, "': '", _variables, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_PERSISTENTVARIABLES, "': '", _persistentvariables, "', '", PROTOCOL_DBCALL_ARGUMENT_TEXTURES, "': '", _textures, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_INVENTORYUNIFORM, "': '", _inventoryuniform, "', '", PROTOCOL_DBCALL_ARGUMENT_INVENTORYVEST, "': '", _inventoryvest, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_INVENTORYBACKPACK, "': '", _inventorybackpack, "', '", PROTOCOL_DBCALL_ARGUMENT_UNIFORM, "': '", _uniform, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_VEST, "': '", _vest, "', '", PROTOCOL_DBCALL_ARGUMENT_BACKPACK, "': '", _backpack, "', '", PROTOCOL_DBCALL_ARGUMENT_HEADGEAR, "': '", _headgear, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_GOOGLES, "': '", _googles, "', '", PROTOCOL_DBCALL_ARGUMENT_PRIMARYWEAPON, "': '", _primaryweapon, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_SECONDARYWEAPON, "': '", _secondaryweapon, "', '", PROTOCOL_DBCALL_ARGUMENT_HANDGUN, "': '", _handgun, 
                 "', '", PROTOCOL_DBCALL_ARGUMENT_TOOLS, "': '", _tools, "', '", PROTOCOL_DBCALL_ARGUMENT_CURRENTWEAPON, "': '", _currentweapon, "' } } }" ] joinString "";
    _response = _request call DS_fnc_Send_Request;
}

// code to spawn player stuff