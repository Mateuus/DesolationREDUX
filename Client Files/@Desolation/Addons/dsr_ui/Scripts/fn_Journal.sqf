disableserialization;
_data = _this select 0;
_mode = _this select 1;

_display = _data select 0;
_TITLE_CTRL = _display displayCtrl 3;
_DESCRIPTION_CTRL = _display displayCtrl 4;
_PREVIEW_CTRL = _display displayCtrl 5;
_ITEM_LIST_CTRL = _display displayCtrl 6;
_BUILD_BTN = _display displayCtrl 7;
_PREVIOUS_BTN = _display displayCtrl 9;
_NEXT_BTN = _display displayCtrl 10;

_buildings = missionNamespace getVariable ["CFG_BUILDABLES",[]];

//--- if we are attempting to build something
if(_mode == "BUILD") exitWith {

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
{
	_item_name = _x select 0;
	_count = _x select 1;
	
	_displayName = getText(configFile >> "cfgMagazines" >> _item_name >> "displayName");
	_ITEM_LIST_CTRL lbAdd (_displayName + " | x" + str(_count));
} forEach _parts;
if !(call compile _condition) then {
	_BUILD_BTN ctrlEnable false;
	_BUILD_BTN ctrlSetTextColor [1,0.3,0.3,1];
} else {
	_BUILD_BTN ctrlSetTextColor [0.3,1,0.3,1];
};

