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