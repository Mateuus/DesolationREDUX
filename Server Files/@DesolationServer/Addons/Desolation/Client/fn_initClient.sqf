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

_enabled = call compile (["Enabled","DS"] call BASE_fnc_getCfgValue);
if(!_enabled) exitWith {diag_log "DESOLATION IS NOT ENABLED, THE PLUGIN WILL NOT RUN";};

0 cutRsc ["background","PLAIN",0];
0 fadeSound 0;
0 fadeMusic 0;

call ds_fnc_initInvHandler;
[] spawn DS_fnc_initBuilding;

//asks the server to spawn us

// get client custom loadout data
_clientLoadoutData = uiNamespace getVariable ["DS_LOADOUTDATA",[]];

if(_clientLoadoutData isEqualTo []) then {	
	// no loadout data exists in UI (joined from a3launcher?)
	_clientLoadoutDataProfile = [];
	_clientLoadoutDataProfile pushBack (profileNamespace getVariable ["DS_Default_Uniform","U_C_Poor_2"]);
	_clientLoadoutDataProfile pushBack (profileNamespace getVariable ["DS_Default_Headgear","H_StrawHat"]);
	_clientLoadoutDataProfile pushBack (profileNamespace getVariable ["DS_Default_Goggles","G_Aviator"]);
	
	// update UI with profile loadout data
	uiNamespace setVariable ["DS_LOADOUTDATA",_clientLoadoutDataProfile];
};
// request spawn
[player,uiNamespace getVariable "DS_LOADOUTDATA"] remoteExec ["DS_fnc_requestSpawn", 2];
