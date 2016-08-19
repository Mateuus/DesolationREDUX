/*
	fn_spawnDatabaseVehicles
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
//loadVehicleIdCount//0 inputs

//loadVehicles//get entire array of all vehicles, use count - 1 to loop the spawns :)
_type = "loadVehicleIDs";
_preparedQuery = [0, DESOLATIONSERVERRANDOMID, _type] joinString ":";
_vehDBArray = call compile ("extDB2" callExtension _preparedQuery);
_vehIDArray = _vehDBArray select 1;
diag_log format["[DesolationDebug] Server Array of DB Vehicles - preparedQ:%1",_preparedQuery];
diag_log format["[DesolationDebug] Server Array of DB Vehicles - _vehIDArray:%1",_vehIDArray];
_vehCount = count(_vehIDArray)-1;
for "_v" from 0 to _vehCount do
{
	_type = "loadVehicle";
	_identifier = _vehIDArray select _v select 0;
	diag_log format["[DesolationDebug] Server spawning loop DB Vehicle - _identifier:%1",_identifier];
	_prepOutgoing = format ["%1:%2",_type,_identifier];
	_preparedQuery = [0, DESOLATIONSERVERRANDOMID, _prepOutgoing] joinString ":";
	_dbVehicle = call compile ("extDB2" callExtension _preparedQuery);
	diag_log format["[DesolationDebug] Server spawning loop DB Vehicle - _dbVehicle:%1",_dbVehicle];
	_vehicleArray = _dbVehicle select 1 select 0;
	diag_log format["[DesolationDebug] Server spawning loop DB Vehicle - _vehicleArray:%1",_vehicleArray];
	_vehicleID = _vehicleArray select 0;
	_vehicleClassName = _vehicleArray select 1;
	_vehicleOwnerUID = _vehicleArray select 2;
	_vehicleOwnerLastName = _vehicleArray select 3;
	_vehiclePos = [_vehicleArray select 4,_vehicleArray select 5,_vehicleArray select 6];
	_vehicleDir = _vehicleArray select 7;
	_vehicleLocked = _vehicleArray select 8;
	_vehicleHitPoints = _vehicleArray select 9;
	_vehicleInventory = _vehicleArray select 10;
	//create vehicle
	_vehicle = createVehicle [_vehicleClassName, [0,0,0], [], 0, "CAN_COLLIDE"];
	_vehicle allowDamage false;
	_vehicle setPos _vehiclePos;
	_vehicle setDir _vehicleDir;
	_vehicle setVelocity [0, 0, 0];
	_vehicle allowDamage true;
	for "_h" from 0 to 34 do
	{
		_getHitPointValues = _vehicleHitPoints select _h select 1;
		_vehicle setHitIndex [_h,_getHitPointValues];
	};
	_vehicle setVariable['DS_Veh_Locked',_vehicleLocked,true];
	_vehicle setVariable['DS_Veh_OwnerUID',_vehicleOwnerUID,true];
	
	//vehicleInventory and initEventHandlers
};


_vehCount