/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */
 
 if(isMultiplayer) exitWith {diag_log "Multiplayer: Waiting for server init";};

private["_version"];
_version = getText(configFile >> "CfgPatches" >> "SM_Zombz" >> "version");
diag_log format["SM_Zombz %1: Starting postInit!", _version];

if !(isMultiplayer) exitWith {};

SM_System_ThreadID = 420;
SM_System_Tasks = [];
SM_System_TasksDelay = [];
SM_System_TaskTimer = time;
[] call SM_System_AdjustTask;
[] call SM_System_InitializeTasks;

SM_Debug =  ["SM_Debug", false] call SM_ConfigFetch;
SM_ExileEnabled = (isClass (configFile >> "CfgPatches" >> "exile_client"));
SM_EpochEnabled = (isClass (configFile >> "CfgPatches" >> "A3_epoch_code"));

if (isDedicated) then
{
	SM_ZombieCleanupDeath = ["SM_ZombieCleanupDeath", 150] call SM_ConfigFetch;
	SM_ZombieWaveCount = ["SM_ZombieWaveCount", 5] call SM_ConfigFetch;
	SM_ZombieItemCount = ["SM_ZombieItemCount", 5] call SM_ConfigFetch;
	SM_ZombieSpawnDelay = ["SM_ZombieSpawnDelay", 60] call SM_ConfigFetch;
	SM_ZombieMaxDistance = ["SM_ZombieMaxDistance", 150] call SM_ConfigFetch;
	SM_ZombieMinDistance = ["SM_ZombieMinDistance", 25] call SM_ConfigFetch;
	SM_ZombieCleanup = ["SM_ZombieCleanup", 60] call SM_ConfigFetch;
	SM_ZombieCleanupDistance = ["SM_ZombieCleanupDistance", 300] call SM_ConfigFetch;
	SM_MaxZombies = ["SM_MaxZombies", 200] call SM_ConfigFetch;
	SM_ZombiesPerPlayer = ["SM_ZombiesPerPlayer", 10] call SM_ConfigFetch;
	SM_ZombieHealth = ["SM_ZombieHealth", 0.7] call SM_ConfigFetch;
	SM_GiveZombiePoptabs = ["SM_GiveZombiePoptabs", true] call SM_ConfigFetch;
	SM_MaxPoptabs = ["SM_MaxPoptabs", 50] call SM_ConfigFetch;
	SM_PoptabChanceHigh = ["SM_PoptabChanceHigh", 100] call SM_ConfigFetch;
	SM_PopTabsChanceLow = ["SM_PopTabsChanceLow", 65] call SM_ConfigFetch;
	SM_GivePlayerRespect = ["SM_GivePlayerRespect", true] call SM_ConfigFetch;
	SM_MaxRespect = ["SM_MaxRespect", 50] call SM_ConfigFetch;
	SM_MaxChanceOfLoot = ["SM_MaxChanceOfLoot", 100] call SM_ConfigFetch;
	SM_MinChanceOfLoot = ["SM_MinChanceOfLoot", 85] call SM_ConfigFetch;
	SM_MaxItemDrop = ["SM_MaxItemDrop", 3] call SM_ConfigFetch;
	SM_ZombieClasses = ["SM_ZombieClasses", []] call SM_ConfigFetch;
	SM_Zombie_GlowingFace = ["SM_Zombie_GlowingFace", true] call SM_ConfigFetch;
	SM_Zombie_SpawnInGround = ["SM_Zombie_SpawnInGround", true] call SM_ConfigFetch;
	SM_ExplodingHeadEnabled = ["SM_ExplodingHeadEnabled", false] call SM_ConfigFetch;
	SM_MaxZombiesInHorde = ["SM_MaxZombiesInHorde", 69] call SM_ConfigFetch;
	SM_SpawnHordeChance = ["SM_SpawnHordeChance", 2.5] call SM_ConfigFetch;
	SM_HordesEnabled = ["SM_HordesEnabled", true] call SM_ConfigFetch;
	SM_HordeSpawnDelay = ["SM_HordeSpawnDelay", 120] call SM_ConfigFetch;
	SM_HordeMarkerCleanup = ["SM_HordeMarkerCleanup", 120] call SM_ConfigFetch;
	SM_MinZombiesInHorde = ["SM_MinZombiesInHorde", 10] call SM_ConfigFetch;
	SM_ZombieSpawnMaxDistanceFromPosition = ["SM_ZombieSpawnMaxDistanceFromPosition", 15] call SM_ConfigFetch;
	SM_HordeSpawnMaxDistanceFromPosition = ["SM_HordeSpawnMaxDistanceFromPosition", 35] call SM_ConfigFetch;
	SM_ZombieSpawnMaxDistanceFromPositionTown = ["SM_ZombieSpawnMaxDistanceFromPositionTown", 10] call SM_ConfigFetch;
	SM_ZombieSpawnMinDistanceFromPositionTown = ["SM_ZombieSpawnMinDistanceFromPositionTown", 5] call SM_ConfigFetch;
	SM_ZombieMinDistanceTown = ["SM_ZombieMinDistanceTown", 25] call SM_ConfigFetch;
	SM_ZombieMaxDistanceTown = ["SM_ZombieMaxDistanceTown", 100] call SM_ConfigFetch;
	SM_ZombiesPerWave = ["SM_ZombiesPerWave", 5] call SM_ConfigFetch;
	SM_HordeMarkerEnabled = ["SM_HordeMarkerEnabled", true] call SM_ConfigFetch;
	SM_HordeNotificationEnabled = ["SM_HordeNotificationEnabled", true] call SM_ConfigFetch;
	SM_DespawnZombieOrKill = ["SM_DespawnZombieOrKill", true] call SM_ConfigFetch;
	SM_HordeNotificationText = ["SM_HordeNotificationText", ""] call SM_ConfigFetch;
	SM_HordeMarkerType = ["SM_HordeMarkerType", 1] call SM_ConfigFetch;
	SM_HordeMarkerCleanupEnabled = ["SM_HordeMarkerCleanupEnabled", true] call SM_ConfigFetch;
	SM_HordeMarkerText = ["SM_HordeMarkerText", ""] call SM_ConfigFetch;
	SM_HordeMarkerStyle = ["SM_HordeMarkerStyle", ""] call SM_ConfigFetch;
	SM_HordeMarkerColor = ["SM_HordeMarkerColor", ""] call SM_ConfigFetch;
	SM_ZombiesPerWaveTown = ["SM_ZombiesPerWaveTown", 7] call SM_ConfigFetch;
	SM_ZombiesPerPlayerInTown = ["SM_ZombiesPerPlayerInTown", 15] call SM_ConfigFetch;
	SM_SearchForTownRadius = ["SM_SearchForTownRadius", 1000] call SM_ConfigFetch;
	SM_TownSearchTypes = ["SM_TownSearchTypes", []] call SM_ConfigFetch;
	SM_LootArray = call 
	{
		if (SM_ExileEnabled) exitWith { ["SM_LootItemsExile", []] call SM_ConfigFetch };
		if (SM_EpochEnabled) exitWith { ["SM_LootItemsEpoch", []] call SM_ConfigFetch };
		["SM_LootItems", []] call SM_ConfigFetch
	};
	SM_MaxCrypto = ["SM_MaxCrypto", 50] call SM_ConfigFetch;
	SM_GiveCrpyto = ["SM_GiveCrpyto", true] call SM_ConfigFetch;
	SM_UserSafezoneCheckMarkerObjects = ["SM_UserSafezoneCheckMarkerObjects", ""] call SM_ConfigFetch;
	SM_UserSafezoneCheck = ["SM_UserSafezoneCheck", false] call SM_ConfigFetch;
	SM_UserSafezoneCheckType = ["SM_UserSafezoneCheckType", 1] call SM_ConfigFetch;
	SM_UserSafezoneCheckDistance = ["SM_UserSafezoneCheckDistance", 50] call SM_ConfigFetch;
	SM_UserBaseCheck = ["SM_UserBaseCheck", false] call SM_ConfigFetch;
	SM_UserBaseCheckMarkerObjects = ["SM_UserBaseCheckMarkerObjects", ""] call SM_ConfigFetch;
	SM_UserBaseCheckType = ["SM_UserBaseCheckType", 1] call SM_ConfigFetch;
	SM_UserBaseCheckDistance = ["SM_UserBaseCheckDistance", 50] call SM_ConfigFetch;
	SM_NotificationEnabled = ["SM_NotificationEnabled", true] call SM_ConfigFetch;
	SM_ZombieGutsLength = ["SM_ZombieGutsLength", 300] call SM_ConfigFetch;
	SM_ShuffleArrayDelay = ["SM_ShuffleArrayDelay", 300] call SM_ConfigFetch;
	SM_FacesArray = ["SM_FacesArray", []] call SM_ConfigFetch;
	SM_FaceFemaleArray = ["SM_FaceFemaleArray", []] call SM_ConfigFetch;
	SM_ZombieZones = ["SM_ZombieZones", []] call SM_ConfigFetch;
	SM_ZombieZonesEnabled = ["SM_ZombieZonesEnabled", false] call SM_ConfigFetch;
	SM_ZombiesCanSpawnRandomly = ["SM_ZombiesCanSpawnRandomly", false] call SM_ConfigFetch;
	SM_RespawnDelayForPlayerEnabled = ["SM_RespawnDelayForPlayerEnabled", true] call SM_ConfigFetch;
	SM_RespawnDelayForPlayer = ["SM_RespawnDelayForPlayer", 300] call SM_ConfigFetch;
	SM_ZombieSpawnMinDistanceFromPosition = ["SM_ZombieSpawnMinDistanceFromPosition", 5] call SM_ConfigFetch;
	SM_HordeSpawnMinDistanceFromPosition = ["SM_HordeSpawnMinDistanceFromPosition", 5] call SM_ConfigFetch;
	SM_RespawnDelayForPlayerTown = ["SM_RespawnDelayForPlayerTown", 420] call SM_ConfigFetch;
	SM_ZombieClassesTown = ["SM_ZombieClassesTown", []] call SM_ConfigFetch;
	SM_TownSearchEnabled = ["SM_TownSearchEnabled", false] call SM_ConfigFetch;
	SM_DisableZombieSpawnsUntilInNewZoneEnabled = ["SM_DisableZombieSpawnsUntilInNewZoneEnabled", false] call SM_ConfigFetch;
	SM_HordeZonesEnabled = ["SM_HordeZonesEnabled", false] call SM_ConfigFetch;
	SM_HordeUseZombieZones = ["SM_HordeUseZombieZones", false] call SM_ConfigFetch;
	SM_HordeZones = ["SM_HordeZones", []] call SM_ConfigFetch;
	SM_HordeCanSpawnRandomly = ["SM_HordeCanSpawnRandomly", false] call SM_ConfigFetch;
	SM_HordeMinDistanceTown = ["SM_HordeMinDistanceTown", 5] call SM_ConfigFetch;
	SM_HordeMaxDistanceTown = ["SM_HordeMaxDistanceTown", 100] call SM_ConfigFetch;
	SM_HordeSpawnMinDistanceFromPositionTown = ["SM_HordeSpawnMinDistanceFromPositionTown", 5] call SM_ConfigFetch;
	SM_HordeSpawnMaxDistanceFromPositionTown = ["SM_HordeSpawnMaxDistanceFromPositionTown", 100] call SM_ConfigFetch;
	SM_MaxZombiesInHordeTown = ["SM_MaxZombiesInHordeTown", 50] call SM_ConfigFetch;
	SM_MinZombiesInHordeTown = ["SM_MinZombiesInHordeTown", 5] call SM_ConfigFetch;
	SM_HordeClassesTown = ["SM_HordeClassesTown", []] call SM_ConfigFetch;
	SM_HordeClasses = ["SM_HordeClasses", []] call SM_ConfigFetch;
	SM_HordeMinDistance = ["SM_HordeMinDistance", 10] call SM_ConfigFetch;
	SM_HordeMaxDistance = ["SM_HordeMaxDistance", 150] call SM_ConfigFetch;
	SM_ZombieSide = call 
	{
		_ret = "";
		switch (toLower (["SM_ZombieSide", "civilian"] call SM_ConfigFetch)) do 
		{
			case "west": { _ret = west }; 
			case "east": { _ret = east }; 
			case "independent": { _ret = independent };
			case "civilian": { _ret = civilian };
			default { _ret = ""};
		};
		if (_ret isEqualTo "") then
		{
			_ret = east;
		};
		_ret
	};

	SM_CurrentZombiesSpawned = [];
	DeadZombieBodys = [];
	SM_CurrentZombieCount = 0;

	SM_ZombieClasses = SM_ZombieClasses call SM_ArrayShuffle;
	SM_LootArray = SM_LootArray call SM_ArrayShuffle; 

	ZombieCleanupThreadID = [SM_ZombieCleanup, SM_Cleanup, [], true, "Zombie Cleanup"] call SM_System_AddTask;
	ZombieLocalityThreadID = [SM_ZombieCleanup, SM_ZombieLocality, [], true, "Zombie Locality"] call SM_System_AddTask;
	ZombieSpawnThreadID = [SM_ZombieSpawnDelay, SM_SpawnZombies, [], true, "Zombie Spawn"] call SM_System_AddTask;
	ZombieShuffleArrayThreadID = [SM_ShuffleArrayDelay, { SM_ZombieClasses = SM_ZombieClasses call SM_ArrayShuffle; SM_LootArray = SM_LootArray call SM_ArrayShuffle; }, [], true, "Randomize things"] call SM_System_AddTask;

	if (SM_HordesEnabled) then
	{
		ZombieHordeThreadID = [SM_HordeSpawnDelay, SM_SpawnHorde, [], true, "Zombie Horde Spawn"] call SM_System_AddTask;
	};

	if (SM_ZombieZonesEnabled) then
	{
		{
			if ((_x select 9) isEqualTo 1) then
			{
				_markerName = format["SM_ZombieZone_%1",random 10000];
				_marker = createMarker [_markerName,(_x select 0)];
				_marker setMarkerBrush (_x select 14);
				_marker setMarkerAlpha (_x select 13);
				_marker setMarkerColor (_x select 12);
				_marker setMarkerShape (_x select 10);
				_marker setMarkerSize [(_x select 1),(_x select 1)];
			};

			if ((_x select 8) isEqualTo 1) then
			{
				_markerName = format["SM_ZombieZone_%1",random 10000];
				_marker = createMarker [_markerName,(_x select 0)];
				_marker setMarkerText (_x select 11);
				_marker setMarkerType (_x select 7);
				_marker setMarkerAlpha (_x select 15);
			};
		} forEach SM_ZombieZones;
	};

	if (SM_HordeZonesEnabled) then
	{
		{
			if ((_x select 10) isEqualTo 1) then
			{
				_markerName = format["SM_ZombieZone_%1",random 10000];
				_marker = createMarker [_markerName,(_x select 0)];
				_marker setMarkerBrush (_x select 15);
				_marker setMarkerAlpha (_x select 14);
				_marker setMarkerColor (_x select 13);
				_marker setMarkerShape (_x select 11);
				_marker setMarkerSize [(_x select 1),(_x select 1)];
			};

			if ((_x select 9) isEqualTo 1) then
			{
				_markerName = format["SM_ZombieZone_%1",random 10000];
				_marker = createMarker [_markerName,(_x select 0)];
				_marker setMarkerText (_x select 12);
				_marker setMarkerType (_x select 8);
				_marker setMarkerAlpha (_x select 16);
			};
		} forEach SM_HordeZones;
	};

	"SM_ServerNetworkMessage" addPublicVariableEventHandler compileFinal "(_this select 1) call SM_Network_HandleMessage";
};

