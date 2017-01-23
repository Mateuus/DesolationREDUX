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

params["_display"];

_lastTime = missionNamespace getVariable ["DS_var_escapeTimer",diag_tickTime];
if(diag_tickTime >= _lastTime) then {
	missionNamespace setVariable ["DS_var_escapeTimer",diag_tickTime+60];
	call ds_fnc_saveData;
};

if(isNil {_display}) exitWith {systemchat "ESCAPE DISPLAY NIL";};
if(isNull _display) exitWith {systemchat "ESCAPE DISPLAY NULL";};

_ctrl = _display displayCtrl 103;
_ctrl ctrlEnable false;
_ctrl = _display displayCtrl 1002;
_ctrl ctrlEnable false;
_ctrl = _display displayCtrl 1010;
_ctrl ctrlEnable false;