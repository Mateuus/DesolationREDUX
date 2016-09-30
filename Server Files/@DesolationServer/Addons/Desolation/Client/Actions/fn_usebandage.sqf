_classname = "dsr_item_bandage";
if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
	if([] call ds_fnc_doAction) then {
		if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
			//--- perhaps look up effects TODO
			call DS_fnc_stopBleeding;
			player removeMagazine _classname;
		};
	};
};
