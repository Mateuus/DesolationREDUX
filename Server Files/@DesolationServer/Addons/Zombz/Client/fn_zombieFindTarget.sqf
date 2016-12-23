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

params ["_zombieAgent"];

_target = objNull;

if ((face _zombieAgent) isEqualTo "SM_ZombzNoFace") exitWith
{
	objNull
};

_targets = allPlayers - entities "HeadlessClient_F";
_smokes = _zombieAgent nearObjects ["SmokeShell", 1000];
if !(_smokes isEqualTo []) then
{
	_targets append _smokes;
};

if !((player distance _zombieAgent) > 1000) then
{
	_passed = false;
	_distance = 1000;
	{
		_unit = _x;
		_tmpDistace = _unit distance _zombieAgent;
		_isvisible = _tmpDistace <= _distance;
		_detectionnumber = 0;
		_detected = false;
		if (isPlayer _unit) then
		{
			if (!((vehicle _unit) getVariable ["SM_HasZombieGuts",false]) && !((vehicle _unit) getVariable ["SM_HasBeenEaten",false]) && !(isObjectHidden (vehicle _unit)) && _isvisible) then
			{
				if ((vehicle _unit) isEqualTo _unit) then
				{
					switch (stance _unit) do 
					{
						case "STAND": { _detectionnumber = _detectionnumber + 0.50 };
						case "CROUCH": { _detectionnumber = _detectionnumber + 0.35 };
						case "PRONE": { _detectionnumber = _detectionnumber + 0.15 };
						default { _detectionnumber = _detectionnumber + 0 };
					};
				}
				else
				{
					_detectionnumber = random 0.50;
				};

				_detectionnumber = _detectionnumber + (_tmpDistace call
				{
					_distanceCheck = _this;
					if (_distanceCheck < 5) exitWith { 1 };
					if (_distanceCheck >= 5 && _distanceCheck < 10) exitWith { 0.50 };
					if (_distanceCheck >= 10 && _distanceCheck < 20) exitWith { 0.40 };
					if (_distanceCheck >= 20 && _distanceCheck < 35) exitWith { 0.30 };
					if (_distanceCheck >= 35 && _distanceCheck < 50) exitWith { 0.25 };
					if (_distanceCheck >= 50 && _distanceCheck < 100) exitWith { 0.20 };
					if (_distanceCheck >= 100 && _distanceCheck < 500) exitWith { 0.15 };
					if (_distanceCheck >= 500) exitWith { 0.10 };
				});

				_detectionnumber = _detectionnumber + random 0.50;

				_isInFront = [_zombieAgent,_unit] call SM_fnc_zombieCanSee;

				if (_isInFront) then 
				{
					_detectionnumber = _detectionnumber + 0.25;
				};

				if (_detectionnumber > 1) then 
				{ 
					_detected = true; 
				};
				_isvisible = _detected;
			}
			else
			{
				_isvisible = false;
			};
		}
		else
		{
			if (_isvisible) then
			{
				_distanceCheck = _tmpDistace;
				_detectionnumber = _detectionnumber + (_distanceCheck call
				{
					_distanceCheck = _this;
					if (_distanceCheck < 5) exitWith { 1 };
					if (_distanceCheck >= 5 && _distanceCheck < 10) exitWith { 0.50 };
					if (_distanceCheck >= 10 && _distanceCheck < 20) exitWith { 0.40 };
					if (_distanceCheck >= 20 && _distanceCheck < 35) exitWith { 0.30 };
					if (_distanceCheck >= 35 && _distanceCheck < 50) exitWith { 0.25 };
					if (_distanceCheck >= 50 && _distanceCheck < 100) exitWith { 0.20 };
					if (_distanceCheck >= 100 && _distanceCheck < 500) exitWith { 0.15 };
					if (_distanceCheck >= 500) exitWith { 0.10 };
				});

				_randomAddition = (random 0.50);

				_detectionnumber = _detectionnumber + _randomAddition;

				_isInFront = [_zombieAgent,_unit] call SM_fnc_zombieCanSee;

				if (_isInFront) then 
				{
					_detectionnumber = _detectionnumber + 0.25
				};

				if (_detectionnumber > 1) then 
				{ 
					_detected = true; 
				};

				_isvisible = _detected;
			};
		};
		if (_isvisible) then
		{
			if (_unit isKindOf "ChemLight") then
			{
				if (daytime >= 19 || daytime < 5) then
				{
					_distance = _tmpDistace;
					_target = _unit;
				};
			}
			else
			{
				_distance = _tmpDistace;
				_target = vehicle _unit;
			};
		};
	} forEach _targets;
};

_target