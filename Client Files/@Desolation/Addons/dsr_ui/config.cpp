class CfgPatches
{
	class dsr_ui
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F","A3_Ui_F","A3_Functions_F","A3_UiFonts_F","A3_Map_Stratis","A3_Map_Altis","A3_Map_VR","A3_Map_Tanoabuka","A3_Map_Stratis_Scenes", "A3_Map_VR_Scenes", "A3_Map_Altis_Scenes","A3_Map_Tanoa_Scenes_F"};
		fileName = "dsr_ui.pbo";
		requiredVersion = 0.1;
		author[]= {"Desolation Redux Dev Team"};
	};
};

class CfgFunctions {
	class Intro {
		tag = "opx";
		class functions {
			file = "\dsr_ui\Scripts\Intro";
			class init {};
			class mainMenuFadeIn {};
			class characterCustomization {};
			class forceCharacterCustomization {};
			class displayQuote {};
			class characterCustomization_changeItem {};
			class charToMain {};
			class mainMenu {};
			class startMainMenu {};
			class cinematic {};
		};
	};
};

//--- todo move this shit somewhere else
class CfgMissions {
	class Cutscenes {
		class DSIntro {
			directory = "dsr_ui\Intro\dsintro.tanoa";
		};
	};
};
class CfgWorlds {
	class CAWorld;
	
	class Altis : CAWorld {
		cutscenes[] = {"DSIntro"};
	};
	class Stratis : CAWorld {
		cutscenes[] = {"DSIntro"};
	};
	class Tanoa : CAWorld {
		cutscenes[] = {"DSIntro"};
	};
	class VR : CAWorld {
		cutscenes[] = {"DSIntro"};
	};
	initWorld = "Tanoa";
	demoWorld = "Tanoa";
};
//---
class CfgDifficultyPresets {
	class Recruit {
		weaponCrosshair = 0;
		reducedDamage = 0;
		visionAid  = 0;
		groupIndicators = 0;
		friendlyTags = 0;
		deathMessages = 0;
	};
	class Regular {
		weaponCrosshair = 0;
		reducedDamage = 0;
		visionAid  = 0;
		groupIndicators = 0;
		friendlyTags = 0;
		deathMessages = 0;
	};
	class Veteran {
		weaponCrosshair = 0;
		visionAid  = 0;
		reducedDamage = 0;
		groupIndicators = 0;
		friendlyTags = 0;
		deathMessages = 0;
	};
	class DesoHardcore {
		displayName = "Desolation Redux: Hardcore Mode";
		levelAI = "AILevelHigh";
		description = "Desolation `haaaard` coore!";
		optionDescription = "The hardest difficulty there is.";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		class Options {
			reducedDamage = 0;
			groupIndicators = 0; 
			friendlyTags = 0;
			enemyTags = 0;
			detectedMines = 0;
			commands = 0;
			waypoints = 0;
			weaponInfo = 0;
			stanceIndicator = 0;
			staminaBar = 0;
			weaponCrosshair = 0;
			visionAid = 0;
			thirdPersonView = 0;
			cameraShake = 1;
			scoreTable = 0;
			deathMessages = 0;
			vonID = 1;
			mapContent = 0;
			autoReport = 0;
			multipleSaves = 0;
		};
	};
};
//--- end todo

class CfgMusic {
	class MAD {
		duration = 198;
	};
	class Defcon {
		duration = 193;
	};
	class SkyNet {
		duration = 234;
	};
	class Wasteland {
		duration = 195;
	};
	class track1
	{
		name = "";
		sound[] = {"\dsr_ui\Sounds\track1.ogg", 1, 1.0};
	};
	class track2
	{
		name = "";
		sound[] = {"\dsr_ui\Sounds\track2.ogg", 1, 1.0};
	};
	class track2_redefined
	{
		name = "";
		sound[] = {"\dsr_ui\Sounds\track2_redefined.ogg", 1, 1.0};
	};
};

class CfgFontFamilies {
    // LauHoWi-a font by Dr. Wolfgang Wiebecke and Laurens Hornemann
    class LauHoWi_a {
            fonts[] = {
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a6",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a7",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a8",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a9",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a10",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a11",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a12",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a13",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a14",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a15",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a16",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a17",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a18",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a19",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a20",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a21",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a22",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a23",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a24",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a25",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a26",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a27",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a28",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a29",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a30",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a31",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a34",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a35",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a37",
                "\dsr_ui\Fonts\LauHoWi-a\LauHoWi-a46"
            };
            spaceWidth = 0.7;
            spacing = 0.13;
    };
    class LauHoWi_a_bold {
            fonts[] = {
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold6",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold7",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold8",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold9",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold10",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold11",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold12",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold13",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold14",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold15",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold16",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold17",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold18",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold19",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold20",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold21",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold22",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold23",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold24",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold25",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold26",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold27",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold28",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold29",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold30",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold31",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold34",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold35",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold37",
                "\dsr_ui\Fonts\LauHoWi-a-bold\LauHoWi-a-bold46"
            };
            spaceWidth = 0.7;
            spacing = 0.13;
    };
    class LauHoWi_a_italic {
            fonts[] = {
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic6",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic7",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic8",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic9",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic10",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic11",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic12",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic13",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic14",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic15",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic16",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic17",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic18",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic19",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic20",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic21",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic22",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic23",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic24",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic25",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic26",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic27",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic28",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic29",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic30",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic31",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic34",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic35",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic37",
                "\dsr_ui\Fonts\LauHoWi-a-italic\LauHoWi-a-italic46"
            };
            spaceWidth = 0.7;
            spacing = 0.13;
    };
};


class RscPicture;
class RscButton;
class RscText;
class IGUIBack;
class RscActiveText;
class RscCombo;
class RscListBox;
class RscProgress;
class RscPictureKeepAspect;
class RscDisplayInventory_DLCTemplate;
class RscStructuredText;
class RscTitle;
class RscButtonMenuOK;
class RscControlsGroupNoHScrollbars;
class RscHTML;
class RscButtonMenu;
class RscStandardDisplay;
class RscVignette;
class RscControlsGroupNoScrollbars;
class RscFrame;
class CA_Title;
class RscDebugConsole;
class RscTrafficLight;
class RscFeedback;
class RscMessageBox;
class ShortcutPos;
class RscButtonMenuCancel;
class RscButtonMenuSteam;
class RscActivePicture;
class RscButtonMenuMain;

class RscTitles {
	class transition_type1
	{
		idd = -1;
		movingEnable = 1;
		enableSimulation = 1;
		fadeout=2;
		fadein=2;
		duration = 1;

