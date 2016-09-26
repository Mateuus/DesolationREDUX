class CfgPatches
{
	class dsr_weapons
	{
		fileName = "dsr_weapons.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {"DSR_hgun_P07","DSR_hgun_Rook"};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};
class CfgWeapons
{
	 //--- import
	class hgun_P07_F;
	class hgun_Rook40_F;
	class arifle_Katiba_F;
	
	//--- Handguns
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
	class DSR_hgun_Rook : hgun_Rook40_F {
		_generalMacro = "DSR_hgun_Rook";
		displayName = "Old Rook";
		descriptionShort = "A rook 40 from the old war.";
		description = "An old rook 40 from the war between CSAT and NATO. This is one of the few that survived.";
		inertia = 0.2;
		dexterity = 1.8;
		initSpeed = 450;
		maxZeroing = 100;
	};
	
	//--- rifles
	class DSR_arifle_Katiba : arifle_Katiba_F {
		_generalMacro = "DSR_arifle_Katiba";
		displayName = "Old Katiba";
		descriptionShort = "A katiba 40 from the old war.";
		description = "An old katiba 40 from the war between CSAT and NATO. This is one of the few that survived.";
	};
};