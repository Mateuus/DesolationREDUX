/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params [_Water,_Ground]

_blackList = ["out"];
if (_Water) then {_blackList = _blackList + "water"};
if (_Ground) then {_blackList = _blackList + "ground"};

while {_randomLocation isEqualTo [0,0]} do 
{
_randomLocation = [0,0];
_randomLocation = [[call BIS_fnc_worldArea],_blackList] call BIS_fnc_randomPos;
};
_randomLocation