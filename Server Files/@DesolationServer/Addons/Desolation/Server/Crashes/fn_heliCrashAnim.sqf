_heli = _this select 0;
_heliwreckModel = _this select 1;
_smokesize = _this select 2;
_smokeModelPos = _this select 3;
_wreckSmoke = _this select 4;


_heli  setHit ["tail_rotor_hit", 1];
sleep 3;
systemchat "Play heli crash soundfile";
_heli  setHit ["main_rotor_hit", 1];
_heli  setHit ["engine_hit", 1];
[_heli,_smokesize,_smokeModelPos,false] spawn DS_fnc_crashSmoke;
waitUntil {isTouchingGround _heli};
_heli setdamage 1;
_wreckPos = getpos _heli;
_wreckDir = getDir _heli;
_wreckUp = VectorUp _heli;

//remove origional helicrew from vehicle
{
	deleteVehicle _x
} forEach crew _heli;

//TODO Spawn new helicrew with custom weapons. (use set velocity random to fling crew hidden members, unhide after impact!)

sleep 0.5;
deletevehicle _heli;
_wreck = _heliWreckModel createvehicle _wreckPos;
_wreck setDir _wreckDir;
_wreck setVectorUp _wreckUp;

if (_wreckSmoke > 0) then {
[_wreck,7,[0,0,0],true] call DS_fnc_crashSmoke;
};
_wreckPos