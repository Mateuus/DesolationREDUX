/*
	fn_dbSendVehicleClaim
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

//--- player is requesting vehicle claim
private["_playerObj","_vehicleObj","_claimantUID","_playerUID","_vehicleType","_playerName","_hitpointArray","_getAllHitPoints","_getHitPointNames","_getHitPointValues","_vehiclePOS","_vehicleDir","_locked","_inventoryArray"];
_playerObj = _this select 0;
_vehicleObj = _this select 1;
_claimantUID = _vehicleObj getVariable["DS_Veh_OwnerUID",0];
_playerUID = getPlayerUID _playerObj;
if!(_claimantUID isEqualTo _playerUID)exitWith{diag_log "Claimant and Player UID mismatch";};
_vehicleType = TypeOf _vehicleObj;
_playerName = name _playerObj;
_hitpointArray = [];
_getAllHitPoints = getAllHitPointsDamage _vehicleObj;
for "_i" from 0 to 34 do
{
	_getHitPointNames = _getAllHitPoints select 0 select _i;
	_getHitPointValues = _getAllHitPoints select 2 select _i;
	_hitpointArray pushback [_getHitPointNames,_getHitPointValues];
};
_vehiclePOS = getPosATL _vehicleObj;
_vehicleDir = direction _vehicleObj;
_locked = _vehicleObj getVariable['DS_Veh_Locked',0];
_inventoryArray = [];
["claimVehicle",_playerUID, "",[_playerObj,_vehicleType,_playerUID,_playerName,_vehiclePOS select 0,_vehiclePOS select 1,_vehiclePOS select 2,_vehicleDir,_locked,_hitpointArray,_inventoryArray]] call DS_fnc_dbRequest; //--- send claim to database