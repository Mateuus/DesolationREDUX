/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

/*
	Quick N Dirty
*/
class CfgPatches
{
	class dsr_items
	{
		fileName = "dsr_items.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Weapons_F","A3_Characters_F", "dsr_actions"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author = "Desolation Redux Dev Team";
	};
};
class CfgWeapons 
{
	class U_C_Poloshirt_stripped; //import
	class U_C_DSR_Tester: U_C_Poloshirt_stripped 
	{
		scope = 2;
		author = "Desolation Redux";
		displayName = "Desolation Tester Uniform";
		hiddenSelectionsTextures[] = {"\dsr_ui\Assets\alpha_tester_shirt_co.paa"};
	};
};
class CfgVehicles 
{
	class C_man_polo_3_F;
	class C_man_p_beggar_F: C_man_polo_3_F 
	{
		model = "\A3\Characters_F\Civil\c_poloshirt";
		uniformClass = "U_C_DSR_Tester";
		hiddenSelections[] = {"Camo", "insignia"};
		hiddenSelectionsTextures[] = {"\dsr_ui\Assets\alpha_tester_shirt_co.paa"};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class dsr_item_base : CA_Magazine 
	{
		author = "Desolation Redux Dev Team";
		scope = 1;
		displayName = "Desolation Item";
		picture = "\dsr_ui\Assets\logo.paa";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		descriptionShort = "Desolation Item - UNDEFINED DESCRIPTION";
		descriptionUse = "Desolation Item - UNDEFINED USE";
		editorSubcategory = "dsr_items";
		icon = "iconObject_4x1";
		mass = 5;
		count = 1;
	};
	
