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

params ["_zomieAgent","_target","_soundLast","_distance"];

if ((animationState _zomieAgent) isEqualTo "unconscious") exitWith { _soundLast };

if ((diag_tickTime - _soundLast) >= 3) then
{
	_aggressiveSound = selectRandom _aggressiveArray; 
	[_zomieAgent, _aggressiveSound] remoteExecCall ["Say3D", -2];
	_soundLast = diag_tickTime;
};

_distance = _zomieAgent distance _target;
_alive = alive _zomieAgent;
if (((_zomieAgent distance2D _target) <= _distance) && _alive) then
{
	doStop _zomieAgent;
	_zomieAgent setdir (_zomieAgent getDir _target);

	if !((vehicle _target) isKindOf "Man") then
	{
		_damage = random 0.02;

		_count = count ((getAllHitPointsDamage _target) select 0);
		_index = 0;

		while {_count > _index} do
		{
			if !((((getAllHitPointsDamage _target) select 0) select _index) isEqualTo "HitFuel") then 
			{
				_target setHitIndex [_index, (_target getHitIndex _index) + _damage]
			};
			_index = _index + 1;
		};

		if ((getNumber(configfile >> "CfgVehicles" >> (typeOf _target) >> "armor")) < 90) then
		{
			if !(canmove _target) then
			{
				{
					if ((random 5) < 1) then
					{
						_screamSound = selectRandom (getArray (configFile >> "SM_Zombz" >> "SM_ScreamArray")); 
						[_x, _screamSound] remoteExecCall ["Say3D", -2];
					};
					_x setDamage ((damage _x) + (0.15 / 25));
				} foreach (crew vehicle _target); 	
			};
		};

		_vehicleHit = selectRandom (getArray (configFile >> "SM_Zombz" >> "SM_VehicleHitArray"));
		[_zomieAgent, _vehicleHit] remoteExecCall ["Say3D", -2];

		_infectionEnabled = ["infectionEnabled","SM"] call SM_fnc_getCfgValue;
		if (_infectionEnabled) then
		{
			_vel = velocity (vehicle _target);
			_dir = direction _zomieAgent;
			[(vehicle _target), [((_vel select 0) + ((sin _dir) * 1.5)), ((_vel select 1) + ((cos _dir) * 1.5)), ((_vel select 2) + (random 1))]] call SM_fnc_targetSetVelocity;
		};
	}
	else
	{
		_target setDamage ((damage _target) + 0.15);
		call SM_fnc_blurEffect;

		_screamSound = selectRandom (getArray (configFile >> "SM_Zombz" >> "SM_ScreamArray")); 
		[_target, _screamSound] remoteExecCall ["Say3D", -2];

		_velocityEnabled = ["velocityEnabled","SM"] call SM_fnc_getCfgValue;
		if (_velocityEnabled) then
		{
			_vel = velocity _target;
			_dir = direction _zomieAgent;
			[(vehicle _target), [((_vel select 0) + ((sin _dir) * 1)), ((_vel select 1) + ((cos _dir) * 1)), ((_vel select 2) + (random 1))]] call SM_fnc_targetSetVelocity;
		};
		
		_bleedEnabled = ["bleedEnabled","SM"] call SM_fnc_getCfgValue;
		if (_bleedEnabled) then
		{
			_bleedChance = ["bleedChance","SM"] call SM_fnc_getCfgValue;
			if (_bleedChance > random 100) then
			{
				_target setBleedingRemaining 20;
			};
		};

		_infectionEnabled = ["infectionEnabled","SM"] call SM_fnc_getCfgValue;
		if (_infectionEnabled) then
		{
			if (_target getVariable ["SM_InfectionImmune", false]) exitWith {};
			_infectionChance = ["infectionChance","SM"] call SM_fnc_getCfgValue;
			if (_infectionChance > random 100) then
			{
				_targetInfection = _target getVariable ["SM_InfectionDOT", 0];
				if !(_targetInfection >= 1) then
				{
					_target setVariable ["SM_InfectionDOT", (_targetInfection + random 0.25)];
				};
			};
		};
	};
};

_soundLast
