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

 // on build button click, request a buildable from the server
 
_groupIndex = missionNamespace getVariable["CURRENT_GROUP_INDEX",0];


_buildableData = missionNamespace getVariable ["CFG_BUILDABLE_DATA",[]];
_buildableGroups = missionNamespace getVariable ["CFG_BUILDABLE_GROUPS",[]];

_buildings = _buildableData select _groupIndex;

_index = missionNamespace getVariable ["CURRENT_INDEX",-1];
if(_index < 0) exitWith {systemchat "FUCK STOKES WE FUCKED UP";};

_entry = _buildings select _index;

[_entry,player] remoteExec ["DS_fnc_requestBuild",2];

/*
_parts = _entry select 0;
_name = _entry select 1;
_model = _entry select 2;
_description = _entry select 3;
_preview = _entry select 4;
_condition = _entry select 5;




systemchat "=== BUILDING DATA ===";
systemchat ("Name: " + _name);
systemchat ("Can Build: " + str(call compile _condition));
systemchat ("Parts: " + str(_parts));
*/