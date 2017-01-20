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
	_state = lifeState _target;
	if(_state == "INCAPACITATED") then {
		_target setVariable ["DS_var_Defibbed",true,true];
	} else {
		[-500] remoteExecCall ["DS_fnc_onBloodRecive", _target];
	};
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname,_target,false,_success,_failure] call DS_fnc_useItemTarget;