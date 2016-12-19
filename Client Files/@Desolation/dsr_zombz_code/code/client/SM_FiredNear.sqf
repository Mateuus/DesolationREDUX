/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_zombie","_fired","_zombiePosition","_firedPosition","_zombieVariable"];
_zombie = _this select 0;
_fired = _this select 7;
if !(isPlayer _fired) exitWith {};
_zombiePosition = position _zombie;
_firedPosition = position _fired;
_zombieVariable = _zombie getVariable ["SM_FiredNear", []];
_zombieVariable pushBack _firedPosition;
_zombie setVariable ["SM_FiredNear", _zombieVariable];

true
