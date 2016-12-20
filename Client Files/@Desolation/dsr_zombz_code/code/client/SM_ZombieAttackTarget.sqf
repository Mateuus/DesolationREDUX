/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_zombie", objNull],["_target", objNull],["_soundLast", diag_tickTime],["_aggressiveArray", []],["_screamArray", []],["_vehicleHitArray", []],"_soundPitch","_aggressiveSound","_soundLast","_distance","_alive","_uncon","_count","_index","_damage","_screamSound","_vehicleHit","_vel","_dir","_targetInfection"];

if ((animationState _zombie) isEqualTo "unconscious") exitWith { _soundLast };
if !(_zombie isKindOf "SM_Zombz_Base") exitWith { _soundLast };

if ((diag_tickTime - _soundLast) >= SM_ZombieSoundDelayAggressive) then
{
	_aggressiveSound = selectRandom _aggressiveArray; 
	[_zombie, _aggressiveSound] remoteExecCall ["SM_Say3D", -2];
	_soundLast = diag_tickTime;
};

_distance = _zombie distance _target;
_alive = alive _zombie;
if (((_zombie distance2D _target) <= _distance) && _alive) then
{
	doStop _zombie;
	_zombie setdir (_zombie getDir _target);

	if !((vehicle _target) isKindOf "Man") then
	{
		_damage = random SM_ZombieDamageCar;

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
					if ((random 10) < 1) then
					{
						_screamSound = selectRandom _screamArray;
						[_x, _screamSound] remoteExecCall ["SM_Say3D", -2];
					};
					_x setDamage ((damage _x) + (SM_ZombieDamagePlayer / 25));
				} foreach (crew vehicle _target); 	
			};
		};

		_vehicleHit = selectRandom _vehicleHitArray;
		[_zombie, _vehicleHit] remoteExecCall ["SM_Say3D", -2];

		if (SM_SetVelocityOnHit) then
		{
			_vel = velocity (vehicle _target);
			_dir = direction _zombie;
			[(vehicle _target), [((_vel select 0) + ((sin _dir) * SM_ZombieDamageCarStrength)), ((_vel select 1) + ((cos _dir) * SM_ZombieDamageCarStrength)), ((_vel select 2) + (random 1))]] call SM_SetVelocity;
		};
	}
	else
	{
		_target setDamage ((damage _target) + SM_ZombieDamagePlayer);
		call SM_SetBlur;

		_screamSound = selectRandom _screamArray; 
		[_target, _screamSound] remoteExecCall ["SM_Say3D", -2];

		if (SM_SetVelocityOnHit) then
		{
			_vel = velocity _target;
			_dir = direction _zombie;
			[(vehicle _target), [((_vel select 0) + ((sin _dir) * SM_ZombieDamagePlayerStrength)), ((_vel select 1) + ((cos _dir) * SM_ZombieDamagePlayerStrength)), ((_vel select 2) + (random 1))]] call SM_SetVelocity;
		};
		
		if (SM_BleedingEnabled) then
		{
			if ((random SM_BleedChanceHigh) > SM_BleedChanceLow) then
			{
				_target setBleedingRemaining SM_BleedTime;
			};
		};

		if (SM_Infection) then
		{
			if (_target getVariable ["SM_InfectionImmune", false]) exitWith {};
			_dice = 100;
			if ((_dice < SM_InfectionChanceHigh) && (_dice > SM_InfectionChanceLow)) then
			{
				_targetInfection = _target getVariable ["SM_InfectionDOT", 0];
				if !(_targetInfection >= 1) then
				{
					_target setVariable ["SM_InfectionDOT", (_targetInfection + random SM_InfectionIncrease), true];
				};
			};
		};
	};
};

_soundLast
