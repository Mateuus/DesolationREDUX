/*
	fn_requestFreshSpawn
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_client","_location"];

if !(_client getVariable ["ReadyToSpawn",false]) exitWith {};
_unit = (createGroup CIVILIAN) createUnit [typeof _client, _location, [],0, "NONE"];
_unit allowDamage false;
_unit hideObjectGlobal true;

_unit addMPEventHandler ["MPKilled", DS_fnc_onPlayerKilled];
[_unit] call DS_fnc_setupLoadout;

_unit hideObjectGlobal false;
_unit allowDamage true;
[_unit] remoteExecCall ["DS_fnc_finishSpawn",_client];