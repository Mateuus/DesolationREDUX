params["_classname"];

if !(_classname find "_empty") exitWith {};
_data = (toLower(_classname) splitString "_");
_data deleteAt (count(_data)-1);
_data pushBack "dirty";
_newItem = _data joinString "_";

if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
	if([] call ds_fnc_doAction) then {
		if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
			//--- perhaps look up effects TODO
			player removeMagazine _classname;
			player addMagazine _newItem;
		};
	};
};
