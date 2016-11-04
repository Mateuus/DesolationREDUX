/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_classname",["_removeItem",true],["_oncomplete",{}],["_onfailure",{}],["_replacement",""]];

if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
	if([] call ds_fnc_doAction) then {
		if(({toLower(_x) == toLower(_classname)} count (magazines player)) > 0) then {
			
			if(_removeItem) then {
				player removeMagazine _classname;
			};
			
			call _oncomplete;
			
			if(_replacement != "") then {
				player addMagazine _replacement;
			};
			
		} else {
			["Item Does Not Exist"] call _onfailure;
		};
	} else {
		["Player Moved"] call _onfailure;
	};
} else {
	["Item Does Not Exist"] call _onfailure;
};
