/*
	fn_initServer

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/

_enabled = call compile (["Enabled","DS"] call BASE_fnc_getCfgValue);
if(!_enabled) exitWith {diag_log "DESOLATION IS NOT ENABLED, THE PLUGIN WILL NOT RUN";};

_debug = call compile (["DebugMode","DS"] call BASE_fnc_getCfgValue);

if !(_debug) then {
	{
		_x setMarkerAlpha 0;
	} forEach allMapMarkers;
};

addMissionEventHandler ["PlayerDisconnected", DS_fnc_playerDisconnected];
addMissionEventHandler ["HandleDisconnect", DS_fnc_handleDisconnect];



// start Vehicle Spawns
[] spawn {
	_vehCount = 0; //--- get this from the database spawning system
	diag_log ("Spawned " + str(_vehCount) + " vehicles from the database");
	_randomSpawnCount = (call compile (["NumVehicles","DS"] call BASE_fnc_getCfgValue)) - _vehCount;
	[_randomSpawnCount] call DS_fnc_spawnVehicles; //--- spawn 1000 vehicles (TODO: take into account database vehicles & the cfg entry for vehicle spawn count)
};

// start Item Spawns
[] spawn DS_fnc_lootManager;

//--- start subsystems
[] spawn DS_fnc_simManager;
