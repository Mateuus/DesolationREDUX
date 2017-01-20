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

if(isNull OM_var_lifted) exitWith {false};
if(local OM_var_lifted) then {[OM_var_lifted] remoteExecCall ["OM_fnc_serverDrop",2];};
if !(isNil "OM_var_EachFrameEH") then 
{
	removeMissionEventHandler ["EachFrame",OM_var_EachFrameEH];
	OM_var_EachFrameEH = nil;
};
OM_var_lifted removeAllEventHandlers "EpeContact";
OM_var_collisionForce = 0;
OM_var_lifted = objNull;

true;