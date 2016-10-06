/*
	fn_initClient

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_enabled = call compile (["Enabled","DS"] call BASE_fnc_getCfgValue);
if(!_enabled) exitWith {diag_log "DESOLATION IS NOT ENABLED, THE PLUGIN WILL NOT RUN";};

0 cutRsc ["background","PLAIN",0];
0 fadeSound 0;
0 fadeMusic 0;

call ds_fnc_initInvHandler;
call ds_fnc_initHealthSys;

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
