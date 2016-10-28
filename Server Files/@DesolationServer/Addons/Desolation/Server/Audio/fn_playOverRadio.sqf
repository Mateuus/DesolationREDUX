/*
	Desolation Redux loot manager
	by: @_Lystic

	Description: Handles loot spawning for the server & parses the config values
*/
params["_parameter","_type"];

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
