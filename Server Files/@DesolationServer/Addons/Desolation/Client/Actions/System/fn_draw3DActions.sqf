if !(DS_var_3DActionsEnabled) exitWith { false };
if (isNil "DS_var_valid3DActions") then
{
	DS_var_valid3DActions = [];
};

if ((count DS_var_valid3DActions) == 0) exitWith { false };

_obj = cursorObject;
if (isNull _obj) exitWith { false };
_dif0 = (boundingBoxReal _obj) select 0;
_dif1 = (boundingBoxReal _obj) select 1;
_distance = (_dif0 distance _dif1) + 3;
_visPos = ASLToATL(AGLToASL positionCameraToWorld [0,0,3]);
_camPos = ASLToATL(AGLToASL positionCameraToWorld [0,0,0]);
_alreadyHasValidAction = false;

{
	_icon = _x select 0;
	_damage = _x select 1;
	_pos = _x select 2;
	_txt = _x select 3;
	_partName = _x select 4;
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