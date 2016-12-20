/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Not me.
private ["_itemClassName","_cargoType","_itemType"];
_itemClassName = _this;
_cargoType = 4;
_itemType = [_itemClassName] call BIS_fnc_itemType;
switch (_itemType select 0) do 
{
	case "Weapon": 		{ _cargoType = 2; };
	case "Mine": 		{ _cargoType = 1; };
	case "Magazine": 	{ _cargoType = 1; };
	case "Item":		{ _cargoType = 4; };
	case "Equipment": 
	{ 
		if ((_itemType select 1) == "Backpack" ) then
		{
			_cargoType = 3; 
		}
		else 
		{
			_cargoType = 4; 
		};
	};
};

_cargoType
