class CfgPatches
{
	class DS_DESOLATION_REDUX
	{
		fileName = "desolationredux.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Ui_F","A3_Functions_F","A3_UiFonts_F"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};
class CfgEditorCategories
{
	class EdCat_Desolation {
		displayName = "Desolation Redux";
	};
};
class CfgEditorSubcategories
{
	class EdSubcat_Desolation {
		displayName = "Desolation Redux";
	};
};
class CfgCrafting
{
	class DS_Crafting_Recipe
	{
		displayName = "";//Crafted Object Name
		picture = "";
		DSRequiredItems[] = 
		{
			{"DS_Inv_Rock_01",2}, //2 of single item needed
			{"DS_Inv_Tinder",1} // single item, single qty
		};
	};
	class DS_BottleMilk
	{
		displayName = "Plastic Bottle of Milk";
		picture = "";
		DSRequiredItems[] = 
		{
			{"DS_Drink_PlasticBottle_Wet",1}, 
			{"DS_Inv_PowderedMilk",1} 
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class DS_InvItem: CA_Magazine
	{
		author = "Desolation Redux Dev Team";
		scope = 2;
		displayName = "Desolation Item";
		picture = "";	//--fill in with desolation logo :)
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		descriptionShort = "Desolation Assets";
		descriptionUse = "Describe DS Item's Use";
		mass = 5;
		DSInventoryItemType = "sleeping"; // Item type for the handler to pass proper info
		DSObjectName = "DS_Obj_SleepingBag_Khaki"; // Buildables use this option 
		DSHealthAdjustment[] = // Adjustments to health vars when using/consuming items
		{
			0.00,// Health
			0.00,// Food
			0.00,// Drink
			0.00,// Blood
			0.00,// Blood Pressure
			0.00,// Temperature
			0.00,// Infection
			0.00,// Wet
			0.00,// Soiled
			0.00// Sanity
		};
		DSCraftedObjects[] = // Crafting recipes will check this on what to give you back
		{
			"DS_Obj_FirePit_Rock"
		};	
		DSUsedItem = "";// Item to return to player after using the FoodDrink item
	};
//Desolation Sleeping and Health Related Items
	class DS_Inv_SleepingBag_Khaki: DS_InvItem {
		displayName = "Rolled Sleeping Bag(Khaki)";
		descriptionShort = "Use this to rest up and gain some health";
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_folded_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Sleeping_bag_folded_F.jpg";
		mass = 10;
		DSInventoryItemType = "sleeping";
		DSObjectName = "DS_Obj_SleepingBag_Khaki";
	};
	class DS_Inv_SleepingBag_Blue: DS_Inv_SleepingBag_Khaki {
		displayName = "Rolled Sleeping Bag(Blue)";
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_blue_folded_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Sleeping_bag_blue_folded_F.jpg";
		DSInventoryItemType = "sleeping";
		DSObjectName = "DS_Obj_SleepingBag_Blue";
	};
	class DS_Inv_SleepingBag_Brown: DS_Inv_SleepingBag_Khaki {
		displayName = "Rolled Sleeping Bag(Brown)";
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_brown_folded_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Sleeping_bag_brown_folded_F.jpg";
		DSInventoryItemType = "sleeping";
		DSObjectName = "DS_Obj_SleepingBag_Brown";
	};
	class DS_Medical_Antibiotic: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Box of Antibiotics";
		descriptionShort = "Get a bottle of water and consume both to help fight your sickness.";
		model = "\A3\Structures_F_EPA\Items\Medical\Antibiotic_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Antibiotic_F.jpg";
		mass = 10;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_Bandage: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Sterile Medical Bandage";
		descriptionShort = "Use this to clot a strong bleed or to cover a wound to prevent infection.";
		model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Bandage_F.jpg";
		mass = 10;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_BloodBag_typeO: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "BloodBag - Type O";
		descriptionShort = "Use this to replenish your blood. Do not use the wrong blood type in fear of your body rejecting the transfusion and the infection taking control of you!";
		model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BloodBag_F.jpg";
		mass = 25;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_BloodBag_typeA: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "BloodBag - Type A";
		descriptionShort = "Use this to replenish your blood. Do not use the wrong blood type in fear of your body rejecting the transfusion and the infection taking control of you!";
		model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BloodBag_F.jpg";
		mass = 25;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_BloodBag_typeB: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "BloodBag - Type B";
		descriptionShort = "Use this to replenish your blood. Do not use the wrong blood type in fear of your body rejecting the transfusion and the infection taking control of you!";
		model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BloodBag_F.jpg";
		mass = 25;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_BloodBag_typeAB: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "BloodBag - Type AB";
		descriptionShort = "Use this to replenish your blood. Do not use the wrong blood type in fear of your body rejecting the transfusion and the infection taking control of you!";
		model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BloodBag_F.jpg";
		mass = 25;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_BloodBag_infected: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "BloodBag - Unmarked";
		descriptionShort = "This is an unmarked BloodBag, take your chances but be cautious of symptoms afterward....";
		model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BloodBag_F.jpg";
		mass = 25;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_Defibrillator: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Defib Machine";
		descriptionShort = "I hope the batteries in this thing hold out for when we need it!";
		model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Defibrillator_F.jpg";
		mass = 70;
	};
	class DS_Medical_DisinfectantSpray: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Disinfectant Spray";
		descriptionShort = "This will help keep your wounds infection free";
		model = "\A3\Structures_F_EPA\Items\Medical\DisinfectantSpray_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_DisinfectantSpray_F.jpg";
		mass = 20;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_HeatPack: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Heat Pack(single)";
		descriptionShort = "This will help keep you warm on those cold nights. Also use this to reduce hypothermia symptoms faster.";
		model = "\A3\Structures_F_EPA\Items\Medical\HeatPack_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_HeatPack_F.jpg";
		mass = 5;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_Painkillers: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Painkillers";
		descriptionShort = "This will help keep the pain at bay while you find the proper medical attention.";
		model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_PainKillers_F.jpg";
		mass = 5;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_VitaminBottle: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Vitamins";
		descriptionShort = "This will help keep the pain at bay while you find the proper medical attention.";
		model = "\A3\Structures_F_EPA\Items\Medical\VitaminBottle_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_VitaminBottle_F.jpg";
		mass = 5;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
	};
	class DS_Medical_WaterPurificationTablets: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Water Purification Tablets";
		descriptionShort = "Get some water and mix in these tablets for the cleanest water around!";
		model = "\A3\Structures_F_EPA\Items\Medical\WaterPurificationTablets_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_WaterPurificationTablets_F.jpg";
		mass = 15;
	};
//Desolation Food and Drink Items
	class DS_Drink_Canteen_Dry: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Canteen - Empty";
		descriptionShort = "Make sure to keep this filled at all times.";
		model = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Canteen_F.jpg";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Grinder_F.jpg";
		mass = 15;
		DSInventoryItemType = "fooddrink";
		DSCraftedObjects[] = {"DS_Drink_Canteen_Wet"};
	};
	class DS_Drink_Canteen_Wet: DS_Drink_Canteen_Dry {
		author = "Desolation Redux Dev Team";
		displayName = "Canteen with Liquid";
		descriptionShort = "Make sure to drink from this wisely. Fire and a boiling pot will be needed to refill this with fresh water";
		model = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Canteen_F.jpg";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Grinder_F.jpg";
		mass = 30;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,40.00,0.00,0.00,-0.03,-0.50,0.00,0.00,0.00};//+40 drink -0.03 temperature -0.5 infection
		DSUsedItem = "DS_Drink_Canteen_Dry";
	};
	class DS_Drink_PlasticBottle_Dry: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Plastic Bottle (Empty)";
		descriptionShort = "Save these for filling and storing with fresh water.";
		model = "\A3\Structures_F_EPA\Items\Food\BottlePlastic_V2_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BottlePlastic_V2_F.jpg";
		mass = 30;
		DSInventoryItemType = "fooddrink";
		DSCraftedObjects[] = {"DS_Drink_PlasticBottle_Wet","DS_Drink_PlasticBottle_Milk"};
	};
	class DS_Drink_PlasticBottle_Wet: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Plastic Bottle (Wet)";
		descriptionShort = "Make sure to stock up on fresh water for the Desolate Future you will endure";
		model = "\A3\Structures_F_EPA\Items\Food\BottlePlastic_V2_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BottlePlastic_V2_F.jpg";
		mass = 30;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,30.00,0.00,0.00,-0.03,-0.50,0.00,0.00,0.00};//+30 drink -0.03 temperature -0.5 infection
		DSUsedItem = "DS_Drink_PlasticBottle_Dry";
	};
	class DS_Drink_PlasticBottle_Milk: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Plastic Bottle (Milk)";
		descriptionShort = "You were fortunate to find such a tasty and healthy drink";
		model = "\A3\Structures_F_EPA\Items\Food\BottlePlastic_V2_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_BottlePlastic_V2_F.jpg";
		mass = 30;
		DSInventoryItemType = "fooddrink";
		DSHealthAdjustment[] = {0.00,0.00,60.00,0.00,0.00,0.00,-1.00,0.00,0.00,0.00};
		DSUsedItem = "DS_Drink_PlasticBottle_Dry";
	};
	class DS_Inv_PowderedMilk: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Packet of Powdered Milk";
		descriptionShort = "Get a bottle of water and mix these together! I would not eat this powder...";
		model = "\A3\Structures_F_EPA\Items\Food\PowderedMilk_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_PowderedMilk_F.jpg";
		mass = 5;
	};
