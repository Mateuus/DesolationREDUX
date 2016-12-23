/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params ["_Water","_Ground"];

_blackList = ["out"];
if (_Water) then {_blackList pushBack "water"};
if (_Ground) then {_blackList pushBack "ground"};
_randomLocation = [0,0];
while {_randomLocation isEqualTo [0,0]} do 
{
	_randomLocation = [[call BIS_fnc_worldArea],_blackList] call BIS_fnc_randomPos;
};
_randomLocation;