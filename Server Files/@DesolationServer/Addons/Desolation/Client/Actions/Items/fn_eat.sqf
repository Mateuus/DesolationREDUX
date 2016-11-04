/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_classname"];
_success = {
	DS_var_hunger = (DS_var_hunger + 20) min 100;
	DS_var_lastAte = diag_tickTime;
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname,true,_success,_failure] call DS_fnc_useItem;

