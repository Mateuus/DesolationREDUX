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

params ["_zombieAgent"];
private["_target","_targets"];

if ((player distance _zombieAgent) > 1000) exitWith { ["", netID _zombieAgent] remoteExecCall ["SM_fnc_transferOwnership", 2]; objNull };

if ((face _zombieAgent) isEqualTo "SM_ZombzNoFace") exitWith { objNull };

_target = objNull;

_targets = SM_NearbyPlayers;
_smokes = _zombieAgent nearEntities ["SmokeShell", 1000];
_targets append _smokes;

_passed = false;
_distance = 1000;

{
	_unit = _x;
	if (isNull _unit) exitWith { false };
	_tmpDistace = _unit distance _zombieAgent;
	_isvisible = _tmpDistace <= _distance;
	_detectionnumber = 0.50;
	if (isPlayer _unit) then
	{
		if (!(_unit getVariable ["SM_HasZombieGuts",false]) && !(_unit getVariable ["SM_HasBeenEaten",false]) && !(isObjectHidden _unit) && _isvisible && ([_zombieAgent,_unit] call SM_fnc_zombieCanSee)) then
		{
            if ((vehicle _unit) == _unit) then
            {
                switch (stance _unit) do 
                {
                    case "STAND": { _detectionnumber = _detectionnumber + 0.50 };
                    case "CROUCH": { _detectionnumber = _detectionnumber + 0.35 };
                    case "PRONE": { _detectionnumber = _detectionnumber + 0.15 };
                };
            }
            else
            {
                _detectionnumber = 0.50;
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

			if (_detectionnumber > 1) then 
			{ 
				_isvisible = true; 
			}
			else
			{
				_isvisible = false;
			};
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

			if ([_zombieAgent,_unit] call SM_fnc_zombieCanSee) then 
			{
				_detectionnumber = _detectionnumber + 0.25;
			};

			if (_detectionnumber > 1) then 
			{ 
				_isvisible = true; 
			}
			else
			{
				_isvisible = false;
			};
		}
		else
		{
			_isvisible = false;
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
	true
} count _targets;

_target
