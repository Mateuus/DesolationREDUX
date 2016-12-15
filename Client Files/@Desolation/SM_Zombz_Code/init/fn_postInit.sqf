/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private["_version"];
_version = getText(configFile >> "CfgPatches" >> "SM_Zombz" >> "version");
diag_log format["SM_Zombz %1: Starting postInit!", _version];

[] call SM_CompileConfig;

SM_System_ThreadID = 420;
SM_System_Tasks = [];
SM_System_TasksDelay = [];
SM_System_TaskTimer = time;
[] call SM_System_AdjustTask;
[] call SM_System_InitializeTasks;

if (isDedicated) then
{
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
	SM_IdleZombies = [];
	execFSM "SM_Zombz_Code\code\fsm\zombieIdleManager.fsm";

	SM_InfectionThreadID = [SM_InfectionDelay,SM_InfectionThread,[],true,"Infection thread, deals the damage"] call SM_System_AddTask;
	
	"SM_ClientNetworkMessage" addPublicVariableEventHandler compileFinal "(_this select 1) call SM_Network_HandleMessage";
};

diag_log format["SM_Zombz %1: Finished postInit!", _version];

true
