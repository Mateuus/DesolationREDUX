/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

player remoteExec ["DS_fnc_registerNewPlayer",-2];
{
	[_x] call DS_fnc_registerNewPlayer;
} forEach (allPlayers-[player]);