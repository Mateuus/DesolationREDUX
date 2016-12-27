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

//PLEASE NOTE: Lootcrate spawning is only temporary and will be replaced with random loot piles/ lootable crew corpses...

_heliCrashPos = _this select 0;
_crashName = _this select 1;

//not implemented yet
//_maxPiles = getNumber configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "loot" >> "maxLootpiles");

_weaponLoot = getArray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "loot" >> "weapons");
_magazineLoot = getArray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "loot" >> "magazines");
_itemLoot = getArray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "loot" >> "items");
_backpackLoot = getArray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "loot" >> "backpacks");


_lootCratePos = _heliCrashPos findEmptyPosition [1, 30, "Box_NATO_Wps_F"];
_lootcrate = "Box_NATO_Wps_F" createVehicle _lootCratePos;

//place weapons in crate
if !(count _weaponLoot > 0) then {
	{
		_lootcrate addWeaponCargoGlobal [_x, 1];
	}foreach _weaponLoot;
};

//place mags in crate
if !(count _magazineLoot > 0) then {
	{
		_lootcrate addMagazineCargoGlobal [_x, 3];
	}foreach _magazineLoot;
};

//place items in crate
if !(count _itemLoot > 0) then {
	{
		_lootcrate addItemCargoGlobal [_x, 1];
	}foreach _itemLoot;
};

//place backpacks in crate
if !(count _backpackLoot > 0) then {
	{
		_lootcrate addbackpackCargoGlobal [_x, 1];
	}foreach _backpackLoot;
};

true