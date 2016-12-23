/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

_maxZombies = ["maxZombies","SM"] call SM_fnc_getCfgValue;
_townTypes = ["townTypes","SM"] call SM_fnc_getCfgValue;
_zombieClasses = getArray (configFile >> "ZombieSettings" >> "zombieClasses");

_leftOverZombies = _maxZombies;

_centerPos = getArray (configFile >> "CfgWorlds" >> worldName >> "centerPosition");
_towns = nearestLocations [_centerPos, _townTypes, worldSize];

// This should only happen if there are no valid town names.
if (_towns isEqualTo []) exitWith
{
	"No valid towns to spawn zombies at" call SM_fnc_log;
};

_townCount = count _towns;

// Calculate the zombies per town, from the town count, and max zombies.
_zombiesPerTown = round (_maxZombies / _townCount);

// Why would this EVER be above it??
if (_zombiesPerTown > _maxZombies) then
{
	_zombiesPerTown = _zombiesPerTown - 1;
};

{
	// Get town position
	_position = locationPosition _x;

	// Spawn the required amount of zombies that the town needs.
	for "_i" from 1 to _zombiesPerTown do
	{
		if ([selectRandom _zombieClasses,_position] call SM_fnc_spawnZombie) then
		{
			_leftOverZombies = _leftOverZombies - 1;
		};
	};
} forEach _towns;

// There was an issue spawning a zombie, so randomly spawn the left overs around the map.
if (_leftOverZombies > 0) then
{
	for "_i" from 1 to _leftOverZombies do
	{
		_radius = floor (random worldSize);
		_angle = floor (random 360);
		_position = [round ((_centerPos select 0) + (_radius * (cos _angle))), round((_centerPos select 1) + (_radius * (sin _angle)))];
		if ([selectRandom _zombieClasses,_position] call SM_fnc_spawnZombie) then
		{
			_leftOverZombies = _leftOverZombies - 1;
		};
	};
};

// There was an issue spawning zombies around the map, so log how many didn't spawn.
// Zombies that are left over, are due to not finding a valid road within 200 meters.
if (_leftOverZombies > 0) then
{
	format["Zombies left over after spawning: %1", _leftOverZombies] call SM_fnc_log;
};

format["Zombies spawned: %1", (_maxZombies - _leftOverZombies)] call SM_fnc_log;

true
