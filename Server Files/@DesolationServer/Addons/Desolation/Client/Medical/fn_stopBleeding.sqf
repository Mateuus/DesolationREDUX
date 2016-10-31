/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/


{
	[player,_x] remoteExec ["DS_fnc_removeBleedSource",-2];
} forEach (player getVariable "DS_var_BleedSources");
// TODO: Toggle bleeding off
