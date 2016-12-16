/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private["_zombiesToPass","_group","_zombieGroup","_zombie","_owner","_ownerObj","_alreadyRunning","_playersToPassZombies","_distance","_closestPlayer","_distanceZ","_passed"];
_zombiesToPass = [];

{
	_group = _x;
	if (_group getVariable ["SM_IsZombieGroup", false]) then
	{
		_zombies = units _group;
		if (_zombies isEqualTo []) then
		{
			deleteGroup _group;
		}
		else
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
							[_zombie] joinSilent _group;
							_group setGroupOwner (owner _closestPlayer);
							[_closestPlayer, "ZombieReceive", [netId _zombie]] call SM_Network_SendMessage;
						};
					};
				};
			} forEach _zombies;
		};
	};
} forEach allGroups;

true
