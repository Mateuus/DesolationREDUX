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
	Quick N Dirty
*/
_enabled = (["Enabled","AT"] call BASE_fnc_getCfgValue);
if(toLower(_enabled) != "true") exitWith {};

params["_key"];

_check = player getVariable["ToolsAreOn",false];
if!(_check) then {
	if((_key == (call compile (["Key","AT"] call BASE_fnc_getCfgValue))) && toLower(["Enabled","AT"] call BASE_fnc_getCfgValue) == "true") then {
		diag_log "[DesolationDebug] Quick GodMode and TP";
		player setVariable["ToolsAreOn",true,true];
		player addaction ["God Mode ON", {
				player setVariable ["AdminGod",true,true];
				player allowDamage false;
			}, nil, 0, false, true, "", "!(player getVariable['AdminGod',false])"];
		player addaction ["God Mode OFF", {
				player setVariable ["AdminGod",false,true];
				player allowDamage true;
			}, nil, 0, false, true, "", "(player getVariable['AdminGod',false])"];
			
		player addaction ["Teleport ONCE", {
				onMapSingleClick "vehicle player setPos _pos; onMapSingleClick '';true;";
			}, nil, 0, false, true, "", "!(player getVariable['AdminTP',false])"];
			
		player addaction ["Add Map", {
				player addItem "ItemMap";
				player assignItem "ItemMap";
				player setVariable["HaveMap",true];
			}, nil, 0, false, true, "", "!(player getVariable['HaveMap',false])"];
			
		player addaction ["Add SleepingBag", {
				player addItem "DS_Inv_SleepingBag_Khaki";
			}, nil, 0, false, true, "", ""];
			
		player addaction ["Debug Console", {
				createDialog "RscDisplayDebugPublic";
			}, nil, 0, false, true, "", ""];
		player addaction ["Arsenal", {
				createDialog "RscDisplayArsenal";
			}, nil, 0, false, true, "", ""];
		
	};
};