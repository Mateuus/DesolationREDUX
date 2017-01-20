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
	systemchat "TAKE TARGETS BLOOD HERE";
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname/*"dsr_item_bloodbag_empty"*/,_target,true,_success,_failure,"dsr_item_bloodbag_full"] call DS_fnc_useItemTarget;