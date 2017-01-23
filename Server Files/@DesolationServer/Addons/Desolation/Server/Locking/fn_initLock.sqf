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

DS_var_finishedVehicles = false;
DS_var_finishedLoot = false;
SM_var_finishedZombies = (isNil "SM_fnc_initServer"); //if SM_Zombz is removed, then ignore its bootup timer
_password = bis_functions_mainscope getVariable ["ServerCommandPassword_DS", ""];
diag_log ("SERVER LOCKING > PASSWORD: " + _password);
_password serverCommand "#lock";
diag_log "SERVER LOCKING > LOCKED";