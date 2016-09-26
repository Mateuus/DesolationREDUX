/*
	fn_closeButtons

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
disableSerialization;
_buttons = uiNamespace getVariable ["dsr_var_itemButtons",[]];
{
	if(!isNull _x) then {
		ctrlDelete _x;
	};
} forEach _buttons;
uiNamespace setVariable ["dsr_var_itemButtons",[]];