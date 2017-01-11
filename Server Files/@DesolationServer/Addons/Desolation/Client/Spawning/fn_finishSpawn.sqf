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

params["_unit",["_goggles",""]];


selectPlayer _unit;

if(_goggles != "") then {
	_goggles spawn {
		uiSleep 2;
		removeGoggles player;
		player addGoggles _this;
		systemchat "GIVEN GOGGLES";
	};
};
//--- fade into the game
1 fadeSound 2;
1 fadeMusic 2;
0 cutText ["","BLACK IN",2];
//--- show region
[] spawn DS_fnc_showRegionNotification;
//--- init subsystems

	// starting health systems
call ds_fnc_initHealthSys;
[] spawn DS_fnc_initStatusSys;
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
	_text = _text + "<t size='1.4' align='center' color='#FFFFFF'>Desolation <t color='#FF3333'>Redux</t></t><br/><t size='1.1' align='center'>Debug</t><br/><br/>";
	_text = _text + "<t color='#FFFF55' align='left' size='0.9'>Damage:</t><t align='right' size='0.9'>" + str(damage player) + "</t><br/>";
	_text = _text + "<t color='#FF5555' align='left' size='0.9'>Blood:</t><t align='right' size='0.9'>" + str(DS_var_Blood) + "</t><br/>";
	_text = _text + "<t color='#55FF55' align='left' size='0.9'>Hunger:</t><t align='right' size='0.9'>" + str(DS_var_Hunger) + "</t><br/>";
	_text = _text + "<t color='#5555FF' align='left' size='0.9'>Thirst:</t><t align='right' size='0.9'>" + str(DS_var_Thirst) + "</t><br/>";
	_text = _text + "<t color='#55FFFF' align='left' size='0.9'>FPS:</t><t align='right' size='0.9'>" + str(diag_fps) + "</t><br/>";
	_text = _text + "<t color='#FF55FF' align='left' size='0.9'>Scripts:</t><t align='right' size='0.9'>" + str(diag_activeScripts) + "</t><br/>";
	
	
	hintSilent parseText (_text);
}];