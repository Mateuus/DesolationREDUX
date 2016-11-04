/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

_success = {
	call DS_fnc_stopBleeding;
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};

["dsr_item_bandage",true,_success,_failure] call DS_fnc_useItem;