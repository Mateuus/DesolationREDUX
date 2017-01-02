/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

if !(["Enabled","SM"] call SM_fnc_getCfgValue) exitWith {};

private _version = getText(configFile >> "CfgPatches" >> "DSR_Zombz_code" >> "version");
diag_log format["SM_Zombz %1: Starting Init!", _version];

// wait until the preinit for the mod has completed
waitUntil {!isNil "SM_fnc_zombieInit"};

SM_idleZombies = [];
SM_InfectionDOT = 0;
SM_IsImmune = false;
SM_isImmuneStart = diag_tickTime;

[] call SM_fnc_checkPlayers;
[] call SM_fnc_zombieInit;

diag_log format["SM_Zombz %1: Finished Init!", _version];

true