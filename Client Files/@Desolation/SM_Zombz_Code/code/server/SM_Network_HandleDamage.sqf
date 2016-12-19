/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _zombie = objectFromNetId (_this select 0);
if(isNull _zombie) exitWith
{
	"Error fetching zombie to explode head" call SM_Util_Log;
};

if (!(isNil "SM_LastZombie") && (SM_LastZombie isEqualTo _zombie)) exitWith 
{
	"Zombie attempted to be exploded twice" call SM_Util_Log;
};
SM_LastZombie = _zombie;

SM_ClientNetworkMessage = ["ExplodeHead", [(netId _zombie)]];
publicVariable "SM_ClientNetworkMessage";
SM_ClientNetworkMessage = nil;

removeHeadgear _zombie;
removeGoggles _zombie;

_hmd = (hmd _zombie);
_zombie unassignItem _hmd;
_zombie removeItem _hmd;

_zombie setFace "SM_ZombzNoFace";

_headExplodeSound = selectRandom
[
	"SM_Zombz\sounds\explode\1.ogg",
	"SM_Zombz\sounds\explode\2.ogg",
	"SM_Zombz\sounds\explode\3.ogg",
	"SM_Zombz\sounds\explode\4.ogg"
];
playsound3d [_headExplodeSound, _zombie, false, getPosASL _zombie, 10, 1, 30];

true
