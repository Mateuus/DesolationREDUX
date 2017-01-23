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
