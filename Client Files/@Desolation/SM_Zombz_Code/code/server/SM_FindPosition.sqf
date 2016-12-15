/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params[["_center", []],["_minDistance", 0],["_maxDistance", 0],"_radius","_angle","_xOffset","_yOffset","_centerX","_centerY","_newX","_newY","_position"];
_radius = floor ((random (_maxDistance - _minDistance)) + _minDistance);
_angle = floor (random 360);
_xOffset = _radius * (cos _angle);
_yOffset = _radius * (sin _angle);
_centerX = _center select 0;
_centerY = _center select 1;
_newX = _centerX + _xOffset;
_newY = _centerY + _yOffset;
_newX = round(_newX);
_newY = round(_newY);
_position = [_newX, _newY];
_position = _position findEmptyPosition [0, 10, "Man"];

if !(_position isEqualTo []) then
{
	if (_position call SM_IsSafezoneNear) then
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

if !(_position isEqualTo []) then
{
	if (_position call SM_BaseAreaCheck) then
	{
		_position = [];
	};
};

_position
