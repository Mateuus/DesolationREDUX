class CfgPatches
{
	class dsr_objects
	{
		fileName = "dsr_objects.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F", "A3_Structures_F_Ind"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};
class CfgVehicles
{
	class NATO_Box_Base;
	
	class DSR_Crate_Airdrop_F : NATO_Box_Base {
		_generalMacro = "DSR_Crate_Airdrop_F";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_CargoBox_V1_F.jpg";
		author = "Desolation Redux Dev Team";
		mapSize = 1.53;
		scope = 2;
		scopeCurator = 2;
		displayName = "$STR_A3_CfgVehicles_Land_CargoBox_V1_F0";
		model = "\A3\Structures_F\Ind\Cargo\CargoBox_V1_F.p3d";
		icon = "iconObject_1x1";
		destrType = "DestructNo";
		cost = 3000;
		editorSubcategory = "EdSubcat_Storage";
		//--- crate container restraints 
		maximumLoad = 2000;
		transportMaxWeapons = 12;
		transportMaxMagazines = 64;
		transportMaxBackpacks = 12;
	};
};