class CfgPatches
{
	class Desolation {};
};
class Plugins
{
	class Desolation
	{
		name = "Desolation Redux";
		desc = "ArmA 3 Zombie Survival Mod";
		tag = "DS";
	};
};
/*
class CfgPluginActions {
	class RepairCars {
		class Actions {
			class RepairEngine {
				text = "Repair Engine";
				action = "systemchat 'repairing engine'; [] spawn DS_fnc_repairEngine;";
				condition = "call DS_fnc_CheckEngine";
			};
			class RepairBody {
				text = "Repair Body";
				action = "systemchat 'repairing body'; [] spawn DS_fnc_repairBody;";
				condition = "call DS_fnc_CheckBody";
			};
			class RepairFueltank {
				text = "Repair Fuel Tank";
				action = "systemchat 'repairing fuel tank'; [] spawn DS_fnc_repairFuelTank;";
				condition = "call DS_fnc_CheckFueltank";
			};
			class RepairGlass {
				text = "Repair Glass";
				action = "systemchat 'repairing glass'; [] spawn DS_fnc_repairGlass;";
				condition = "call DS_fnc_CheckGlass";
			};
			class RepairWheels {
				text = "Repair Wheel";
				action = "systemchat 'repairing wheels'; [] spawn DS_fnc_repairWheels;";
				condition = "call DS_fnc_CheckWheels";
			};
		};
		condition = "_cursor isKindOf 'LandVehicle' && player distance _cursor < 5";
		text = "Repair Vehicle";
	};
};
*/
class CfgPluginKeybinds 
{
	class OpenJournalIndex 
	{
		displayName = "Open Building Journal";
		tooltip = "Open the journal containing buildables";
		tag = "DS";
		variable = "OpenBuildingJournal";
		defaultKeys[] = {{0x24,0}};
		code = "call DS_fnc_openJournal;";
	};
	class Toggle3DAction 
	{
		displayName = "Toggle 3D Actions";
		tooltip = "Toggle 3D actions to be able to easily use any actions in 3D";
		tag = "DS";
		variable = "Toggle3DAction";
		defaultKeys[] = {{0x0F,0}};
		code = "call DS_fnc_toggleActions;";
	};
	class do3DAction
	{
		displayName = "Use 3D Action";
		tooltip = "Allows you to use the highlighted action";
		tag = "DS";
		variable = "do3DAction";
		defaultKeys[] = {{0x39,0}};
		code = "[] spawn DS_fnc_do3DAction; DS_var_3DActionsEnabled";
	};
};

class CfgFunctions
{
	class DS
	{
		//--- client functions
		class Client_Actions_Vehicle {
			file = "Desolation\client\actions\repair";
			isclient = 1;
			class removePart {};
			class repairPart {};
		};
		class Client_Building {
			file = "Desolation\Client\Building";
			isclient = 1;
			class openJournal {};
			class initBuilding {};
			class onBuildClick {};
			class registerBuildable {};
			class onCrateFilled {};
		};
		class Client_Spawning {
			file = "Desolation\Client\Spawning";
			isclient = 1;
			class findSpawnPosition {};
			class onRegionSelected {};
			class freshSpawn {};
			class finishSpawn {};
			class showRegionNotification {};
		};
		class Client_Events {
			file = "Desolation\Client\Events";
			isclient = 1;
			class initEventHandlers {};
			class registerPlayer {};
			class registerNewPlayer {};
		};
		class Client_Functions {
			file = "Desolation\Client\Functions";
			isclient = 1;
			class infoText {};
			class notWhitelisted {};
			class receiveTransmition {};
			class calcGrayscale {};
			class getCfgValue {};
			class shuffleArray {};
			class genRandMapPos {};
		};
		class Client_Actions_System {
			file = "Desolation\Client\Actions\System";
			isclient = 1;
			class toggleActions {};
			class draw3DActions {};
			class get3DPartName {};
			class calculate3DActions {};
			class do3DAction {};
		};
		class Client_Actions_Items {
			file = "Desolation\Client\Actions\Items";
			isclient = 1;
			class doAction {};
			class doActionTarget {};
			class useItem {};
			class useItemTarget {};
			class drink {};
			class eat {};
			class fillblood {};
			class fillhcarbon {};
			class fillwater {};
			class lightfire {};
			class useantibiotic {};
			class usebandage {};
			class useblood {};
			class usedefib {};
			class usedisinfectant {};
			class usehandwarmer {};
			class usepainkillers {};
			class usevitamins {};
			class usewpt {};
			class usesplint {};
			class useCure {};
			class useImmune {};
		};
		class Client_Interface {
			file = "Desolation\Client\Interface";
			isclient = 1;
			class onEscape {};
		};
		class Client {
			file = "Desolation\Client";
			isclient = 1;
			class initClient {};
		};
		class Client_Status {
			file = "Desolation\Client\Status";
			isclient = 1;
			class initHealthSys {};
			class onBleedTick {};
			class onBloodReceive {};
			class onDrink {};
			class onEat {};
			class onEffectTick {};
			class onInfectionTick {};
			class onHungerTick {};
			class onThirstTick {};
			class onUpdateTick {};
			class onTick {};
		};
		class Client_Medical {
			file = "Desolation\Client\Medical";
			isclient = 1;
			class knockOut {};
			class stopBleeding {};
		};
		class Client_Medical_Bleeding {
			file = "Desolation\Client\Medical\Bleeding";
			isclient = 1;
			class createBleedSource {};
			class initBleedingSystem {};
			class onHitPartReceived {};
			class removeBleedSource {};
			class updateBleedSource {};
		};
		class Client_Inventory {
			file = "Desolation\Client\Inventory";
			isclient = 1;
			class closeButtons {};
			class saveData {};
			class initInvHandler {};
			class itemClick {};
			class setupInvEvents {};
		};
		//--- server functions
		class Server_Actions_Vehicle {
			file = "Desolation\Server\actions\repair";
			isserver = 1;
			class removePartReq {};
			class repairPartReq {};
		};
		class Server_Database {
			file = "Desolation\Server\Database";
			isserver = 1;
			class dbRequest {};
			class dbOnSpawnResponse {};
		};
		class Server_Airdrop {
			file = "Desolation\Server\Airdrop";
			isserver = 1;
			class addCrateItems {};
			class DoDrop {};
			class initAirdrops {};
			class spawnCrate {};
			class genCrateItems {};
		};
		class Server_Events {
			file = "Desolation\Server\Events";
			isserver = 1;
			class onPlayerKilled {};
			class handleDisconnect {};
			class playerDisconnected {};
		};
		class Server_Players {
			file = "Desolation\Server\Players";
			isserver = 1;
			class requestLoadSpawn {};
			class requestFreshSpawn {};
			class requestSpawn {};
			class requestSave {};
			class setupLoadout {};
		};
		class Server_Loot {
			file = "Desolation\Server\Loot";
			isserver = 1;
			class lootManager {};
			class spawnLoot {};
			class despawnLoot {};
		};
		class Server_Audio {
			file = "Desolation\Server\Audio";
			isserver = 1;
			class playOverRadio {};
		};
		class Server_Crashes {
			file = "Desolation\Server\Crashes";
			isserver = 1;
			class spawnCrashes {};
			class crashSmoke {};
			class spawnCrashLoot {};
			class initHeliCrashes {};
			class heliCrashAnim {};
		};
		class Server_Vehicles {
			file = "Desolation\Server\Vehicles";
			isserver = 1;
			class spawnVehicles {};
			class spawnFromDB {};
			class vehicleMonitor {};
			class simManager {};
		};
		class Server_Building {
			file = "Desolation\Server\Building";
			isserver = 1;
			class requestBuild {};
			class finishBuild {};
			class initBuildingSys {};
		};
		class Server_Locking {
			file = "Desolation\Server\Locking";
			isserver = 1;
			class checkServerLock {};
			class initLock {};
		};
		class Server {
			file = "Desolation\Server";
			isserver = 1;
			class initServer {};
		};
	};
};
class CfgHeliCrashes {
	class Settings {
		MinTimeBetweenCrashes = 5;
		MaxTimeBetweenCrashes = 20;
		NumberOfCrashesToSpawn = 5;
		MaxSearchDistance = 5000;
	};
	class CrashTypes {
		class Military {
			HeliClass = "I_Heli_Transport_02_F";
			WreckClass = "I_Heli_Transport_02_F";
			WreckSmoke = 1; //1 for true 0 for false!
			SpawnAltitude = 600;
			//particle effects config (size and origin)
			SmokePos[] = {0,0,0};
			SmokeSize = 7;
			Locations[] =
			{
				{4060.2971,2753.147},
				{3014.8438,12482.121},
				{7501.166,9649.7529},
				{10790.136,4316.1323}
			};
			
			class loot {
				maxLootpiles = 10;//not implemented yet
				weapons[] = {
					"srifle_EBR_F"
				};
				magazines[] = {
				
				};
				items[] = {
					"FirstAidKit"
				};
				backpacks[] = {
			
				};
			};
		};
		
		class Medical {
			HeliClass = "I_Heli_Transport_02_F";
			WreckClass = "I_Heli_Transport_02_F";
			WreckSmoke = 1; //1 for true 0 for false!
			SpawnAltitude = 600;
			//particle effects config (size and origin)
			SmokePos[] = {0,0,0};
			SmokeSize = 7;
			Locations[] =
			{
				{2794.793,6132.3345},
				{12407.456,3987.5303},
				{11379.448,11809.968},
				{10190.923,2723.2224}
			};
			
			class loot {
				maxLootpiles = 10;//not implemented yet
				weapons[] = {
				};
				magazines[] = {
				"dsr_item_antibiotic",
				"dsr_item_bloodbag_full",
				"dsr_item_bandage",
				"dsr_item_defibrillator",
				"dsr_item_disinfectant",
				"dsr_item_painkillers"
				};
				items[] = {
				"FirstAidKit"
				};
				backpacks[] = {
				};
			};
		};
	};
};
class CfgAirdropSpawns {
	class MedicDrop {
		name = "Medical Drop";
		weapons[] = {
			
		};
		magazines[] = {
			"dsr_item_antibiotic",
			"dsr_item_bloodbag_full",
			"dsr_item_bandage",
			"dsr_item_defibrillator",
			"dsr_item_disinfectant",
			"dsr_item_painkillers"
		};
		items[] = {
			"FirstAidKit"
		};
		backpacks[] = {
			
		};
	};
	class BuildingDrop {
		name = "Building Supplies Drop";
		weapons[] = {
			
		};
		magazines[] = {
			"dsr_item_log",
			"dsr_item_portablegenerator",
			"dsr_item_campinglight",
			"dsr_item_campingchair",
			"dsr_item_sleepingmat",
			"dsr_item_ducttape",
			"dsr_item_matches",
			"dsr_item_metalwire",
			"dsr_item_grinder",
			"dsr_item_hammer",
			"dsr_item_saw",
			"dsr_item_sleepingbag",
			"dsr_item_pillow"
		};
		items[] = {
			
		};
		backpacks[] = {
			"B_Kitbag_mcamo"
		};
	};
	class FoodDrop {
		name = "Food Supplies Drop";
		weapons[] = {
			
		};
		magazines[] = {
			"dsr_item_beans",
			"dsr_item_cereal",
			"dsr_item_powderedmilk",
			"dsr_item_rice",
			"dsr_item_bacon",
			"dsr_item_waterbottle_full",
			"dsr_item_canteen_full",
			"dsr_item_spirit",
			"dsr_item_franta",
			"dsr_item_canopener",
			"dsr_item_waterpurificationtablets",
			"dsr_item_vitamins"
		};
		items[] = {
			
		};
		backpacks[] = {
			
		};
	};
};
class CfgItemSpawns {
	buildingTypes[] = {"Military","Civilian","Industrial","Commercial","Medical","Mechanical"};
	lootRarity[] = {"rare","semirare","average","semicommon","common"};
	lootTypes[] = {"Weapon","Handgun","Magazine","Food","Drink","Medical","Junk","Backpack","Uniform","Vest","Helmet","Cosmetic","GeneralItem","Construction","Book","Electronic","CarPart","Attachment"};

