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

 
 
params["_classname",["_target",""]];
if(_target isEqualType "") then {

	_success = {
		call DS_fnc_stopBleeding;
	};
	_failure = {
		private["_type"];
		_type = _this select 0;
		if(_type != "Player Moved") then {
			systemchat _type;
		};
	};

	[_classname /*"dsr_item_bandage"*/,true,_success,_failure] call DS_fnc_useItem;
	
} else {

	if(isNull _target) exitWith {};
	
	_success = {
		params["_target"];
		[] remoteExecCall ["DS_fnc_stopBleeding",_target];
	};
	_failure = {
		private["_type"];
		_type = _this select 0;
		if(_type != "Player Moved") then {
			systemchat _type;
		};
	};
	
	[_classname /*"dsr_item_bandage"*/,_target,true,_success,_failure] call DS_fnc_useItemTarget;

};
 
 
 
 
 
 
 
