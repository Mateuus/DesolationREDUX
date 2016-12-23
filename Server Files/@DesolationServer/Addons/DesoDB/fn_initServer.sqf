#include "constants.hpp"

_worldUUID = call DB_fnc_getWorldUUID;
if(_worldUUID == "") exitWith {diag_log "WORLD IDENTIFICATION IS NOT SET, THE DATABASE PLUGIN WILL NOT RUN";};

_poolSize = call DB_fnc_getPoolSize;
if(isNil {_poolSize}) exitWith {diag_log "THREAD POOL SIZE IS NOT SET, THE DATABASE PLUGIN WILL NOT RUN";};

diag_log ("DesoDB > World UUID: " + _worldUUID);
diag_log ("DesoDB > Pool Size: " + str(_poolSize));

_request = ["initdb",[["poolsize",_poolSize],["worlduuid",_worldUUID]]] call DB_fnc_buildDLLRequest;
diag_log "DesoDB > Init DB Request";
diag_log _request;
[_request] call DB_fnc_sendRequest;
