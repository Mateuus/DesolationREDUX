

params["_classname"];

_giveNewItem = false;
_newItem = "";
if((_classname find '_full' != 0) || (_classname find '_dirty' != 0)) then {
	_data = (toLower(_classname) splitString "_");
	_data deleteAt (count(_data)-1);
	_data pushBack "empty";
	_newItem = _data joinString "_";
};

if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
	if([] call ds_fnc_doAction) then {
		if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
			//--- perhaps look up effects TODO
			DS_var_thirst = (DS_var_thirst + 20) min 100;
			DS_var_lastDrank = diag_tickTime;
			player removeMagazine _classname;
			if(_giveNewItem) then {
				player addMagazine _newItem;
			};
		};
	};
};
