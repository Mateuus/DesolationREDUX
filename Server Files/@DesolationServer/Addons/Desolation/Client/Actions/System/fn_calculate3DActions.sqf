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

if !(canSuspend) exitWith { _this spawn DS_fnc_calculate3DActions; };

while {DS_var_3DActionsEnabled} do
{
	_obj = cursorTarget;
	_validActions = [];
	if (isNull _obj) then
	{
		_obj = cursorObject;
	};
	if (!(isNull _obj) && (vehicle player == player)) then 
	{
		_dif0 = (boundingBoxReal _obj) select 0;
		_dif1 = (boundingBoxReal _obj) select 1;
		_distance = (_dif0 distance _dif1) + 4;

		if ((_obj distance player) > (_distance / 2)) exitWith 
		{
			DS_var_3DPartName = nil;
			DS_var_3DActionData = nil;
			DS_var_valid3DActionsCode = nil;
			DS_var_valid3DActionCodeSelected = nil;
			DS_var_valid3DActions = [];

			false
		};

		if ((_obj isKindOf "landVehicle") || (_obj isKindOf "air") || (_obj isKindOf "ship") || (_obj isKindOf "Man") || (_obj isKindOf "House")) exitWith
		{
			_hitpoints = getAllHitPointsDamage _obj;

			if ((count _hitpoints) == 0) exitWith { false };

			_i = -1;
			_validActions = [];
			{
				_i = _i + 1;
				_pos = _obj    selectionPosition _x;
				_partName = (_hitpoints select 0) select _i;
				if (_pos isEqualTo [0,0,0]) then 
				{
					_partName = (selectionNames _obj) select _i;
					_pos = _obj selectionPosition [_partName,"HitPoints"];
					_partName = "Hit" + _partName;
				};
				if !(_pos isEqualTo [0,0,0]) then
				{
					if (_partName == "") exitWith { false };
					if (((toLower _partName) find "reserve") != -1) exitWith { false };
					_pos = _obj modelToWorldVisual _pos;
					_damage = (_hitpoints select 2) select _i;
					_data = (tolower _partName) call DS_fnc_get3DPartName;
					if (isNull _data) exitWith {};
					_txt = getText (_data >> "Name");
					_icon = getText (_data >> "Icon");
					_validActions pushBack [_icon,_damage,_pos,_txt,_partName];
				};
				true
			} count (_hitpoints select 1);
		};
		if ((_obj isKindOf "DSR_Crate_Base") || (_obj isKindOf "DSR_objects_base") || (_obj isKindOf "LootWeaponHolder") || (toLower(str _obj) find 'water' != -1)) exitWith
		{
			_pos = _obj modelToWorld [0,0,0];
			_data = "action" call DS_fnc_get3DPartName;
			//_txt = getText (_data >> "Name");
			_icon = getText (_data >> "Icon");
			_validActions pushBack [_icon,0,_pos,"","Action"];
		};
		DS_var_valid3DActions = [];
	}
	else
	{
		DS_var_valid3DActions = [];
	};

	if (!((count _validActions) < 1) && !(_validActions isEqualTo DS_var_valid3DActions)) then
	{
		DS_var_valid3DActions = _validActions;
	};
	uiSleep 0.1;
	true
};