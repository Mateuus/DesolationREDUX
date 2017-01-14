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
	class ReammoBox;
	class LootWeaponHolder: ReammoBox
	{
		scope = 1;
		scopeCurator = 0;
		author = "Desolation Redux Dev Team";
		isGround = 1;
		accuracy = 0.2;
		forceSupply = 1;
		showWeaponCargo = 1;
		transportMaxMagazines = 1e+009;
		transportMaxWeapons = 1e+009;
		transportMaxBackpacks = 0;
		icon = "iconObject_1x1";
		model = "\A3\Weapons_f\dummyweapon.p3d";
		destrType = "DestructNo";
		class TransportMagazines {};
	};
	class NATO_Box_Base;
	class DSR_Crate_Base: NATO_Box_Base
	{
		_generalMacro = "DSR_Crate_Base";
		editorPreview = "\dsr_ui\assets\logo.paa";
		model = "\A3\Structures_F\Ind\Cargo\CargoBox_V1_F.p3d";
		author = "Desolation Redux Dev Team";
		scope = 1;
		scopeCurator = 1;
		displayName = "Desolation Redux - UNDEFINED DISPLAYNAME";
		cost = 3000;
		editorSubcategory = "EdSubcat_Storage";
		maximumLoad = 0;
		icon = "iconObject_1x1";
		destrType = "DestructNo";
		mapSize = 1;
	};
	class DSR_Crate_Airdrop_F : DSR_Crate_Base 
	{
		_generalMacro = "DSR_Crate_Airdrop_F";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_CargoBox_V1_F.jpg";
		author = "Desolation Redux Dev Team";
		mapSize = 1.53;
		scope = 2;
		scopeCurator = 2;
		displayName = "$STR_A3_CfgVehicles_Land_CargoBox_V1_F0";
		model = "\A3\Structures_F\Ind\Cargo\CargoBox_V1_F.p3d";

		//--- crate container restraints
		maximumLoad = 2000;
	};
	class DSR_Workbench: DSR_Crate_Base
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Workbench";
		maximumLoad = 600;
		model = "\dsr_objects\workbench\dsr_workbench.p3d";
	};
	class DSR_House_lv1: DSR_Crate_Base
	{
		displayName = "House Level 1";
		scope = 2;
		scopeCurator = 2;
		model = "\dsr_objects\House_lv1\dsr_playerhouse_lv1.p3d";
		maximumLoad = 2000;
	};
	class DSR_Storage_Small: DSR_Crate_Base
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Wooden crate small";
		model = "\dsr_objects\storage_wood\dsr_storage_small.p3d";
		maximumLoad = 1000;
	};
	class DSR_Storage_Large: DSR_Crate_Base
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "Wooden crate large";
		model = "\dsr_objects\storage_wood\dsr_storage_large.p3d";
		maximumLoad = 2000;
	};

	class NonStrategic;
	class DSR_objects_base: NonStrategic
	{
		scope = 1;
		author = "Desolation Redux Dev Team";
		mapSize = 1;
		armor = 10000;
		cost = 1000;
		icon = "iconObject_1x1";
		picture = "";
		destrType = "DestructNo";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		editorSubcategory = "DSR_Objects";
	};
	class dsr_gun_cabinet_metal: DSR_objects_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Gun Cabinet Metal";
		model = "\dsr_objects\gun_cab\gun_cab.p3d";
		mass = 150;
	};
	class dsr_water_catchment: DSR_objects_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Water-Catchment";
		model = "\dsr_objects\water_catchment\water_catchment.p3d";
		icon = "iconObject_4x1";
		mass = 150;
	};
	class dsr_stockade_gate: DSR_objects_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Stockade Gate";
		model = "\dsr_objects\stockade_gate\dsr_stockade_gate.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_stockade_wall: DSR_objects_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Stockade Wall";
		model = "\dsr_objects\stockade_wall\dsr_stockade_wall.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_stockade_rampart: DSR_objects_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Stockade Rampart";
		model = "\dsr_objects\stockade_rampart\dsr_stockade_rampart.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_stockade_tower: DSR_objects_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Stockade Tower";
		model = "\dsr_objects\stockade_tower\dsr_stockade_tower.p3d";
		icon = "iconObject_4x1";
		editorSubcategory = "DSR_Objects";
		mass = 150;
	};
	class dsr_objects_workbench: DSR_objects_base
	{
		displayName = "Workbench";
		model = "dsr_objects\workbench\dsr_workbench.p3d";
		//editorPreview = ""
		faction = "Empty";
		scope = 2;
	}; 
};
class CfgEditorSubcategories
{
	class DSR_Objects
	{
		displayName = "DSR Objects";
	};
};