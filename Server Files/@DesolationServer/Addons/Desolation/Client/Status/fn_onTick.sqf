/*
	fn_onTick

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_sourcesinfo = player getVariable ["DS_var_BleedSourcesInfo",[]];
if(count(_sourcesinfo) > 0) then {
	[_sourcesinfo] call ds_fnc_onBleedTick;
};
call ds_fnc_onHungerTick;
call ds_fnc_onThirstTick;

call ds_fnc_onEffectTick;