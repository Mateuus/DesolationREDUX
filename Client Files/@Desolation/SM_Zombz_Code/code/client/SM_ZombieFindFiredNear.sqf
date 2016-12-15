/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_pos","_zombie","_firedNear","_distanceEnemy"];

_zombie = _this;

_firedNear = _zombie getVariable ["SM_FiredNear",[]];

if (_firedNear isEqualTo []) exitWith
{
	[]
};

_distance = 1000;
_pos = [];

{
	_distanceEnemy = _zombie distance _x;
	if (_distanceEnemy <= _distance) then
	{
		_distance = _distanceEnemy;
		_pos = _x;
	};
} forEach _firedNear;

_zombie setVariable ["SM_FiredNear",nil];

_pos