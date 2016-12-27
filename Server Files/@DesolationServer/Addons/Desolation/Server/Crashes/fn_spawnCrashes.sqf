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

_numberOfCrashes = getnumber (configFile >> "CfgHeliCrashes" >> "Settings" >> "NumberOfCrashesToSpawn");
_maxSearchDistance = getnumber (configFile >> "CfgHeliCrashes" >> "Settings" >> "MaxSearchDistance");
_maxTime = getnumber (configFile >> "CfgHeliCrashes" >> "Settings" >> "MaxTimeBetweenCrashes");
_minTime = getnumber (configFile >> "CfgHeliCrashes" >> "Settings" >> "MinTimeBetweenCrashes");
_mapsize = worldSize;

for "_i" from 1 to _numberOfCrashes do
{
	_crashType = selectRandom DS_HeliCrash_CrashTypes;
	_heliType = getText (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "HeliClass");
	_wreckClass = getText (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "WreckClass");
	_smokepos = getArray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SmokePos");
	_smokeSize = getnumber (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SmokeSize");
	_wreckSmoke = getnumber (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "WreckSmoke");
	_spawnAlt = getnumber (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SpawnAltitude");

	_crashPos = [_crashType, _maxSearchDistance] call DS_fnc_getCrashLocation;
	
	_spawnDirection = random 360;
	_spawnPos = [(_crashPos select 0) + sin(_spawnDirection) * _mapsize, (_crashPos select 1) + cos(_spawnDirection) * _mapsize, _spawnAlt];

	_heli = _heliType createVehicle _spawnPos;

	(group _heli) move _crashPos;
	(group _heli) setSpeedMode "full";
	waituntil {(_heli distance2d _crashPos) < 500};
	_wreckPos = [_heli, _wreckClass, _smokeSize, _smokepos, _wreckSmoke] call DS_fnc_heliCrashAnim;
	[_wreckPos, _crashType] call DS_fnc_spawnCrashLoot;
	_waitTime = random [_minTime, (_maxTime/2), _maxTime];
	_waitTime = _waitTime * 60;
	uiSleep _waitTime; 
};

true