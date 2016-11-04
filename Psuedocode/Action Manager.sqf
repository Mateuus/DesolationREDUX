/* CONFIG */

/*
class CfgPluginActions {
	class RepairCars {
		class Actions {
			class RepairEngine {
				distance = 5;
				text = "Repair Engine";
				action = "";
				condition = "_cursor getHitPointDamage 'HitEngine' > 0";
			};
			class RepairBody {
				distance = 5;
				text = "Repair Body";
				action = "";
				condition = "_cursor getHitPointDamage 'HitBody' > 0";
			};
			class RepairFueltank {
				distance = 5;
				text = "Repair Fuel Tank";
				action = "";
				condition = "_cursor getHitPointDamage 'HitFuel' > 0";
			};
			class RepairGlass {
				distance = 5;
				text = "Repair Glass";
				action = "";
				condition = "(_cursor getHitPointDamage 'HitRGlass' > 0) || (_cursor getHitPointDamage 'HitLGlass' > 0) || (_cursor getHitPointDamage 'HitGlass1' > 0)";
			};
			class RepairWheels {
				distance = 5;
				text = "Repair Glass";
				action = "";
				condition = "(_cursor getHitPointDamage 'HitLFWheel' > 0) || (_cursor getHitPointDamage 'HitRFWheel' > 0) || (_cursor getHitPointDamage 'HitLBWheel' > 0) || (_cursor getHitPointDamage 'HitRBWheel' > 0)";
			};
		};
		condition = "_cursor isKindOf 'LandVehicle'";
		text = "Repair Vehicle";
	};
};
*/

//Server
BASE_fnc_initActions = {
	_config = configFile >> "CfgPluginActions";
	
	_USER_ACTIONS = [];
	for "_i" from 0 to count(_config)-1 do {
		
		_ACTION_GROUP = [];
	
		_entry = _config select _i;
		_actions = _entry >> "Actions";
		_menuName = getText(_entry >> "Text");
		_conditional = "params['_player','_vehiclePlayer','_cursor'];" + getText(_entry >> "Condition");
		
		_ACTION_GROUP pushBack _menuName;
		_ACTION_GROUP pushBack _conditional;
		
		_ACTION_GROUP_ACTIONS = [];
		for "_j" from 0 to count(_actions)-1 do {
			_action = _actions select _i;
			
			_text = getText(_action >> "text");
			_condition = "[player,vehicle player,cursorObject] call {params['_player','_vehiclePlayer','_cursor'];" + getText(_action >> "condition") + "};";
			_action = getText(_action >> "action");
			_distance = getNumber(_action >> "distance");
			
			_ACTION_GROUP_ACTIONS pushBack _text;
			_ACTION_GROUP_ACTIONS pushBack _condition;
			_ACTION_GROUP_ACTIONS pushBack _action;
			_ACTION_GROUP_ACTIONS pushBack _distance;
		};
		_ACTION_GROUP pushBack _ACTION_GROUP_ACTIONS; 
		_USER_ACTIONS pushBack _ACTION_GROUP;
	};
	BASE_VAR_ACTIONS = compileFinal str(_USER_ACTIONS);
	publicVariable "BASE_VAR_ACTIONS";
};

//Clients
BASE_fnc_startActionManager = {
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
};