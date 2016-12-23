/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_zombie","_pos","_distance","_dir"];
_zombie = _this;
_pos = getPosATL _zombie;
_distance = 10;
_dir = random 360;
_distance = random (_distance * 30);

_pos = [(_pos select 0) + _distance * sin _dir, (_pos select 1) + _distance * cos _dir, _pos select 2];

_pos