if (hasInterface) then
{
	SM_ZombieAgroRange = 200;
	SM_SoundDistance = ["SM_SoundDistance", 30] call SM_ConfigFetch;
	SM_ZombieDamagePlayer = ["SM_ZombieDamagePlayer", 0.15] call SM_ConfigFetch;
	SM_ZombieDamagePlayerStrength = ["SM_ZombieDamagePlayerStrength", 1] call SM_ConfigFetch;
	SM_ZombieDamageCarStrength = ["SM_ZombieDamageCarStrenth", 1.5] call SM_ConfigFetch;
	SM_ZombieDamageCar = ["SM_ZombieDamageCar",0.02] call SM_ConfigFetch;
	SM_PoptabChanceHigh = ["SM_PoptabChanceHigh", 100] call SM_ConfigFetch;
	SM_MaxRespect = ["SM_MaxRespect", 50] call SM_ConfigFetch;
	SM_SoundVolume = ["SM_SoundVolume", 1] call SM_ConfigFetch;
	SM_AttackSpeed = ["SM_AttackSpeed", 0.8] call SM_ConfigFetch;
	SM_BleedingEnabled = ["SM_BleedingEnabled", true] call SM_ConfigFetch;
	SM_BleedTime = ["SM_BleedTime", 20] call SM_ConfigFetch;
	SM_BleedChanceHigh = ["SM_BleedChanceHigh", 100] call SM_ConfigFetch;
	SM_BleedChanceLow = ["SM_BleedChanceLow", 90] call SM_ConfigFetch;
	SM_ZombieTargetPosMemory = ["SM_ZombieTargetPosMemory", 7.5] call SM_ConfigFetch;
	SM_ZombieSoundDelayAggressive = ["SM_ZombieSoundDelayAggressive", 3] call SM_ConfigFetch;
	SM_ZombieSoundDelayMoan = ["SM_ZombieSoundDelayMoan", 15] call SM_ConfigFetch;
	SM_ZombieFindTargetDelay = ["SM_ZombieFindTargetDelay", 1] call SM_ConfigFetch;
	SM_ZombieEat = ["SM_ZombieEat", 30] call SM_ConfigFetch;
	SM_InfectionIncrease = ["SM_InfectionIncrease", 0.25] call SM_ConfigFetch;
	SM_Infection = ["SM_Infection", true] call SM_ConfigFetch;
	SM_InfectionChanceHigh = ["SM_InfectionChanceHigh", 100] call SM_ConfigFetch;
	SM_InfectionChanceLow = ["SM_InfectionChanceLow", 85] call SM_ConfigFetch;
	SM_InfectionDamage = ["SM_InfectionDamage", 0.01] call SM_ConfigFetch;
	SM_InfectionDelay = ["SM_InfectionDelay", 2] call SM_ConfigFetch;
	SM_ZombieEatSoundDelay = ["SM_ZombieEatSoundDelay", 7] call SM_ConfigFetch;
	SM_ZombieSpeedMultiplyer = ["SM_ZombieSpeedMultiplyer", 2.5] call SM_ConfigFetch;
	SM_ZombieSpeedDistance = ["SM_ZombieSpeedDistance", 35] call SM_ConfigFetch;
	SM_ZombieSpeedIncreaseEnabled = ["SM_ZombieSpeedIncreaseEnabled", true] call SM_ConfigFetch;
	SM_ZombiesFastClose = ["SM_ZombiesFastClose", false] call SM_ConfigFetch;
	SM_MultiplierDistanceFromTarget = ["SM_MultiplierDistanceFromTarget", 1.5] call SM_ConfigFetch;
	SM_Zombie_SpawnInGround = ["SM_Zombie_SpawnInGround", true] call SM_ConfigFetch;
	SM_AttackArray = ["SM_AttackArray", []] call SM_ConfigFetch;
	SM_AggressiveArray = ["SM_AggressiveArray", []] call SM_ConfigFetch;
	SM_EatingArray = ["SM_EatingArray", []] call SM_ConfigFetch;
	SM_MoanArray = ["SM_MoanArray", []] call SM_ConfigFetch;
	SM_ScreamArray = ["SM_ScreamArray", []] call SM_ConfigFetch;
	SM_VehicleHitArray = ["SM_VehicleHitArray", []] call SM_ConfigFetch;
	SM_ZombieBiteArray = ["SM_ZombieBiteArray", []] call SM_ConfigFetch;
	SM_ZombieInBuildingSpeedDevidor = ["SM_ZombieInBuildingSpeedDevidor", 3] call SM_ConfigFetch;
	SM_FiredNearEVHEnabled = ["SM_FiredNearEVHEnabled", true] call SM_ConfigFetch;
	SM_UserSafezoneCheckMarkerObjects = ["SM_UserSafezoneCheckMarkerObjects", ""] call SM_ConfigFetch;
	SM_UserSafezoneCheck = ["SM_UserSafezoneCheck", false] call SM_ConfigFetch;
	SM_UserSafezoneCheckType = ["SM_UserSafezoneCheckType", 1] call SM_ConfigFetch;
	SM_UserSafezoneCheckDistance = ["SM_UserSafezoneCheckDistance", 50] call SM_ConfigFetch;
	SM_UserBaseCheck = ["SM_UserBaseCheck", false] call SM_ConfigFetch;
	SM_UserBaseCheckMarkerObjects = ["SM_UserBaseCheckMarkerObjects", ""] call SM_ConfigFetch;
	SM_UserBaseCheckType = ["SM_UserBaseCheckType", 1] call SM_ConfigFetch;
	SM_UserBaseCheckDistance = ["SM_UserBaseCheckDistance", 50] call SM_ConfigFetch;
	SM_NotificatonType = ["SM_NotificatonType", 1] call SM_ConfigFetch;
	SM_ZombieGutsLength = ["SM_ZombieGutsLength", 300] call SM_ConfigFetch;
	SM_ScreenEffects = ["SM_ScreenEffects", []] call SM_ConfigFetch;
	SM_ExplodingHeadEnabled = ["SM_ExplodingHeadEnabled", true] call SM_ConfigFetch;
	SM_CustomScreenEffects = ["SM_CustomScreenEffects", false] call SM_ConfigFetch;
	SM_SetVelocityOnHit = ["SM_SetVelocityOnHit", false] call SM_ConfigFetch;
	SM_ZombieIdleDelay = ["SM_ZombieIdleDelay", 3] call SM_ConfigFetch;
	SM_ImmunityLength = ["SM_ImmunityLength", 420] call SM_ConfigFetch;

	SM_IdleZombies = [];
	execFSM "SM_Zombz_Code\code\fsm\zombieIdleManager.fsm";

	SM_InfectionThreadID = [SM_InfectionDelay,SM_InfectionThread,[],true,"Infection thread, deals the damage"] call SM_System_AddTask;
	
	"SM_ClientNetworkMessage" addPublicVariableEventHandler compileFinal "(_this select 1) call SM_Network_HandleMessage";
};

diag_log format["SM_Zombz %1: Finished postInit!", _version];

true
