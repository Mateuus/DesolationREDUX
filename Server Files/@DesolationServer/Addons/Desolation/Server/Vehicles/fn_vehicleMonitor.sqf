/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

//TODO: this updates like every 5 minutes or some shit, why is it updating????
DS_var_finishedVehicles = true;
call DS_fnc_checkServerLock;

while{true} do {
	uiSleep (60*30);
	diag_log  "Vehicle Monitor> Updating Database";
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
			["updateVehicle","",[_x]] call DS_fnc_dbRequest;
			_newArray1 pushBack _x;
			_newArray2 pushBack _uuid;
		};
	} forEach (DS_var_Vehicles);
	diag_log  "Vehicle Monitor> Done";
	DS_var_Vehicles = _newArray1;
	DS_var_VehicleUUIDS = _newArray2;
};