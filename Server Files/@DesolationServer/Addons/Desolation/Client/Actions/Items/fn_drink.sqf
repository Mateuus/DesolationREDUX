

params["_classname"];

_giveNewItem = false;
_newItem = "";
if((_classname find '_full' != 0) || (_classname find '_dirty' != 0)) then {
	_data = (toLower(_classname) splitString "_");
	_data deleteAt (count(_data)-1);
	_data pushBack "empty";
	_newItem = _data joinString "_";
	_giveNewItem = true;
};

_success = {
	DS_var_thirst = (DS_var_thirst + 20) min 100;
	DS_var_lastDrank = diag_tickTime;
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname,true,_success,_failure,_newItem] call DS_fnc_useItem;