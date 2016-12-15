/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params[["_zombie", objNull],["_target", objNull],"_dir","_pos","_distance","_random"];

_dir = _zombie getRelDir _target;
_pos = getPosATL _target;
_distance = _zombie distance _target;
_random = random 10;
_distance = random (_distance * SM_MultiplierDistanceFromTarget);

if !(isNil "_dir") then
{
	_pos = [(_pos select 0) + (_distance * (sin _dir)), (_pos select 1) + (_distance * (cos _dir)), _pos select 2];
};

_pos
