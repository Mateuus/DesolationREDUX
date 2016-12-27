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

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/


private ["_damage"];
_infection = SM_InfectionDOT;


if (_infection > 0) then
{
	if (isNil "SM_InfectionEffect") then
	{
		SM_InfectionEffect = ppEffectCreate ["ChromAberration", 1000];
		SM_InfectionEffect ppEffectEnable true;
	};

	if (SM_IsImmune) exitWith
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
			SM_InfectionEffect ppEffectAdjust [0.04, 0.3, false];
			SM_InfectionEffect ppEffectCommit 3;
		};
	};

	if (_damage != (damage player)) then
	{
		DS_var_Blood = DS_var_Blood - (_damage * 20000);
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

if (((diag_tickTime - SM_isImmuneStart) >= 600) && SM_IsImmune) then
{
	SM_isImmuneStart = diag_tickTime;
	SM_IsImmune = false;
};

true
