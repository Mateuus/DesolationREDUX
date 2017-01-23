class CfgPatches
{
	class dsr_objects
	{
		fileName = "dsr_objects.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F","A3_Structures_F_Ind"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author = "Desolation Redux Dev Team";
	};
};

class CfgVehicles
{
	class House;
	class House_F: House {};
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
		mass = 150;
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
	class NonStrategic;
	class DSR_Objects_Base: NonStrategic
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
	class DSR_objects_splint: DSR_Objects_Base
	{
		scope = 2;
		scopeCurator = 2;
		model = "dsr_objects\splint\dsr_splint";
		displayName = "splint";
	};
	#include "gun_cab\gun_cab.hpp"
	#include "house_lv1\house_lv1.hpp"
	#include "house_lv2\house_lv2.hpp"
	#include "decor\decor.hpp"
	#include "cot\cot.hpp"
	#include "stockade_gate\stockade_gate.hpp"
	#include "stockade_rampart\stockade_rampart.hpp"
	#include "stockade_tower\stockade_tower.hpp"
	#include "stockade_wall\stockade_wall.hpp"
	#include "storage_wood\storage_wood.hpp"
	#include "workbench\workbench.hpp"
	#include "water_catchment\water_catchment.hpp"
	#include "farming\farming.hpp"
	#include "anvillog\anvillog.hpp"
	#include "billboard\billboard.hpp"
};
class CfgEditorSubcategories
{
	class DSR_Objects
	{
		displayName = "DSR Objects";
	};
};