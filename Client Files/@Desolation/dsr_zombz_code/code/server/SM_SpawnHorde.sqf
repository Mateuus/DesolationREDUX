/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_zombieClasses","_zombieMaxDistance","_zombieMinDistance","_maxDistance","_minDistance","_zombiesToSpawn","_inZone","_zone","_hordeChance","_group","_player","_currentZombies","_currentZombieSpawned","_zombiesToPass","_isValid","_data","_zombiePos","_minSpawn","_randomPos","_random","_zombie","_passed","_marker"];

"player Check" call SM_Util_Log;
if !(count (allPlayers - entities "HeadlessClient_F") > 0) exitWith { true }; 

_hordeChance = random 100;

if (SM_CurrentZombieCount >= SM_MaxZombies) exitWith {};

"checking horde chance..." call SM_Util_Log;
if (_hordeChance < SM_SpawnHordeChance) then
{
	_group = grpNull;

	"Starting Zombie Check" call SM_Util_Log;

	_player = vehicle (selectRandom (allPlayers - entities "HeadlessClient_F"));
	_currentZombies = 0;
	_currentZombieSpawned = [];
	_zombiesToPass = [];
	_data = _player call SM_PlayerZombieCount;
	_currentZombies = _data select 0;
	_currentZombieSpawned = _data select 1;

	_isValid = _player call SM_SpawnCheck;

	if (_isValid) then
	{
		"Spawning Zombies" call SM_Util_Log;


		if (SM_HordeZonesEnabled) then
		{
			_inZone = false;
			if (SM_HordeUseZombieZones) then
			{
				{
					if ((_player distance2D (_x select 0)) <= (_x select 1)) exitWith
					{
						_inZone = true;
						_zone = _forEachIndex;
					};
				} forEach SM_ZombieZones;
			}
			else
			{
				{
					if ((_player distance2D (_x select 0)) <= (_x select 1)) exitWith
					{
						_inZone = true;
						_zone = _forEachIndex;
					};
				} forEach SM_ZombieHordeZones;
			};

			if (_inZone) then
			{
				if !(SM_HordeUseZombieZones) then
				{
					_zoneData = SM_ZombieZones select _zone;
					_zombiesToSpawn = (round(random (_zoneData select 6))) max (_zoneData select 7);
					_minDistance = _zoneData select 2;
					_maxDistance = _zoneData select 3;
					_zombieMinDistance = _zoneData select 4;
					_zombieMaxDistance = _zoneData select 5;
					_zombieClasses = _zoneData select 17;
					if ((_zombieClasses) isEqualTo []) then
					{
						_zombieClasses = SM_HordeClasses;
						if (_zombieClasses isEqualTo []) then
						{
							_zombieClasses = SM_ZombieClasses;
						};
					};
				}
				else
				{
					_zoneData = SM_ZombieZones select _zone;
					_zombiesToSpawn = (round (random SM_MaxZombiesInHorde)) max SM_MinZombiesInHorde;
					_minDistance = _zoneData select 4;
					_maxDistance = _zoneData select 3;
					_zombieMinDistance = _zoneData select 5;
					_zombieMaxDistance = _zoneData select 6;
					_zombieClasses = _zoneData select 18;
					if ((_zombieClasses) isEqualTo []) then
					{
						_zombieClasses = SM_HordeClasses;
						if (_zombieClasses isEqualTo []) then
						{
							_zombieClasses = SM_ZombieClasses;
						};
					};
				};
			}
			else
			{
				if (SM_HordeCanSpawnRandomly) then
				{
					if (_player call SM_IsPlayerInTown) then
					{
						_minDistance = SM_HordeMinDistanceTown;
						_maxDistance = SM_HordeMaxDistanceTown;
						_zombieMinDistance = SM_HordeSpawnMinDistanceFromPositionTown;
						_zombieMaxDistance = SM_HordeSpawnMaxDistanceFromPositionTown;
						_zombiesToSpawn = (round (random SM_MaxZombiesInHordeTown)) max SM_MinZombiesInHordeTown;
						
						_zombieClasses = SM_HordeClassesTown;
						if (_zombieClasses isEqualTo []) then
						{
							_zombieClasses = SM_ZombieClassesTown;
						};
					}
					else
					{
						_minDistance = SM_HordeMinDistance;
						_maxDistance = SM_HordeMaxDistance;
						_zombieMinDistance = SM_HordeSpawnMinDistanceFromPosition;
						_zombieMaxDistance = SM_HordeSpawnMaxDistanceFromPosition;
						_zombiesToSpawn = (round (random SM_MaxZombiesInHorde)) max SM_MinZombiesInHorde;
						
						_zombieClasses = SM_HordeClasses;
						if (_zombieClasses isEqualTo []) then
						{
							_zombieClasses = SM_ZombieClasses;
						};
					};
				};
			};
		}
		else
		{
			if (_player call SM_IsPlayerInTown) then
			{
				_minDistance = SM_HordeMinDistanceTown;
				_maxDistance = SM_HordeMaxDistanceTown;
				_zombieMinDistance = SM_HordeSpawnMinDistanceFromPositionTown;
				_zombieMaxDistance = SM_HordeSpawnMaxDistanceFromPositionTown;
				_zombiesToSpawn = (round (random SM_MaxZombiesInHordeTown)) max SM_MinZombiesInHordeTown;
				
				_zombieClasses = SM_HordeClassesTown;
				if (_zombieClasses isEqualTo []) then
				{
					_zombieClasses = SM_ZombieClassesTown;
				};
			}
			else
			{
				_minDistance = SM_HordeMinDistance;
				_maxDistance = SM_HordeMaxDistance;
				_zombieMinDistance = SM_HordeSpawnMinDistanceFromPosition;
				_zombieMaxDistance = SM_HordeSpawnMaxDistanceFromPosition;
				_zombiesToSpawn = (round (random SM_MaxZombiesInHorde)) max SM_MinZombiesInHorde;
				
				_zombieClasses = SM_HordeClasses;
				if (_zombieClasses isEqualTo []) then
				{
					_zombieClasses = SM_ZombieClasses;
				};
			};
		};

		if (isNil "_minDistance") exitWith
		{
			"could not find detect spawn type" call SM_Util_Log;
		};

		for "_i" from 0 to 20 do
		{
			_zombiePos = [(position _player), _minDistance, _maxDistance] call SM_FindPosition;
			if !(_zombiePos isEqualTo []) exitWith {};
		};

		if (_zombiePos isEqualTo []) exitWith {};

		_group = _player getVariable ["SM_ZombieGroup", grpNull];
		if (isNull _group) then
		{
			_group = createGroup SM_ZombieSide;
			_player setVariable ["SM_ZombieGroup", _group];
			_group setVariable ["SM_IsZombieGroup", true];
		};

		for "_i" from 1 to _zombiesToSpawn do
		{
			if (SM_CurrentZombieCount >= SM_MaxZombies) exitWith {};
			
			for "_i" from 0 to 20 do
			{
				_randomPos = [_zombiePos, _zombieMinDistance, _zombieMaxDistance] call SM_FindPosition;
				if !(_randomPos isEqualTo []) exitWith {};
			};

			if (_randomPos isEqualTo []) exitWith {};

			_zombie = _group createUnit [selectRandom _zombieClasses, _randomPos, [], 0, "NONE"];

			[_zombie] joinSilent _group;
			_zombiesToPass pushBack _zombie;

			SM_CurrentZombieCount = SM_CurrentZombieCount + 1;
			_currentZombieSpawned pushBack (netId _zombie);
			_currentZombies = _currentZombies + 1;
			SM_CurrentZombiesSpawned pushBack (netId _zombie);
			_zombie setVariable ["SM_ZombieOwner", (netId _player), true];

			_zombie remoteExecCall ["SM_SetZombieVariables", -2];

			"Zombie Spawned" call SM_Util_Log;
		};
	};
	if (!(_zombiesToPass isEqualTo []) && !isNull _group) then
	{
		_player setVariable ["SM_CurrentZombies", [_currentZombies, _currentZombieSpawned]];

		[_group,_player,_zombiesToPass] spawn
		{
			_zombiesToPass = [];
			_player = _this select 1;
			_group = _this select 0;
			{
				waitUntil {!isNull _x};
				if (_x in (units (_this select 0))) then
				{
					_zombiesToPass pushBack (netId _x);
				}
				else
				{
					[_x] joinSilent _group;
					_group setGroupOwner (owner _player);
					_zombiesToPass pushBack (netId _x);
				};
			} forEach (_this select 2);

			[_player, "ZombieReceive", [_zombiesToPass]] call SM_Network_SendMessage;
		};

		if (SM_HordeMarkerEnabled) then
		{
			switch (SM_HordeMarkerType) do
			{
				case 1:
				{
					_marker = createMarker [format["ZombieHorde_%1", (random 100)], _zombiePos];
					_marker setMarkerType "SM_Zombz_Marker4";
					_marker setMarkerText SM_HordeMarkerText;
				};
				case 2:
				{
					_marker = createMarker [format["ZombieHorde_%1", (random 100)], _zombiePos];
					_marker setMarkerType "SM_Zombz_Marker3";
					_marker setMarkerText SM_HordeMarkerText;
				};
				case 3:
				{
					_marker = createMarker [format["ZombieHorde_%1", (random 100)], _zombiePos];
					_marker setMarkerType "SM_Zombz_Marker2";
					_marker setMarkerText SM_HordeMarkerText;
				};
				case 4:
				{
					_marker = createMarker [format["ZombieHorde_%1", (random 100)], _zombiePos];
					_marker setMarkerType "SM_Zombz_Marker1";
					_marker setMarkerText SM_HordeMarkerText;
				};
				case 5:
				{
					_marker = createMarker [format["ZombieHorde_%1", (random 100)], _zombiePos];
					_marker setMarkerType "hd_warning";
					_marker setMarkerText SM_HordeMarkerText;
					_marker setMarkerColor "ColorRed";
				};
				case 6:
				{
					_marker = createMarker [format["ZombieHorde_%1", (random 100)], _zombiePos];
					_marker setMarkerType SM_HordeMarkerStyle;
					_marker setMarkerText SM_HordeMarkerText;
					_marker setMarkerColor SM_HordeMarkerColor;		
				};
				default { "Error: SM_HordeMarkerType is not valid" call SM_Util_Log; };
			};
		};

		if (SM_HordeNotificationEnabled) then
		{
			SM_ClientNetworkMessage = ["Notification",SM_HordeNotificationText];
			publicVariable "SM_ClientNetworkMessage";
			SM_ClientNetworkMessage = nil;
		};

		if (!(isNil "_marker") && SM_HordeMarkerCleanupEnabled) then
		{
			[SM_HordeMarkerCleanup, {deleteMarker _this}, _marker, false, "Horde Marker"] call SM_System_AddTask;
		};
	};
};

true
