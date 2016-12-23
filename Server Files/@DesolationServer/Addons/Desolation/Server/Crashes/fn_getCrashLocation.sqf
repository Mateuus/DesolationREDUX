/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/

_crashtype = _this select 0;
_maxSearchDist = _this select 1;

//_spawnLocations = [];

_variableNameLocations = format ["DS_HeliCrash_%1_locations",_crashtype];
_desiredLocations = missionNamespace getVariable _variableNameLocations;
_foundLocations = [];

while {(count _foundLocations) < 0} {
	_mapPos = [true,false] call DS_fnc_GetRandMapPos;
	_foundLocations = nearestLocations [_mapPos, _desiredLocations, _maxSearchDist];
};

_crashLocation = getPos (selectRandom _foundLocations);
_crashPosition = [[[[_crashLocation], (_maxSearchDist/2)]], ["Out","Water"]] call BIS_fnc_randomPos;


_crashPosition
