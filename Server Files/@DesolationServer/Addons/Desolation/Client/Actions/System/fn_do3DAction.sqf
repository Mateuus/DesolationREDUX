if (isNil "DS_var_3DActionData") exitWith {};

DS_var_3DActionData params ["_partName","_thisDamage","_position"];
_actionConfig = (DS_var_3DActionData call DS_fnc_get3DPartName) >> "Actions"; //the actions class of the part
_actionClasses = "true" configClasses _actionConfig;

_validActions = [];
{
	_condition = getText(_x >> "condition");
	_code = getText(_x >> "code");

	if (call compile _condition) then 
	{
		_validActions pushBack _code;
	};
} count _actionClasses;

if ((count _validActions) < 1) exitWith
{
	DS_var_valid3DActionsCode = [];
};

if !(_validActions isEqualTo DS_var_valid3DActionsCode) then
{
	DS_var_valid3DActionsCode = _validActions;
};

true