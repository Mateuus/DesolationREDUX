/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
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