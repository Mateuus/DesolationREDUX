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
_maxTime = getnumber (configFile >> "CfgHeliCrashes" >> "Settings" >> "MaxTimeBetweenCrashes");
_minTime = getnumber (configFile >> "CfgHeliCrashes" >> "Settings" >> "MinTimeBetweenCrashes");
_mapsize = worldSize;

for "_i" from 1 to _numberOfCrashes do
{
	_crashType = selectRandom DS_HeliCrash_CrashTypes;
	_heliType = getText (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "HeliClass");
	if (_heliType isEqualTo "") exitWith {diag_log "Crashes> Error no heliType defined!"};
	_wreckClass = getText (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "WreckClass");
	_smokepos = getArray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SmokePos");
	_smokeSize = getnumber (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SmokeSize");
	_wreckSmoke = getnumber (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "WreckSmoke");
	_spawnAlt = getnumber (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashType >> "SpawnAltitude");

	_crashPos = [true, false] call DS_fnc_GenRandMapPos;
	
	_spawnDirection = random 360;
	_spawnPos = [(_crashPos select 0) + sin(_spawnDirection) * _mapsize, (_crashPos select 1) + cos(_spawnDirection) * _mapsize, _spawnAlt];
	_timeout = diag_ticktime + 20;
	
	
	

	_heli = _heliType createVehicle [0,0,0];

	createVehicleCrew _heli;
	_heli engineOn true;
	(group _heli) move _crashPos;
	_heli setPosATL _spawnPos;
	(group _heli) setSpeedMode "full";
	while { (_timeout - diag_tickTime) >= 0} do
	{
		_heli setVelocity [0,0,0];
		uiSleep 0.5;
	};
	waituntil {(_heli distance2d _crashPos) < 500};
	_wreckPos = [_heli, _wreckClass, _smokeSize, _smokepos, _wreckSmoke] call DS_fnc_heliCrashAnim;
	[_wreckPos, _crashType] call DS_fnc_spawnCrashLoot;
	_waitTime = random [_minTime, (_maxTime/2), _maxTime];
	_waitTime = _waitTime * 60;
	uiSleep _waitTime; 
};

true