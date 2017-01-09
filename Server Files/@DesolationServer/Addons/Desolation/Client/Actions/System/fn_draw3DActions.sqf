_visPos = ASLtoATL(AGLToASL positionCameraToWorld [0,0,3]);
_obj = cursorTarget;
if (isNull _obj) exitWith { false };

_dif0 = (boundingBoxReal _obj) select 0;
_dif1 = (boundingBoxReal _obj) select 1;
_distance = (_dif0 distance _dif1) + 3;

if ((_obj distance player) > (_distance / 2)) exitWith { false };

_hitpoints = getAllHitPointsDamage _obj;

if ((count _hitpoints) == 0) exitWith { false };

_i = -1;
_validActions = [];
{
	_i = _i + 1;
	_pos = _obj    selectionPosition _x;
	_partName = (_hitpoints select 0) select _i;
	if (_pos isEqualTo [0,0,0]) then 
	{
		_partName = (selectionNames _obj) select _i;
		_pos = _obj selectionPosition [_partName,"HitPoints"];
		_partName = "Hit" + _partName;
	};
	if !(_pos isEqualTo [0,0,0]) then
	{
		if (_partName == "") exitWith { false };
		if (((toLower _partName) find "reserve") != -1) exitWith { false };
		_pos = _obj modelToWorldVisual _pos;
		_damage = (_hitpoints select 2) select _i;
		_data = (tolower _partName) call DS_fnc_get3DPartName;
		_txt = _data select 0;
		_icon = _data select 1;
		_angle = getDir player;
		_validActions pushBack [_icon,_damage,_pos,_txt,_partName];
	};
	true
} count (_hitpoints select 1);

_camPos = ASLtoATL(AGLToASL positionCameraToWorld [0,0,0]);
_uVectorTo = _camPos vectorFromTo _visPos;
_dist = _camPos distance _visPos;
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
		_vChange = _uVectorTo vectorMultiply ((_dist / 20)*_j);
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
} count _validActions;

if !(_alreadyHasValidAction) then
{
	DS_var_3DPartName = nil;
};