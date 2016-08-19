/*
	fn_playerUpdateStats
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
waitUntil {alive player};
while{alive player}do{
	uiSleep 30;
	[player] remoteExec ["DS_fnc_dbSendStatsUpdate", 2];
	//add get from config here to modify save times :)
};