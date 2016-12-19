/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params ["_zombieNetIds"];
if !(_zombieNetIds isEqualType []) then
{
	if !(_zombieNetIds in SM_IdleZombies) then
	{
		_zombie = objectFromNetId _zombieNetIds;
		_isNotLocal = false;
		_startTime = diag_tickTime;
		waitUntil 
		{
			_localZombie = local _zombie;
			if (((diag_tickTime - _startTime) >= 3) && !_localZombie) then
			{
				_isNotLocal = true;
				true
			}
			else
			{
				_localZombie
			}
		};

		if (_isNotLocal) exitWith 
		{
			["UpdateLocality",[_zombieNetIds,(netId player)]] call SM_Network_SendMessage;
		};

		_zombie setVariable ["SM_AlreadyRunning",(getPlayerUID player),true];
		_pos = _zombie call SM_ZombieFindPositionWander;
		if !(_pos isEqualTo []) then
		{
			_zombie moveTo _pos;
			_zombie setVariable ["SM_LastTargetCheck",diag_ticktime];
		};
		_zombie setVariable ["SM_ZombieSoundDelayMoan",diag_tickTime - random SM_ZombieSoundDelayMoan];
		SM_IdleZombies pushBack _zombieNetIds;
	};
}
else
{
	{
		if !(_x in SM_IdleZombies) then
		{
			_zombie = objectFromNetId _x;
			_isNotLocal = false;
			_startTime = diag_tickTime;
			waitUntil 
			{
				_localZombie = local _zombie;
				if (((diag_tickTime - _startTime) >= 3) && !_localZombie) then
				{
					_isNotLocal = true;
					true
				}
				else
				{
					_localZombie
				}
			};

			if (_isNotLocal) exitWith 
			{
				["UpdateLocality",[_X,(netId player)]] call SM_Network_SendMessage;
			};

			_zombie setVariable ["SM_AlreadyRunning",(getPlayerUID player),true];
			_pos = _zombie call SM_ZombieFindPositionWander;
			if !(_pos isEqualTo []) then
			{
				_zombie moveTo _pos;
				_zombie setVariable ["SM_LastTargetCheck",diag_ticktime];
			};
			_zombie setVariable ["SM_ZombieSoundDelayMoan",diag_tickTime - random SM_ZombieSoundDelayMoan];
			SM_IdleZombies pushBack _x;
		};
	} forEach _zombieNetIds;
};

true
