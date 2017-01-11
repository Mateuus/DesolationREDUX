/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

if !(DS_var_3DActionsEnabled) exitWith { false };
if (isNil "DS_var_valid3DActions") then
{
	DS_var_valid3DActions = [];
};

if (((count DS_var_valid3DActions) == 0) || (vehicle player != player)) exitWith { false };

_obj = cursorTarget;
if (isNull _obj) then
{
	_obj = cursorObject;
};
if (isNull _obj) exitWith { false };
_dif0 = (boundingBoxReal _obj) select 0;
_dif1 = (boundingBoxReal _obj) select 1;
_distance = (_dif0 distance _dif1) + 4;
_visPos = ASLToATL(AGLToASL positionCameraToWorld [0,0,3]);
_camPos = ASLToATL(AGLToASL positionCameraToWorld [0,0,0]);
_alreadyHasValidAction = false;

{
	_x params ["_icon","_damage","_pos","_txt","_partName"];
	_valid = false;
	for "_j" from 1 to _distance do 
	{
		_vChange = (_camPos vectorFromTo _visPos) vectorMultiply (((_camPos distance _visPos) / 20)*_j);
		_checkPos = _camPos vectorAdd _vChange;
		if((_checkPos distance _pos) <= 0.1) exitWith 
		{
			_valid = true;
		};
	};

	if (_valid) then
	{
		if !(_alreadyHasValidAction) then
		{
			drawIcon3D 
			[
				_icon,
				[_damage, 1 - _damage, 0, 1],
				_pos,
				2*1.5,
				2*1.5,
				0,
				_txt,
				2,
				0.05,
				"LauHoWi_a"
			];
			_alreadyHasValidAction = true;
			DS_var_3DPartName = _partName;
		}
		else
		{
			drawIcon3D 
			[
				_icon,
				[_damage, 1 - _damage, 0, 1],
				_pos,
				1*1.5,
				1*1.5,
				0,
				_txt,
				2,
				0.05,
				"LauHoWi_a"
			];
		};
	}
	else
	{
		drawIcon3D 
		[
			_icon,
			[_damage, 1 - _damage, 0, 1],
			_pos,
			1*1.5,
			1*1.5,
			0,
			_txt,
			2,
			0.05,
			"LauHoWi_a"
		];
	};
} count DS_var_valid3DActions;

if !(_alreadyHasValidAction) then
{
	DS_var_3DPartName = nil;
};

true