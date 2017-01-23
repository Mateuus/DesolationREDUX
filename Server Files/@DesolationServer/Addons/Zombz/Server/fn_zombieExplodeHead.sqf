/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
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