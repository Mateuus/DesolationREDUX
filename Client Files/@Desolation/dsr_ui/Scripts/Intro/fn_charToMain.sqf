scriptName "fn_charToMain";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_charToMain.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_charToMain.sqf"

disableSerialization;
{
	_c = _x;
	_c ctrlSetFade 1;
	_c ctrlCommit 1.9;
} forEach (AllControls (findDisplay 88002));

// Transition
5001 cutRsc ["transition_type1","PLAIN"];
sleep 2;
closeDialog 0;

opx_mainMenu_thread = [] spawn opx_fnc_mainMenu;