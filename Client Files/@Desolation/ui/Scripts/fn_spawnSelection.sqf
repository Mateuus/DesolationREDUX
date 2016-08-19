/*
	DS_spawnSelection UI init
	Created by kegan
*/

disableserialization;
_display = _this select 0;

//--- north
_ctrl = _display displayCtrl 1600;
_ctrl buttonSetAction "
	uiNamespace setVariable ['ds_exitsafe',true];
	closeDialog 0;
	[0] spawn DS_fnc_onRegionSelected;
";
//--- south
_ctrl = _display displayCtrl 1601;
_ctrl buttonSetAction "
	uiNamespace setVariable ['ds_exitsafe',true];
	closeDialog 0;
	[1] spawn DS_fnc_onRegionSelected;
";
//--- east
_ctrl = _display displayCtrl 1602;
_ctrl buttonSetAction "
	uiNamespace setVariable ['ds_exitsafe',true];
	closeDialog 0;
	[2] spawn DS_fnc_onRegionSelected;
";