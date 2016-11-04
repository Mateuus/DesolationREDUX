waitUntil{!isnil "BASE_VAR_ACTIONS"};
_groups = call BASE_VAR_ACTIONS;
while{true} do {
	{
		_INDEX_NUM = _forEachIndex;
		_text = _x select 0;
		_condition = _x select 1;
		_actions = _x select 2;
		if([player,vehicle player,cursorObject] call _condition) then {
			_uActions = missionNamespace getVariable ["ACTIONS_" + _INDEX_NUM,[]];
			if(_uActions isEqualTo []) then {
				{
					_aText  = _x select 0;
					_aCondition = _x select 1;
					_aAction = _x select 2;
					_aDistance = _x select 3;
					_uActions pushback (player addAction [parseText _aText,_aAction,[],0,false,true,"",_aCondition,_aDistance]);
				} forEach _actions;
				missionNamespace setVariable ["ACTIONS_" + _INDEX_NUM,_uActions];
			};
		} else {
			_uActions = missionNamespace getVariable ["ACTIONS_" + _INDEX_NUM,[]];
			if !(_uActions isEqualTo []) then {
				{
					player removeAction _x;
				} forEach _uActions;
				missionNamespace setVariable ["ACTIONS_" + _INDEX_NUM,[]];
			};
		};
	} forEach _groups;
	uiSleep 0.01;
};