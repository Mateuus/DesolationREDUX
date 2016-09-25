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



class DS_spawnSelection {
	idd = 4000;
	name = "DS_spawnSelection";
	movingEnable = 1;
	enableSimulation = 1;
	
	onLoad = "_this call compile preprocessfilelinenumbers 'dsr_ui\Scripts\fn_spawnSelection.sqf';";
	onUnload = "_this call compile preprocessfilelinenumbers 'dsr_ui\Scripts\fn_spawnSelectionUnload.sqf';";
	
	class controlsBackground {
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
