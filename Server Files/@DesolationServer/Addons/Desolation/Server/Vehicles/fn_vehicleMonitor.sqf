/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
while{true} do {
	uiSleep 60*15;
	_newArray1 = [];
	_newArray2 = [];
	{
		_uuid = DS_var_VehicleUUIDS select _forEachIndex;
		if (isNull _x || !(alive _x)) then {
			["destroyVehicle","",[_uuid,objNull]] call DS_fnc_dbRequest;
			if(!isNull _x) then {
				detach _x;
				deleteVehicle _x;
			};
		} else {
			_newArray1 pushBack _x;
			_newArray2 pushBack _uuid;
		};
	} forEach (DS_var_Vehicles);
	DS_var_Vehicles = _newArray1;
	DS_var_VehicleUUIDS = _newArray2;
};