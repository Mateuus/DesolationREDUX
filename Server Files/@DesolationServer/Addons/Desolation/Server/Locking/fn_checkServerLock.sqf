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

 
_password = bis_functions_mainscope getVariable ["DS_ServerCommandPassword", ""];
if(DS_var_finishedVehicles && DS_var_finishedLoot && SM_var_finishedZombies) then {
	bis_functions_mainscope setVariable ["DS_ServerCommandPassword",nil,true]; //--- wipe security vulnerability 
	_password serverCommand "#unlock";
};