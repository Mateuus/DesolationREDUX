/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

_sourcesinfo = player getVariable ["DS_var_BleedSourcesInfo",[]];

if(count(_sourcesinfo) > 0) then {
	if !(DS_var_isBleeding) then {
		DS_var_isBleeding = true;
	};
	[_sourcesinfo] call ds_fnc_onBleedTick;
} else {
	if (DS_var_isBleeding) then {
		DS_var_isBleeding = false;
	};
};
call ds_fnc_onHungerTick;
call ds_fnc_onThirstTick;

call ds_fnc_onEffectTick;