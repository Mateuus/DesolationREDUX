/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

if !(SM_CurrentZombiesSpawned isEqualTo []) then 
{
	private["_currentZombiesDeleted","_zombieNetID","_zombie","_playerIsNear"];
	_currentZombiesDeleted = [];
	{
		_zombieNetID = _x;
		_zombie = objectFromNetId _zombieNetID;
		if !(isNull _zombie) then
		{
			_playerIsNear = false;
			{
				if ((_zombie distance2D (position _x)) <= SM_ZombieCleanupDistance) exitWith
				{
					_playerIsNear = true;
				};
			} forEach allPlayers;
			if !(_playerIsNear) exitWith
			{
				_currentZombiesDeleted pushBack _forEachIndex;
				deleteVehicle _zombie;
			};

			if (_zombie call SM_IsSafezoneNear) exitWith
			{
				deleteVehicle _zombie;
				_currentZombiesDeleted pushBack _forEachIndex;
			};
		}
		else
		{
			_currentZombiesDeleted pushBack _forEachIndex;
		};		
	} forEach SM_CurrentZombiesSpawned;
	if !(_currentZombiesDeleted isEqualTo []) then
	{
		{
			SM_CurrentZombiesSpawned deleteAt (_x - _forEachIndex);
		} forEach _currentZombiesDeleted;
	};
};

if !(DeadZombieBodys isEqualTo []) then 
{
	private["_deadBodysDeleted","_zombie"];
	_deadBodysDeleted = [];
	{
		_x params [["_zombieNetID", ""],["_timeFromDeath", diag_tickTime]];
		if !(_zombieNetID isEqualTo "") then
		{
			_zombie = objectFromNetId _zombieNetID;
			if !(isNull _zombie) then
			{
				if ((diag_tickTime - _timeFromDeath) > SM_ZombieCleanupDeath) then
				{
					_attachedObj = attachedObjects _zombie;
					if!(_attachedObj isEqualTo []) then
					{
						{
							deleteVehicle _x;
						} forEach _attachedObj;
					};
					deleteVehicle _zombie;
					_deadBodysDeleted pushBack _forEachIndex;
				};
			}
			else
			{
				_deadBodysDeleted pushBack _forEachIndex;
			};
		};
	} forEach DeadZombieBodys;
	if !(_deadBodysDeleted isEqualTo []) then
	{
		{
			DeadZombieBodys deleteAt (_x - _forEachIndex);
		} forEach _deadBodysDeleted;
	};
};

true
