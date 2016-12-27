/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
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
call SM_fnc_infectionTick;
call ds_fnc_onEffectTick;