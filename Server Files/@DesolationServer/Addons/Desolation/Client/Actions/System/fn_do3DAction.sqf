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

if (isNil "DS_var_valid3DActionsCode") then { DS_var_valid3DActionsCode = []; };
if (isNil "DS_var_valid3DActionCodeSelected") then { DS_var_valid3DActionCodeSelected = ""; };
_obj = cursorTarget;
if (isNull _obj) then
{
	_obj = cursorObject;
};
if (isNull _obj) exitWith { false };
if (DS_var_valid3DActionCodeSelected == "") then
{
	if (isNil "DS_var_3DActionData") exitWith {};

	DS_var_3DActionData params ["_partName","_thisDamage"];
	_actionConfig = ((toLower _partName) call DS_fnc_get3DPartName) >> "Actions";
	_actionConfig = (configProperties [_actionConfig, "true", true]);

	_validActions = [];
	for "_i" from 0 to (count _actionConfig) - 1 do
	{
		_config = _actionConfig select _i;
		_condition = getText(_config >> "condition");
		_code = getText(_config >> "code");
		_text = getText(_config >> "text");

		_condition = str([_thisDamage, _obj]) + " call { params['_thisDamage','_thisObject']; (" + _condition + ")};";
		if (call compile _condition) then 
		{
			_validActions pushBack [_code,_text];
		};
	};
	if ((count _validActions) < 1) exitWith
	{
		DS_var_valid3DActionsCode = [];
	};

	if !(_validActions isEqualTo DS_var_valid3DActionsCode) then
	{
		DS_var_valid3DActionsCode = _validActions;
	};
}
else
{
	call compile DS_var_valid3DActionCodeSelected;
	DS_var_valid3DActionCodeSelected = nil;
};

true
