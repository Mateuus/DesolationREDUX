_object = cursorObject;
_player = player;

[_player,_object] remoteExec ["DS_fnc_dbDeleteObject", 2];





/*
_classname = TypeOf _object;
if(isNull _classname)exitWith{hint "You Cannot Pack This Item"};
//player animation to pick it up, use attach to get the player centered on object to pack it :)
sleep 5;
deleteVehicle _object;
_player addItem _classname;*/