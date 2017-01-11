class CfgPatches
{
	class dsr_weapons
	{
		fileName = "dsr_weapons.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {"DSR_hgun_ACPC2","DSR_hgun_P07","DSR_hgun_PDW2000","DSR_hgun_Pistol_heavy_01","DSR_Pistol_heavy_02","DSR_hgun_Pistol_Signal","DSR_hgun_Rook","DSR_arifle_Katiba","DSR_arifle_Katiba_C","DSR_arifle_Katiba_GL","DSR_arifle_MXC","DSR_arifle_MXC_Black","DSR_arifle_MX","DSR_arifle_MX_Black","DSR_arifle_MX_GL","DSR_arifle_MX_GL_Black","DSR_arifle_MX_SW","DSR_arifle_MX_SW_Black","DSR_arifle_MXM","DSR_arifle_MXM_Black","DSR_SMG_01","DSR_SMG_02","DSR_LMG_Mk200","DSR_LMG_Zafir","DSR_MMG_01_hex","DSR_MMG_01_tan","DSR_MMG_02_camo","DSR_MMG_02_black","DSR_MMG_02_sand","DSR_srifle_DMR_01","DSR_srifle_DMR_02","DSR_srifle_DMR_02_camo","DSR_srifle_DMR_02_sniper","DSR_srifle_DMR_03","DSR_srifle_DMR_03_khaki","DSR_srifle_DMR_03_tan","DSR_srifle_DMR_03_multicam","DSR_srifle_DMR_03_woodland","DSR_srifle_DMR_04","DSR_srifle_DMR_04_Tan","DSR_srifle_DMR_05_blk","DSR_srifle_DMR_05_hex","DSR_srifle_DMR_05_tan","DSR_srifle_DMR_06_camo","DSR_srifle_DMR_06_olive","DSR_srifle_EBR","DSR_srifle_GM6","DSR_srifle_GM6_camo","DSR_srifle_LRR","DSR_srifle_LRR_camo"};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};
class CfgWeapons
{
	//--- import

	//Handguns
    class hgun_ACPC2_F;
	class hgun_P07_F;
    class hgun_PDW2000_F;
    class hgun_Pistol_heavy_01_F;
    class hgun_Pistol_heavy_02_F;
    class hgun_Pistol_Signal_F;
	class hgun_Rook40_F;
	//Assault Rifles
	class arifle_Katiba_F;
	class arifle_Katiba_C_F;
    class arifle_Katiba_GL_F;
    class arifle_MXC_F;
    class arifle_MXC_Black_F;
    class arifle_MX_F;
    class arifle_MX_Black_F;
    class arifle_MX_GL_F;
    class arifle_MX_GL_Black_F;
    class arifle_MX_SW_F;
    class arifle_MX_SW_Black_F;
    class arifle_MXM_F;
    class arifle_MXM_Black_F;
 	//Sub Machinguns
    class SMG_01_F;
    class SMG_02_F;
    //Light Machinguns
    class LMG_Mk200_F;
    class LMG_Zafir_F;
    class MMG_01_hex_F;
    class MMG_01_tan_F;
    class MMG_02_camo_F;
    class MMG_02_black_F;
    class MMG_02_sand_F;
    //Sniper Rifles
    class srifle_DMR_01_F;
    class srifle_DMR_02_F;
    class srifle_DMR_02_camo_F;
    class srifle_DMR_02_sniper_F;
    class srifle_DMR_03_F;
    class srifle_DMR_03_khaki_F;
    class srifle_DMR_03_tan_F;
    class srifle_DMR_03_multicam_F;
    class srifle_DMR_03_woodland_F;
    class srifle_DMR_04_F;
    class srifle_DMR_04_Tan_F;
    class srifle_DMR_05_blk_F;
    class srifle_DMR_05_hex_F;
    class srifle_DMR_05_tan_F;
    class srifle_DMR_06_camo_F;
    class srifle_DMR_06_olive_F;
    class srifle_EBR_F;
    class srifle_GM6_F;
    class srifle_GM6_camo_F;
    class srifle_LRR_F;
    class srifle_LRR_camo_F;
    //--- import end
	
	//--- Handguns
	class DSR_hgun_ACPC2 : hgun_ACPC2_F {
		_generalMacro = "DSR_hgun_ACPC2";
		displayName = "Old ACPC2";
		descriptionShort = "A ACPC2 from the old war.";
		description = "An old ACPC2 from the war between CSAT and NATO. This is one of the few that survived. It Fires .45 ACP.";
	};
	class DSR_hgun_P07 : hgun_P07_F {
		_generalMacro = "DSR_hgun_P07";
		displayName = "Old P07";
		descriptionShort = "A P07 from the old war.";
		description = "An old P07 from the war between CSAT and NATO. This is one of the few that survived.";
		inertia = 0.1;
		dexterity = 1.9;
		initSpeed = 410;
		maxZeroing = 100;
	};
	class DSR_hgun_PDW2000 : hgun_PDW2000_F {
		_generalMacro = "DSR_hgun_PDW2000";
		displayName = "Old PDW2000";
		descriptionShort = "A PDW2000 from the old war.";
		description = "An old PDW2000 from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_hgun_Pistol_heavy_01 : hgun_Pistol_heavy_01_F {
		_generalMacro = "DSR_hgun_Pistol_heavy_01";
		displayName = "Old 4-five";
		descriptionShort = "A 4-five from the old war.";
		description = "An old 4-five from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_Pistol_heavy_02 : hgun_Pistol_heavy_02_F {
		_generalMacro = "DSR_Pistol_heavy_02";
		displayName = "Old Zubr";
		descriptionShort = "A Zubr from the old war.";
		description = "An old Zubr from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_hgun_Pistol_Signal : hgun_Pistol_Signal_F {
		_generalMacro = "DSR_hgun_Pistol_Signal";
		displayName = "Old Starter Pistol";
		descriptionShort = "A Starter Pistol from the old war.";
		description = "An old Starter Pistol from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_hgun_Rook : hgun_Rook40_F {
		_generalMacro = "DSR_hgun_Rook";
		displayName = "Old Rook";
		descriptionShort = "A Rook 40 from the old war.";
		description = "An old Rook 40 from the war between CSAT and NATO. This is one of the few that survived.";
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = 450;
		maxZeroing = 100;
	};
	//--- rifles
	class DSR_arifle_Katiba : arifle_Katiba_F {
		_generalMacro = "DSR_arifle_Katiba";
		displayName = "Old Katiba";
		descriptionShort = "A Katiba from the old war.";
		description = "An old Katiba from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_Katiba_C : arifle_Katiba_C_F {
		_generalMacro = "DSR_arifle_Katiba_C";
		displayName = "Old Katiba Carbine";
		descriptionShort = "A Katiba Carbine from the old war.";
		description = "An old Katiba Carbine from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_Katiba_GL : arifle_Katiba_GL_F {
		_generalMacro = "DSR_arifle_Katiba_GL";
		displayName = "Old Katiba GL";
		descriptionShort = "A Katiba GL from the old war.";
		description = "An old Katiba GL from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MXC : arifle_MXC_F {
		_generalMacro = "DSR_arifle_MXC";
		displayName = "Old MXC";
		descriptionShort = "A MXC from the old war.";
		description = "An old MXC from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MXC_Black : arifle_MXC_Black_F {
		_generalMacro = "DSR_arifle_MXC_Black";
		displayName = "Old MXC Black";
		descriptionShort = "A MXC Black from the old war.";
		description = "An old MXC Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MX : arifle_MX_F {
		_generalMacro = "DSR_arifle_MX";
		displayName = "Old MX";
		descriptionShort = "A MX from the old war.";
		description = "An old MX from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MX_Black : arifle_MX_Black_F {
		_generalMacro = "DSR_arifle_MX_Black";
		displayName = "Old MX Black";
		descriptionShort = "A MX Black from the old war.";
		description = "An old MX Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MX_GL : arifle_MX_GL_F {
		_generalMacro = "DSR_arifle_MX_GL";
		displayName = "Old MX 3GL";
		descriptionShort = "A MX 3GL from the old war.";
		description = "An old MX 3GL from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MX_GL_Black : arifle_MX_GL_Black_F {
		_generalMacro = "DSR_arifle_MX_GL_Black";
		displayName = "Old MX 3GL Black";
		descriptionShort = "A MX 3GL Black from the old war.";
		description = "An old MX 3GL Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MX_SW : arifle_MX_SW_F {
		_generalMacro = "DSR_arifle_MX_SW";
		displayName = "Old MX SW";
		descriptionShort = "A MX SW from the old war.";
		description = "An old MX SW from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MX_SW_Black : arifle_MX_SW_Black_F {
		_generalMacro = "DSR_arifle_MX_SW_Black";
		displayName = "Old MX SW Black";
		descriptionShort = "A MX SW Black from the old war.";
		description = "An old MX SW Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MXM : arifle_MXM_F {
		_generalMacro = "DSR_arifle_MXM";
		displayName = "Old MXM";
		descriptionShort = "A MXM from the old war.";
		description = "An old MXM from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_arifle_MXM_Black : arifle_MXM_Black_F {
		_generalMacro = "DSR_arifle_MXM_Black";
		displayName = "Old MXM Black";
		descriptionShort = "A MXM Black from the old war.";
		description = "An old MXM Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	//--- Sub Machineguns
	class DSR_SMG_01 : SMG_01_F {
		_generalMacro = "DSR_SMG_01";
		displayName = "Old Vermin";
		descriptionShort = "A Vermin from the old war.";
		description = "An old Vermin from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_SMG_02 : SMG_02_F {
		_generalMacro = "DSR_SMG_02";
		displayName = "Old Sting";
		descriptionShort = "A Sting from the old war.";
		description = "An old Sting from the war between CSAT and NATO. This is one of the few that survived.";
	};
	//--- Light Machineguns
	class DSR_LMG_Mk200 : LMG_Mk200_F {
		_generalMacro = "DSR_LMG_Mk200";
		displayName = "Old Mk200";
		descriptionShort = "A Mk200 from the old war.";
		description = "An old Mk200 from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_LMG_Zafir : LMG_Zafir_F {
		_generalMacro = "DSR_LMG_Zafir";
		displayName = "Old Zafir";
		descriptionShort = "A Zafir from the old war.";
		description = "An old Zafir from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_MMG_01_hex : MMG_01_hex_F {
		_generalMacro = "DSR_MMG_01_hex";
		displayName = "Old Navid Hex";
		descriptionShort = "A Navid Hex from the old war.";
		description = "An old Navid Hex from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_MMG_01_tan : MMG_01_tan_F {
		_generalMacro = "DSR_MMG_01_tan";
		displayName = "Old Navid Tan";
		descriptionShort = "A Navid Tan from the old war.";
		description = "An old Navid Tan from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_MMG_02_camo : MMG_02_camo_F {
		_generalMacro = "DSR_MMG_02_camo";
		displayName = "Old SPMG Camo";
		descriptionShort = "A SPMG Camo from the old war.";
		description = "An old SPMG Camo from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_MMG_02_black : MMG_02_black_F {
		_generalMacro = "DSR_MMG_02_black";
		displayName = "Old SPMG Black";
		descriptionShort = "A SPMG Black from the old war.";
		description = "An old SPMG Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_MMG_02_sand : MMG_02_sand_F {
		_generalMacro = "DSR_MMG_02_sand";
		displayName = "Old SPMG Sand";
		descriptionShort = "A SPMG Sand from the old war.";
		description = "An old SPMG Sand from the war between CSAT and NATO. This is one of the few that survived.";
	};
	//--- Sniper Rifles
	class DSR_srifle_DMR_01 : srifle_DMR_01_F {
		_generalMacro = "DSR_srifle_DMR_01";
		displayName = "Old Rahim";
		descriptionShort = "A Rahim from the old war.";
		description = "An old Rahim from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_02 : srifle_DMR_02_F {
		_generalMacro = "DSR_srifle_DMR_02";
		displayName = "Old MAR-10";
		descriptionShort = "A MAR-10 from the old war.";
		description = "An old MAR-10 from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_02_camo : srifle_DMR_02_camo_F {
		_generalMacro = "DSR_srifle_DMR_02_camo";
		displayName = "Old MAR-10 Camo";
		descriptionShort = "A MAR-10 Camo from the old war.";
		description = "An old MAR-10 Camo from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_02_sniper : srifle_DMR_02_sniper_F {
		_generalMacro = "DSR_srifle_DMR_02_sniper";
		displayName = "Old MAR-10 Sand";
		descriptionShort = "A MAR-10 Sand from the old war.";
		description = "An old MAR-10 Sand from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_03 : srifle_DMR_03_F {
		_generalMacro = "DSR_srifle_DMR_03";
		displayName = "Old Mk-I EMR";
		descriptionShort = "A Mk-I EMR from the old war.";
		description = "An old Mk-I EMR from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_03_khaki : srifle_DMR_03_khaki_F {
		_generalMacro = "DSR_srifle_DMR_03_khaki";
		displayName = "Old Mk-I EMR Khaki";
		descriptionShort = "A Mk-I EMR Khaki from the old war.";
		description = "An old Mk-I EMR Khaki from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_03_tan : srifle_DMR_03_tan_F {
		_generalMacro = "DSR_srifle_DMR_03_tan";
		displayName = "Old Mk-I EMR Tan";
		descriptionShort = "A Mk-I EMR Tan from the old war.";
		description = "An old Mk-I EMR Tan from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_03_multicam : srifle_DMR_03_multicam_F {
		_generalMacro = "DSR_srifle_DMR_03_multicam";
		displayName = "Old Mk-I EMR Camo";
		descriptionShort = "A Mk-I EMR Camo from the old war.";
		description = "An old Mk-I EMR Camo from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_03_woodland : srifle_DMR_03_woodland_F {
		_generalMacro = "DSR_srifle_DMR_03_woodland";
		displayName = "Old Mk-I EMR Woodland";
		descriptionShort = "A Mk-I EMR Woodland from the old war.";
		description = "An old Mk-I EMR Woodland from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_04 : srifle_DMR_04_F {
		_generalMacro = "DSR_srifle_DMR_04";
		displayName = "Old ASP-1 Kir";
		descriptionShort = "A ASP-1 Kir from the old war.";
		description = "An old ASP-1 Kir from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_04_Tan : srifle_DMR_04_Tan_F {
		_generalMacro = "DSR_srifle_DMR_04_Tan";
		displayName = "Old ASP-1 Kir Tan";
		descriptionShort = "A ASP-1 Kir Tan from the old war.";
		description = "An old ASP-1 Kir Tan from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_05_blk : srifle_DMR_05_blk_F {
		_generalMacro = "DSR_srifle_DMR_05_blk";
		displayName = "Old Cyrus Black";
		descriptionShort = "A Cyrus Black from the old war.";
		description = "An old Cyrus Black from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_05_hex : srifle_DMR_05_hex_F {
		_generalMacro = "DSR_srifle_DMR_05_hex";
		displayName = "Old Cyrus Hex";
		descriptionShort = "A Cyrus Hex from the old war.";
		description = "An old Cyrus Hex from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_05_tan : srifle_DMR_05_tan_F {
		_generalMacro = "DSR_srifle_DMR_05_tan";
		displayName = "Old Cyrus Tan";
		descriptionShort = "A Cyrus Tan from the old war.";
		description = "An old Cyrus Tan from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_06_camo : srifle_DMR_06_camo_F {
		_generalMacro = "DSR_srifle_DMR_06_camo";
		displayName = "Old Mk14 Camo";
		descriptionShort = "A Mk14 Camo from the old war.";
		description = "An old Mk14 Camo from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_DMR_06_olive : srifle_DMR_06_olive_F {
		_generalMacro = "DSR_srifle_DMR_06_olive";
		displayName = "Old Mk14 Olive";
		descriptionShort = "A Mk14 Olive from the old war.";
		description = "An old Mk14 Olive from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_EBR : srifle_EBR_F {
		_generalMacro = "DSR_srifle_EBR";
		displayName = "Old EBR";
		descriptionShort = "A EBR from the old war.";
		description = "An old EBR from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_GM6 : srifle_GM6_F {
		_generalMacro = "DSR_srifle_GM6";
		displayName = "Old Lynx";
		descriptionShort = "A Lynx from the old war.";
		description = "An old Lynx from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_GM6_camo : srifle_GM6_camo_F {
		_generalMacro = "DSR_srifle_GM6_camo";
		displayName = "Old Lynx Camo";
		descriptionShort = "A Lynx Camo from the old war.";
		description = "An old Lynx Camo from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_LRR : srifle_LRR_F {
		_generalMacro = "DSR_srifle_LRR";
		displayName = "Old M320 LRR";
		descriptionShort = "A M320 LRR from the old war.";
		description = "An old M320 LRR from the war between CSAT and NATO. This is one of the few that survived.";
	};
	class DSR_srifle_LRR_camo : srifle_LRR_camo_F {
		_generalMacro = "DSR_srifle_LRR_camo";
		displayName = "Old M320 LRR Camo";
		descriptionShort = "A M320 LRR Camo from the old war.";
		description = "An old M320 LRR Camo from the war between CSAT and NATO. This is one of the few that survived.";
	};
};