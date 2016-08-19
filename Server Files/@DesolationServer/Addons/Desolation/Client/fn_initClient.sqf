/*
	fn_initClient
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

0 cutText ["Waiting for server...","BLACK FADED",2];
0 fadeSound 0;
0 fadeMusic 0;



//asks the server to spawn us
[player] remoteExec ["DS_fnc_requestSpawn", 2];
