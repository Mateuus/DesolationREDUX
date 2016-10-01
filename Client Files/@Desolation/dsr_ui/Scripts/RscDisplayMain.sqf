#include "\a3\Ui_f\hpp\defineResincl.inc"
#include "\a3\Ui_f\hpp\defineResinclDesign.inc"
#include "\a3\Ui_f\hpp\defineDIKCodes.inc"

#define MENU_TIME	0.2
#define SPOTLIGHT_ZOOM	1.2
#define SPOTLIGHT_TIME	0.1

disableserialization;
private _mode = _this select 0;
private _params = _this select 1;
private _class = _this select 2;

switch _mode do
{
	//--- Main menu display is loaded at start of the game and when returning from the profile menu
	case "onLoad":
	{
		_display = _params select 0;
		
		_newsADDED = "<t color='#FF9900'>Added: </t>";
		_newsUPDATED = "<t color='#FFFF00'>Updated: </t>";
		_newsPATCHED = "<t color='#22FF22'>Patched: </t>";
		
		//--- NEWS
		_msg = "";
		_msg = _msg + "<t size='1.2'>    Changes:</t><br/><br/><t size='0.9'>";
		_msg = _msg + _newsADDED + "New UI<br/>";
		_msg = _msg + _newsADDED + "Default Inventory Selection<br/>";
		_msg = _msg + _newsADDED + "Player Status Effects<br/>";
		_msg = _msg + _newsADDED + "Item Actions<br/>";
		_msg = _msg + _newsADDED + "Loot Spawning<br/>";
		_msg = _msg + _newsADDED + "DSR_bike_F vehicle<br/>";
		_msg = _msg + _newsUPDATED + "Loot spawning config<br/>";
		_msg = _msg + _newsUPDATED + "Spawning system<br/>";
		_msg = _msg + _newsPATCHED + "Loot spawning bug<br/>";
		_msg = _msg + _newsPATCHED + "Vehicle Explosion bug<br/>";
		_msg = _msg + "</t>";
		
		_ctrl = _display displayCtrl 11000;
		_ctrl ctrlSetStructuredText parseText _msg;
		
		
		//--- When pixelGrid command is unavailable, set a replacement variable and redraw. For use with an older EXE.
		if (count supportinfo "n:pixelGrid" == 0) then {
			pixelGrid = 16;
			{
				_ctrl = _x select 0;
				_cfg = _x select 1;
				if !(isnull (_cfg >> "sizeEx")) then {
					_ctrl ctrlsetfontheight (if (isnumber (_cfg >> "sizeEx")) then {getnumber (_cfg >> "sizeEx")} else {call compile gettext (_cfg >> "sizeEx")});
				};
				if (ctrltype _ctrl in [13,16]) then {
					_ctrl ctrlsettooltip toupper gettext (_cfg >> "text")
				};
				_ctrl ctrlsetposition [
					if (isnumber (_cfg >> "x")) then {getnumber (_cfg >> "x")} else {call compile gettext (_cfg >> "x")},
					if (isnumber (_cfg >> "y")) then {getnumber (_cfg >> "y")} else {call compile gettext (_cfg >> "y")},
					if (isnumber (_cfg >> "w")) then {getnumber (_cfg >> "w")} else {call compile gettext (_cfg >> "w")},
					if (isnumber (_cfg >> "h")) then {getnumber (_cfg >> "h")} else {call compile gettext (_cfg >> "h")}
				];
				_ctrl ctrlcommit 0;
			} foreach ([_display,configfile >> "RscDisplayMain"] call bis_fnc_controlConfigs);

			_ctrlWarning = _display ctrlcreate ["RscStructuredText",-1];
			_ctrlWarning ctrlsetposition [0,0.8,1,0.1];
			_ctrlWarning ctrlcommit 0;
			_ctrlWarning ctrlsetstructuredtext parsetext "<t align='center'>MAIN MENU IS NOT DISPLAYED CORRECTLY BECAUSE OLDER EXE IS USED.<br />NAVIGATE BY TOOLTIPS.</t>";
			_ctrlWarning ctrlsettextcolor [1,0.5,0,1];
		};

		//--- Reset grey background when returning from the profile menu (cutscene didn't actually change)
		missionnamespace setvariable ["RscDisplayMain_grey",true];

		//--- Init event handlers
		_display displayaddeventhandler ["childdestroyed",{with uinamespace do {["refresh",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';}}];
		//_display displayaddeventhandler ["keydown",{with uinamespace do {["keyDown",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';}}];
		_display displayaddeventhandler ["mousemoving",{with uinamespace do {["grey",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';}}];
		_display displayaddeventhandler ["mouseholding",{with uinamespace do {["grey",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';}}];
		_display displayaddeventhandler ["childdestroyed","with uinamespace do {['childDestroyed',_this,''] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};"];

		//--- System init
		with uinamespace do {

			//--- Get colors and grids
			true call bis_fnc_displayColorGet;
			false call bis_fnc_guiGridToProfile;

			//--- Apply colors to main menu
			[configfile >> _class,_display] call bis_fnc_displayColorSet;
		};

		//--- Menu Bar Init
		{
			_ctrlGroup = _display displayctrl (_x select 0);
			_ctrlGroupPos = ctrlposition _ctrlGroup;
			_ctrlTitle = _display displayctrl (_x select 1);
			_ctrlTitleIcon = _display displayctrl (_x select 2);
			{
				_handler = _x;
				{
					_x ctrladdeventhandler [
						_handler,
						format ["with uinamespace do {['menuEnter',[_this select 0,%1],''] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};",_ctrlGroupPos select 3]
					];
				} foreach [_ctrlTitle,_ctrlTitleIcon];
			} foreach ["mouseenter","setfocus"];

			_ctrlGroupPos set [3,0];
			_ctrlGroup ctrlsetposition _ctrlGroupPos;
			_ctrlGroup ctrlcommit 0;
		} foreach [
			[IDC_MAIN_GROUP_SINGLEPLAYER,	IDC_MAIN_TITLE_SINGLEPLAYER,	IDC_MAIN_TITLEICON_SINGLEPLAYER],
			[IDC_MAIN_GROUP_MULTIPLAYER,	IDC_MAIN_TITLE_MULTIPLAYER,	IDC_MAIN_TITLEICON_MULTIPLAYER],
			[IDC_MAIN_GROUP_TUTORIALS,	IDC_MAIN_TITLE_TUTORIALS,	IDC_MAIN_TITLEICON_TUTORIALS],
			[IDC_MAIN_GROUP_OPTIONS,	IDC_MAIN_TITLE_OPTIONS,		IDC_MAIN_TITLEICON_OPTIONS],
			[IDC_MAIN_GROUP_SESSION,	IDC_MAIN_TITLE_SESSION,		IDC_MAIN_TITLEICON_SESSION]
		];

		//--- Spotlight Init
		{
			_ctrlGroup = _display displayctrl _x;
			_ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
			_ctrlButton = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_BUTTON;
			{
				_ctrlButton ctrladdeventhandler [
					_x,
					{with uinamespace do {['spotlightEnter',_this,''] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}
				];
			} foreach ["mouseenter","setfocus"];
			{
				_ctrlButton ctrladdeventhandler [
					_x,
					{with uinamespace do {['spotlightExit',_this,''] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}
				];
			} foreach ["mouseexit","killfocus"];
		} foreach [
			IDC_MAIN_SPOTLIGHT_GROUP_1,
			IDC_MAIN_SPOTLIGHT_GROUP_2,
			IDC_MAIN_SPOTLIGHT_GROUP_3
		];

		//--- Init hardcoded spotlights
		_ctrlGroupSpotlight2 = _display displayctrl IDC_MAIN_SPOTLIGHT_GROUP_2;
		_ctrlButtonSpotlight2 = _ctrlGroupSpotlight2 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_BUTTON;
		_ctrlButtonSpotlight2 ctrladdeventhandler [
			"buttonclick",
			{
				_display = ctrlparent (_this select 0);
				ctrlactivate (_display displayctrl IDC_MAIN_QUICKPLAY);
			}
		];

		_ctrlGroupSpotlight3 = _display displayctrl IDC_MAIN_SPOTLIGHT_GROUP_3;
		_ctrlButtonSpotlight3 = _ctrlGroupSpotlight3 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_BUTTON;
		_ctrlButtonSpotlight3 ctrladdeventhandler [
			"buttonclick",
			{
				_display = ctrlparent (_this select 0);
				ctrlactivate (_display displayctrl IDC_SP_EDITOR);
			}
		];
		_ctrlPictureSpotlight3 = _ctrlGroupSpotlight3 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
		_ctrlVideoSpotlight3 = _ctrlGroupSpotlight3 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_VIDEO;
		uinamespace setvariable ["RscDisplayMain_spotlightDefault",[[],[],[ctrltext _ctrlPictureSpotlight3,ctrltext _ctrlVideoSpotlight3]]];

		//--- Info panels
		{
			_ctrlInfo = _display displayctrl _x;
			{
				_ctrlButton = _ctrlInfo controlsGroupCtrl _x;
				_ctrlButton ctrladdeventhandler ["mouseEnter",{with uinamespace do {["infoEnter",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
				_ctrlButton ctrladdeventhandler ["setfocus",{with uinamespace do {["infoEnter",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
				_ctrlButton ctrladdeventhandler ["mouseExit",{with uinamespace do {["infoExit",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
				_ctrlButton ctrladdeventhandler ["killfocus",{with uinamespace do {["infoExit",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
				_ctrlButton ctrladdeventhandler ["buttonclick",{with uinamespace do {["infoClick",_this,""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
			} foreach [
				IDC_MAIN_INFO_BUTTON,
				IDC_MAIN_INFO_BUTTON_DEV
			];
		} foreach [
			IDC_MAIN_INFO_MODS,
			IDC_MAIN_INFO_DLCS,
			IDC_MAIN_INFO_DLCSOWNED,
			IDC_MAIN_INFO_NEWS,
			IDC_MAIN_INFO_VERSION
		];

		//--- Version
		_ctrlInfoVersion = _display displayctrl IDC_MAIN_INFO_VERSION;
		_ctrlInfoVersionButton = _ctrlInfoVersion controlsGroupCtrl IDC_MAIN_INFO_BUTTON;
		_ctrlInfoVersionButtonDev = _ctrlInfoVersion controlsGroupCtrl IDC_MAIN_INFO_BUTTON_DEV;

		//--- Dev version
		_versionBuild = productVersion select 4;
		_version = productVersion select 2;
		if (_versionBuild == "Development") then {
			_version = productVersion select 3;
			_versionName = if (cheatsenabled) then {localize "STR_A3_RscDisplayMain_Version_Internal"} else {localize "STR_A3_RSCDISPLAY_LOADING_DEV"};

			_ctrlVersion = _display displayCtrl IDC_MAIN_VERSION;
			_ctrlVersion ctrlshow false;

			_ctrlVersionDev = _display displayCtrl IDC_MAIN_VERSION_DEV;
			_ctrlVersionDev ctrlshow true;
			_ctrlVersionDev ctrlsettext format ["%1\n%2",_versionName,ctrltext _ctrlVersion];

			_ctrlInfoVersionButton ctrlshow false;
			_ctrlInfoVersionButtonDev ctrlshow true;
		};

		//--- New version
		if (_version != profilenamespace getvariable ["RscDisplayMain_version" + _versionBuild,0]) then {
			_ctrlInfoVersionNotification = _ctrlInfoVersion controlsGroupCtrl IDC_MAIN_INFO_NOTIFICATION;
			_ctrlInfoVersionNotification ctrlshow true;
			_ctrlInfoVersionButton ctrlsettooltip format ["%1\n%2",localize "STR_A3_RscDisplayMain_InfoVersion_New_tooltip",localize "STR_A3_RscDisplayMain_InfoVersion_tooltip"];
			_ctrlInfoVersionButtonDev ctrlsettooltip format ["%1\n%2",localize "STR_A3_RscDisplayMain_InfoVersion_New_tooltip",localize "STR_A3_RscDisplayMain_InfoVersion_tooltip"];
		};

		//--- Mouse Area Init
		_ctrlMouseArea = _display displayctrl IDC_MAIN_MOUSEAREA;
		//_ctrlMouseArea ctrladdeventhandler ["mouseenter",{with uinamespace do {["menuClear",[ctrlparent (_this select 0),0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
		_ctrlMouseArea ctrladdeventhandler ["mousebuttondown",{with uinamespace do {["menuClear",[ctrlparent (_this select 0),0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
		["refresh",[_display],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';

		//--- Close menu when focus is set to any non-menu element apart from the mouse area
		_menuControlIDCs = [
			IDC_MAIN_GROUP_SINGLEPLAYER,
			IDC_MAIN_GROUP_MULTIPLAYER,
			IDC_MAIN_GROUP_TUTORIALS,
			IDC_MAIN_GROUP_OPTIONS,
			IDC_MAIN_GROUP_SESSION,

			IDC_MAIN_TITLE_SINGLEPLAYER,
			IDC_MAIN_TITLE_MULTIPLAYER,
			IDC_MAIN_TITLE_TUTORIALS,
			IDC_MAIN_TITLE_OPTIONS,
			IDC_MAIN_TITLE_SESSION,

			IDC_MAIN_TITLEICON_SINGLEPLAYER,
			IDC_MAIN_TITLEICON_MULTIPLAYER,
			IDC_MAIN_TITLEICON_TUTORIALS,
			IDC_MAIN_TITLEICON_OPTIONS,
			IDC_MAIN_TITLEICON_SESSION
		];
		{
			if (!(ctrlidc _x in _menuControlIDCs) && !(ctrlidc (ctrlParentControlsGroup _x) in _menuControlIDCs)) then {
				_x ctrladdeventhandler ["mouseenter",{with uinamespace do {["menuClear",[ctrlparent (_this select 0),0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
				_x ctrladdeventhandler ["setfocus",{with uinamespace do {["menuClear",[ctrlparent (_this select 0),0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
			};
		} foreach (allcontrols _display - [_ctrlMouseArea]);
	};
	case "refresh": {
		_display = _params select 0;
		_ctrlGroupSpotlight1 = _display displayctrl IDC_MAIN_SPOTLIGHT_GROUP_1;
		_ctrlGroupSpotlight2 = _display displayctrl IDC_MAIN_SPOTLIGHT_GROUP_2;
		_ctrlGroupSpotlight3 = _display displayctrl IDC_MAIN_SPOTLIGHT_GROUP_3;

		//--- When pixelGrid command is unavailable, set pixelGrid variable for use by sub-displays
		if (count supportinfo "n:pixelGrid" == 0) then {
			missionnamespace setvariable ["pixelGrid",16];
		};

		//--- When screen is too small, show menu bar icons, not texts
		_ctrlTitleOptions = _Display displayctrl IDC_MAIN_TITLE_OPTIONS;
		_ctrlTitleSession = _Display displayctrl IDC_MAIN_TITLE_SESSION;
		_showMenuIcons = (((ctrlposition _ctrlTitleOptions select 0) + (ctrlposition _ctrlTitleOptions select 2)) > (ctrlposition _ctrlTitleSession select 0));
		{(_display displayctrl _x) ctrlshow !_showMenuIcons;} foreach [IDC_MAIN_TITLE_SINGLEPLAYER,IDC_MAIN_TITLE_MULTIPLAYER,IDC_MAIN_TITLE_TUTORIALS,IDC_MAIN_TITLE_OPTIONS];
		{(_display displayctrl _x) ctrlshow _showMenuIcons;} foreach [IDC_MAIN_TITLEICON_SINGLEPLAYER,IDC_MAIN_TITLEICON_MULTIPLAYER,IDC_MAIN_TITLEICON_TUTORIALS,IDC_MAIN_TITLEICON_OPTIONS];

		//--- Init custom spotlight
		_spotlights = [];
		{
			_condition = gettext (_x >> "condition");
			if (_condition == "") then {_condifiton = "true";};
			[_condition,_spotlights,_x] call {
				private ["_display","_ctrlGroupSpotlight1","_ctrlGroupSpotlight2","_ctrlGroupSpotlight3","_condition","_spotlights","_x"];
				if ([] call compile (_this select 0)) then {(_this select 1) append [_this select 2];};
			};
		} foreach ("isclass _x" configclasses (configfile >> "RscDisplayMain" >> "Spotlight"));
		_cfgSpotlight = selectrandom _spotlights;//("isclass _x" configclasses (configfile >> "RscDisplayMain" >> "Spotlight"));
		if !(isnil "_cfgSpotlight") then {
			_ctrlPictureSpotlight1 = _ctrlGroupSpotlight1 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
			_ctrlPictureSpotlight1 ctrlsettext gettext (_cfgSpotlight >> "picture");

			_ctrlVideoSpotlight1 = _ctrlGroupSpotlight1 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_VIDEO;
			_ctrlVideoSpotlight1 ctrlsettext gettext (_cfgSpotlight >> "video");

			_ctrlActionSpotlight1 = _ctrlGroupSpotlight1 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_ACTION;
			_ctrlActionSpotlight1 ctrlsettext toupper gettext (_cfgSpotlight >> "actionText");

			_ctrlButtonSpotlight1 = _ctrlGroupSpotlight1 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_BUTTON;
			_ctrlButtonSpotlight1 ctrlseteventhandler ["buttonclick",gettext (_cfgSpotlight >> "action")];

			_spotlightText = gettext (_cfgSpotlight >> "text");
			if (getnumber (_cfgSpotlight >> "textIsQuote") > 0) then {_spotlightText = format ["""%1""",_spotlightText];};
			_ctrlTextSpotlight1 = _ctrlGroupSpotlight1 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_TEXT;
			_ctrlTextSpotlight1 ctrlsettext _spotlightText;
		};

		//--- Init editor spotlight
		_ctrlPictureSpotlight3 = _ctrlGroupSpotlight3 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
		_ctrlVideoSpotlight3 = _ctrlGroupSpotlight3 controlsGroupCtrl IDC_MAIN_SPOTLIGHT_VIDEO;
		if (worldname == "") then {
			//--- Empty world
			_spotlightDefault = uinamespace getvariable ["RscDisplayMain_spotlightDefault",[]];
			_spotlightDefault3 = _spotlightDefault param [2,[]];
			_ctrlPictureSpotlight3 ctrlsettext (_spotlightDefault3 param [0,""]);
			_ctrlVideoSpotlight3 ctrlsettext (_spotlightDefault3 param [1,""]);
		} else {
			//--- Show world picture and video
			_worldPicture = gettext (configfile >> "cfgworlds" >> worldname >> "pictureMap");
			_ctrlPictureSpotlight3 ctrlsettext _worldPicture;
			_previewVideo = gettext (configfile >> "cfgworlds" >> worldname >> "previewVideo");
			_ctrlVideoSpotlight3 ctrlsettext _previewVideo;
		};

		//--- Adjust spotlight texts
		{
			_ctrlGroup = _display displayctrl _x;
			_ctrlText = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_TEXT;
			_ctrlText ctrlsetstructuredtext parsetext toupper ctrltext _ctrlText;
			_ctrlTextHeight = ctrltextheight _ctrlText;
			_ctrlTextPos = ctrlposition _ctrlText;
			_ctrlTextPos set [1,((ctrlposition _ctrlGroup select 3) - _ctrlTextHeight) / 2];
			_ctrlTextPos set [3,_ctrlTextHeight];
			_ctrlText ctrlsetposition _ctrlTextPos;
			_ctrlText ctrlcommit 0;
			_ctrlText ctrlenable false;
		} foreach [IDC_MAIN_SPOTLIGHT_GROUP_1,IDC_MAIN_SPOTLIGHT_GROUP_2,IDC_MAIN_SPOTLIGHT_GROUP_3];

		//--- Clear spotlight
		{
			//["playVideo",[_x,false],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
			ctrlDelete (_x controlsGroupCtrl 222);
		} foreach [_ctrlGroupSpotlight1,_ctrlGroupSpotlight2,_ctrlGroupSpotlight3];

		//--- Clear menus
		["menuClear",[ctrlparent _ctrlGroup,0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';

		//--- Set neutral focus
		_ctrlMouseArea = _display displayctrl IDC_MAIN_MOUSEAREA;
		ctrlsetfocus _ctrlMouseArea;

		//--- Show Welcome screen
		_showWelcomeScreen = [_display] call (uinamespace getvariable "bis_fnc_showWelcomeScreen");

		//--- Show Apex controls preset prompt
		if (!_showWelcomeScreen && {!(profilenamespace getvariable ["RscDisplayKeysPresetMsgBox_shown",false])}) then {

			//--- Check if Apex keys are assigned
			_match = true;
			{
				_force = false;
				_a = getarray _x;
				{
					if (_x isequaltype "") then {
						_a set [_foreachindex,call compile _x]; //--- Convert macro to single number 
					} else {
						if (_x isequaltype []) then {_force = true;}; //--- Force match when format is different (i.e., it's a key combination)
					};
				} foreach _a;
				_b = actionkeys (configname _x);
				_match = _match && (_a isequalto _b || _force);
			} foreach configproperties [configfile >> "CfgDefaultKeysPresets" >> "Arma3Apex" >> "Mappings","isarray _x",false];

			//--- Show prompt when they aren't
			if !(_match) then {_display ctrlcreate ["RscMsgBoxKeysPreset",-1];};

			//--- Prevent this int he future (if user is already using Apex controls, he shouldn't get the message after changing it)
			profilenamespace setvariable ["RscDisplayKeysPresetMsgBox_shown",true];
			saveprofilenamespace;
		};
	};
	case "keyDown": {
		_display = _params select 0;
		_key = _params select 1;
		switch _key do {
			case DIK_ESCAPE: {
				[_display] spawn {
					_display = _this select 0;
					_prompt = ["Hm?",nil,true,true,_display,true] call (uinamespace getvariable "bis_fnc_guiMessage");
					if (_prompt) then {
						ctrlactivate (_display displayctrl IDC_MAIN_QUIT);
					};
				};
			};
		};
		false
	};
	case "menuEnter": {
		private _ctrlTitle = _params select 0;
		private _display = ctrlparent _ctrlTitle;
		["menuClear",[_display],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
		private _ctrlGroup = _display displayctrl (ctrlidc _ctrlTitle - 10);
		if (isnull _ctrlGroup) then {_ctrlGroup = _display displayctrl (ctrlidc _ctrlTitle - 110)};
		private _ctrlGroupPos = ctrlposition _ctrlGroup;
		//--- Move buttons group next to the title button (not for the session group, is too far right)
		if (ctrlidc _ctrlTitle != IDC_MAIN_TITLE_SESSION) then {
			_ctrlGroupPos set [0,ctrlposition _ctrlTitle select 0];
			_ctrlGroup ctrlsetposition _ctrlGroupPos;
			_ctrlGroup ctrlcommit 0;
		};
		_ctrlGroupPos set [3,_params select 1];
		_ctrlGroup ctrlsetposition _ctrlGroupPos;
		_ctrlGroup ctrlcommit MENU_TIME;
	};
	case "menuExit": {
		private _ctrlTitle = _params select 0;
		private _commitTime = _params param [1,MENU_TIME];
		private _ctrlGroup = _display displayctrl (ctrlidc _ctrlTitle - 10);
		if (isnull _ctrlGroup) then {_ctrlGroup = _display displayctrl (ctrlidc _ctrlTitle - 110)};
		private _ctrlGroupPos = ctrlposition _ctrlGroup;
		_ctrlGroupPos set [3,0];
		_ctrlGroup ctrlsetposition _ctrlGroupPos;
		_ctrlGroup ctrlcommit _commitTime;
	};
	case "menuClear": {
		private _display = _params select 0;
		private _commitTime = _params param [1,MENU_TIME];
		{
			["menuExit",[_display displayctrl _x,_commitTime],''] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
		} foreach [
			IDC_MAIN_TITLE_SINGLEPLAYER,
			IDC_MAIN_TITLE_MULTIPLAYER,
			IDC_MAIN_TITLE_TUTORIALS,
			IDC_MAIN_TITLE_OPTIONS,
			IDC_MAIN_TITLE_SESSION
		];
	};
	case "spotlightEnter": {
		private _ctrlButton = _params select 0;
		private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
		private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
		private _ctrlHover = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_HOVER;
		private _ctrlGroupPos = ctrlposition _ctrlGroup;
		//_ctrlPicture ctrlsetposition [
		//	-(_ctrlGroupPos select 2) * (SPOTLIGHT_ZOOM - 1) / 2,
		//	-(_ctrlGroupPos select 3) * (SPOTLIGHT_ZOOM - 1) / 2,
		//	(_ctrlGroupPos select 2) * SPOTLIGHT_ZOOM,
		//	(_ctrlGroupPos select 3) * SPOTLIGHT_ZOOM
		//];
		//_ctrlPicture ctrlcommit SPOTLIGHT_TIME;
		_ctrlHover ctrlsetfade 0;
		_ctrlHover ctrlcommit SPOTLIGHT_TIME;

		//["menuClear",[ctrlparent _ctrlGroup],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
		["playVideo",[ctrlParentControlsGroup _ctrlPicture,true],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
	};
	case "spotlightExit": {
		private _ctrlButton = _params select 0;
		private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
		private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
		private _ctrlHover = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_HOVER;
		private _ctrlGroupPos = ctrlposition _ctrlGroup;
		_ctrlPicture ctrlsetposition [
			0,
			0,
			(_ctrlGroupPos select 2),
			(_ctrlGroupPos select 3)
		];
		_ctrlPicture ctrlsettextcolor [1,1,1,1];
		_ctrlPicture ctrlcommit SPOTLIGHT_TIME;
		_ctrlHover ctrlsetfade 1;
		_ctrlHover ctrlcommit SPOTLIGHT_TIME;
		["playVideo",[_ctrlGroup,false],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
	};
	case "infoEnter": {
		_ctrlButton = _params select 0;
		_ctrlInfo = ctrlParentControlsGroup _ctrlButton;
		_ctrlIconBackground = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_BACKGROUND_ICON;
		_ctrlIcon = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_ICON;
		_ctrlIconBackground ctrlsettextcolor [1,1,1,1];
		_ctrlIcon ctrlsettextcolor [0,0,0,1];
		if (ctrlclassname _ctrlInfo in ["InfoNews","InfoVersion"]) then {
			_ctrlBackground = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_BACKGROUND;
			_ctrlBackground ctrlsettextcolor [1,1,1,1];
		};
		//["menuClear",[ctrlparent _ctrlGroup],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
	};
	case "infoExit": {
		_ctrlButton = _params select 0;
		_ctrlInfo = ctrlParentControlsGroup _ctrlButton;
		_ctrlIconBackground = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_BACKGROUND_ICON;
		_ctrlIcon = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_ICON;
		_ctrlIconBackground ctrlsettextcolor [INFO_BACKGROUND_COLOR];
		_ctrlIcon ctrlsettextcolor [INFO_ICON_COLOR];
		if (ctrlclassname _ctrlInfo in ["InfoNews","InfoVersion"]) then {
			_ctrlBackground = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_BACKGROUND;
			_ctrlBackground ctrlsettextcolor [INFO_BACKGROUND_COLOR];
		};
	};
	case "infoClick": {
		_ctrlButton = _params select 0;
		_ctrlInfo = ctrlParentControlsGroup _ctrlButton;
		_ctrlInfoVersionNotification = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_NOTIFICATION;
		_ctrlInfoVersionNotification ctrlshow false;

		switch (ctrlclassname _ctrlInfo) do {
			case "InfoVersion": {
				//--- Mark the current version as "read"
				_versionBuild = productVersion select 4;
				_version = productVersion select 2;
				if (_versionBuild == "Development") then {_version = productVersion select 3;};
				profilenamespace setvariable ["RscDisplayMain_version" + _versionBuild,_version];
				saveprofilenamespace;

				_ctrlInfoVersionButton = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_BUTTON;
				_ctrlInfoVersionButtonDev = _ctrlInfo controlsGroupCtrl IDC_MAIN_INFO_BUTTON_DEV;
				_ctrlInfoVersionButton ctrlsettooltip localize "STR_A3_RscDisplayMain_InfoVersion_tooltip";
				_ctrlInfoVersionButtonDev ctrlsettooltip localize "STR_A3_RscDisplayMain_InfoVersion_tooltip";
			};
		};
		false
	};
	case "playVideo": {
		private _ctrlGroup = _params select 0;
		private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
		private _ctrlVideoSource = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_VIDEO;
		private _file = ctrltext _ctrlVideoSource;

		if (_file == "") exitwith {};

		//--- Delete the previous video (do it in spawn, would crash the game when called from videoStopped handler)
		[_ctrlGroup controlsGroupCtrl 222] spawn {
			disableserialization;
			ctrlDelete (_this select 0);
		};
		if (_params select 1) then {
			_ctrlVideo = (ctrlparent _ctrlGroup) ctrlcreate ["RscVideo",222,_ctrlGroup];
			_ctrlVideo ctrlsettext _file;
			_ctrlVideo ctrlsetposition ctrlposition _ctrlVideoSource;
			_ctrlVideo ctrlcommit 0;
			_ctrlVideo ctrlenable false;
			_ctrlPicture ctrlsettextcolor [0,0,0,1];
			_ctrlPicture ctrlsetposition ctrlposition _ctrlVideoSource;
			_ctrlPicture ctrlcommit 0;

			_ctrlVideo ctrladdeventhandler [
				"videostopped",
				{with uinamespace do {["playVideo",[ctrlParentControlsGroup (_this select 0),true],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}
			];
		};
	};
	case "grey": {
		if (missionnamespace getvariable ["RscDisplayMain_grey",true]) then {
			_display = _params select 0;

			//--- Initial refresh (can't be in onLoad, it's too soon for example for stats evaluation)
			if !(uinamespace getvariable ["BIS_initGame",false]) then {["refresh",[_display],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};

			//--- Switch start-up loading screen to the default one (see RscDisplayLoading script)
			uinamespace setvariable ["BIS_initGame",true];

			"MainMenuDummy" cutRsc ["RscDisplayMainMenuBackground","plain"]; //--- Register empty layer, because layer 0 is the same as no layer (bug?)
			"MainMenu" cutRsc ["RscDisplayMainMenuBackground","plain"];
			(_display displayctrl IDC_MAIN_BACKGROUND_PICTURE) ctrlshow false;
		};
		missionnamespace setvariable ["RscDisplayMain_grey",false];
	};

	//--- Launch Arsenal based on RscDisplayDLCContentBrowser request
	case "childDestroyed":
	{
		_exit = _params select 2;

		// switch 7 to IDC_EXIT_TO_MAIN, also test there is test request (global variable?) so it doesn't start Arsenal for every exitToMain request.
		if (
			_exit == 7
			&&
			(
				!isnil {uiNameSpace getvariable "BIS_fnc_arsenal_defaultClass"}
				||
				!isnil {uiNameSpace getvariable "BIS_fnc_garage_defaultClass"}
			)
		) then {
			playMission['','\A3\Missions_F_Bootcamp\Scenarios\Arsenal.VR'];
		};
	};
};