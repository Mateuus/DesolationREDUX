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
	
	class DSR_Crate_Airdrop_F : NATO_Box_Base 
	{
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

class CfgMagazines
{
	class CA_Magazine;
	class dsr_gun_cabinet_metal: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Gun Cabinet Metal";
		model = "\dsr_objects\gun_cab\gun_cab.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_water_catchment: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Water-Catchment";
		model = "\dsr_objects\water_catchment\water_catchment.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_engine_block: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Engine Block";
		model = "\dsr_objects\engine_repair\engine_repair.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_vehicle_gas_tank: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Gas Tank";
		model = "\dsr_objects\vehicle_gas_tank\vehicle_gas_tank.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 100;
	};
	class dsr_vehicle_tire_repair: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Tire Repair";
		model = "\dsr_objects\tire_part\tire_part.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 100;
	};
	class dsr_tools_spanner: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Spanner Wrench";
		model = "\dsr_objects\spanner\spanner.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 25;
	};
	class dsr_tools_saw: CA_Magazine
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Saw";
		model = "\dsr_objects\saw\saw.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 25;
	};
};