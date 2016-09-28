/*
	Stops the player from bleeding (on bandage)

*/

{
	[player,_x] remoteExec ["DS_fnc_removeBleedSource",-2];
} forEach (player getVariable "DS_var_BleedSources");
// TODO: Toggle bleeding off