	//--- DSR Items
		//--- Vehicle Parts
	class dsr_item_engineblock: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Engine Block";
		model = "\dsr_items\engine_repair\engine_repair.p3d";
		mass = 150;
	};
	class dsr_item_gastank: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Gas Tank";
		model = "\dsr_items\vehicle_gas_tank\vehicle_gas_tank.p3d";
		mass = 100;
	};
	class dsr_items_glasspart: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Vehicle Glass";
		model = "\dsr_items\materials\dsr_part_glass.p3d";
		mass = 100;
	};
	class dsr_item_tirepart: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Tire Repair";
		model = "\dsr_items\tire_part\tire_part.p3d";
		mass = 100;
	};
	class dsr_item_spanner: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Spanner Wrench";
		model = "\dsr_items\spanner\spanner.p3d";
		mass = 5;
	};
	class dsr_item_saw: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Saw";
		model = "\dsr_items\saw\saw.p3d";
		mass = 5;
	};
	class dsr_item_toolbox: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Toolbox";
		model = "\dsr_items\tools\dsr_toolbox.p3d";
		mass = 10;
	};
		//--- Medical
	class dsr_item_splint: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Splint";
		model = "\dsr_items\medical\splint\dsr_splint.p3d";
		mass = 5;
	};
	class dsr_item_new_bandage: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Bandage";
		model = "\dsr_items\medical\bandage\dsr_bandage.p3d";
		mass = 3;
	};
	class dsr_item_painmed: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Pain Medication";
		model = "\dsr_items\medical\painmed\dsr_painmed.p3d";
		mass = 3;
	};
	class dsr_item_peptobismol: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Pepy Bismol";
		model = "\dsr_items\medical\peptobismol\dsr_peptobismol.p3d";
		mass = 3;
	};
	class dsr_item_bloodbag_empty : dsr_item_base {
		displayName = "Empty Bloodbag";
		model = "\dsr_items\medical\bloodbag\dsr_bloodbag.p3d";
		descriptionShort = "An empty bloodbag.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_bloodbag_full : dsr_item_base {
		displayName = "Full Bloodbag";
		model = "\dsr_items\medical\bloodbag\dsr_bloodbag.p3d";
		descriptionShort = "A bloodbag filled with blood.";
		descriptionUse = "TODO";
		mass = 5;
	};
		//--- Food
	class dsr_item_tuna: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Tuna";
		model = "\dsr_items\tuna\tuna.p3d";
		mass = 5;
	};
	class dsr_item_bag_rice: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Bag of Rice";
		model = "\dsr_items\food\rice\dsr_bagrice.p3d";
		mass = 10;
	};
	class dsr_item_mre: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "MRE";
		model = "\dsr_items\food\mre\dsr_mre.p3d";
		mass = 10;
	};
	class dsr_item_canchicken: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Canned Chicken";
		model = "\dsr_items\food\canchicken\dsr_canchicken.p3d";
		mass = 5;
	};
	class dsr_item_canclams: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Canned Clams";
		model = "\dsr_items\food\canclams\dsr_canclams.p3d";
		mass = 5;
	};
	class dsr_item_deviledham: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Deviled Ham";
		model = "\dsr_items\food\deviledham\dsr_deviledham.p3d";
		mass = 5;
	};
	class dsr_item_driedbeans: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Bag of Dried Beans";
		model = "\dsr_items\food\driedbeans\dsr_driedbeans.p3d";
		mass = 10;
	};
	class dsr_item_instantcoffee: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Instant Coffee Mix";
		model = "\dsr_items\food\instantcoffee\dsr_instantcoffee.p3d";
		mass = 5;
	};
		//--- Materials
	class dsr_item_scrapmetal: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Scrap Metal";
		model = "\dsr_items\materials\dsr_scrap_metal.p3d";
		mass = 5;
	};
	class dsr_item_carbattery: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Car Battery";
		model = "\dsr_items\materials\dsr_battery_car.p3d";
		mass = 10;
	};
	class dsr_item_bricks: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Bricks";
		model = "\dsr_items\materials\dsr_bricks.p3d";
		mass = 10;
	};
	class dsr_item_plasticdrum: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Plastic Drum";
		model = "\dsr_items\materials\dsr_drum_plastic.p3d";
		mass = 10;
	};
	class dsr_item_ducttape: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Duct Tape";
		model = "\dsr_items\materials\dsr_ducttape.p3d";
		mass = 5;
	};
	class dsr_item_electricalcomp: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Electrical Components";
		model = "\dsr_items\materials\dsr_electricalcomp.p3d";
		mass = 5;
	};
	class dsr_item_hardware: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Hardware Box";
		model = "\dsr_items\materials\dsr_hardware.p3d";
		mass = 5;
	};
	class dsr_item_logs: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Wood Logs";
		model = "\dsr_items\materials\dsr_logs.p3d";
		mass = 50;
	};
	class dsr_item_lumber: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Lumber";
		model = "\dsr_items\materials\dsr_lumber.p3d";
		mass = 25;
	};
	class dsr_item_plywood: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Plywood";
		model = "\dsr_items\materials\dsr_plywood.p3d";
		mass = 25;
	};
	class dsr_item_seedpack: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Pack of Seeds";
		model = "\dsr_items\materials\dsr_seedpack.p3d";
		mass = 5;
	};
	class dsr_item_fishingrod_broken: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Broken Fishing Rod";
		model = "\dsr_items\tools\dsr_fishingrod_broken.p3d";
		mass = 15;
	};
	class dsr_item_wateringcan: dsr_item_base
	{
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
		scope = 2;
		scopeCurator = 2;
		displayName = "Watering Can";
		model = "\dsr_items\tools\dsr_wateringcan.p3d";
		mass = 10;
	};
	
	//--- A3 items
	class dsr_item_log : dsr_item_base {
		displayName = "Wooden Log";
		model = "\A3\Structures_F_EPA\Civ\Camping\WoodenLog_F.p3d";
		descriptionShort = "A wooden log cut from a tree";
		descriptionUse = "Used to make fires and build things";
		mass = 20;
	};
	//--- electronics
	class dsr_item_battery_charged : dsr_item_base {
		displayName = "LiPo Battery";
		model = "\A3\Structures_F_EPA\Items\Electronics\Battery_F.p3d";
		descriptionShort = "A fully charged lithium-ion battery";
		descriptionUse = "Used to power small electronics";
		mass = 3;
	};
	class dsr_item_battery_dead : dsr_item_base {
		displayName = "LiPo Battery";
		model = "\A3\Structures_F_EPA\Items\Electronics\Battery_F.p3d";
		descriptionShort = "A dead lithium-ion battery";
		descriptionUse = "Used to power small electronics, however this battery is dead.";
		mass = 3;
	};
	class dsr_item_extensioncord : dsr_item_base {
		displayName = "Extension Cord";
		model = "\A3\Structures_F\Items\Electronics\ExtensionCord_F.p3d";
		descriptionShort = "An electrical extension cord.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_fmradio : dsr_item_base {
		displayName = "FM Radio";
		model = "\A3\Structures_F\Items\Electronics\FMradio_F.p3d";
		descriptionShort = "A radio.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_camera : dsr_item_base {
		displayName = "Camera";
		model = "\A3\Structures_F\Items\Electronics\HandyCam_F.p3d";
		descriptionShort = "A camera.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_laptop : dsr_item_base {
		displayName = "Laptop";
		model = "\A3\Structures_F\Items\Electronics\Laptop_F.p3d";
		descriptionShort = "A laptop.";
		descriptionUse = "TODO";
		mass = 8;
	};
	class dsr_item_phoneold : dsr_item_base {
		displayName = "Old Phone";
		model = "\A3\Structures_F\Items\Electronics\MobilePhone_old_F.p3d";
		descriptionShort = "An old phone.";
		descriptionUse = "TODO";
		mass = 2;
	};
	class dsr_item_phonesmart : dsr_item_base {
		displayName = "Smart Phone";
		model = "\A3\Structures_F\Items\Electronics\MobilePhone_smart_F.p3d";
		descriptionShort = "A smart phone.";
		descriptionUse = "TODO";
		mass = 2;
	};
	class dsr_item_portablegenerator : dsr_item_base {
		displayName = "Portable Generator";
		model = "\A3\Structures_F\Items\Electronics\Portable_generator_F.p3d";
		descriptionShort = "A portable generator.";
		descriptionUse = "TODO";
		mass = 15;
	};
	class dsr_item_portableradio : dsr_item_base {
		displayName = "Portable Radio";
		model = "\A3\Structures_F\Items\Electronics\PortableLongRangeRadio_F.p3d";
		descriptionShort = "A portable radio.";
		descriptionUse = "TODO";
		mass = 3;
	};
	class dsr_item_satphone : dsr_item_base {
		displayName = "Satellite Phone";
		model = "\A3\Structures_F\Items\Electronics\SatellitePhone_F.p3d";
		descriptionShort = "A satphone for rural environments.";
		descriptionUse = "TODO";
		mass = 10;
	};
	class dsr_item_survivalradio : dsr_item_base {
		displayName = "Survival Radio";
		model = "\A3\Structures_F\Items\Electronics\SurvivalRadio_F.p3d";
		descriptionShort = "A survival radio for long range reception.";
		descriptionUse = "TODO";
		mass = 10;
	};
	
	//--- food
	class dsr_item_beans : dsr_item_base {
		displayName = "Ben's Baked Beans";
		model = "\A3\Structures_F_EPA\Items\Food\BakedBeans_F.p3d";
		descriptionShort = "Baked beans, they look tasty.";
		descriptionUse = "You eat them.";
		mass = 5;
	};
	class dsr_item_cereal : dsr_item_base {
		displayName = "Standard Cereal";
		model = "\A3\Structures_F_EPA\Items\Food\CerealsBox_F.p3d";
		descriptionShort = "Cereal, looks yummy.";
		descriptionUse = "You eat it.";
		mass = 8;
	};
	class dsr_item_powderedmilk : dsr_item_base {
		displayName = "Powdered Milk";
		model = "\A3\Structures_F_EPA\Items\Food\PowderedMilk_F.p3d";
		descriptionShort = "Powdered Milk, edible but would be better as actual milk.";
		descriptionUse = "You eat it.";
		mass = 4;
	};
	class dsr_item_rice : dsr_item_base {
		displayName = "Rice";
		model = "\A3\Structures_F_EPA\Items\Food\RiceBox_F.p3d";
		descriptionShort = "Rice, looks good.";
		descriptionUse = "You eat it.";
		mass = 7;
	};
	class dsr_item_bacon : dsr_item_base {
		displayName = "Tactical Bacon";
		model = "\A3\Structures_F\Items\Food\TacticalBacon_F.p3d";
		descriptionShort = "Tactical Bacon, they look tasty.";
		descriptionUse = "You eat them.";
		mass = 5;
	};
	//--- drinks
	class dsr_item_waterbottle_full : dsr_item_base {
		displayName = "Full Water Bottle";
		model = "\A3\Structures_F_EPA\Items\Food\BottlePlastic_V2_F.p3d";
		descriptionShort = "A full bottle of clean water.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	class dsr_item_waterbottle_dirty : dsr_item_base {
		displayName = "Full Water Bottle";
		model = "\A3\Structures_F_EPA\Items\Food\BottlePlastic_V2_F.p3d";
		descriptionShort = "A full bottle of dirty water.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	class dsr_item_waterbottle_empty : dsr_item_base {
		displayName = "Empty Water Bottle";
		model = "\A3\Structures_F_EPA\Items\Food\BottlePlastic_V2_F.p3d";
		descriptionShort = "An Empty bottle.";
		descriptionUse = "You can fill this with water.";
		mass = 5;
	};
	class dsr_item_canteen_full : dsr_item_base {
		displayName = "Full Canteen of Water";
		model = "\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		descriptionShort = "A full canteen of clean water.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	class dsr_item_canteen_dirty : dsr_item_base {
		displayName = "Full Canteen of Water";
		model = "\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		descriptionShort = "A full canteen of dirty water.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	class dsr_item_canteen_empty : dsr_item_base {
		displayName = "Empty Canteen";
		model = "\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		descriptionShort = "An empty canteen.";
		descriptionUse = "You can fill this with water.";
		mass = 5;
	};
	class dsr_item_rustyspirit : dsr_item_base {
		displayName = "Rusty Spirit";
		model = "\A3\Structures_F\Items\Food\Can_Rusty_F.p3d";
		descriptionShort = "Lemon-Lime soda.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	class dsr_item_spirit : dsr_item_base {
		displayName = "Spirit";
		model = "\A3\Structures_F\Items\Food\Can_V1_F.p3d";
		descriptionShort = "Lemon-Lime soda.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	class dsr_item_franta : dsr_item_base {
		displayName = "Franta";
		model = "\A3\Structures_F\Items\Food\Can_V2_F.p3d";
		descriptionShort = "Orange soda.";
		descriptionUse = "You drink it.";
		mass = 5;
	};
	//--- housing
	class dsr_item_campinglight : dsr_item_base {
		displayName = "Camping Light";
		model = "\A3\Structures_F\Civ\Camping\Camping_Light_off_F.p3d";
		descriptionShort = "Light up the night with this camping light.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_campingchair : dsr_item_base {
		displayName = "Camping Chair";
		model = "\A3\Structures_F\Civ\Camping\CampingChair_V1_folded_F.p3d";
		descriptionShort = "A comfortable seat for beside the fire.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_sleepingmat : dsr_item_base {
		displayName = "Sleeping Mat";
		model = "\A3\Structures_F\Civ\Camping\Ground_sheet_folded_F.p3d";
		descriptionShort = "A mat to place a sleeping bag on.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_pillow : dsr_item_base {
		displayName = "Pillow";
		model = "\A3\Structures_F\Civ\Camping\Pillow_F.p3d";
		descriptionShort = "A pillow for sleeping with";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_sleepingbag : dsr_item_base {
		displayName = "Sleeping Bag";
		model = "\A3\Structures_F\Civ\Camping\Sleeping_bag_folded_F.p3d";
		descriptionShort = "A thermal sleeping bag";
		descriptionUse = "TODO";
		mass = 5;
	};
	//--- tools
	class dsr_item_butane_full : dsr_item_base {
		displayName = "Full Butane Bottle";
		model = "\A3\Structures_F_EPA\Items\Tools\ButaneCanister_F.p3d";
		descriptionShort = "A bottle filled with butane.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_butane_empty : dsr_item_base {
		displayName = "Empty Butane Bottle";
		model = "\A3\Structures_F_EPA\Items\Tools\ButaneCanister_F.p3d";
		descriptionShort = "An empty bottle used for butane.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_butanetorch : dsr_item_base {
		displayName = "Butane Torch";
		model = "\A3\Structures_F_EPA\Items\Tools\ButaneTorch_F.p3d";
		descriptionShort = "A butane torch.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_canopener : dsr_item_base {
		displayName = "Can Opener";
		model = "\A3\Structures_F_EPA\Items\Tools\CanOpener_F.p3d";
		descriptionShort = "A metal can opener.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_propane_full : dsr_item_base {
		displayName = "Full Propane Bottle";
		model = "\A3\Structures_F_EPA\Items\Tools\GasCanister_F.p3d";
		descriptionShort = "A bottle filled with propane.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_propane_empty : dsr_item_base {
		displayName = "Empty Propane Bottle";
		model = "\A3\Structures_F_EPA\Items\Tools\GasCanister_F.p3d";
		descriptionShort = "An empty bottle used for propane.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_propanecooker : dsr_item_base {
		displayName = "Propane Cooker";
		model = "\A3\Structures_F_EPA\Items\Tools\GasCooker_F.p3d";
		descriptionShort = "A propane cooker.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_matches : dsr_item_base {
		displayName = "Matches";
		model = "\A3\Structures_F_EPA\Items\Tools\Matches_F.p3d";
		descriptionShort = "A box of matches.";
		descriptionUse = "TODO";
		count = 40;
		mass = 5;
	};
	class dsr_item_metalwire : dsr_item_base {
		displayName = "Metal Wire";
		model = "\A3\Structures_F_EPA\Items\Tools\MetalWire_F.p3d";
		descriptionShort = "A coil of metal wire.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_drill : dsr_item_base {
		displayName = "Drill";
		model = "\A3\Structures_F\Items\Tools\DrillAku_F.p3d";
		descriptionShort = "An electric drill.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_tincontainer : dsr_item_base {
		displayName = "Tin Container";
		model = "\A3\Structures_F_EPA\Items\Vessels\TinContainer_F.p3d";
		descriptionShort = "A tin container.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_nailfile : dsr_item_base {
		displayName = "Nail File";
		model = "\A3\Structures_F\Items\Tools\File_F.p3d";
		descriptionShort = "A nail file.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_grinder : dsr_item_base {
		displayName = "Grinder";
		model = "\A3\Structures_F\Items\Tools\Grinder_F.p3d";
		descriptionShort = "A grinder.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_hammer : dsr_item_base {
		displayName = "Hammer";
		model = "\A3\Structures_F\Items\Tools\Hammer_F.p3d";
		descriptionShort = "A hammer.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_tapemeasure : dsr_item_base {
		displayName = "Tape Measure";
		model = "\A3\Structures_F\Items\Tools\Meter3m_F.p3d";
		descriptionShort = "A measuring tape.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_multimeter : dsr_item_base {
		displayName = "MultiMeter";
		model = "\A3\Structures_F\Items\Tools\MultiMeter_F.p3d";
		descriptionShort = "A MultiMeter.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_pliers : dsr_item_base {
		displayName = "Pliers";
		model = "\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		descriptionShort = "Pliers.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_screwdriver_flathead : dsr_item_base {
		displayName = "Flat-Head Screwdriver";
		model = "\A3\Structures_F\Items\Tools\Screwdriver_V1_F.p3d";
		descriptionShort = "A flat-head screwdriver.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_screwdriver_phillips : dsr_item_base {
		displayName = "Phillips-Head Screwdriver";
		model = "\A3\Structures_F\Items\Tools\Screwdriver_V2_F.p3d";
		descriptionShort = "A phillips-head screwdriver.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_wrench : dsr_item_base {
		displayName = "Wrench";
		model = "\A3\Structures_F\Items\Tools\Wrench_F.p3d";
		descriptionShort = "A wrench.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_bucket_full : dsr_item_base {
		displayName = "Full Bucket";
		model = "\A3\Structures_F\Items\Vessels\Bucket_F.p3d";
		descriptionShort = "A bucket filled with water.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_bucket_empty : dsr_item_base {
		displayName = "Empty Bucket";
		model = "\A3\Structures_F\Items\Vessels\Bucket_F.p3d";
		descriptionShort = "An empty bucket.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_fuelcan_full : dsr_item_base {
		displayName = "Full Fuel Canister";
		model = "\A3\Structures_F\Items\Vessels\CanisterFuel_F.p3d";
		descriptionShort = "A full fuel can.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_fuelcan_empty : dsr_item_base {
		displayName = "Empty Fuel Canister";
		model = "\A3\Structures_F\Items\Vessels\CanisterFuel_F.p3d";
		descriptionShort = "An empty fuel can.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_oilcan_full : dsr_item_base {
		displayName = "Full Oil Canister";
		model = "\A3\Structures_F\Items\Vessels\CanisterOil_F.p3d";
		descriptionShort = "A full oil can.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_oilcan_empty : dsr_item_base {
		displayName = "Empty Oil Canister";
		model = "\A3\Structures_F\Items\Vessels\CanisterOil_F.p3d";
		descriptionShort = "An empty oil can.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_plasticjug : dsr_item_base {
		displayName = "Plastic Jug";
		model = "\A3\Structures_F\Items\Vessels\CanisterPlastic_F.p3d";
		descriptionShort = "A plastic jug.";
		descriptionUse = "TODO";
		mass = 5;
	};
	
	//--- misc/junk
	class dsr_item_suitcase : dsr_item_base {
		displayName = "Suitcase";
		model = "\A3\Structures_F\Items\Luggage\Suitcase_F.p3d";
		descriptionShort = "A large suitcase used to store things.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_money : dsr_item_base {
		displayName = "Money";
		model = "\A3\Structures_F\Items\Valuables\Money_F.p3d";
		descriptionShort = "A bunch of useless cash.";
		descriptionUse = "Can be used to start fires.";
		mass = 5;
	};
	class dsr_item_crushedcan : dsr_item_base {
		displayName = "Crushed Can";
		model = "\A3\Structures_F\Items\Food\Can_Dented_F.p3d";
		descriptionShort = "A crushed can.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_file : dsr_item_base {
		displayName = "A File";
		model = "\A3\Structures_F\Items\Documents\File1_F.p3d";
		descriptionShort = "Useless information is contained on this file.";
		descriptionUse = "Can be used to start fires.";
		mass = 3;
	};
	class dsr_item_file2 : dsr_item_base {
		displayName = "A File";
		model = "\A3\Structures_F\Items\Documents\File2_F.p3d";
		descriptionShort = "Useless information is contained on this file.";
		descriptionUse = "Can be used to start fires.";
		mass = 3;
	};
	class dsr_item_photos : dsr_item_base {
		displayName = "Photos";
		model = "\A3\Structures_F\Items\Documents\FilePhotos_F.p3d";
		descriptionShort = "A collection of photos.";
		descriptionUse = "Can be used to start fires.";
		mass = 4;
	};
	class dsr_item_notepad : dsr_item_base {
		displayName = "Notepad";
		model = "\A3\Structures_F\Items\Documents\Notepad_F.p3d";
		descriptionShort = "A notepad with nothing on it.";
		descriptionUse = "Can be used to start fires.";
		mass = 5;
	};
	class dsr_item_pen_black : dsr_item_base {
		displayName = "Black Pen";
		model = "\A3\Structures_F\Items\Stationery\PenBlack_F.p3d";
		descriptionShort = "A black ballpoint pen";
		descriptionUse = "TODO";
		mass = 1;
	};
	class dsr_item_pen_red : dsr_item_base {
		displayName = "Red Pen";
		model = "\A3\Structures_F\Items\Stationery\PenRed_F.p3d";
		descriptionShort = "A red ballpoint pen.";
		descriptionUse = "TODO";
		mass = 1;
	};
	class dsr_item_pencil_blue : dsr_item_base {
		displayName = "Blue pencil";
		model = "\A3\Structures_F\Items\Stationery\PencilBlue_F.p3d";
		descriptionShort = "A blue pencil.";
		descriptionUse = "TODO";
		mass = 1;
	};
	class dsr_item_pencil_green : dsr_item_base {
		displayName = "Green Pencil";
		model = "\A3\Structures_F\Items\Stationery\PencilGreen_F.p3d";
		descriptionShort = "A green pencil.";
		descriptionUse = "TODO";
		mass = 1;
	};
	class dsr_item_pencil_red : dsr_item_base {
		displayName = "Red Pencil";
		model = "\A3\Structures_F\Items\Stationery\PencilRed_F.p3d";
		descriptionShort = "A red pencil.";
		descriptionUse = "TODO";
		mass = 1;
	};
	class dsr_item_pencil_yellow : dsr_item_base {
		displayName = "Yellow Pencil";
		model = "\A3\Structures_F\Items\Stationery\PencilYellow_F.p3d";
		descriptionShort = "A yellow pencil.";
		descriptionUse = "TODO";
		mass = 1;
	};
	//--- medical
	class dsr_item_antibiotic : dsr_item_base {
		displayName = "Antibiotic";
		model = "\A3\Structures_F_EPA\Items\Medical\Antibiotic_F.p3d";
		descriptionShort = "An antibiotic for treating most infections.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_bandage : dsr_item_base {
		displayName = "Bandage";
		model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
		descriptionShort = "A bandage wrap for treating bleeding wounds.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_defibrillator : dsr_item_base {
		displayName = "Defibrillator";
		model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
		descriptionShort = "An emergency defib.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_disinfectant : dsr_item_base {
		displayName = "Disinfectant Spray";
		model = "\A3\Structures_F_EPA\Items\Medical\DisinfectantSpray_F.p3d";
		descriptionShort = "Spray that kills 99.9% of bacteria.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_handwarmer : dsr_item_base {
		displayName = "Handwarmer";
		model = "\A3\Structures_F_EPA\Items\Medical\HeatPack_F.p3d";
		descriptionShort = "A single handwarmer.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_painkillers : dsr_item_base {
		displayName = "Painkillers";
		model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
		descriptionShort = "A powerfull opiate that is highly addictive.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_vitamins : dsr_item_base {
		displayName = "Vitamins";
		model = "\A3\Structures_F_EPA\Items\Medical\VitaminBottle_F.p3d";
		descriptionShort = "Vitamins packed with essentials for a healthy body.";
		descriptionUse = "TODO";
		mass = 5;
	};
	class dsr_item_waterpurificationtablets : dsr_item_base {
		displayName = "Water Purification Tablets";
		model = "\A3\Structures_F_EPA\Items\Medical\WaterPurificationTablets_F.p3d";
		descriptionShort = "Quickly kills harmful bacteria in water.";
		descriptionUse = "TODO";
		mass = 5;
	};
};

class CfgEditorSubcategories
{
	class dsr_items
	{
		displayName = "DSR Items";
	};
};