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

params ["_class","_center"];
private ["_return","_positionToSpawnZombie"];

// Why would this ever happen?
if (isNil "_class") exitWith {};
if (isNil "_center") exitWith {};

// Make sure that the zombie class is a valid class.
if !(_class isKindOf "SM_Zombz_Base") exitWith {};

try
{
	_buildingSpawnChance = ["buildingSpawnChance","SM"] call SM_fnc_getCfgValue;
	if ((random 100) < _buildingSpawnChance) then
	{
		_nearbuildings = _center nearObjects ["House",15];
		if !(_nearbuildings isEqualTo []) then
		{
			_spawnPositions = [];
			// Check if there is any buildings nearby to spawn the zombie at.
			for "_i" from 0 to ((count _nearbuildings) - 1) do
			{
				_buildingToSpawnZombie = _nearbuildings select _i;

				// this should almost never happen.... but if it does...
				if (isNull _buildingToSpawnZombie) then
				{
					if !((count _nearbuildings) > 1) throw "could not find any valid building to spawn zombie!";

					// what are the chances of selecthing another null building?
					_buildingToSpawnZombie = selectRandom _nearbuildings;
				};

				// Get the loot postions for the building.
				_positions = getArray (configFile >> "CfgItemSpawns" >> "Buildings" >> (typeOf _buildingToSpawnZombie) >> "positions");

				if (_positions isEqualTo []) throw "Failed to spawn zombie, no valid building spawn positions";

				_spawnPositions pushBack [_positions, _buildingToSpawnZombie];
			};

			// Why would this ever happen?!?!
			// This is kinda a useless check, but you never know with arma...
			if (_spawnPositions isEqualTo []) throw "No valid spawn positons found";

			// Select a random building from the spawn buildings provided.
			_data = selectRandom _spawnPositions;
			_positionToSpawnZombie = ASLtoATL(AGLtoASL((_data select 1) modelToWorld selectRandom(_data select 0)));
		};
	};

	if (_positionToSpawnZombie isEqualTo []) then
	{
		// calculate a random postion based on the center positon.
		_radius = floor ((random (1 - 5)) + 5);
		_angle = floor (random 360);
		_roads = _center nearRoads 200;

		// Error checking to make sure there are roads nearby.
		if (_roads isEqualTo []) throw "No valid roads to spawn a zombie at";

		_center = getPosATL (selectRandom _roads);
		_positionToSpawnZombie = [round ((_center select 0) + (_radius * (cos _angle))), round((_center select 1) + (_radius * (sin _angle)))];	
	};

	if (_positionToSpawnZombie isEqualTo []) throw "Could not calculate zombie spawn position!";

	// create the zombie agent...
	_zombieAgent = createAgent [_class, _positionToSpawnZombie, [], 0, "NONE"];

	// disable the zombie simulation to save resources.
	_zombieAgent enableSimulationGlobal false;

	// No need to have the zombie showing if it's not doing anything.
	_zombieAgent hideObjectGlobal true;

	// Set the variable owner to the server
	_zombieAgent setVariable ["SM_ZombieOwner", "__SERVER__"];

	// Push the zombie back into a idle state.
	SM_IdleZombies pushBack (netId _zombieAgent);

	// Set zombie variables
	_zombieAgent setCombatMode "RED";
	_zombieAgent allowFleeing 0;
	_zombieAgent enableAttack false;
	_zombieAgent setUnitPos "UP";
	_zombieAgent disableAI "ALL";
	_zombieAgent setSpeaker "NoVoice";

	// why does the zombie need glasses?
	// I never understood why zombies spawn with glasses... i must be missing something.
	removegoggles _zombieAgent;

	// It's not a zombie without damage!
	_zombieAgent setdamage 0.7;

	// Because why not?
	_zombieAgent setDir (random 360);

	// Fixes zombies just standing in one place, even though they are being controlled and being told to move.
	_zombieAgent setHitIndex [10, 0];
	_zombieAgent setHitPointDamage ["hitLegs", 0];

	// Give the zombies a hat, if they have one (mostly arma 2 zombies)
	_headGear = getText (configFile >> "CfgVehicles" >> _class >> "headgear");
	if (_headGear != "") then
	{
		_zombieAgent addHeadgear _headGear;
	};

	// Give them there zombies some faces!
	if (_zombieAgent isKindOf "SM_Zombz_FemaleBase") then
	{
		_face = selectRandom (getArray (configFile >> "ZombieSettings" >> "FemaleFaces"));
		[_zombieAgent, _face] remoteExecCall ["setFace", 0, _zombieAgent];
	}
	else
	{
		_face = selectRandom (getArray (configFile >> "ZombieSettings" >> "MaleFaces"));
		[_zombieAgent, _face] remoteExecCall ["setFace", 0, _zombieAgent];
	};

	// When the zombie dies, we need to know about it!
	_zombieAgent addMPEventHandler ["MPKilled", { _this call SM_fnc_onMPKilled}];

	_return = true;
} 
catch 
{
	format["Erorr spawning zombie: %1", _exception] call SM_fnc_log;
};

_return
