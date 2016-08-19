_objecttank = _this select 0;

sleep 0.5;
waituntil {(getpos _objecttank select 2) < 1};

_ThrowArray = ["ryanzombies\sounds\vehicle_throw1.ogg", "ryanzombies\sounds\vehicle_throw2.ogg"];
_Throw = selectRandom _ThrowArray;
playsound3d [format ["%1",_Throw], _objecttank];