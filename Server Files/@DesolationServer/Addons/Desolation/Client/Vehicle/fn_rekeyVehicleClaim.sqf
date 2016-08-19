/*
	fn_rekeyVehicleClaim
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

//--- player is requesting vehicle claim
private["_vehicleObj"];
_vehicleObj = _this;
_vehicleObj setVariable['DS_Veh_OwnerUID',(getPlayerUID player),true];
_vehicleObj setVariable['DS_Veh_Locked',0];
_vehicleObj lock 0;
[player,_vehicleObj] remoteExec ["DS_fnc_dbSendVehicleClaim", 2];
