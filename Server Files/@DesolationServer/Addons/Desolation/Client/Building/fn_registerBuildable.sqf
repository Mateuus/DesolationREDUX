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
params["_crate"];

[_crate] spawn OM_fnc_liftObject;
waitUntil{!isNull OM_var_lifted};
waitUntil{isNull OM_var_lifted};

player reveal [_crate, 4];

_crate addEventHandler ["ContainerClosed",{
	params["_container","_player"];
	_data = _container getVariable "SVAR_buildParams";
	_items = _data select 0;
	_magData = getMagazineCargo _container;
	_magItems = call compile tolower(str(_magData select 0));
	_magCount = _magData select 1;
	
	_full = true;
	{
		_itemType = tolower(_x select 0);
		_count = _x select 1;
			
		_index = _magItems find _itemType;
		if(_index == -1) exitWith {_full = false;};
		_mCount = _magCount select _index;
		if(_mCount < _count) exitWith {_full = false;};
	} forEach _items;
	
	if(_full) then {
		[_container] call DS_fnc_onCrateFilled;
	};
}];

//--- TODO: register 3D icons for item requirements