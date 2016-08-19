/*
	fn_onPlayerKilled
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
diag_log "[DesolationDebug] onPlayerKilled:You just died";
[player] remoteExec ["DS_fnc_fn_dbOnPlayerKilled", 2];
