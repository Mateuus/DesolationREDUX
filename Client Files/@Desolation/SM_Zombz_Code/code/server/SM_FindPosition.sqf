/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Heh, it's alot more optimized...
params [["_center", []],["_minDistance", 0],["_maxDistance", 0],"_radius","_angle","_position"];
_radius = floor ((random (_maxDistance - _minDistance)) + _minDistance);
_angle = floor (random 360);
_position = [round ((_center select 0) + (_radius * (cos _angle))), round((_center select 1) + (_radius * (sin _angle)))];

if !(_position isEqualTo []) then
{
	if (_position call SM_IsSafezoneNear) then
	{
		_position = [];
	};
};

if !(_position isEqualTo []) then
{
	if (_position call SM_BaseAreaCheck) then
	{
		_position = [];
	};
};

if !(_position isEqualTo []) then
{
	if (surfaceIsWater _position) then 
	{
		_position = [];
	};
};

_position
