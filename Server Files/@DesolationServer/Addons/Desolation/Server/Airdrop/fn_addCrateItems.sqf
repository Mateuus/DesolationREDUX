params["_crate","_cItems"];
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