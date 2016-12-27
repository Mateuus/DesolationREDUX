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
params["_crate","_cItems"];
private["_weapons","_mags","_items","_backpacks"];

_weapons = _cItems select 0;
_mags = _cItems select 1;
_items = _cItems select 2;
_backpacks = _cItems select 3;
{
	_crate addWeaponCargoGlobal [_x,1];
} forEach _weapons;
{
	_crate addMagazineCargoGlobal [_x,1];
} forEach _mags;
{
	_crate addItemCargoGlobal [_x,1];
} forEach _items;
{
	_crate addBackpackCargoGlobal [_x,1];
} forEach _backpacks;