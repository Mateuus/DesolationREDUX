/*
	fn_handleDisconnect
	
	Desolation Redux
	2016 Desolation Dev Team
	By Kegan
	License info here and copyright symbol above
*/

_unit = _this select 0;
_unitID = _this select 1;
_unitUID = _this select 2;
_unitName = _this select 3;

_unit setVariable ["DCed",true];
if(alive _unit) then {
	[_unit,false] call DS_fnc_requestSave;
};

// deleteVehicle _unit; // (why was this here??)