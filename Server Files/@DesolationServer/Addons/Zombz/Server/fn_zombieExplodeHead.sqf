/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

_zombieAgent = objectFromNetId (_this select 0);
if(isNull _zombieAgent) exitWith
{
	"Error fetching zombie to explode head" call SM_Util_Log;
};

[_this select 0] remoteExecCall ["SM_fnc_headExplodeEffect", -2];

removeHeadgear _zombieAgent;
removeGoggles _zombieAgent;

_hmd = (hmd _zombieAgent);
_zombieAgent unassignItem _hmd;
_zombieAgent removeItem _hmd;

_zombieAgent setFace "SM_ZombzNoFace";

_headExplodeSound = selectRandom
[
	"SM_Zombz\sounds\explode\1.ogg",
	"SM_Zombz\sounds\explode\2.ogg",
	"SM_Zombz\sounds\explode\3.ogg",
	"SM_Zombz\sounds\explode\4.ogg"
];
playsound3d [_headExplodeSound, _zombieAgent, false, getPosASL _zombieAgent, 10, 1, 30];

true