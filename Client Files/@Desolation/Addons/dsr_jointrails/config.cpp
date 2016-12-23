class CfgPatches
{
	class dsr_jointrails
	{
		fileName = "dsr_jointrails.pbo";
		requiredAddons[] = {
			"A3_Weapons_F",
			"A3_Weapons_F_Exp",
			"A3_Weapons_F_Mark",
			"A3_Weapons_F_EPA_LongRangeRifles_DMR_01",
			"A3_Weapons_F_Mark_LongRangeRifles_DMR_02",
			"A3_Weapons_F_Mark_LongRangeRifles_DMR_03",
			"A3_Weapons_F_Mark_LongRangeRifles_DMR_04",
			"A3_Weapons_F_Mark_LongRangeRifles_DMR_05",
			"A3_Weapons_F_Mark_LongRangeRifles_DMR_06",
			"A3_Weapons_F_EBR",
			"A3_Weapons_F_LongRangeRifles_GM6",
			"A3_Weapons_F_LongRangeRifles_M320",
			"A3_Weapons_F_Machineguns_M200",
			"A3_Weapons_F_Mark_Machineguns_MMG_01",
			"A3_Weapons_F_Mark_Machineguns_MMG_02",
			"A3_Weapons_F_Machineguns_Zafir",
			"A3_Weapons_F_Rifles_Khaybar",
			"A3_Weapons_F_Rifles_Mk20",
			"A3_Weapons_F_Rifles_MX",
			"A3_Weapons_F_Rifles_TRG20",
			"A3_Weapons_F_Pistols_PDW2000",
			"A3_Weapons_F_Rifles_Vector",
			"A3_Weapons_F_Rifles_SMG_02",
			"A3_Weapons_F_Exp_SMGs_SMG_05",
			"A3_Weapons_F_Exp_Machineguns_LMG_03",
			"A3_Weapons_F_Exp_LongRangeRifles_DMR_07",
			"A3_Weapons_F_Exp_Rifles_AK12"
		};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
	
	
	//asdg support
	class asdg_jointrails
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.44;
		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Mark"};
		author[] = {"SDG Compatability for Desolation Redux Joint Rails"};
	};
	class asdg_jointmuzzles
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.44;
		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Mark"};
		author[] = {"ASDG Compatability for Desolation Redux Joint Rails"};
	};
};

//--- class imports
class CowsSlot;
class PointerSlot;

//--- slot information
class DSR_JR_SlotInfo : CowsSlot {
	access = 0;
	scope = 0;
	displayName = "";
	linkProxy = "defaultProxy";
	iconPosition[] = {0,0};
	iconScale = 0;
	iconPicture = "\dsr_ui\Assets\logo.paa";
	iconPinpoint = "Center";
};
class DSR_JR_FrontSlot: DSR_JR_SlotInfo {
	compatibleItems[] = {"acc_flashlight","acc_pointer_IR"};
	linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
	iconPicture = "\A3\Weapons_F\data\UI\attachment_side.paa";
};
class DSR_JR_MuzzleSlot: DSR_JR_SlotInfo {
	linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
	iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
};
class DSR_JR_UnderSlot: DSR_JR_SlotInfo {
	linkProxy = "\A3\Data_F_Mark\Proxies\Weapon_Slots\UNDERBARREL";
	iconPicture = "\A3\Weapons_F_Mark\Data\UI\attachment_under.paa";
	iconPinpoint = "Bottom";
};
class DSR_JR_OpticSlot: DSR_JR_SlotInfo {
	
	linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
	iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
	iconPinpoint = "Bottom";
};
//--- base classes
class DSR_JR_OPTIC : DSR_JR_OpticSlot {};
class DSR_JR_OPTIC_SHORT : DSR_JR_OpticSlot {};
class DSR_JR_OPTIC_LONG : DSR_JR_OpticSlot {};
class DSR_JR_OPTIC_SIDE : DSR_JR_OpticSlot {};

class DSR_JR_MUZZLE_762 : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_556 : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_338 : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_9364 : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_9MIL : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_9MILSMG : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_45ACP : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_45ACPSMG : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_545R : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_762R : DSR_JR_MuzzleSlot {};
class DSR_JR_MUZZLE_762LMG : DSR_JR_MuzzleSlot {};

//--- asdg compatability

