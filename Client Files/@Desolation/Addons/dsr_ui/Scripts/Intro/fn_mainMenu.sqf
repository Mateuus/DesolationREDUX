scriptName "fn_mainMenu";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_mainMenu.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_mainMenu.sqf"

disableSerialization;

[] spawn opx_fnc_startMainMenu;

//////////

skipTime (random 24);

// Scene 1
cam camSetPos [9677.26,6176.95,160.714];
cam camSetTarget [10073.3,5931.57,19.281];
cam camSetFOV .9;
cam camSetFocus [20, 0];
cam camCommit 0;

cam camPreparePos [9677.26,6176.95,160.714];
cam camPrepareTarget [9871.81,6663.12,84.9935];
cam camCommitPrepared 40;
sleep 38;

// Scene 2
5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;

skipTime (random 24);

cam camSetPos [3537.93,6026.65,26.7918];
cam camSetTarget [3714.48,5985.32,53.9627];
cam camSetFOV .9;
cam camSetFocus [20, 0];
cam camCommit 0;

cam camPreparePos [3602.8,5875.96,104.924];
cam camPrepareTarget [3714.48,5985.32,53.9627];
cam camCommitPrepared 40;
sleep 38;

// Scene 3
5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;

skipTime (random 24);

cam camSetPos [11196,4228.97,9.42087];
cam camSetTarget [11257.1,4263.96,13.6173];
cam camSetFOV .9;
cam camSetFocus [20, 0];
cam camCommit 0;

cam camPreparePos [11214.7,4246.48,9.06512];
cam camPrepareTarget [11257.1,4263.96,13.6173];
cam camCommitPrepared 40;
sleep 38;

// Scene 4
5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;

skipTime (random 24);

cam camSetPos [12499.3,11742.9,3.03954];
cam camSetTarget [12457.4,11748.1,4.38582];
cam camSetFOV .9;
cam camSetFocus [20, 0];
cam camCommit 0;

cam camPreparePos [12460.8,11761,5.92258];
cam camPrepareTarget [12450.2,11954.6,31.9219];
cam camCommitPrepared 40;
sleep 38;

//////////

2 fadeSound 0;
5000 cutRsc ["transition_type1","PLAIN"];

_d = findDisplay 88001;
{
	_c = _x;
	_c ctrlSetFade 1;
	_c ctrlCommit 2;
} forEach (allControls _d);
sleep 2;

closeDialog 0;

// Restart main menu
opx_mainMenu_thread = [] spawn opx_fnc_mainMenu;

// Fade to character customization
//[] spawn opx_fnc_characterCustomization;

//sleep 20;
//cam cameraEffect ["TERMINATE","BACK"];
//camDestroy cam;
//player switchCamera "INTERNAL";