/*
	fn_setupInvEvents

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
disableSerialization;
waitUntil{!isNull findDisplay 602 || !DSR_var_InvOpen};

_display = findDisplay 602;
if(isNull _display) exitWith {systemchat "ERROR: event displayNull";};
_listboxes = [633,638,619];
{
	_ctrl = (_display displayCtrl _x);
	if(isNull _ctrl) exitWith {systemchat "ERROR: event ctrlNull";};
	_ctrl ctrlAddEventHandler ["LbDblClick",{[_this] spawn dsr_fnc_itemClick}];
} forEach _listboxes;