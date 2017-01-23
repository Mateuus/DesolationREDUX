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
params["_player",["_respond",true]];
NULL_CALLBACK = compileFinal "";
["savePlayer","NULL_CALLBACK",[_player]] call DS_fnc_dbRequest;
if(_respond) then {
	"Data saved" remoteExec ["systemChat",_player];
} else {
	deleteVehicle _player;
};