/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private["_lootHolder"];
_zombie = objectFromNetId (_this select 0);
_player = objectFromNetId (_this select 1);

_zombie setVariable ["SM_HasBeenGutted",true,true];

_attachedObj = attachedObjects _zombie;
_lootHolder = objNull;
if!(_attachedObj isEqualTo []) then
{
	{
		if((typeOf _x) isEqualTo "LootWeaponHolder") exitWith 
		{
			_lootHolder = _x;
		};
	} forEach _attachedObj;
};

if(isNull _lootHolder) then
{
	_lootHolder = createVehicle["LootWeaponHolder", (getPosATL _zombie), [], 0, "CAN_COLLIDE"];
	_lootHolder attachTo [_zombie, [0,0,0]];
};

_lootHolder addMagazineCargoGlobal ["SM_Zombz_Item_Heart",1];

true
