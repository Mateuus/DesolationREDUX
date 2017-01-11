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
	if (isNull _obj) then
	{
		_obj = cursorObject;
	};
	if (!(isNull _obj) && (vehicle player == player)) then 
	{
		if (isNil "DS_var_3DLastObject") then { DS_var_3DLastObject = objNull; };
		if (isNil "DS_var_3DLastPosition") then { DS_var_3DLastPosition = getPosATL _obj; };
		if ((_obj == DS_var_3DLastObject) && (DS_var_3DLastPosition isEqualTo (getPosATL _obj))) exitWith { false };
		DS_var_3DLastObject = _obj;
		DS_var_3DLastPosition = getPosATL _obj;

		_dif0 = (boundingBoxReal _obj) select 0;
		_dif1 = (boundingBoxReal _obj) select 1;
		_distance = (_dif0 distance _dif1) + 10;

		if ((_obj distance player) > (_distance / 2)) exitWith { false };

		if ((_obj isKindOf "landVehicle") || (_obj isKindOf "air") || (_obj isKindOf "ship") || (_obj isKindOf "Man") || (_obj isKindOf "House")) exitWith
		{
			_hitpoints = getAllHitPointsDamage _obj;

			if ((count _hitpoints) == 0) exitWith { false };

			_i = -1;
			DS_var_valid3DActions = [];
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
					_txt = _data select 0;
					_icon = _data select 1;
					DS_var_valid3DActions pushBack [_icon,_damage,_pos,_txt,_partName];
				};
				true
			} count (_hitpoints select 1);
		};
		if ((_obj isKindOf "DSR_Crate_Base") || (_obj isKindOf "DSR_objects_base") || (_obj isKindOf "LootWeaponHolder") || (toLower(_obj) find 'water' != -1)) exitWith
		{
			_pos = _obj modelToWorld [0,0,0];
			_data = "action" call DS_fnc_get3DPartName;
			//_txt = _data select 0;
			_icon = _data select 1;
			DS_var_valid3DActions pushBack [_icon,0,_pos,"",""];
		};
	}
	else
	{
		DS_var_valid3DActions = [];
		DS_var_3DLastObject = nil;
		DS_var_3DLastPosition = nil;
	};
	uiSleep 0.1;
	true
};