class asdg_SlotInfo : DSR_JR_SlotInfo {};
class asdg_FrontSideRail : DSR_JR_FrontSlot {};
class asdg_MuzzleSlot : DSR_JR_MuzzleSlot {};
class asdg_UnderSlot : DSR_JR_UnderSlot {};
class asdg_OpticRail : DSR_JR_OpticSlot {};
class asdg_OpticRail1913 : DSR_JR_OPTIC {};
class asdg_OpticRail1913_short : DSR_JR_OPTIC_SHORT {};
class asdg_OpticRail1913_long : DSR_JR_OPTIC_LONG {};
class asdg_OpticSideMount : DSR_JR_OPTIC_SIDE {};
class asdg_MuzzleSlot_762 : DSR_JR_MUZZLE_762 {};
class asdg_MuzzleSlot_556 : DSR_JR_MUZZLE_556 {};
class asdg_MuzzleSlot_338 : DSR_JR_MUZZLE_338 {};
class asdg_MuzzleSlot_93x64 : DSR_JR_MUZZLE_9364 {};
class asdg_MuzzleSlot_9MM : DSR_JR_MUZZLE_9MIL {};
class asdg_MuzzleSlot_9MM_SMG : DSR_JR_MUZZLE_9MILSMG {};
class asdg_MuzzleSlot_45ACP : DSR_JR_MUZZLE_45ACP {};
class asdg_MuzzleSlot_45ACP_SMG : DSR_JR_MUZZLE_45ACPSMG {};
class asdg_MuzzleSlot_545R : DSR_JR_MUZZLE_545R {};
class asdg_MuzzleSlot_762R : DSR_JR_MUZZLE_762R {};
class asdg_MuzzleSlot_762MG : DSR_JR_MUZZLE_762LMG {};

//--- weapon definitions

