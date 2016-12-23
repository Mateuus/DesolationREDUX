class CfgPatches
{
	class dsr_patches
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Functions_F","A3_Map_Tanoabuka","dsr_ui"};
		fileName = "dsr_patches.pbo";
		requiredVersion = 0.1;
		author[]= {"Desolation Redux Dev Team"};
	};
};

class CfgFunctions {
	class A2 {
		class Numbers {
			class parseNumber {file = "\dsr_patches\Scripts\parseNumber.sqf";};	
		};
	};
};
class CfgWorlds {
	class CAWorld;
	class Tanoa: CAWorld {
		class AmbientA3 {
			delete Radius440_500;
			delete Radius40_60;
		};
	};
};