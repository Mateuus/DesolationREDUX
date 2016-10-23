scriptName "fn_characterCustomization_changeItem";
/*--------------------------------------------------------------------
	Author: Maverick (ofpectag: MAV)
    File: fn_characterCustomization_changeItem.sqf

	<Maverick Applications>
    Written by Maverick Applications (www.maverick-apps.de)
    You're not allowed to use this file without permission from the author!
--------------------------------------------------------------------*/
#define __filename "fn_characterCustomization_changeItem.sqf"

_class = param[0, "", [""]];
_direction = param[1, 0, [0]];

if (_class == "") exitWith {};

if (_class == "clothing") then {
	if (_direction == 0) then {
		if (opx_clothes_index <= 0) then {
			opx_clothes_index = (count opx_clothes) - 1;
		} else {
			opx_clothes_index = opx_clothes_index - 1;
		};
	} else {
		if (opx_clothes_index >= ((count opx_clothes) - 1)) then {
			opx_clothes_index = 0;
		} else {
			opx_clothes_index = opx_clothes_index + 1;
		};
	};
	player forceAddUniform (opx_clothes select opx_clothes_index);
};
if (_class == "glasses") then {
	if (_direction == 0) then {
		if (opx_glasses_index <= 0) then {
			opx_glasses_index = (count opx_glasses) - 1;
		} else {
			opx_glasses_index = opx_glasses_index - 1;
		};
	} else {
		if (opx_glasses_index >= ((count opx_glasses) - 1)) then {
			opx_glasses_index = 0;
		} else {
			opx_glasses_index = opx_glasses_index + 1;
		};
	};
	player addGoggles (opx_glasses select opx_glasses_index);
};
if (_class == "headgear") then {
	if (_direction == 0) then {
		if (opx_headgear_index <= 0) then {
			opx_headgear_index = (count opx_headgear) - 1;
		} else {
			opx_headgear_index = opx_headgear_index - 1;
		};
	} else {
		if (opx_headgear_index >= ((count opx_headgear) - 1)) then {
			opx_headgear_index = 0;
		} else {
			opx_headgear_index = opx_headgear_index + 1;
		};
	};
	player addHeadgear (opx_headgear select opx_headgear_index);
};