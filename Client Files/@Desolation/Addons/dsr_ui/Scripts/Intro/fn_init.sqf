scriptName "fn_init";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_init.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_init.sqf"

diag_log "Starting main menu scene";

cam = "camera" camCreate (getPos player);
0 fadeSound 0;

//if (true) exitWith {};

if !(uiNamespace getVariable ["dsr_mainMenu_cinematic_ran", false]) then {
    playMusic "track2_redefined";
    5000 cutRsc ["transition_type3","PLAIN"];
    sleep 0.5;
    [] spawn opx_fnc_displayQuote;
	uiNamespace setVariable ["dsr_mainMenu_cinematic_ran", true];
    sleep 5;
} else {
    playMusic "track2";
    5000 cutRsc ["transition_type2","PLAIN"];
};

opx_cinematic_thread = [] spawn opx_fnc_cinematic;


// Music restarter
addMusicEventHandler ["MusicStop", {
	_track = selectRandom ["track1", "track2"];
	playMusic _track;
}];