		class controlsBackground {};

		class controls
		{
			class blackbackground: RscText
			{
				idc = -1;
				x = 0 * safezoneW + safezoneX;
				y = 0 * safezoneH + safezoneY;
				w = 1 * safezoneW;
				h = 1 * safezoneH;
				colorBackground[] = {0,0,0,2};
			};
			class blackbackground2: blackbackground { };
			class blackbackground3: blackbackground { };
		};
	};
	class quoteTemplate
	{
		idd = -1;
		movingEnable = 1;
		enableSimulation = 1;
		fadeout=1;
		fadein=1;
		duration = 4.5;
		onLoad = "uiNamespace setVariable ['quoteTemplate', _this select 0]";

		class controlsBackground {};

		class controls
		{
			class textQuote: RscStructuredText
			{
				idc = 0;
				x = 0.0256094 * safezoneW + safezoneX;
				y = 0.401035 * safezoneH + safezoneY;
				w = 0.953938 * safezoneW;
				h = 0.175938 * safezoneH;
			};
			class textAuthor: RscStructuredText
			{
				idc = 1;
				x = 0.309213 * safezoneW + safezoneX;
				y = 0.576973 * safezoneH + safezoneY;
				w = 0.381575 * safezoneW;
				h = 0.0989651 * safezoneH;
			};
		};
	};
	class transition_type3
	{
		idd = -1;
		movingEnable = 1;
		enableSimulation = 1;
		fadeout=2;
		fadein=0;
		duration = 7;

		class controlsBackground {};

		class controls
		{
			class blackbackground: RscText
			{
				idc = -1;
				x = 0 * safezoneW + safezoneX;
				y = 0 * safezoneH + safezoneY;
				w = 1 * safezoneW;
				h = 1 * safezoneH;
				colorBackground[] = {0,0,0,2};
			};
			class blackbackground2: blackbackground { };
			class blackbackground3: blackbackground { };
		};
	};
	class transition_type2
	{
		idd = -1;
		movingEnable = 1;
		enableSimulation = 1;
		fadeout=2;
		fadein=0;
		duration = 0.3;

		class controlsBackground {};

		class controls
		{
			class blackbackground: RscText
			{
				idc = -1;
				x = 0 * safezoneW + safezoneX;
				y = 0 * safezoneH + safezoneY;
				w = 1 * safezoneW;
				h = 1 * safezoneH;
				colorBackground[] = {0,0,0,2};
			};
			class blackbackground2: blackbackground { };
			class blackbackground3: blackbackground { };
		};
	};
};


class DS_Journal {
	idd = 4001;
	name = "DS_Journal";
	movingEnable = 1;
	enableSimulation = 1;
	
	onLoad = "";
	onUnload = "";
	class controlsBackground {
		class BackgroundPic: RscPicture
		{
			idc = -1;
			text = "\dsr_ui\Assets\journal.paa";
			x = "safeZoneX + (safeZoneW/2) - (pixelW*400)";
			y = "safeZoneY + (safeZoneH/2) - (pixelH*400)";
			w = "800 * pixelW";
			h = "800 * pixelH";
		};
	};
	class Controls {
		
	};
};

class DS_spawnSelection {
	idd = 4000;
	name = "DS_spawnSelection";
	movingEnable = 1;
	enableSimulation = 1;
	
	onLoad = "_this call compile preprocessfilelinenumbers 'dsr_ui\Scripts\fn_spawnSelection.sqf';";
	onUnload = "_this call compile preprocessfilelinenumbers 'dsr_ui\Scripts\fn_spawnSelectionUnload.sqf';";
	
	class controlsBackground {
		class PictureBackground: RscPicture
		{
			idc = 1999;
			text = "\dsr_ui\Assets\background.paa";
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
		};
		class IGUIBack_2200: IGUIBack
		{
			idc = 2200;
			x = 0.0375;
			y = 0.315;
			w = 0.925;
			h = 0.35;
		};
		class RscText_1002: RscText
		{
			idc = 1002;
			text = "Select a spawn point";
			x = 0.0375;
			y = 0.275;
			w = 0.925;
			h = 0.04;
			colorBackground[] = {1,0,0,0.5};
		};
	};
	class Controls {
		class RscPicture_1200: RscPicture
		{
			idc = 1200;
			text = "dsr_ui\Data\north.paa";
			x = 0.0875;
			y = 0.365;
			w = 0.2416;
			h = 0.25;
		};
		class RscPicture_1201: RscPicture
		{
			idc = 1201;
			text = "dsr_ui\Data\east.paa";
			x = 0.3791;
			y = 0.365;
			w = 0.2417;
			h = 0.25;
		};
		class RscPicture_1202: RscPicture
		{
			idc = 1202;
			text = "dsr_ui\Data\south.paa";
			x = 0.6708;
			y = 0.365;
			w = 0.2416;
			h = 0.25;
		};
		//--- left
		class RscButton_1600: RscButton
		{
			idc = 1600;
			text = "North";
			x = 0.075;
			y = 0.665;
			w = 0.1625;
			h = 0.04;
			colorBackground[] = {1,0,0,0.5};
		};
		//--- middle
		class RscButton_1602: RscButton
		{
			idc = 1602;
			text = "East";
			x = 0.3375;
			y = 0.665;
			w = 0.325;
			h = 0.06;
			colorBackground[] = {1,0,0,0.5};
		};
		//--- right
		class RscButton_1601: RscButton
		{
			idc = 1601;
			text = "South";
			x = 0.7625;
			y = 0.665;
			w = 0.1625;
			h = 0.04;
			colorBackground[] = {1,0,0,0.5};
		};
	};
};

