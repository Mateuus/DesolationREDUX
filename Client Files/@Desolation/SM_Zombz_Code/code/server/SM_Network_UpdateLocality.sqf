/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_zombieNetId", ""],["_targetNetId", ""],"_zombie","_target","_alreadyRunning","_targetGroup","_owner","_zombieInfo","_count","_zombieArray","_targetData","_array","_passed"];
_zombie = objectFromNetId _zombieNetId;
_target = objectFromNetId _targetNetId;

if (isNull _zombie) exitWith 
{ 
	"Problem fetching zombie to update locality to" call SM_Util_log; 
};
if (isNull _target) exitWith 
{ 
	"Problem fetching player to update locality to" call SM_Util_log; 
	deleteVehicle _zombie; 
};

if (alive _zombie) then
{
	_serverGroup = missionNamespace getVariable ["SM_LeaderGroup",grpNull];
	if (isNull _serverGroup) then
	{
		_serverGroup = createGroup SM_ZombieSide;
		missionNamespace setVariable ["SM_ZombieGroup", _serverGroup];	
	};
	[_zombie] joinSilent _serverGroup;
	_serverGroup setGroupOwner -2;

	uiSleep 0.3;

	_group = _target getVariable ["SM_ZombieGroup", grpNull];
	if (isNull _group) then
	{
		_group = createGroup SM_ZombieSide;
		_target setVariable ["SM_ZombieGroup", _group];
		_group setVariable ["SM_IsZombieGroup", true];
	};

	if (_zombie in (units _group)) exitWith
	{
		_group setGroupOwner (owner _target);
		[_target, "ZombieReceive", [(netId _zombie)]] call SM_Network_SendMessage;
	};

	_owner = objectFromNetId (_zombie getVariable ["SM_ZombieOwner", _targetNetId]);
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
	_group setGroupOwner (owner _target);
	_zombie setVariable ["SM_ZombieOwner", netId _target];

	[_target, "ZombieReceive", [(netId _zombie)]] call SM_Network_SendMessage;

	_targetData = _target getVariable ["SM_CurrentZombies", [0, []]];
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
	_target setVariable ["SM_CurrentZombies", [_count, _array]];
};

true
