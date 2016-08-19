/*
	fn_playerUpdateStats
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

waitUntil {alive player};
uisleep 1;
_playerFood = player getVariable["DS_statFood",100];
_playerDrink = player getVariable["DS_statDrink",100];
_playerBloodLeft = player getVariable["DS_statBloodLeft",16000];
_playerBloodPressure = player getVariable["DS_statBloodPressure",80];
_playerTemperature = player getVariable["DS_statTemperature",98.6];
_playerInfection = player getVariable["DS_statInfection",0];
_playerWetness = player getVariable["DS_statWetness",0];
_playerSoiled = player getVariable["DS_statSoiled",0];
_playerSanity = player getVariable["DS_statSanity",0];
player setVariable["DS_statFood",_playerFood,true];
player setVariable["DS_statDrink",_playerDrink,true];
player setVariable["DS_statBloodLeft",_playerBloodLeft,true];
player setVariable["DS_statBloodPressure",_playerBloodPressure,true];
player setVariable["DS_statTemperature",_playerTemperature,true];
player setVariable["DS_statInfection",_playerInfection,true];
player setVariable["DS_statWetness",_playerWetness,true];
player setVariable["DS_statSoiled",_playerSoiled,true];
player setVariable["DS_statSanity",_playerSanity,true];
[player] remoteExec ["DS_fnc_dbSendStatsUpdate", 2];
while{alive player}do{
	uiSleep 30;
	[player] remoteExec ["DS_fnc_dbSendStatsUpdate", 2];
	//add get from config here to modify save times :)
};