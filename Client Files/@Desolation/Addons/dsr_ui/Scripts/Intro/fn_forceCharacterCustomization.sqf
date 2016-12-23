scriptName "fn_forceCharacterCustomization";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_forceCharacterCustomization.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_forceCharacterCustomization.sqf"

disableSerialization;

// Fade out all controls of main menu
_d = findDisplay 88001;
{
	_c = _x;
	_c ctrlEnable false;
	_c ctrlSetFade 1;
	_c ctrlCommit 1;
} forEach (allControls _d);

// Sound
2 fadeSound 0;

// Transition
5001 cutRsc ["transition_type1","PLAIN"];
sleep 2;

// Fade to character customization
[] spawn opx_fnc_characterCustomization;