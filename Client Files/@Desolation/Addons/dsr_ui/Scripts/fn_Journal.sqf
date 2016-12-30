disableserialization;
_data = _this select 0;
_mode = _this select 1;

_display = _data select 0;


_groupIndex = uiNamespace getVariable["CURRENT_GROUP_INDEX",0];


_buildableData = missionNamespace getVariable ["CFG_BUILDABLE_DATA",[]];
_buildableGroups = missionNamespace getVariable ["CFG_BUILDABLE_GROUPS",[]];

_buildings = _buildableData select _groupIndex;


//--- index controls
if(_mode == "LOADINDEX") exitWith {
	_ctrl = _display displayCtrl 5;
	_ctrl ctrlSetStructuredText parseText "<t font='LauHoWi_a' size='0.8'>
	
		woo fucking lad, this is the description<br/><br/>
		ben can customize this because i dont want 2
	</t>";

	_list = _display displayCtrl 6;
	{
		_class = _x select 0;
		_name = _x select 1;
		_condition = _x select 2;
		_preview = _x select 3;
		
		_index = _list lbAdd _name;
		if(call compile _condition) then {
			_list lbSetColor[_index,[0.3,1,0.3,1]];
		} else {
			_list lbSetColor[_index,[1,0.3,0.3,1]];
		};
		_list lbSetPicture [_index,_preview];
	} forEach _buildableGroups;
	
	
	
};
if(_mode == "GOTO") exitWith {
	_display = findDisplay 4002;
	_list = _display displayCtrl 6;
	_index = lbCurSel _list;
	if(_index != -1) then {
		_groupData = _buildableGroups select _index;
		_condition = _groupData select 2;
		if(call compile _condition) then {
			CURRENT_GROUP_INDEX = _index;
			closeDialog 0;
			createDialog "DS_Journal";
		};
	};
};

//--- journal controls
_TITLE_CTRL = _display displayCtrl 3;
_DESCRIPTION_CTRL = _display displayCtrl 4;
_PREVIEW_CTRL = _display displayCtrl 5;
_ITEM_LIST_CTRL = _display displayCtrl 6;
_BUILD_BTN = _display displayCtrl 7;
_PREVIOUS_BTN = _display displayCtrl 9;
_NEXT_BTN = _display displayCtrl 10;


if(_mode == "BUILD") exitWith {

};
if(_mode == "INDEX") exitWith {
	closeDialog 0;
	createDialog "DS_Journal_Index";
};

//--- determine current index
if(_mode == "LOAD") then {
	CURRENT_INDEX = 0;
};
if(_mode == "NEXT") then {
	CURRENT_INDEX = (CURRENT_INDEX + 1) min (count(_buildings)-1);
};
if(_mode == "PREV") then {
	CURRENT_INDEX = (CURRENT_INDEX - 1) max 0;
};

//--- load data for that buildable

_entry = _buildings select CURRENT_INDEX;
_parts = _entry select 0;
_name = _entry select 1;
_condition = _entry select 2;
_description = _entry select 3;
_model = _entry select 4;
_preview = _entry select 5;


_TITLE_CTRL ctrlSetText _name;
_DESCRIPTION_CTRL ctrlSetStructuredText parseText ("<t font='LauHoWi_a' size='0.8'>" + _description + "</t>");
_PREVIEW_CTRL ctrlSetText _preview;
lbClear _ITEM_LIST_CTRL;
{
	_item_name = _x select 0;
	_count = _x select 1;
	
	_displayName = getText(configFile >> "CfgMagazines" >> _item_name >> "displayName");
	_ITEM_LIST_CTRL lbAdd (_displayName + " | x" + str(_count));
} forEach _parts;
if !(call compile _condition) then {
	_BUILD_BTN ctrlSetTextColor [1,0.3,0.3,1];
} else {
	_BUILD_BTN ctrlSetTextColor [0.3,1,0.3,1];
};

