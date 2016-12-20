/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_damage"];
_infection = player getVariable ["SM_InfectionDOT",0];


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

	switch true do
	{
		case (_infection < 0.15):
		{
			_damage = _damage + (_infection / ( 1 / SM_InfectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.005, 0.005, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.15) && (_infection < 0.25)):
		{
			_damage = _damage + (_infection / ( 1 / SM_InfectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.01, 0.01, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.25) && (_infection < 0.45)):
		{
			_damage = _damage + (_infection / ( 1 / SM_InfectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.015, 0.015, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.45) && (_infection < 0.65)):
		{
			_damage = _damage + (_infection / ( 1 / SM_InfectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.02, 0.02, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case ((_infection >= 0.65) && (_infection < 0.75)):
		{
			_damage = _damage + (_infection / ( 1 / SM_InfectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.025, 0.025, false];
			SM_InfectionEffect ppEffectCommit 3;
		};

		case (_infection >= 0.75):
		{
			_damage = _damage + (_infection / ( 1 / SM_InfectionDamage));
			SM_InfectionEffect ppEffectAdjust [0.3, 0.3, false];
			SM_InfectionEffect ppEffectCommit 3;
		};
	};

	if !(_damage isEqualTo (damage player)) then
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
