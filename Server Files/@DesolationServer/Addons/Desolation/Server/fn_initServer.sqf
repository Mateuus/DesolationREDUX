/*
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

// start vehicle & object spawns
[] spawn DS_fnc_spawnVehicles;

// start helicrash spawns
// [] spawn DS_fnc_spawnCrashes;

// start item spawns
[] spawn DS_fnc_lootManager;

// start airdrops
[] spawn DS_fnc_initAirdrops;

//--- start subsystems
[] spawn DS_fnc_simManager;



//--- DEBUG (monitor thread counts)
[] spawn {
	while{true} do {
		_threads = Diag_activeScripts;
		NUM_THREADS = (_threads select 0) + (_threads select 1) - 1;
		
		if(NUM_THREADS > 13 && diag_fps < 40) then {
			diag_log ("ERROR: CANT KEEP UP! To many threads running on the server - " + str(NUM_THREADS) + " - FPS: " + str(diag_fps));
		};
		uiSleep 0.5;
	};
};