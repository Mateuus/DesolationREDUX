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
call DS_fnc_initStatusSys;
call DS_fnc_initBleedingSystem;
call DS_fnc_registerPlayer;
call DS_fnc_initEventHandlers;

//--- init removable plugins
if(!isNil "RSM_fnc_initRealism") then {
	[player] call RSM_fnc_initRealism;
};

//--- TEMP
addMissionEventHandler ["EachFrame",{
	_text = "";
	_text = _text + "<t align='center' size='1.5'><img image='\dsr_ui\Assets\logo.paa'><br/>Debug Menu</t><br/><br/>";
	_text = _text + "<t color='#FFFF33' align='left' size='0.9'>Damage:</t><t align='right' size='0.9'>" + str(damage player) + "</t><br/>";
	_text = _text + "<t color='#FF3333' align='left' size='0.9'>Blood:</t><t align='right' size='0.9'>" + str(DS_var_Blood) + "</t><br/>";
	_text = _text + "<t color='#33FF33' align='left' size='0.9'>Hunger:</t><t align='right' size='0.9'>" + str(DS_var_Hunger) + "</t><br/>";
	_text = _text + "<t color='#3333FF' align='left' size='0.9'>Thirst:</t><t align='right' size='0.9'>" + str(DS_var_Thirst) + "</t><br/>";
	_text = _text + "<t color='#33FFFF' align='left' size='0.9'>FPS:</t><t align='right' size='0.9'>" + str(diag_fps) + "</t><br/>";
	_text = _text + "<t color='#FF33FF' align='left' size='0.9'>Scripts:</t><t align='right' size='0.9'>" + str(diag_activeScripts) + "</t><br/>";
	
	
	hintSilent parseText (_text);
}];