//Desolation Toolbox Items and Crafting Requirements
	class DS_Tool_Grinder: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Electric Grinder";
		descriptionShort = "Many great uses for a grinder during these hard times";
		model = "\A3\Structures_F\Items\Tools\Grinder_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Grinder_F.jpg";
		mass = 30;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Drill: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Electric Drill";
		descriptionShort = "Many great uses for a drill during these hard times";
		model = "\A3\Structures_F\Items\Tools\DrillAku_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_DrillAku_F.jpg";
		mass = 35;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_DustMask: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Dust Mask";
		descriptionShort = "Protect yourself from the Contagions of this world";
		model = "\A3\Structures_F\Items\Tools\DustMask_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_DustMask_F.jpg";
		mass = 5;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Hammer: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Hammer";
		descriptionShort = "Build your little heart out!";
		model = "\A3\Structures_F\Items\Tools\Hammer_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Hammer_F.jpg";
		mass = 15;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_MultiMeter: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Multi-Meter";
		descriptionShort = "Diagnose those electrical issues and paranormal phenomenons!";
		model = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_MultiMeter_F.jpg";
		mass = 10;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Pliers: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Multi-Meter";
		descriptionShort = "Diagnose those electrical issues and paranormal phenomenons!";
		model = "\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pliers_F.jpg";
		mass = 10;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Saw: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Hand Saw";
		descriptionShort = "Cut through the toughest of problems with this manual hand saw.";
		model = "\A3\Structures_F\Items\Tools\Saw_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Saw_F.jpg";
		mass = 20;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_PhilipsScrewDriver: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Screw Driver (Philips)";
		descriptionShort = "Screw that shit down tight, but dont strip them grooves....";
		model = "\A3\Structures_F\Items\Tools\Screwdriver_V2_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Screwdriver_V2_F.jpg";
		mass = 10;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_FlatScrewDriver: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Screw Driver (FlatHead)";
		descriptionShort = "This is why I think the inventor of the Flat Head screw driver was just fucking with us.";
		model = "\A3\Structures_F\Items\Tools\Screwdriver_V1_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Screwdriver_V1_F.jpg";
		mass = 10;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Wrench: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Wrench (Monkey)";
		descriptionShort = "What good is a dam wrench without the MONKEY? Use this to make tight connections with your buildables.";
		model = "\A3\Structures_F\Items\Tools\Wrench_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Wrench_F.jpg";
		mass = 10;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_ButaneCanister: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Butane Refill";
		descriptionShort = "This is the gas needed to have a torch";
		model = "\A3\Structures_F_EPA\Items\Tools\ButaneCanister_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_ButaneCanister_F.jpg";
		mass = 50;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_ButaneTorch: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Butane Torch Tip";
		descriptionShort = "Just get yourself a Canister of Butane to complete this Torch";
		model = "\A3\Structures_F_EPA\Items\Tools\ButaneTorch_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_ButaneTorch_F.jpg";
		mass = 25;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_DuctTape: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "HVAC Pro DuctTape";
		descriptionShort = "Duct Tape, for any job any time any where!";
		model = "\A3\Structures_F_EPA\Items\Tools\DuctTape_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_DuctTape_F.jpg";
		mass = 10;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_FireExtinguisher: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Fire Extinguisher";
		descriptionShort = "You never know when your shits gonna be on fire!";
		model = "\A3\Structures_F_EPA\Items\Tools\FireExtinguisher_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_FireExtinguisher_F.jpg";
		mass = 35;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Matches: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Box of Matches";
		descriptionShort = "You never know when you wanna set shit on fire!";
		model = "\A3\Structures_F_EPA\Items\Tools\Matches_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Matches_F.jpg";
		mass = 5;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Shovel: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Shovel";
		descriptionShort = "You never know when you wanna set shit on fire!";
		model = "\A3\Structures_F_EPA\Items\Tools\Shovel_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Shovel_F.jpg";
		mass = 75;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_Axe: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Axe";
		descriptionShort = "You never know when you wanna set shit on fire!";
		model = "\A3\Structures_F\Items\Tools\Axe_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		mass = 75;
		DSInventoryItemType = "toolbox";
	};
	class DS_Tool_FireAxe: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Firemans Axe";
		descriptionShort = "You never know when you wanna set shit on fire!";
		model = "\A3\Structures_F\Items\Tools\Axe_fire_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_fire_F.jpg";
		mass = 75;
		DSInventoryItemType = "toolbox";
	};