class RscDisplayMPInterrupt: RscStandardDisplay {
	scriptName = "RscDisplayMPInterrupt";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscDisplayMPInterrupt"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay'); _code = missionNamespace getVariable ['ds_fnc_onEscape',{}]; [_this select 0] call _code;";
	onUnload = "[""onUnload"",_this,""RscDisplayMPInterrupt"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	movingEnable = 0;
	enableSimulation = 1;
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class TitleBackground: RscText
		{
			idc = 1050;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "14.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class MissionNameBackground: RscText
		{
			idc = -1;
			x = "SafezoneX + (1 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "SafezoneW - (2 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
		class Pause1: RscText
		{
			idc = 1000;
			x = "safezoneX + safezoneW - 2.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "safezoneY + 1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "0.7 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,1};
			shadow = 2;
		};
		class Pause2: Pause1
		{
			idc = 1001;
			x = "safezoneX + safezoneW - 3.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
	};
	class controls
	{
		delete B_Players;
		delete B_Options;
		delete B_Abort;
		delete B_Retry;
		delete B_Load;
		delete B_Save;
		delete B_Continue;
		delete B_Diary;
		delete TrafficLight;
		class Title: RscTitle
		{
			idc = 523;
			style = 0;
			text = "$STR_XBOX_CONTROLER_DP_MENU";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "14.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0};
		};
		class PlayersName: CA_Title
		{
			idc = 109;
			style = 1;
			colorBackground[] = {0,0,0,0};
			x = "6 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "14.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonCancel: RscButtonMenu
		{
			idc = 2;
			shortcuts[] = {"0x00050000 + 1","0x00050000 + 8"};
			default = 1;
			class ShortcutPos: ShortcutPos
			{
				left = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			};
			text = "$STR_DISP_INT_CONTINUE";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "15.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonSAVE: RscButtonMenu
		{
			idc = 103;
			text = "$STR_DISP_INT_SAVE";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonSkip: RscButtonMenu
		{
			idc = 1002;
			text = "$STR_DISP_INT_SKIP";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonRespawn: RscButtonMenu
		{
			idc = 1010;
			text = "$STR_DISP_INT_RESPAWN";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonOptions: RscButtonMenu
		{
			idc = 101;
			text = "$STR_A3_RscDisplayMain_ButtonOptions";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "18.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonVideo: RscButtonMenu
		{
			idc = 301;
			text = "$STR_A3_RscDisplayInterrupt_ButtonVideo";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "15.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_TOOLTIP_MAIN_VIDEO";
		};
		class ButtonAudio: RscButtonMenu
		{
			idc = 302;
			text = "$STR_A3_RscDisplayInterrupt_ButtonAudio";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_TOOLTIP_MAIN_AUDIO";
		};
		class ButtonControls: RscButtonMenu
		{
			idc = 303;
			text = "$STR_A3_RscDisplayInterrupt_ButtonControls";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_TOOLTIP_MAIN_CONTROLS";
		};
		class ButtonGame: RscButtonMenu
		{
			idc = 307;
			text = "$STR_A3_RscDisplayInterrupt_ButtonGame";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "18.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_TOOLTIP_MAIN_GAME";
		};
		class ButtonTutorialHints: RscButtonMenu
		{
			idc = 122;
			text = "$STR_A3_RscDisplayInterrupt_ButtonTutorialHints";
			tooltip = "$STR_TOOLTIP_MAIN_FIELDMANUAL";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "19.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonAbort: RscButtonMenu
		{
			idc = 104;
			text = "$STR_DISP_INT_ABORT";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class DebugConsole: RscDebugConsole
		{
			x = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "22 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "21.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MissionTitle: RscText
		{
			idc = 120;
			font = "RobotoCondensedLight";
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			shadow = 0;
			x = "SafezoneX + (1 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			w = "SafezoneW - (15 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Version: RscText
		{
			style = 1;
			font = "RobotoCondensedLight";
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			shadow = 0;
			x = "SafezoneX + SafezoneW - (13 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			idc = 1005;
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TraffLight: RscTrafficLight
		{
			idc = 121;
			x = "SafezoneX + SafezoneW - (2 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			show = 0;
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Feedback: RscFeedback{};
		class MessageBox: RscMessageBox{};
	};
};

class RscDisplayMultiplayerSetup: RscStandardDisplay {
	scriptName = "RscDisplayMultiplayerSetup";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscDisplayMultiplayerSetup"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayMultiplayerSetup"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	west = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_bluefor_ca.paa";
	east = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_opfor_ca.paa";
	guer = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_indep_ca.paa";
	civl = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\flag_civil_ca.paa";
	none = "#(argb,8,8,3)color(0,0,0,0)";
	westUnlocked = "a3\ui_f\data\map\diary\icons\playerwest_ca.paa";
	westLocked = "a3\ui_f\data\map\diary\icons\playerbriefwest_ca.paa";
	eastUnlocked = "a3\ui_f\data\map\diary\icons\playereast_ca.paa";
	eastLocked = "a3\ui_f\data\map\diary\icons\playerbriefeast_ca.paa";
	guerUnlocked = "a3\ui_f\data\map\diary\icons\playerguer_ca.paa";
	guerLocked = "a3\ui_f\data\map\diary\icons\playerbriefguer_ca.paa";
	civlUnlocked = "a3\ui_f\data\map\diary\icons\playerciv_ca.paa";
	civlLocked = "a3\ui_f\data\map\diary\icons\playerbriefciv_ca.paa";
	virtUnlocked = "a3\ui_f\data\map\diary\icons\playervirtual_ca.paa";
	virtLocked = "a3\ui_f\data\map\diary\icons\playerbriefvirtual_ca.paa";
	disabledAllAI = "$STR_DISP_MULTI_ENABLE_AI";
	enabledAllAI = "$STR_DISP_MULTI_DISABLE_AI";
	hostLocked = "$STR_DISP_MULTI_UNLOCK";
	hostUnlocked = "$STR_DISP_MULTI_LOCK";
	colorNotAssigned[] = {1,1,1,0.25};
	colorAssigned[] = {1,1,1,1};
	colorConfirmed[] = {0,1,0,1};
	class controlsbackground
	{
		delete SideBackground;

		class RolesBackground: RscText
		{
			colorBackground[] = {0,0,0,0.3};
			idc = 1085;
			x = "(4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)) - (3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + ((14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2)))";
			h = "(10.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};	
	};
	class controls
	{
		delete B_Civilian;
		delete B_Guerrila;
		delete B_East;
		delete B_West;
		delete B_Side;
		delete B_OK;
		delete B_Cancel;
		delete B_Kick;
		delete B_EnableAll;
		delete B_Lock;
		delete TextDescription;
		delete ValueDescription;
		delete TextMessage;
		delete ValueRoles;
		delete TextParam1;
		delete TextParam2;
		delete ValueParam1;
		delete ValueParam2;
		delete ValuePool;
		delete B_Params;
		delete TextPool;
		delete TextRoles;
		delete ButtonSteamWorkshop;
		delete CA_B_West;
		delete CA_B_East;
		delete CA_B_Guerrila;
		delete CA_B_Civilian;
		delete CA_B_Virtual;
		delete TextSide;
		
		class Title: RscTitle
		{
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			idc = 1000;
			text = "Select A Slot";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CA_ValueRoles: RscListBox
		{
			idc = 109;
			colorPlayer[] = {1,1,0,1};
			colorAI[] = {1,0,0,1};
			colorNobody[] = {1,1,1,0.25};
			enabledAI = "a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\enabledai_ca.paa";
			disabledAI = "a3\ui_f\data\gui\rsc\rscdisplaymultiplayersetup\disabledai_ca.paa";
			rowHeight = "1.75 * 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			x = "(4.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)) - (3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40))";
			w = "(3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + ((14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2)))";
			//--- todo increase height
			h = "(9.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			colorSelectBackground[] = {1,1,1,0.3};
			colorSelectBackground2[] = {1,1,1,0.3};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		class TextRole: RscText
		{
			idc = 108;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(14.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = "Survivor Roles:";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,1};
		};
	};
};

class mainMenu {
    idd = 88001;
    movingEnable = 0;
    enableSimulation = 1;
    fadein=2;
    duration = 999999;
    onLoad = "[] spawn opx_fnc_mainMenuFadeIn;";

    class controls {
		class RscText_1001: RscText
		{
			idc = 1001;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.819 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.18,0.19,0.23,0.2};

		};
		class RscText_1002: RscText
		{
			idc = 1002;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.18,0.19,0.23,0.2};

		};
		class RscText_1003: RscText
		{
			idc = 1003;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.874 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.18,0.19,0.23,0.2};

		};
		class RscText_1003_: RscText
		{
			idc = 26589;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {1,1,1,0.2};
		};
		class RscText_1004: RscText
		{
			idc = 1004;
			text = "SURVIVE"; //--- ToDo: Localize;
			x = -0.2898438 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.07;
			shadow = 2;
		};
		class RscText_1088: RscText
		{
			idc = 2791;
			text = "MY SURVIVOR"; //--- ToDo: Localize;
			x = -0.2898438 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.05;
			shadow = 2;
		};
		class RscText_1005: RscText
		{
			idc = 1005;
			text = "OPTIONS"; //--- ToDo: Localize;
			x = -0.2898438 * safezoneW + safezoneX;
			y = 0.819 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.05;
			shadow = 2;
		};
		class RscText_1006: RscText
		{
			idc = 1006;
			text = "EXIT"; //--- ToDo: Localize;
			x = -0.2898438 * safezoneW + safezoneX;
			y = 0.874 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.044 * safezoneH;
			sizeEx = 0.05;
			shadow = 2;
		};
		class buttonPlay: RscButtonMenu
		{
			idc = 2400;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0,0,0,0};
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class buttonCustomizeCharacter: RscButtonMenu
		{
			idc = 2403;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.764 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0,0,0,0};
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class buttonOptions: RscButtonMenu
		{
			idc = 2401;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.819 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0,0,0,0};
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class buttonExit: RscButtonMenu
		{
			idc = 2402;
			x = -0.29500003 * safezoneW + safezoneX;
			y = 0.874 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0,0,0,0};
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
	};
};

class characterCustomization {
    idd = 88002;
    movingEnable = 0;
    enableSimulation = 1;
    fadein=2;
    duration = 999999;
    onLoad = "";

    class controls {
		class RscStructuredText_1100: RscStructuredText
		{
			idc = -1;
			x = 0.582503 * safezoneW + safezoneX;
			y = 0.247089 * safezoneH + safezoneY;
			w = 0.170162 * safezoneW;
			h = 0.00549806 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscStructuredText_1101: RscStructuredText
		{
			idc = -1;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.170162 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscStructuredText_1102: RscStructuredText
		{
			idc = -1;
			x = 0.582503 * safezoneW + safezoneX;
			y = 0.280078 * safezoneH + safezoneY;
			w = 0.170162 * safezoneW;
			h = 0.00549806 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscStructuredText_1103: RscStructuredText
		{
			idc = -1;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.269082 * safezoneH + safezoneY;
			w = 0.170162 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscStructuredText_1104: RscStructuredText
		{
			idc = -1;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.390039 * safezoneH + safezoneY;
			w = 0.170162 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscStructuredText_1105: RscStructuredText
		{
			idc = -1;
			x = 0.582503 * safezoneW + safezoneX;
			y = 0.401035 * safezoneH + safezoneY;
			w = 0.170162 * safezoneW;
			h = 0.00549806 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};



		class d5254057924834: RscStructuredText
		{
			idc = -1;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			text = "<t align='center' size='1.5'>&lt;<t/>";
			colorBackground[] = {0.3,0,0,1};
		};
		class buttonHeadgearBack: RscButtonMenu
		{
			idc = 8;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorText[] = {0,0,0,1};
			colorBackground[] = {0.3,0,0,0};
			shadow = 2;
			sizeEx = 0.07;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class d5254345403879: RscStructuredText
		{
			idc = -1;
			x = 0.897044 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			text = "<t align='center' size='1.5'>&gt;<t/>";
			colorBackground[] = {0.3,0,0,1};
		};
		class buttonHeadgearForward: RscButtonMenu
		{
			idc = 9;
			x = 0.897044 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorText[] = {0,0,0,1};
			colorBackground[] = {0.3,0,0,0};
			shadow = 2;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class d525434354874: RscStructuredText
		{
			idc = -1;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.269082 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			text = "<t align='center' size='1.5'>&lt;<t/>";
			colorBackground[] = {0.3,0,0,1};
		};
		class buttonGlassesBack: RscButtonMenu
		{
			idc = 10;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.269082 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorText[] = {0,0,0,1};
			colorBackground[] = {0.3,0,0,0};
			shadow = 2;
			sizeEx = 0.07;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class d5254343257656: RscStructuredText
		{
			idc = -1;
			x = 0.897044 * safezoneW + safezoneX;
			y = 0.269082 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			text = "<t align='center' size='1.5'>&gt;<t/>";
			colorBackground[] = {0.3,0,0,1};
		};
		class buttonGlassesForward: RscButtonMenu
		{
			idc = 3;
			x = 0.897044 * safezoneW + safezoneX;
			y = 0.269082 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorText[] = {0,0,0,1};
			colorBackground[] = {0.3,0,0,0};
			shadow = 2;
			sizeEx = 0.07;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class d525433232324: RscStructuredText
		{
			idc = -1;
			x = 0.897044 * safezoneW + safezoneX;
			y = 0.390039 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			text = "<t align='center' size='1.5'>&gt;<t/>";
			colorBackground[] = {0.3,0,0,1};
		};
		class buttonClothingForward: RscButtonMenu
		{
			idc = 4;
			x = 0.897044 * safezoneW + safezoneX;
			y = 0.390039 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorText[] = {0,0,0,1};
			colorBackground[] = {0.3,0,0,0};
			shadow = 2;
			sizeEx = 0.07;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class d525434: RscStructuredText
		{
			idc = -1;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.390039 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			text = "<t align='center' size='1.5'>&lt;<t/>";
			colorBackground[] = {0.3,0,0,1};
		};
		class buttonClothingBack: RscButtonMenu
		{
			idc = 5;
			x = 0.752665 * safezoneW + safezoneX;
			y = 0.390039 * safezoneH + safezoneY;
			w = 0.0257821 * safezoneW;
			h = 0.0329884 * safezoneH;
			colorText[] = {0,0,0,1};
			colorBackground[] = {0.3,0,0,0};
			shadow = 2;
			sizeEx = 0.07;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};



		class RscStructuredText_1106: RscStructuredText
		{
			idc = -1;
			x = -0.00017268 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.252665 * safezoneW;
			h = 0.0549806 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscText_1000: RscText
		{
			idc = -1;
			text = "MY SURVIVOR"; //--- ToDo: Localize;
			x = 0.0152966 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.237195 * safezoneW;
			h = 0.0549806 * safezoneH;
			sizeEx = 2 * 0.04;
			shadow = 2;

		};
		class RscText_1001: RscText
		{
			idc = -1;
			x = 0.0101399 * safezoneW + safezoneX;
			y = 0.291074 * safezoneH + safezoneY;
			w = 0.242352 * safezoneW;
			h = 0.0439845 * safezoneH;
			colorBackground[] = {0.18,0.19,0.23,0.4};
		};
		class RscText_1002: RscText
		{
			idc = 6;
			text = "CONFIRM AND RETURN TO MAIN MENU"; //--- ToDo: Localize;
			x = 0.0152959 * safezoneW + safezoneX;
			y = 0.291074 * safezoneH + safezoneY;
			w = 0.237195 * safezoneW;
			h = 0.0439845 * safezoneH;
			sizeEx = 1.2 * 0.04;
			shadow = 2;
		};
		class buttonBack: RscButtonMenu
		{
			idc = 7;
			x = 0.0101402 * safezoneW + safezoneX;
			y = 0.291074 * safezoneH + safezoneY;
			w = 0.242352 * safezoneW;
			h = 0.0439845 * safezoneH;
			colorBackground[] = {1,1,1,0};
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureOver = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureFocused = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTexturePressed = "#(argb,8,8,3)color(1,1,1,0.1)";
		    animTextureDefault = "#(argb,8,8,3)color(1,1,1,0.1)";
		};
		class RscText_1003: RscStructuredText
		{
			idc = -1;
			text = "<t align='center' size='1.5'>HEADGEAR<t/>"; //--- ToDo: Localize;
			x = 0.783603 * safezoneW + safezoneX;
			y = 0.225097 * safezoneH + safezoneY;
			w = 0.108285 * safezoneW;
			h = 0.0329884 * safezoneH;
			sizeEx = 1.2 * 0.04;
			shadow = 2;
		};
		class RscText_1004: RscStructuredText
		{
			idc = -1;
			text = "<t align='center' size='1.5'>GLASSES<t/>"; //--- ToDo: Localize;
			x = 0.783603 * safezoneW + safezoneX;
			y = 0.269082 * safezoneH + safezoneY;
			w = 0.108285 * safezoneW;
			h = 0.0329884 * safezoneH;
			sizeEx = 1.2 * 0.04;
			shadow = 2;
		};
		class RscText_1005: RscStructuredText
		{
			idc = -1;
			text = "<t align='center' size='1.5'>CLOTHING<t/>"; //--- ToDo: Localize;
			x = 0.783603 * safezoneW + safezoneX;
			y = 0.390039 * safezoneH + safezoneY;
			w = 0.108285 * safezoneW;
			h = 0.0329884 * safezoneH;
			sizeEx = 1.2 * 0.04;
			shadow = 2;
		};
		class RscText_1006: RscText
		{
			idc = -1;

			x = 0.721726 * safezoneW + safezoneX;
			y = 0.489004 * safezoneH + safezoneY;
			w = 0.2011 * safezoneW;
			h = 0.120957 * safezoneH;
			colorBackground[] = {0.18,0.19,0.23,0.4};
		};
		class RscStructuredText_1107: RscStructuredText
		{
			idc = -1;
			shadow = 0;

			text = "Use the arrow keys next to the selection names to customize your character. Each new character will spawn equipped with this loadout."; //--- ToDo: Localize;
			x = 0.726882 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.190788 * safezoneW;
			h = 0.0989651 * safezoneH;
			colorBackground[] = {-1,-1,-1,0};
		};
	};
};

class RscDisplayInventory {
	scriptName = "RscDisplayInventory";
	scriptPath = "IGUI";
	onLoad = "[""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayInventory"",'IGUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	idd = 602;
	enableSimulation = 1;
	class Colors
	{
		dragValidBgr[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",0.5};
		dragInvalidBgr[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",0.5};
		dragValidBar[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",0.5};
		dragInvalidBar[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",0.5};
		progressBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",1};
		progressBarBgr[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.75};
		highlight[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",0.5};
	};
	class controlsBackground{};
	class controls
	{
		delete Background;
		delete Title;
		delete ButtonOK;
		delete ButtonCancel;
		class CA_ContainerBackground: RscText
		{
			idc = 1001;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class CA_PlayerBackground: RscText
		{
			idc = 1002;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "22 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class TitleBackground: RscText
		{
			idc = 1020;
			x = "14.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "24.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.1,0.1,0.1,1};
		};
		class PlayersName: RscText
		{
			idc = 111;
			text = "$STR_DIARY_PLAYER_NAME";
			x = "15.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "19.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class RankBackground: RscText
		{
			idc = 1014;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.2};
		};
		class RankPicture: RscPicture
		{
			idc = 1203;
			text = "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonBack: RscActiveText
		{
			idc = 2;
			style = 48;
			color[] = {1,1,1,0.7};
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
			x = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.7};
			colorActive[] = {1,1,1,1};
			tooltip = "$STR_DISP_CLOSE";
		};
		class BackgroundSlotPrimary: RscPicture
		{
			idc = 1242;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryMuzzle: BackgroundSlotPrimary
		{
			idc = 1243;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryUnderBarrel: BackgroundSlotPrimary
		{
			idc = 1200;
			x = "28.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryFlashlight: BackgroundSlotPrimary
		{
			idc = 1244;
			x = "30.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryOptics: BackgroundSlotPrimary
		{
			idc = 1245;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryMagazineGL: BackgroundSlotPrimary
		{
			idc = 1267;
			x = "34.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotPrimaryMagazine: BackgroundSlotPrimary
		{
			idc = 1246;
			x = "36.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondary : RscPictureKeepAspect
		{
			idc = 1247;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryMuzzle: BackgroundSlotPrimary
		{
			idc = 1248;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryUnderBarrel: BackgroundSlotPrimary
		{
			idc = 1266;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryFlashlight: BackgroundSlotPrimary
		{
			idc = 1249;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryOptics: BackgroundSlotPrimary
		{
			idc = 1250;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotSecondaryMagazine: BackgroundSlotPrimary
		{
			idc = 1251;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgun: BackgroundSlotPrimary
		{
			idc = 1252;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunMuzzle: BackgroundSlotPrimary
		{
			idc = 1253;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunUnderBarrel: BackgroundSlotPrimary
		{
			idc = 1268;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunFlashlight: BackgroundSlotPrimary
		{
			idc = 1254;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunOptics: BackgroundSlotPrimary
		{
			idc = 1255;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHandgunMagazine: BackgroundSlotPrimary
		{
			idc = 1256;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHeadgear: BackgroundSlotPrimary
		{
			idc = 1257;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotGoggles: BackgroundSlotPrimary
		{
			idc = 1258;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotHMD: BackgroundSlotPrimary
		{
			idc = 1259;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotBinoculars: BackgroundSlotPrimary
		{
			idc = 1260;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotMap: BackgroundSlotPrimary
		{
			idc = 1261;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotGPS: BackgroundSlotPrimary
		{
			idc = 1262;
			x = "17.32 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotCompass: BackgroundSlotPrimary
		{
			idc = 1263;
			x = "21.76 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotRadio: BackgroundSlotPrimary
		{
			idc = 1264;
			x = "19.54 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundSlotWatch: BackgroundSlotPrimary
		{
			idc = 1265;
			x = "23.98 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ExternalContainerBackground: RscPicture
		{
			colorText[] = {1,1,1,0.1};
			idc = 1240;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PlayerContainerBackground: ExternalContainerBackground
		{
			idc = 1241;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundTab: RscActiveText
		{
			idc = 6321;
			colorBackgroundSelected[] = {1,1,1,1};
			colorFocused[] = {1,1,1,0};
			soundDoubleClick[] = {"",0.1,1};
			color[] = {1,1,1,1};
			colorBackground[] = {0,0,0,1};
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SoldierTab: GroundTab
		{
			idc = 6401;
			x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundContainer: RscListBox
		{
			class DLCTemplate: RscDisplayInventory_DLCTemplate
			{
				class Controls;
			};
			idc = 632;
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag = 1;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			itemBackground[] = {1,1,1,0.1};
			itemSpacing = 0.001;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SoldierContainer: GroundContainer
		{
			idc = 640;
		};
		class GroundFilter: RscCombo
		{
			idc = 6554;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundLoad: RscProgress
		{
			idc = 6307;
			texture = "";
			textureExt = "";
			colorBar[] = {0.9,0.9,0.9,0.9};
			colorExtBar[] = {1,1,1,1};
			colorFrame[] = {1,1,1,1};
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SlotPrimary: GroundTab
		{
			class DLCTemplate: RscDisplayInventory_DLCTemplate
			{
				class Controls;
			};
			idc = 610;
			style = "0x30 + 0x800";
			color[] = {1,1,1,1};
			colorBackground[] = {1,1,1,0.1};
			colorBackgroundSelected[] = {1,1,1,0.1};
			colorFocused[] = {0,0,0,0};
			canDrag = 1;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotPrimaryMuzzle: SlotPrimary
		{
			idc = 620;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotPrimaryUnderBarrel: SlotPrimary
		{
			idc = 641;
			x = "28.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotPrimaryFlashlight: SlotPrimary
		{
			idc = 622;
			x = "30.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotPrimaryOptics: SlotPrimary
		{
			idc = 621;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotPrimaryMagazineGL: SlotPrimary
		{
			idc = 644;
			x = "34.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotPrimaryMagazine: SlotPrimary
		{
			idc = 623;
			x = "36.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotSecondary: SlotPrimary
		{
			idc = 611;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotSecondaryMuzzle: SlotPrimary
		{
			idc = 624;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotSecondaryUnderBarrel: SlotPrimary
		{
			idc = 642;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.59 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotSecondaryFlashlight: SlotPrimary
		{
			idc = 626;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotSecondaryOptics: SlotPrimary
		{
			idc = 625;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotSecondaryMagazine: SlotPrimary
		{
			idc = 627;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "14.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHandgun: SlotPrimary
		{
			idc = 612;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "17 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHandgunMuzzle: SlotPrimary
		{
			idc = 628;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHandgunUnderBarrel: SlotPrimary
		{
			idc = 643;
			x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHandgunFlashlight: SlotPrimary
		{
			idc = 630;
			x = "31.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHandgunOptics: SlotPrimary
		{
			idc = 629;
			x = "33.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHandgunMagazine: SlotPrimary
		{
			idc = 631;
			x = "36.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHeadgear: SlotPrimary
		{
			idc = 6240;
			x = "26.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotGoggles: SlotPrimary
		{
			idc = 6216;
			x = "29.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotHMD: SlotPrimary
		{
			idc = 6217;
			x = "32.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotBinoculars: SlotPrimary
		{
			idc = 6238;
			x = "35.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotMap: SlotPrimary
		{
			idc = 6211;
			x = "15.16 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotGPS: SlotPrimary
		{
			idc = 6215;
			x = "17.38 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotCompass: SlotPrimary
		{
			idc = 6212;
			x = "21.82 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotRadio: SlotPrimary
		{
			idc = 6214;
			x = "19.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class SlotWatch: SlotPrimary
		{
			idc = 6213;
			x = "24.04 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "20.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class UniformTab: GroundTab
		{
			idc = 6332;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.5};
		};
		class UniformSlot: SlotPrimary
		{
			idc = 6331;
			x = "15.35 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class UniformLoad: GroundLoad
		{
			idc = 6304;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class UniformContainer: GroundContainer
		{
			idc = 633;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class VestTab: UniformTab
		{
			idc = 6382;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class VestSlot: SlotPrimary
		{
			idc = 6381;
			x = "19.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class VestLoad: GroundLoad
		{
			idc = 6305;
			x = "18.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class VestContainer: UniformContainer
		{
			idc = 638;
		};
		class BackpackTab: UniformTab
		{
			idc = 6192;
			x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackpackSlot: SlotPrimary
		{
			idc = 6191;
			x = "22.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0,0,0.5};
		};
		class BackpackLoad: GroundLoad
		{
			idc = 6306;
			x = "22.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackpackContainer: UniformContainer
		{
			idc = 619;
		};
		class TotalLoad: GroundLoad
		{
			idc = 6308;
			x = "15.1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "22.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ContainerMarker: GroundTab
		{
			idc = 6325;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GroundMarker: ContainerMarker
		{
			idc = 6385;
			x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SoldierMarker: ContainerMarker
		{
			idc = 6405;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "24 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};

class RscDisplayMain: RscStandardDisplay {
	idd = 0;
	scriptName = "RscDisplayMain";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscDisplayMain"",'GUI'] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf'";
	onUnload = "[""onUnload"",_this,""RscDisplayMain"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	
	delete Spotlight;
	class ControlsBackground {
		delete BackgroundLeft;
		delete BackgroundRight;
	};
	class Controls
	{
		delete ModIcons;
		delete B_Quit;
		delete B_Expansions;
		delete B_Credits;
		delete B_Player;
		delete B_Options;
		delete B_SinglePlayer;
		delete B_MissionEditor;
		delete B_MultiPlayer;
		delete B_SingleMission;
		delete B_Campaign;
		delete Date;
		delete ModList;
		delete TrafficLight;
		delete Version;
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		delete Footer;
		delete AllMissions;
		delete ProofsOfConcept;
		
		delete TitleMultiplayer;
		delete TitleSingleplayer;
		delete TitleTutorials;
		delete TitleOptions;
		
		delete TitleIconSingleplayer;
		delete TitleIconMultiplayer;
		delete TitleIconTutorials;
		delete TitleIconOptions;
		
		delete GroupSingleplayer;
		delete GroupMultiplayer;
		delete GroupTutorials;
		delete GroupOptions;
		
		delete LogoApex;
		delete Logo;
		delete GroupSession;
		delete TitleSession;
		delete NewLogo;
		delete Profile;
		
		class InfoMods: RscControlsGroupNoHScrollbars
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoDLCsOwned: InfoMods
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoDLCs: InfoDLCsOwned
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoNews: InfoMods
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoVersion: InfoNews
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		
		class BackgroundBar: RscText
		{
			colorBackground[] = {0,0,0,0.75};
			x = -10;
			y = -10;
			w = 1;
			h = 1;
		};
		class BackgroundCenter: BackgroundBar
		{
			colorBackground[] = {0,0,0,1};
		};
		class BackgroundBarLeft: RscPicture
		{
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\gradientMods_ca.paa";
			colorText[] = {0,0,0,1};
			angle = 180;
			x = -10;
			y = -10;
			w = 1;
			h = 1;
		};
		class BackgroundBarRight: BackgroundBarLeft
		{
			angle = 0;
		};
		
		//--- ACTIVATE ON EXIT
		class Exit: RscButton {
			x = -10;
			y = -10;
			tooltip = "Quit the game.";
			backgroundColor[] = {0,0,0,1};
			textColor[] = {1,1,1,1};
		};
		

		
		
		
		//--- PLAY tab
		//--- editor button not working, may need to do our own
		class Editor: RscButtonMenuMain
		{
			idc = 142;
			text = "$STR_A3_RscDisplayMain_ButtonEditor";
			tooltip = "$STR_TOOLTIP_SINGLEPLAYER_EDITOR_A3";
			x = -10;
			y = -10;
			w = 0.2;
			h = 0.05;
			show = 0;
			onbuttonclick = "";
			class Attributes
			{
				align = "center";
				color = "#ffffff";
				font = "PuristaLight";
				shadow = 0;
				size = 1.5;
			};
		}; 
		//--- editor button not working
		class ServerBrowser: Editor
		{
			idc = 105;
			text = "Play Online";
			tooltip = "Find a server to play on.";
			onbuttonclick = "";
		};
		
		//--- OPTIONS tab
		class Video: Editor
		{
			idc = 301;
			text = "$STR_A3_RscDisplayMain_ButtonVideo";
			tooltip = "$STR_TOOLTIP_MAIN_VIDEO";
			show = 0;
			onbuttonclick = "";
		};
		class Audio: Editor
		{
			idc = 302;
			text = "$STR_A3_RscDisplayMain_ButtonAudio";
			tooltip = "$STR_TOOLTIP_MAIN_AUDIO";
			show = 0;
			onbuttonclick = "";
		};
		class Controls: Editor
		{
			idc = 303;
			text = "$STR_A3_RscDisplayMain_ButtonControls";
			tooltip = "$STR_TOOLTIP_MAIN_CONTROLS";
			show = 0;
			onbuttonclick = "";
		};
		
		
	};
};


class RscDisplayMain_OLD: RscStandardDisplay
{
	idd = 0;
	scriptName = "RscDisplayMain";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscDisplayMain"",'GUI'] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf'";
	onUnload = "[""onUnload"",_this,""RscDisplayMain"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	
	delete Spotlight;
	class ControlsBackground {
		delete BackgroundLeft;
		delete BackgroundRight;
	};
	class Controls
	{
		delete ModIcons;
		delete B_Quit;
		delete B_Expansions;
		delete B_Credits;
		delete B_Player;
		delete B_Options;
		delete B_SinglePlayer;
		delete B_MissionEditor;
		delete B_MultiPlayer;
		delete B_SingleMission;
		delete B_Campaign;
		delete Date;
		delete ModList;
		delete TrafficLight;
		delete Version;
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		delete Footer;
		delete AllMissions;
		delete ProofsOfConcept;
		
		delete TitleMultiplayer;
		delete TitleSingleplayer;
		delete TitleTutorials;
		delete TitleOptions;
		
		delete TitleIconSingleplayer;
		delete TitleIconMultiplayer;
		delete TitleIconTutorials;
		delete TitleIconOptions;
		
		delete GroupSingleplayer;
		delete GroupMultiplayer;
		delete GroupTutorials;
		delete GroupOptions;
		
		delete LogoApex;
		delete Logo;
		delete GroupSession;
		delete TitleSession;
		
		class InfoMods: RscControlsGroupNoHScrollbars
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoDLCsOwned: InfoMods
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoDLCs: InfoDLCsOwned
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoNews: InfoMods
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		class InfoVersion: InfoNews
		{
			y = -10;
			x = -10;
			w = 1;
			h = 1;
		};
		
		
		class BackgroundBar: RscText
		{
			colorBackground[] = {0,0,0,0.75};
			x = -10;
			y = -10;
			w = 1;
			h = 1;
		};
		class BackgroundCenter: BackgroundBar
		{
			colorBackground[] = {0,0,0,1};
		};
		class BackgroundBarLeft: RscPicture
		{
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\gradientMods_ca.paa";
			colorText[] = {0,0,0,1};
			angle = 180;
			x = -10;
			y = -10;
			w = 1;
			h = 1;
		};
		class BackgroundBarRight: BackgroundBarLeft
		{
			angle = 0;
		};
		
		class NewsBackground: IGUIBack
		{
			idc = 22000;
			x = "safeZoneX+(pixelW * pixelGrid * 2)";
			y = 0.247 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.528 * safezoneH;
		};
		class NewsTitle: RscText
		{
			idc = 10000;
			text = "Version 1.0.1 News";
			x = "safeZoneX+(pixelW * pixelGrid * 2)";
			y = 0.225 * safezoneH + safezoneY;
			w = 0.252656 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.4,0,0,0.75};
		};
		class NewsContent: RscStructuredText
		{
			idc = 11000;
			x = "safeZoneX + ((0.04625 * safezoneW + safezoneX)-(0.0410937 * safezoneW + safezoneX))+(pixelW * pixelGrid * 2)";
			y = 0.247 * safezoneH + safezoneY;
			w = 0.242344 * safezoneW;
			h = 0.517 * safezoneH;
		};
		
		class NextHat: RscButtonMenuMain 
		{
			tooltip = "Change your starting hat";
			class Attributes
			{
				align = "center";
				color = "#ffffff";
				font = "PuristaLight";
				shadow = 0;
				size = 2;
			};
			text = "Change Hat";
			x = "safeZoneX + safezoneW - 0.4 - (pixelW * pixelGrid * 2)";
			w = 0.4;
			y = 0.2;
			h = 0.1;
			onbuttonclick = "0 call compile preprocessfilelinenumbers '\dsr_ui\Scripts\loadout_handler.sqf'";
		};
		class NextGlasses: NextHat 
		{
			tooltip = "Change your starting glasses";
			text = "Change Glasses";
			x = "safeZoneX + safezoneW - 0.4 - (pixelW * pixelGrid * 2)";
			w = 0.4;
			y = 0.31;
			h = 0.1;
			onbuttonclick = "1 call compile preprocessfilelinenumbers '\dsr_ui\Scripts\loadout_handler.sqf'";
		};
		class NextUniform: NextHat 
		{
			tooltip = "Change your starting uniform";
			text = "Change Uniform";
			x = "safeZoneX + safezoneW - 0.4 - (pixelW * pixelGrid * 2)";
			w = 0.4;
			y = 0.42;
			h = 0.1;
			onbuttonclick = "2 call compile preprocessfilelinenumbers '\dsr_ui\Scripts\loadout_handler.sqf'";
		};
		
		//--- UPDATE ICONS TO SURROUND LOGO ( after logo resize )
		class Exit: RscButton {
			x = "0.6-(2 *	(pixelW * pixelGrid * 2))";
			y = "0.2-(2 *	(pixelH * pixelGrid * 2))";
			tooltip = "Quit the game.";
			backgroundColor[] = {0,0,0,1};
			textColor[] = {1,1,1,1};
		};
		class Profile: Exit
		{
			idc = 109;
			style = 0;
			text = "Edit Profile";
			tooltip = "Edit your profile.";
			x = 0.4;
			y = "0.2 - (2 *	(pixelH * pixelGrid * 2))";
			w = "0.2 - (2 * 	(pixelW * pixelGrid * 2))";
			onbuttonclick = "";
		};
		
		
		//--- PLAY tab
		//--- editor button not working, may need to do our own
		class Editor: RscButtonMenuMain
		{
			idc = 142;
			text = "$STR_A3_RscDisplayMain_ButtonEditor";
			tooltip = "$STR_TOOLTIP_SINGLEPLAYER_EDITOR_A3";
			x = 0.4;
			y = 0.3;
			w = 0.2;
			h = 0.05;
			show = 0;
			onbuttonclick = "";
			class Attributes
			{
				align = "center";
				color = "#ffffff";
				font = "PuristaLight";
				shadow = 0;
				size = 1.5;
			};
		}; 
		//--- editor button not working
		class ServerBrowser: Editor
		{
			idc = 105;
			text = "Play Online";
			tooltip = "Find a server to play on.";
			y = 0.2;
			show = 1;
			onbuttonclick = "";
		};
		
		//--- HELP tab
		class Website: Editor
		{
			idc = 1338;
			y = 0.2;
			text = "Visit Website";
			tooltip = "Find everything you need on our website.";
			url = "http://desolationredux.com";
			onbuttonclick = "";
			show = 0;
		};
		class BugReport: Editor
		{
			idc = 1340;
			text = "Report a bug";
			tooltip = "Found a bug? Please report it ASAP!";
			url = "http://desolationredux.com/";
			onbuttonclick = "";
			y = 0.25;
			show = 0;
		};
		//--- MAIN tab
		class Options: Editor
		{
			idc = 1342;
			text = "Options";
			tooltip = "Configure your game.";
			onbuttonclick = "[""mOpen"",[(findDisplay 0),2],""RscDisplayMain""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf'";
			y = 0.25;
			show = 1;
		};
		class Help: Editor
		{
			idc = 1343;
			text = "Help";
			tooltip = "Need help?";
			onbuttonclick = "[""mOpen"",[(findDisplay 0),3],""RscDisplayMain""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf'";
			y = 0.3;
			show = 1;
		};
		//--- OPTIONS tab
		class Video: Editor
		{
			idc = 301;
			text = "$STR_A3_RscDisplayMain_ButtonVideo";
			tooltip = "$STR_TOOLTIP_MAIN_VIDEO";
			y = 0.2;
			show = 0;
			onbuttonclick = "";
		};
		class Audio: Editor
		{
			idc = 302;
			text = "$STR_A3_RscDisplayMain_ButtonAudio";
			tooltip = "$STR_TOOLTIP_MAIN_AUDIO";
			y = 0.25;
			show = 0;
			onbuttonclick = "";
		};
		class Controls: Editor
		{
			idc = 303;
			text = "$STR_A3_RscDisplayMain_ButtonControls";
			tooltip = "$STR_TOOLTIP_MAIN_CONTROLS";
			y = 0.3;
			show = 0;
			onbuttonclick = "";
		};
		class DesolationControls: Editor
		{
			idc = 1344;
			text = "Desolation Controls";
			tooltip = "";
			show = 0;
			onbuttonclick = "";
			y = 0.35;
		};
		class DesolationBack: Editor
		{
			idc = 1345;
			text = "Back";
			tooltip = "Back to the main menu.";
			show = 0;
			onbuttonclick = "[""mOpen"",[(findDisplay 0),0],""RscDisplayMain""] call compile preprocessfilelinenumbers '\dsr_ui\Scripts\RscDisplayMain.sqf'";
			y = 0.2;
		};
		//--- CHANGE SIZING (make bigger)
		class NewLogo: RscPictureKeepAspect
		{
			text = "\dsr_ui\Assets\logo_topalign.paa";
			url = "";
			shadow = 0;
			x = 0;
			y = "safezoneY+(pixelH * pixelGrid * 2)";
			w = 1;
			h = 0.5;
		};
	};
};

