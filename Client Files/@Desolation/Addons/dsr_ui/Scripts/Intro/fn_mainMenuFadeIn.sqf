scriptName "fn_mainMenuFadeIn";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_mainMenuFadeIn.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_mainMenuFadeIn.sqf"

disableSerialization;

_d = findDisplay 88001;

{
	_c = _x;
	_startPos = ctrlPosition _c;
	_finalPos = if ((ctrlClassName  _c) in ["RscText_1004","RscText_1088","RscText_1005","RscText_1006"]) then {
		[(0.018  * safezoneW + safezoneX), _startPos select 1, _startPos select 2, _startPos select 3];
	} else {
		[(0.01  * safezoneW + safezoneX), _startPos select 1, _startPos select 2, _startPos select 3];
	};

	_c ctrlSetFade 1;
	_c ctrlSetPosition _startPos;
	_c ctrlCommit 0;

	_c ctrlSetPosition _finalPos;
	_c ctrlCommit 2.5;
} forEach (allControls _d);

sleep 1.5;

{
	_x ctrlSetFade 0;
	_x ctrlCommit 1;
} forEach (allControls _d);