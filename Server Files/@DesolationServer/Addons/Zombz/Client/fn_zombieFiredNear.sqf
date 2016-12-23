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

private ["_zombieAgent","_fired","_zombiePosition","_firedPosition","_zombieVariable"];
_zombieAgent = _this select 0;
_fired = _this select 7;

if !(isPlayer _fired) exitWith {};

_zombiePosition = position _zombieAgent;
_firedPosition = position _fired;
_zombieVariable = _zombieAgent getVariable ["SM_FiredNear", []];
_zombieVariable pushBack _firedPosition;
_zombieAgent setVariable ["SM_FiredNear", _zombieVariable];

true
