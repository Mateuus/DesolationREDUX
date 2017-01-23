scriptName "fn_cinematic";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_cinematic.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_cinematic.sqf"

disableSerialization;

[] spawn opx_fnc_startMainMenu;

opx_startDate = date;

// Scene 1
cam cameraEffect ["Internal", "Back"];
cam camSetFOV .30;
cam camSetFocus [5, 2];;
cam camSetPos [10025.5,2412.84,0.532604];
cam camSetTarget[10093.5,2385.02,9.50921];
cam camCommit 0;

cam camPrepareFov 0.9;
cam camPreparePos [10025.5,2412.98,1.08452];
cam camPrepareTarget [10117.8,2455.68,8.11908];
cam camCommitPrepared 20;
sleep 0.05;
showCinemaBorder false;

sleep 14;
5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;

[] spawn {
	sleep 3;
	unit2 switchMove "Acts_B_M02_briefing";
};

// Scene 2
cam camSetPos [13063.1,4845.36,0.663498];
cam camSetTarget [13185.2,4880.74,90.5298];
cam camSetFOV .3;
cam camSetFocus [20, 1];
cam camCommit 0;

cam camPreparePos [13059.3,4861.02,0.973633];
cam camPrepareTarget [13181,4861.15,75.325];
cam camCommitPrepared 32;

sleep 10;
5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;
2 fadeSound 0.8;
setDate [2008,5,12,20,10];

unit3_move = true;

// Scene 3
cam camSetPos [9109.61,8917.74,0.744812];
cam camSetTarget [9060.09,8843.79,18.0904];
cam camSetFOV .6;
cam camSetFocus [20, 1];
cam camCommit 0;

cam camPreparePos [9096.53,8920.75,1.48282];
cam camPrepareTarget [9181.47,8800.83,13.4144];
cam camCommitPrepared 27;

sleep 12;

5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;

unit4_move = true;

// Scene 4
cam camSetPos [4801.21,10188.9,1.10138];
cam camSetTarget [4808.49,10184.1,2.30145];
cam camSetFOV .6;
cam camSetFocus [20, 1];
cam camCommit 0;

cam camPreparePos [4782.45,10188,0.430481];
cam camPrepareTarget [4801.86,10204,4.43073];
cam camCommitPrepared 20;

sleep 15;

2 fadeSound 0;
5000 cutRsc ["transition_type1","PLAIN"];
sleep 2;
//setDate _startDate;
//skipTime 2;
//setDate [2008,5,12,20,30];

// Scene 5
cam camSetPos [4529.18,8103.5,1.38016];
cam camSetTarget [4529.43,8104.26,0.449707];
cam camSetFOV .4;
cam camSetFocus [20, 1];
cam camCommit 0;

unit5_move = true;

[] spawn {
	sleep 5;
	cam camSetPos [4528.65,8101.325,1.19777];
	cam camSetFOV 1.2;
	cam camCommit 0;
	cam camPreparePos [4527.95,8099.15,1.01538];
	cam camCommitPrepared 17;
};

cam camPreparePos [4527.95,8099.15,1.01538];
cam camPrepareTarget [4535.36,8123.55,2.26425];
cam camCommitPrepared 20;

unit5_2 switchMove "Acts_ExecutionVictim_KillTerminal";
[] spawn {
	unit5 playMoveNow "Acts_GetAttention_End_2";
};

sleep 10;

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