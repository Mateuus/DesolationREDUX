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
_config = configFile >> "CfgAirdropSpawns";
_config = _config select floor(random(count(_config)));

_weapons = getArray(_config >> "weapons");
_magazines = getArray(_config >> "magazines");
_items = getArray(_config >> "items");
_backpacks = getArray(_config >> "backpacks");

_selection = [];
if(count(_weapons) > 0) then {_selection pushback [1,_weapons];};
if(count(_magazines) > 0) then {_selection pushback [2,_magazines];};
if(count(_items) > 0) then {_selection pushback [3,_items];};
if(count(_backpacks) > 0) then {_selection pushback [4,_backpacks];};



_out = [getText(_config >> "name"),[],[],[],[]];
for "_i" from 0 to 4+ceil(random(4)) do {
	if(_selection isEqualTo []) exitWith {};

	_index = floor(random(count(_selection)));
	
	_array = _selection select _index;
	
	_outIndex = _array select 0;
	_itemList = _array select 1;
	
	_item = _itemList deleteAt floor(random(count(_itemList)));
	if(_itemList isEqualTo []) then {
		_selection deleteAt _index;
	} else {
		_array set[1,_itemList];
		_selection set[_index,_array];
	};
	
	_outArray = _out select _outIndex;
	_outArray pushback _item;
	_out set[_outIndex,_outArray];
};
_out;