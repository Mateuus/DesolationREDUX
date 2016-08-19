/*
	fn_dbSendStatsUpdate
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

//--- player is requesting stats update
_playerObj = _this select 0;

_hitpointArray = [];
_getAllHitPoints = getAllHitPointsDamage _playerObj;
for "_i" from 0 to 10 do
{
	_getHitPointNames = _getAllHitPoints select 0 select _i;
	_getHitPointValues = _getAllHitPoints select 2 select _i;
	_hitpointArray pushback [_getHitPointNames,_getHitPointValues];
};

_playerUID = _playerObj getVariable["DSPlayerUID",""];
_playerPOS = getPosATL _playerObj;
_playerDir = direction _playerObj;
_equipmentArray=getUnitLoadout _playerObj;
_playerFood = _playerObj getVariable["DS_statFood",0];
_playerDrink = _playerObj getVariable["DS_statDrink",0];
_playerBloodLeft = _playerObj getVariable["DS_statBloodLeft",0];
_playerBloodPressure = _playerObj getVariable["DS_statBloodPressure",0];
_playerTemperature = _playerObj getVariable["DS_statTemperature",0];
_playerInfection = _playerObj getVariable["DS_statInfection",0];
_playerWetness = _playerObj getVariable["DS_statWetness",0];
_playerSoiled = _playerObj getVariable["DS_statSoiled",0];
_playerSanity = _playerObj getVariable["DS_statSanity",0];
diag_log format["[DesolationDebug]newEquipmentArray from getUnitLoadout:%1",_equipmentArray];
["updateMyPlayer",_playerUID, "",[_playerObj,_hitpointArray,_playerPOS select 0,_playerPOS select 1,_playerPOS select 2,_playerDir,_equipmentArray,_playerFood,_playerDrink,_playerBloodLeft,_playerBloodPressure,_playerTemperature,_playerInfection,_playerWetness,_playerSoiled,_playerSanity]] call DS_fnc_dbRequest; //--- send request to database