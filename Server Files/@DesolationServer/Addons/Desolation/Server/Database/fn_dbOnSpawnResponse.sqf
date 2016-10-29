/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/

params["_type","_params"];

_playeruuid = _params select 0;
_response = _params select 1;
_playerObj = _params select 2;

switch(_type) do {
	case "load": {
		_playerObj setVariable ["cUUID",_response deleteAt 0];
		[_response,_playerObj] call DS_fnc_requestLoadSpawn;
	};
	case "fresh": {
		//--- fresh spawn
		[] remoteExec ["DS_fnc_freshSpawn",_playerObj]; //--- tell client to start the fresh spawn sequence
	};
};