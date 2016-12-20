/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_group","_zone","_inZone","_zombiesToSpawn","_minDistance","_maxDistance","_zombieMinDistance","_zombieMaxDistance","_maxZombies","_zombieClasses","_group","_player","_currentZombies","_currentZombieSpawned","_zombiesToPass","_isValid","_data","_town","_zombiePos","_minSpawn","_randomPos","_random","_zombie","_passed","_inZone","_zone","_spawnDelay"];
_group = grpNull;
_zone = -2;

"player Check" call SM_Util_Log;

if !(count (allPlayers - entities "HeadlessClient_F") > 0) exitWith { true }; 

"Starting Zombie Check" call SM_Util_Log;
_alreadySpawnedPlayers = [];
try
{
	for "_i" from 1 to SM_ZombieWaveCount do
	{
		"Fetching player" call SM_Util_Log;
		_player = vehicle (selectRandom (allPlayers - entities "HeadlessClient_F"));

		if (_player in _alreadySpawnedPlayers) then
		{
			format["%1 (%2) has already spawned zombies this wave!",name _player,getPlayerUID _player] call SM_Util_Log;
		}
		else
		{

			format["Spawning zombies for %1 (%2)", (name _player), (getPlayerUID _player)] call SM_Util_Log;

			_currentZombies = 0;
			_currentZombieSpawned = [];
			_zombiesToPass = [];

			_isValid = _player call SM_SpawnCheck;
			if (_isValid) then
			{
				_data = _player call SM_PlayerZombieCount;
				_currentZombies = _data select 0;
				_currentZombieSpawned = _data select 1;

				format["Current zombies for player %1 (%2): %3", (name _player), (getPlayerUID _player), _currentZombies] call SM_Util_Log;
				
				[] call SM_ZombieCount;
				"Spawning Zombies" call SM_Util_Log;
				try 
				{
					if (SM_ZombieZonesEnabled) then
					{
						_inZone = false;
						{
							if ((_player distance2D (_x select 0)) <= (_x select 1)) exitWith
							{
								_inZone = true;
								_zone = _forEachIndex;
							};
						} forEach SM_ZombieZones;

						if(_inZone) then
						{
							_zoneData = SM_ZombieZones select _zone;
							_zombiesToSpawn = _zoneData select 2;
							_minDistance = _zoneData select 4;
							_maxDistance = _zoneData select 3;
							_zombieMinDistance = _zoneData select 5;
							_zombieMaxDistance = _zoneData select 6;
							_maxZombies = _zoneData select 16;
							_spawnDelay = _zoneData select 17;
							_zombieClasses = _zoneData select 18;
							if ((_zombieClasses) isEqualTo []) then
							{
								_zombieClasses = SM_ZombieClasses;
							};
						}
						else
						{
							if (SM_ZombiesCanSpawnRandomly) then
							{
								if (_player call SM_IsPlayerInTown) then
								{
									_minDistance = SM_ZombieMinDistanceTown;
									_maxDistance = SM_ZombieMaxDistanceTown;
									_zombieMinDistance = SM_ZombieSpawnMaxDistanceFromPositionTown;
									_zombieMaxDistance = SM_ZombieSpawnMinDistanceFromPositionTown;
									_zombiesToSpawn = SM_ZombiesPerWaveTown;
									_maxZombies = SM_ZombiesPerPlayerInTown;
									_zombieClasses = SM_ZombieClassesTown;
									_spawnDelay = SM_RespawnDelayForPlayerTown;

									if (SM_ZombieClassesTown isEqualTo []) then
									{
										_zombieClasses = SM_ZombieClasses;
									};
								}
								else
								{
									_minDistance = SM_ZombieMinDistance;
									_maxDistance = SM_ZombieMaxDistance;
									_zombieMinDistance = SM_ZombieSpawnMinDistanceFromPosition;
									_zombieMaxDistance = SM_ZombieSpawnMaxDistanceFromPosition;
									_zombiesToSpawn = SM_ZombiesPerWave;
									_maxZombies = SM_ZombiesPerPlayer;
									_zombieClasses = SM_ZombieClasses;
									_spawnDelay = SM_RespawnDelayForPlayer;
								};
							};
						};
					}
					else
					{
						if (_player call SM_IsPlayerInTown) then
						{
							_minDistance = SM_ZombieMinDistanceTown;
							_maxDistance = SM_ZombieMaxDistanceTown;
							_zombieMinDistance = SM_ZombieSpawnMaxDistanceFromPositionTown;
							_zombieMaxDistance = SM_ZombieSpawnMinDistanceFromPositionTown;
							_zombiesToSpawn = SM_ZombiesPerWaveTown;
							_maxZombies = SM_ZombiesPerPlayerInTown;
							_zombieClasses = SM_ZombieClassesTown;
							_spawnDelay = SM_RespawnDelayForPlayerTown;

							if (SM_ZombieClassesTown isEqualTo []) then
							{
								_zombieClasses = SM_ZombieClasses;
							};
						}
						else
						{
							_minDistance = SM_ZombieMinDistance;
							_maxDistance = SM_ZombieMaxDistance;
							_zombieMinDistance = SM_ZombieSpawnMinDistanceFromPosition;
							_zombieMaxDistance = SM_ZombieSpawnMaxDistanceFromPosition;
							_zombiesToSpawn = SM_ZombiesPerWave;
							_maxZombies = SM_ZombiesPerPlayer;
							_zombieClasses = SM_ZombieClasses;
							_spawnDelay = SM_RespawnDelayForPlayer;
						};
					};

					if (isNil "_minDistance") throw "No valid location to spawn zombies";

					if (SM_RespawnDelayForPlayerEnabled && ((diag_tickTime - (_player getVariable ["SM_LastSpawnedZombies",diag_tickTime])) >= _spawnDelay)) exitWith
					{
						"Player cannot spawn zombies yet!" call SM_Util_Log;
					};

					if (SM_DisableZombieSpawnsUntilInNewZoneEnabled && ((_player getVariable ["SM_LastZone",-1]) isEqualTo _zone) && _currentZombies >= _maxZombies) exitWith
					{
						"Player cannot spawn zombies due to being in the same zone!" call SM_Util_Log;
					};

					_zombiePos = [(position _player), _minDistance, _maxDistance] call SM_FindPosition;
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
						if !(((_currentZombies >= _maxZombies) && (SM_CurrentZombieCount >= SM_MaxZombies))) then
						{
							if (_currentZombies >= _maxZombies) throw format["Max zombie for player %1 (%2) reached!", (name _player), (getPlayerUID _player)];

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
							_zombie setVariable ["SM_ZombieOwner", netid _player];

							_zombie call SM_SetZombieVariables; 

							"Zombie Spawned" call SM_Util_Log;
						}
						else
						{
							if (_currentZombies >= _zombiesToSpawn) throw format["Max zombie for player %1 (%2) reached!", (name _player), (getPlayerUID _player)];
							if (SM_CurrentZombieCount >= SM_MaxZombies) throw "Max zombie count reached!";
						};
					};
				}
				catch
				{
					_exception call SM_Util_Log;
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

					if (SM_RespawnDelayForPlayerEnabled) then
					{
						_player setVariable ["SM_LastSpawnedZombies", diag_tickTime];
					};

					_alreadySpawnedPlayers pushBack _player;

					if ((SM_DisableZombieSpawnsUntilInNewZoneEnabled) && !(isNil "_zone")) then
					{
						if !(_zone isEqualTo -2) then
						{
							_player setVariable ["SM_LastZone",_zone];
						};
					};
				};
			};
		};
	};
}
catch
{
	_exception call SM_Util_Log;
};

true
