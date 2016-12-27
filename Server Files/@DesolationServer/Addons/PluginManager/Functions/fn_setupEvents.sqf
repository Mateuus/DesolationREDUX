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

private["_code"];
params["_fnclist"];

diag_log "<PluginManager>: Initializing server events";

{
	if((toLower(_x) find "handledisconnect") != -1) then {
		_code = missionNamespace getVariable [_x,{}];
		
		
	};
	if((toLower(_x) find "oneachframe") != -1) then {
		_code = missionNamespace getVariable [_x,{}];
		
		
	};
	
} forEach _fnclist;