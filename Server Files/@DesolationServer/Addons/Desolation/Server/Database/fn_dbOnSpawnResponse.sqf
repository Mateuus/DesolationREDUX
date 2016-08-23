/*
	fn_dbOnSpawnResponse
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_type","_params"];

_playerObj = _params select 0;




switch(_type) do {
	case "load": {
		_dbIdentifier = getplayeruid _playerObj;
		_dbCallback = "DS_fnc_dbLoadPlayerResponse";
		["requestPlayerData",_dbIdentifier, _dbCallback,[_playerObj]] call DS_fnc_dbRequest; //--- request the players data from the database
	};
	case "fresh": {
		[] remoteExec ["DS_fnc_freshSpawn",_playerObj]; //--- tell client to start the fresh spawn sequence
	};
};