/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

disableSerialization;
_buttons = uiNamespace getVariable ["ds_var_itemButtons",[]];
{
	if(!isNull _x) then {
		ctrlDelete _x;
	};
} forEach _buttons;
uiNamespace setVariable ["ds_var_itemButtons",[]];