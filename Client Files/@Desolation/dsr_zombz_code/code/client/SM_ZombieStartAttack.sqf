/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_zombie","_target","_soundLast","_attackArray","_aggressiveArray","_uncon","_random","_aggressive","_attack"];
_zombie = _this select 0;
_soundLast = _this select 2;
_target = _this select 1;
_attackArray = _this select 3;
_aggressiveArray = _this select 4;

if ((animationState _zombie) isEqualTo "unconscious") exitWith { _soundLast };

if ((diag_ticktime - _soundLast) >= SM_ZombieSoundDelayAggressive) then
{
	_aggressive = selectRandom _aggressiveArray; 
	[_zombie, _aggressive] remoteExecCall ["SM_Say3D", -2];
	_soundLast = diag_ticktime;
};

doStop _zombie;

_zombie setDir (_zombie getDir _target);

_attackAnim = selectRandom 
[
	"ZombieStandingAttack1",
	"ZombieStandingAttack2",
	"ZombieStandingAttack3",
	"ZombieStandingAttack4",
	"ZombieStandingAttack5",
	"ZombieStandingAttack6",
	"ZombieStandingAttack7",
	"ZombieStandingAttack8",
	"ZombieStandingAttack9",
	"ZombieStandingAttack10"
];

[_zombie, _attackAnim] remoteExecCall ["SM_ZombieDoMove", -2];

_attack = selectRandom _attackArray;
[_zombie, _attack] remoteExecCall ["SM_Say3D", -2];

_soundLast
