/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_zombiesToPass","_group","_zombieGroup","_zombie","_owner","_ownerObj","_alreadyRunning","_playersToPassZombies","_distance","_closestPlayer","_distanceZ","_passed"];
_zombiesToPass = [];

{
	_group = _x;
	_zombies = units _group;

	// fix for emepty group "spam" in RPT.
	if (_zombies isEqualTo []) then
	{
		deleteGroup _group;
	};
	if (_group getVariable ["SM_IsZombieGroup", false]) then
	{
		{
			_zombie = _x;
			if (alive _zombie) then
			{
				_closestPlayer = objNull;
				_distance = 1000;
				{
					_player = _x;
					if ((_zombie distance _player) < _distance) then
					{
						_distance = _zombie distance _player;
						_closestPlayer = _player;
					};
				} forEach allPlayers;
				if (isNull _closestPlayer) then
				{
					deleteVehicle _zombie;
				} 
				else
				{
					_group = _closestPlayer getVariable ["SM_ZombieGroup", grpNull];
					if (isNull _group) then
					{
						_group = createGroup SM_ZombieSide;
						_closestPlayer setVariable ["SM_ZombieGroup", _group];
						_group setVariable ["SM_IsZombieGroup", true];
					};

					if !(_zombie in (units _group)) then
					{
						_owner = objectFromNetId (_zombie getVariable ["SM_ZombieOwner", ""]);
						if !(isNull _owner) then
						{ 
							_zombieInfo = _owner getVariable ["SM_CurrentZombies", [0, []]];
							_count = _zombieInfo select 0;
							_count = _count - 1;
							_zombieArray = _zombieInfo select 1;
							_index = [_zombieArray, (netid _zombie)] call SM_System_FindTask;
							if !(_index isEqualTo -1) then
							{
								_zombieArray deleteAt _index;
							};

							if !(_count isEqualTo (count _zombieArray)) then
							{
								_count = 0;
								{
									_zombie = objectFromNetId _x;
									if ((alive _zombie) || !(isNull _zombie)) then
									{
										_count = _count + 1;
									};
								} forEach _zombieArray;
							};
							_owner setVariable ["SM_CurrentZombies", [_count, _zombieArray]];
						};
						
						[_zombie] joinSilent _group;
						_group setGroupOwner (owner _closestPlayer);
						_zombie setVariable ["SM_ZombieOwner", netId _closestPlayer];
						[_closestPlayer, "ZombieReceive", [netId _zombie]] call SM_Network_SendMessage;

						_targetData = _closestPlayer getVariable ["SM_CurrentZombies", [0, []]];
						_count = _targetData select 0;
						_count = _count + 1;
						_array = _targetData select 1;
						_array pushBack (netId _zombie);
						if !(_count isEqualTo (count _array)) then
						{
							_count = 0;
							{
								_zombie = objectFromNetId _x;
								if ((alive _zombie) || !(isNull _zombie)) then
								{
									_count = _count + 1;
								};
							} forEach _array;
						};
						_closestPlayer setVariable ["SM_CurrentZombies", [_count, _array]];
					};
				};
			};
		} forEach _zombies;
	};
} forEach allGroups;

true
