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

params ["_zombieAgent","_target","_soundLast"];

if ((animationState _zombieAgent) isEqualTo "unconscious") exitWith { _soundLast };

if ((diag_ticktime - _soundLast) >= 3) then
{
	_aggressive = selectRandom getArray (configFile >> "SM_Zombz" >> "SM_AggressiveArray"); 
	[_zombieAgent, _aggressive] remoteExecCall ["Say3D", _zombieAgent nearEntities ["C_man_p_beggar_F",30]];
	_soundLast = diag_ticktime;
};

doStop _zombieAgent;

_zombieAgent setDir (_zombieAgent getDir _target);

_attackAnim = selectRandom ["ZombieAttack1", "ZombieAttack2", "ZombieAttack3"];
[_zombieAgent, _attackAnim] remoteExecCall ["switchMove", _zombieAgent nearEntities ["C_man_p_beggar_F",30]];

_attack = selectRandom getArray (configFile >> "SM_Zombz" >> "SM_AttackArray");
[_zombieAgent, _attack] remoteExecCall ["say3D", _zombieAgent nearEntities ["C_man_p_beggar_F",30]];

_soundLast
