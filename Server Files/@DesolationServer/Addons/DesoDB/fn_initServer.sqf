#include "constants.hpp"

_worldUUID = call DB_fnc_getWorldUUID;
if(_worldUUID == "") exitWith {diag_log "WORLD IDENTIFICATION IS NOT SET, THE DATABASE PLUGIN WILL NOT RUN";};

_poolSize = call DB_fnc_getPoolSize;
if(isNil {_poolSize}) exitWith {diag_log "THREAD POOL SIZE IS NOT SET, THE DATABASE PLUGIN WILL NOT RUN";};

diag_log ("DesoDB > World UUID: " + _worldUUID);
diag_log ("DesoDB > Pool Size: " + str(_poolSize));

_request = ["initdb",[["poolsize",_poolSize],["worlduuid",_worldUUID]]] call DB_fnc_buildDLLRequest;
diag_log "DesoDB > Dll Request";
diag_log _request;
[_request] call DB_fnc_sendRequest;

[] spawn {
	diag_log "Starting DB test";
	uiSleep 10;
	diag_log "TESTING DB CONNECTION";
	_request = ["dbVersion"] call DB_fnc_buildDBRequest;
	diag_log ([_request] call DB_fnc_sendRequest);
};