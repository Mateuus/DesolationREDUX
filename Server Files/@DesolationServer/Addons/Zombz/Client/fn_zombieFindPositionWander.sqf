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
_pos = getPosATL _zombieAgent;
_distance = 10;
_dir = random 360;
_distance = random (_distance * 30);

_pos = [(_pos select 0) + _distance * sin _dir, (_pos select 1) + _distance * cos _dir, _pos select 2];

_pos