class CfgWeapons
{
	//--- base imports
	class Rifle;
	
	
	//--- base import buildoff (used for some items but not all)
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
	};
	class Rifle_Long_Base_F : Rifle_Base_F 
	{
		class WeaponSlotsInfo;
	};
	class Rifle_Short_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_AK12_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	
	
	//--- base weapon classes
	class DMR_01_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class DMR_02_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class DMR_03_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class DMR_04_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class DMR_05_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class DMR_06_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class EBR_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class GM6_base_F: Rifle_Long_Base_F 
	{
		class WeaponSlotsInfo;
	};
	class LRR_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class MMG_01_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class MMG_02_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_Katiba_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class mk20_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class Tavor_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class pdw2000_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class SMG_01_Base: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class SMG_02_base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
	};
	class SMG_05_base_F: Rifle_Short_Base_F
	{
		class WeaponSlotsInfo;
	};
	class LMG_03_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	class DMR_07_base_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo;
	};
	
	
	
	//--- weapon overrides
	class srifle_DMR_01_F: DMR_01_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.38};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.5};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.4,0.7};
				iconScale = 0.2;
			};
		};
	};
	class srifle_DMR_02_F: DMR_02_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_338
			{
				iconPosition[] = {0,0.4};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC_LONG
			{
				iconPosition[] = {0.5,0.36};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.22,0.42};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.2,0.8};
				iconScale = 0.3;
			};
		};
	};
	class srifle_DMR_03_F: DMR_03_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_762
			{
				iconPosition[] = {0.12,0.431};
				iconScale = 0.15;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.36};
				iconScale = 0.15;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.33,0.4};
				iconScale = 0.2;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.3,0.8};
				iconScale = 0.3;
			};
		};
	};
	class srifle_DMR_04_F: DMR_04_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.52,0.38};
				iconScale = 0.15;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.3,0.43};
				iconScale = 0.2;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.3,0.7};
				iconScale = 0.2;
			};
		};
	};
	class srifle_DMR_05_blk_F: DMR_05_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_9364
			{
				iconPosition[] = {0,0.43};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC_LONG
			{
				iconPosition[] = {0.5,0.38};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.22,0.43};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.2,0.8};
				iconScale = 0.3;
			};
		};
	};
	class srifle_DMR_06_camo_F: DMR_06_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_762
			{
				iconPosition[] = {0.06,0.4};
				iconScale = 0.15;
			};
			class CowsSlot: DSR_JR_OPTIC_SHORT
			{
				iconPosition[] = {0.52,0.36};
				iconScale = 0.15;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.32,0.8};
				iconScale = 0.3;
			};
		};
	};
	class srifle_EBR_F: EBR_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_762
			{
				iconPosition[] = {0.05,0.38};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.3};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.4};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.3,0.65};
				iconScale = 0.2;
			};
		};
	};
	class srifle_GM6_F: GM6_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.55,0.3};
				iconScale = 0.2;
			};
		};
	};
	class srifle_LRR_F: LRR_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.6,0.35};
				iconScale = 0.2;
			};
		};
	};
	class LMG_Mk200_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC_SHORT
			{
				iconPosition[] = {0.6,0.45};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.5};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.35,0.8};
				iconScale = 0.2;
			};
		};
	};
	class MMG_01_hex_F: MMG_01_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_9364
			{
				iconPosition[] = {0.06,0.4};
				iconScale = 0.15;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.57,0.28};
				iconScale = 0.15;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.38,0.42};
				iconScale = 0.2;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.35,0.85};
				iconScale = 0.3;
			};
		};
	};
	class MMG_02_camo_F: MMG_02_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_338
			{
				iconPosition[] = {0.06,0.42};
				iconScale = 0.15;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.62,0.32};
				iconScale = 0.15;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.38,0.42};
				iconScale = 0.2;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.35,0.85};
				iconScale = 0.3;
			};
		};
	};
	class LMG_Zafir_F: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC_SHORT
			{
				iconPosition[] = {0.6,0.35};
				iconScale = 0.15;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.4,0.4};
				iconScale = 0.15;
			};
		};
	};
	class arifle_Katiba_F: arifle_Katiba_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.45};
				iconScale = 0.2;
			};
		};
	};
	class arifle_Katiba_C_F: arifle_Katiba_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.45};
				iconScale = 0.2;
			};
		};
	};
	class arifle_Katiba_GL_F: arifle_Katiba_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.45};
				iconScale = 0.2;
			};
		};
	};
	class arifle_Mk20_F: mk20_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_556
			{
				iconPosition[] = {0,0.38};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.25};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.35};
				iconScale = 0.25;
			};
		};
	};
	class arifle_Mk20C_F: mk20_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_556
			{
				iconPosition[] = {0,0.38};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.35};
				iconScale = 0.25;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.25};
				iconScale = 0.2;
			};
		};
	};
	class arifle_Mk20_GL_F: mk20_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_556
			{
				iconPosition[] = {0,0.38};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.35,0.35};
				iconScale = 0.25;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.25};
				iconScale = 0.2;
			};
		};
	};
	class arifle_MXC_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.3};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.2,0.4};
				iconScale = 0.25;
			};
		};
	};
	class arifle_MX_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.35};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.2,0.45};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.2,0.7};
				iconScale = 0.2;
			};
		};
	};
	class arifle_MX_GL_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.35};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.2,0.45};
				iconScale = 0.25;
			};
		};
	};
	class arifle_MX_SW_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.35};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.2,0.45};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.2,0.7};
				iconScale = 0.2;
			};
		};
	};
	class arifle_MXM_F: arifle_MX_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.35};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.2,0.45};
				iconScale = 0.25;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.2,0.7};
				iconScale = 0.2;
			};
		};
	};
	class arifle_TRG21_F: Tavor_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_556
			{
				iconPosition[] = {0,0.4};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC_SHORT
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.25,0.4};
				iconScale = 0.25;
			};
		};
	};
	class arifle_TRG20_F: Tavor_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_556
			{
				iconPosition[] = {0.1,0.4};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC_SHORT
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.25,0.4};
				iconScale = 0.25;
			};
		};
	};
	class hgun_PDW2000_F: pdw2000_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_9MILSMG
			{
				iconPosition[] = {0.0,0.45};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.5,0.4};
				iconScale = 0.15;
			};
		};
	};
	class SMG_01_F: SMG_01_Base
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_45ACPSMG
			{
				iconPosition[] = {0.1,0.4};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.4,0.3};
				iconScale = 0.2;
			};
		};
	};
	class SMG_02_F: SMG_02_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_9MILSMG
			{
				iconPosition[] = {0.08,0.4};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.27};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.28,0.4};
				iconScale = 0.25;
			};
		};
	};
	class SMG_05_F: SMG_05_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_9MILSMG
			{
				iconPosition[] = {0.05,0.35};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.25,0.35};
				iconScale = 0.25;
			};
		};
	};
	class LMG_03_F: LMG_03_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_556
			{
				iconPosition[] = {0,0.4};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.57,0.28};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.38,0.42};
				iconScale = 0.25;
			};
		};
	};
	class srifle_DMR_07_blk_F: DMR_07_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC_LONG
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
		};
	};
	class srifle_DMR_07_hex_F: DMR_07_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC_LONG
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
		};
	};
	class srifle_DMR_07_ghex_F: DMR_07_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: DSR_JR_OPTIC_LONG
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
		};
	};
	class arifle_AK12_F: arifle_AK12_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_762
			{
				iconPosition[] = {0.0,0.35};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.3,0.35};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
			class UnderBarrelSlot: DSR_JR_UnderSlot
			{
				iconPosition[] = {0.35,0.7};
				iconScale = 0.3;
			};
		};
	};
	class arifle_AK12_GL_base_F: arifle_AK12_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class MuzzleSlot: DSR_JR_MUZZLE_762
			{
				iconPosition[] = {0.0,0.35};
				iconScale = 0.2;
			};
			class PointerSlot: DSR_JR_FrontSlot
			{
				iconPosition[] = {0.3,0.35};
				iconScale = 0.2;
			};
			class CowsSlot: DSR_JR_OPTIC
			{
				iconPosition[] = {0.45,0.28};
				iconScale = 0.2;
			};
		};
	};
};
