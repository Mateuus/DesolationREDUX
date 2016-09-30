class CfgPatches
{
	class dsr_ui
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F","A3_Ui_F","A3_Functions_F","A3_UiFonts_F"};
		fileName = "dsr_ui.pbo";
		requiredVersion = 0.1;
		author[]= {"Desolation Redux Dev Team"};
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

class RscDisplayMPInterrupt: RscStandardDisplay
{
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

//--- UI overrides
class RscDisplayInventory
{
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




