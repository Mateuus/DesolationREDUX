/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params ["_zombie", "_unit", ["_offset", 0]];

((((_zombie worldToModel getPos _unit) select 1) - _offset > 0) && if !((_zombie distance _unit) >= (SM_ZombieAgroRange / 2)) then {[_unit, "VIEW", _zombie] checkVisibility [eyePos _unit, eyePos _zombie] > 0} else { true })
