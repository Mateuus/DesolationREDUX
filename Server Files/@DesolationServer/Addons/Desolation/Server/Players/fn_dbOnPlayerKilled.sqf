/*
	fn_dbOnPlayerKilled
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

//--- player is requesting stats update
_victim = _this select 0;
_disconnected = _victim getVariable ["DSPlayerDisconnected",false];
if!(_disconnected)then{
	_victimUID = _victim getVariable["DSPlayerUID",""];
	
	if(_victimUID == "") exitWith {diag_log "Player died w/ no uid?";};
	
	["onPlayerKilled",_victimUID, "",[_victim]] call DS_fnc_dbRequest; //--- send request to database

	["deleteAlivePlayer",_victimUID, "",[_victim]] call DS_fnc_dbRequest; //--- send request to database

	_victimName = _victim getVariable["DSPlayerName",""];
	_victimPOS = getPosATL _victim;
	_killer = _this select 1;
	_killerWeapon = currentWeapon _killer;
	_killerName = name _killer;
	_killerUID = getplayerUID _killer;
	//if(isNil _killerName)then{_killerName = "UnknownK"};
	//if(isNil _killerUID)then{_killerUID = "UnknownUID"};

	_type = "insertDeadPlayer";
	_prepOutgoing = format ["%1:%2:%3:%4:%5:%6:%7:%8:%9:%10",_type,_victimUID,_victimName,_victimPOS select 0,_victimPOS select 1,_victimPOS select 2,_killerUID,_killerName,_killerWeapon,_distance];
	_preparedQuery = [1, DESOLATIONSERVERRANDOMID,_prepOutgoing] joinString ":";
	diag_log format["[DesolationDebug] onPlayerKilled preparedQ:%1",_preparedQuery];
	call compile ("extDB2" callExtension _preparedQuery);

	//-DonkeyPunch custom identify body code for another addition :)
	_distance = _victim distance _killer;
	_deathTime = serverTime;
	_deathinfo = [_killerName,_killerWeapon,_distance,_deathTime];
	_victim setVariable ["DSIdentifyBody", _deathinfo, true];
};