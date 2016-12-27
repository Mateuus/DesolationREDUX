/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

params [["_pos",[]],["_minDist",0],["_maxDist",0],["_objDist",0],["_waterMode",0],["_maxGradient",0],["_shoreMode",false],"_newPos", "_posX", "_posY","_attempts","_newX", "_newY", "_testPos"];

_newPos = [];
_posX = _pos select 0;
_posY = _pos select 1;

_attempts = 0;

while {_attempts < 1000} do
{
	_newX = _posX + (_maxDist - (random (_maxDist * 2)));
	_newY = _posY + (_maxDist - (random (_maxDist * 2)));
	_testPos = [_newX, _newY];

	if ((_pos distance _testPos) >= _minDist) then
	{
		if !((_testPos isFlatEmpty [_objDist, 0, _maxGradient, _objDist max 5, _waterMode, _shoreMode, objNull]) isEqualTo []) then 
		{
			_newPos = _testPos;
			_attempts = 1000;
		};
	};

	_attempts = _attempts + 1;
};

_newPos