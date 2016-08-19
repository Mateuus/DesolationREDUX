/*
	fn_requestSpawn
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

//--- player is requesting to spawn in, determine how they should do it
_playerObj = _this select 0;//type of for handler
_playerUID = getPlayerUID _playerObj;
_playerName = name _playerObj;
_playerObj setVariable["DSPlayerName",_playerName,true];
_playerObj setVariable["DSPlayerDisconnected",false,true];

["joinedAlivePlayerCheck",_playerUID, "DS_fnc_dbOnSpawnResponse",[_playerObj]] call DS_fnc_dbRequest; //--- send request to database