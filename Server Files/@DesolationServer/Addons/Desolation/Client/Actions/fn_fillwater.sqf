params["_classname"];

if !(_classname find "_empty") exitWith {};
_data = (toLower(_classname) splitString "_");
_data deleteAt (count(_data)-1);
_data pushBack "dirty";
_newItem = _data joinString "_";

_success = {
	systemchat "Filled with water";
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname,true,_success,_failure,_newItem] call DS_fnc_useItem;
