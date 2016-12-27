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
params["_location","_cItems"];


_angle = random(360); 

_xChange = 5000*sin(_angle);
_yChange = 5000*cos(_angle);

_spawnPos = [(_location select 0) + _xChange,(_location select 1) + _yChange,500];
_finishPos = [(_location select 0) - _xChange,(_location select 1) - _yChange,500];


_plane = createVehicle ["DSR_C130J_F",_spawnPos,[],0,"FLY"];
createVehicleCrew _plane;
if(getTerrainHeightASL _spawnPos < 0) then {
	_plane setPosASl _spawnPos;
} else {
	_plane setPosAtl _spawnPos;
};
_plane setDir (_angle+180);
_plane flyInHeight 500;
_plane flyInHeightASL  [500,500,500];
_plane forceSpeed 400;
_pilot = driver _plane;
_pilot action ["CollisionLightOn", _plane];
_plane setCollisionLight  true;

_group = createGroup civilian;  
[_pilot] joinSilent _group;
_location set[2,500];

_send = [];
{
	if("ItemRadio" in (assignedItems _x)) then {
		_send pushBack _x;
	};
} forEach allPlayers;
_name = _cItems deleteAt 0;
if !(_send isEqualTo []) then {
	[netID _pilot,("UN Flight #" + str(floor(random(9000)+1000))),["A crate is being dropped!","Grid: " + (mapGridPosition _location),"Type: " + _name]] remoteExec ["DS_fnc_receiveTransmition",_send];
};

_group move _location;
waitUntil{(_plane distance2D _location) < 500};
["DropTheLoad","MUSIC"] call DS_fnc_playOverRadio;
waitUntil{(_plane distance2D _location) < 100}; //--- sometimes the plane misses this distance ???
_pos = getposATL _plane;
_pos = _pos vectorAdd [0,0,-10];

[_pos,_cItems] spawn DS_fnc_SpawnCrate;
_group move _finishPos;
waitUntil{hintSilent str((_plane distance2D _finishPos)); (_plane distance2D _finishPos) < 500};
deleteVehicle _plane;
deleteGroup _group;