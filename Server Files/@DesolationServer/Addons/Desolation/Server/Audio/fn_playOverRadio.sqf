/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params["_parameter","_type"];
private["_send"];

if(_type == "MUSIC") then {
	_send = [];
	{
		if("ItemRadio" in (assignedItems _x)) then {
			_send pushBack _x;
		};
	} forEach allPlayers;

	if !(_send isEqualTo []) then {
		"DropTheLoad" remoteExec["playMusic",_send];
	};
};
if(_type == "OGG") then {
	{
		if("ItemRadio" in (assignedItems _x)) then {
			playSound3D [_parameter, _x];
		};
	} forEach allPlayers;	
};
