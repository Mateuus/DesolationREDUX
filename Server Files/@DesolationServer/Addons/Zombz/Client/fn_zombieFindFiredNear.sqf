/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

params ["_zombieAgent"];

_firedNear = _zombieAgent getVariable ["SM_FiredNear",[]];

if (_firedNear isEqualTo []) exitWith
{
	[]
};

_distance = 1000;
_pos = [];

{
	_distanceEnemy = _zombieAgent distance _x;
	if (_distanceEnemy <= _distance) then
	{
		_distance = _distanceEnemy;
		_pos = _x;
	};
} forEach _firedNear;

_zombieAgent setVariable ["SM_FiredNear",nil];

_pos