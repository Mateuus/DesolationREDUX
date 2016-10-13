#include "constants.hpp"

private["_request"];

//_worldUUID = call compile (["Enabled","DS"] call BASE_fnc_getCfgValue);
//_poolSize = call compile (["Enabled","DS"] call BASE_fnc_getCfgValue);

_worldUUID = Global_Var_WORLD_UUID;
if(isNil _worldUUID) exitWith {diag_log "WORLD IDENTIFICATION IS NOT SET, THE DATABASE PLUGIN WILL NOT RUN";};

_poolSize = Global_Var_POOLSIZE;
if(isNil _worldUUID) exitWith {diag_log "THREAD POOL SIZE IS NOT SET, THE DATABASE PLUGIN WILL NOT RUN";};

_request = format [FORMATSTRING_INIT_DB, _poolSize, _worldUUID];

[_request] call DS_fnc_Send_Request;
