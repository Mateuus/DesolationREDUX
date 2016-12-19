/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_dif0","_dif1","_distance"];
_dif0 = (boundingBoxReal _this) select 0;
_dif1 = (boundingBoxReal _this) select 1;
_distance = ((_dif0 distance2D _dif1) / 2);
if (_this isKindOf "Man") then
{
	_distance = (_dif0 distance2D _dif1);
};
if (_this isKindOf "Air") then
{
	_distance = ((_dif0 distance2D _dif1) / 4);
};

_distance
