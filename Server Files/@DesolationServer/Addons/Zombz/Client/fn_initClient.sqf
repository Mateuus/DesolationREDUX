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

private _version = getText(configFile >> "CfgPatches" >> "DSR_SM_Zombz" >> "version");
diag_log format["DSR_SM_Zombz %1: Starting Init!", _version];

if !(isMultiplayer) exitWith 
{
	diag_log format["DSR_SM_Zombz %1: Finished Init, but was exited due to not being in a multiplayer session!", _version];
};

// wait until the preinit for the mod has completed
waitUntil {!isNil "SM_fnc_zombieInit"};

SM_idleZombies = [];

// Exec the manager FSM.
[] execFSM "DSR_Zombz_Code\FSM\Manager.fsm";

diag_log format["DSR_SM_Zombz %1: Finished Init!", _version];

true