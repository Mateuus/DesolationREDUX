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

private _menuBackCtrl = 1345;

switch _mode do
{
	//--- Menu navigation code 
	case "mOpen": {
		_display = _params select 0;
		_menuNumber = _params select 1;
		
		_menus = [
			[105,1342,1343], //main
			[], //unused list 
			[301,302,303/*,1344*/], //options
			[1338,1340] //help
		];
		
		if(isNull _display) then {_display = findDisplay 0;};
		
		
		{
			_ctrl = _display displayCtrl _x;
			_ctrl ctrlShow false;
		} forEach (_menus select (uiNameSpace getVariable ["DS_MENU_PREVMENU",0]));
		
		{
			_ctrl = _display displayCtrl _x;
			_ctrl ctrlShow true;
		} forEach (_menus select _menuNumber);
		
		//--- editor button fix
		if(_menuNumber == 1) then {
			_ctrl = _display displayCtrl 105;
			_pos = ctrlPosition _ctrl;
			_y = (_pos select 1) + (_pos select 3);
			_ctrl = _display displayCtrl 142;
			_ctrl ctrlSetPosition _pos;
			_ctrl ctrlCommit 0;
			_ctrl ctrlShow true;
		};
		
		if(_menuNumber != 0) then {
			_ctrl = _display displayCtrl _menuBackCtrl;
			
			_pos = ctrlPosition _ctrl;
			_y = (0.2) + (count(_menus select _menuNumber)*(_pos select 3));
			_pos set [1,_y];
			_ctrl ctrlSetPosition _pos;
			_ctrl ctrlCommit 0;
			_ctrl ctrlShow true;
			
		} else {
			_ctrl = _display displayCtrl _menuBackCtrl;
			_ctrl ctrlShow false;
		};
		uinamespace setVariable ["DS_MENU_PREVMENU",_menuNumber];
	};


	//--- Main menu display is loaded at start of the game and when returning from the profile menu
	case "onLoad":
	{
		_display = _params select 0;
		if(isNull _display) then {_display = findDisplay 0;};
		
		_newsADDED = "<t color='#FF9900'>Added: </t>";
		_newsUPDATED = "<t color='#FFFF00'>Updated: </t>";
		_newsPATCHED = "<t color='#22FF22'>Patched: </t>";
		
		//--- NEWS
		_msg = "";
		_msg = _msg + "<t size='0.9'>";
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
		
		uiNameSpace setVariable ["DS_MENU_PREVMENU",0];
		
		//--- cleanup bugged stuff?
		_ctrl = _display displayCtrl 1001;
		_ctrl ctrlShow false;
		_ctrl = _display displayCtrl 1111;
		_ctrl ctrlShow false;
		_ctrl = _display displayCtrl 1011;
		_ctrl ctrlShow false;
		_ctrl = _display displayCtrl 101;
		_ctrl ctrlShow false;
		_ctrl = _display displayCtrl 150;
		_ctrl ctrlShow false;
		_ctrl = _display displayCtrl 151;
		_ctrl ctrlShow false;
		_ctrl = _display displayCtrl 103;
		_ctrl ctrlShow false;
		
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

		
		//--- Mouse Area Init
		_ctrlMouseArea = _display displayctrl IDC_MAIN_MOUSEAREA;
		_ctrlMouseArea ctrladdeventhandler ["mousebuttondown",{with uinamespace do {["menuClear",[ctrlparent (_this select 0),0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';};}];
		["refresh",[_display],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';
	};
	case "refresh": {
		_display = _params select 0;
	
		["menuClear",[ctrlparent _ctrlGroup,0],""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf';

		//--- Set neutral focus
		_ctrlMouseArea = _display displayctrl IDC_MAIN_MOUSEAREA;
		ctrlsetfocus _ctrlMouseArea;

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
					_prompt = 
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
		private _commitTime = _params param [1,0];
		private _ctrlGroup = _display displayctrl (ctrlidc _ctrlTitle - 10);
		if (isnull _ctrlGroup) then {_ctrlGroup = _display displayctrl (ctrlidc _ctrlTitle - 110)};
		private _ctrlGroupPos = ctrlposition _ctrlGroup;
		_ctrlGroupPos set [3,0];
		_ctrlGroup ctrlsetposition _ctrlGroupPos;
		_ctrlGroup ctrlcommit _commitTime;
	};
	case "menuClear": {
		private _display = _params select 0;
		private _commitTime = _params param [1,0];
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
		diag_log "SPOTLIGHT ENTER CALLED";
	};
	case "spotlightExit": {
		diag_log "SPOTLIGHT EXIT CALLED";
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
		diag_log "PLAY VIDEO CALLED";
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