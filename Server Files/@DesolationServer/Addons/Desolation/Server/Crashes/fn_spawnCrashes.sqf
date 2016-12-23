/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_numberOfCrashes = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "Settings" >> "NumberOfCrashesToSpawn");
_maxSearchDistance = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "Settings" >> "MaxSearchDistance");
_maxTime = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "Settings" >> "MaxTimeBetweenCrashes");
_minTime = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "Settings" >> "MinTimeBetweenCrashes");
_mapsize = call BIS_fnc_mapSize;
for "_i" from 1 to _numberOfCrashes do
{
_crashType = DS_HeliCrash_CrashTypes selectRandom;
_heliType = getText configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "HeliClass");
_wreckClass = getText configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "WreckClass");
_smokepos = getArray configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SmokePos");
_smokeSize = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SmokeSize");
_wreckSmoke = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "WreckSmoke");
_spawnAlt = getnumber configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SpawnAltitude");

_crashPos = [_crashType,_maxSearchDistance] call DS_fnc_getCrashLocation;
_spawnDirection = random 360;

_spawnPos = [(_crashPos select 0) + sin(_dir)*_mapsize, (_crashPos select 1) + cos(_dir)*_mapsize,_spawnAlt];

_heli = _heliType createVehicle _spawnPos;
	(group _heli) move [_crashPos, 0];
	(group _heli) setSpeedMode "full";
	waituntil{(_heli distance2d _crashPos) < 50};
_wreckPos = [_heli,_wreckClass,_smokeSize,_smokepos,_wreckSmoke] call DS_fnc_heliCrashAnim;
[_wreckPos,_crashType,] call DS_fnc_spawnCrashLoot;
_waitTime = random [_minTime,(_maxTime/2),_maxTime];
_waitTime = _waitTime * 60;
sleep(_waitTime); 
};