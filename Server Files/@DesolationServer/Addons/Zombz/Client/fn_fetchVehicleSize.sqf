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

_target = _this;
_dif0 = (boundingBoxReal _target) select 0;
_dif1 = (boundingBoxReal _target) select 1;
_distance = ((_dif0 distance2D _dif1) / 2);
if (_target isKindOf "Man") then
{
	_distance = (_dif0 distance2D _dif1);
};
if (_target isKindOf "Air") then
{
	_distance = ((_dif0 distance2D _dif1) / 4);
};

_distance
