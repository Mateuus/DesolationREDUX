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

 
_password = bis_functions_mainscope getVariable ["ServerCommandPassword_DS", ""];
if(DS_var_finishedVehicles && DS_var_finishedLoot && SM_var_finishedZombies) then {
	bis_functions_mainscope setVariable ["ServerCommandPassword_DS",nil,true]; //--- wipe security vulnerability 
	_password serverCommand "#unlock";
	diag_log "SERVER LOCKING > UNLOCKED";
	
	
	_password spawn {
		params["_password"];
		
		uiSleep (3600*4)-(60*5);
		"Server restarting in 5 minutes.\nPlease log out soon" remoteExecCall ["hint",allPlayers];
		uiSleep 60*4;
		"Server restarting in 60 seconds.\nPlease log out now" remoteExecCall ["hint",allPlayers];
		uiSleep 60;
		// prevent new players from connecting
		_password serverCommand "#lock";
		{
			_password serverCommand ("#kick " + (owner _x));
		} forEach allPlayers;
		uiSleep 10; // wait for all disconnects to process
		_password serverCommand "#shutdown";
		
	};
};