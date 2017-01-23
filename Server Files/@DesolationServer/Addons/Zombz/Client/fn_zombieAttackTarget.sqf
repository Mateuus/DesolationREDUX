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

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

params ["_zombieAgent","_target","_soundLast","_distance"];

if ((animationState _zombieAgent) isEqualTo "unconscious") exitWith { _soundLast };

if ((diag_tickTime - _soundLast) >= 3) then
{
	_aggressive = selectRandom getArray (configFile >> "SM_Zombz" >> "SM_AggressiveArray");
	[_zombieAgent, _aggressive] remoteExecCall ["Say3D", SM_NearbyPlayers];
	_soundLast = diag_tickTime;
};

_distance = _zombieAgent distance _target;
_alive = alive _zombieAgent;
if (((_zombieAgent distance2D _target) <= _distance) && _alive) then
{
	doStop _zombieAgent;
	_zombieAgent setdir (_zombieAgent getDir _target);

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
						[_x, _screamSound] remoteExecCall ["Say3D", SM_NearbyPlayers];
					};

					//--- TODO: Replace this "call" with an actual function
					{
						DS_var_Blood = DS_var_Blood - (random(2500) max 500);
						_bleedEnabled = ["bleedEnabled","SM"] call SM_fnc_getCfgValue;
						if (_bleedEnabled) then
						{
							_bleedChance = ["bleedChance","SM"] call SM_fnc_getCfgValue;
							if (random 100 < _bleedChance) then
							{
								DS_var_damagedBy pushBack objNull;
								_selections = ["spine3","leftforearm","rightforearm","lefthand","righthand","leftupleg","rightupleg","leftleg","rightleg","leftfoot","rightfoot","head","pelvis"];
								[objNull, selectRandom _selections] call DS_fnc_onHitPartReceived;
							};
						};
						_infectionEnabled = ["infectionEnabled","SM"] call SM_fnc_getCfgValue;
						if (_infectionEnabled) then
						{
							if (DS_var_immune) exitWith {};
							_infectionChance = ["infectionChance","SM"] call SM_fnc_getCfgValue;
							if (random 100 < _infectionChance) then
							{
								if !(DS_var_infectionDOT >= 1) then
								{
									DS_var_infectionDOT = DS_var_InfectionDOT + random 0.25;
								};
							};
						};
					} remoteExecCall ["call",_x];
					true
				} count (crew vehicle _target); 	
			};
		};

		_vehicleHit = selectRandom (getArray (configFile >> "SM_Zombz" >> "SM_VehicleHitArray"));
		[_zombieAgent, _vehicleHit] remoteExecCall ["Say3D", SM_NearbyPlayers];

		_infectionEnabled = ["infectionEnabled","SM"] call SM_fnc_getCfgValue;
		if (_infectionEnabled) then
		{
			_vel = velocity (vehicle _target);
			_dir = direction _zombieAgent;
			[(vehicle _target), [((_vel select 0) + ((sin _dir) * 1.5)), ((_vel select 1) + ((cos _dir) * 1.5)), ((_vel select 2) + (random 1))]] call SM_fnc_targetSetVelocity;
		};
	}
	else
	{
		DS_var_Blood = DS_var_Blood - (random(5000) max 1000);
		call SM_fnc_blurEffect;

		_screamSound = selectRandom (getArray (configFile >> "SM_Zombz" >> "SM_ScreamArray")); 

		[_target, _screamSound] remoteExecCall ["Say3D", SM_NearbyPlayers];

		_velocityEnabled = ["velocityEnabled","SM"] call SM_fnc_getCfgValue;
		if (_velocityEnabled) then
		{
			_vel = velocity _target;
			_dir = direction _zombieAgent;
			[(vehicle _target), [((_vel select 0) + ((sin _dir) * 1)), ((_vel select 1) + ((cos _dir) * 1)), ((_vel select 2) + (random 1))]] call SM_fnc_targetSetVelocity;
		};
		
		_bleedEnabled = ["bleedEnabled","SM"] call SM_fnc_getCfgValue;
		if (_bleedEnabled) then
		{
			_bleedChance = ["bleedChance","SM"] call SM_fnc_getCfgValue;
			if (random 100 < _bleedChance) then
			{
				DS_var_damagedBy pushBack _zombieAgent;
				_selections = ["spine3","leftforearm","rightforearm","lefthand","righthand","leftupleg","rightupleg","leftleg","rightleg","leftfoot","rightfoot","head","pelvis"];
				[_zombieAgent,selectRandom _selections] call DS_fnc_onHitPartReceived;
			};
		};

		_infectionEnabled = ["infectionEnabled","SM"] call SM_fnc_getCfgValue;
		if (_infectionEnabled) then
		{
			if (DS_var_immune) exitWith {};
			_infectionChance = ["infectionChance","SM"] call SM_fnc_getCfgValue;
			if (random 100 < _infectionChance) then
			{
				if !(DS_var_infectionDOT >= 1) then
				{
					DS_var_infectionDOT = DS_var_InfectionDOT + random 0.25;
				};
			};
		};
	};
};

_soundLast
