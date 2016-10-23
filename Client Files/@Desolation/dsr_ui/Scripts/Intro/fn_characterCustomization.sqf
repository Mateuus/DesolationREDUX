scriptName "fn_characterCustomization";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_characterCustomization.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_characterCustomization.sqf"

// Lower weapon
player playMove "amovpercmstpsnonwnondnon";

// DAY!!
setDate opx_startDate;

// Vars
opx_clothes = ["U_BG_Guerilla3_1","U_BG_Guerilla2_3","U_BG_Guerilla2_1","U_BG_Guerilla2_2","TRYK_shirts_DENIM_BWH","TRYK_shirts_DENIM_R","TRYK_shirts_DENIM_ylb","TRYK_shirts_BLK_PAD_BLW","TRYK_shirts_BLK_PAD"];
opx_glasses = ["G_Aviator","G_Spectacles","G_Sport_Greenblack","G_Squares_Tinted","G_Shades_Black",""];
opx_headgear = ["H_Bandanna_gry","H_Bandanna_sand","H_Booniehat_oli","H_Booniehat_tan","H_Cap_blk","H_Cap_grn","H_Hat_grey","H_StrawHat_dark","H_Cap_grn_BI","H_Cap_blu",""];

opx_clothes_index = -1;
opx_glasses_index = -1;
opx_headgear_index = -1;

// Items and stance
player addWeapon "CUP_arifle_M16A4_Aim_Laser";
if (!isNil "BIS_fnc_ambientAnim__terminate") then {
	player call BIS_fnc_ambientAnim__terminate;
};
[player, "STAND1", "ASIS"] call BIS_fnc_ambientAnim;

// Close dialogs
closeDialog 0;

// Terminate parent thread
terminate (missionNamespace getVariable ["opx_mainMenu_thread", scriptNull]);
terminate (missionNamespace getVariable ["opx_cinematic_thread", scriptNull]);

// Set player to pos
cam camSetFOV .90;
cam camSetFocus [1, 1];
cam camSetPos [8848.92,2838.95,1.15129];
cam camSetTarget [8849.8,2839.98,1.19461];
cam camCommit 0;

// Sleep and open dialog
sleep 2;
createDialog "characterCustomization";

// Buttons
waitUntil {!isNull (findDisplay 88002)};
disableSerialization;
_d = findDisplay 88002;
_d displayAddEventHandler ["KeyDown",{
	_return = false;
	if((_this select 1) == 1) then {
		_return = true;
	};
	_return;
}];
(_d displayCtrl 8) ctrlAddEventHandler ["ButtonDown", {
	["headgear", 0] spawn opx_fnc_characterCustomization_changeItem;
}];
(_d displayCtrl 9) ctrlAddEventHandler ["ButtonDown", {
	["headgear", 1] spawn opx_fnc_characterCustomization_changeItem;
}];
(_d displayCtrl 10) ctrlAddEventHandler ["ButtonDown", {
	["glasses", 0] spawn opx_fnc_characterCustomization_changeItem;
}];
(_d displayCtrl 3) ctrlAddEventHandler ["ButtonDown", {
	["glasses", 1] spawn opx_fnc_characterCustomization_changeItem;
}];
(_d displayCtrl 4) ctrlAddEventHandler ["ButtonDown", {
	["clothing", 1] spawn opx_fnc_characterCustomization_changeItem;
}];
(_d displayCtrl 5) ctrlAddEventHandler ["ButtonDown", {
	["clothing", 0] spawn opx_fnc_characterCustomization_changeItem;
}];

(_d displayCtrl 7) ctrlAddEventHandler ["ButtonDown", {
	[] spawn opx_fnc_charToMain;
}];