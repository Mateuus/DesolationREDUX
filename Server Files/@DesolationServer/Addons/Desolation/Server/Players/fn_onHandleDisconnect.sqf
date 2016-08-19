/*
	fn_OnHandleDisconnect
	
	Desolation Redux
	2016 Desolation Dev Team
	By Kegan
	License info here and copyright symbol above
*/

_unit = _this select 0;
_unitID = _this select 1;
_unitUID = _this select 2;
_unitName = _this select 3;
_unit setVariable ["DSPlayerDisconnected",true]; //--- removed (global variable) toggle
[_unit] call DS_fnc_dbSendStatsUpdate;
deleteVehicle _unit;
_unit = objNull;