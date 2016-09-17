/*
	fn_finishSpawn
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_unit"];


//--- todo: initialize event handlers on unit
selectPlayer _unit;
//--- fade into the game
1 fadeSound 2;
1 fadeMusic 2;
0 cutText ["","BLACK IN",2];
//--- show region
[] spawn DS_fnc_showRegionNotification;
//--- init subsystems
call DS_fnc_initBleedingSystem;
call DS_fnc_registerPlayer;
call DS_fnc_initEventHandlers;

//--- init removable plugins
if(!isNil "RSM_fnc_initRealism") then {
	[player] call RSM_fnc_initRealism;
};