//Desolation Misc Crafting Components
	class DS_Inv_Rock_01: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Small Rock";
		descriptionShort = "Use this to make craftables";
		model = "\A3\Rocks_F\Small_Stone_01_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Small_Stone_01_F.jpg";
		DSInventoryItemType = "craftables";
		DSCraftedObjects[] = {"DS_Obj_FirePit_Rock"};
	};
	class DS_Inv_Rock_02: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Small Rock";
		descriptionShort = "Use this to make craftables";
		model = "\A3\Rocks_F\Small_Stone_02_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Small_Stone_02_F.jpg";
		DSInventoryItemType = "craftables";
		DSCraftedObjects[] = {"DS_Obj_FirePit_Rock"};
	};
	class DS_Inv_WoodenLog: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Wood Log";
		descriptionShort = "There are many uses for wood in this hard up world!";
		model = "\A3\Structures_F_EPA\Civ\Camping\WoodenLog_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_WoodenLog_F.jpg";
		DSInventoryItemType = "craftables";
		DSCraftedObjects[] = {"DS_Obj_FirePit_Rock"};
		//example DSRequiredCraftingItems[] = {"DS_Inv_Rock_01","DS_Inv_Rock_02"};
	};
	class DS_Inv_GasCanister: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Gas Canister";
		descriptionShort = "Use this with a Gas Cooker for some home cooked meals.";
		model = "\A3\Structures_F_EPA\Items\Tools\GasCanister_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_GasCanister_F.jpg";
		DSInventoryItemType = "craftables";
		DSCraftedObjects[] = {"DS_Obj_GasCooker"};//Make cooking pot with gas composition
		DSRequiredCraftingItems[] = {"DS_Inv_GasCooker"};
	};
	class DS_Inv_GasCooker: DS_InvItem {
		author = "Desolation Redux Dev Team";
		displayName = "Gas Cooker";
		descriptionShort = "Use this with a Gas Canister for some home cooked meals.";
		model = "\A3\Structures_F_EPA\Items\Tools\GasCanister_F.p3d";
		picture = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_GasCanister_F.jpg";
		DSInventoryItemType = "craftables";
		DSCraftedObjects[] = {"DS_Obj_GasCooker"};//Make cooking pot with gas composition
		DSRequiredCraftingItems[] = {"DS_Inv_GasCanister"};
	};
};
class DesolationActions
{
	displayNameDefault = "ActionBase";
	displayName = "ActionBase";
	position = "";
	priority = 1.5;
	radius = 3;
	onlyForPlayer = 0;
	condition = "";
	statement = "hint 'ActionBase'";
};

