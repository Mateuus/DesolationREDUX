/*
	fn_dbLoadPlayerResponse
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_data","_params"];
diag_log format["[DesolationDebug]loadPlayerResp _data:%1 _params:%2",_data,_params];
_playerObj = _params select 0;
_playerUID = getplayeruid _playerObj;
_dataArray = (_data select 1) select 0;
_playerDBUID = _dataArray select 0;
_lastName = _dataArray select 1;
_playerHitPoints = _dataArray select 2;
_playerPositionX = _dataArray select 3; 
_playerPositionY = _dataArray select 4;
_playerPositionZ = _dataArray select 5; //--- this should always be 0,just to make sure we will log it & sset it to 0
_playerDir = _dataArray select 6;
_equipmentArray = _dataArray select 7;
_playerFood = _dataArray select 8;
_playerDrink = _dataArray select 9;
_playerBloodLeft = _dataArray select 10;
_playerBloodPressure = _dataArray select 11;
_playerTemperature = _dataArray select 12;
_playerInfection = _dataArray select 13;
_playerWetness = _dataArray select 14;
_playerSoiled = _dataArray select 15;
_playerSanity = _dataArray select 16;

diag_log format["<LOAD PLAYER RESPONSE INFO>: player Z is %1 in the databse, should be 0", _playerPositionZ];

if(_playerUID != _playerDBUID) exitWith {diag_log "<LOAD PLAYER RESPONSE ERROR>: Bad UID response? This really should never happen?";};//Send an end mission to client as to not spawn in loading zone

//--- finish player spawn
_unit = (createGroup CIVILIAN) createUnit [typeof _playerObj, [_playerPositionX,_playerPositionY,_playerPositionZ], [],0, "NONE"]; //--- create the unit at the players location
_unit allowDamage false;
_unit hideObjectGlobal true;
	[_unit,_equipmentArray] call DS_fnc_setupLoadout; //--- load the players inventory into the unit
_unit hideObjectGlobal false;
_unit allowDamage true;
_unit setVariable["DSPlayerUID",_playerUID,true];
_unit setVariable["DSPlayerName",name _playerObj,true];//-- names lol
_unit setVariable["DS_isPlayerInCombat",false,true];//-- start to a combat logging system
_unit setVariable["DS_isPlayerSleeping",false,true];//-- for those that kill sleeping peeps - bandit rank added :)
for "_i" from 0 to 10 do {
	_getHitPointValues = _playerHitPoints select _i select 1;
	_unit setHitIndex [_i,_getHitPointValues];
};
_playerStatsArray = [_playerFood,_playerDrink,_playerBloodLeft,_playerBloodPressure,_playerTemperature,_playerInfection,_playerWetness,_playerSoiled,_playerSanity];
diag_log format["[DesolationDebug]loadPlayerResp _playerStatsArray:%1",_playerStatsArray];
_unit addMPEventHandler ["MPKilled", {_this call DS_fnc_dbOnPlayerKilled}];
[_unit,_playerStatsArray] remoteExecCall ["DS_fnc_finishSpawn",_playerObj]; //--- tell player to spawn w/ this unit we created