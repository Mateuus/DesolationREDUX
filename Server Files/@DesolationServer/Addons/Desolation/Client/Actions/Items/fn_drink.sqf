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

params["_classname"];

_giveNewItem = false;
_newItem = "";
if((_classname find '_full' != 0) || (_classname find '_dirty' != 0)) then {
	_data = (toLower(_classname) splitString "_");
	_data deleteAt (count(_data)-1);
	_data pushBack "empty";
	_newItem = _data joinString "_";
	_giveNewItem = true;
};

_success = {
	[20] call DS_fnc_onDrink;
};
_failure = {
	private["_type"];
	_type = _this select 0;
	if(_type != "Player Moved") then {
		systemchat _type;
	};
};
[_classname,true,_success,_failure,_newItem] call DS_fnc_useItem;