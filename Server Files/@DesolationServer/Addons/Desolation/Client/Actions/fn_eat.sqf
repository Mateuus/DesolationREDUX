

params["_classname"];

if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
	if([] call ds_fnc_doAction) then {
		if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
			//--- perhaps look up effects TODO
			DS_var_hunger = (DS_var_hunger + 20) min 100;
			DS_var_lastAte = diag_tickTime;
			player removeMagazine _classname;
		};
	};
};