	class Loot {
        class Military {
            class Weapon {
                rare[] = {
                    {"DSR_srifle_DMR_02",5},                //MAR-10
                    {"DSR_srifle_DMR_02_camo",5},           //MAR-10
                    {"DSR_srifle_DMR_02_sniper",5},         //MAR-10
                    {"DSR_srifle_DMR_03",6},                //Mk-I EMR
                    {"DSR_srifle_DMR_03_khaki",5},          //Mk-I EMR
                    {"DSR_srifle_DMR_03_tan",5},            //Mk-I EMR
                    {"DSR_srifle_DMR_03_multicam",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_03_woodland",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_04",4},                //ASP-1 Kir
                    {"DSR_srifle_DMR_04_Tan",5},            //ASP-1 Kir
                    {"DSR_srifle_DMR_05_blk",5},            //Cyrus
                    {"DSR_srifle_DMR_05_hex",5},            //Cyrus
                    {"DSR_srifle_DMR_05_tan",5},            //Cyrus
                    {"DSR_srifle_EBR",7},
                    {"DSR_srifle_GM6",1},
                    {"DSR_srifle_GM6_camo",1},
                    {"DSR_srifle_LRR",2},
                    {"DSR_srifle_LRR_camo",2},
                    {"DSR_LMG_Zafir",7},
                    {"DSR_MMG_01_hex",2},                   //Navid
                    {"DSR_MMG_01_tan",2},                   //Navid
                    {"DSR_MMG_02_camo",3},                  //SPMG
                    {"DSR_MMG_02_black",4},                 //SPMG
                    {"DSR_MMG_02_sand",4}                   //SPMG
                };
                semirare[] = {
                    {"DSR_arifle_MX_GL",17},
                    {"DSR_arifle_MX_GL_Black",16},
                    {"DSR_arifle_MX_SW",15},
                    {"DSR_arifle_MX_SW_Black",14},
                    {"DSR_arifle_MXM",13},
                    {"DSR_arifle_MXM_Black",12},
                    {"DSR_LMG_Mk200",6},
                    {"DSR_srifle_DMR_01",5},                 //Rahim
                    {"DSR_srifle_DMR_06_camo",1},            //Mk14
                    {"DSR_srifle_DMR_06_olive",1}            //Mk14
                };
                average[] = {
                    {"DSR_arifle_Katiba",20},
                    {"DSR_arifle_Katiba_C",18},
                    {"DSR_arifle_Katiba_GL",16},
                    {"DSR_arifle_MXC",13},
                    {"DSR_arifle_MXC_Black",12},
                    {"DSR_arifle_MX",11},
                    {"DSR_arifle_MX_Black",10}
                };
                semicommon[] = {
                    {"DSR_arifle_Katiba",37},
                    {"DSR_arifle_Katiba_C",32},
                    {"DSR_arifle_Katiba_GL",31}
                };
                common[] = {
                    {"DSR_SMG_01",45},
                    {"DSR_SMG_02",55}
                };
            };
            class Handgun {
                rare[] = {
                    {"DSR_hgun_PDW2000",1},
                    {"DSR_hgun_Pistol_heavy_01",35},    //4-five
                    {"DSR_hgun_Pistol_heavy_02",10},    //Zubr
                    {"DSR_hgun_P07",54}
                };
                semirare[] = {
                    {"DSR_hgun_Pistol_heavy_01",5},    //4-five
                    {"DSR_hgun_P07",40},
                    {"DSR_hgun_Rook",55}
                };
                average[] = {
                    {"DSR_hgun_ACPC2",55},
                    {"DSR_hgun_P07",10},
                    {"DSR_hgun_Rook",35}
                };
                semicommon[] = {
                    {"DSR_hgun_Rook",25},
                    {"DSR_hgun_ACPC2",75}
                };
                common[] = {
                    {"DSR_hgun_Pistol_Signal",45},
                    {"DSR_hgun_ACPC2",55}
                };
            };
			class Magazine {
				rare[] = {
                    {"100Rnd_580x42_Mag_F",13},
                    {"100Rnd_580x42_Mag_Tracer_F",12},
                    {"5Rnd_127x108_Mag",2},             //12.7 mm 5Rnd Mag
                    {"5Rnd_127x108_APDS_Mag",1},        //12.7mm 5Rnd APDS Mag
                    {"10Rnd_127x54_Mag",3},             //12.7mm 10Rnd Mag - ASPR
                    {"7Rnd_408_Mag",6},                 //.408 7Rnd LRR Mag
                    {"20Rnd_762x51_Mag",10},            //7.62 mm 20Rnd Mag
                    {"10Rnd_338_Mag",6},                //.338 LM 10Rnd Mag
                    {"10Rnd_93x64_DMR_05_Mag",3},       //9.3mm 10Rnd Mag
                    {"10Rnd_50BW_Mag_F",4},             //.50 BW 10Rnd Caseless Mag - Type 115
                    {"130Rnd_338_Mag",4},
                    {"150Rnd_762x54_Box",8},
                    {"150Rnd_762x54_Box_Tracer",7},
                    {"150Rnd_93x64_Mag",5},
                    {"1Rnd_HE_Grenade_shell",9},
                    {"3Rnd_HE_Grenade_shell",7}
                };
                semirare[] = {
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"30Rnd_65x39_caseless_mag",5},
                    {"30Rnd_65x39_caseless_green",4},
                    {"30Rnd_65x39_caseless_mag_Tracer",4},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",4},
                    {"10Rnd_762x54_Mag",3},                         //7.62 mm 10Rnd Mag - Rahim
                    {"30Rnd_762x39_Mag_F",2},
                    {"30Rnd_762x39_Mag_Green_F",1},
                    {"30Rnd_762x39_Mag_Tracer_F",1},
                    {"30Rnd_762x39_Mag_Tracer_Green_F",1},
                    {"30Rnd_580x42_Mag_F",3},
                    {"30Rnd_580x42_Mag_Tracer_F",2},
                    {"100Rnd_65x39_caseless_mag",3},
                    {"100Rnd_65x39_caseless_mag_Tracer",2},
                    {"200Rnd_65x39_cased_Box",3},
                    {"200Rnd_65x39_cased_Box_Tracer",2},
                    {"200Rnd_65x39_Belt_Tracer_Red",2},
                    {"200Rnd_65x39_Belt_Tracer_Green",2},
                    {"200Rnd_65x39_Belt_Tracer_Yellow",2},
                    {"150Rnd_762x54_Box",3},
                    {"150Rnd_762x54_Box_Tracer",2},
                    {"150Rnd_556x45_Drum_Mag_F",3},
                    {"150Rnd_556x45_Drum_Mag_Tracer_F",1},
                    {"200Rnd_556x45_Box_F",4},
                    {"200Rnd_556x45_Box_Red_F",3},
                    {"200Rnd_556x45_Box_Tracer_F",3},
                    {"200Rnd_556x45_Box_Tracer_Red_F",3}
                };
                average[] = {
                    {"30Rnd_545x39_Mag_F",12},
                    {"30Rnd_545x39_Mag_Green_F",11},
                    {"30Rnd_545x39_Mag_Tracer_F",11},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",10},
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"20Rnd_556x45_UW_mag",7},
                    {"30Rnd_65x39_caseless_mag",4},
                    {"30Rnd_65x39_caseless_green",3},
                    {"30Rnd_65x39_caseless_mag_Tracer",3},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",3},
                    {"20Rnd_650x39_Cased_Mag_F",5}
                };
                semicommon[] = {
                    {"30Rnd_545x39_Mag_F",3},
                    {"30Rnd_545x39_Mag_Green_F",2},
                    {"30Rnd_545x39_Mag_Tracer_F",2},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",2},
                    {"30Rnd_45ACP_Mag_SMG_01",10},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Green",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02",9},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Red",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Green",7},
                    {"30Rnd_9x21_Mag",9},
                    {"30Rnd_9x21_Red_Mag",7},
                    {"30Rnd_9x21_Yellow_Mag",7},
                    {"30Rnd_9x21_Green_Mag",7}
                };
                common[] = {
                    {"FlareWhite_F",9},
                    {"FlareGreen_F",9},
                    {"FlareRed_F",9},
                    {"FlareYellow_F",9},
                    {"6Rnd_GreenSignal_F",9},
                    {"6Rnd_RedSignal_F",9},
                    {"10Rnd_9x21_Mag",7},
                    {"16Rnd_9x21_Mag",4},
                    {"16Rnd_9x21_red_Mag",5},
                    {"16Rnd_9x21_green_Mag",5},
                    {"16Rnd_9x21_yellow_Mag",5},
                    {"11Rnd_45ACP_Mag",8},
                    {"9Rnd_45ACP_Mag",9},
                    {"6Rnd_45ACP_Cylinder",3}
                };
			};
            class Food {
                rare[] = {
                    {"dsr_item_beans",100}
                };
                semirare[] = {
                    {"dsr_item_powderedmilk",100}
                };
                average[] = {
                    {"dsr_item_cereal",100}
                };
                semicommon[] = {
                    {"dsr_item_rice",100}
                };
                common[] = {
                    {"dsr_item_bacon",100}
                };
            };
            class Drink {
                rare[] = {
                    {"dsr_item_waterbottle_full",70},
                    {"dsr_item_canteen_full",30}
                };
                semirare[] = {
                    {"dsr_item_franta",55},
                    {"dsr_item_spirit",45}
				};
                average[] = {
                    {"dsr_item_rustyspirit",100}
                };
                semicommon[] = {
                    {"dsr_item_waterbottle_dirty",70},
                    {"dsr_item_canteen_dirty",30}
                };
                common[] = {
                    {"dsr_item_waterbottle_empty",70},
                    {"dsr_item_canteen_empty",30}
                };
            };
            class Medical {
                rare[] = {
                    {"dsr_item_antibiotic",40},
                    {"dsr_item_bloodbag_full",25},
                    {"dsr_item_defibrillator",35}
                };
                semirare[] = {
                    {"dsr_item_painkillers",40},
                    {"dsr_item_bloodbag_empty",60}
                };
                average[] = {
                    {"dsr_item_handwarmer",20},
                    {"dsr_item_painkillers",30},
                    {"dsr_item_bandage",40},
                    {"dsr_item_waterpurificationtablets",10}
                };
                semicommon[] = {
                    {"dsr_item_bandage",35},
                    {"dsr_item_handwarmer",15},
                    {"dsr_item_vitamins",50}
                };
                common[] = {
                    {"dsr_item_bandage",25},
                    {"dsr_item_disinfectant",30},
                    {"dsr_item_vitamins",45}
				};
            };
            class Junk {
                rare[] = {
                    {"dsr_item_suitcase",35},
                    {"dsr_item_money",65}
                };
                semirare[] = {
                    {"dsr_item_file2",40},
                    {"dsr_item_money",60}
                };
                average[] = {
                    {"dsr_item_photos",65},
                    {"dsr_item_file2",35}
                };
                semicommon[] = {
                    {"dsr_item_photos",25},
                    {"dsr_item_notepad",5},
                    {"dsr_item_pen_black",5},
                    {"dsr_item_pen_red",5},
                    {"dsr_item_crushedcan",60}
                };
                common[] = {
                    {"dsr_item_notepad",15},
                    {"dsr_item_pencil_blue",4},
                    {"dsr_item_pencil_green",2},
                    {"dsr_item_pencil_red",2},
                    {"dsr_item_pencil_yellow",2},
                    {"dsr_item_crushedcan",75}
                };
            };
            class Backpack {
                rare[] = {
                    {"B_Carryall_oucamo",20},
                    {"B_Carryall_ocamo",15},
                    {"B_Carryall_khk",10},
                    {"B_Carryall_oli",20},
                    {"B_Carryall_cbr",10},
                    {"B_Carryall_mcamo",10},
                    //Special Need to Test (Some might spawn with gear in them)
                    {"I_Parachute_02_F",5},
                    {"B_Parachute_02_F",5},
                    {"B_Carryall_ocamo_Exp",5}
                };
                semirare[] = {
                    {"B_Kitbag_sgg",65},
                    {"B_Kitbag_cbr",25},
                    {"B_Kitbag_mcamo",5},
                    {"B_Kitbag_rgr_Exp",5}
                };
                average[] = {
                    {"B_Bergen_blk",55},
                    {"B_Bergen_rgr",15},
                    {"B_Bergen_sgg",15},
                    {"B_Bergen_mcamo",15}
                };
                semicommon[] = {
                    {"B_HuntingBackpack",5},
                    {"B_OutdoorPack_blk",8},
                    {"B_OutdoorPack_blu",6},
                    {"B_OutdoorPack_tan",6},
                    {"B_FieldPack_blk",30},
                    {"B_FieldPack_oucamo",15},
                    {"B_FieldPack_ocamo",15},
                    {"B_FieldPack_cbr",15}
                };
                common[] = {
                    {"B_AssaultPack_blk",50},
                    {"B_AssaultPack_dgtl",10},
                    {"B_AssaultPack_khk",10},
                    {"B_AssaultPack_sgg",10},
                    {"B_AssaultPack_cbr",15},
                    {"B_AssaultPack_mcamo",5}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_B_CombatUniform_mcam_tshirt",1},
                    {"U_B_CombatUniform_mcam",1},
                    {"U_I_CombatUniform",1},                //Green or Independant
                    {"U_O_CombatUniform_ocamo",1},          //Hex
                    {"U_O_CombatUniform_oucamo",1},         //Winter
                    {"U_B_CTRG_1",1},
                    {"U_B_CTRG_3",1},
                    {"U_B_FullGhillie_ard",1},
                    {"U_B_FullGhillie_lsh",1},
                    {"U_B_FullGhillie_sard",1},
                    {"U_B_GhillieSuit",1},
                    {"U_B_CombatUniform_mcam_vest",1},
                    {"U_B_Wetsuit",1},                      //Black
                    {"U_I_Wetsuit",1},                      //Green
                    {"U_O_Wetsuit",1},                      //Digital
                    {"U_I_G_resistanceLeader_F",1},         //Tattoo'd Guy
                    {"U_I_OfficerUniform",1},
                    {"U_I_CombatUniform_shortsleeve",1},
                    {"U_I_CombatUniform_tshirt",1},
                    {"U_O_OfficerUniform_ocamo",1}
                };
                semirare[] = {
                    {"U_B_survival_uniform",5},
                    {"U_B_CTRG_2",5},
                    {"U_C_Scientist",10},
                    {"U_Rangemaster",5},
                    {"U_B_HeliPilotCoveralls",10},           //US Green        
                    {"U_B_PilotCoveralls",15},               //Grey
                    {"U_O_PilotCoveralls",8},               //Camo
                    {"U_OG_leader",5},
                    {"U_BG_Guerilla1_1",5},
                    {"U_BG_Guerilla3_2",5},
                    {"U_I_HeliPilotCoveralls",15},           //Tan
                    {"U_I_pilotCoveralls",12}                //Green
                };
                average[] = {
                    {"U_Competitor",20},
                    {"U_BG_Guerilla2_1",15},
                    {"U_BG_Guerilla2_2",15},
                    {"U_BG_Guerilla2_3",15},
                    {"U_BG_Guerilla3_1",15},
                    {"U_Marshal",20}
                };
                semicommon[] = {
                    {"U_C_Commoner1_1",10},
                    {"U_C_Commoner1_2",10},     
                    {"U_C_Commoner1_3",10},
                    {"U_C_Commoner2_1",10},
                    {"U_C_Commoner2_2",10},
                    {"U_C_Commoner2_3",10},
                    {"U_C_Journalist",4},
                    {"U_C_Poloshirt_stripped",5},
                    {"U_C_Commoner_shorts",9},
                    {"U_C_ShirtSurfer_shorts",5},
                    {"U_C_TeeSurfer_shorts_1",5},
                    {"U_C_TeeSurfer_shorts_2",5},
                    {"U_C_WorkerCoveralls",4},
                    {"U_C_HunterBody_grn",3}
                };
                common[] = {
                    {"U_C_Poor_1",25},
                    {"U_C_Poor_2",25},
                    {"U_C_Poor_shorts_1",10},
                    {"U_C_Poloshirt_blue",10},
                    {"U_C_Poloshirt_burgundy",10},
                    {"U_C_Poloshirt_tricolour",5},
                    {"U_C_Poloshirt_salmon",10},
                    {"U_C_Poloshirt_redwhite",5}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Chestrig_blk",1},
                    {"V_Chestrig_khk",1},
                    {"V_Chestrig_oli",1},
                    {"V_Chestrig_rgr",1},
                    {"V_PlateCarrier1_blk",1},
                    {"V_PlateCarrier1_rgr",1},
                    {"V_PlateCarrier2_rgr",1},
                    {"V_PlateCarrier3_rgr",1},
                    {"V_PlateCarrierGL_rgr",1},
                    {"V_PlateCarrierIA1_dgtl",1},
                    {"V_PlateCarrierIA2_dgtl",1},
                    {"V_PlateCarrierIAGL_dgtl",1},
                    {"V_PlateCarrierSpec_rgr",1},
                    {"V_I_G_resistanceLeader_F",1},
                    {"V_PlateCarrierSpec_blk",1},
                    {"V_PlateCarrierSpec_mtp",1},
                    {"V_PlateCarrierGL_mtp",1},
                    {"V_PlateCarrierGL_blk",1},
                    {"V_PlateCarrierIAGL_oli",1},
                    {"V_PlateCarrier_Kerry",1},
                    {"V_PlateCarrierL_CTRG",1},
                    {"V_PlateCarrierH_CTRG",1},
                    {"V_RebreatherB",1},
                    {"V_RebreatherIA",1},
                    {"V_RebreatherIR",1}
                };
                semirare[] = {
                    {"V_TacVest_blk",1},
                    {"V_TacVest_blk_POLICE",1},
                    {"V_TacVest_brn",1},
                    {"V_TacVest_camo",1},
                    {"V_TacVest_khk",1},
                    {"V_TacVest_oli",1},
                    {"V_TacVestCamo_khk",1},
                    {"V_TacVestIR_blk",1}
                };
                average[] = {
                    {"V_HarnessO_brn",1},
                    {"V_HarnessO_gry",1},
                    {"V_HarnessOGL_brn",1},
                    {"V_HarnessOGL_gry",1},
                    {"V_HarnessOSpec_brn",1},
                    {"V_HarnessOSpec_gry",1}
                };
                semicommon[] = {
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_blk",1},
                    {"V_BandollierB_cbr",1},
                    {"V_BandollierB_khk",1},
                    {"V_BandollierB_oli",1},
                    {"V_BandollierB_rgr",1}
                };
                common[] = {
                    {"V_Press_F",1},
                    {"V_Rangemaster_belt",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_HelmetB_camo",1},
                    {"H_HelmetB_grass",1},
                    {"H_HelmetB_black",1},
                    {"H_HelmetB_light",1},
                    {"H_HelmetB_sand",1},
                    {"H_HelmetB_desert",1},
                    {"H_HelmetB_light_black",1},
                    {"H_HelmetB_light_grass",1},
                    {"H_HelmetB_light_snakeskin",1},
                    {"H_HelmetB_light_desert",1},
                    {"H_HelmetB_light_sand",1},
                    {"H_HelmetB_snakeskin",1},
                    {"H_HelmetB_paint",1},
                    {"H_HelmetSpecB",1},
                    {"H_HelmetSpecB_paint1",1},
                    {"H_HelmetSpecB_blk",1},
                    {"H_HelmetSpecB_paint2",1},
                    {"H_HelmetSpecO_ocamo",1},
                    {"H_HelmetSpecO_blk",1},
                    {"H_HelmetB_plain_blk",1},
                    {"H_HelmetB_plain_mcamo",1},
                    {"H_HelmetB",1},
                    {"H_HelmetIA",1},
                    {"H_HelmetIA_net",1},
                    {"H_HelmetIA_camo",1},
                    {"H_HelmetO_ocamo",1},
                    {"H_HelmetO_oucamo",1},
                    {"H_HelmetLeaderO_ocamo",1},
                    {"H_HelmetLeaderO_oucamo",1}
                };
                semirare[] = {
                    {"H_Shemag_olive_hs",1},
                    {"H_ShemagOpen_tan",1},
                    {"H_ShemagOpen_khk",1},
                    {"H_Shemag_khk",1},
                    {"H_Shemag_tan",1},
                    {"H_Shemag_olive",1},
                    {"H_Helmet_Kerry",1},
                    {"H_HelmetCrew_B",1},
                    {"H_HelmetCrew_I",1},
                    {"H_HelmetCrew_O",1},
                    {"H_CrewHelmetHeli_I",1},
                    {"H_CrewHelmetHeli_B",1},
                    {"H_CrewHelmetHeli_O",1},
                    {"H_PilotHelmetHeli_B",1},
                    {"H_PilotHelmetHeli_I",1},
                    {"H_PilotHelmetHeli_O",1},
                    {"H_PilotHelmetFighter_B",1},
                    {"H_PilotHelmetFighter_I",1},
                    {"H_PilotHelmetFighter_O",1}
                };
                average[] = {
                    {"H_RacingHelmet_1_black_F",1},
                    {"H_RacingHelmet_1_blue_F",1},
                    {"H_RacingHelmet_1_green_F",1},
                    {"H_RacingHelmet_1_orange_F",1},
                    {"H_RacingHelmet_1_red_F",1},
                    {"H_RacingHelmet_1_white_F",1},
                    {"H_RacingHelmet_1_yellow_F",1},
                    {"H_Beret_grn",1},
                    {"H_Beret_blk",1},
                    {"H_Beret_blk_POLICE",1},
                    {"H_Beret_red",1},
                    {"H_Beret_brn_SF",1},
                    {"H_Beret_grn_SF",1},
                    {"H_Beret_02",1},
                    {"H_Beret_Colonel",1},
                    {"H_Beret_ocamo",1},
                    {"H_TurbanO_blk",1},
                    {"H_MilCap_blue",1},
                    {"H_MilCap_gry",1},
                    {"H_MilCap_ocamo",1},
                    {"H_MilCap_rucamo",1},
                    {"H_MilCap_oucamo",1},
                    {"H_MilCap_mcamo",1},
                    {"H_MilCap_dgtl",1}
                };
                semicommon[] = {
                    {"H_Booniehat_dirty",1},
                    {"H_Booniehat_khk_hs",1},
                    {"H_Booniehat_grn",1},
                    {"H_Booniehat_indp",1},
                    {"H_Booniehat_khk",1},
                    {"H_Booniehat_oli",1},
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_dgtl",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Cap_grn_BI",1},
                    {"H_Cap_blk",1},
                    {"H_Cap_blu",1},
                    {"H_Cap_oli",1},
                    {"H_Cap_grn",1},
                    {"H_Cap_red",1},
                    {"H_Cap_surfer",1},
                    {"H_Cap_tan",1},
                    {"H_Cap_blk_CMMG",1},
                    {"H_Cap_blk_ION",1},
                    {"H_Cap_oli_hs",1},
                    {"H_Cap_police",1},
                    {"H_Cap_usblack",1},
                    {"H_Cap_tan_specops_US",1},
                    {"H_Cap_blk_Raven",1},
                    {"H_Cap_brn_SPECOPS",1},
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_headphones",1},
                    {"H_Cap_press",1},
                    {"H_Cap_marshal",1},
                    {"H_Watchcap_camo",1},
                    {"H_Watchcap_blk",1},
                    {"H_Hat_blue",1},
                    {"H_Hat_brown",1},
                    {"H_Hat_camo",1},
                    {"H_Hat_checker",1},
                    {"H_Hat_grey",1},
                    {"H_Hat_tan",1}
                };
                common[] = {
                    {"H_Bandanna_gry",1},
                    {"H_Bandanna_blu",1},
                    {"H_Bandanna_cbr",1},
                    {"H_Bandanna_mcamo",1},
                    {"H_Bandanna_sgg",1},
                    {"H_Bandanna_sand",1},
                    {"H_Bandanna_surfer",1},
                    {"H_Bandanna_surfer_blk",1},
                    {"H_Bandanna_surfer_grn",1},
                    {"H_Bandanna_camo",1},
                    {"H_Bandanna_khk",1},
                    {"H_Bandanna_khk_hs",1},
                    {"H_BandMask_blk",1},
                    {"H_BandMask_demon",1},
                    {"H_BandMask_khk",1},
                    {"H_BandMask_reaper",1},
                    {"H_Watchcap_cbr",1},
                    {"H_Watchcap_khk",1},
                    {"H_Watchcap_sgg",1},
                    {"H_StrawHat",1},
                    {"H_StrawHat_dark",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"ItemGPS",1},
                    {"NVGoggles",1},
                    {"Binocular",1},
                    {"Rangefinder",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1},
                    {"ItemRadio",1}
                };
                semirare[] = {
                    {"Binocular",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                semicommon[] = {
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                common[] = {
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"dsr_item_sleepingbag",1}
                };
                semirare[] = {
                    {"dsr_item_campingchair",1}
                };
                average[] = {
                    {"dsr_item_sleepingmat",1}
                };
                semicommon[] = {
                    {"dsr_item_pillow",1},
                    {"dsr_item_sleepingmat",1}
                };
                common[] = {
                    {"dsr_item_pillow",1}
                };
            };
            class Construction {
                rare[] = {
                    {"dsr_item_butane_full",1},
                    {"dsr_item_propane_full",1},
                    {"dsr_item_metalwire",1},
                    {"dsr_item_multimeter",1}
                };
                semirare[] = {
                    {"dsr_item_butanetorch",1},
                    {"dsr_item_butane_empty",1},
                    {"dsr_item_propanecooker",1},
                    {"dsr_item_drill",1},
                    {"dsr_item_grinder",1},
                    {"dsr_item_tapemeasure",1},
                    {"dsr_item_fuelcan_full",1},
                    {"dsr_item_oilcan_full",1}
                };
                average[] = {
                    {"dsr_item_propane_empty",1},
                    {"dsr_item_pliers",1},
                    {"dsr_item_ducttape",1},
                    {"dsr_item_saw",1}
                };
                semicommon[] = {
                    {"dsr_item_canopener",1},
                    {"dsr_item_matches",1},
                    {"dsr_item_hammer",1},
                    {"dsr_item_fuelcan_empty",1},
                    {"dsr_item_oilcan_empty",1}
                };
                common[] = {
                    {"dsr_item_tincontainer",1},
                    {"dsr_item_nailfile",1},
                    {"dsr_item_screwdriver_flathead",1},
                    {"dsr_item_screwdriver_phillips",1},
                    {"dsr_item_bucket_empty",1},
                    {"dsr_item_plasticjug",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"ItemRadio",1},
                    {"ItemGPS",1},
                    {"dsr_item_battery_charged",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portablegenerator",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_satphone",1},
                    {"dsr_item_laptop",1}
                };
                semirare[] = {
                    {"ItemRadio",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_laptop",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"dsr_item_battery_dead",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_camera",1}
                };
                semicommon[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
                common[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
            };
            //Nothing Yet
            class CarPart {
                rare[] = {
                    {"dsr_item_log",1}
                };
                semirare[] = {
                    {"dsr_item_log",1}
                };
                average[] = {
                    {"dsr_item_log",1}
                };
                semicommon[] = {
                    {"dsr_item_log",1}
                };
                common[] = {
                    {"dsr_item_log",1}
                };
            };
            class Attachment {
                rare[] = {
                    {"optic_SOS",1},
                    {"optic_NVS",1},
                    {"optic_Nightstalker",1},
                    {"optic_tws",1},
                    {"optic_tws_mg",1},
                    {"optic_DMS",1},
                    {"optic_LRPS",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"bipod_01_F_mtp",1},
                    {"bipod_02_F_tan",1},
                    {"bipod_02_F_hex",1},
                    {"bipod_03_F_oli",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                semirare[] = {
                    {"optic_AMS",1},
                    {"optic_AMS_khk",1},
                    {"optic_AMS_snd",1},
                    {"optic_KHS_blk",1},
                    {"optic_KHS_hex",1},
                    {"optic_KHS_old",1},
                    {"optic_KHS_tan",1},
                    {"optic_MRCO",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                average[] = {
                    {"optic_Arco",1},
                    {"optic_Hamr",1},
                    {"optic_Holosight",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1}
                };
                semicommon[] = {
                    {"optic_Aco",1},
                    {"optic_ACO_grn",1},
                    {"optic_Aco_smg",1},
                    {"optic_ACO_grn_smg",1},
                    {"acc_flashlight",1}
                };
                common[] = {
                    {"optic_MRD",1},
                    {"optic_Yorris",1},
                    {"acc_flashlight",1}
                };
            };
        };
        class Civilian {
            class Weapon {
                rare[] = {
                    {"DSR_srifle_DMR_02",5},                //MAR-10
                    {"DSR_srifle_DMR_02_camo",5},           //MAR-10
                    {"DSR_srifle_DMR_02_sniper",5},         //MAR-10
                    {"DSR_srifle_DMR_03",6},                //Mk-I EMR
                    {"DSR_srifle_DMR_03_khaki",5},          //Mk-I EMR
                    {"DSR_srifle_DMR_03_tan",5},            //Mk-I EMR
                    {"DSR_srifle_DMR_03_multicam",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_03_woodland",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_04",4},                //ASP-1 Kir
                    {"DSR_srifle_DMR_04_Tan",5},            //ASP-1 Kir
                    {"DSR_srifle_DMR_05_blk",5},            //Cyrus
                    {"DSR_srifle_DMR_05_hex",5},            //Cyrus
                    {"DSR_srifle_DMR_05_tan",5},            //Cyrus
                    {"DSR_srifle_EBR",7},
                    {"DSR_srifle_GM6",1},
                    {"DSR_srifle_GM6_camo",1},
                    {"DSR_srifle_LRR",2},
                    {"DSR_srifle_LRR_camo",2},
                    {"DSR_LMG_Zafir",7},
                    {"DSR_MMG_01_hex",2},                   //Navid
                    {"DSR_MMG_01_tan",2},                   //Navid
                    {"DSR_MMG_02_camo",3},                  //SPMG
                    {"DSR_MMG_02_black",4},                 //SPMG
                    {"DSR_MMG_02_sand",4}                   //SPMG
                };
                semirare[] = {
                    {"DSR_arifle_MX_GL",17},
                    {"DSR_arifle_MX_GL_Black",16},
                    {"DSR_arifle_MX_SW",15},
                    {"DSR_arifle_MX_SW_Black",14},
                    {"DSR_arifle_MXM",13},
                    {"DSR_arifle_MXM_Black",12},
                    {"DSR_LMG_Mk200",6},
                    {"DSR_srifle_DMR_01",5},                 //Rahim
                    {"DSR_srifle_DMR_06_camo",1},            //Mk14
                    {"DSR_srifle_DMR_06_olive",1}            //Mk14
                };
                average[] = {
                    {"DSR_arifle_Katiba",20},
                    {"DSR_arifle_Katiba_C",18},
                    {"DSR_arifle_Katiba_GL",16},
                    {"DSR_arifle_MXC",13},
                    {"DSR_arifle_MXC_Black",12},
                    {"DSR_arifle_MX",11},
                    {"DSR_arifle_MX_Black",10}
                };
                semicommon[] = {
                    {"DSR_arifle_Katiba",37},
                    {"DSR_arifle_Katiba_C",32},
                    {"DSR_arifle_Katiba_GL",31}
                };
                common[] = {
                    {"DSR_SMG_01",45},
                    {"DSR_SMG_02",55}
                };
            };
            class Handgun {
                rare[] = {
                    {"DSR_hgun_PDW2000",1},
                    {"DSR_hgun_Pistol_heavy_01",35},    //4-five
                    {"DSR_hgun_Pistol_heavy_02",10},    //Zubr
                    {"DSR_hgun_P07",54}
                };
                semirare[] = {
                    {"DSR_hgun_Pistol_heavy_01",5},    //4-five
                    {"DSR_hgun_P07",40},
                    {"DSR_hgun_Rook",55}
                };
                average[] = {
                    {"DSR_hgun_ACPC2",55},
                    {"DSR_hgun_P07",10},
                    {"DSR_hgun_Rook",35}
                };
                semicommon[] = {
                    {"DSR_hgun_Rook",25},
                    {"DSR_hgun_ACPC2",75}
                };
                common[] = {
                    {"DSR_hgun_Pistol_Signal",45},
                    {"DSR_hgun_ACPC2",55}
                };
            };
            class Magazine {
                rare[] = {
                    {"100Rnd_580x42_Mag_F",13},
                    {"100Rnd_580x42_Mag_Tracer_F",12},
                    {"5Rnd_127x108_Mag",2},             //12.7 mm 5Rnd Mag
                    {"5Rnd_127x108_APDS_Mag",1},        //12.7mm 5Rnd APDS Mag
                    {"10Rnd_127x54_Mag",3},             //12.7mm 10Rnd Mag - ASPR
                    {"7Rnd_408_Mag",6},                 //.408 7Rnd LRR Mag
                    {"20Rnd_762x51_Mag",10},            //7.62 mm 20Rnd Mag
                    {"10Rnd_338_Mag",6},                //.338 LM 10Rnd Mag
                    {"10Rnd_93x64_DMR_05_Mag",3},       //9.3mm 10Rnd Mag
                    {"10Rnd_50BW_Mag_F",4},             //.50 BW 10Rnd Caseless Mag - Type 115
                    {"130Rnd_338_Mag",4},
                    {"150Rnd_762x54_Box",8},
                    {"150Rnd_762x54_Box_Tracer",7},
                    {"150Rnd_93x64_Mag",5},
                    {"1Rnd_HE_Grenade_shell",9},
                    {"3Rnd_HE_Grenade_shell",7}
                };
                semirare[] = {
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"30Rnd_65x39_caseless_mag",5},
                    {"30Rnd_65x39_caseless_green",4},
                    {"30Rnd_65x39_caseless_mag_Tracer",4},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",4},
                    {"10Rnd_762x54_Mag",3},                         //7.62 mm 10Rnd Mag - Rahim
                    {"30Rnd_762x39_Mag_F",2},
                    {"30Rnd_762x39_Mag_Green_F",1},
                    {"30Rnd_762x39_Mag_Tracer_F",1},
                    {"30Rnd_762x39_Mag_Tracer_Green_F",1},
                    {"30Rnd_580x42_Mag_F",3},
                    {"30Rnd_580x42_Mag_Tracer_F",2},
                    {"100Rnd_65x39_caseless_mag",3},
                    {"100Rnd_65x39_caseless_mag_Tracer",2},
                    {"200Rnd_65x39_cased_Box",3},
                    {"200Rnd_65x39_cased_Box_Tracer",2},
                    {"200Rnd_65x39_Belt_Tracer_Red",2},
                    {"200Rnd_65x39_Belt_Tracer_Green",2},
                    {"200Rnd_65x39_Belt_Tracer_Yellow",2},
                    {"150Rnd_762x54_Box",3},
                    {"150Rnd_762x54_Box_Tracer",2},
                    {"150Rnd_556x45_Drum_Mag_F",3},
                    {"150Rnd_556x45_Drum_Mag_Tracer_F",1},
                    {"200Rnd_556x45_Box_F",4},
                    {"200Rnd_556x45_Box_Red_F",3},
                    {"200Rnd_556x45_Box_Tracer_F",3},
                    {"200Rnd_556x45_Box_Tracer_Red_F",3}
                };
                average[] = {
                    {"30Rnd_545x39_Mag_F",12},
                    {"30Rnd_545x39_Mag_Green_F",11},
                    {"30Rnd_545x39_Mag_Tracer_F",11},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",10},
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"20Rnd_556x45_UW_mag",7},
                    {"30Rnd_65x39_caseless_mag",4},
                    {"30Rnd_65x39_caseless_green",3},
                    {"30Rnd_65x39_caseless_mag_Tracer",3},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",3},
                    {"20Rnd_650x39_Cased_Mag_F",5}
                };
                semicommon[] = {
                    {"30Rnd_545x39_Mag_F",3},
                    {"30Rnd_545x39_Mag_Green_F",2},
                    {"30Rnd_545x39_Mag_Tracer_F",2},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",2},
                    {"30Rnd_45ACP_Mag_SMG_01",10},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Green",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02",9},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Red",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Green",7},
                    {"30Rnd_9x21_Mag",9},
                    {"30Rnd_9x21_Red_Mag",7},
                    {"30Rnd_9x21_Yellow_Mag",7},
                    {"30Rnd_9x21_Green_Mag",7}
                };
                common[] = {
                    {"FlareWhite_F",9},
                    {"FlareGreen_F",9},
                    {"FlareRed_F",9},
                    {"FlareYellow_F",9},
                    {"6Rnd_GreenSignal_F",9},
                    {"6Rnd_RedSignal_F",9},
                    {"10Rnd_9x21_Mag",7},
                    {"16Rnd_9x21_Mag",4},
                    {"16Rnd_9x21_red_Mag",5},
                    {"16Rnd_9x21_green_Mag",5},
                    {"16Rnd_9x21_yellow_Mag",5},
                    {"11Rnd_45ACP_Mag",8},
                    {"9Rnd_45ACP_Mag",9},
                    {"6Rnd_45ACP_Cylinder",3}
                };
            };
			class Food {
                rare[] = {
                    {"dsr_item_beans",1}
                };
                semirare[] = {
                    {"dsr_item_cereal",1}
                };
                average[] = {
                    {"dsr_item_powderedmilk",1}
                };
                semicommon[] = {
                    {"dsr_item_rice",1}
                };
                common[] = {
                    {"dsr_item_bacon",1}
                };
            };
            class Drink {
                rare[] = {
                    {"dsr_item_waterbottle_full",1},
                    {"dsr_item_canteen_full",1}
                };
                semirare[] = {
                    {"dsr_item_rustyspirit",1},
                    {"dsr_item_spirit",1}
			};
                average[] = {
                    {"dsr_item_franta",1}
                };
                semicommon[] = {
                    {"dsr_item_waterbottle_empty",1},
                    {"dsr_item_canteen_empty",1}
                };
                common[] = {
                    {"dsr_item_waterbottle_dirty",1},
                    {"dsr_item_canteen_dirty",1}
                };
            };
            class Medical {
                rare[] = {
                    {"dsr_item_antibiotic",1},
                    {"dsr_item_bandage",1},
                    {"dsr_item_defibrillator",1},
                    {"dsr_item_bloodbag_full",1}
                };
                semirare[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_bloodbag_empty",1}
                };
                average[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_disinfectant",1},
                    {"dsr_item_painkillers",1},
                    {"dsr_item_waterpurificationtablets",1}
                };
                semicommon[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_handwarmer",1},
                    {"dsr_item_vitamins",1}
                };
                common[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_vitamins",1}
				};
            };
            class Junk {
                rare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                semirare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                average[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                semicommon[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                common[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"B_Carryall_oucamo",1},
                    {"B_Carryall_ocamo",1},
                    {"B_Carryall_khk",1},
                    {"B_Carryall_oli",1},
                    {"B_Carryall_cbr",1},
                    {"B_Carryall_mcamo",1},
                    //Special Need to Test (Some might spawn with gear in them)
                    {"I_Parachute_02_F",1},
                    {"B_Parachute_02_F",1},
                    {"B_AssaultPack_rgr_LAT",1},
                    {"B_AssaultPack_rgr_Medic",1},
                    {"B_AssaultPack_rgr_Repair",1},
                    {"B_AssaultPack_blk_DiverExp",1},
                    {"B_Kitbag_rgr_Exp",1},
                    {"B_FieldPack_blk_DiverExp",1},
                    {"B_FieldPack_ocamo_Medic",1},
                    {"B_FieldPack_cbr_LAT",1},
                    {"B_FieldPack_cbr_Repair",1},
                    {"B_Carryall_ocamo_Exp",1}
                };
                semirare[] = {
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_mcamo",1}
                };
                average[] = {
                    {"B_Bergen_blk",1},
                    {"B_Bergen_rgr",1},
                    {"B_Bergen_sgg",1},
                    {"B_Bergen_mcamo",1}
                };
                semicommon[] = {
                    {"B_HuntingBackpack",1},
                    {"B_OutdoorPack_blk",1},
                    {"B_OutdoorPack_blu",1},
                    {"B_OutdoorPack_tan",1},
                    {"B_FieldPack_blk",1},
                    {"B_FieldPack_oucamo",1},
                    {"B_FieldPack_ocamo",1},
                    {"B_FieldPack_cbr",1}
                };
                common[] = {
                    {"B_AssaultPack_blk",1},
                    {"B_AssaultPack_dgtl",1},
                    {"B_AssaultPack_khk",1},
                    {"B_AssaultPack_sgg",1},
                    {"B_AssaultPack_cbr",1},
                    {"B_AssaultPack_mcamo",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_B_CombatUniform_wdl",1},
                    {"U_B_CombatUniform_sgg",1},
                    {"U_B_CombatUniform_wdl_tshirt",1},
                    {"U_B_CombatUniform_sgg_tshirt",1},
                    {"U_O_SpecopsUniform_blk",1},
                    {"U_B_CombatUniform_wdl_vest",1},
                    {"U_B_CombatUniform_sgg_vest",1},
                    {"U_B_SpecopsUniform_sgg",1},
                    {"U_AttisBody",1},
                    {"U_AntigonaBody",1},
                    {"U_B_CombatUniform_mcam_worn",1},
                    {"U_B_CombatUniform_mcam_tshirt",1},
                    {"U_B_CombatUniform_mcam",1},
                    {"U_I_CombatUniform",1},
                    {"U_O_CombatUniform_ocamo",1},
                    {"U_O_CombatUniform_oucamo",1},
                    {"U_Competitor",1},
                    {"U_B_CTRG_1",1},
                    {"U_B_CTRG_3",1},
                    {"U_OG_leader",1},
                    {"U_BG_Guerilla1_1",1},
                    {"U_IG_Guerilla1_1",1},
                    {"U_OG_Guerilla1_1",1},
                    {"U_OG_Guerilla2_1",1},
                    {"U_IG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"U_IG_Guerilla2_2",1},
                    {"U_OG_Guerilla2_2",1},
                    {"U_BG_Guerilla2_3",1},
                    {"U_IG_Guerilla2_3",1},
                    {"U_OG_Guerilla2_3",1},
                    {"U_BG_Guerilla3_1",1},
                    {"U_IG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_2",1},
                    {"U_IG_Guerilla3_2",1},
                    {"U_BG_Guerilla3_2",1},
                    {"U_IG_Guerrilla_6_1",1},
                    {"U_BG_Guerrilla_6_1",1},
                    {"U_OG_Guerrilla_6_1",1},
                    {"U_BG_leader",1},
                    {"U_B_FullGhillie_ard",1},
                    {"U_B_FullGhillie_lsh",1},
                    {"U_B_FullGhillie_sard",1},
                    {"U_B_GhillieSuit",1},
                    {"U_B_CombatUniform_mcam_vest",1},
                    {"U_B_Wetsuit",1},
                    {"U_I_Wetsuit",1},
                    {"U_O_Wetsuit",1},
                    {"U_I_G_resistanceLeader_F",1},
                    {"U_IG_leader",1},
                    {"U_I_OfficerUniform",1},
                    {"U_I_CombatUniform_shortsleeve",1},
                    {"U_I_HeliPilotCoveralls",1},
                    {"U_I_pilotCoveralls",1},
                    {"U_I_CombatUniform_tshirt",1},
                    {"U_O_SpecopsUniform_ocamo",1},
                    {"U_O_OfficerUniform_ocamo",1},
                    {"U_O_PilotCoveralls",1}
                };
                semirare[] = {
                    {"U_B_survival_uniform",1},
                    {"U_B_CTRG_2",1},
                    {"U_Marshal",1},
                    {"U_NikosBody",1},
                    {"U_NikosAgedBody",1},
                    {"U_OrestesBody",1},
                    {"U_C_Scientist",1},
                    {"U_C_PriestBody",1},
                    {"U_KerryBody",1},
                    {"U_MillerBody",1},
                    {"U_Rangemaster",1},
                    {"U_B_HeliPilotCoveralls",1},
                    {"U_B_PilotCoveralls",1},
                    {"U_OI_Scientist",1}
                };
                average[] = {
                    {"U_C_Fisherman",1},
                    {"U_C_FishermanOveralls",1},
                    {"U_C_HunterBody_brn",1},
                    {"U_IG_Menelaos",1},
                    {"U_C_Novak",1}
                };
                semicommon[] = {
                    {"U_C_Commoner1_2",1},     
                    {"U_C_Commoner1_3",1},
                    {"U_C_Commoner2_1",1},
                    {"U_C_Commoner2_2",1},
                    {"U_C_Commoner2_3",1}
                };
                common[] = {
                    {"U_C_Poor_2",1},
                    {"U_C_Poor_1",1},
                    {"U_C_Poor_shorts_1",1},
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_burgundy",1},
                    {"U_C_Poloshirt_tricolour",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_redwhite",1},
                    {"U_C_WorkerOveralls",1},
                    {"U_C_Farmer",1},
                    {"U_C_Scavenger_2",1},
                    {"U_C_Scavenger_1",1},
                    {"U_C_Poor_shorts_2",1},
                    {"U_C_Journalist",1},
                    {"U_C_Poloshirt_stripped",1},
                    {"U_C_Commoner1_1",1},
                    {"U_C_Commoner_shorts",1},
                    {"U_C_ShirtSurfer_shorts",1},
                    {"U_C_TeeSurfer_shorts_1",1},
                    {"U_C_TeeSurfer_shorts_2",1},
                    {"U_C_WorkerCoveralls",1},
                    {"U_C_HunterBody_grn",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Chestrig_blk",1},
                    {"V_Chestrig_khk",1},
                    {"V_Chestrig_oli",1},
                    {"V_Chestrig_rgr",1},
                    {"V_PlateCarrier1_blk",1},
                    {"V_PlateCarrier1_rgr",1},
                    {"V_PlateCarrier2_rgr",1},
                    {"V_PlateCarrier3_rgr",1},
                    {"V_PlateCarrierGL_rgr",1},
                    {"V_PlateCarrierIA1_dgtl",1},
                    {"V_PlateCarrierIA2_dgtl",1},
                    {"V_PlateCarrierIAGL_dgtl",1},
                    {"V_PlateCarrierSpec_rgr",1},
                    {"V_I_G_resistanceLeader_F",1},
                    {"V_PlateCarrierSpec_blk",1},
                    {"V_PlateCarrierSpec_mtp",1},
                    {"V_PlateCarrierGL_mtp",1},
                    {"V_PlateCarrierGL_blk",1},
                    {"V_PlateCarrierIAGL_oli",1},
                    {"V_PlateCarrier_Kerry",1},
                    {"V_PlateCarrierL_CTRG",1},
                    {"V_PlateCarrierH_CTRG",1},
                    {"V_RebreatherB",1},
                    {"V_RebreatherIA",1},
                    {"V_RebreatherIR",1}
                };
                semirare[] = {
                    {"V_TacVest_blk",1},
                    {"V_TacVest_blk_POLICE",1},
                    {"V_TacVest_brn",1},
                    {"V_TacVest_camo",1},
                    {"V_TacVest_khk",1},
                    {"V_TacVest_oli",1},
                    {"V_TacVestCamo_khk",1},
                    {"V_TacVestIR_blk",1}
                };
                average[] = {
                    {"V_HarnessO_brn",1},
                    {"V_HarnessO_gry",1},
                    {"V_HarnessOGL_brn",1},
                    {"V_HarnessOGL_gry",1},
                    {"V_HarnessOSpec_brn",1},
                    {"V_HarnessOSpec_gry",1}
                };
                semicommon[] = {
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_blk",1},
                    {"V_BandollierB_cbr",1},
                    {"V_BandollierB_khk",1},
                    {"V_BandollierB_oli",1},
                    {"V_BandollierB_rgr",1}
                };
                common[] = {
                    {"V_Press_F",1},
                    {"V_Rangemaster_belt",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_HelmetB_camo",1},
                    {"H_HelmetB_grass",1},
                    {"H_HelmetB_black",1},
                    {"H_HelmetB_light",1},
                    {"H_HelmetB_sand",1},
                    {"H_HelmetB_desert",1},
                    {"H_HelmetB_light_black",1},
                    {"H_HelmetB_light_grass",1},
                    {"H_HelmetB_light_snakeskin",1},
                    {"H_HelmetB_light_desert",1},
                    {"H_HelmetB_light_sand",1},
                    {"H_HelmetB_snakeskin",1},
                    {"H_HelmetB_paint",1},
                    {"H_HelmetSpecB",1},
                    {"H_HelmetSpecB_paint1",1},
                    {"H_HelmetSpecB_blk",1},
                    {"H_HelmetSpecB_paint2",1},
                    {"H_HelmetSpecO_ocamo",1},
                    {"H_HelmetSpecO_blk",1},
                    {"H_HelmetB_plain_blk",1},
                    {"H_HelmetB_plain_mcamo",1},
                    {"H_HelmetB",1},
                    {"H_HelmetIA",1},
                    {"H_HelmetIA_net",1},
                    {"H_HelmetIA_camo",1},
                    {"H_HelmetO_ocamo",1},
                    {"H_HelmetO_oucamo",1},
                    {"H_HelmetLeaderO_ocamo",1},
                    {"H_HelmetLeaderO_oucamo",1}
                };
                semirare[] = {
                    {"H_Shemag_olive_hs",1},
                    {"H_ShemagOpen_tan",1},
                    {"H_ShemagOpen_khk",1},
                    {"H_Shemag_khk",1},
                    {"H_Shemag_tan",1},
                    {"H_Shemag_olive",1},
                    {"H_Helmet_Kerry",1},
                    {"H_HelmetCrew_B",1},
                    {"H_HelmetCrew_I",1},
                    {"H_HelmetCrew_O",1},
                    {"H_CrewHelmetHeli_I",1},
                    {"H_CrewHelmetHeli_B",1},
                    {"H_CrewHelmetHeli_O",1},
                    {"H_PilotHelmetHeli_B",1},
                    {"H_PilotHelmetHeli_I",1},
                    {"H_PilotHelmetHeli_O",1},
                    {"H_PilotHelmetFighter_B",1},
                    {"H_PilotHelmetFighter_I",1},
                    {"H_PilotHelmetFighter_O",1}
                };
                average[] = {
                    {"H_RacingHelmet_1_black_F",1},
                    {"H_RacingHelmet_1_blue_F",1},
                    {"H_RacingHelmet_1_green_F",1},
                    {"H_RacingHelmet_1_orange_F",1},
                    {"H_RacingHelmet_1_red_F",1},
                    {"H_RacingHelmet_1_white_F",1},
                    {"H_RacingHelmet_1_yellow_F",1},
                    {"H_Beret_grn",1},
                    {"H_Beret_blk",1},
                    {"H_Beret_blk_POLICE",1},
                    {"H_Beret_red",1},
                    {"H_Beret_brn_SF",1},
                    {"H_Beret_grn_SF",1},
                    {"H_Beret_02",1},
                    {"H_Beret_Colonel",1},
                    {"H_Beret_ocamo",1},
                    {"H_TurbanO_blk",1},
                    {"H_MilCap_blue",1},
                    {"H_MilCap_gry",1},
                    {"H_MilCap_ocamo",1},
                    {"H_MilCap_rucamo",1},
                    {"H_MilCap_oucamo",1},
                    {"H_MilCap_mcamo",1},
                    {"H_MilCap_dgtl",1}
                };
                semicommon[] = {
                    {"H_Booniehat_dirty",1},
                    {"H_Booniehat_khk_hs",1},
                    {"H_Booniehat_grn",1},
                    {"H_Booniehat_indp",1},
                    {"H_Booniehat_khk",1},
                    {"H_Booniehat_oli",1},
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_dgtl",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Cap_grn_BI",1},
                    {"H_Cap_blk",1},
                    {"H_Cap_blu",1},
                    {"H_Cap_oli",1},
                    {"H_Cap_grn",1},
                    {"H_Cap_red",1},
                    {"H_Cap_surfer",1},
                    {"H_Cap_tan",1},
                    {"H_Cap_blk_CMMG",1},
                    {"H_Cap_blk_ION",1},
                    {"H_Cap_oli_hs",1},
                    {"H_Cap_police",1},
                    {"H_Cap_usblack",1},
                    {"H_Cap_tan_specops_US",1},
                    {"H_Cap_blk_Raven",1},
                    {"H_Cap_brn_SPECOPS",1},
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_headphones",1},
                    {"H_Cap_press",1},
                    {"H_Cap_marshal",1},
                    {"H_Watchcap_camo",1},
                    {"H_Watchcap_blk",1},
                    {"H_Hat_blue",1},
                    {"H_Hat_brown",1},
                    {"H_Hat_camo",1},
                    {"H_Hat_checker",1},
                    {"H_Hat_grey",1},
                    {"H_Hat_tan",1}
                };
                common[] = {
                    {"H_Bandanna_gry",1},
                    {"H_Bandanna_blu",1},
                    {"H_Bandanna_cbr",1},
                    {"H_Bandanna_mcamo",1},
                    {"H_Bandanna_sgg",1},
                    {"H_Bandanna_sand",1},
                    {"H_Bandanna_surfer",1},
                    {"H_Bandanna_surfer_blk",1},
                    {"H_Bandanna_surfer_grn",1},
                    {"H_Bandanna_camo",1},
                    {"H_Bandanna_khk",1},
                    {"H_Bandanna_khk_hs",1},
                    {"H_BandMask_blk",1},
                    {"H_BandMask_demon",1},
                    {"H_BandMask_khk",1},
                    {"H_BandMask_reaper",1},
                    {"H_Watchcap_cbr",1},
                    {"H_Watchcap_khk",1},
                    {"H_Watchcap_sgg",1},
                    {"H_StrawHat",1},
                    {"H_StrawHat_dark",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"ItemGPS",1},
                    {"NVGoggles",1},
                    {"Binocular",1},
                    {"Rangefinder",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1},
                    {"ItemRadio",1}
                };
                semirare[] = {
                    {"Binocular",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                semicommon[] = {
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                common[] = {
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_hgun_P07",1}
                };
                semirare[] = {
                    {"DSR_hgun_P07",1}
                };
                average[] = {
                    {"DSR_hgun_P07",1}
                };
                semicommon[] = {
                    {"DSR_hgun_P07",1}
                };
                common[] = {
                    {"DSR_hgun_P07",1}
                };
            };
            class Construction {
                rare[] = {
                    {"dsr_item_butane_full",1},
                    {"dsr_item_propane_full",1},
                    {"dsr_item_metalwire",1},
                    {"dsr_item_multimeter",1}
                };
                semirare[] = {
                    {"dsr_item_butanetorch",1},
                    {"dsr_item_butane_empty",1},
                    {"dsr_item_propanecooker",1},
                    {"dsr_item_drill",1},
                    {"dsr_item_grinder",1},
                    {"dsr_item_tapemeasure",1},
                    {"dsr_item_fuelcan_full",1},
                    {"dsr_item_oilcan_full",1}
                };
                average[] = {
                    {"dsr_item_propane_empty",1},
                    {"dsr_item_pliers",1},
                    {"dsr_item_ducttape",1},
                    {"dsr_item_saw",1}
                };
                semicommon[] = {
                    {"dsr_item_canopener",1},
                    {"dsr_item_matches",1},
                    {"dsr_item_hammer",1},
                    {"dsr_item_fuelcan_empty",1},
                    {"dsr_item_oilcan_empty",1}
                };
                common[] = {
                    {"dsr_item_tincontainer",1},
                    {"dsr_item_nailfile",1},
                    {"dsr_item_screwdriver_flathead",1},
                    {"dsr_item_screwdriver_phillips",1},
                    {"dsr_item_bucket_empty",1},
                    {"dsr_item_plasticjug",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"ItemRadio",1},
                    {"ItemGPS",1},
                    {"dsr_item_battery_charged",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portablegenerator",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_satphone",1},
                    {"dsr_item_laptop",1}
                };
                semirare[] = {
                    {"ItemRadio",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_laptop",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"dsr_item_battery_dead",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_camera",1}
			};
                semicommon[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
                common[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
            };
            //Nothing Yet
            class CarPart {
                rare[] = {
                    {"dsr_item_log",1}
                };
                semirare[] = {
                    {"dsr_item_log",1}
                };
                average[] = {
                    {"dsr_item_log",1}
                };
                semicommon[] = {
                    {"dsr_item_log",1}
                };
                common[] = {
                    {"dsr_item_log",1}
                };
            };
            class Attachment {
                rare[] = {
                    {"optic_SOS",1},
                    {"optic_NVS",1},
                    {"optic_Nightstalker",1},
                    {"optic_tws",1},
                    {"optic_tws_mg",1},
                    {"optic_DMS",1},
                    {"optic_LRPS",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"bipod_01_F_mtp",1},
                    {"bipod_02_F_tan",1},
                    {"bipod_02_F_hex",1},
                    {"bipod_03_F_oli",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                semirare[] = {
                    {"optic_AMS",1},
                    {"optic_AMS_khk",1},
                    {"optic_AMS_snd",1},
                    {"optic_KHS_blk",1},
                    {"optic_KHS_hex",1},
                    {"optic_KHS_old",1},
                    {"optic_KHS_tan",1},
                    {"optic_MRCO",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                average[] = {
                    {"optic_Arco",1},
                    {"optic_Hamr",1},
                    {"optic_Holosight",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1}
                };
                semicommon[] = {
                    {"optic_Aco",1},
                    {"optic_ACO_grn",1},
                    {"optic_Aco_smg",1},
                    {"optic_ACO_grn_smg",1},
                    {"acc_flashlight",1}
                };
                common[] = {
                    {"optic_MRD",1},
                    {"optic_Yorris",1},
                    {"acc_flashlight",1}
                };
            };
        };
        class Industrial {
            class Weapon {
                rare[] = {
                    {"DSR_srifle_DMR_02",5},                //MAR-10
                    {"DSR_srifle_DMR_02_camo",5},           //MAR-10
                    {"DSR_srifle_DMR_02_sniper",5},         //MAR-10
                    {"DSR_srifle_DMR_03",6},                //Mk-I EMR
                    {"DSR_srifle_DMR_03_khaki",5},          //Mk-I EMR
                    {"DSR_srifle_DMR_03_tan",5},            //Mk-I EMR
                    {"DSR_srifle_DMR_03_multicam",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_03_woodland",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_04",4},                //ASP-1 Kir
                    {"DSR_srifle_DMR_04_Tan",5},            //ASP-1 Kir
                    {"DSR_srifle_DMR_05_blk",5},            //Cyrus
                    {"DSR_srifle_DMR_05_hex",5},            //Cyrus
                    {"DSR_srifle_DMR_05_tan",5},            //Cyrus
                    {"DSR_srifle_EBR",7},
                    {"DSR_srifle_GM6",1},
                    {"DSR_srifle_GM6_camo",1},
                    {"DSR_srifle_LRR",2},
                    {"DSR_srifle_LRR_camo",2},
                    {"DSR_LMG_Zafir",7},
                    {"DSR_MMG_01_hex",2},                   //Navid
                    {"DSR_MMG_01_tan",2},                   //Navid
                    {"DSR_MMG_02_camo",3},                  //SPMG
                    {"DSR_MMG_02_black",4},                 //SPMG
                    {"DSR_MMG_02_sand",4}                   //SPMG
                };
                semirare[] = {
                    {"DSR_arifle_MX_GL",17},
                    {"DSR_arifle_MX_GL_Black",16},
                    {"DSR_arifle_MX_SW",15},
                    {"DSR_arifle_MX_SW_Black",14},
                    {"DSR_arifle_MXM",13},
                    {"DSR_arifle_MXM_Black",12},
                    {"DSR_LMG_Mk200",6},
                    {"DSR_srifle_DMR_01",5},                 //Rahim
                    {"DSR_srifle_DMR_06_camo",1},            //Mk14
                    {"DSR_srifle_DMR_06_olive",1}            //Mk14
                };
                average[] = {
                    {"DSR_arifle_Katiba",20},
                    {"DSR_arifle_Katiba_C",18},
                    {"DSR_arifle_Katiba_GL",16},
                    {"DSR_arifle_MXC",13},
                    {"DSR_arifle_MXC_Black",12},
                    {"DSR_arifle_MX",11},
                    {"DSR_arifle_MX_Black",10}
                };
                semicommon[] = {
                    {"DSR_arifle_Katiba",37},
                    {"DSR_arifle_Katiba_C",32},
                    {"DSR_arifle_Katiba_GL",31}
                };
                common[] = {
                    {"DSR_SMG_01",45},
                    {"DSR_SMG_02",55}
                };
            };
            class Handgun {
                rare[] = {
                    {"DSR_hgun_PDW2000",1},
                    {"DSR_hgun_Pistol_heavy_01",35},    //4-five
                    {"DSR_hgun_Pistol_heavy_02",10},    //Zubr
                    {"DSR_hgun_P07",54}
                };
                semirare[] = {
                    {"DSR_hgun_Pistol_heavy_01",5},    //4-five
                    {"DSR_hgun_P07",40},
                    {"DSR_hgun_Rook",55}
                };
                average[] = {
                    {"DSR_hgun_ACPC2",55},
                    {"DSR_hgun_P07",10},
                    {"DSR_hgun_Rook",35}
                };
                semicommon[] = {
                    {"DSR_hgun_Rook",25},
                    {"DSR_hgun_ACPC2",75}
                };
                common[] = {
                    {"DSR_hgun_Pistol_Signal",45},
                    {"DSR_hgun_ACPC2",55}
                };
            };
            class Magazine {
                rare[] = {
                    {"100Rnd_580x42_Mag_F",13},
                    {"100Rnd_580x42_Mag_Tracer_F",12},
                    {"5Rnd_127x108_Mag",2},             //12.7 mm 5Rnd Mag
                    {"5Rnd_127x108_APDS_Mag",1},        //12.7mm 5Rnd APDS Mag
                    {"10Rnd_127x54_Mag",3},             //12.7mm 10Rnd Mag - ASPR
                    {"7Rnd_408_Mag",6},                 //.408 7Rnd LRR Mag
                    {"20Rnd_762x51_Mag",10},            //7.62 mm 20Rnd Mag
                    {"10Rnd_338_Mag",6},                //.338 LM 10Rnd Mag
                    {"10Rnd_93x64_DMR_05_Mag",3},       //9.3mm 10Rnd Mag
                    {"10Rnd_50BW_Mag_F",4},             //.50 BW 10Rnd Caseless Mag - Type 115
                    {"130Rnd_338_Mag",4},
                    {"150Rnd_762x54_Box",8},
                    {"150Rnd_762x54_Box_Tracer",7},
                    {"150Rnd_93x64_Mag",5},
                    {"1Rnd_HE_Grenade_shell",9},
                    {"3Rnd_HE_Grenade_shell",7}
                };
                semirare[] = {
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"30Rnd_65x39_caseless_mag",5},
                    {"30Rnd_65x39_caseless_green",4},
                    {"30Rnd_65x39_caseless_mag_Tracer",4},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",4},
                    {"10Rnd_762x54_Mag",3},                         //7.62 mm 10Rnd Mag - Rahim
                    {"30Rnd_762x39_Mag_F",2},
                    {"30Rnd_762x39_Mag_Green_F",1},
                    {"30Rnd_762x39_Mag_Tracer_F",1},
                    {"30Rnd_762x39_Mag_Tracer_Green_F",1},
                    {"30Rnd_580x42_Mag_F",3},
                    {"30Rnd_580x42_Mag_Tracer_F",2},
                    {"100Rnd_65x39_caseless_mag",3},
                    {"100Rnd_65x39_caseless_mag_Tracer",2},
                    {"200Rnd_65x39_cased_Box",3},
                    {"200Rnd_65x39_cased_Box_Tracer",2},
                    {"200Rnd_65x39_Belt_Tracer_Red",2},
                    {"200Rnd_65x39_Belt_Tracer_Green",2},
                    {"200Rnd_65x39_Belt_Tracer_Yellow",2},
                    {"150Rnd_762x54_Box",3},
                    {"150Rnd_762x54_Box_Tracer",2},
                    {"150Rnd_556x45_Drum_Mag_F",3},
                    {"150Rnd_556x45_Drum_Mag_Tracer_F",1},
                    {"200Rnd_556x45_Box_F",4},
                    {"200Rnd_556x45_Box_Red_F",3},
                    {"200Rnd_556x45_Box_Tracer_F",3},
                    {"200Rnd_556x45_Box_Tracer_Red_F",3}
                };
                average[] = {
                    {"30Rnd_545x39_Mag_F",12},
                    {"30Rnd_545x39_Mag_Green_F",11},
                    {"30Rnd_545x39_Mag_Tracer_F",11},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",10},
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"20Rnd_556x45_UW_mag",7},
                    {"30Rnd_65x39_caseless_mag",4},
                    {"30Rnd_65x39_caseless_green",3},
                    {"30Rnd_65x39_caseless_mag_Tracer",3},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",3},
                    {"20Rnd_650x39_Cased_Mag_F",5}
                };
                semicommon[] = {
                    {"30Rnd_545x39_Mag_F",3},
                    {"30Rnd_545x39_Mag_Green_F",2},
                    {"30Rnd_545x39_Mag_Tracer_F",2},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",2},
                    {"30Rnd_45ACP_Mag_SMG_01",10},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Green",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02",9},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Red",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Green",7},
                    {"30Rnd_9x21_Mag",9},
                    {"30Rnd_9x21_Red_Mag",7},
                    {"30Rnd_9x21_Yellow_Mag",7},
                    {"30Rnd_9x21_Green_Mag",7}
                };
                common[] = {
                    {"FlareWhite_F",9},
                    {"FlareGreen_F",9},
                    {"FlareRed_F",9},
                    {"FlareYellow_F",9},
                    {"6Rnd_GreenSignal_F",9},
                    {"6Rnd_RedSignal_F",9},
                    {"10Rnd_9x21_Mag",7},
                    {"16Rnd_9x21_Mag",4},
                    {"16Rnd_9x21_red_Mag",5},
                    {"16Rnd_9x21_green_Mag",5},
                    {"16Rnd_9x21_yellow_Mag",5},
                    {"11Rnd_45ACP_Mag",8},
                    {"9Rnd_45ACP_Mag",9},
                    {"6Rnd_45ACP_Cylinder",3}
                };
            };
			class Food {
                rare[] = {
                    {"dsr_item_beans",1}
                };
                semirare[] = {
                    {"dsr_item_cereal",1}
                };
                average[] = {
                    {"dsr_item_powderedmilk",1}
                };
                semicommon[] = {
                    {"dsr_item_rice",1}
                };
                common[] = {
                    {"dsr_item_bacon",1}
                };
            };
            class Drink {
                rare[] = {
                    {"dsr_item_waterbottle_full",1},
                    {"dsr_item_canteen_full",1}
                };
                semirare[] = {
                    {"dsr_item_rustyspirit",1},
                    {"dsr_item_spirit",1}
			};
                average[] = {
                    {"dsr_item_franta",1}
                };
                semicommon[] = {
                    {"dsr_item_waterbottle_empty",1},
                    {"dsr_item_canteen_empty",1}
                };
                common[] = {
                    {"dsr_item_waterbottle_dirty",1},
                    {"dsr_item_canteen_dirty",1}
                };
            };
            class Medical {
                rare[] = {
                    {"dsr_item_antibiotic",1},
                    {"dsr_item_bandage",1},
                    {"dsr_item_defibrillator",1},
                    {"dsr_item_bloodbag_full",1}
                };
                semirare[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_bloodbag_empty",1}
                };
                average[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_disinfectant",1},
                    {"dsr_item_painkillers",1},
                    {"dsr_item_waterpurificationtablets",1}
                };
                semicommon[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_handwarmer",1},
                    {"dsr_item_vitamins",1}
                };
                common[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_vitamins",1}
			};
            };
            class Junk {
                rare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                semirare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                average[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                semicommon[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                common[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"B_Carryall_oucamo",1},
                    {"B_Carryall_ocamo",1},
                    {"B_Carryall_khk",1},
                    {"B_Carryall_oli",1},
                    {"B_Carryall_cbr",1},
                    {"B_Carryall_mcamo",1},
                    //Special Need to Test (Some might spawn with gear in them)
                    {"I_Parachute_02_F",1},
                    {"B_Parachute_02_F",1},
                    {"B_AssaultPack_rgr_LAT",1},
                    {"B_AssaultPack_rgr_Medic",1},
                    {"B_AssaultPack_rgr_Repair",1},
                    {"B_AssaultPack_blk_DiverExp",1},
                    {"B_Kitbag_rgr_Exp",1},
                    {"B_FieldPack_blk_DiverExp",1},
                    {"B_FieldPack_ocamo_Medic",1},
                    {"B_FieldPack_cbr_LAT",1},
                    {"B_FieldPack_cbr_Repair",1},
                    {"B_Carryall_ocamo_Exp",1}
                };
                semirare[] = {
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_mcamo",1}
                };
                average[] = {
                    {"B_Bergen_blk",1},
                    {"B_Bergen_rgr",1},
                    {"B_Bergen_sgg",1},
                    {"B_Bergen_mcamo",1}
                };
                semicommon[] = {
                    {"B_HuntingBackpack",1},
                    {"B_OutdoorPack_blk",1},
                    {"B_OutdoorPack_blu",1},
                    {"B_OutdoorPack_tan",1},
                    {"B_FieldPack_blk",1},
                    {"B_FieldPack_oucamo",1},
                    {"B_FieldPack_ocamo",1},
                    {"B_FieldPack_cbr",1}
                };
                common[] = {
                    {"B_AssaultPack_blk",1},
                    {"B_AssaultPack_dgtl",1},
                    {"B_AssaultPack_khk",1},
                    {"B_AssaultPack_sgg",1},
                    {"B_AssaultPack_cbr",1},
                    {"B_AssaultPack_mcamo",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_B_CombatUniform_wdl",1},
                    {"U_B_CombatUniform_sgg",1},
                    {"U_B_CombatUniform_wdl_tshirt",1},
                    {"U_B_CombatUniform_sgg_tshirt",1},
                    {"U_O_SpecopsUniform_blk",1},
                    {"U_B_CombatUniform_wdl_vest",1},
                    {"U_B_CombatUniform_sgg_vest",1},
                    {"U_B_SpecopsUniform_sgg",1},
                    {"U_AttisBody",1},
                    {"U_AntigonaBody",1},
                    {"U_B_CombatUniform_mcam_worn",1},
                    {"U_B_CombatUniform_mcam_tshirt",1},
                    {"U_B_CombatUniform_mcam",1},
                    {"U_I_CombatUniform",1},
                    {"U_O_CombatUniform_ocamo",1},
                    {"U_O_CombatUniform_oucamo",1},
                    {"U_Competitor",1},
                    {"U_B_CTRG_1",1},
                    {"U_B_CTRG_3",1},
                    {"U_OG_leader",1},
                    {"U_BG_Guerilla1_1",1},
                    {"U_IG_Guerilla1_1",1},
                    {"U_OG_Guerilla1_1",1},
                    {"U_OG_Guerilla2_1",1},
                    {"U_IG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"U_IG_Guerilla2_2",1},
                    {"U_OG_Guerilla2_2",1},
                    {"U_BG_Guerilla2_3",1},
                    {"U_IG_Guerilla2_3",1},
                    {"U_OG_Guerilla2_3",1},
                    {"U_BG_Guerilla3_1",1},
                    {"U_IG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_2",1},
                    {"U_IG_Guerilla3_2",1},
                    {"U_BG_Guerilla3_2",1},
                    {"U_IG_Guerrilla_6_1",1},
                    {"U_BG_Guerrilla_6_1",1},
                    {"U_OG_Guerrilla_6_1",1},
                    {"U_BG_leader",1},
                    {"U_B_FullGhillie_ard",1},
                    {"U_B_FullGhillie_lsh",1},
                    {"U_B_FullGhillie_sard",1},
                    {"U_B_GhillieSuit",1},
                    {"U_B_CombatUniform_mcam_vest",1},
                    {"U_B_Wetsuit",1},
                    {"U_I_Wetsuit",1},
                    {"U_O_Wetsuit",1},
                    {"U_I_G_resistanceLeader_F",1},
                    {"U_IG_leader",1},
                    {"U_I_OfficerUniform",1},
                    {"U_I_CombatUniform_shortsleeve",1},
                    {"U_I_HeliPilotCoveralls",1},
                    {"U_I_pilotCoveralls",1},
                    {"U_I_CombatUniform_tshirt",1},
                    {"U_O_SpecopsUniform_ocamo",1},
                    {"U_O_OfficerUniform_ocamo",1},
                    {"U_O_PilotCoveralls",1}
                };
                semirare[] = {
                    {"U_B_survival_uniform",1},
                    {"U_B_CTRG_2",1},
                    {"U_Marshal",1},
                    {"U_NikosBody",1},
                    {"U_NikosAgedBody",1},
                    {"U_OrestesBody",1},
                    {"U_C_Scientist",1},
                    {"U_C_PriestBody",1},
                    {"U_KerryBody",1},
                    {"U_MillerBody",1},
                    {"U_Rangemaster",1},
                    {"U_B_HeliPilotCoveralls",1},
                    {"U_B_PilotCoveralls",1},
                    {"U_OI_Scientist",1}
                };
                average[] = {
                    {"U_C_Fisherman",1},
                    {"U_C_FishermanOveralls",1},
                    {"U_C_HunterBody_brn",1},
                    {"U_IG_Menelaos",1},
                    {"U_C_Novak",1}
                };
                semicommon[] = {
                    {"U_C_Commoner1_2",1},     
                    {"U_C_Commoner1_3",1},
                    {"U_C_Commoner2_1",1},
                    {"U_C_Commoner2_2",1},
                    {"U_C_Commoner2_3",1}
                };
                common[] = {
                    {"U_C_Poor_2",1},
                    {"U_C_Poor_1",1},
                    {"U_C_Poor_shorts_1",1},
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_burgundy",1},
                    {"U_C_Poloshirt_tricolour",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_redwhite",1},
                    {"U_C_WorkerOveralls",1},
                    {"U_C_Farmer",1},
                    {"U_C_Scavenger_2",1},
                    {"U_C_Scavenger_1",1},
                    {"U_C_Poor_shorts_2",1},
                    {"U_C_Journalist",1},
                    {"U_C_Poloshirt_stripped",1},
                    {"U_C_Commoner1_1",1},
                    {"U_C_Commoner_shorts",1},
                    {"U_C_ShirtSurfer_shorts",1},
                    {"U_C_TeeSurfer_shorts_1",1},
                    {"U_C_TeeSurfer_shorts_2",1},
                    {"U_C_WorkerCoveralls",1},
                    {"U_C_HunterBody_grn",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Chestrig_blk",1},
                    {"V_Chestrig_khk",1},
                    {"V_Chestrig_oli",1},
                    {"V_Chestrig_rgr",1},
                    {"V_PlateCarrier1_blk",1},
                    {"V_PlateCarrier1_rgr",1},
                    {"V_PlateCarrier2_rgr",1},
                    {"V_PlateCarrier3_rgr",1},
                    {"V_PlateCarrierGL_rgr",1},
                    {"V_PlateCarrierIA1_dgtl",1},
                    {"V_PlateCarrierIA2_dgtl",1},
                    {"V_PlateCarrierIAGL_dgtl",1},
                    {"V_PlateCarrierSpec_rgr",1},
                    {"V_I_G_resistanceLeader_F",1},
                    {"V_PlateCarrierSpec_blk",1},
                    {"V_PlateCarrierSpec_mtp",1},
                    {"V_PlateCarrierGL_mtp",1},
                    {"V_PlateCarrierGL_blk",1},
                    {"V_PlateCarrierIAGL_oli",1},
                    {"V_PlateCarrier_Kerry",1},
                    {"V_PlateCarrierL_CTRG",1},
                    {"V_PlateCarrierH_CTRG",1},
                    {"V_RebreatherB",1},
                    {"V_RebreatherIA",1},
                    {"V_RebreatherIR",1}
                };
                semirare[] = {
                    {"V_TacVest_blk",1},
                    {"V_TacVest_blk_POLICE",1},
                    {"V_TacVest_brn",1},
                    {"V_TacVest_camo",1},
                    {"V_TacVest_khk",1},
                    {"V_TacVest_oli",1},
                    {"V_TacVestCamo_khk",1},
                    {"V_TacVestIR_blk",1}
                };
                average[] = {
                    {"V_HarnessO_brn",1},
                    {"V_HarnessO_gry",1},
                    {"V_HarnessOGL_brn",1},
                    {"V_HarnessOGL_gry",1},
                    {"V_HarnessOSpec_brn",1},
                    {"V_HarnessOSpec_gry",1}
                };
                semicommon[] = {
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_blk",1},
                    {"V_BandollierB_cbr",1},
                    {"V_BandollierB_khk",1},
                    {"V_BandollierB_oli",1},
                    {"V_BandollierB_rgr",1}
                };
                common[] = {
                    {"V_Press_F",1},
                    {"V_Rangemaster_belt",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_HelmetB_camo",1},
                    {"H_HelmetB_grass",1},
                    {"H_HelmetB_black",1},
                    {"H_HelmetB_light",1},
                    {"H_HelmetB_sand",1},
                    {"H_HelmetB_desert",1},
                    {"H_HelmetB_light_black",1},
                    {"H_HelmetB_light_grass",1},
                    {"H_HelmetB_light_snakeskin",1},
                    {"H_HelmetB_light_desert",1},
                    {"H_HelmetB_light_sand",1},
                    {"H_HelmetB_snakeskin",1},
                    {"H_HelmetB_paint",1},
                    {"H_HelmetSpecB",1},
                    {"H_HelmetSpecB_paint1",1},
                    {"H_HelmetSpecB_blk",1},
                    {"H_HelmetSpecB_paint2",1},
                    {"H_HelmetSpecO_ocamo",1},
                    {"H_HelmetSpecO_blk",1},
                    {"H_HelmetB_plain_blk",1},
                    {"H_HelmetB_plain_mcamo",1},
                    {"H_HelmetB",1},
                    {"H_HelmetIA",1},
                    {"H_HelmetIA_net",1},
                    {"H_HelmetIA_camo",1},
                    {"H_HelmetO_ocamo",1},
                    {"H_HelmetO_oucamo",1},
                    {"H_HelmetLeaderO_ocamo",1},
                    {"H_HelmetLeaderO_oucamo",1}
                };
                semirare[] = {
                    {"H_Shemag_olive_hs",1},
                    {"H_ShemagOpen_tan",1},
                    {"H_ShemagOpen_khk",1},
                    {"H_Shemag_khk",1},
                    {"H_Shemag_tan",1},
                    {"H_Shemag_olive",1},
                    {"H_Helmet_Kerry",1},
                    {"H_HelmetCrew_B",1},
                    {"H_HelmetCrew_I",1},
                    {"H_HelmetCrew_O",1},
                    {"H_CrewHelmetHeli_I",1},
                    {"H_CrewHelmetHeli_B",1},
                    {"H_CrewHelmetHeli_O",1},
                    {"H_PilotHelmetHeli_B",1},
                    {"H_PilotHelmetHeli_I",1},
                    {"H_PilotHelmetHeli_O",1},
                    {"H_PilotHelmetFighter_B",1},
                    {"H_PilotHelmetFighter_I",1},
                    {"H_PilotHelmetFighter_O",1}
                };
                average[] = {
                    {"H_RacingHelmet_1_black_F",1},
                    {"H_RacingHelmet_1_blue_F",1},
                    {"H_RacingHelmet_1_green_F",1},
                    {"H_RacingHelmet_1_orange_F",1},
                    {"H_RacingHelmet_1_red_F",1},
                    {"H_RacingHelmet_1_white_F",1},
                    {"H_RacingHelmet_1_yellow_F",1},
                    {"H_Beret_grn",1},
                    {"H_Beret_blk",1},
                    {"H_Beret_blk_POLICE",1},
                    {"H_Beret_red",1},
                    {"H_Beret_brn_SF",1},
                    {"H_Beret_grn_SF",1},
                    {"H_Beret_02",1},
                    {"H_Beret_Colonel",1},
                    {"H_Beret_ocamo",1},
                    {"H_TurbanO_blk",1},
                    {"H_MilCap_blue",1},
                    {"H_MilCap_gry",1},
                    {"H_MilCap_ocamo",1},
                    {"H_MilCap_rucamo",1},
                    {"H_MilCap_oucamo",1},
                    {"H_MilCap_mcamo",1},
                    {"H_MilCap_dgtl",1}
                };
                semicommon[] = {
                    {"H_Booniehat_dirty",1},
                    {"H_Booniehat_khk_hs",1},
                    {"H_Booniehat_grn",1},
                    {"H_Booniehat_indp",1},
                    {"H_Booniehat_khk",1},
                    {"H_Booniehat_oli",1},
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_dgtl",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Cap_grn_BI",1},
                    {"H_Cap_blk",1},
                    {"H_Cap_blu",1},
                    {"H_Cap_oli",1},
                    {"H_Cap_grn",1},
                    {"H_Cap_red",1},
                    {"H_Cap_surfer",1},
                    {"H_Cap_tan",1},
                    {"H_Cap_blk_CMMG",1},
                    {"H_Cap_blk_ION",1},
                    {"H_Cap_oli_hs",1},
                    {"H_Cap_police",1},
                    {"H_Cap_usblack",1},
                    {"H_Cap_tan_specops_US",1},
                    {"H_Cap_blk_Raven",1},
                    {"H_Cap_brn_SPECOPS",1},
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_headphones",1},
                    {"H_Cap_press",1},
                    {"H_Cap_marshal",1},
                    {"H_Watchcap_camo",1},
                    {"H_Watchcap_blk",1},
                    {"H_Hat_blue",1},
                    {"H_Hat_brown",1},
                    {"H_Hat_camo",1},
                    {"H_Hat_checker",1},
                    {"H_Hat_grey",1},
                    {"H_Hat_tan",1}
                };
                common[] = {
                    {"H_Bandanna_gry",1},
                    {"H_Bandanna_blu",1},
                    {"H_Bandanna_cbr",1},
                    {"H_Bandanna_mcamo",1},
                    {"H_Bandanna_sgg",1},
                    {"H_Bandanna_sand",1},
                    {"H_Bandanna_surfer",1},
                    {"H_Bandanna_surfer_blk",1},
                    {"H_Bandanna_surfer_grn",1},
                    {"H_Bandanna_camo",1},
                    {"H_Bandanna_khk",1},
                    {"H_Bandanna_khk_hs",1},
                    {"H_BandMask_blk",1},
                    {"H_BandMask_demon",1},
                    {"H_BandMask_khk",1},
                    {"H_BandMask_reaper",1},
                    {"H_Watchcap_cbr",1},
                    {"H_Watchcap_khk",1},
                    {"H_Watchcap_sgg",1},
                    {"H_StrawHat",1},
                    {"H_StrawHat_dark",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"ItemGPS",1},
                    {"NVGoggles",1},
                    {"Binocular",1},
                    {"Rangefinder",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1},
                    {"ItemRadio",1}
                };
                semirare[] = {
                    {"Binocular",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                semicommon[] = {
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                common[] = {
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_hgun_P07",1}
                };
                semirare[] = {
                    {"DSR_hgun_P07",1}
                };
                average[] = {
                    {"DSR_hgun_P07",1}
                };
                semicommon[] = {
                    {"DSR_hgun_P07",1}
                };
                common[] = {
                    {"DSR_hgun_P07",1}
                };
            };
            class Construction {
                rare[] = {
                    {"dsr_item_butane_full",1},
                    {"dsr_item_propane_full",1},
                    {"dsr_item_metalwire",1},
                    {"dsr_item_multimeter",1}
                };
                semirare[] = {
                    {"dsr_item_butanetorch",1},
                    {"dsr_item_butane_empty",1},
                    {"dsr_item_propanecooker",1},
                    {"dsr_item_drill",1},
                    {"dsr_item_grinder",1},
                    {"dsr_item_tapemeasure",1},
                    {"dsr_item_fuelcan_full",1},
                    {"dsr_item_oilcan_full",1}
                };
                average[] = {
                    {"dsr_item_propane_empty",1},
                    {"dsr_item_pliers",1},
                    {"dsr_item_ducttape",1},
                    {"dsr_item_saw",1}
                };
                semicommon[] = {
                    {"dsr_item_canopener",1},
                    {"dsr_item_matches",1},
                    {"dsr_item_hammer",1},
                    {"dsr_item_fuelcan_empty",1},
                    {"dsr_item_oilcan_empty",1}
                };
                common[] = {
                    {"dsr_item_tincontainer",1},
                    {"dsr_item_nailfile",1},
                    {"dsr_item_screwdriver_flathead",1},
                    {"dsr_item_screwdriver_phillips",1},
                    {"dsr_item_bucket_empty",1},
                    {"dsr_item_plasticjug",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"ItemRadio",1},
                    {"ItemGPS",1},
                    {"dsr_item_battery_charged",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portablegenerator",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_satphone",1},
                    {"dsr_item_laptop",1}
                };
                semirare[] = {
                    {"ItemRadio",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_laptop",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"dsr_item_battery_dead",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_camera",1}
			};
                semicommon[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
                common[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
            };
            //Nothing Yet
            class CarPart {
                rare[] = {
                    {"dsr_item_log",1}
                };
                semirare[] = {
                    {"dsr_item_log",1}
                };
                average[] = {
                    {"dsr_item_log",1}
                };
                semicommon[] = {
                    {"dsr_item_log",1}
                };
                common[] = {
                    {"dsr_item_log",1}
                };
            };
            class Attachment {
                rare[] = {
                    {"optic_SOS",1},
                    {"optic_NVS",1},
                    {"optic_Nightstalker",1},
                    {"optic_tws",1},
                    {"optic_tws_mg",1},
                    {"optic_DMS",1},
                    {"optic_LRPS",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"bipod_01_F_mtp",1},
                    {"bipod_02_F_tan",1},
                    {"bipod_02_F_hex",1},
                    {"bipod_03_F_oli",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                semirare[] = {
                    {"optic_AMS",1},
                    {"optic_AMS_khk",1},
                    {"optic_AMS_snd",1},
                    {"optic_KHS_blk",1},
                    {"optic_KHS_hex",1},
                    {"optic_KHS_old",1},
                    {"optic_KHS_tan",1},
                    {"optic_MRCO",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                average[] = {
                    {"optic_Arco",1},
                    {"optic_Hamr",1},
                    {"optic_Holosight",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1}
                };
                semicommon[] = {
                    {"optic_Aco",1},
                    {"optic_ACO_grn",1},
                    {"optic_Aco_smg",1},
                    {"optic_ACO_grn_smg",1},
                    {"acc_flashlight",1}
                };
                common[] = {
                    {"optic_MRD",1},
                    {"optic_Yorris",1},
                    {"acc_flashlight",1}
                };
            };
        };
        class Commercial {
            class Weapon {
                rare[] = {
                    {"DSR_srifle_DMR_02",5},                //MAR-10
                    {"DSR_srifle_DMR_02_camo",5},           //MAR-10
                    {"DSR_srifle_DMR_02_sniper",5},         //MAR-10
                    {"DSR_srifle_DMR_03",6},                //Mk-I EMR
                    {"DSR_srifle_DMR_03_khaki",5},          //Mk-I EMR
                    {"DSR_srifle_DMR_03_tan",5},            //Mk-I EMR
                    {"DSR_srifle_DMR_03_multicam",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_03_woodland",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_04",4},                //ASP-1 Kir
                    {"DSR_srifle_DMR_04_Tan",5},            //ASP-1 Kir
                    {"DSR_srifle_DMR_05_blk",5},            //Cyrus
                    {"DSR_srifle_DMR_05_hex",5},            //Cyrus
                    {"DSR_srifle_DMR_05_tan",5},            //Cyrus
                    {"DSR_srifle_EBR",7},
                    {"DSR_srifle_GM6",1},
                    {"DSR_srifle_GM6_camo",1},
                    {"DSR_srifle_LRR",2},
                    {"DSR_srifle_LRR_camo",2},
                    {"DSR_LMG_Zafir",7},
                    {"DSR_MMG_01_hex",2},                   //Navid
                    {"DSR_MMG_01_tan",2},                   //Navid
                    {"DSR_MMG_02_camo",3},                  //SPMG
                    {"DSR_MMG_02_black",4},                 //SPMG
                    {"DSR_MMG_02_sand",4}                   //SPMG
                };
                semirare[] = {
                    {"DSR_arifle_MX_GL",17},
                    {"DSR_arifle_MX_GL_Black",16},
                    {"DSR_arifle_MX_SW",15},
                    {"DSR_arifle_MX_SW_Black",14},
                    {"DSR_arifle_MXM",13},
                    {"DSR_arifle_MXM_Black",12},
                    {"DSR_LMG_Mk200",6},
                    {"DSR_srifle_DMR_01",5},                 //Rahim
                    {"DSR_srifle_DMR_06_camo",1},            //Mk14
                    {"DSR_srifle_DMR_06_olive",1}            //Mk14
                };
                average[] = {
                    {"DSR_arifle_Katiba",20},
                    {"DSR_arifle_Katiba_C",18},
                    {"DSR_arifle_Katiba_GL",16},
                    {"DSR_arifle_MXC",13},
                    {"DSR_arifle_MXC_Black",12},
                    {"DSR_arifle_MX",11},
                    {"DSR_arifle_MX_Black",10}
                };
                semicommon[] = {
                    {"DSR_arifle_Katiba",37},
                    {"DSR_arifle_Katiba_C",32},
                    {"DSR_arifle_Katiba_GL",31}
                };
                common[] = {
                    {"DSR_SMG_01",45},
                    {"DSR_SMG_02",55}
                };
            };
            class Handgun {
                rare[] = {
                    {"DSR_hgun_PDW2000",1},
                    {"DSR_hgun_Pistol_heavy_01",35},    //4-five
                    {"DSR_hgun_Pistol_heavy_02",10},    //Zubr
                    {"DSR_hgun_P07",54}
                };
                semirare[] = {
                    {"DSR_hgun_Pistol_heavy_01",5},    //4-five
                    {"DSR_hgun_P07",40},
                    {"DSR_hgun_Rook",55}
                };
                average[] = {
                    {"DSR_hgun_ACPC2",55},
                    {"DSR_hgun_P07",10},
                    {"DSR_hgun_Rook",35}
                };
                semicommon[] = {
                    {"DSR_hgun_Rook",25},
                    {"DSR_hgun_ACPC2",75}
                };
                common[] = {
                    {"DSR_hgun_Pistol_Signal",45},
                    {"DSR_hgun_ACPC2",55}
                };
            };
            class Magazine {
                rare[] = {
                    {"100Rnd_580x42_Mag_F",13},
                    {"100Rnd_580x42_Mag_Tracer_F",12},
                    {"5Rnd_127x108_Mag",2},             //12.7 mm 5Rnd Mag
                    {"5Rnd_127x108_APDS_Mag",1},        //12.7mm 5Rnd APDS Mag
                    {"10Rnd_127x54_Mag",3},             //12.7mm 10Rnd Mag - ASPR
                    {"7Rnd_408_Mag",6},                 //.408 7Rnd LRR Mag
                    {"20Rnd_762x51_Mag",10},            //7.62 mm 20Rnd Mag
                    {"10Rnd_338_Mag",6},                //.338 LM 10Rnd Mag
                    {"10Rnd_93x64_DMR_05_Mag",3},       //9.3mm 10Rnd Mag
                    {"10Rnd_50BW_Mag_F",4},             //.50 BW 10Rnd Caseless Mag - Type 115
                    {"130Rnd_338_Mag",4},
                    {"150Rnd_762x54_Box",8},
                    {"150Rnd_762x54_Box_Tracer",7},
                    {"150Rnd_93x64_Mag",5},
                    {"1Rnd_HE_Grenade_shell",9},
                    {"3Rnd_HE_Grenade_shell",7}
                };
                semirare[] = {
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"30Rnd_65x39_caseless_mag",5},
                    {"30Rnd_65x39_caseless_green",4},
                    {"30Rnd_65x39_caseless_mag_Tracer",4},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",4},
                    {"10Rnd_762x54_Mag",3},                         //7.62 mm 10Rnd Mag - Rahim
                    {"30Rnd_762x39_Mag_F",2},
                    {"30Rnd_762x39_Mag_Green_F",1},
                    {"30Rnd_762x39_Mag_Tracer_F",1},
                    {"30Rnd_762x39_Mag_Tracer_Green_F",1},
                    {"30Rnd_580x42_Mag_F",3},
                    {"30Rnd_580x42_Mag_Tracer_F",2},
                    {"100Rnd_65x39_caseless_mag",3},
                    {"100Rnd_65x39_caseless_mag_Tracer",2},
                    {"200Rnd_65x39_cased_Box",3},
                    {"200Rnd_65x39_cased_Box_Tracer",2},
                    {"200Rnd_65x39_Belt_Tracer_Red",2},
                    {"200Rnd_65x39_Belt_Tracer_Green",2},
                    {"200Rnd_65x39_Belt_Tracer_Yellow",2},
                    {"150Rnd_762x54_Box",3},
                    {"150Rnd_762x54_Box_Tracer",2},
                    {"150Rnd_556x45_Drum_Mag_F",3},
                    {"150Rnd_556x45_Drum_Mag_Tracer_F",1},
                    {"200Rnd_556x45_Box_F",4},
                    {"200Rnd_556x45_Box_Red_F",3},
                    {"200Rnd_556x45_Box_Tracer_F",3},
                    {"200Rnd_556x45_Box_Tracer_Red_F",3}
                };
                average[] = {
                    {"30Rnd_545x39_Mag_F",12},
                    {"30Rnd_545x39_Mag_Green_F",11},
                    {"30Rnd_545x39_Mag_Tracer_F",11},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",10},
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"20Rnd_556x45_UW_mag",7},
                    {"30Rnd_65x39_caseless_mag",4},
                    {"30Rnd_65x39_caseless_green",3},
                    {"30Rnd_65x39_caseless_mag_Tracer",3},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",3},
                    {"20Rnd_650x39_Cased_Mag_F",5}
                };
                semicommon[] = {
                    {"30Rnd_545x39_Mag_F",3},
                    {"30Rnd_545x39_Mag_Green_F",2},
                    {"30Rnd_545x39_Mag_Tracer_F",2},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",2},
                    {"30Rnd_45ACP_Mag_SMG_01",10},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Green",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02",9},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Red",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Green",7},
                    {"30Rnd_9x21_Mag",9},
                    {"30Rnd_9x21_Red_Mag",7},
                    {"30Rnd_9x21_Yellow_Mag",7},
                    {"30Rnd_9x21_Green_Mag",7}
                };
                common[] = {
                    {"FlareWhite_F",9},
                    {"FlareGreen_F",9},
                    {"FlareRed_F",9},
                    {"FlareYellow_F",9},
                    {"6Rnd_GreenSignal_F",9},
                    {"6Rnd_RedSignal_F",9},
                    {"10Rnd_9x21_Mag",7},
                    {"16Rnd_9x21_Mag",4},
                    {"16Rnd_9x21_red_Mag",5},
                    {"16Rnd_9x21_green_Mag",5},
                    {"16Rnd_9x21_yellow_Mag",5},
                    {"11Rnd_45ACP_Mag",8},
                    {"9Rnd_45ACP_Mag",9},
                    {"6Rnd_45ACP_Cylinder",3}
                };
            };
			class Food {
                rare[] = {
                    {"dsr_item_beans",1}
                };
                semirare[] = {
                    {"dsr_item_cereal",1}
                };
                average[] = {
                    {"dsr_item_powderedmilk",1}
                };
                semicommon[] = {
                    {"dsr_item_rice",1}
                };
                common[] = {
                    {"dsr_item_bacon",1}
                };
            };
            class Drink {
                rare[] = {
                    {"dsr_item_waterbottle_full",1},
                    {"dsr_item_canteen_full",1}
                };
                semirare[] = {
                    {"dsr_item_rustyspirit",1},
                    {"dsr_item_spirit",1}
			};
                average[] = {
                    {"dsr_item_franta",1}
                };
                semicommon[] = {
                    {"dsr_item_waterbottle_empty",1},
                    {"dsr_item_canteen_empty",1}
                };
                common[] = {
                    {"dsr_item_waterbottle_dirty",1},
                    {"dsr_item_canteen_dirty",1}
                };
            };
            class Medical {
                rare[] = {
                    {"dsr_item_antibiotic",1},
                    {"dsr_item_bandage",1},
                    {"dsr_item_defibrillator",1},
                    {"dsr_item_bloodbag_full",1}
                };
                semirare[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_bloodbag_empty",1}
                };
                average[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_disinfectant",1},
                    {"dsr_item_painkillers",1},
                    {"dsr_item_waterpurificationtablets",1}
                };
                semicommon[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_handwarmer",1},
                    {"dsr_item_vitamins",1}
                };
                common[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_vitamins",1}
			};
            };
            class Junk {
                rare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                semirare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                average[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                semicommon[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                common[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"B_Carryall_oucamo",1},
                    {"B_Carryall_ocamo",1},
                    {"B_Carryall_khk",1},
                    {"B_Carryall_oli",1},
                    {"B_Carryall_cbr",1},
                    {"B_Carryall_mcamo",1},
                    //Special Need to Test (Some might spawn with gear in them)
                    {"I_Parachute_02_F",1},
                    {"B_Parachute_02_F",1},
                    {"B_AssaultPack_rgr_LAT",1},
                    {"B_AssaultPack_rgr_Medic",1},
                    {"B_AssaultPack_rgr_Repair",1},
                    {"B_AssaultPack_blk_DiverExp",1},
                    {"B_Kitbag_rgr_Exp",1},
                    {"B_FieldPack_blk_DiverExp",1},
                    {"B_FieldPack_ocamo_Medic",1},
                    {"B_FieldPack_cbr_LAT",1},
                    {"B_FieldPack_cbr_Repair",1},
                    {"B_Carryall_ocamo_Exp",1}
                };
                semirare[] = {
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_mcamo",1}
                };
                average[] = {
                    {"B_Bergen_blk",1},
                    {"B_Bergen_rgr",1},
                    {"B_Bergen_sgg",1},
                    {"B_Bergen_mcamo",1}
                };
                semicommon[] = {
                    {"B_HuntingBackpack",1},
                    {"B_OutdoorPack_blk",1},
                    {"B_OutdoorPack_blu",1},
                    {"B_OutdoorPack_tan",1},
                    {"B_FieldPack_blk",1},
                    {"B_FieldPack_oucamo",1},
                    {"B_FieldPack_ocamo",1},
                    {"B_FieldPack_cbr",1}
                };
                common[] = {
                    {"B_AssaultPack_blk",1},
                    {"B_AssaultPack_dgtl",1},
                    {"B_AssaultPack_khk",1},
                    {"B_AssaultPack_sgg",1},
                    {"B_AssaultPack_cbr",1},
                    {"B_AssaultPack_mcamo",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_B_CombatUniform_wdl",1},
                    {"U_B_CombatUniform_sgg",1},
                    {"U_B_CombatUniform_wdl_tshirt",1},
                    {"U_B_CombatUniform_sgg_tshirt",1},
                    {"U_O_SpecopsUniform_blk",1},
                    {"U_B_CombatUniform_wdl_vest",1},
                    {"U_B_CombatUniform_sgg_vest",1},
                    {"U_B_SpecopsUniform_sgg",1},
                    {"U_AttisBody",1},
                    {"U_AntigonaBody",1},
                    {"U_B_CombatUniform_mcam_worn",1},
                    {"U_B_CombatUniform_mcam_tshirt",1},
                    {"U_B_CombatUniform_mcam",1},
                    {"U_I_CombatUniform",1},
                    {"U_O_CombatUniform_ocamo",1},
                    {"U_O_CombatUniform_oucamo",1},
                    {"U_Competitor",1},
                    {"U_B_CTRG_1",1},
                    {"U_B_CTRG_3",1},
                    {"U_OG_leader",1},
                    {"U_BG_Guerilla1_1",1},
                    {"U_IG_Guerilla1_1",1},
                    {"U_OG_Guerilla1_1",1},
                    {"U_OG_Guerilla2_1",1},
                    {"U_IG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"U_IG_Guerilla2_2",1},
                    {"U_OG_Guerilla2_2",1},
                    {"U_BG_Guerilla2_3",1},
                    {"U_IG_Guerilla2_3",1},
                    {"U_OG_Guerilla2_3",1},
                    {"U_BG_Guerilla3_1",1},
                    {"U_IG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_2",1},
                    {"U_IG_Guerilla3_2",1},
                    {"U_BG_Guerilla3_2",1},
                    {"U_IG_Guerrilla_6_1",1},
                    {"U_BG_Guerrilla_6_1",1},
                    {"U_OG_Guerrilla_6_1",1},
                    {"U_BG_leader",1},
                    {"U_B_FullGhillie_ard",1},
                    {"U_B_FullGhillie_lsh",1},
                    {"U_B_FullGhillie_sard",1},
                    {"U_B_GhillieSuit",1},
                    {"U_B_CombatUniform_mcam_vest",1},
                    {"U_B_Wetsuit",1},
                    {"U_I_Wetsuit",1},
                    {"U_O_Wetsuit",1},
                    {"U_I_G_resistanceLeader_F",1},
                    {"U_IG_leader",1},
                    {"U_I_OfficerUniform",1},
                    {"U_I_CombatUniform_shortsleeve",1},
                    {"U_I_HeliPilotCoveralls",1},
                    {"U_I_pilotCoveralls",1},
                    {"U_I_CombatUniform_tshirt",1},
                    {"U_O_SpecopsUniform_ocamo",1},
                    {"U_O_OfficerUniform_ocamo",1},
                    {"U_O_PilotCoveralls",1}
                };
                semirare[] = {
                    {"U_B_survival_uniform",1},
                    {"U_B_CTRG_2",1},
                    {"U_Marshal",1},
                    {"U_NikosBody",1},
                    {"U_NikosAgedBody",1},
                    {"U_OrestesBody",1},
                    {"U_C_Scientist",1},
                    {"U_C_PriestBody",1},
                    {"U_KerryBody",1},
                    {"U_MillerBody",1},
                    {"U_Rangemaster",1},
                    {"U_B_HeliPilotCoveralls",1},
                    {"U_B_PilotCoveralls",1},
                    {"U_OI_Scientist",1}
                };
                average[] = {
                    {"U_C_Fisherman",1},
                    {"U_C_FishermanOveralls",1},
                    {"U_C_HunterBody_brn",1},
                    {"U_IG_Menelaos",1},
                    {"U_C_Novak",1}
                };
                semicommon[] = {
                    {"U_C_Commoner1_2",1},     
                    {"U_C_Commoner1_3",1},
                    {"U_C_Commoner2_1",1},
                    {"U_C_Commoner2_2",1},
                    {"U_C_Commoner2_3",1}
                };
                common[] = {
                    {"U_C_Poor_2",1},
                    {"U_C_Poor_1",1},
                    {"U_C_Poor_shorts_1",1},
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_burgundy",1},
                    {"U_C_Poloshirt_tricolour",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_redwhite",1},
                    {"U_C_WorkerOveralls",1},
                    {"U_C_Farmer",1},
                    {"U_C_Scavenger_2",1},
                    {"U_C_Scavenger_1",1},
                    {"U_C_Poor_shorts_2",1},
                    {"U_C_Journalist",1},
                    {"U_C_Poloshirt_stripped",1},
                    {"U_C_Commoner1_1",1},
                    {"U_C_Commoner_shorts",1},
                    {"U_C_ShirtSurfer_shorts",1},
                    {"U_C_TeeSurfer_shorts_1",1},
                    {"U_C_TeeSurfer_shorts_2",1},
                    {"U_C_WorkerCoveralls",1},
                    {"U_C_HunterBody_grn",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Chestrig_blk",1},
                    {"V_Chestrig_khk",1},
                    {"V_Chestrig_oli",1},
                    {"V_Chestrig_rgr",1},
                    {"V_PlateCarrier1_blk",1},
                    {"V_PlateCarrier1_rgr",1},
                    {"V_PlateCarrier2_rgr",1},
                    {"V_PlateCarrier3_rgr",1},
                    {"V_PlateCarrierGL_rgr",1},
                    {"V_PlateCarrierIA1_dgtl",1},
                    {"V_PlateCarrierIA2_dgtl",1},
                    {"V_PlateCarrierIAGL_dgtl",1},
                    {"V_PlateCarrierSpec_rgr",1},
                    {"V_I_G_resistanceLeader_F",1},
                    {"V_PlateCarrierSpec_blk",1},
                    {"V_PlateCarrierSpec_mtp",1},
                    {"V_PlateCarrierGL_mtp",1},
                    {"V_PlateCarrierGL_blk",1},
                    {"V_PlateCarrierIAGL_oli",1},
                    {"V_PlateCarrier_Kerry",1},
                    {"V_PlateCarrierL_CTRG",1},
                    {"V_PlateCarrierH_CTRG",1},
                    {"V_RebreatherB",1},
                    {"V_RebreatherIA",1},
                    {"V_RebreatherIR",1}
                };
                semirare[] = {
                    {"V_TacVest_blk",1},
                    {"V_TacVest_blk_POLICE",1},
                    {"V_TacVest_brn",1},
                    {"V_TacVest_camo",1},
                    {"V_TacVest_khk",1},
                    {"V_TacVest_oli",1},
                    {"V_TacVestCamo_khk",1},
                    {"V_TacVestIR_blk",1}
                };
                average[] = {
                    {"V_HarnessO_brn",1},
                    {"V_HarnessO_gry",1},
                    {"V_HarnessOGL_brn",1},
                    {"V_HarnessOGL_gry",1},
                    {"V_HarnessOSpec_brn",1},
                    {"V_HarnessOSpec_gry",1}
                };
                semicommon[] = {
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_blk",1},
                    {"V_BandollierB_cbr",1},
                    {"V_BandollierB_khk",1},
                    {"V_BandollierB_oli",1},
                    {"V_BandollierB_rgr",1}
                };
                common[] = {
                    {"V_Press_F",1},
                    {"V_Rangemaster_belt",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_HelmetB_camo",1},
                    {"H_HelmetB_grass",1},
                    {"H_HelmetB_black",1},
                    {"H_HelmetB_light",1},
                    {"H_HelmetB_sand",1},
                    {"H_HelmetB_desert",1},
                    {"H_HelmetB_light_black",1},
                    {"H_HelmetB_light_grass",1},
                    {"H_HelmetB_light_snakeskin",1},
                    {"H_HelmetB_light_desert",1},
                    {"H_HelmetB_light_sand",1},
                    {"H_HelmetB_snakeskin",1},
                    {"H_HelmetB_paint",1},
                    {"H_HelmetSpecB",1},
                    {"H_HelmetSpecB_paint1",1},
                    {"H_HelmetSpecB_blk",1},
                    {"H_HelmetSpecB_paint2",1},
                    {"H_HelmetSpecO_ocamo",1},
                    {"H_HelmetSpecO_blk",1},
                    {"H_HelmetB_plain_blk",1},
                    {"H_HelmetB_plain_mcamo",1},
                    {"H_HelmetB",1},
                    {"H_HelmetIA",1},
                    {"H_HelmetIA_net",1},
                    {"H_HelmetIA_camo",1},
                    {"H_HelmetO_ocamo",1},
                    {"H_HelmetO_oucamo",1},
                    {"H_HelmetLeaderO_ocamo",1},
                    {"H_HelmetLeaderO_oucamo",1}
                };
                semirare[] = {
                    {"H_Shemag_olive_hs",1},
                    {"H_ShemagOpen_tan",1},
                    {"H_ShemagOpen_khk",1},
                    {"H_Shemag_khk",1},
                    {"H_Shemag_tan",1},
                    {"H_Shemag_olive",1},
                    {"H_Helmet_Kerry",1},
                    {"H_HelmetCrew_B",1},
                    {"H_HelmetCrew_I",1},
                    {"H_HelmetCrew_O",1},
                    {"H_CrewHelmetHeli_I",1},
                    {"H_CrewHelmetHeli_B",1},
                    {"H_CrewHelmetHeli_O",1},
                    {"H_PilotHelmetHeli_B",1},
                    {"H_PilotHelmetHeli_I",1},
                    {"H_PilotHelmetHeli_O",1},
                    {"H_PilotHelmetFighter_B",1},
                    {"H_PilotHelmetFighter_I",1},
                    {"H_PilotHelmetFighter_O",1}
                };
                average[] = {
                    {"H_RacingHelmet_1_black_F",1},
                    {"H_RacingHelmet_1_blue_F",1},
                    {"H_RacingHelmet_1_green_F",1},
                    {"H_RacingHelmet_1_orange_F",1},
                    {"H_RacingHelmet_1_red_F",1},
                    {"H_RacingHelmet_1_white_F",1},
                    {"H_RacingHelmet_1_yellow_F",1},
                    {"H_Beret_grn",1},
                    {"H_Beret_blk",1},
                    {"H_Beret_blk_POLICE",1},
                    {"H_Beret_red",1},
                    {"H_Beret_brn_SF",1},
                    {"H_Beret_grn_SF",1},
                    {"H_Beret_02",1},
                    {"H_Beret_Colonel",1},
                    {"H_Beret_ocamo",1},
                    {"H_TurbanO_blk",1},
                    {"H_MilCap_blue",1},
                    {"H_MilCap_gry",1},
                    {"H_MilCap_ocamo",1},
                    {"H_MilCap_rucamo",1},
                    {"H_MilCap_oucamo",1},
                    {"H_MilCap_mcamo",1},
                    {"H_MilCap_dgtl",1}
                };
                semicommon[] = {
                    {"H_Booniehat_dirty",1},
                    {"H_Booniehat_khk_hs",1},
                    {"H_Booniehat_grn",1},
                    {"H_Booniehat_indp",1},
                    {"H_Booniehat_khk",1},
                    {"H_Booniehat_oli",1},
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_dgtl",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Cap_grn_BI",1},
                    {"H_Cap_blk",1},
                    {"H_Cap_blu",1},
                    {"H_Cap_oli",1},
                    {"H_Cap_grn",1},
                    {"H_Cap_red",1},
                    {"H_Cap_surfer",1},
                    {"H_Cap_tan",1},
                    {"H_Cap_blk_CMMG",1},
                    {"H_Cap_blk_ION",1},
                    {"H_Cap_oli_hs",1},
                    {"H_Cap_police",1},
                    {"H_Cap_usblack",1},
                    {"H_Cap_tan_specops_US",1},
                    {"H_Cap_blk_Raven",1},
                    {"H_Cap_brn_SPECOPS",1},
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_headphones",1},
                    {"H_Cap_press",1},
                    {"H_Cap_marshal",1},
                    {"H_Watchcap_camo",1},
                    {"H_Watchcap_blk",1},
                    {"H_Hat_blue",1},
                    {"H_Hat_brown",1},
                    {"H_Hat_camo",1},
                    {"H_Hat_checker",1},
                    {"H_Hat_grey",1},
                    {"H_Hat_tan",1}
                };
                common[] = {
                    {"H_Bandanna_gry",1},
                    {"H_Bandanna_blu",1},
                    {"H_Bandanna_cbr",1},
                    {"H_Bandanna_mcamo",1},
                    {"H_Bandanna_sgg",1},
                    {"H_Bandanna_sand",1},
                    {"H_Bandanna_surfer",1},
                    {"H_Bandanna_surfer_blk",1},
                    {"H_Bandanna_surfer_grn",1},
                    {"H_Bandanna_camo",1},
                    {"H_Bandanna_khk",1},
                    {"H_Bandanna_khk_hs",1},
                    {"H_BandMask_blk",1},
                    {"H_BandMask_demon",1},
                    {"H_BandMask_khk",1},
                    {"H_BandMask_reaper",1},
                    {"H_Watchcap_cbr",1},
                    {"H_Watchcap_khk",1},
                    {"H_Watchcap_sgg",1},
                    {"H_StrawHat",1},
                    {"H_StrawHat_dark",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"ItemGPS",1},
                    {"NVGoggles",1},
                    {"Binocular",1},
                    {"Rangefinder",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1},
                    {"ItemRadio",1}
                };
                semirare[] = {
                    {"Binocular",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                semicommon[] = {
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                common[] = {
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_hgun_P07",1}
                };
                semirare[] = {
                    {"DSR_hgun_P07",1}
                };
                average[] = {
                    {"DSR_hgun_P07",1}
                };
                semicommon[] = {
                    {"DSR_hgun_P07",1}
                };
                common[] = {
                    {"DSR_hgun_P07",1}
                };
            };
            class Construction {
                rare[] = {
                    {"dsr_item_butane_full",1},
                    {"dsr_item_propane_full",1},
                    {"dsr_item_metalwire",1},
                    {"dsr_item_multimeter",1}
                };
                semirare[] = {
                    {"dsr_item_butanetorch",1},
                    {"dsr_item_butane_empty",1},
                    {"dsr_item_propanecooker",1},
                    {"dsr_item_drill",1},
                    {"dsr_item_grinder",1},
                    {"dsr_item_tapemeasure",1},
                    {"dsr_item_fuelcan_full",1},
                    {"dsr_item_oilcan_full",1}
                };
                average[] = {
                    {"dsr_item_propane_empty",1},
                    {"dsr_item_pliers",1},
                    {"dsr_item_ducttape",1},
                    {"dsr_item_saw",1}
                };
                semicommon[] = {
                    {"dsr_item_canopener",1},
                    {"dsr_item_matches",1},
                    {"dsr_item_hammer",1},
                    {"dsr_item_fuelcan_empty",1},
                    {"dsr_item_oilcan_empty",1}
                };
                common[] = {
                    {"dsr_item_tincontainer",1},
                    {"dsr_item_nailfile",1},
                    {"dsr_item_screwdriver_flathead",1},
                    {"dsr_item_screwdriver_phillips",1},
                    {"dsr_item_bucket_empty",1},
                    {"dsr_item_plasticjug",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"ItemRadio",1},
                    {"ItemGPS",1},
                    {"dsr_item_battery_charged",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portablegenerator",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_satphone",1},
                    {"dsr_item_laptop",1}
                };
                semirare[] = {
                    {"ItemRadio",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_laptop",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"dsr_item_battery_dead",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_camera",1}
			};
                semicommon[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
                common[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
            };
            //Nothing Yet
            class CarPart {
                rare[] = {
                    {"dsr_item_log",1}
                };
                semirare[] = {
                    {"dsr_item_log",1}
                };
                average[] = {
                    {"dsr_item_log",1}
                };
                semicommon[] = {
                    {"dsr_item_log",1}
                };
                common[] = {
                    {"dsr_item_log",1}
                };
            };
            class Attachment {
                rare[] = {
                    {"optic_SOS",1},
                    {"optic_NVS",1},
                    {"optic_Nightstalker",1},
                    {"optic_tws",1},
                    {"optic_tws_mg",1},
                    {"optic_DMS",1},
                    {"optic_LRPS",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"bipod_01_F_mtp",1},
                    {"bipod_02_F_tan",1},
                    {"bipod_02_F_hex",1},
                    {"bipod_03_F_oli",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                semirare[] = {
                    {"optic_AMS",1},
                    {"optic_AMS_khk",1},
                    {"optic_AMS_snd",1},
                    {"optic_KHS_blk",1},
                    {"optic_KHS_hex",1},
                    {"optic_KHS_old",1},
                    {"optic_KHS_tan",1},
                    {"optic_MRCO",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                average[] = {
                    {"optic_Arco",1},
                    {"optic_Hamr",1},
                    {"optic_Holosight",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1}
                };
                semicommon[] = {
                    {"optic_Aco",1},
                    {"optic_ACO_grn",1},
                    {"optic_Aco_smg",1},
                    {"optic_ACO_grn_smg",1},
                    {"acc_flashlight",1}
                };
                common[] = {
                    {"optic_MRD",1},
                    {"optic_Yorris",1},
                    {"acc_flashlight",1}
                };
            };
        };
        class Medical {
            class Weapon {
                rare[] = {
                    {"DSR_srifle_DMR_02",5},                //MAR-10
                    {"DSR_srifle_DMR_02_camo",5},           //MAR-10
                    {"DSR_srifle_DMR_02_sniper",5},         //MAR-10
                    {"DSR_srifle_DMR_03",6},                //Mk-I EMR
                    {"DSR_srifle_DMR_03_khaki",5},          //Mk-I EMR
                    {"DSR_srifle_DMR_03_tan",5},            //Mk-I EMR
                    {"DSR_srifle_DMR_03_multicam",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_03_woodland",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_04",4},                //ASP-1 Kir
                    {"DSR_srifle_DMR_04_Tan",5},            //ASP-1 Kir
                    {"DSR_srifle_DMR_05_blk",5},            //Cyrus
                    {"DSR_srifle_DMR_05_hex",5},            //Cyrus
                    {"DSR_srifle_DMR_05_tan",5},            //Cyrus
                    {"DSR_srifle_EBR",7},
                    {"DSR_srifle_GM6",1},
                    {"DSR_srifle_GM6_camo",1},
                    {"DSR_srifle_LRR",2},
                    {"DSR_srifle_LRR_camo",2},
                    {"DSR_LMG_Zafir",7},
                    {"DSR_MMG_01_hex",2},                   //Navid
                    {"DSR_MMG_01_tan",2},                   //Navid
                    {"DSR_MMG_02_camo",3},                  //SPMG
                    {"DSR_MMG_02_black",4},                 //SPMG
                    {"DSR_MMG_02_sand",4}                   //SPMG
                };
                semirare[] = {
                    {"DSR_arifle_MX_GL",17},
                    {"DSR_arifle_MX_GL_Black",16},
                    {"DSR_arifle_MX_SW",15},
                    {"DSR_arifle_MX_SW_Black",14},
                    {"DSR_arifle_MXM",13},
                    {"DSR_arifle_MXM_Black",12},
                    {"DSR_LMG_Mk200",6},
                    {"DSR_srifle_DMR_01",5},                 //Rahim
                    {"DSR_srifle_DMR_06_camo",1},            //Mk14
                    {"DSR_srifle_DMR_06_olive",1}            //Mk14
                };
                average[] = {
                    {"DSR_arifle_Katiba",20},
                    {"DSR_arifle_Katiba_C",18},
                    {"DSR_arifle_Katiba_GL",16},
                    {"DSR_arifle_MXC",13},
                    {"DSR_arifle_MXC_Black",12},
                    {"DSR_arifle_MX",11},
                    {"DSR_arifle_MX_Black",10}
                };
                semicommon[] = {
                    {"DSR_arifle_Katiba",37},
                    {"DSR_arifle_Katiba_C",32},
                    {"DSR_arifle_Katiba_GL",31}
                };
                common[] = {
                    {"DSR_SMG_01",45},
                    {"DSR_SMG_02",55}
                };
            };
            class Handgun {
                rare[] = {
                    {"DSR_hgun_PDW2000",1},
                    {"DSR_hgun_Pistol_heavy_01",35},    //4-five
                    {"DSR_hgun_Pistol_heavy_02",10},    //Zubr
                    {"DSR_hgun_P07",54}
                };
                semirare[] = {
                    {"DSR_hgun_Pistol_heavy_01",5},    //4-five
                    {"DSR_hgun_P07",40},
                    {"DSR_hgun_Rook",55}
                };
                average[] = {
                    {"DSR_hgun_ACPC2",55},
                    {"DSR_hgun_P07",10},
                    {"DSR_hgun_Rook",35}
                };
                semicommon[] = {
                    {"DSR_hgun_Rook",25},
                    {"DSR_hgun_ACPC2",75}
                };
                common[] = {
                    {"DSR_hgun_Pistol_Signal",45},
                    {"DSR_hgun_ACPC2",55}
                };
            };
            class Magazine {
                rare[] = {
                    {"100Rnd_580x42_Mag_F",13},
                    {"100Rnd_580x42_Mag_Tracer_F",12},
                    {"5Rnd_127x108_Mag",2},             //12.7 mm 5Rnd Mag
                    {"5Rnd_127x108_APDS_Mag",1},        //12.7mm 5Rnd APDS Mag
                    {"10Rnd_127x54_Mag",3},             //12.7mm 10Rnd Mag - ASPR
                    {"7Rnd_408_Mag",6},                 //.408 7Rnd LRR Mag
                    {"20Rnd_762x51_Mag",10},            //7.62 mm 20Rnd Mag
                    {"10Rnd_338_Mag",6},                //.338 LM 10Rnd Mag
                    {"10Rnd_93x64_DMR_05_Mag",3},       //9.3mm 10Rnd Mag
                    {"10Rnd_50BW_Mag_F",4},             //.50 BW 10Rnd Caseless Mag - Type 115
                    {"130Rnd_338_Mag",4},
                    {"150Rnd_762x54_Box",8},
                    {"150Rnd_762x54_Box_Tracer",7},
                    {"150Rnd_93x64_Mag",5},
                    {"1Rnd_HE_Grenade_shell",9},
                    {"3Rnd_HE_Grenade_shell",7}
                };
                semirare[] = {
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"30Rnd_65x39_caseless_mag",5},
                    {"30Rnd_65x39_caseless_green",4},
                    {"30Rnd_65x39_caseless_mag_Tracer",4},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",4},
                    {"10Rnd_762x54_Mag",3},                         //7.62 mm 10Rnd Mag - Rahim
                    {"30Rnd_762x39_Mag_F",2},
                    {"30Rnd_762x39_Mag_Green_F",1},
                    {"30Rnd_762x39_Mag_Tracer_F",1},
                    {"30Rnd_762x39_Mag_Tracer_Green_F",1},
                    {"30Rnd_580x42_Mag_F",3},
                    {"30Rnd_580x42_Mag_Tracer_F",2},
                    {"100Rnd_65x39_caseless_mag",3},
                    {"100Rnd_65x39_caseless_mag_Tracer",2},
                    {"200Rnd_65x39_cased_Box",3},
                    {"200Rnd_65x39_cased_Box_Tracer",2},
                    {"200Rnd_65x39_Belt_Tracer_Red",2},
                    {"200Rnd_65x39_Belt_Tracer_Green",2},
                    {"200Rnd_65x39_Belt_Tracer_Yellow",2},
                    {"150Rnd_762x54_Box",3},
                    {"150Rnd_762x54_Box_Tracer",2},
                    {"150Rnd_556x45_Drum_Mag_F",3},
                    {"150Rnd_556x45_Drum_Mag_Tracer_F",1},
                    {"200Rnd_556x45_Box_F",4},
                    {"200Rnd_556x45_Box_Red_F",3},
                    {"200Rnd_556x45_Box_Tracer_F",3},
                    {"200Rnd_556x45_Box_Tracer_Red_F",3}
                };
                average[] = {
                    {"30Rnd_545x39_Mag_F",12},
                    {"30Rnd_545x39_Mag_Green_F",11},
                    {"30Rnd_545x39_Mag_Tracer_F",11},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",10},
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"20Rnd_556x45_UW_mag",7},
                    {"30Rnd_65x39_caseless_mag",4},
                    {"30Rnd_65x39_caseless_green",3},
                    {"30Rnd_65x39_caseless_mag_Tracer",3},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",3},
                    {"20Rnd_650x39_Cased_Mag_F",5}
                };
                semicommon[] = {
                    {"30Rnd_545x39_Mag_F",3},
                    {"30Rnd_545x39_Mag_Green_F",2},
                    {"30Rnd_545x39_Mag_Tracer_F",2},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",2},
                    {"30Rnd_45ACP_Mag_SMG_01",10},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Green",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02",9},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Red",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Green",7},
                    {"30Rnd_9x21_Mag",9},
                    {"30Rnd_9x21_Red_Mag",7},
                    {"30Rnd_9x21_Yellow_Mag",7},
                    {"30Rnd_9x21_Green_Mag",7}
                };
                common[] = {
                    {"FlareWhite_F",9},
                    {"FlareGreen_F",9},
                    {"FlareRed_F",9},
                    {"FlareYellow_F",9},
                    {"6Rnd_GreenSignal_F",9},
                    {"6Rnd_RedSignal_F",9},
                    {"10Rnd_9x21_Mag",7},
                    {"16Rnd_9x21_Mag",4},
                    {"16Rnd_9x21_red_Mag",5},
                    {"16Rnd_9x21_green_Mag",5},
                    {"16Rnd_9x21_yellow_Mag",5},
                    {"11Rnd_45ACP_Mag",8},
                    {"9Rnd_45ACP_Mag",9},
                    {"6Rnd_45ACP_Cylinder",3}
                };
            };
			class Food {
                rare[] = {
                    {"dsr_item_beans",1}
                };
                semirare[] = {
                    {"dsr_item_cereal",1}
                };
                average[] = {
                    {"dsr_item_powderedmilk",1}
                };
                semicommon[] = {
                    {"dsr_item_rice",1}
                };
                common[] = {
                    {"dsr_item_bacon",1}
                };
            };
            class Drink {
                rare[] = {
                    {"dsr_item_waterbottle_full",1},
                    {"dsr_item_canteen_full",1}
                };
                semirare[] = {
                    {"dsr_item_rustyspirit",1},
                    {"dsr_item_spirit",1}
			};
                average[] = {
                    {"dsr_item_franta",1}
                };
                semicommon[] = {
                    {"dsr_item_waterbottle_empty",1},
                    {"dsr_item_canteen_empty",1}
                };
                common[] = {
                    {"dsr_item_waterbottle_dirty",1},
                    {"dsr_item_canteen_dirty",1}
                };
            };
            class Medical {
                rare[] = {
                    {"dsr_item_antibiotic",1},
                    {"dsr_item_bandage",1},
                    {"dsr_item_defibrillator",1},
                    {"dsr_item_bloodbag_full",1}
                };
                semirare[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_bloodbag_empty",1}
                };
                average[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_disinfectant",1},
                    {"dsr_item_painkillers",1},
                    {"dsr_item_waterpurificationtablets",1}
                };
                semicommon[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_handwarmer",1},
                    {"dsr_item_vitamins",1}
                };
                common[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_vitamins",1}
			};
            };
            class Junk {
                rare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                semirare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                average[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                semicommon[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                common[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"B_Carryall_oucamo",1},
                    {"B_Carryall_ocamo",1},
                    {"B_Carryall_khk",1},
                    {"B_Carryall_oli",1},
                    {"B_Carryall_cbr",1},
                    {"B_Carryall_mcamo",1},
                    //Special Need to Test (Some might spawn with gear in them)
                    {"I_Parachute_02_F",1},
                    {"B_Parachute_02_F",1},
                    {"B_AssaultPack_rgr_LAT",1},
                    {"B_AssaultPack_rgr_Medic",1},
                    {"B_AssaultPack_rgr_Repair",1},
                    {"B_AssaultPack_blk_DiverExp",1},
                    {"B_Kitbag_rgr_Exp",1},
                    {"B_FieldPack_blk_DiverExp",1},
                    {"B_FieldPack_ocamo_Medic",1},
                    {"B_FieldPack_cbr_LAT",1},
                    {"B_FieldPack_cbr_Repair",1},
                    {"B_Carryall_ocamo_Exp",1}
                };
                semirare[] = {
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_mcamo",1}
                };
                average[] = {
                    {"B_Bergen_blk",1},
                    {"B_Bergen_rgr",1},
                    {"B_Bergen_sgg",1},
                    {"B_Bergen_mcamo",1}
                };
                semicommon[] = {
                    {"B_HuntingBackpack",1},
                    {"B_OutdoorPack_blk",1},
                    {"B_OutdoorPack_blu",1},
                    {"B_OutdoorPack_tan",1},
                    {"B_FieldPack_blk",1},
                    {"B_FieldPack_oucamo",1},
                    {"B_FieldPack_ocamo",1},
                    {"B_FieldPack_cbr",1}
                };
                common[] = {
                    {"B_AssaultPack_blk",1},
                    {"B_AssaultPack_dgtl",1},
                    {"B_AssaultPack_khk",1},
                    {"B_AssaultPack_sgg",1},
                    {"B_AssaultPack_cbr",1},
                    {"B_AssaultPack_mcamo",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_B_CombatUniform_wdl",1},
                    {"U_B_CombatUniform_sgg",1},
                    {"U_B_CombatUniform_wdl_tshirt",1},
                    {"U_B_CombatUniform_sgg_tshirt",1},
                    {"U_O_SpecopsUniform_blk",1},
                    {"U_B_CombatUniform_wdl_vest",1},
                    {"U_B_CombatUniform_sgg_vest",1},
                    {"U_B_SpecopsUniform_sgg",1},
                    {"U_AttisBody",1},
                    {"U_AntigonaBody",1},
                    {"U_B_CombatUniform_mcam_worn",1},
                    {"U_B_CombatUniform_mcam_tshirt",1},
                    {"U_B_CombatUniform_mcam",1},
                    {"U_I_CombatUniform",1},
                    {"U_O_CombatUniform_ocamo",1},
                    {"U_O_CombatUniform_oucamo",1},
                    {"U_Competitor",1},
                    {"U_B_CTRG_1",1},
                    {"U_B_CTRG_3",1},
                    {"U_OG_leader",1},
                    {"U_BG_Guerilla1_1",1},
                    {"U_IG_Guerilla1_1",1},
                    {"U_OG_Guerilla1_1",1},
                    {"U_OG_Guerilla2_1",1},
                    {"U_IG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"U_IG_Guerilla2_2",1},
                    {"U_OG_Guerilla2_2",1},
                    {"U_BG_Guerilla2_3",1},
                    {"U_IG_Guerilla2_3",1},
                    {"U_OG_Guerilla2_3",1},
                    {"U_BG_Guerilla3_1",1},
                    {"U_IG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_2",1},
                    {"U_IG_Guerilla3_2",1},
                    {"U_BG_Guerilla3_2",1},
                    {"U_IG_Guerrilla_6_1",1},
                    {"U_BG_Guerrilla_6_1",1},
                    {"U_OG_Guerrilla_6_1",1},
                    {"U_BG_leader",1},
                    {"U_B_FullGhillie_ard",1},
                    {"U_B_FullGhillie_lsh",1},
                    {"U_B_FullGhillie_sard",1},
                    {"U_B_GhillieSuit",1},
                    {"U_B_CombatUniform_mcam_vest",1},
                    {"U_B_Wetsuit",1},
                    {"U_I_Wetsuit",1},
                    {"U_O_Wetsuit",1},
                    {"U_I_G_resistanceLeader_F",1},
                    {"U_IG_leader",1},
                    {"U_I_OfficerUniform",1},
                    {"U_I_CombatUniform_shortsleeve",1},
                    {"U_I_HeliPilotCoveralls",1},
                    {"U_I_pilotCoveralls",1},
                    {"U_I_CombatUniform_tshirt",1},
                    {"U_O_SpecopsUniform_ocamo",1},
                    {"U_O_OfficerUniform_ocamo",1},
                    {"U_O_PilotCoveralls",1}
                };
                semirare[] = {
                    {"U_B_survival_uniform",1},
                    {"U_B_CTRG_2",1},
                    {"U_Marshal",1},
                    {"U_NikosBody",1},
                    {"U_NikosAgedBody",1},
                    {"U_OrestesBody",1},
                    {"U_C_Scientist",1},
                    {"U_C_PriestBody",1},
                    {"U_KerryBody",1},
                    {"U_MillerBody",1},
                    {"U_Rangemaster",1},
                    {"U_B_HeliPilotCoveralls",1},
                    {"U_B_PilotCoveralls",1},
                    {"U_OI_Scientist",1}
                };
                average[] = {
                    {"U_C_Fisherman",1},
                    {"U_C_FishermanOveralls",1},
                    {"U_C_HunterBody_brn",1},
                    {"U_IG_Menelaos",1},
                    {"U_C_Novak",1}
                };
                semicommon[] = {
                    {"U_C_Commoner1_2",1},     
                    {"U_C_Commoner1_3",1},
                    {"U_C_Commoner2_1",1},
                    {"U_C_Commoner2_2",1},
                    {"U_C_Commoner2_3",1}
                };
                common[] = {
                    {"U_C_Poor_2",1},
                    {"U_C_Poor_1",1},
                    {"U_C_Poor_shorts_1",1},
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_burgundy",1},
                    {"U_C_Poloshirt_tricolour",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_redwhite",1},
                    {"U_C_WorkerOveralls",1},
                    {"U_C_Farmer",1},
                    {"U_C_Scavenger_2",1},
                    {"U_C_Scavenger_1",1},
                    {"U_C_Poor_shorts_2",1},
                    {"U_C_Journalist",1},
                    {"U_C_Poloshirt_stripped",1},
                    {"U_C_Commoner1_1",1},
                    {"U_C_Commoner_shorts",1},
                    {"U_C_ShirtSurfer_shorts",1},
                    {"U_C_TeeSurfer_shorts_1",1},
                    {"U_C_TeeSurfer_shorts_2",1},
                    {"U_C_WorkerCoveralls",1},
                    {"U_C_HunterBody_grn",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Chestrig_blk",1},
                    {"V_Chestrig_khk",1},
                    {"V_Chestrig_oli",1},
                    {"V_Chestrig_rgr",1},
                    {"V_PlateCarrier1_blk",1},
                    {"V_PlateCarrier1_rgr",1},
                    {"V_PlateCarrier2_rgr",1},
                    {"V_PlateCarrier3_rgr",1},
                    {"V_PlateCarrierGL_rgr",1},
                    {"V_PlateCarrierIA1_dgtl",1},
                    {"V_PlateCarrierIA2_dgtl",1},
                    {"V_PlateCarrierIAGL_dgtl",1},
                    {"V_PlateCarrierSpec_rgr",1},
                    {"V_I_G_resistanceLeader_F",1},
                    {"V_PlateCarrierSpec_blk",1},
                    {"V_PlateCarrierSpec_mtp",1},
                    {"V_PlateCarrierGL_mtp",1},
                    {"V_PlateCarrierGL_blk",1},
                    {"V_PlateCarrierIAGL_oli",1},
                    {"V_PlateCarrier_Kerry",1},
                    {"V_PlateCarrierL_CTRG",1},
                    {"V_PlateCarrierH_CTRG",1},
                    {"V_RebreatherB",1},
                    {"V_RebreatherIA",1},
                    {"V_RebreatherIR",1}
                };
                semirare[] = {
                    {"V_TacVest_blk",1},
                    {"V_TacVest_blk_POLICE",1},
                    {"V_TacVest_brn",1},
                    {"V_TacVest_camo",1},
                    {"V_TacVest_khk",1},
                    {"V_TacVest_oli",1},
                    {"V_TacVestCamo_khk",1},
                    {"V_TacVestIR_blk",1}
                };
                average[] = {
                    {"V_HarnessO_brn",1},
                    {"V_HarnessO_gry",1},
                    {"V_HarnessOGL_brn",1},
                    {"V_HarnessOGL_gry",1},
                    {"V_HarnessOSpec_brn",1},
                    {"V_HarnessOSpec_gry",1}
                };
                semicommon[] = {
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_blk",1},
                    {"V_BandollierB_cbr",1},
                    {"V_BandollierB_khk",1},
                    {"V_BandollierB_oli",1},
                    {"V_BandollierB_rgr",1}
                };
                common[] = {
                    {"V_Press_F",1},
                    {"V_Rangemaster_belt",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_HelmetB_camo",1},
                    {"H_HelmetB_grass",1},
                    {"H_HelmetB_black",1},
                    {"H_HelmetB_light",1},
                    {"H_HelmetB_sand",1},
                    {"H_HelmetB_desert",1},
                    {"H_HelmetB_light_black",1},
                    {"H_HelmetB_light_grass",1},
                    {"H_HelmetB_light_snakeskin",1},
                    {"H_HelmetB_light_desert",1},
                    {"H_HelmetB_light_sand",1},
                    {"H_HelmetB_snakeskin",1},
                    {"H_HelmetB_paint",1},
                    {"H_HelmetSpecB",1},
                    {"H_HelmetSpecB_paint1",1},
                    {"H_HelmetSpecB_blk",1},
                    {"H_HelmetSpecB_paint2",1},
                    {"H_HelmetSpecO_ocamo",1},
                    {"H_HelmetSpecO_blk",1},
                    {"H_HelmetB_plain_blk",1},
                    {"H_HelmetB_plain_mcamo",1},
                    {"H_HelmetB",1},
                    {"H_HelmetIA",1},
                    {"H_HelmetIA_net",1},
                    {"H_HelmetIA_camo",1},
                    {"H_HelmetO_ocamo",1},
                    {"H_HelmetO_oucamo",1},
                    {"H_HelmetLeaderO_ocamo",1},
                    {"H_HelmetLeaderO_oucamo",1}
                };
                semirare[] = {
                    {"H_Shemag_olive_hs",1},
                    {"H_ShemagOpen_tan",1},
                    {"H_ShemagOpen_khk",1},
                    {"H_Shemag_khk",1},
                    {"H_Shemag_tan",1},
                    {"H_Shemag_olive",1},
                    {"H_Helmet_Kerry",1},
                    {"H_HelmetCrew_B",1},
                    {"H_HelmetCrew_I",1},
                    {"H_HelmetCrew_O",1},
                    {"H_CrewHelmetHeli_I",1},
                    {"H_CrewHelmetHeli_B",1},
                    {"H_CrewHelmetHeli_O",1},
                    {"H_PilotHelmetHeli_B",1},
                    {"H_PilotHelmetHeli_I",1},
                    {"H_PilotHelmetHeli_O",1},
                    {"H_PilotHelmetFighter_B",1},
                    {"H_PilotHelmetFighter_I",1},
                    {"H_PilotHelmetFighter_O",1}
                };
                average[] = {
                    {"H_RacingHelmet_1_black_F",1},
                    {"H_RacingHelmet_1_blue_F",1},
                    {"H_RacingHelmet_1_green_F",1},
                    {"H_RacingHelmet_1_orange_F",1},
                    {"H_RacingHelmet_1_red_F",1},
                    {"H_RacingHelmet_1_white_F",1},
                    {"H_RacingHelmet_1_yellow_F",1},
                    {"H_Beret_grn",1},
                    {"H_Beret_blk",1},
                    {"H_Beret_blk_POLICE",1},
                    {"H_Beret_red",1},
                    {"H_Beret_brn_SF",1},
                    {"H_Beret_grn_SF",1},
                    {"H_Beret_02",1},
                    {"H_Beret_Colonel",1},
                    {"H_Beret_ocamo",1},
                    {"H_TurbanO_blk",1},
                    {"H_MilCap_blue",1},
                    {"H_MilCap_gry",1},
                    {"H_MilCap_ocamo",1},
                    {"H_MilCap_rucamo",1},
                    {"H_MilCap_oucamo",1},
                    {"H_MilCap_mcamo",1},
                    {"H_MilCap_dgtl",1}
                };
                semicommon[] = {
                    {"H_Booniehat_dirty",1},
                    {"H_Booniehat_khk_hs",1},
                    {"H_Booniehat_grn",1},
                    {"H_Booniehat_indp",1},
                    {"H_Booniehat_khk",1},
                    {"H_Booniehat_oli",1},
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_dgtl",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Cap_grn_BI",1},
                    {"H_Cap_blk",1},
                    {"H_Cap_blu",1},
                    {"H_Cap_oli",1},
                    {"H_Cap_grn",1},
                    {"H_Cap_red",1},
                    {"H_Cap_surfer",1},
                    {"H_Cap_tan",1},
                    {"H_Cap_blk_CMMG",1},
                    {"H_Cap_blk_ION",1},
                    {"H_Cap_oli_hs",1},
                    {"H_Cap_police",1},
                    {"H_Cap_usblack",1},
                    {"H_Cap_tan_specops_US",1},
                    {"H_Cap_blk_Raven",1},
                    {"H_Cap_brn_SPECOPS",1},
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_headphones",1},
                    {"H_Cap_press",1},
                    {"H_Cap_marshal",1},
                    {"H_Watchcap_camo",1},
                    {"H_Watchcap_blk",1},
                    {"H_Hat_blue",1},
                    {"H_Hat_brown",1},
                    {"H_Hat_camo",1},
                    {"H_Hat_checker",1},
                    {"H_Hat_grey",1},
                    {"H_Hat_tan",1}
                };
                common[] = {
                    {"H_Bandanna_gry",1},
                    {"H_Bandanna_blu",1},
                    {"H_Bandanna_cbr",1},
                    {"H_Bandanna_mcamo",1},
                    {"H_Bandanna_sgg",1},
                    {"H_Bandanna_sand",1},
                    {"H_Bandanna_surfer",1},
                    {"H_Bandanna_surfer_blk",1},
                    {"H_Bandanna_surfer_grn",1},
                    {"H_Bandanna_camo",1},
                    {"H_Bandanna_khk",1},
                    {"H_Bandanna_khk_hs",1},
                    {"H_BandMask_blk",1},
                    {"H_BandMask_demon",1},
                    {"H_BandMask_khk",1},
                    {"H_BandMask_reaper",1},
                    {"H_Watchcap_cbr",1},
                    {"H_Watchcap_khk",1},
                    {"H_Watchcap_sgg",1},
                    {"H_StrawHat",1},
                    {"H_StrawHat_dark",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"ItemGPS",1},
                    {"NVGoggles",1},
                    {"Binocular",1},
                    {"Rangefinder",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1},
                    {"ItemRadio",1}
                };
                semirare[] = {
                    {"Binocular",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                semicommon[] = {
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                common[] = {
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_hgun_P07",1}
                };
                semirare[] = {
                    {"DSR_hgun_P07",1}
                };
                average[] = {
                    {"DSR_hgun_P07",1}
                };
                semicommon[] = {
                    {"DSR_hgun_P07",1}
                };
                common[] = {
                    {"DSR_hgun_P07",1}
                };
            };
            class Construction {
                rare[] = {
                    {"dsr_item_butane_full",1},
                    {"dsr_item_propane_full",1},
                    {"dsr_item_metalwire",1},
                    {"dsr_item_multimeter",1}
                };
                semirare[] = {
                    {"dsr_item_butanetorch",1},
                    {"dsr_item_butane_empty",1},
                    {"dsr_item_propanecooker",1},
                    {"dsr_item_drill",1},
                    {"dsr_item_grinder",1},
                    {"dsr_item_tapemeasure",1},
                    {"dsr_item_fuelcan_full",1},
                    {"dsr_item_oilcan_full",1}
                };
                average[] = {
                    {"dsr_item_propane_empty",1},
                    {"dsr_item_pliers",1},
                    {"dsr_item_ducttape",1},
                    {"dsr_item_saw",1}
                };
                semicommon[] = {
                    {"dsr_item_canopener",1},
                    {"dsr_item_matches",1},
                    {"dsr_item_hammer",1},
                    {"dsr_item_fuelcan_empty",1},
                    {"dsr_item_oilcan_empty",1}
                };
                common[] = {
                    {"dsr_item_tincontainer",1},
                    {"dsr_item_nailfile",1},
                    {"dsr_item_screwdriver_flathead",1},
                    {"dsr_item_screwdriver_phillips",1},
                    {"dsr_item_bucket_empty",1},
                    {"dsr_item_plasticjug",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"ItemRadio",1},
                    {"ItemGPS",1},
                    {"dsr_item_battery_charged",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portablegenerator",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_satphone",1},
                    {"dsr_item_laptop",1}
                };
                semirare[] = {
                    {"ItemRadio",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_laptop",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"dsr_item_battery_dead",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_camera",1}
			};
                semicommon[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
                common[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
            };
            //Nothing Yet
            class CarPart {
                rare[] = {
                    {"dsr_item_log",1}
                };
                semirare[] = {
                    {"dsr_item_log",1}
                };
                average[] = {
                    {"dsr_item_log",1}
                };
                semicommon[] = {
                    {"dsr_item_log",1}
                };
                common[] = {
                    {"dsr_item_log",1}
                };
            };
            class Attachment {
                rare[] = {
                    {"optic_SOS",1},
                    {"optic_NVS",1},
                    {"optic_Nightstalker",1},
                    {"optic_tws",1},
                    {"optic_tws_mg",1},
                    {"optic_DMS",1},
                    {"optic_LRPS",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"bipod_01_F_mtp",1},
                    {"bipod_02_F_tan",1},
                    {"bipod_02_F_hex",1},
                    {"bipod_03_F_oli",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                semirare[] = {
                    {"optic_AMS",1},
                    {"optic_AMS_khk",1},
                    {"optic_AMS_snd",1},
                    {"optic_KHS_blk",1},
                    {"optic_KHS_hex",1},
                    {"optic_KHS_old",1},
                    {"optic_KHS_tan",1},
                    {"optic_MRCO",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                average[] = {
                    {"optic_Arco",1},
                    {"optic_Hamr",1},
                    {"optic_Holosight",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1}
                };
                semicommon[] = {
                    {"optic_Aco",1},
                    {"optic_ACO_grn",1},
                    {"optic_Aco_smg",1},
                    {"optic_ACO_grn_smg",1},
                    {"acc_flashlight",1}
                };
                common[] = {
                    {"optic_MRD",1},
                    {"optic_Yorris",1},
                    {"acc_flashlight",1}
                };
            };
        };
        class Mechanical {
            class Weapon {
                rare[] = {
                    {"DSR_srifle_DMR_02",5},                //MAR-10
                    {"DSR_srifle_DMR_02_camo",5},           //MAR-10
                    {"DSR_srifle_DMR_02_sniper",5},         //MAR-10
                    {"DSR_srifle_DMR_03",6},                //Mk-I EMR
                    {"DSR_srifle_DMR_03_khaki",5},          //Mk-I EMR
                    {"DSR_srifle_DMR_03_tan",5},            //Mk-I EMR
                    {"DSR_srifle_DMR_03_multicam",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_03_woodland",5},       //Mk-I EMR
                    {"DSR_srifle_DMR_04",4},                //ASP-1 Kir
                    {"DSR_srifle_DMR_04_Tan",5},            //ASP-1 Kir
                    {"DSR_srifle_DMR_05_blk",5},            //Cyrus
                    {"DSR_srifle_DMR_05_hex",5},            //Cyrus
                    {"DSR_srifle_DMR_05_tan",5},            //Cyrus
                    {"DSR_srifle_EBR",7},
                    {"DSR_srifle_GM6",1},
                    {"DSR_srifle_GM6_camo",1},
                    {"DSR_srifle_LRR",2},
                    {"DSR_srifle_LRR_camo",2},
                    {"DSR_LMG_Zafir",7},
                    {"DSR_MMG_01_hex",2},                   //Navid
                    {"DSR_MMG_01_tan",2},                   //Navid
                    {"DSR_MMG_02_camo",3},                  //SPMG
                    {"DSR_MMG_02_black",4},                 //SPMG
                    {"DSR_MMG_02_sand",4}                   //SPMG
                };
                semirare[] = {
                    {"DSR_arifle_MX_GL",17},
                    {"DSR_arifle_MX_GL_Black",16},
                    {"DSR_arifle_MX_SW",15},
                    {"DSR_arifle_MX_SW_Black",14},
                    {"DSR_arifle_MXM",13},
                    {"DSR_arifle_MXM_Black",12},
                    {"DSR_LMG_Mk200",6},
                    {"DSR_srifle_DMR_01",5},                 //Rahim
                    {"DSR_srifle_DMR_06_camo",1},            //Mk14
                    {"DSR_srifle_DMR_06_olive",1}            //Mk14
                };
                average[] = {
                    {"DSR_arifle_Katiba",20},
                    {"DSR_arifle_Katiba_C",18},
                    {"DSR_arifle_Katiba_GL",16},
                    {"DSR_arifle_MXC",13},
                    {"DSR_arifle_MXC_Black",12},
                    {"DSR_arifle_MX",11},
                    {"DSR_arifle_MX_Black",10}
                };
                semicommon[] = {
                    {"DSR_arifle_Katiba",37},
                    {"DSR_arifle_Katiba_C",32},
                    {"DSR_arifle_Katiba_GL",31}
                };
                common[] = {
                    {"DSR_SMG_01",45},
                    {"DSR_SMG_02",55}
                };
            };
            class Handgun {
                rare[] = {
                    {"DSR_hgun_PDW2000",1},
                    {"DSR_hgun_Pistol_heavy_01",35},    //4-five
                    {"DSR_hgun_Pistol_heavy_02",10},    //Zubr
                    {"DSR_hgun_P07",54}
                };
                semirare[] = {
                    {"DSR_hgun_Pistol_heavy_01",5},    //4-five
                    {"DSR_hgun_P07",40},
                    {"DSR_hgun_Rook",55}
                };
                average[] = {
                    {"DSR_hgun_ACPC2",55},
                    {"DSR_hgun_P07",10},
                    {"DSR_hgun_Rook",35}
                };
                semicommon[] = {
                    {"DSR_hgun_Rook",25},
                    {"DSR_hgun_ACPC2",75}
                };
                common[] = {
                    {"DSR_hgun_Pistol_Signal",45},
                    {"DSR_hgun_ACPC2",55}
                };
            };
            class Magazine {
                rare[] = {
                    {"100Rnd_580x42_Mag_F",13},
                    {"100Rnd_580x42_Mag_Tracer_F",12},
                    {"5Rnd_127x108_Mag",2},             //12.7 mm 5Rnd Mag
                    {"5Rnd_127x108_APDS_Mag",1},        //12.7mm 5Rnd APDS Mag
                    {"10Rnd_127x54_Mag",3},             //12.7mm 10Rnd Mag - ASPR
                    {"7Rnd_408_Mag",6},                 //.408 7Rnd LRR Mag
                    {"20Rnd_762x51_Mag",10},            //7.62 mm 20Rnd Mag
                    {"10Rnd_338_Mag",6},                //.338 LM 10Rnd Mag
                    {"10Rnd_93x64_DMR_05_Mag",3},       //9.3mm 10Rnd Mag
                    {"10Rnd_50BW_Mag_F",4},             //.50 BW 10Rnd Caseless Mag - Type 115
                    {"130Rnd_338_Mag",4},
                    {"150Rnd_762x54_Box",8},
                    {"150Rnd_762x54_Box_Tracer",7},
                    {"150Rnd_93x64_Mag",5},
                    {"1Rnd_HE_Grenade_shell",9},
                    {"3Rnd_HE_Grenade_shell",7}
                };
                semirare[] = {
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"30Rnd_65x39_caseless_mag",5},
                    {"30Rnd_65x39_caseless_green",4},
                    {"30Rnd_65x39_caseless_mag_Tracer",4},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",4},
                    {"10Rnd_762x54_Mag",3},                         //7.62 mm 10Rnd Mag - Rahim
                    {"30Rnd_762x39_Mag_F",2},
                    {"30Rnd_762x39_Mag_Green_F",1},
                    {"30Rnd_762x39_Mag_Tracer_F",1},
                    {"30Rnd_762x39_Mag_Tracer_Green_F",1},
                    {"30Rnd_580x42_Mag_F",3},
                    {"30Rnd_580x42_Mag_Tracer_F",2},
                    {"100Rnd_65x39_caseless_mag",3},
                    {"100Rnd_65x39_caseless_mag_Tracer",2},
                    {"200Rnd_65x39_cased_Box",3},
                    {"200Rnd_65x39_cased_Box_Tracer",2},
                    {"200Rnd_65x39_Belt_Tracer_Red",2},
                    {"200Rnd_65x39_Belt_Tracer_Green",2},
                    {"200Rnd_65x39_Belt_Tracer_Yellow",2},
                    {"150Rnd_762x54_Box",3},
                    {"150Rnd_762x54_Box_Tracer",2},
                    {"150Rnd_556x45_Drum_Mag_F",3},
                    {"150Rnd_556x45_Drum_Mag_Tracer_F",1},
                    {"200Rnd_556x45_Box_F",4},
                    {"200Rnd_556x45_Box_Red_F",3},
                    {"200Rnd_556x45_Box_Tracer_F",3},
                    {"200Rnd_556x45_Box_Tracer_Red_F",3}
                };
                average[] = {
                    {"30Rnd_545x39_Mag_F",12},
                    {"30Rnd_545x39_Mag_Green_F",11},
                    {"30Rnd_545x39_Mag_Tracer_F",11},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",10},
                    {"30Rnd_556x45_Stanag",6},
                    {"30Rnd_556x45_Stanag_green",5},
                    {"30Rnd_556x45_Stanag_red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Red",5},
                    {"30Rnd_556x45_Stanag_Tracer_Green",5},
                    {"30Rnd_556x45_Stanag_Tracer_Yellow",5},
                    {"20Rnd_556x45_UW_mag",7},
                    {"30Rnd_65x39_caseless_mag",4},
                    {"30Rnd_65x39_caseless_green",3},
                    {"30Rnd_65x39_caseless_mag_Tracer",3},
                    {"30Rnd_65x39_caseless_green_mag_Tracer",3},
                    {"20Rnd_650x39_Cased_Mag_F",5}
                };
                semicommon[] = {
                    {"30Rnd_545x39_Mag_F",3},
                    {"30Rnd_545x39_Mag_Green_F",2},
                    {"30Rnd_545x39_Mag_Tracer_F",2},
                    {"30Rnd_545x39_Mag_Tracer_Green_F",2},
                    {"30Rnd_45ACP_Mag_SMG_01",10},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Green",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",7},
                    {"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02",9},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Red",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",7},
                    {"30Rnd_9x21_Mag_SMG_02_Tracer_Green",7},
                    {"30Rnd_9x21_Mag",9},
                    {"30Rnd_9x21_Red_Mag",7},
                    {"30Rnd_9x21_Yellow_Mag",7},
                    {"30Rnd_9x21_Green_Mag",7}
                };
                common[] = {
                    {"FlareWhite_F",9},
                    {"FlareGreen_F",9},
                    {"FlareRed_F",9},
                    {"FlareYellow_F",9},
                    {"6Rnd_GreenSignal_F",9},
                    {"6Rnd_RedSignal_F",9},
                    {"10Rnd_9x21_Mag",7},
                    {"16Rnd_9x21_Mag",4},
                    {"16Rnd_9x21_red_Mag",5},
                    {"16Rnd_9x21_green_Mag",5},
                    {"16Rnd_9x21_yellow_Mag",5},
                    {"11Rnd_45ACP_Mag",8},
                    {"9Rnd_45ACP_Mag",9},
                    {"6Rnd_45ACP_Cylinder",3}
                };
            };
			class Food {
                rare[] = {
                    {"dsr_item_beans",1}
                };
                semirare[] = {
                    {"dsr_item_cereal",1}
                };
                average[] = {
                    {"dsr_item_powderedmilk",1}
                };
                semicommon[] = {
                    {"dsr_item_rice",1}
                };
                common[] = {
                    {"dsr_item_bacon",1}
                };
            };
            class Drink {
                rare[] = {
                    {"dsr_item_waterbottle_full",1},
                    {"dsr_item_canteen_full",1}
                };
                semirare[] = {
                    {"dsr_item_rustyspirit",1},
                    {"dsr_item_spirit",1}
			};
                average[] = {
                    {"dsr_item_franta",1}
                };
                semicommon[] = {
                    {"dsr_item_waterbottle_empty",1},
                    {"dsr_item_canteen_empty",1}
                };
                common[] = {
                    {"dsr_item_waterbottle_dirty",1},
                    {"dsr_item_canteen_dirty",1}
                };
            };
            class Medical {
                rare[] = {
                    {"dsr_item_antibiotic",1},
                    {"dsr_item_bandage",1},
                    {"dsr_item_defibrillator",1},
                    {"dsr_item_bloodbag_full",1}
                };
                semirare[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_bloodbag_empty",1}
                };
                average[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_disinfectant",1},
                    {"dsr_item_painkillers",1},
                    {"dsr_item_waterpurificationtablets",1}
                };
                semicommon[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_handwarmer",1},
                    {"dsr_item_vitamins",1}
                };
                common[] = {
                    {"dsr_item_bandage",1},
                    {"dsr_item_vitamins",1}
			};
            };
            class Junk {
                rare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                semirare[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1},
                    {"ItemWatch",1}
                };
                average[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                semicommon[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
                common[] = {
                    {"UGL_FlareCIR_F",1},
                    {"UGL_FlareGreen_F",1},
                    {"UGL_FlareRed_F",1},
                    {"UGL_FlareWhite_F",1},
                    {"UGL_FlareYellow_F",1}
                };
            };
            class Backpack {
                rare[] = {
                    {"B_Carryall_oucamo",1},
                    {"B_Carryall_ocamo",1},
                    {"B_Carryall_khk",1},
                    {"B_Carryall_oli",1},
                    {"B_Carryall_cbr",1},
                    {"B_Carryall_mcamo",1},
                    //Special Need to Test (Some might spawn with gear in them)
                    {"I_Parachute_02_F",1},
                    {"B_Parachute_02_F",1},
                    {"B_AssaultPack_rgr_LAT",1},
                    {"B_AssaultPack_rgr_Medic",1},
                    {"B_AssaultPack_rgr_Repair",1},
                    {"B_AssaultPack_blk_DiverExp",1},
                    {"B_Kitbag_rgr_Exp",1},
                    {"B_FieldPack_blk_DiverExp",1},
                    {"B_FieldPack_ocamo_Medic",1},
                    {"B_FieldPack_cbr_LAT",1},
                    {"B_FieldPack_cbr_Repair",1},
                    {"B_Carryall_ocamo_Exp",1}
                };
                semirare[] = {
                    {"B_Kitbag_sgg",1},
                    {"B_Kitbag_cbr",1},
                    {"B_Kitbag_mcamo",1}
                };
                average[] = {
                    {"B_Bergen_blk",1},
                    {"B_Bergen_rgr",1},
                    {"B_Bergen_sgg",1},
                    {"B_Bergen_mcamo",1}
                };
                semicommon[] = {
                    {"B_HuntingBackpack",1},
                    {"B_OutdoorPack_blk",1},
                    {"B_OutdoorPack_blu",1},
                    {"B_OutdoorPack_tan",1},
                    {"B_FieldPack_blk",1},
                    {"B_FieldPack_oucamo",1},
                    {"B_FieldPack_ocamo",1},
                    {"B_FieldPack_cbr",1}
                };
                common[] = {
                    {"B_AssaultPack_blk",1},
                    {"B_AssaultPack_dgtl",1},
                    {"B_AssaultPack_khk",1},
                    {"B_AssaultPack_sgg",1},
                    {"B_AssaultPack_cbr",1},
                    {"B_AssaultPack_mcamo",1}
                };
            };
            class Uniform {
                rare[] = {
                    {"U_B_CombatUniform_wdl",1},
                    {"U_B_CombatUniform_sgg",1},
                    {"U_B_CombatUniform_wdl_tshirt",1},
                    {"U_B_CombatUniform_sgg_tshirt",1},
                    {"U_O_SpecopsUniform_blk",1},
                    {"U_B_CombatUniform_wdl_vest",1},
                    {"U_B_CombatUniform_sgg_vest",1},
                    {"U_B_SpecopsUniform_sgg",1},
                    {"U_AttisBody",1},
                    {"U_AntigonaBody",1},
                    {"U_B_CombatUniform_mcam_worn",1},
                    {"U_B_CombatUniform_mcam_tshirt",1},
                    {"U_B_CombatUniform_mcam",1},
                    {"U_I_CombatUniform",1},
                    {"U_O_CombatUniform_ocamo",1},
                    {"U_O_CombatUniform_oucamo",1},
                    {"U_Competitor",1},
                    {"U_B_CTRG_1",1},
                    {"U_B_CTRG_3",1},
                    {"U_OG_leader",1},
                    {"U_BG_Guerilla1_1",1},
                    {"U_IG_Guerilla1_1",1},
                    {"U_OG_Guerilla1_1",1},
                    {"U_OG_Guerilla2_1",1},
                    {"U_IG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_1",1},
                    {"U_BG_Guerilla2_2",1},
                    {"U_IG_Guerilla2_2",1},
                    {"U_OG_Guerilla2_2",1},
                    {"U_BG_Guerilla2_3",1},
                    {"U_IG_Guerilla2_3",1},
                    {"U_OG_Guerilla2_3",1},
                    {"U_BG_Guerilla3_1",1},
                    {"U_IG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_1",1},
                    {"U_OG_Guerilla3_2",1},
                    {"U_IG_Guerilla3_2",1},
                    {"U_BG_Guerilla3_2",1},
                    {"U_IG_Guerrilla_6_1",1},
                    {"U_BG_Guerrilla_6_1",1},
                    {"U_OG_Guerrilla_6_1",1},
                    {"U_BG_leader",1},
                    {"U_B_FullGhillie_ard",1},
                    {"U_B_FullGhillie_lsh",1},
                    {"U_B_FullGhillie_sard",1},
                    {"U_B_GhillieSuit",1},
                    {"U_B_CombatUniform_mcam_vest",1},
                    {"U_B_Wetsuit",1},
                    {"U_I_Wetsuit",1},
                    {"U_O_Wetsuit",1},
                    {"U_I_G_resistanceLeader_F",1},
                    {"U_IG_leader",1},
                    {"U_I_OfficerUniform",1},
                    {"U_I_CombatUniform_shortsleeve",1},
                    {"U_I_HeliPilotCoveralls",1},
                    {"U_I_pilotCoveralls",1},
                    {"U_I_CombatUniform_tshirt",1},
                    {"U_O_SpecopsUniform_ocamo",1},
                    {"U_O_OfficerUniform_ocamo",1},
                    {"U_O_PilotCoveralls",1}
                };
                semirare[] = {
                    {"U_B_survival_uniform",1},
                    {"U_B_CTRG_2",1},
                    {"U_Marshal",1},
                    {"U_NikosBody",1},
                    {"U_NikosAgedBody",1},
                    {"U_OrestesBody",1},
                    {"U_C_Scientist",1},
                    {"U_C_PriestBody",1},
                    {"U_KerryBody",1},
                    {"U_MillerBody",1},
                    {"U_Rangemaster",1},
                    {"U_B_HeliPilotCoveralls",1},
                    {"U_B_PilotCoveralls",1},
                    {"U_OI_Scientist",1}
                };
                average[] = {
                    {"U_C_Fisherman",1},
                    {"U_C_FishermanOveralls",1},
                    {"U_C_HunterBody_brn",1},
                    {"U_IG_Menelaos",1},
                    {"U_C_Novak",1}
                };
                semicommon[] = {
                    {"U_C_Commoner1_2",1},     
                    {"U_C_Commoner1_3",1},
                    {"U_C_Commoner2_1",1},
                    {"U_C_Commoner2_2",1},
                    {"U_C_Commoner2_3",1}
                };
                common[] = {
                    {"U_C_Poor_2",1},
                    {"U_C_Poor_1",1},
                    {"U_C_Poor_shorts_1",1},
                    {"U_C_Poloshirt_blue",1},
                    {"U_C_Poloshirt_burgundy",1},
                    {"U_C_Poloshirt_tricolour",1},
                    {"U_C_Poloshirt_salmon",1},
                    {"U_C_Poloshirt_redwhite",1},
                    {"U_C_WorkerOveralls",1},
                    {"U_C_Farmer",1},
                    {"U_C_Scavenger_2",1},
                    {"U_C_Scavenger_1",1},
                    {"U_C_Poor_shorts_2",1},
                    {"U_C_Journalist",1},
                    {"U_C_Poloshirt_stripped",1},
                    {"U_C_Commoner1_1",1},
                    {"U_C_Commoner_shorts",1},
                    {"U_C_ShirtSurfer_shorts",1},
                    {"U_C_TeeSurfer_shorts_1",1},
                    {"U_C_TeeSurfer_shorts_2",1},
                    {"U_C_WorkerCoveralls",1},
                    {"U_C_HunterBody_grn",1}
                };
            };
            class Vest {
                rare[] = {
                    {"V_Chestrig_blk",1},
                    {"V_Chestrig_khk",1},
                    {"V_Chestrig_oli",1},
                    {"V_Chestrig_rgr",1},
                    {"V_PlateCarrier1_blk",1},
                    {"V_PlateCarrier1_rgr",1},
                    {"V_PlateCarrier2_rgr",1},
                    {"V_PlateCarrier3_rgr",1},
                    {"V_PlateCarrierGL_rgr",1},
                    {"V_PlateCarrierIA1_dgtl",1},
                    {"V_PlateCarrierIA2_dgtl",1},
                    {"V_PlateCarrierIAGL_dgtl",1},
                    {"V_PlateCarrierSpec_rgr",1},
                    {"V_I_G_resistanceLeader_F",1},
                    {"V_PlateCarrierSpec_blk",1},
                    {"V_PlateCarrierSpec_mtp",1},
                    {"V_PlateCarrierGL_mtp",1},
                    {"V_PlateCarrierGL_blk",1},
                    {"V_PlateCarrierIAGL_oli",1},
                    {"V_PlateCarrier_Kerry",1},
                    {"V_PlateCarrierL_CTRG",1},
                    {"V_PlateCarrierH_CTRG",1},
                    {"V_RebreatherB",1},
                    {"V_RebreatherIA",1},
                    {"V_RebreatherIR",1}
                };
                semirare[] = {
                    {"V_TacVest_blk",1},
                    {"V_TacVest_blk_POLICE",1},
                    {"V_TacVest_brn",1},
                    {"V_TacVest_camo",1},
                    {"V_TacVest_khk",1},
                    {"V_TacVest_oli",1},
                    {"V_TacVestCamo_khk",1},
                    {"V_TacVestIR_blk",1}
                };
                average[] = {
                    {"V_HarnessO_brn",1},
                    {"V_HarnessO_gry",1},
                    {"V_HarnessOGL_brn",1},
                    {"V_HarnessOGL_gry",1},
                    {"V_HarnessOSpec_brn",1},
                    {"V_HarnessOSpec_gry",1}
                };
                semicommon[] = {
                    {"V_Rangemaster_belt",1},
                    {"V_BandollierB_blk",1},
                    {"V_BandollierB_cbr",1},
                    {"V_BandollierB_khk",1},
                    {"V_BandollierB_oli",1},
                    {"V_BandollierB_rgr",1}
                };
                common[] = {
                    {"V_Press_F",1},
                    {"V_Rangemaster_belt",1}
                };
            };
            class Helmet {
                rare[] = {
                    {"H_HelmetB_camo",1},
                    {"H_HelmetB_grass",1},
                    {"H_HelmetB_black",1},
                    {"H_HelmetB_light",1},
                    {"H_HelmetB_sand",1},
                    {"H_HelmetB_desert",1},
                    {"H_HelmetB_light_black",1},
                    {"H_HelmetB_light_grass",1},
                    {"H_HelmetB_light_snakeskin",1},
                    {"H_HelmetB_light_desert",1},
                    {"H_HelmetB_light_sand",1},
                    {"H_HelmetB_snakeskin",1},
                    {"H_HelmetB_paint",1},
                    {"H_HelmetSpecB",1},
                    {"H_HelmetSpecB_paint1",1},
                    {"H_HelmetSpecB_blk",1},
                    {"H_HelmetSpecB_paint2",1},
                    {"H_HelmetSpecO_ocamo",1},
                    {"H_HelmetSpecO_blk",1},
                    {"H_HelmetB_plain_blk",1},
                    {"H_HelmetB_plain_mcamo",1},
                    {"H_HelmetB",1},
                    {"H_HelmetIA",1},
                    {"H_HelmetIA_net",1},
                    {"H_HelmetIA_camo",1},
                    {"H_HelmetO_ocamo",1},
                    {"H_HelmetO_oucamo",1},
                    {"H_HelmetLeaderO_ocamo",1},
                    {"H_HelmetLeaderO_oucamo",1}
                };
                semirare[] = {
                    {"H_Shemag_olive_hs",1},
                    {"H_ShemagOpen_tan",1},
                    {"H_ShemagOpen_khk",1},
                    {"H_Shemag_khk",1},
                    {"H_Shemag_tan",1},
                    {"H_Shemag_olive",1},
                    {"H_Helmet_Kerry",1},
                    {"H_HelmetCrew_B",1},
                    {"H_HelmetCrew_I",1},
                    {"H_HelmetCrew_O",1},
                    {"H_CrewHelmetHeli_I",1},
                    {"H_CrewHelmetHeli_B",1},
                    {"H_CrewHelmetHeli_O",1},
                    {"H_PilotHelmetHeli_B",1},
                    {"H_PilotHelmetHeli_I",1},
                    {"H_PilotHelmetHeli_O",1},
                    {"H_PilotHelmetFighter_B",1},
                    {"H_PilotHelmetFighter_I",1},
                    {"H_PilotHelmetFighter_O",1}
                };
                average[] = {
                    {"H_RacingHelmet_1_black_F",1},
                    {"H_RacingHelmet_1_blue_F",1},
                    {"H_RacingHelmet_1_green_F",1},
                    {"H_RacingHelmet_1_orange_F",1},
                    {"H_RacingHelmet_1_red_F",1},
                    {"H_RacingHelmet_1_white_F",1},
                    {"H_RacingHelmet_1_yellow_F",1},
                    {"H_Beret_grn",1},
                    {"H_Beret_blk",1},
                    {"H_Beret_blk_POLICE",1},
                    {"H_Beret_red",1},
                    {"H_Beret_brn_SF",1},
                    {"H_Beret_grn_SF",1},
                    {"H_Beret_02",1},
                    {"H_Beret_Colonel",1},
                    {"H_Beret_ocamo",1},
                    {"H_TurbanO_blk",1},
                    {"H_MilCap_blue",1},
                    {"H_MilCap_gry",1},
                    {"H_MilCap_ocamo",1},
                    {"H_MilCap_rucamo",1},
                    {"H_MilCap_oucamo",1},
                    {"H_MilCap_mcamo",1},
                    {"H_MilCap_dgtl",1}
                };
                semicommon[] = {
                    {"H_Booniehat_dirty",1},
                    {"H_Booniehat_khk_hs",1},
                    {"H_Booniehat_grn",1},
                    {"H_Booniehat_indp",1},
                    {"H_Booniehat_khk",1},
                    {"H_Booniehat_oli",1},
                    {"H_Booniehat_tan",1},
                    {"H_Booniehat_dgtl",1},
                    {"H_Booniehat_mcamo",1},
                    {"H_Cap_grn_BI",1},
                    {"H_Cap_blk",1},
                    {"H_Cap_blu",1},
                    {"H_Cap_oli",1},
                    {"H_Cap_grn",1},
                    {"H_Cap_red",1},
                    {"H_Cap_surfer",1},
                    {"H_Cap_tan",1},
                    {"H_Cap_blk_CMMG",1},
                    {"H_Cap_blk_ION",1},
                    {"H_Cap_oli_hs",1},
                    {"H_Cap_police",1},
                    {"H_Cap_usblack",1},
                    {"H_Cap_tan_specops_US",1},
                    {"H_Cap_blk_Raven",1},
                    {"H_Cap_brn_SPECOPS",1},
                    {"H_Cap_khaki_specops_UK",1},
                    {"H_Cap_headphones",1},
                    {"H_Cap_press",1},
                    {"H_Cap_marshal",1},
                    {"H_Watchcap_camo",1},
                    {"H_Watchcap_blk",1},
                    {"H_Hat_blue",1},
                    {"H_Hat_brown",1},
                    {"H_Hat_camo",1},
                    {"H_Hat_checker",1},
                    {"H_Hat_grey",1},
                    {"H_Hat_tan",1}
                };
                common[] = {
                    {"H_Bandanna_gry",1},
                    {"H_Bandanna_blu",1},
                    {"H_Bandanna_cbr",1},
                    {"H_Bandanna_mcamo",1},
                    {"H_Bandanna_sgg",1},
                    {"H_Bandanna_sand",1},
                    {"H_Bandanna_surfer",1},
                    {"H_Bandanna_surfer_blk",1},
                    {"H_Bandanna_surfer_grn",1},
                    {"H_Bandanna_camo",1},
                    {"H_Bandanna_khk",1},
                    {"H_Bandanna_khk_hs",1},
                    {"H_BandMask_blk",1},
                    {"H_BandMask_demon",1},
                    {"H_BandMask_khk",1},
                    {"H_BandMask_reaper",1},
                    {"H_Watchcap_cbr",1},
                    {"H_Watchcap_khk",1},
                    {"H_Watchcap_sgg",1},
                    {"H_StrawHat",1},
                    {"H_StrawHat_dark",1}
                };
            };
            class Cosmetic {
                rare[] = {
                    {"ItemGPS",1},
                    {"NVGoggles",1},
                    {"Binocular",1},
                    {"Rangefinder",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1},
                    {"ItemRadio",1}
                };
                semirare[] = {
                    {"Binocular",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                semicommon[] = {
                    {"ItemMap",1},
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
                common[] = {
                    {"ItemWatch",1},
                    {"ItemCompass",1}
                };
            };
            class GeneralItem {
                rare[] = {
                    {"DSR_hgun_P07",1}
                };
                semirare[] = {
                    {"DSR_hgun_P07",1}
                };
                average[] = {
                    {"DSR_hgun_P07",1}
                };
                semicommon[] = {
                    {"DSR_hgun_P07",1}
                };
                common[] = {
                    {"DSR_hgun_P07",1}
                };
            };
            class Construction {
                rare[] = {
                    {"dsr_item_butane_full",1},
                    {"dsr_item_propane_full",1},
                    {"dsr_item_metalwire",1},
                    {"dsr_item_multimeter",1}
                };
                semirare[] = {
                    {"dsr_item_butanetorch",1},
                    {"dsr_item_butane_empty",1},
                    {"dsr_item_propanecooker",1},
                    {"dsr_item_drill",1},
                    {"dsr_item_grinder",1},
                    {"dsr_item_tapemeasure",1},
                    {"dsr_item_fuelcan_full",1},
                    {"dsr_item_oilcan_full",1}
                };
                average[] = {
                    {"dsr_item_propane_empty",1},
                    {"dsr_item_pliers",1},
                    {"dsr_item_ducttape",1},
                    {"dsr_item_saw",1}
                };
                semicommon[] = {
                    {"dsr_item_canopener",1},
                    {"dsr_item_matches",1},
                    {"dsr_item_hammer",1},
                    {"dsr_item_fuelcan_empty",1},
                    {"dsr_item_oilcan_empty",1}
                };
                common[] = {
                    {"dsr_item_tincontainer",1},
                    {"dsr_item_nailfile",1},
                    {"dsr_item_screwdriver_flathead",1},
                    {"dsr_item_screwdriver_phillips",1},
                    {"dsr_item_bucket_empty",1},
                    {"dsr_item_plasticjug",1}
                };
            };
            class Electronic {
                rare[] = {
                    {"ItemRadio",1},
                    {"ItemGPS",1},
                    {"dsr_item_battery_charged",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portablegenerator",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_satphone",1},
                    {"dsr_item_laptop",1}
                };
                semirare[] = {
                    {"ItemRadio",1},
                    {"dsr_item_extensioncord",1},
                    {"dsr_item_portableradio",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_laptop",1}
                };
                average[] = {
                    {"ItemRadio",1},
                    {"dsr_item_battery_dead",1},
                    {"dsr_item_phonesmart",1},
                    {"dsr_item_camera",1}
			};
                semicommon[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
                common[] = {
                    {"dsr_item_phoneold",1},
                    {"dsr_item_battery_dead",1}
                };
            };
            //Nothing Yet
            class CarPart {
                rare[] = {
                    {"dsr_item_log",1}
                };
                semirare[] = {
                    {"dsr_item_log",1}
                };
                average[] = {
                    {"dsr_item_log",1}
                };
                semicommon[] = {
                    {"dsr_item_log",1}
                };
                common[] = {
                    {"dsr_item_log",1}
                };
            };
            class Attachment {
                rare[] = {
                    {"optic_SOS",1},
                    {"optic_NVS",1},
                    {"optic_Nightstalker",1},
                    {"optic_tws",1},
                    {"optic_tws_mg",1},
                    {"optic_DMS",1},
                    {"optic_LRPS",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"bipod_01_F_mtp",1},
                    {"bipod_02_F_tan",1},
                    {"bipod_02_F_hex",1},
                    {"bipod_03_F_oli",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                semirare[] = {
                    {"optic_AMS",1},
                    {"optic_AMS_khk",1},
                    {"optic_AMS_snd",1},
                    {"optic_KHS_blk",1},
                    {"optic_KHS_hex",1},
                    {"optic_KHS_old",1},
                    {"optic_KHS_tan",1},
                    {"optic_MRCO",1},
                    {"bipod_01_F_snd",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1},
                    {"acc_pointer_IR",1}
                };
                average[] = {
                    {"optic_Arco",1},
                    {"optic_Hamr",1},
                    {"optic_Holosight",1},
                    {"bipod_01_F_blk",1},
                    {"acc_flashlight",1}
                };
                semicommon[] = {
                    {"optic_Aco",1},
                    {"optic_ACO_grn",1},
                    {"optic_Aco_smg",1},
                    {"optic_ACO_grn_smg",1},
                    {"acc_flashlight",1}
                };
                common[] = {
                    {"optic_MRD",1},
                    {"optic_Yorris",1},
                    {"acc_flashlight",1}
                };
            };
        };
	};
	class Buildings {
		class Land_Airport_01_controlTower_F {
			table = "Military";
			positions[] = {{-3.00696, 3.91602, 4.21086}, {3.06915, 3.89941, 4.23131}, {0.0256958, -2.06201, 4.21085}, {0.376404, 1.16602, 4.65663}, {-1.27332, 0.373535, 7.91646}
			};
		};

		class Land_Airport_02_terminal_F {
			table = "Commercial";
			positions[] = {{3.36981, 10.9082, -1.40149}, {0.277771, 4.55811, -1.40149}, {2.60266, -0.411133, -1.40149}, {5.20868, 3.13037, -1.40149}, {9.82227, 1.33496, -1.40149}, {10.3759, -2.8335, -1.40149}, {-3.33417, -9.50488, -1.40149}, {-19.4422, -10.1187, -1.40149}, {12.8807, -10.3208, -1.40149}, {22.9008, -5.79883, -1.40149}, {21.9941, 10.5249, -1.40149}
			};
		};

		class Land_Airport_01_terminal_F {
			table = "Commercial";
			positions[] = {{-14.3466, -0.588379, -4.02741}, {-11.2858, 2.41602, -4.02741}, {-8.2597, 4.43359, -3.98237}, {-5.414, 7.771, -3.98237}, {8.09961, 8.10889, -4.01762}, {6.22021, -7.17871, -4.00997}, {9.02838, -10.4839, -4.00997}, {5.16388, 5.54004, -4.02803}, {-1.08685, 1.23682, -4.10765}, {3.38068, -4.2085, -4.12297}
			};
		};

		class Land_Airport_01_hangar_F {
			table = "Mechanical";
			positions[] = {{12.7657, -8.04395, -2.68443}, {12.7607, 12.7231, -2.68448}, {-13.3329, 13.9307, -2.68448}, {-12.2171, -7.75732, -2.68444}, {0.403809, 13.1753, -2.68448}, {13.1948, -2.32715, -2.68444}
			};
		};

		class Land_House_Big_04_F {
			table = "Civilian";
			positions[] = {{3.31604, 6.40625, -2.94933}, {-8.47241, 6.26709, -2.95065}, {-8.08984, -6.6377, -2.94858}, {1.90912, -6.72803, -2.94858}, {-8.40582, -6.66602, 0.276856}, {11.6814, -7.04492, 0.276991}, {-0.609863, -7.23633, 0.27781}, {-8.26996, 6.34521, 0.303274}, {4.09497, 6.37451, 0.302769}, {3.77234, 1.79395, 0.301416}, {-5.09198, 4.31494, 0.301416}, {-4.98438, 1.64209, 0.301415}, {-5.69537, -4.48975, -2.94858}, {3.39117, -3.10498, -2.94858}
			};
		};

		class Land_MultistoryBuilding_03_F
		{
			table = "Commercial";
			positions[] = {{-2.22174, 7.31934, -25.9053}, {-5.63617, 4.71777, -25.9053}, {-1.87103, 4.64307, -25.9053}, {-7.48083, -0.407715, -24.22}, {-7.4483, -3.91064, -24.2191}
			};
		};

		class Land_House_Small_04_F
		{
			table = "Civilian";
			positions[] = {{-3.64771, 3.82129, -0.866206}, {-3.73071, -2.66895, -0.866206}, {0.299927, 3.69971, -0.866206}, {-1.31946, -3.97314, -0.866206}, {3.38403, -1.32324, -0.866206}, {-0.83905, -6.95166, -0.866206}
			};
		};

		class Land_House_Small_05_F
		{
			table = "Civilian";
			positions[] = {{-2.06793, -3.41797, -1.08627}, {0.886169, 4.17969, -1.08733}, {-2.90967, 3.9873, -1.08697}, {-2.92603, -0.64502, -1.08615}
			};
		};

		class Land_Shop_City_01_F
		{
			table = "Commercial";
			positions[] = {{1.18323, 0.0922852, -4.91619}, {6.22626, 4.52588, -4.9378}, {2.29846, 4.09277, -4.94828}
			};
		};

		class Land_Shop_City_02_F
		{
			table = "Commercial";
			positions[] = {{-0.675201, -5.24316, -4.36327}, {-2.94293, -7.92676, -4.36245}, {-10.3821, -2.96924, -4.35083}, {-8.8096, -7.85156, -4.35083}, {1.24158, -7.73242, -4.3625}, {1.84985, -2.86328, -4.36363}, {7.10519, -3.02295, -4.36247}, {1.10577, -0.0512695, -4.36428}, {6.86386, 1.68848, -4.36254}, {4.33301, 7.78174, -4.368}, {6.64581, 9.625, -4.36479}
			};
		};

		class Land_FireEscape_01_short_F
		{
			table = "Civilian";
			positions[] = {{-1.92456, -2.33057, 5.87384}, {-0.687744, 1.20215, 4.12385}, {-1.83334, -2.31396, 2.36634}, {-1.86963, -2.36035, -1.14366}, {-1.8194, 1.26514, 0.616343}
			};
		};

		class Land_FireEscape_01_tall_F
		{
			table = "Civilian";
			positions[] = {{-0.839661, -0.429199, 5.98783}, {-1.03955, 3.11719, 4.23783}, {-1.88132, -0.458496, 2.48032}, {-1.98297, 3.11963, -2.77967}, {-1.7475, -0.564453, -1.02967}
			};
		};

		class Land_House_Big_05_F
		{
			table = "Civilian";
			positions[] = {{-8.4136, -4.73389, -1.50791}, {-2.1731, -4.72119, -1.50986}, {5.57956, -4.89111, -1.10227}, {4.74078, 5.41748, -1.1154}, {-2.39563, 5.27197, -1.50986}, {-8.5723, 5.36475, -1.50889}
			};
		};

		class Land_Addon_01_F
		{
			table = "Civilian";
			positions[] = {{-0.162262, -3.75, -1.17012}, {-0.0673828, 3.73633, -1.17012}
			};
		};

		class Land_Addon_04_F
		{
			table = "Civilian";
			positions[] = {{-5.5575, -6.90771, 0.333342}, {-4.92792, 4.2417, 0.333342}, {5.39682, -0.76123, 0.333343}, {2.92578, -6.26123, 0.333342}, {-3.0574, 1.4624, 0.333342}, {-0.601196, -0.920898, 0.333342}, {5.26059, 4.20752, 0.333342}
			};
		};

		class Land_Shop_City_05_F
		{
			table = "Commercial";
			positions[] = {{0.827393, -10.8149, -7.26246}, {-1.22951, -12.0522, -7.27676}
			};
		};

		class Land_Shop_City_03_F
		{
			table = "Commercial";
			positions[] = {{1.4767, -7.66504, -4.96703}, {5.70377, -2.34131, -4.95675}, {1.59322, 2.7832, -4.97481}, {3.5081, 9.0791, -4.97082}
			};
		};

		class Land_Shop_City_06_F
		{
			table = "Commercial";
			positions[] = {{-5.3772, -6.00781, -4.04819}, {-5.99379, 0.533691, -4.0484}, {-3.99609, 7.38623, -4.04862}, {1.19998, 8.27539, -2.34276}, {-4.85144, 7.39014, -0.319801}, {7.30609, 3.1167, -0.319942}, {-4.53831, 2.94531, -0.318829}, {-1.19354, 7.81641, -0.319835}
			};
		};

		class Land_Shop_City_07_F
		{
			table = "Commercial";
			positions[] = {{2.7469, 2.46387, 0.0339336}, {1.1144, 7.68164, 0.0339508}, {-3.86372, 7.56201, 3.63137}, {-2.88173, -5.72949, 3.63136}, {2.03906, -0.931641, 3.63136}, {2.27966, -6.27881, 3.63136}
			};
		};

		class Land_MultistoryBuilding_01_F
		{
			table = "Commercial";
			positions[] = {{10.3646, -11.7373, -21.0179}, {10.9926, -2.41699, -21.018}, {10.8797, 3.23242, -21.018}, {19.1703, 3.99951, -21.0179}, {19.2338, -12.2734, -21.018}, {-18.4634, 16.6816, -21.0179}, {-5.52731, 16.2871, -21.0179}, {-18.555, -11.5474, -21.0179}, {-18.4026, 2.79199, -21.0179}, {-11.7448, -8.86279, 19.2657}, {-12.1009, 9.86328, 19.2656}, {17.3746, -10.2432, 19.2657}, {9.97755, 1.6665, 19.2657}, {18.8899, 10.8208, 19.2657}
			};
		};

		class Land_MultistoryBuilding_04_F
		{
			table = "Commercial";
			positions[] = {{8.58585, -11.7158, -36.3151}, {-2.73436, -11.4868, -36.3152}, {-11.4193, -11.5947, -36.3152}, {-10.7024, 0.208008, -36.3152}, {-10.8938, 10.6709, -36.3152}, {-4.59261, 10.0254, 22.396}, {9.54498, 10.1509, 22.396}, {10.3787, -5.79199, 22.396}
			};
		};

		class Land_School_01_F
		{
			table = "Civilian";
			positions[] = {{12.5829, -4.72314, -1.3499}, {5.64906, -4.41797, -1.3499}, {-2.35116, -4.51416, -1.34991}, {-13.0124, -4.5957, -1.3499}, {-13.5541, 3.14209, -1.25486}, {-13.1472, -1.72852, -1.25354}, {-7.8992, -1.9585, -1.24099}, {-2.83229, -1.9165, -1.24139}, {-0.00878716, 3.48877, -1.25486}, {5.56185, -1.90625, -1.24072}, {13.2059, 3.23486, -1.24905}, {13.2425, -1.62842, -1.24132}, {0.097558, -1.6709, -1.24214}
			};
		};

		class Land_House_Big_03_F {
			table = "Civilian";
			positions[] = {{2.81361, -1.31836, -3.17496}, {5.83369, -4.93799, -3.17496}, {9.58751, -1.87451, -3.17496}, {10.1001, 5.53369, -3.20496}, {3.31785, 5.73145, -3.20496}, {10.4125, 0.702148, -3.17496}, {1.97136, 3.28271, -3.17496}, {-11.5872, -4.88965, -0.111648}, {-12.0157, 4.62109, -0.111648}, {-7.68954, -5.24902, -0.111648}, {2.43372, -5.17139, -0.111647}, {9.50365, -4.35547, -0.111646}, {9.58155, 5.29199, -0.111646}, {2.44902, 5.5708, -0.111649}, {3.10835, -2.11768, -0.0905371}, {7.9266, -1.31445, -0.090538}, {7.36005, 3.07031, -0.090538}, {2.70773, 2.98096, -0.090538}
			};
		};

		class Land_MobileCrane_01_F
		{
			table = "Industrial";
			positions[] = {{7.85629, 5.55029, -19.4707}, {12.0654, 5.69873, -19.4707}, {10.0373, 2.60645, -19.0873}, {6.98733, -2.43115, -19.0873}, {13.9328, -2.59424, -14.0242}, {13.9299, 2.29443, -14.0242}, {8.70084, 2.69189, -14.0242}, {8.80087, -2.91406, -14.0242}, {11.6297, -5.54541, -19.4707}, {7.02059, 2.59668, -19.0873}, {10.1519, -2.59424, -19.0873}
			};
		};

		class Land_MobileCrane_01_hook_F
		{
			table = "Industrial";
			positions[] = {{11.0956, -5.58643, -19.4707}, {6.91805, -2.21387, -19.0873}, {6.82528, 2.53857, -19.0873}, {13.3552, -2.09229, -14.0242}, {8.42605, -2.42188, -14.0242}, {13.9843, 2.74951, -14.0242}, {8.44981, 2.72217, -14.0242}, {10.0628, 2.66943, -19.0873}, {12.0439, 5.68994, -19.4707}, {7.33242, 5.74414, -19.4707}, {7.36204, -5.54248, -19.4707}
			};
		};

		class Land_House_Native_01_F
		{
			table = "Civilian";
			positions[] = {{-3.92445, 2.28174, -3.10247}, {3.39246, -1.94092, -3.10247}, {-3.28581, -1.92529, -3.10247}, {3.17792, 2.13477, -3.10247}, {-0.199219, -2.16943, -3.10247}
			};
		};

		class Land_House_Native_02_F
		{
			table = "Civilian";
			positions[] = {{1.9373, 1.4082, -2.41631}, {1.87907, -1.9209, -2.41631}, {-3.27092, 1.9707, -2.41631}, {-3.23453, -2.0166, -2.41631}
			};
		};

		class Land_Temple_Native_01_F
		{
			table = "Civilian";
			positions[] = {{3.20041, -2.3374, -5.95458}, {-3.14743, -2.46436, -5.95458}, {2.58812, 0.324219, -5.95457}, {2.43742, 3.89014, -5.95457}, {-2.53903, 0.67041, -5.95458}, {-2.64441, 4.02686, -5.95457}, {-3.061, 6.80176, -5.95458}, {3.79857, 6.44727, -5.95457}
			};
		};

		class Land_DPP_01_mainFactory_F
		{
			table = "Industrial";
			positions[] = {{-21.92, 4.79346, -9.16247}, {-21.8768, -14.186, -9.18247}, {15.5463, -18.0396, -4.11747}, {17.3237, -14.4956, -4.11747}, {17.8664, -10.7212, -4.11747}, {15.7866, -7.29785, -4.11747}, {12.6862, -4.30322, -4.25747}, {12.8652, -2.36035, -4.25747}, {12.7665, 4.97803, -4.25747}, {12.8564, 6.83545, -5.54747}, {19.0106, -5.35059, -5.54747}, {18.969, 2.31885, -5.54747}, {20.6808, -4.05322, -7.44347}, {20.4157, 1.51514, -7.44347}, {21.2942, 4.77588, -7.44347}, {19.0013, 5.16553, -7.64927}, {8.50312, 8.93994, -0.31447}, {10.524, -1.4873, -0.314478}, {4.05009, 8.87256, 1.14823}, {-0.406693, -0.691895, 1.14823}, {-7.21104, 2.40869, 1.14823}, {-4.97194, -10.0967, 1.14823}, {1.74726, -14.9678, 1.14823}
			};
		};

		class Land_DPP_01_smallFactory_F
		{
			table = "Industrial";
			positions[] = {{10.0669, -5.00342, 0.989646}, {10.1559, 2.146, 0.989654}, {0.462799, 3.25684, 2.4038}, {-2.98578, 3.05713, 2.40379}
			};
		};

		class Land_SM_01_shed_F
		{
			table = "Industrial";
			positions[] = {{14.0747, 6.86572, -1.56921}, {-1.59459, -0.653809, -1.56921}, {-3.98872, 6.8667, -1.56921}, {10.0919, -0.314453, -1.56921}, {-5.87579, -0.795898, -1.56921}, {-5.62433, 1.68408, -1.56921}
			};
		};

		class Land_SM_01_shed_unfinished_F
		{
			table = "Industrial";
			positions[] = {{-7.00366, 6.81445, -1.61709}, {-5.36069, 1.57568, -1.61709}, {-5.80513, -1.16357, -1.61709}, {3.29742, 0.314453, -1.61709}, {14.6968, -0.174316, -1.61709}, {3.89108, 7.02344, -1.61709}
			};
		};

		class Land_SY_01_conveyor_end_F
		{
			table = "Industrial";
			positions[] = {{3.50247, 2.69287, -3.35729}, {3.48972, -2.6001, 1.40514}, {1.32748, 2.69922, 5.25539}, {-1.38519, 2.59424, 5.25539}, {-1.37393, -1.79199, 5.25539}
			};
		};

		class Land_SY_01_crusher_F
		{
			table = "Industrial";
			positions[] = {{-7.73892, 1.16895, -1.09281}, {7.70358, 16.8159, -1.07898}, {-7.75183, 15.2749, -1.07731}, {7.88333, 2.37988, -1.08442}, {0.680634, 1.1582, -1.09289}, {-6.45386, 11.2256, 11.4876}, {6.70441, 9.83057, 11.5466}, {0.257385, 9.21436, -11.2428}
			};
		};

		class Land_SY_01_reclaimer_F
		{
			table = "Industrial";
			positions[] = {{-12.5131, 0.818359, -2.44122}, {-14.1992, 4.99902, -2.43626}
			};
		};

		class Land_SCF_01_boilerBuilding_F
		{
			table = "Industrial";
			positions[] = {{20.4062, 1.76416, -13.1931}, {12.6199, 2.29736, -13.1931}, {19.1641, 12.5249, -13.1931}, {13.0838, 13.4111, -13.1931}, {19.3361, 6.896, -13.193}, {21.7828, 1.04639, -8.64783}, {11.6639, 1.13867, -8.64783}, {11.6371, -1.03662, -5.52507}, {11.9275, -8.00977, -5.52507}, {-2.03784, 23.6602, -13.1631}, {18.4623, 9.35156, -8.62783}
			};
		};

		class Land_SCF_01_chimney_F
		{
			table = "Industrial";
			positions[] = {{-2.89178, -3.82471, -8.19502}, {-1.37646, 4.09912, -8.19501}, {-5.56982, 0.607422, -8.19502}, {-2.37286, -3.05908, 24.3167}, {-0.946167, 2.91748, 24.3167}
			};
		};

		class Land_SCF_01_clarifier_F
		{
			table = "Industrial";
			positions[] = {{5.16095, -5.48291, -2.02836}, {5.43793, 1.60498, 0.396125}, {-0.846191, -4.61816, 0.396124}, {-7.2016, 2.52979, 0.396124}, {2.42871, 5.18262, 0.396125}, {-1.64771, 0.993652, 8.5348}
			};
		};

		class Land_SCF_01_condenser_F
		{
			table = "Industrial";
			positions[] = {{3.0542, -1.01611, 1.98746}, {6.01874, 0.0473633, 1.98747}, {3.11456, 3.13037, 1.98746}, {-7.3927, 13.7788, -1.52646}, {-4.51294, 7.1416, -1.52646}, {-7.06055, 10.3657, -1.52646}
			};
		};

		class Land_SCF_01_crystallizerTowers_F
		{
			table = "Industrial";
			positions[] = {{-9.3371, -3.31641, -9.8089}, {-3.36139, -2.99854, -6.95771}, {4.14148, -3.05127, -6.95771}, {-0.121643, -0.0981445, -7.18977}, {1.98773, 2.02637, 12.1745}, {6.20105, -3.16553, 12.1745}, {-6.76501, -0.98584, 12.9881}, {-2.0943, 2.76416, 12.37}
			};
		};

		class Land_SCF_01_crystallizer_F
		{
			table = "Industrial";
			positions[] = {{2.2359, 8.30762, -5.88057}, {8.7561, 7.07324, -2.84587}, {2.21698, 8.77686, -0.447963}, {8.15094, 1.03223, -0.440189}, {0.874512, 1.38867, -0.440188}, {7.10388, 4.74316, -0.440193}, {-8.89655, 1.19043, -0.440192}, {-7.01703, 4.94238, -0.440189}, {1.51508, 6.84766, 4.98345}, {-8.77814, 4.89258, 5.00417}, {-8.59552, -0.862305, 5.01047}, {4.62744, -0.416016, 5.00403}, {5.25385, 4.87744, 5.00415}
			};
		};

		class Land_SCF_01_diffuser_F
		{
			table = "Industrial";
			positions[] = {{-6.1275, 16.5728, -2.34902}, {-7.93939, 23.563, -2.34902}, {6.34424, 23.2031, -2.34902}, {6.09753, 9.38672, -2.34902}, {1.71259, 5.66504, 0.989358}, {-3.52942, 5.32617, 0.983278}, {6.54865, -8.6416, -2.34902}, {6.21283, -22.5537, 2.35732}, {3.62836, -21.2036, 2.35732}, {-5.05341, -21.7944, 2.35732}, {-7.55786, -19.8203, 2.35732}, {-3.86725, -17.2979, 4.55072}, {0.824524, -13.2207, 4.55072}, {4.81476, -19.0898, 4.55072}, {4.96899, -13.124, 4.55072}
			};
		};

		class Land_SCF_01_feeder_F
		{
			table = "Industrial";
			positions[] = {{4.57166, 17.146, -3.2917}, {-1.12738, 17.4243, -3.2917}, {-4.72894, 11.957, -3.2917}
			};
		};

		class Land_SCF_01_generalBuilding_F
		{
			table = "Industrial";
			positions[] = {{13.7668, 3.3667, -4.84506}, {5.23486, -14.1592, -4.82014}, {2.16504, -16.2207, -0.336995}, {3.49451, -20.2495, -0.336994}, {5.50555, -23.8975, -0.330949}, {1.70123, -21.7822, -4.82014}, {-4.39288, -15.479, -4.82014}, {-5.02173, -21.3472, -4.82014}, {-5.44708, -23.9912, -0.328772}, {-3.40857, -15.0322, -0.336995}, {-4.04376, -19.9419, -0.333236}, {-7.72589, -8.42334, -0.306211}, {-2.13281, -21.9604, 9.71007}, {-2.1366, -3.09473, 9.71008}
			};
		};

		class Land_SCF_01_storageBin_big_F
		{
			table = "Industrial";
			positions[] = {{4.19385, -9.50781, 8.08185}, {-7.11786, 7.35254, 8.08648}, {-7.30212, -6.74121, 8.09786}, {1.07813, -2.38184, 8.36898}, {5.74097, 7.80664, 8.11623}
			};
		};

		class Land_SCF_01_storageBin_small_F
		{
			table = "Industrial";
			positions[] = {{-0.780762, 3.31348, 7.58101}, {1.15662, -0.510254, 7.53981}
			};
		};

		class Land_SCF_01_warehouse_F
		{
			table = "Industrial";
			positions[] = {{4.28088, -12.4028, -4.56458}, {8.55493, -13.3931, -4.56458}, {16.1413, 14.8442, -4.53404}, {-9.50293, 16.6538, -4.56258}, {-11.0309, 13.7896, -4.56258}
			};
		};

		class Land_SCF_01_washer_F
		{
			table = "Industrial";
			positions[] = {{-5.66089, -10.9932, -1.77585}, {-4.77167, 8.43359, -1.77585}, {0.351501, 9.09912, -1.77585}, {3.99756, 7.39648, -1.77585}, {5.72986, 2.22656, 2.2026}, {5.43201, 0.609375, -1.77584}, {5.75275, -11.5483, -1.77584}, {-5.56262, 1.96045, 2.20261}, {-2.67273, 7.06201, 3.2295}, {2.84528, 7.07959, 3.2295}, {-5.63361, -4.71387, -1.77585}
			};
		};

		class Land_Warehouse_03_F
		{
			table = "Industrial";
			positions[] = {{-10.0099, 4.12891, -2.36559}, {4.32355, -0.524414, -2.36164}, {6.4068, 4.54395, -2.36594}, {6.07056, 4.87842, 0.188947}, {7.8252, 1.41455, 0.199012}, {5.80853, -0.0791016, -2.36267}, {-3.52875, 4.18555, -2.36564}
			};
		};

		class Land_Barracks_01_dilapidated_F
		{
			table = "Military";
			positions[] = {{-1.69293, -3.85742, 0.535027}, {-12.5613, 0.0180664, 0.604081}, {-12.6066, -1.79248, 0.604081}, {-7.84314, -3.68848, 0.604081}, {-8.02209, 3.86475, 0.604081}, {-12.5088, 1.94385, 0.604081}, {0.59137, 3.8667, 0.604081}, {-5.06348, 2.19873, 0.604081}, {6.8587, -3.54736, 0.604081}, {3.14551, -3.66699, 0.604081}, {6.78778, 3.72412, 0.604081}, {3.31708, 2.07324, 0.604081}, {13.371, 2.21875, 0.604082}, {9.73486, 3.48438, 0.604081}, {15.7028, 5.6084, 3.85243}, {-13.0049, 5.65723, 3.85243}, {-12.5955, 3.93408, 3.93806}, {-7.83679, 3.90479, 3.93806}, {-12.5541, 0.0922852, 3.93806}, {-12.6505, -1.86865, 3.93806}, {-7.92334, -3.67725, 3.93806}, {-2.42621, -4.33789, 3.93752}, {-5.72375, -4.66895, 3.93806}, {0.371094, 3.86523, 3.93806}, {-5.55957, 1.91016, 3.93806}, {9.55927, -3.80859, 3.93806}, {13.5131, -3.75439, 3.93806}, {13.6052, 3.84033, 3.93806}, {9.46393, 1.98193, 3.93806}, {2.94727, 1.94189, 3.93806}, {7.06958, 3.84863, 3.93806}, {3.01563, -3.69629, 3.93806}, {7.1875, -3.72266, 3.93806}, {9.89056, -3.63623, 0.604081}, {13.7531, -3.41455, 0.604081}
			};
		};

		class Land_Barracks_01_grey_F
		{
			table = "Military";
			positions[] = {{-1.69293, -3.85742, 0.535027}, {-12.5613, 0.0180664, 0.604081}, {-12.6066, -1.79248, 0.604081}, {-7.84314, -3.68848, 0.604081}, {-8.02209, 3.86475, 0.604081}, {-12.5088, 1.94385, 0.604081}, {0.59137, 3.8667, 0.604081}, {-5.06348, 2.19873, 0.604081}, {6.8587, -3.54736, 0.604081}, {3.14551, -3.66699, 0.604081}, {6.78778, 3.72412, 0.604081}, {3.31708, 2.07324, 0.604081}, {13.371, 2.21875, 0.604082}, {9.73486, 3.48438, 0.604081}, {15.7028, 5.6084, 3.85243}, {-13.0049, 5.65723, 3.85243}, {-12.5955, 3.93408, 3.93806}, {-7.83679, 3.90479, 3.93806}, {-12.5541, 0.0922852, 3.93806}, {-12.6505, -1.86865, 3.93806}, {-7.92334, -3.67725, 3.93806}, {-2.42621, -4.33789, 3.93752}, {-5.72375, -4.66895, 3.93806}, {0.371094, 3.86523, 3.93806}, {-5.55957, 1.91016, 3.93806}, {9.55927, -3.80859, 3.93806}, {13.5131, -3.75439, 3.93806}, {13.6052, 3.84033, 3.93806}, {9.46393, 1.98193, 3.93806}, {2.94727, 1.94189, 3.93806}, {7.06958, 3.84863, 3.93806}, {3.01563, -3.69629, 3.93806}, {7.1875, -3.72266, 3.93806}, {9.89056, -3.63623, 0.604081}, {13.7531, -3.41455, 0.604081}
			};
		};

		class Land_Barracks_01_camo_F
		{
			table = "Military";
			positions[] = {{-1.69293, -3.85742, 0.535027}, {-12.5613, 0.0180664, 0.604081}, {-12.6066, -1.79248, 0.604081}, {-7.84314, -3.68848, 0.604081}, {-8.02209, 3.86475, 0.604081}, {-12.5088, 1.94385, 0.604081}, {0.59137, 3.8667, 0.604081}, {-5.06348, 2.19873, 0.604081}, {6.8587, -3.54736, 0.604081}, {3.14551, -3.66699, 0.604081}, {6.78778, 3.72412, 0.604081}, {3.31708, 2.07324, 0.604081}, {13.371, 2.21875, 0.604082}, {9.73486, 3.48438, 0.604081}, {15.7028, 5.6084, 3.85243}, {-13.0049, 5.65723, 3.85243}, {-12.5955, 3.93408, 3.93806}, {-7.83679, 3.90479, 3.93806}, {-12.5541, 0.0922852, 3.93806}, {-12.6505, -1.86865, 3.93806}, {-7.92334, -3.67725, 3.93806}, {-2.42621, -4.33789, 3.93752}, {-5.72375, -4.66895, 3.93806}, {0.371094, 3.86523, 3.93806}, {-5.55957, 1.91016, 3.93806}, {9.55927, -3.80859, 3.93806}, {13.5131, -3.75439, 3.93806}, {13.6052, 3.84033, 3.93806}, {9.46393, 1.98193, 3.93806}, {2.94727, 1.94189, 3.93806}, {7.06958, 3.84863, 3.93806}, {3.01563, -3.69629, 3.93806}, {7.1875, -3.72266, 3.93806}, {9.89056, -3.63623, 0.604081}, {13.7531, -3.41455, 0.604081}
			};
		};

		class Land_BagBunker_01_large_green_F
		{
			table = "Military";
			positions[] = {{-3.14728, -3.43408, -0.839155}, {-1.14655, 1.00586, -0.836318}, {3.11304, -3.87305, -0.834461}, {0.91864, 0.737793, -0.831506}, {-1.09125, 3.10645, -0.846669}
			};
		};

		class Land_HBarrier_01_tower_green_F
		{
			table = "Military";
			positions[] = {{0.400085, 1.87744, 0.482887}, {-0.725647, -2.3208, 0.482884}, {-0.749512, 1.93896, -2.29711}, {-0.959229, -2.50342, -2.29711}
			};
		};

		class Land_HBarrier_01_big_tower_green_F
		{
			table = "Military";
			positions[] = {{-0.0388794, -2.06543, -0.0721803}, {-0.5849, 1.0791, -0.0721803}
			};
		};

		class Land_Cargo_House_V4_F
		{
			table = "Military";
			positions[] = {{1.93024, 3.46777, -0.134219}, {-1.99597, 0.757813, -0.270255}
			};
		};

		class Land_Cargo_HQ_V4_F
		{
			table = "Military";
			positions[] = {{-2.59113, -4.27148, -0.748882}, {-2.59424, 2.74121, -0.748883}, {6.12561, -1.43262, -0.748886}, {4.92139, 3.66553, -0.748884}, {2.82428, -4.5127, -0.673725}, {6.75214, 0.595215, -3.27373}, {3.83301, -4.36865, -3.27373}, {-1.38422, -4.49805, -3.27373}, {-1.2486, 2.95898, -3.27373}, {3.09406, 3.60059, -3.27373}
			};
		};

		class Land_Cargo_Patrol_V4_F
		{
			table = "Military";
			positions[] = {{1.79944, 0.629883, -2.9121}, {1.91803, -1.25488, -0.560959}, {-1.87482, 1.36816, -0.764956}, {-1.87756, -1.37646, -0.560959}
			};
		};

		class Land_Cargo_Tower_V4_F
		{
			table = "Military";
			positions[] = {{-3.17126, 4.56006, 5.00328}, {4.43848, 3.68555, 5.00327}, {4.6236, -2.42139, 5.00327}, {-3.37885, -5.12842, 4.90572}, {-3.29187, -1.0376, 5.00328}, {0.343079, 1.63135, 5.07844}, {-5.09668, 4.59131, 2.47844}, {-4.39246, -5.45313, 2.61447}, {-1.25903, -0.762695, 2.47844}, {6.07666, 4.14551, 2.6936}, {4.90717, -1.02637, 2.47844}, {1.21716, -0.616699, -0.121563}, {-4.05151, -3.43164, -0.121563}, {-3.77576, 4.30664, 0.108913}, {4.41241, 4.19043, -0.121563}, {-3.32153, 1.43799, -4.29724}, {-2.58942, 3.13281, -4.29724}, {1.42841, 2.67432, -8.24476}
			};
		};

		class Land_PillboxBunker_01_big_F
		{
			table = "Military";
			positions[] = {{-2.7843, 4.40234, -0.79799}, {0.65155, 4.40039, -0.79799}, {3.16467, -0.414063, -0.79799}, {-0.919983, 1.5918, 1.43985}
			};
		};

		class Land_PillboxBunker_01_hex_F
		{
			table = "Military";
			positions[] = {{-1.9942, -0.828613, -0.959151}, {-2.32397, 1.28271, -0.97937}
			};
		};

		class Land_PillboxBunker_01_rectangle_F
		{
			table = "Military";
			positions[] = {{-0.931946, 1.00244, -0.390276}, {-1.341, -0.984375, 0.111176}
			};
		};

		class Land_Cathedral_01_F
		{
			table = "Civilian";
			positions[] = {{12.4813, -13.7446, -10.1117}, {11.6747, -9.44678, -11.2517}, {12.2565, -17.9878, -11.2227}, {3.78693, -14.6914, -12.7812}, {-3.62018, -15.4463, -12.7812}, {-12.1761, -18.0459, -11.2227}, {-12.5489, -13.8569, -10.1117}, {-11.6001, -9.25293, -11.2517}, {-7.80066, -13.1929, -8.7991}, {2.38251, -13.2998, -7.80105}, {-3.08685, -14.3218, -7.80105}, {7.91278, -13.8066, -8.7991}, {8.16644, -0.892578, -9.3812}, {-8.27832, -1.06299, -9.3812}
			};
		};

		class Land_Church_01_F
		{
			table = "Civilian";
			positions[] = {{8.10126, -0.416504, -9.91359}, {8.00543, 7.06006, -9.86603}, {-7.94092, 1.38867, -9.84217}, {-7.92584, 8.74805, -9.84217}
			};
		};

		class Land_Church_02_F
		{
			table = "Civilian";
			positions[] = {{2.1095, -17.0308, -3.31493}, {-1.98883, -17.0156, -3.31492}
			};
		};

		class Land_Mausoleum_01_F
		{
			table = "Civilian";
			positions[] = {{1.35419, -1.64746, -1.89905}, {-1.00244, 1.26172, -1.88787}
			};
		};

		class Land_GuardHouse_01_F
		{
			table = "Civilian";
			positions[] = {{4.39807, 1.53076, -0.987735}, {-1.53021, 2.07129, -0.987734}, {3.81836, -4.1709, -1.00742}, {-1.42365, -0.541016, -1.00742}, {-1.45483, -4.01563, -1.00742}
			};
		};

		class Land_FuelStation_01_shop_F
		{
			table = "Commercial";
			positions[] = {{1.34039, -0.319824, -2.01301}, {-4.40387, -2.54102, -2.01301}, {-4.43878, -0.146484, -2.01301}, {-4.48163, 4.30127, -2.01301}, {1.37292, 1.87549, -2.01301}
			};
		};

		class Land_FuelStation_02_workshop_F
		{
			table = "Mechanical";
			positions[] = {{-4.65692, 7.44629, -1.2575}, {-2.69397, -0.881348, -1.2575}, {3.96014, -0.874023, -1.2575}, {1.59766, 7.14111, -1.2575}, {4.02576, 3.44238, -1.2575}
			};
		};

		class Land_Hotel_01_F
		{
			table = "Commercial";
			positions[] = {{3.96973, -4.05664, -5.28721}, {3.93524, 4.78174, -5.28721}, {0.112183, 2.06885, -5.28721}, {-5.19159, 5.24316, -5.28721}, {-5.53912, -4.07227, -5.28721}, {-8.18829, 0.800781, -1.56211}, {-7.80768, 7.61572, -1.56212}, {6.01831, 7.55127, -1.56212}, {5.84296, -5.86084, -1.56211}, {-7.78247, -6.09717, -1.56211}, {-3.86163, 0.643066, -1.56212}, {-0.725769, 4.19727, -1.56212}, {2.85748, 0.849121, -1.56212}, {-1.03076, -3.27588, -1.56211}, {1.3125, 0.710449, 1.68788}, {-0.789001, 4.49854, 1.68789}, {-4.82312, 0.928711, 1.68788}, {5.86011, 7.3125, 4.51359}, {6.05499, 7.36133, 1.68789}, {-2.10968, 7.91797, 1.68789}, {-7.46893, 7.12549, 1.68789}, {6.11334, -6.15576, 1.68788}, {-7.67957, -5.83838, 1.68788}, {-7.62677, 1.54541, 1.68788}, {-7.32611, 7.44043, 4.51359}, {-7.36676, -5.59521, 4.51364}, {5.93842, -5.94629, 4.51364}, {-0.767456, 4.4707, 4.51355}, {-5.61255, -1.47998, 4.51355}, {3.86053, -4.14502, 4.51363}, {1.37054, -1.40869, 4.51358}
			};
		};

		class Land_Hotel_02_F
		{
			table = "Commercial";
			positions[] = {{6.9483, -0.910156, -3.38828}, {3.59357, 3.63965, -3.38828}, {-7.33313, -1.19873, -3.38828}, {-2.39691, 1.2168, -3.38828}, {-1.81409, 12.2061, -3.38828}, {-2.21124, -9.90088, -3.38828}, {-7.5498, 1.07813, 0.107927}, {0.997925, 2.77393, 0.107927}, {4.06665, -0.816406, 0.226008}
			};
		};

		class Land_Supermarket_01_F
		{
			table = "Commercial";
			positions[] = {{6.30194, -11.0469, -1.53671}, {-4.51752, -11.3296, -1.53671}, {0.467468, -10.2432, -1.53671}, {-4.89508, -7.5459, -1.48064}, {-0.474976, -0.0825195, -1.48064}, {-3.8714, 1.80322, -1.48064}, {4.35724, -2.51172, -1.48064}, {7.13202, 2.08887, -1.48064}, {6.94672, 7.76709, -1.48064}, {3.10266, 7.8999, -1.48064}, {-4.03607, 11.3711, -1.48064}, {-3.44031, 8.20215, -1.48064}, {4.05859, 11.8423, -1.48064}
			};
		};

		class Land_Warehouse_02_F
		{
			table = "Industrial";
			positions[] = {{-2.4668, -12.4736, -3.92001}, {7.32794, -12.4351, -3.92001}, {14.8786, -12.542, -3.92001}
			};
		};

		class Land_StorageTank_01_small_F
		{
			table = "Industrial";
			positions[] = {{-16.3601, 0.801758, -1.05007}, {0.522583, 1.60889, 4.88674}, {0.0722656, -0.759766, 4.88674}, {-1.02252, 1.0459, 4.88673}
			};
		};

		class Land_StorageTank_01_large_F
		{
			table = "Industrial";
			positions[] = {{1.97491, 4.17188, 0.684248}, {8.29785, -9.72461, 0.684288}, {-11.0208, -3.45361, 0.684258}, {1.8186, 17.9902, 1.2294}, {19.0656, 0.043457, 2.1993}, {-6.35602, -16.9229, 1.24216}, {15.979, -9.30664, 1.22207}
			};
		};

		class Land_SM_01_reservoirTower_F
		{
			table = "Industrial";
			positions[] = {{0.744629, 2.54785, -1.95139}, {-0.625549, -2.69141, -1.95139}, {-2.89954, 1.08691, -1.95139}
			};
		};

		class Land_WaterTower_01_F
		{
			table = "Industrial";
			positions[] = {{-0.0684204, -0.130371, 3.76693}
			};
		};

		class Land_House_Small_02_F
		{
			table = "Civilian";
			positions[] = {{-3.23962, -4.72266, -0.71564}, {-0.786072, -4.95947, -0.71564}, {-0.187805, 1.87402, -0.71564}, {-3.37006, 4.82764, -0.71564}, {-3.28796, 1.29834, -0.71564}
			};
		};

		class Land_House_Big_02_F
		{
			table = "Civilian";
			positions[] = {{7.52789, -7.47266, -1.44289}, {7.94958, 7.4585, -1.44289}, {-4.53009, 8.71436, -1.44289}, {-2.10052, 5.26074, -1.44289}, {0.351624, 1.78467, -1.44289}, {4.65405, 3.19971, -1.44289}, {-9.56982, 3.0293, -1.44289}, {-5.66528, -0.0429688, -1.44289}
			};
		};

		class Land_House_Small_03_F
		{
			table = "Civilian";
			positions[] = {{1.85565, -1.06055, -1.32402}, {-1.10022, 4.04395, -1.32402}, {-3.39624, 4.35059, -1.32402}, {-5.51508, -1.06006, -1.32402}, {-3.18793, -1.27197, -1.32402}
			};
		};

		class Land_House_Small_06_F
		{
			table = "Civilian";
			positions[] = {{-3.56342, 1.42627, -1.00212}, {-3.30609, -4.31396, -1.00212}, {1.72375, -4.1626, -1.00212}, {-3.36035, 4.01172, -1.00212}
			};
		};

		class Land_House_Big_01_F
		{
			table = "Civilian";
			positions[] = {{-0.168579, -2.8916, -1.01287}, {-6.79626, -3.13574, -1.01287}, {6.28888, -2.93799, -1.01287}, {6.88696, 4.87793, -1.01287}, {0.589661, 4.896, -1.01287}, {0.561768, -0.488281, -1.01287}, {6.22552, -0.22168, -1.01287}
			};
		};

		class Land_Shed_07_F
		{
			table = "Industrial";
			positions[] = {{3.49219, -1.09473, -1.39405}, {3.34741, 1.29395, -1.39405}, {-3.42761, -0.976074, -1.39405}
			};
		};

		class Land_Shed_05_F
		{
			table = "Industrial";
			positions[] = {{-2.00177, 0.643066, -0.89049}, {1.9892, -1.92578, -0.89049}, {-2.02496, -2.06836, -0.89049}, {1.84515, 0.745605, -0.89049}
			};
		};

		class Land_Shed_02_F
		{
			table = "Industrial";
			positions[] = {{-1.11359, 1.68359, -0.847519}, {0.985229, -0.0498047, -0.844183}
			};
		};

		class Land_Shed_03_F
		{
			table = "Industrial";
			positions[] = {{-0.726868, -0.477051, -0.707936}, {1.9704, -0.0673828, -0.707935}
			};
		};

		class Land_Slum_02_F
		{
			table = "Civilian";
			positions[] = {{3.38623, -0.645996, 0.183215}, {-1.6817, -3.64404, 0.183216}, {2.09442, -3.65576, 0.183216}, {-1.79016, 3.66748, 0.183216}, {1.58813, 2.20703, 0.183216}
			};
		};

		class Land_Slum_01_F
		{
			table = "Civilian";
			positions[] = {{-2.13098, 1.81494, 0.641667}, {4.75482, -1.82471, 0.668514}, {-0.47876, 1.56104, 0.668515}, {4.61261, 1.65479, 0.668515}
			};
		};

		class Land_GarageShelter_01_F
		{
			table = "Mechanical";
			positions[] = {{4.01392, 2.63623, -1.25478}, {0.764343, -1.36768, -1.25478}, {-3.85114, 2.88916, -1.25478}, {-1.22278, -1.68896, -1.25478}
			};
		};

		class Land_Shop_Town_03_F
		{
			table = "Commercial";
			positions[] = {{-0.00872803, -8.08594, -3.36008}, {-5.54944, -8.7085, -3.36202}, {-5.9541, -0.202637, -3.35966}, {-2.71411, -2.58154, -3.35966}, {-0.143982, -0.276855, -3.35966}, {5.16455, -5.21777, -3.35966}, {5.52393, -0.544434, -3.35966}, {-5.91083, 5.50439, -3.35966}, {0.127686, 7.56934, -3.35966}, {2.57611, 2.4585, -3.35966}, {5.67163, 7.2915, -3.35966}
			};
		};

		class Land_Shop_Town_05_F
		{
			table = "Commercial";
			positions[] = {{7.25494, -6.48438, -2.70163}, {-4.45245, -6.21143, -2.70163}, {2.8161, -6.51611, -2.70163}
			};
		};

		class Land_Shop_Town_01_F
		{
			table = "Commercial";
			positions[] = {{3.24677, -6.03857, -3.24511}, {-3.33325, -5.69287, -3.24511}, {-3.68738, 1.44141, -3.24511}, {3.55231, -2.40527, -3.24511}, {-3.48401, -3.26318, -3.24511}, {-3.72571, 4.51416, -3.24511}
			};
		};

		class Land_House_Small_01_F
		{
			table = "Civilian";
			positions[] = {{5.71362, 2.77393, -0.700801}, {1.74152, 2.91113, -0.700801}, {1.97015, -3.09521, -0.700801}, {5.78699, -2.71338, -0.700801}, {-5.24707, 2.52246, -0.700801}, {-0.623718, 2.41797, -0.700801}, {-5.39386, -2.89844, -0.700801}, {-1.83771, -2.96729, -0.700801}
			};
		};

		class Land_Slum_03_F
		{
			table = "Civilian";
			positions[] = {{-5.96301, -3.12549, -0.649454}, {4.46039, -2.96729, -0.649454}, {-6.04901, 0.859863, -0.649454}, {-0.613708, -0.942871, -0.649454}, {-4.32275, 1.02051, -0.649454}, {-4.48254, 6.70654, -0.649455}, {-0.675964, 3.31787, -0.649454}, {1.74304, 2.79688, -0.649454}, {3.23267, 6.64746, -0.649455}, {2.06952, -0.73877, -0.649455}
			};
		};

		class Land_Shop_Town_04_F
		{
			table = "Commercial";
			positions[] = {{-3.46161, -6.2124, -2.43639}, {3.01746, -6.52197, -2.43639}
			};
		};

		class Land_Shop_Town_02_F
		{
			table = "Commercial";
			positions[] = {{-3.1637, -4.87451, -2.14306}, {3.44916, -4.88867, -2.14306}
			};
		};

		class Land_Shed_01_F
		{
			table = "Mechanical";
			positions[] = {{1.75861, 1.10742, -0.914464}, {0.0146484, 1.12256, -0.914464}, {-1.73743, 1.06445, -0.914464}
			};
		};

		class Land_Shed_04_F
		{
			table = "Mechanical";
			positions[] = {{-0.0791626, 0.706543, -0.721425}
			};
		};
	};
};
class CfgVehicleSpawns {
	class Buildings {
		class Land_GarageShelter_01_F {
			locations[] = {{2.60669,0.034668,-1.25005}
			};
			directions[] = {180};
		};
		class Land_House_Big_03_F {
			locations[] = {{6.77026,-3.16113,-3.38936}
			};
			directions[] = {90.9637};
		};
		class Land_House_Small_04_F {
			locations[] = {{-1.33447,-5.72168,-1.05337}
			};
			directions[] = {251.81};
		};
		class Land_House_Small_05_F {
			locations[] = {{-2.72168,-1.87256,-1.23374}
			};
			directions[] = {261.001};
		};
		class Land_School_01_F {
			locations[] = {{0.00146484,-4.24023,-1.57045},{6.99841,-3.93652,-1.57045},{13.7524,-3.68555,-1.61162},{-13.9556,-3.69434,-1.57045}
			};
			directions[] = {124.82,124.82,103.163,258.837};
		};
		class Land_House_Small_06_F {
			locations[] = {{3.64514,3.64111,-1.39313}
			};
			directions[] = {74.936};
		};
		//--- todo: test (removed from list)
		class Land_Shed_06_F {
			locations[] = {{2.33594,-1.5708,-1.215},{0.574951,3.30811,-1.215}
			};
			directions[] = {240.455,305.884};
		};
		class Land_Shed_07_F {
			locations[] = {{3.24463,0.289063,-1.19334}
			};
			directions[] = {272.99};
		};
		class Land_Addon_03_F {
			locations[] = {{-2.08667,2.85498,-1.37288}
			};
			directions[] = {0};
		};
		class Land_Addon_04_F {
			locations[] = {{2.33545,5.64941,-3.09596}
			};
			directions[] = {81.9683};
		};
		class Land_FuelStation_01_workshop_F {
			locations[] = {{-3.58813,-1.25781,-2.53379},{2.52588,-1.18896,-2.53379}
			};
			directions[] = {143.066,180.008};
		};
		class Land_FuelStation_01_roof_F {
			locations[] = {{0.929199,-4.22705,-2.96874},{0.552246,4.25635,-2.8793}
			};
			directions[] = {88.727,272.412};
		};
		class Land_FuelStation_02_workshop_F {
			locations[] = {{-2.76379,2.68311,-1.36458}
			};
			directions[] = {178.493};
		};
		//--- todo: test removed
		class Land_MetalShelter_02_F {
			locations[] = {{-3.0094,6.31982,-2.53849},{-7.5896,4.13184,-2.58269}
			};
			directions[] = {359.991,178.967};
		};
		class Land_FuelStation_02_roof_F {
			locations[] = {{-6.66699,2.45654,-2.40688},{-5.28308,6.86328,-2.44445}
			};
			directions[] = {269.099,91.9652};
		};
		//--- TODO: test removed
		class Land_MetalShelter_01_F {
			locations[] = {{4.56799,-5.29004,-1.56836},{4.73572,-2.22607,-1.56836},{4.77979,1.12451,-1.56836},{4.92883,4.04102,-1.56836}
			};
			directions[] = {87.6316,48.0039,113.241,270.58};
		};
		class Land_Hotel_01_F {
			locations[] = {{-7.40234,-1.85645,-5.50127}
			};
			directions[] = {0};
		};
		class Land_MultistoryBuilding_01_F {
			locations[] = {{13.4235,-11.8364,-20.8827},{12.6835,2.3208,-20.9196},{12.5496,-3.13721,-20.9196},{12.3575,-7.44141,-20.9196}
			};
			directions[] = {90.781,129.967,90.733,90.733};
		};
		class Land_MultistoryBuilding_03_F {
			locations[] = {{-8.17847,1.75049,-25.8977},{-9.08691,1.72754,-25.8977}
			};
			directions[] = {352.662,352.662};
		};
		class Land_Shop_City_03_F {
			locations[] = {{5.67883,-2.56006,-5.107},{4.36108,-0.0917969,-5.10371},{0.976074,5.04053,-5.10353},{1.17896,-5.74658,-5.10401}
			};
			directions[] = {235.877,182.882,176.143,182.882};
		};
		class Land_Shop_City_02_F {
			locations[] = {{1.24805,-10.1792,-4.38337},{2.22461,-10.3315,-4.42472},{3.02271,-10.3169,-4.46243},{3.79883,-10.2437,-4.41579}
			};
			directions[] = {105.568,110.874,109.866,113.647};
		};
		//--- todo: test fix
		class Land_WoodenShelter_01_F {
			locations[] = {{-0.422852,0.0537109,-1.11249}
			};
			directions[] = {176.774};
		};
		class Land_Shop_City_01_F {
			locations[] = {{-2.70569,-3.08887,-5.17591}
			};
			directions[] = {89.0095};
		};
		class Land_Shop_City_06_F {
			locations[] = {{-6.39063,0.680664,-4.38325}
			};
			directions[] = {160.655};
		};
		class Land_MultistoryBuilding_04_F {
			locations[] = {{-13.0975,6.24316,-36.7282},{-13.3356,-0.482422,-36.7282}
			};
			directions[] = {298.955,298.955};
		};
		class Land_Shop_City_05_F {
			locations[] = {{-9.073,-36.6758,-7.46471},{1.22034,-11.5459,-7.46157}
			};
			directions[] = {252.344,183.441};
		};
		class Land_Shop_City_07_F {
			locations[] = {{0.416138,2.33691,-3.30909},{0.440308,5.61621,-3.30862}
			};
			directions[] = {1.38711,1.38811};
		};
		class Land_Warehouse_03_F {
			locations[] = {{8.05029,-0.370117,-2.40732}
			};
			directions[] = {359.972};
		};
		class Land_Warehouse_02_F {
			locations[] = {{0.86377,-17.8154,-5.21577},{11.4291,-17.7988,-5.21577}
			};
			directions[] = {180.796,180.796};
		};
		class Land_WarehouseShelter_01_F {
			locations[] = {{3.39453,-4.16992,-2.85872},{-3.43152,-4.43555,-2.85872}
			};
			directions[] = {181.698,360};
		};
		class Land_SCF_01_crystallizer_F {
			locations[] = {{-5.53345,2.90527,-9.01621},{5.87866,2.62793,-9.01621}
			};
			directions[] = {269.076,90.0837};
		};
		class Land_SCF_01_shed_F {
			locations[] = {{6.4209,-14.1689,-7.21736},{-6.74841,9.47168,-7.21736},{-1.7666,-0.806641,-7.22136},{0.930054,-2.94141,-7.22136}
			};
			directions[] = {0.012765,181.84,26.8011,206.934};
		};
		class Land_SM_01_shed_F {
			locations[] = {{10.884,6.22168,-1.46795},{-0.851929,5.87891,-1.46795}
			};
			directions[] = {268.495,268.495};
		};
		class Land_SM_01_shed_unfinished_F {
			locations[] = {{8.71277,2.2627,-1.51584}
			};
			directions[] = {285.81};
		};
		class Land_SM_01_shelter_wide_F {
			locations[] = {{5.31702,-8.24023,-3.57053},{-5.41321,4.35547,-3.57053}
			};
			directions[] = {1.90951,181.259};
		};
		class Land_SM_01_shelter_narrow_F {
			locations[] = {{0.432373,-7.63574,-2.1163},{0.480225,0.078125,-2.1163}
			};
			directions[] = {104.319,359.576};
		};
		class Land_Airport_01_terminal_F {
			locations[] = {{-1.7406,6.71484,-4.2641},{1.72998,7.27832,-4.26409},{5.48486,8.80859,-4.24886}
			};
			directions[] = {0.802014,180.148,275.272};
		};
		class Land_Airport_01_hangar_F {
			locations[] = {{8.36755,7.4707,-2.70845},{-7.8866,6.66309,-2.70776}
			};
			directions[] = {194.775,160.588};
		};
		class Land_Airport_02_hangar_right_F {
			locations[] = {{-3.37866,-5.04492,-7.71338}
			};
			directions[] = {186.313};
		};
		class Land_Airport_02_hangar_left_F {
			locations[] = {{7.65942,-8.44434,-7.72021}
			};
			directions[] = {180.777};
		};
		class Land_Airport_02_terminal_F {
			locations[] = {{-2.01501,9.99609,-1.49814}
			};
			directions[] = {300.168};
		};
		class Land_Cargo_Tower_V4_F {
			locations[] = {{3.18994,0.212891,-12.8885}
			};
			directions[] = {251.457};
		};
		class Land_PierWooden_01_ladder_F {
			locations[] = {{-0.116943,5.49609,17.7449}
			};
			directions[] = {0};
		};
		class Land_PierWooden_01_dock_F {
			locations[] = {{-0.219727,1.1084,16.9505}
			};
			directions[] = {0};
		};
		class Land_PierWooden_02_ladder_F {
			locations[] = {{0.832275,4.97949,18.4322}
			};
			directions[] = {65.557};
		};
		class Land_PierWooden_02_hut_F {
			locations[] = {{-7.90356,-1.03809,17.3928}
			};
			directions[] = {320.569};
		};
		class Land_PierWooden_03_F {
			locations[] = {{-0.210693,13.5029,18.7532}
			};
			directions[] = {322.913};
		};
	};
	class Vehicles {
		//--- zamaks
		class C_Truck_02_box_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_SM_01_shelter_wide_F","Land_SCF_01_shed_F","Land_SCF_01_crystallizer_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F"};
		};
		class C_Truck_02_covered_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_SM_01_shelter_wide_F","Land_SM_01_shed_unfinished_F","Land_SM_01_shed_F","Land_SCF_01_shed_F","Land_SCF_01_crystallizer_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F","Land_i_Shed_Ind_F"};
		};
		class C_Truck_02_transport_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_SM_01_shelter_wide_F","Land_SM_01_shed_unfinished_F","Land_SM_01_shed_F","Land_SCF_01_shed_F","Land_SCF_01_crystallizer_F","Land_WarehouseShelter_01_F","Land_Warehouse_02_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F","Land_i_Shed_Ind_F"};
		};
		class C_Truck_02_fuel_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_SM_01_shelter_wide_F","Land_SCF_01_shed_F","Land_SCF_01_crystallizer_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F","Land_i_Shed_Ind_F"};
		};
		//--- industrial
		class C_Van_01_box_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_MultistoryBuilding_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F"};
		};
		class C_Van_01_transport_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_WarehouseShelter_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F"};
		};
		class C_Van_01_fuel_F {
			buildings[] = {"Land_SM_01_shelter_narrow_F","Land_FuelStation_02_roof_F","Land_FuelStation_01_roof_F"};
		};

		//--- military
		class B_LSV_01_unarmed_F {
			buildings[] = {"Land_Cargo_Tower_V4_F"};
		};

		//--- civ
		class C_Offroad_02_unarmed_F { //--- jeep
			buildings[] = {"Land_Airport_01_terminal_F","Land_MultistoryBuilding_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_02_workshop_F","Land_FuelStation_01_roof_F","Land_FuelStation_01_workshop_F","Land_House_Big_03_F","Land_GarageShelter_01_F"};
		};
		class C_SUV_01_F {
			buildings[] = {"Land_Airport_01_terminal_F","Land_MultistoryBuilding_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_02_workshop_F","Land_FuelStation_01_roof_F","Land_FuelStation_01_workshop_F","Land_House_Big_03_F","Land_GarageShelter_01_F"};
		};
		class C_Hatchback_01_F {
			buildings[] = {"Land_Airport_01_terminal_F","Land_MultistoryBuilding_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_02_workshop_F","Land_FuelStation_01_roof_F","Land_FuelStation_01_workshop_F","Land_House_Big_03_F","Land_GarageShelter_01_F"};
		};
		class C_Offroad_01_F {
			buildings[] = {"Land_Airport_01_terminal_F","Land_SM_01_shelter_narrow_F","Land_MultistoryBuilding_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_02_workshop_F","Land_FuelStation_01_roof_F","Land_FuelStation_01_workshop_F","Land_House_Big_03_F","Land_GarageShelter_01_F"};
		};
		class C_Hatchback_01_sport_F {
			buildings[] = {"Land_Airport_01_terminal_F","Land_MultistoryBuilding_01_F","Land_FuelStation_02_roof_F","Land_FuelStation_02_workshop_F","Land_FuelStation_01_roof_F","Land_FuelStation_01_workshop_F","Land_House_Big_03_F","Land_GarageShelter_01_F"};
		};
		//--- quads
		class C_Quadbike_01_F {
			buildings[] = {"Land_Shed_07_F"};
		};

		//--- bikes
		class DSR_bike_F {
			buildings[] = {"Land_Airport_02_terminal_F","Land_Warehouse_03_F","Land_Shop_City_07_F","Land_Shop_City_05_F","Land_MultistoryBuilding_04_F","Land_Shop_City_06_F","Land_Shop_City_01_F","Land_Shop_City_02_F","Land_Shop_City_03_F","Land_MultistoryBuilding_03_F","Land_Hotel_01_F","Land_Addon_04_F","Land_Addon_03_F","Land_House_Small_04_F","Land_House_Small_05_F","Land_School_01_F","Land_House_Small_06_F"};
		};

		//--- plans
		class C_Plane_Civil_01_F {
			buildings[] = {"Land_Airport_02_hangar_left_F","Land_Airport_02_hangar_right_F","Land_Airport_01_hangar_F"};
		};
		class C_Plane_Civil_01_racing_F {
			buildings[] = {"Land_Airport_02_hangar_left_F","Land_Airport_02_hangar_right_F","Land_Airport_01_hangar_F"};
		};

		//--- jelli's
		class C_Heli_Light_01_civil_F {
			buildings[] = {};
		};
		class UH1H {
			buildings[] = {};
		};

	};
};

class CfgBuildables {
    class Type1Houses {
		condition = "true"; //--- a check to see if the person has knowledge to build this type
		preview = "\SM_Zombz\Survivors_icon.paa"; //--- preview icon for index
		name = "Type 1 Houses"; //--- name of this buidlable group
		class Buildables {
			class HouseLvl1 {
				parts[] = {
					{"dsr_item_lumber",30},
					{"dsr_item_plywood",7},
					{"dsr_item_logs",15}
				};
				name = "Small Shack";
				model = "DSR_objects_House_lv1";
				crateObject = "dsr_objects_house_lv1_preview";
				description = "The small shack is small... and a shack... a good starting house for losers.";
				preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
				condition = "true";
			};
			class HouseLvl2 {
				parts[] = {
					{"dsr_item_lumber",60},
					{"dsr_item_plywood",14},
					{"dsr_item_logs",45}
				};
				name = "Large Shack";
				model = "DSR_objects_House_lv2";
				crateObject = "dsr_objects_house_lv2_preview";
				description = "This is for testing, it should not be buildable.";
				preview = "\dsr_ui\Assets\houseLvl1Preview_ca.paa";
				condition = "false";
			};
		};
	};
	class Stockade {
		condition = "true"; 
		preview = "\SM_Zombz\Survivors_icon.paa";  
		name = "Stockade Items";  
		class Buildables {
			class StockadeWall {
				parts[] = {
					{"dsr_item_lumber",23},
					{"dsr_item_hardware",4}
				};
				name = "Base Stockade Wall";
				model = "dsr_objects_stockade_wall";
				description = "Basic stockade wall piece";
				crateObject = "dsr_objects_stockade_wall_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
			class StockadeRampart {
				parts[] = {
					{"dsr_item_lumber",45},
					{"dsr_item_hardware",6}
				};
				name = "Stockade Wall Rampart Full";
				model = "dsr_objects_stockade_rampart";
				description = "Stockade Wall with Rampart and Ramp";
				crateObject = "dsr_objects_stockade_rampart_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
			class StockadeRampart_2 {
				parts[] = {
					{"dsr_item_lumber",38},
					{"dsr_item_hardware",5}
				};
				name = "Stockade Wall Rampart no ramp";
				model = "dsr_objects_stockade_rampart_2";
				description = "Stockade Wall with Rampart";
				crateObject = "dsr_objects_stockade_rampart_2_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
			class StockadeGate {
				parts[] = {
					{"dsr_item_lumber",30},
					{"dsr_item_hardware",4},
					{"dsr_item_scrapmetal",2},
					{"dsr_item_logs",2}
				};
				name = "Stockade Wall Rampart no ramp";
				model = "dsr_objects_stockade_rampart_2";
				description = "Stockade Wall with Rampart";
				crateObject = "dsr_objects_stockade_rampart_2_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
			class StockadeTower {
				parts[] = {
					{"dsr_item_lumber",40},
					{"dsr_item_hardware",10},
					{"dsr_item_scrapmetal",4},
					{"dsr_item_logs",10}
				};
				name = "Stockade Guard Tower";
				model = "dsr_objects_stockade_tower";
				description = "Stockade Guard Tower";
				crateObject = "dsr_objects_stockade_tower_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
		};
	};
	class Misc {
		condition = "true"; 
		preview = "\SM_Zombz\Survivors_icon.paa";  
		name = "Miscellaneous";  
		class Buildables {
			class Pallets {
				parts[] = {
					{"dsr_item_lumber",10}
				};
				name = "Pallet";
				model = "Land_Pallets_stack_F";
				description = "A stack of pallets";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				
				crateObject = "DSR_objects_Storage_Small";
				
				condition = "true";
			};
			class Workbench {
				parts[] = {
					{"dsr_item_lumber",10},
					{"dsr_item_hardware",1},
					{"dsr_item_scrapmetal",1}
				};
				name = "Workbench";
				model = "dsr_objects_workbench";
				description = "Crafting Workbench";
				crateObject = "dsr_objects_workbench_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
			class WaterCatchment {
				parts[] = {
					{"dsr_item_logs",6},
					{"dsr_item_ducttape",1},
					{"dsr_item_plasticdrum",1}
				};
				name = "Water Catch";
				model = "dsr_objects_water_catchment";
				description = "System for catching rain water";
				crateObject = "dsr_objects_water_catchment_preview";
				preview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Pallets_stack_F.jpg";
				condition = "true";
			};
		};
	};
};
class CfgCraftables {
	class CraftableItem {
		parts[] = {
			{"Item",2},
			{"Different Item",1}
		};
		name = "Some Crafted Item";
		item = "DSR_Item_That_Is_Craftable";
		description = "Sick moves";
		condition = "true";
	};
};

