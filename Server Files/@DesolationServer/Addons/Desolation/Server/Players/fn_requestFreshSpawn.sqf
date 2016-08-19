/*
	fn_requestFreshSpawn
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_client","_location"];

if !(_client getVariable ["ReadyToSpawn",false]) exitWith {};
_playerUID = getPlayerUID _client;
_unit = (createGroup CIVILIAN) createUnit [typeof _client, _location, [],0, "NONE"];
_unit allowDamage false;
_unit hideObjectGlobal true;
[_unit] call DS_fnc_setupLoadout;
_unit hideObjectGlobal false;
_unit allowDamage true;
_unit setVariable["DSPlayerUID",_playerUID,true];
_unit setVariable["DS_statFood",100,true];
_unit setVariable["DS_statDrink",100,true];
_unit setVariable["DS_statBloodLeft",16000,true];
_unit setVariable["DS_statBloodPressure",80,true];
_unit setVariable["DS_statTemperature",98.6,true];
_unit setVariable["DS_statInfection",0,true];
_unit setVariable["DS_statWetness",0,true];
_unit setVariable["DS_statSoiled",0,true];
_unit setVariable["DS_statSanity",0,true];
_unit addMPEventHandler ["MPKilled", {_this call DS_fnc_dbOnPlayerKilled}];
[_unit] remoteExecCall ["DS_fnc_finishSpawn",_client];