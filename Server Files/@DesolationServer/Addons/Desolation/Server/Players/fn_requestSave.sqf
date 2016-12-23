/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params["_player",["_respond",true]];
NULL_CALLBACK = compileFinal "";
["savePlayer","NULL_CALLBACK",[_player]] call DS_fnc_dbRequest;
if(_respond) then {
	"Data saved" remoteExec ["systemChat",_player];
} else {
	deleteVehicle _player;
};