class SmallFire;
class CfgVehicles
{
	class House_F;
	class House_Small_F;
	class NonStrategic;
	class ThingX;
	class Item_Base_F;
	class DS_Buildable_Object: NonStrategic {
		scope = 2;
		author = "Desolation Redux Dev Team";
		mapSize = 1;
		armor = 10000;
		cost = 2500;
		model = "";
		icon = "iconObject_1x1";
		destrType = "DestructNo";
		vehicleclass = "Desolation_Buildable_Objects";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		DSisBuildableObject = 1;
		DSBuildableType = "object";
	};
	class DS_Buildable_Sleeping: NonStrategic {
		scope = 2;
		author = "Desolation Redux Dev Team";
		mapSize = 1;
		armor = 10000;
		cost = 2500;
		model = "";
		icon = "iconObject_1x1";
		destrType = "DestructNo";
		vehicleclass = "Desolation";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		DSisSleepingObject = 1;//-for condition checks?
		DSBuildableType = "sleeping";
	};
	class DS_Buildable_Crafting: NonStrategic {
		scope = 2;
		author = "Desolation Redux Dev Team";
		mapSize = 1;
		armor = 10000;
		cost = 2500;
		model = "";
		icon = "iconObject_1x1";
		destrType = "DestructNo";
		vehicleclass = "Desolation_Buildable_Objects";
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		DSisUsedInCraftingRecipes = 1;
		DSBuildableType = "crafting";
	};
//--this section for the built objects in game
	class DS_Obj_FirePit_Rock: DS_Buildable_Crafting {
		author = "Desolation Redux Dev Team";
		mapSize = 1.03;
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_FirePlace_F.jpg";
		_generalMacro = "Land_FirePlace_F";
		scope = 2;
		scopeCurator = 2;
		displayName = "Rock Fire Pit";
		model = "\A3\Structures_F\Civ\Camping\Fireplace_F.p3d";
		icon = "iconObject_circle";
		editorCategory = "EdCat_Desolation";
		editorSubcategory = "EdSubcat_Camping";		
		vehicleClass = "DesolationObjects";
		destrType = "DestructNo";
		simulation = "fire";
		cost = 100;
		keepHorizontalPlacement = 0;
		class UserActions{
			class warmup: DesolationActions
			{
				displayNameDefault = "Warm Up";
				displayName = "Warm Yourself UP";
				position = "ohniste";
				condition = "(inflamed this)";
				statement = "hint 'placeholder for temp system feature'";
			};
			class cookmeat: DesolationActions
			{
				displayNameDefault = "Cook Meat";
				displayName = "Cook Meat";
				position = "ohniste";
				condition = "(inflamed this)";
				statement = "hint 'another placeholder'";
			};
			class boilwater: DesolationActions
			{
				displayNameDefault = "Boil Water";
				displayName = "Boil Water";
				position = "ohniste";
				condition = "(inflamed this)";
				statement = "hint 'another placeholder'";
			};
		};
		actionBegin1 = "lightfire";
		actionEnd1 = "lightfire";
		actionBegin2 = "extinguishfire";
		actionEnd2 = "extinguishfire";
		actionBegin3 = "warmup";
		actionEnd3 = "warmup";
		actionBegin4 = "cookmeat";
		actionEnd4 = "cookmeat";
		actionBegin5 = "boilwater";
		actionEnd5 = "boilwater";
		class DestructionEffects {
			class Smoke1 {
				simulation = "particles";
				type = "HouseDestructionSmoke3";
				position = "destructionEffect1";
				qualityLevel = 2;
				intensity = 0.15;
				interval = 1;
				lifeTime = 0.05;
			};
			class Smoke2 : Smoke1 {
				type = "HouseDestructionSmoke4";
				lifeTime = 0.035;
				simulation = "particles";
				position = "destructionEffect1";
				qualityLevel = 2;
				intensity = 0.15;
				interval = 1;
			};
			class Smoke3 : Smoke1 {
				type = "HouseDestrSmokeLong";
				lifeTime = 0.035;
				simulation = "particles";
				position = "destructionEffect1";
				qualityLevel = 2;
				intensity = 0.15;
				interval = 1;
			};
			class Smoke1Med {
				simulation = "particles";
				type = "HouseDestructionSmoke3Med";
				position = "destructionEffect1";
				qualityLevel = 1;
				intensity = 0.15;
				interval = 1;
				lifeTime = 0.05;
			};
			class Smoke2Med : Smoke1Med {
				type = "HouseDestructionSmoke4Med";
				lifeTime = 0.035;
				simulation = "particles";
				position = "destructionEffect1";
				qualityLevel = 1;
				intensity = 0.15;
				interval = 1;
			};
			class Smoke3Med : Smoke1Med {
				type = "HouseDestrSmokeLongMed";
				lifeTime = 0.035;
				simulation = "particles";
				position = "destructionEffect1";
				qualityLevel = 1;
				intensity = 0.15;
				interval = 1;
			};
			class Smoke1Low {
				simulation = "particles";
				type = "HouseDestructionSmoke3Low";
				position = "destructionEffect1";
				qualityLevel = 0;
				intensity = 0.15;
				interval = 1;
				lifeTime = 0.05;
			};
			class Smoke2Low : Smoke1Low {
				type = "HouseDestructionSmoke4Low";
				lifeTime = 0.035;
				simulation = "particles";
				position = "destructionEffect1";
				qualityLevel = 0;
				intensity = 0.15;
				interval = 1;
			};
			class Smoke3Low : Smoke1Low {
				type = "HouseDestrSmokeLongLow";
				lifeTime = 0.035;
				simulation = "particles";
				position = "destructionEffect1";
				qualityLevel = 0;
				intensity = 0.15;
				interval = 1;
			};
			class Sound {
				simulation = "sound";
				type = "DestrHouse";
				position = "destructionEffect1";
				intensity = 1;
				interval = 1;
				lifeTime = 0.125;
			};
			class DestroyPhase1 {
				simulation = "destroy";
				type = "DelayedDestruction";
				lifeTime = 2.5;
				position = "";
				intensity = 1;
				interval = 1;
			};
			class DamageAround1 {
				simulation = "damageAround";
				type = "DamageAroundHouse";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class Effects: SmallFire{
			class Light1
			{
				simulation = "light";
				type = "SmallFirePlaceLight";
			};
			class sound
			{
				simulation = "sound";
				type = "Fire_camp_small";
			};
			class Smoke1
			{
				simulation = "particles";
				type = "SmallFireS";
			};
			class Fire1: Smoke1
			{
				simulation = "particles";
				type = "SmallFireFPlace";
			};
			class Refract1
			{
				simulation = "particles";
				type = "SmallFireFRefract";
			};
		};
	};
	class DS_Obj_SleepingBag_Khaki: DS_Buildable_Sleeping {
		author = "Desolation Redux Dev Team";
		displayName = "Opened Sleeping Bag(Khaki)";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Sleeping_bag_F.jpg";
		_generalMacro = "Land_Sleeping_bag_F";
		scope = 2;
		scopeCurator = 2;
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_F.p3d";
		DSisSleepingObject = 1;//-for condition checks?
		vehicleClass = "";
		icon = "iconObject_1x2";
		destrType = "DestructNo";
		class UserActions{
			
		};
	};
	class DS_Obj_SleepingBag_Blue: DS_Buildable_Sleeping {
		author = "Desolation Redux Dev Team";
		displayName = "Opened Sleeping Bag(Blue)";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Sleeping_bag_blue_F.jpg";
		_generalMacro = "Land_Sleeping_bag_blue_F";
		scope = 2;
		scopeCurator = 2;
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_blue_F.p3d";
		DSisSleepingObject = 1;//-for condition checks?
		vehicleClass = "DesolationObjects";
		editorCategory = "EdCat_Desolation";
		editorSubcategory = "EdSubcat_Camping";
		icon = "iconObject_1x2";
		destrType = "DestructNo";
		class UserActions{
			
		};
	};
	class DS_Obj_SleepingBag_Brown: DS_Buildable_Sleeping {
		author = "Desolation Redux Dev Team";
		displayName = "Opened Sleeping Bag(Brown)";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Sleeping_bag_brown_F.jpg";
		_generalMacro = "Land_Sleeping_bag_brown_F";
		scope = 2;
		scopeCurator = 2;
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_brown_F.p3d";
		DSisSleepingObject = 1;//-for condition checks?
		vehicleClass = "DesolationObjects";
		editorCategory = "EdCat_Desolation";
		editorSubcategory = "EdSubcat_Camping";
		icon = "iconObject_1x2";
		destrType = "DestructNo";
		class UserActions{
			
		};
	};	
};

//TODO
class CfgLiveStats {};



