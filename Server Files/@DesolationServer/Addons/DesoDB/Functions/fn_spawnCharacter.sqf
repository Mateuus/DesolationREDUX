#include "..\constants.hpp"

params["_player"];
private["_request", "_response","_playeruuid", "_dpvaruuid","_friendlist","_doswitchloop","_innerdoloop"];


_request = format [FORMATSTRING_DBCALL_FUNCTION_LOAD_PLAYER, name _player, getPlayerUID _player];
_response = _request call DS_fnc_Send_Request;

_playeruuid = _resonse select 0;
_dpvaruuid = _resonse select 1;
_friendlist = _resonse select 2;

/* to be implemented later */
/*
if (_dpvaruuid == "") then {
   _request = format [FORMATSTRING_DBCALL_FUNCTION_AV_CHARS, _playeruuid];
   _response = _request call DS_fnc_Send_Request;
   
   if (_resonse != []) {
   // send _response to client
   // wait for user answer, must be an uuid of the response of
   _variabuuid = "lol;
   _request = format [FORMATSTRING_DBCALL_FUNCTION_LINK_CHARS, _playeruuid, _variabuuid];
   _response = _request call DS_fnc_Send_Request;
   }
}
*/

_request = format [FORMATSTRING_DBCALL_FUNCTION_LOAD_CHAR, _playeruuid];
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
    
    _request = format [FORMATSTRING_DBCALL_FUNCTION_CREATE_CHAR, _playeruuid, _animationstate, _direction, _positiontype, _positionx, _positiony, _positionz, _classname, _hitpoints, _variables, _persistentvariables, _textures, _inventoryuniform, _inventoryvest, _inventorybackpack, _uniform, _vest, _backpack, _headgear, _googles, _primaryweapon, _secondaryweapon, _handgun, _tools, _currentweapon];
    _response = _request call DS_fnc_Send_Request;
}

// code to spawn player stuff