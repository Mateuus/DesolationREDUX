/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

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