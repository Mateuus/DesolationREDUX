private["_request"];

if !(isNil Global_Var_WORLD_UUID) then {
    DS_fnc_Send_Request = compile preprocessFileLineNumbers "path\to\sendRequest.sqf;
    DS_fnc_spawnCharacter = compile preprocessFileLineNumbers "path\to\spawnCharacter.sqf;
    ...
    _request = "{ 'dllfunction': '" + PROTOCOL_LIBARY_FUNCTION_EXECUTE_INIT_DB + "', 'dllarguments': {  'poolsize': " + Global_Var_POOLSIZE + ", 'worlduuid': '" + Global_Var_WORLD_UUID + "' } }"
    
    [_request] call DS_fnc_Send_Request;
} else {
     // log error
     diag_log "WORLD_UUID not set";
            
     // handle error, do something terrible like set the server on fire
}