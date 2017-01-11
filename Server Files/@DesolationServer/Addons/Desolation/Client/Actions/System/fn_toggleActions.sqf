if (isNil "DS_var_3DActionsEnabled") then
{
	DS_var_3DActionsEnabled = false;
};

if !(DS_var_3DActionsEnabled) then
{
	DS_var_3DActionsEnabled = true;
	DS_var_3DDrawEvent = addMissionEventHandler ["Draw3D",{ [] call DS_fnc_draw3DActions; }];
	[] spawn
	{
		while {DS_var_3DActionsEnabled} do
		{
			_obj = cursorObject;
			if !(isNull _obj) then 
			{
				if (isNil "DS_var_3DLastObject") then { DS_var_3DLastObject = objNull; };
				if (isNil "DS_var_3DLastPosition") then { DS_var_3DLastPosition = getPosATL _obj; };
				if ((_obj == DS_var_3DLastObject) && (DS_var_3DLastPosition isEqualTo (getPosATL _obj))) exitWith { false };
				DS_var_3DLastObject = _obj;
				DS_var_3DLastPosition = getPosATL _obj;
				_dif0 = (boundingBoxReal _obj) select 0;
				_dif1 = (boundingBoxReal _obj) select 1;
				_distance = (_dif0 distance _dif1) + 3;

				if ((_obj distance player) > (_distance / 2)) exitWith { false };

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
			}
			else
			{
				DS_var_valid3DActions = [];
			};
			uiSleep 1;
			true
		};
	};
}
else
{
	DS_var_3DActionsEnabled = false;
	if (isNil "DS_var_3DDrawEvent") exitWith {};
	removeMissionEventHandler ["Draw3D", DS_var_3DDrawEvent];
	DS_var_3DDrawEvent = nil;
	DS_var_3DPartName = nil;
};

true