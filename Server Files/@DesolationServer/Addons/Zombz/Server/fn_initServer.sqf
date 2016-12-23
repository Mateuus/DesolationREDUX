/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

if !(["Enabled","SM"] call SM_fnc_getCfgValue) exitWith {};

private _version = getText(configFile >> "CfgPatches" >> "DSR_Zombz_code" >> "version");
diag_log format["SM_Zombz %1: Starting Init!", _version];

if !(isMultiplayer) exitWith 
{
	diag_log format["SM_Zombz %1: Finished Init, but was exited due to not being in a multiplayer session!", _version];
};

// wait until the preinit for the mod has completed
waitUntil {!isNil "SM_fnc_spawnZombies"};

SM_IdleZombies = [];
SM_FailedPassedZombies = [];

// Spawn zombies
[] call SM_fnc_spawnZombies;

// This should only happen if there are no zombies left on the map!
if (SM_IdleZombies isEqualTo []) exitWith
{
	diag_log format["SM_Zombz %1: Finished Init, but was exited due to no zombies spawned!", _version];
};

// Pass all zombies to all clients.
bis_functions_mainscope setVariable ["SM_allZombies", SM_IdleZombies, true];

// Manager FSM for Zombz.
[] execFSM "zombz\FSM\manager.fsm";

diag_log format["SM_Zombz %1: Finished Init!", _version];