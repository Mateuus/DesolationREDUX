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

 
params["_classname",["_target",objNull]];
if(isNull _target) exitWith {};

_success = {
	params["_target"];
	_blood = _target getVariable ["SVAR_DS_var_Blood",27500];
	if(_blood > 15000) then {
		[-15000] remoteExecCall ["DS_fnc_onBloodReceive",_target];
	} else {
		systemchat ((name _target) + " does not have enough blood!");
	};
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname,_target,true,_success,_failure,"dsr_item_bloodbag_full"] call DS_fnc_useItemTarget;