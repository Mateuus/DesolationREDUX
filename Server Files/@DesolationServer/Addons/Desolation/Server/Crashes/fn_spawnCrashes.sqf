/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_numberOfCrashes = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "Settings" >> "NumberOfCrashesToSpawn");
_maxSearchDistance = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "Settings" >> "MaxSearchDistance");
_mapsize = call BIS_fnc_mapSize;
for "_i" from 1 to _numberOfCrashes do
{
_crashType = DS_HeliCrash_CrashTypes selectRandom;
_heliType = getText configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "HeliClass");
_spawnAlt = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SpawnAltitude");

_crashPos = [_crashType,_maxSearchDistance] call DS_fnc_getCrashLocation;
_spawnDirection = random 360;

_spawnPos = [(_crashPos select 0) + sin(_dir)*_mapsize, (_crashPos select 1) + cos(_dir)*_mapsize,_spawnAlt];

_heli = _heliType createVehicle _spawnPos;
//--To do--- Create Waypoint and send helicopter to crash

};