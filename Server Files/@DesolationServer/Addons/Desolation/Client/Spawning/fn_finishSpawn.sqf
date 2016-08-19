/*
	fn_finishSpawn
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_unit"];


//--- todo: initialize event handlers on unit
selectPlayer _unit;
1 fadeSound 2;
1 fadeMusic 2;
0 cutText ["","BLACK IN",2];
[] spawn DS_fnc_showRegionNotification;
[] spawn DS_fnc_playerUpdateStats;
call DS_fnc_initBleedingSystem;
call DS_fnc_initEventHandlers;
call DS_fnc_registerPlayer;
