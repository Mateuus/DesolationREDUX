_objectcar = _this select 0;

sleep 0.5;
if ((random 15 < 1) && (alive _objectcar)) then {[_objectcar] execVM "\ryanzombies\caralarm.sqf"};
waituntil {(getpos _objectcar select 2) < 1};

_ThrowArray = ["ryanzombies\sounds\vehicle_throw1.ogg", "ryanzombies\sounds\vehicle_throw2.ogg"];
_Throw = selectRandom _ThrowArray;
playsound3d [format ["%1",_Throw], _objectcar];