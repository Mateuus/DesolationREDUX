params["_centerPos","_radius"];
private["_randomDir","_xChange","_yChange","_add"];
_randomDir = random(360);
_xChange = random(_radius) * sin(_randomDir);
_yChange = random(_radius) * cos(_randomDir);
_add = [_xChange,_yChange];
if(count(_centerPos) > 2) then {
	_add pushback 0;
};
_pos = _centerPos vectorAdd _add;

