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

params [["_victim", objNull],["_selection", ""],["_damage", 0],["_damager", objNull],"_hmd","_headExplode"];

if((_selection == "head") && _damage >= 1) then
{
	if !((face _victim) == "SM_ZombzNoFace") then 
	{
		_victim setFace "SM_ZombzNoFace";
		[netId _victim] remoteExecCall ["SM_fnc_zombieExplodeHead", 2];
	};
};

_damage
