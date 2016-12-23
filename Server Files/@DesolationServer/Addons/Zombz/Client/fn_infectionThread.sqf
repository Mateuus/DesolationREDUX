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


private ["_damage"];
_infection = player getVariable ["SM_InfectionDOT", 0];


if (_infection > 0) then
{
	if (isNil "SM_InfectionEffect") then
	{
		SM_InfectionEffect = ppEffectCreate ["ChromAberration", 1000];
		SM_InfectionEffect ppEffectEnable true;
	};

	if (player getVariable ["SM_IsImmune",false]) exitWith
	{
		SM_InfectionEffect ppEffectAdjust [0, 0, false]; 
		SM_InfectionEffect ppEffectCommit 2;
	};
	_damage = damage player;

	_infectionDamage = ["infectionDamage","SM"] call SM_fnc_getCfgValue;

	switch true do
	{
		case (_infection < 0.15):
		{
			_damage = _damage + (_infection / ( 1 / _infectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.005, 0.005, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.15) && (_infection < 0.25)):
		{
			_damage = _damage + (_infection / ( 1 / _infectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.01, 0.01, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.25) && (_infection < 0.45)):
		{
			_damage = _damage + (_infection / ( 1 / _infectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.015, 0.015, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.45) && (_infection < 0.65)):
		{
			_damage = _damage + (_infection / ( 1 / _infectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.02, 0.02, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.65) && (_infection < 0.75)):
		{
			_damage = _damage + (_infection / ( 1 / _infectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.025, 0.025, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case (_infection >= 0.75):
		{
			_damage = _damage + (_infection / ( 1 / _infectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.3, 0.3, false];
			SM_InfectionEffect ppEffectCommit 3;
		};
	};

	if (_damage != (damage player)) then
	{
		player setDamage _damage;
	};
}
else
{
	if !(isNil "SM_InfectionEffect") then
	{
		ppEffectDestroy SM_InfectionEffect;
		SM_InfectionEffect = nil;
	};
};

true
