class CfgPatches
{
	class DS_DESOLATION_VEHICLES
	{
		fileName = "desolation_vehicles.pbo";
		requiredAddons[] = {"A3_Data_F","A3_Ui_F","A3_Functions_F","A3_UiFonts_F"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};
class CfgFunctions 
{
	class Desolation_Redux_Functions 
	{
		class bootstrap 
		{
			file = "\DS_desolation_vehicles\bootstrap";
			class preInit 
			{
				preInit = 1;
			};
		};
	};
};
class CfgVehicleTemplates
{
	class DS_Veh_Offroad_Civ_Base
	{
		textureList[] = 
		{
			
		};

		animationList[] =
		{
			"hideLeftDoor",0.25,
			"hideRightDoor",0.10,
			"hideRearDoor",0.4,
			"hideBullbar",0.50,//50% chance the front push bar is missing
			"hideFenders",0.05,
			"hideHeadSupportRear",0.75,
			"hideHeadSupportFront",0.80,
			"hideRollcage",0.10, //10% chance the Rollcage is missing
			"hideSeatsRear",0.05,
			"hideSpareWheel",0.33 //33% chance the Spare is missing :)
		};
	};
};
class DesolationPlayerActions
{
	displayName = "";
	displayNameDefault = "";
	position = "";
	priority = 1.5;
	radius = 3;
	onlyForplayer = 0;
	condition = "";
	statement = "";
	showWindow = false;
};
class Desolation_Vehicle_Actions
{
	class lock_a3: DesolationPlayerActions {
		displayName = "Lock";
		displayNameDefault = "Lock";
		position = "";
		//priority = 1.5;
		//radius = 3;
		//onlyForplayer = 0;
		condition = "((this getVariable['DS_Veh_Locked',2]) isEqualTo 0) && ((this getVariable['DS_Veh_OwnerUID',0]) isEqualTo (getplayerUID player))";//check unlocked
		statement = "this setVariable['DS_Veh_Locked',2];this lock 2";//lock it
	};
	class unlock_a3: DesolationPlayerActions {
		displayName = "Unlock";
		displayNameDefault = "Unlock";
		position = "";
		//priority = 1.5;
		//radius = 3;
		//onlyForplayer = 0;
		condition = "((this getVariable['DS_Veh_Locked',0]) isEqualTo 2) && ((this getVariable['DS_Veh_OwnerUID',0]) isEqualTo (getplayerUID player))";//check locked
		statement = "this setVariable['DS_Veh_Locked',0];this lock 0";//unlock it
	};
	class claim_ownership: DesolationPlayerActions {
		displayName = "Rekey and Claim";
		displayNameDefault = "Rekey and Claim";
		position = "temp";
		priority = 1.5;
		radius = 3;
		onlyForplayer = 0;
		condition = "((this getVariable['DS_Veh_Locked',0]) isEqualTo 0) && ((this getVariable['DS_Veh_OwnerUID',0]) isEqualTo 0)";
		statement = "this call DS_fnc_rekeyVehicleClaim";//"this setVariable['DS_Veh_OwnerUID',(getPlayerUID player)];this lock 0";
	};
	class steal_ownership: DesolationPlayerActions {
		displayName = "Steal and Rekey";
		displayNameDefault = "Steal and Rekey";
		position = "temp";
		priority = 1.5;
		radius = 3;
		onlyForplayer = 0;
		condition = "!((this getVariable['DS_Veh_OwnerUID',0]) isEqualTo 0)  && !((this getVariable['DS_Veh_OwnerUID',0]) isEqualTo (getPlayerUID player))";
		statement = "this setVariable['DS_Veh_OwnerUID',(getPlayerUID player)]";
	};
};
class DefaultEventHandlers;
class AnimationSources;
class CfgVehicles
{
	class DS_Veh_Offroad_Civ_Base
	{
		author = "Desolation Redux Dev Team";
		displayName = "Offroad";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\C_Offroad_01_F.jpg";
		_generalMacro = "C_Offroad_01_F";
		scope = 2;
		crew = "C_man_1";
		side = 3;
		faction = "CIV_F";
		class SimpleObject {
			animate[] = {{"damageHide", 0}, {"damageHideVez", 0}, {"damageHideHlaven", 0}, {"wheel_1_1_destruct", 0}, {"wheel_1_2_destruct", 0}, {"wheel_1_3_destruct", 0}, {"wheel_1_4_destruct", 0}, {"wheel_2_1_destruct", 0}, {"wheel_2_2_destruct", 0}, {"wheel_2_3_destruct", 0}, {"wheel_2_4_destruct", 0}, {"wheel_1_1_destruct_unhide", 0}, {"wheel_1_2_destruct_unhide", 0}, {"wheel_1_3_destruct_unhide", 0}, {"wheel_1_4_destruct_unhide", 0}, {"wheel_2_1_destruct_unhide", 0}, {"wheel_2_2_destruct_unhide", 0}, {"wheel_2_3_destruct_unhide", 0}, {"wheel_2_4_destruct_unhide", 0}, {"wheel_1_3_Damage", 0}, {"wheel_1_4_Damage", 0}, {"wheel_2_3_Damage", 0}, {"wheel_2_4_Damage", 0}, {"wheel_1_3_Damper_Damage_BackAnim", 0}, {"wheel_1_4_Damper_Damage_BackAnim", 0}, {"wheel_2_3_Damper_Damage_BackAnim", 0}, {"wheel_2_4_Damper_Damage_BackAnim", 0}, {"Glass1_destruct", 0}, {"Glass2_destruct", 0}, {"Glass3_destruct", 0}, {"Glass4_destruct", 0}, {"Glass5_destruct", 0}, {"Glass6_destruct", 0}, {"Wheel_1_1", 0.9999}, {"wheel_2_1", 0.9999}, {"wheel_1_2", 0.9999}, {"Wheel_2_2", 0.9999}, {"pedal_thrust", 0}, {"pedal_brake", 1}, {"wheel_1_1_Damage", 0}, {"wheel_1_2_Damage", 0}, {"wheel_2_1_Damage", 0}, {"wheel_2_2_Damage", 0}, {"wheel_1_1_Damper_Damage_BackAnim", 0}, {"wheel_1_2_Damper_Damage_BackAnim", 0}, {"wheel_2_1_Damper_Damage_BackAnim", 0}, {"wheel_2_2_Damper_Damage_BackAnim", 0}, {"Wheel_1_1_Damper", 0.2474}, {"wheel_2_1_Damper", 0.2329}, {"wheel_1_2_Damper", 0.459}, {"Wheel_2_2_Damper", 0.4537}, {"GunnerLF", 1}, {"GunnerLF_pos", 1}, {"GunnerRF", 1}, {"GunnerRF_pos", 1}, {"DamageHideGunner_RF", 0}, {"DamageHideGunner_LF", 0}, {"DrivingWheel", 0}, {"Steering_1_1", 0}, {"Steering_2_1", 0}, {"IndicatorSpeed", 0}, {"DamageHidemph", 0}, {"fuel", 1}, {"DamageHidefuel", 0}, {"IndicatorRPM", 0}, {"DamageHiderpm", 0}, {"prop_02", 0}, {"DamageHidetemp", 0}, {"HideDoor1", 0}, {"DamageHidedoor1", 0}, {"HideDoor2", 0}, {"HideGlass2", 0}, {"DamageHideGlass2", 0}, {"HideDoor3", 1}, {"HidePolice", 1}, {"DamageHidePolice", 0}, {"HideServices", 1}, {"DamageHideServices", 0}, {"DamageUnHideServices", 1}, {"HideBackpacks", 1}, {"DamageHideBackpack_proxy", 0}, {"HideBumper1", 0}, {"DamageHideBumper_1_proxy", 0}, {"DamageUnHideBumper1", 1}, {"HideBumper2", 1}, {"DamageHideBumper_2_proxy", 0}, {"DamageUnHideBumper2", 1}, {"HideConstruction", 1}, {"DamageHideConstruction_proxy", 0}, {"DamageUnHideConstruction", 1}, {"reverse_light", 1}, {"daylights", 0}, {"Beacon1", 231.967}, {"BeaconsStart", 0}, {"BeaconsServicesStart", 0}, {"Beacon2", 231.967}, {"Beacon3", 231.967}, {"Beacon4", 231.967}, {"Beacon5", 231.967}, {"Beacon6", 231.967}, {"BeaconS1", 231.967}, {"BeaconS2", 231.967}, {"BeaconS3", 231.967}, {"BeaconS4", 231.967}};
			hide[] = {"clan", "zasleh"};
			verticalOffset = -0.0415897;
		};
		class EventHandlers {
			init = "if (local (_this select 0)) then {[(_this select 0), """", [], true] call bis_fnc_initVehicle;};";
			// DefaultEventHandlers
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed = "_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
		// Offroad_01_civil_base_F
		features = "Randomization: Yes, 6 skins, disabled by: this setVariable [""BIS_enableRandomization"",false];							<br />Specific skin may be set by: this setVariable [""color"",X]; (the number ranges from 0 to 5)							<br />Camo selections: 2 - the body, wheels and accessories							<br />Script door sources: None							<br />Script animations: HideDoor1, HideDoor2, HideDoor3, HidePolice, HideServices, HideBackpacks, HideBumper1, HideBumper2, HideConstruction							<br />Executed scripts: \A3\soft_F\Offroad_01\scripts\randomize.sqf 							<br />Firing from vehicles: Positions 2 to 5							<br />Slingload: Slingloadable							<br />Cargo proxy indexes: 1 to 5";
		transportSoldier = 1;
		cargoProxyIndexes[] = {1};
		getInProxyOrder[] = {1, 2, 3, 4, 5};
		class Turrets {
			class CargoTurret_01 {
				gunnerAction = "passenger_flatground_3";
				memoryPointsGetInGunner = "pos cargo RR";
				memoryPointsGetInGunnerDir = "pos cargo RR dir";
				gunnerName = "Passenger (Right Seat 2)";
				gunnerCompartments = "Compartment2";
				proxyIndex = 2;
				isPersonTurret = 1;
				canHideGunner = 0;
				allowLauncherIn = 0;
				allowLauncherOut = 0;
				class TurnIn {
					limitsArrayTop[] = {{33.8208, -93.9616}, {40.8906, 66.5705}};
					limitsArrayBottom[] = {{-9.4643, -94.5753}, {-8.3683, -67.6867}, {-9.7173, 43.6372}, {-10.1082, 78.9166}};
				};
				class dynamicViewLimits {
					CargoTurret_02[] = {-65, 75};
				};
				// CargoTurret
				class ViewGunner {
					// ViewCargo
					initAngleX = 5;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					minFov = 0.25;
					maxFov = 1.25;
					initFov = 0.75;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				animationSourceBody = "";
				animationSourceGun = "";
				body = "";
				canEject = 1;
				commanding = 0;
				dontCreateAI = 1;
				gun = "";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				hideWeaponsGunner = 0;
				isCopilot = 0;
				primaryGunner = 0;
				proxyType = "CPCargo";
				startEngine = 0;
				turretFollowFreeLook = 0;
				viewGunnerInExternal = 1;
				disableSoundAttenuation = 1;
				outGunnerMayFire = 1;
				showAsCargo = 1;
				maxElev = 45;
				minElev = -45;
				maxTurn = 95;
				minTurn = -95;
				// NewTurret
				animationSourceHatch = "hatchGunner";
				animationSourceCamElev = "camElev";
				gunnerType = "";
				primaryObserver = 0;
				weapons[] = {};
				magazines[] = {};
				soundServo[] = {"", 0.00316228, 1};
				soundElevation[] = {"", 1, 1};
				particlesPos = "usti hlavne";
				particlesDir = "konec hlavne";
				initElev = 0;
				initTurn = 0;
				minOutElev = -4;
				maxOutElev = 20;
				initOutElev = 0;
				minOutTurn = -60;
				maxOutTurn = 60;
				initOutTurn = 0;
				maxHorizontalRotSpeed = 1.2;
				maxVerticalRotSpeed = 1.2;
				stabilizedInAxes = 3;
				primary = 1;
				hasGunner = 1;
				turretCanSee = 0;
				canUseScanners = 1;
				class TurretSpec {
					showHeadPhones = 0;
				};
				gunnerOpticsModel = "";
				gunnerOpticsColor[] = {0, 0, 0, 1};
				gunnerForceOptics = 1;
				gunnerOpticsShowCursor = 0;
				turrentInfoType = "";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsColor[] = {0, 0, 0, 1};
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsEffect[] = {};
				memoryPointGunnerOutOptics = "";
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				gunnerUsesPilotView = 0;
				castGunnerShadow = 0;
				viewGunnerShadow = 1;
				viewGunnerShadowDiff = 1;
				viewGunnerShadowAmb = 1;
				ejectDeadGunner = 0;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				showHMD = 0;
				lockWhenDriverOut = 0;
				lockWhenVehicleSpeed = -1;
				LODTurnedIn = -1;
				LODTurnedOut = -1;
				memoryPointsGetInGunnerPrecise = "";
				missileBeg = "spice rakety";
				missileEnd = "konec rakety";
				armorLights = 0.4;
				class Reflectors {};
				aggregateReflectors[] = {};
				class GunFire {
					// WeaponFireGun
					access = 0;
					cloudletDuration = 0.2;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 0.2;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 0.5;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletFire";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.01;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 4500;
					deltaT = -3000;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {0.82, 0.95, 0.93, 0};
						};
						class T1 {
							maxT = 200;
							color[] = {0.75, 0.77, 0.9, 0};
						};
						class T2 {
							maxT = 400;
							color[] = {0.56, 0.62, 0.67, 0};
						};
						class T3 {
							maxT = 600;
							color[] = {0.39, 0.46, 0.47, 0};
						};
						class T4 {
							maxT = 800;
							color[] = {0.24, 0.31, 0.31, 0};
						};
						class T5 {
							maxT = 1000;
							color[] = {0.23, 0.31, 0.29, 0};
						};
						class T6 {
							maxT = 1500;
							color[] = {0.21, 0.29, 0.27, 0};
						};
						class T7 {
							maxT = 2000;
							color[] = {0.19, 0.23, 0.21, 0};
						};
						class T8 {
							maxT = 2300;
							color[] = {0.22, 0.19, 0.1, 0};
						};
						class T9 {
							maxT = 2500;
							color[] = {0.35, 0.2, 0.02, 0};
						};
						class T10 {
							maxT = 2600;
							color[] = {0.62, 0.29, 0.03, 0};
						};
						class T11 {
							maxT = 2650;
							color[] = {0.59, 0.35, 0.05, 0};
						};
						class T12 {
							maxT = 2700;
							color[] = {0.75, 0.37, 0.03, 0};
						};
						class T13 {
							maxT = 2750;
							color[] = {0.88, 0.34, 0.03, 0};
						};
						class T14 {
							maxT = 2800;
							color[] = {0.91, 0.5, 0.17, 0};
						};
						class T15 {
							maxT = 2850;
							color[] = {1, 0.6, 0.2, 0};
						};
						class T16 {
							maxT = 2900;
							color[] = {1, 0.71, 0.3, 0};
						};
						class T17 {
							maxT = 2950;
							color[] = {0.98, 0.83, 0.41, 0};
						};
						class T18 {
							maxT = 3000;
							color[] = {0.98, 0.91, 0.54, 0};
						};
						class T19 {
							maxT = 3100;
							color[] = {0.98, 0.99, 0.6, 0};
						};
						class T20 {
							maxT = 3300;
							color[] = {0.96, 0.99, 0.72, 0};
						};
						class T21 {
							maxT = 3600;
							color[] = {1, 0.98, 0.91, 0};
						};
						class T22 {
							maxT = 4200;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class GunClouds {
					// WeaponCloudsGun
					access = 0;
					cloudletDuration = 0.3;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 1;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 1;
					cloudletAccY = 0.4;
					cloudletMinYSpeed = 0.2;
					cloudletMaxYSpeed = 0.8;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.05;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class MGunClouds {
					// WeaponCloudsMGun
					access = 0;
					cloudletGrowUp = 0.05;
					cloudletFadeIn = 0;
					cloudletFadeOut = 0.1;
					cloudletDuration = 0.05;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 0.3;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					timeToLive = 0;
					interval = 0.02;
					size = 0.3;
					sourceSize = 0.02;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				// NewTurret
				class HitPoints {
					class HitTurret {
						armor = 0.8;
						material = 51;
						name = "turret";
						visual = "turret";
						passThrough = 1;
						explosionShielding = 1;
					};
					class HitGun {
						armor = 0.6;
						material = 52;
						name = "gun";
						visual = "gun";
						passThrough = 1;
						explosionShielding = 1;
					};
				};
				class Turrets {};
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.07;
					maxFov = 0.35;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				forceNVG = 0;
				gunnerLeftHandAnimName = "";
				gunnerRightHandAnimName = "";
				gunnerLeftLegAnimName = "";
				gunnerRightLegAnimName = "";
				gunnerDoor = "";
				preciseGetInOut = 0;
				allowTabLock = 1;
				showAllTargets = 0;
				slingLoadOperator = 0;
				playerPosition = 0;
				class TurnOut {
					// TurnIn
					turnOffset = 0;
				};
				gunnerInAction = "ManActTestDriver";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "kulas";
				selectionFireAnim = "zasleh";
				showCrewAim = 0;
			};
			class CargoTurret_02 {
				gunnerAction = "passenger_flatground_2";
				gunnerName = "Passenger (Left Seat 2)";
				memoryPointsGetInGunner = "pos cargo LR";
				memoryPointsGetInGunnerDir = "pos cargo LR dir";
				proxyIndex = 3;
				class TurnIn {
					limitsArrayTop[] = {{37.1488, -71.9003}, {36.4967, 92.2757}};
					limitsArrayBottom[] = {{-22.1832, -70.0989}, {-13.9068, -22.8107}, {-7.1236, 75.6849}, {-7.8564, 102.583}};
				};
				class dynamicViewLimits {
					CargoTurret_01[] = {-75, 65};
				};
				// CargoTurret_01
				gunnerCompartments = "Compartment2";
				isPersonTurret = 1;
				canHideGunner = 0;
				allowLauncherIn = 0;
				allowLauncherOut = 0;
				// CargoTurret
				class ViewGunner {
					// ViewCargo
					initAngleX = 5;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					minFov = 0.25;
					maxFov = 1.25;
					initFov = 0.75;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				animationSourceBody = "";
				animationSourceGun = "";
				body = "";
				canEject = 1;
				commanding = 0;
				dontCreateAI = 1;
				gun = "";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				hideWeaponsGunner = 0;
				isCopilot = 0;
				primaryGunner = 0;
				proxyType = "CPCargo";
				startEngine = 0;
				turretFollowFreeLook = 0;
				viewGunnerInExternal = 1;
				disableSoundAttenuation = 1;
				outGunnerMayFire = 1;
				showAsCargo = 1;
				maxElev = 45;
				minElev = -45;
				maxTurn = 95;
				minTurn = -95;
				// NewTurret
				animationSourceHatch = "hatchGunner";
				animationSourceCamElev = "camElev";
				gunnerType = "";
				primaryObserver = 0;
				weapons[] = {};
				magazines[] = {};
				soundServo[] = {"", 0.00316228, 1};
				soundElevation[] = {"", 1, 1};
				particlesPos = "usti hlavne";
				particlesDir = "konec hlavne";
				initElev = 0;
				initTurn = 0;
				minOutElev = -4;
				maxOutElev = 20;
				initOutElev = 0;
				minOutTurn = -60;
				maxOutTurn = 60;
				initOutTurn = 0;
				maxHorizontalRotSpeed = 1.2;
				maxVerticalRotSpeed = 1.2;
				stabilizedInAxes = 3;
				primary = 1;
				hasGunner = 1;
				turretCanSee = 0;
				canUseScanners = 1;
				class TurretSpec {
					showHeadPhones = 0;
				};
				gunnerOpticsModel = "";
				gunnerOpticsColor[] = {0, 0, 0, 1};
				gunnerForceOptics = 1;
				gunnerOpticsShowCursor = 0;
				turrentInfoType = "";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsColor[] = {0, 0, 0, 1};
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsEffect[] = {};
				memoryPointGunnerOutOptics = "";
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				gunnerUsesPilotView = 0;
				castGunnerShadow = 0;
				viewGunnerShadow = 1;
				viewGunnerShadowDiff = 1;
				viewGunnerShadowAmb = 1;
				ejectDeadGunner = 0;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				showHMD = 0;
				lockWhenDriverOut = 0;
				lockWhenVehicleSpeed = -1;
				LODTurnedIn = -1;
				LODTurnedOut = -1;
				memoryPointsGetInGunnerPrecise = "";
				missileBeg = "spice rakety";
				missileEnd = "konec rakety";
				armorLights = 0.4;
				class Reflectors {};
				aggregateReflectors[] = {};
				class GunFire {
					// WeaponFireGun
					access = 0;
					cloudletDuration = 0.2;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 0.2;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 0.5;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletFire";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.01;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 4500;
					deltaT = -3000;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {0.82, 0.95, 0.93, 0};
						};
						class T1 {
							maxT = 200;
							color[] = {0.75, 0.77, 0.9, 0};
						};
						class T2 {
							maxT = 400;
							color[] = {0.56, 0.62, 0.67, 0};
						};
						class T3 {
							maxT = 600;
							color[] = {0.39, 0.46, 0.47, 0};
						};
						class T4 {
							maxT = 800;
							color[] = {0.24, 0.31, 0.31, 0};
						};
						class T5 {
							maxT = 1000;
							color[] = {0.23, 0.31, 0.29, 0};
						};
						class T6 {
							maxT = 1500;
							color[] = {0.21, 0.29, 0.27, 0};
						};
						class T7 {
							maxT = 2000;
							color[] = {0.19, 0.23, 0.21, 0};
						};
						class T8 {
							maxT = 2300;
							color[] = {0.22, 0.19, 0.1, 0};
						};
						class T9 {
							maxT = 2500;
							color[] = {0.35, 0.2, 0.02, 0};
						};
						class T10 {
							maxT = 2600;
							color[] = {0.62, 0.29, 0.03, 0};
						};
						class T11 {
							maxT = 2650;
							color[] = {0.59, 0.35, 0.05, 0};
						};
						class T12 {
							maxT = 2700;
							color[] = {0.75, 0.37, 0.03, 0};
						};
						class T13 {
							maxT = 2750;
							color[] = {0.88, 0.34, 0.03, 0};
						};
						class T14 {
							maxT = 2800;
							color[] = {0.91, 0.5, 0.17, 0};
						};
						class T15 {
							maxT = 2850;
							color[] = {1, 0.6, 0.2, 0};
						};
						class T16 {
							maxT = 2900;
							color[] = {1, 0.71, 0.3, 0};
						};
						class T17 {
							maxT = 2950;
							color[] = {0.98, 0.83, 0.41, 0};
						};
						class T18 {
							maxT = 3000;
							color[] = {0.98, 0.91, 0.54, 0};
						};
						class T19 {
							maxT = 3100;
							color[] = {0.98, 0.99, 0.6, 0};
						};
						class T20 {
							maxT = 3300;
							color[] = {0.96, 0.99, 0.72, 0};
						};
						class T21 {
							maxT = 3600;
							color[] = {1, 0.98, 0.91, 0};
						};
						class T22 {
							maxT = 4200;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class GunClouds {
					// WeaponCloudsGun
					access = 0;
					cloudletDuration = 0.3;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 1;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 1;
					cloudletAccY = 0.4;
					cloudletMinYSpeed = 0.2;
					cloudletMaxYSpeed = 0.8;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.05;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class MGunClouds {
					// WeaponCloudsMGun
					access = 0;
					cloudletGrowUp = 0.05;
					cloudletFadeIn = 0;
					cloudletFadeOut = 0.1;
					cloudletDuration = 0.05;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 0.3;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					timeToLive = 0;
					interval = 0.02;
					size = 0.3;
					sourceSize = 0.02;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				// NewTurret
				class HitPoints {
					class HitTurret {
						armor = 0.8;
						material = 51;
						name = "turret";
						visual = "turret";
						passThrough = 1;
						explosionShielding = 1;
					};
					class HitGun {
						armor = 0.6;
						material = 52;
						name = "gun";
						visual = "gun";
						passThrough = 1;
						explosionShielding = 1;
					};
				};
				class Turrets {};
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.07;
					maxFov = 0.35;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				forceNVG = 0;
				gunnerLeftHandAnimName = "";
				gunnerRightHandAnimName = "";
				gunnerLeftLegAnimName = "";
				gunnerRightLegAnimName = "";
				gunnerDoor = "";
				preciseGetInOut = 0;
				allowTabLock = 1;
				showAllTargets = 0;
				slingLoadOperator = 0;
				playerPosition = 0;
				class TurnOut {
					// TurnIn
					turnOffset = 0;
				};
				gunnerInAction = "ManActTestDriver";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "kulas";
				selectionFireAnim = "zasleh";
				showCrewAim = 0;
			};
			class CargoTurret_03 {
				gunnerAction = "passenger_flatground_4_vehicle_passenger_stand_1";
				gunnerInAction = "vehicle_passenger_stand_1_passenger_flatground_4";
				gunnerName = "Passenger (Right Seat 1)";
				memoryPointsGetInGunner = "pos cargo RF";
				memoryPointsGetInGunnerDir = "pos cargo RF dir";
				proxyIndex = 4;
				forceHideGunner = 0;
				canHideGunner = 1;
				isPersonTurret = 2;
				LODTurnedIn = 1200;
				LODTurnedOut = -1;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				animationSourceHatch = "gunner_rf_turn";
				allowLauncherIn = 0;
				allowLauncherOut = 1;
				class TurnIn {
					limitsArrayTop[] = {{44.0899, 0.4614}};
					limitsArrayBottom[] = {{-5.6161, -103.247}, {-6.3359, -86.6666}, {-4.5173, -52.2224}, {-2.1727, -26.9412}, {-2.7195, 17.1711}, {-8.6474, 52.2545}, {-9.5587, 116.703}};
					turnOffset = -180;
				};
				class TurnOut {
					limitsArrayTop[] = {{38.5373, -12.3438}};
					limitsArrayBottom[] = {{-55.8132, -78.701}, {-55.695, -42.9749}, {-20.5349, -8.1766}, {-18.5114, 7.3282}, {-19.9175, 18.9012}, {-20.0625, 26.8051}, {-19.9485, 37.7768}, {-34.0815, 67.2254}, {-48.6922, 80.0348}, {-47.6331, 90.4505}};
					// TurnIn
					turnOffset = -180;
				};
				class dynamicViewLimits {
					CargoTurret_01[] = {5, 75};
					CargoTurret_02[] = {-15, 75};
					CargoTurret_04[] = {-75, 75};
				};
				// CargoTurret_01
				gunnerCompartments = "Compartment2";
				// CargoTurret
				class ViewGunner {
					// ViewCargo
					initAngleX = 5;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					minFov = 0.25;
					maxFov = 1.25;
					initFov = 0.75;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				animationSourceBody = "";
				animationSourceGun = "";
				body = "";
				canEject = 1;
				commanding = 0;
				dontCreateAI = 1;
				gun = "";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				hideWeaponsGunner = 0;
				isCopilot = 0;
				primaryGunner = 0;
				proxyType = "CPCargo";
				startEngine = 0;
				turretFollowFreeLook = 0;
				viewGunnerInExternal = 1;
				disableSoundAttenuation = 1;
				showAsCargo = 1;
				maxElev = 45;
				minElev = -45;
				maxTurn = 95;
				minTurn = -95;
				// NewTurret
				animationSourceCamElev = "camElev";
				gunnerType = "";
				primaryObserver = 0;
				weapons[] = {};
				magazines[] = {};
				soundServo[] = {"", 0.00316228, 1};
				soundElevation[] = {"", 1, 1};
				particlesPos = "usti hlavne";
				particlesDir = "konec hlavne";
				initElev = 0;
				initTurn = 0;
				minOutElev = -4;
				maxOutElev = 20;
				initOutElev = 0;
				minOutTurn = -60;
				maxOutTurn = 60;
				initOutTurn = 0;
				maxHorizontalRotSpeed = 1.2;
				maxVerticalRotSpeed = 1.2;
				stabilizedInAxes = 3;
				primary = 1;
				hasGunner = 1;
				turretCanSee = 0;
				canUseScanners = 1;
				class TurretSpec {
					showHeadPhones = 0;
				};
				gunnerOpticsModel = "";
				gunnerOpticsColor[] = {0, 0, 0, 1};
				gunnerForceOptics = 1;
				gunnerOpticsShowCursor = 0;
				turrentInfoType = "";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsColor[] = {0, 0, 0, 1};
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsEffect[] = {};
				memoryPointGunnerOutOptics = "";
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				gunnerUsesPilotView = 0;
				castGunnerShadow = 0;
				viewGunnerShadow = 1;
				viewGunnerShadowDiff = 1;
				viewGunnerShadowAmb = 1;
				ejectDeadGunner = 0;
				showHMD = 0;
				lockWhenDriverOut = 0;
				lockWhenVehicleSpeed = -1;
				memoryPointsGetInGunnerPrecise = "";
				missileBeg = "spice rakety";
				missileEnd = "konec rakety";
				armorLights = 0.4;
				class Reflectors {};
				aggregateReflectors[] = {};
				class GunFire {
					// WeaponFireGun
					access = 0;
					cloudletDuration = 0.2;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 0.2;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 0.5;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletFire";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.01;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 4500;
					deltaT = -3000;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {0.82, 0.95, 0.93, 0};
						};
						class T1 {
							maxT = 200;
							color[] = {0.75, 0.77, 0.9, 0};
						};
						class T2 {
							maxT = 400;
							color[] = {0.56, 0.62, 0.67, 0};
						};
						class T3 {
							maxT = 600;
							color[] = {0.39, 0.46, 0.47, 0};
						};
						class T4 {
							maxT = 800;
							color[] = {0.24, 0.31, 0.31, 0};
						};
						class T5 {
							maxT = 1000;
							color[] = {0.23, 0.31, 0.29, 0};
						};
						class T6 {
							maxT = 1500;
							color[] = {0.21, 0.29, 0.27, 0};
						};
						class T7 {
							maxT = 2000;
							color[] = {0.19, 0.23, 0.21, 0};
						};
						class T8 {
							maxT = 2300;
							color[] = {0.22, 0.19, 0.1, 0};
						};
						class T9 {
							maxT = 2500;
							color[] = {0.35, 0.2, 0.02, 0};
						};
						class T10 {
							maxT = 2600;
							color[] = {0.62, 0.29, 0.03, 0};
						};
						class T11 {
							maxT = 2650;
							color[] = {0.59, 0.35, 0.05, 0};
						};
						class T12 {
							maxT = 2700;
							color[] = {0.75, 0.37, 0.03, 0};
						};
						class T13 {
							maxT = 2750;
							color[] = {0.88, 0.34, 0.03, 0};
						};
						class T14 {
							maxT = 2800;
							color[] = {0.91, 0.5, 0.17, 0};
						};
						class T15 {
							maxT = 2850;
							color[] = {1, 0.6, 0.2, 0};
						};
						class T16 {
							maxT = 2900;
							color[] = {1, 0.71, 0.3, 0};
						};
						class T17 {
							maxT = 2950;
							color[] = {0.98, 0.83, 0.41, 0};
						};
						class T18 {
							maxT = 3000;
							color[] = {0.98, 0.91, 0.54, 0};
						};
						class T19 {
							maxT = 3100;
							color[] = {0.98, 0.99, 0.6, 0};
						};
						class T20 {
							maxT = 3300;
							color[] = {0.96, 0.99, 0.72, 0};
						};
						class T21 {
							maxT = 3600;
							color[] = {1, 0.98, 0.91, 0};
						};
						class T22 {
							maxT = 4200;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class GunClouds {
					// WeaponCloudsGun
					access = 0;
					cloudletDuration = 0.3;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 1;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 1;
					cloudletAccY = 0.4;
					cloudletMinYSpeed = 0.2;
					cloudletMaxYSpeed = 0.8;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.05;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class MGunClouds {
					// WeaponCloudsMGun
					access = 0;
					cloudletGrowUp = 0.05;
					cloudletFadeIn = 0;
					cloudletFadeOut = 0.1;
					cloudletDuration = 0.05;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 0.3;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					timeToLive = 0;
					interval = 0.02;
					size = 0.3;
					sourceSize = 0.02;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				// NewTurret
				class HitPoints {
					class HitTurret {
						armor = 0.8;
						material = 51;
						name = "turret";
						visual = "turret";
						passThrough = 1;
						explosionShielding = 1;
					};
					class HitGun {
						armor = 0.6;
						material = 52;
						name = "gun";
						visual = "gun";
						passThrough = 1;
						explosionShielding = 1;
					};
				};
				class Turrets {};
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.07;
					maxFov = 0.35;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				forceNVG = 0;
				gunnerLeftHandAnimName = "";
				gunnerRightHandAnimName = "";
				gunnerLeftLegAnimName = "";
				gunnerRightLegAnimName = "";
				gunnerDoor = "";
				preciseGetInOut = 0;
				allowTabLock = 1;
				showAllTargets = 0;
				slingLoadOperator = 0;
				playerPosition = 0;
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "kulas";
				selectionFireAnim = "zasleh";
				showCrewAim = 0;
			};
			class CargoTurret_04 {
				gunnerAction = "passenger_flatground_4_vehicle_passenger_stand_1";
				gunnerInAction = "vehicle_passenger_stand_1_passenger_flatground_4";
				gunnerName = "Passenger (Left Seat 1)";
				memoryPointsGetInGunner = "pos cargo LF";
				memoryPointsGetInGunnerDir = "pos cargo LF dir";
				proxyIndex = 5;
				animationSourceHatch = "gunner_lf_turn";
				allowLauncherIn = 0;
				allowLauncherOut = 1;
				class TurnIn {
					limitsArrayTop[] = {{32.7249, -3.3246}};
					limitsArrayBottom[] = {{-13.8937, -116.091}, {-15.9318, -73.9232}, {-7.7741, -33.6104}, {-2.2081, -11.6789}, {-2.175, 33.6969}, {-4.7948, 64.9968}, {-6.1246, 108.424}};
					turnOffset = -180;
				};
				class TurnOut {
					limitsArrayTop[] = {{60.2039, -100.44}};
					limitsArrayBottom[] = {{-39.8219, -73.3444}, {-35.1597, -60.962}, {-28.0802, -54.4944}, {-18.1518, -30.9259}, {-20.7152, 12.1939}, {-36.7666, 33.6105}, {-39.7748, 75.8732}};
					// TurnIn
					turnOffset = -180;
				};
				class dynamicViewLimits {
					CargoTurret_01[] = {-75, 15};
					CargoTurret_02[] = {-75, -5};
					CargoTurret_03[] = {-75, 75};
				};
				// CargoTurret_03
				forceHideGunner = 0;
				canHideGunner = 1;
				isPersonTurret = 2;
				LODTurnedIn = 1200;
				LODTurnedOut = -1;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				// CargoTurret_01
				gunnerCompartments = "Compartment2";
				// CargoTurret
				class ViewGunner {
					// ViewCargo
					initAngleX = 5;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					minFov = 0.25;
					maxFov = 1.25;
					initFov = 0.75;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				animationSourceBody = "";
				animationSourceGun = "";
				body = "";
				canEject = 1;
				commanding = 0;
				dontCreateAI = 1;
				gun = "";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				hideWeaponsGunner = 0;
				isCopilot = 0;
				primaryGunner = 0;
				proxyType = "CPCargo";
				startEngine = 0;
				turretFollowFreeLook = 0;
				viewGunnerInExternal = 1;
				disableSoundAttenuation = 1;
				showAsCargo = 1;
				maxElev = 45;
				minElev = -45;
				maxTurn = 95;
				minTurn = -95;
				// NewTurret
				animationSourceCamElev = "camElev";
				gunnerType = "";
				primaryObserver = 0;
				weapons[] = {};
				magazines[] = {};
				soundServo[] = {"", 0.00316228, 1};
				soundElevation[] = {"", 1, 1};
				particlesPos = "usti hlavne";
				particlesDir = "konec hlavne";
				initElev = 0;
				initTurn = 0;
				minOutElev = -4;
				maxOutElev = 20;
				initOutElev = 0;
				minOutTurn = -60;
				maxOutTurn = 60;
				initOutTurn = 0;
				maxHorizontalRotSpeed = 1.2;
				maxVerticalRotSpeed = 1.2;
				stabilizedInAxes = 3;
				primary = 1;
				hasGunner = 1;
				turretCanSee = 0;
				canUseScanners = 1;
				class TurretSpec {
					showHeadPhones = 0;
				};
				gunnerOpticsModel = "";
				gunnerOpticsColor[] = {0, 0, 0, 1};
				gunnerForceOptics = 1;
				gunnerOpticsShowCursor = 0;
				turrentInfoType = "";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsColor[] = {0, 0, 0, 1};
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsEffect[] = {};
				memoryPointGunnerOutOptics = "";
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				gunnerUsesPilotView = 0;
				castGunnerShadow = 0;
				viewGunnerShadow = 1;
				viewGunnerShadowDiff = 1;
				viewGunnerShadowAmb = 1;
				ejectDeadGunner = 0;
				showHMD = 0;
				lockWhenDriverOut = 0;
				lockWhenVehicleSpeed = -1;
				memoryPointsGetInGunnerPrecise = "";
				missileBeg = "spice rakety";
				missileEnd = "konec rakety";
				armorLights = 0.4;
				class Reflectors {};
				aggregateReflectors[] = {};
				class GunFire {
					// WeaponFireGun
					access = 0;
					cloudletDuration = 0.2;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 0.2;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 0.5;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletFire";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.01;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 4500;
					deltaT = -3000;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {0.82, 0.95, 0.93, 0};
						};
						class T1 {
							maxT = 200;
							color[] = {0.75, 0.77, 0.9, 0};
						};
						class T2 {
							maxT = 400;
							color[] = {0.56, 0.62, 0.67, 0};
						};
						class T3 {
							maxT = 600;
							color[] = {0.39, 0.46, 0.47, 0};
						};
						class T4 {
							maxT = 800;
							color[] = {0.24, 0.31, 0.31, 0};
						};
						class T5 {
							maxT = 1000;
							color[] = {0.23, 0.31, 0.29, 0};
						};
						class T6 {
							maxT = 1500;
							color[] = {0.21, 0.29, 0.27, 0};
						};
						class T7 {
							maxT = 2000;
							color[] = {0.19, 0.23, 0.21, 0};
						};
						class T8 {
							maxT = 2300;
							color[] = {0.22, 0.19, 0.1, 0};
						};
						class T9 {
							maxT = 2500;
							color[] = {0.35, 0.2, 0.02, 0};
						};
						class T10 {
							maxT = 2600;
							color[] = {0.62, 0.29, 0.03, 0};
						};
						class T11 {
							maxT = 2650;
							color[] = {0.59, 0.35, 0.05, 0};
						};
						class T12 {
							maxT = 2700;
							color[] = {0.75, 0.37, 0.03, 0};
						};
						class T13 {
							maxT = 2750;
							color[] = {0.88, 0.34, 0.03, 0};
						};
						class T14 {
							maxT = 2800;
							color[] = {0.91, 0.5, 0.17, 0};
						};
						class T15 {
							maxT = 2850;
							color[] = {1, 0.6, 0.2, 0};
						};
						class T16 {
							maxT = 2900;
							color[] = {1, 0.71, 0.3, 0};
						};
						class T17 {
							maxT = 2950;
							color[] = {0.98, 0.83, 0.41, 0};
						};
						class T18 {
							maxT = 3000;
							color[] = {0.98, 0.91, 0.54, 0};
						};
						class T19 {
							maxT = 3100;
							color[] = {0.98, 0.99, 0.6, 0};
						};
						class T20 {
							maxT = 3300;
							color[] = {0.96, 0.99, 0.72, 0};
						};
						class T21 {
							maxT = 3600;
							color[] = {1, 0.98, 0.91, 0};
						};
						class T22 {
							maxT = 4200;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class GunClouds {
					// WeaponCloudsGun
					access = 0;
					cloudletDuration = 0.3;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 1;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 1;
					cloudletAccY = 0.4;
					cloudletMinYSpeed = 0.2;
					cloudletMaxYSpeed = 0.8;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.05;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class MGunClouds {
					// WeaponCloudsMGun
					access = 0;
					cloudletGrowUp = 0.05;
					cloudletFadeIn = 0;
					cloudletFadeOut = 0.1;
					cloudletDuration = 0.05;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 0.3;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					timeToLive = 0;
					interval = 0.02;
					size = 0.3;
					sourceSize = 0.02;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				// NewTurret
				class HitPoints {
					class HitTurret {
						armor = 0.8;
						material = 51;
						name = "turret";
						visual = "turret";
						passThrough = 1;
						explosionShielding = 1;
					};
					class HitGun {
						armor = 0.6;
						material = 52;
						name = "gun";
						visual = "gun";
						passThrough = 1;
						explosionShielding = 1;
					};
				};
				class Turrets {};
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.07;
					maxFov = 0.35;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				forceNVG = 0;
				gunnerLeftHandAnimName = "";
				gunnerRightHandAnimName = "";
				gunnerLeftLegAnimName = "";
				gunnerRightLegAnimName = "";
				gunnerDoor = "";
				preciseGetInOut = 0;
				allowTabLock = 1;
				showAllTargets = 0;
				slingLoadOperator = 0;
				playerPosition = 0;
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "kulas";
				selectionFireAnim = "zasleh";
				showCrewAim = 0;
			};
			class MainTurret {
				stabilizedInAxes = 4;
				outGunnerMayFire = 1;
				memoryPointGun = "machinegun";
				body = "";
				gun = "";
				gunnerAction = "ManActTestDriverOut";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				soundServo[] = {"A3\sounds_f\dummysound", 0.316228, 1, 15};
				minElev = -5;
				maxElev = 40;
				minTurn = -360;
				maxTurn = 360;
				gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				primaryGunner = 1;
				enableManualFire = 0;
				gunnerForceOptics = 0;
				startEngine = 0;
				class HitPoints {
					class HitTurret {
						armor = 0.8;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0.5;
						explosionShielding = 0.4;
					};
					class HitGun {
						armor = 0.4;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
						explosionShielding = 0.2;
					};
				};
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.07;
					maxFov = 0.35;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				class ViewGunner {
					// ViewOptics
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.07;
					maxFov = 0.35;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				disableSoundAttenuation = 0;
				// NewTurret
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				animationSourceHatch = "hatchGunner";
				animationSourceCamElev = "camElev";
				proxyType = "CPGunner";
				proxyIndex = 1;
				gunnerName = "Gunner";
				gunnerType = "";
				primaryObserver = 0;
				weapons[] = {};
				magazines[] = {};
				soundElevation[] = {"", 1, 1};
				particlesPos = "usti hlavne";
				particlesDir = "konec hlavne";
				initElev = 0;
				initTurn = 0;
				minOutElev = -4;
				maxOutElev = 20;
				initOutElev = 0;
				minOutTurn = -60;
				maxOutTurn = 60;
				initOutTurn = 0;
				maxHorizontalRotSpeed = 1.2;
				maxVerticalRotSpeed = 1.2;
				primary = 1;
				hasGunner = 1;
				commanding = 1;
				turretCanSee = 0;
				canUseScanners = 1;
				class TurretSpec {
					showHeadPhones = 0;
				};
				gunnerOpticsColor[] = {0, 0, 0, 1};
				gunnerOpticsShowCursor = 0;
				turrentInfoType = "";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsColor[] = {0, 0, 0, 1};
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsEffect[] = {};
				memoryPointGunnerOutOptics = "";
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOutFireAlsoInInternalCamera = 1;
				gunnerUsesPilotView = 0;
				castGunnerShadow = 0;
				viewGunnerShadow = 1;
				viewGunnerShadowDiff = 1;
				viewGunnerShadowAmb = 1;
				ejectDeadGunner = 0;
				hideWeaponsGunner = 1;
				canHideGunner = -1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				showHMD = 0;
				viewGunnerInExternal = 0;
				lockWhenDriverOut = 0;
				lockWhenVehicleSpeed = -1;
				gunnerCompartments = "Compartment1";
				LODTurnedIn = -1;
				LODTurnedOut = -1;
				memoryPointsGetInGunnerPrecise = "";
				missileBeg = "spice rakety";
				missileEnd = "konec rakety";
				armorLights = 0.4;
				class Reflectors {};
				aggregateReflectors[] = {};
				class GunFire {
					// WeaponFireGun
					access = 0;
					cloudletDuration = 0.2;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 0.2;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 0.5;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletFire";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.01;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 4500;
					deltaT = -3000;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {0.82, 0.95, 0.93, 0};
						};
						class T1 {
							maxT = 200;
							color[] = {0.75, 0.77, 0.9, 0};
						};
						class T2 {
							maxT = 400;
							color[] = {0.56, 0.62, 0.67, 0};
						};
						class T3 {
							maxT = 600;
							color[] = {0.39, 0.46, 0.47, 0};
						};
						class T4 {
							maxT = 800;
							color[] = {0.24, 0.31, 0.31, 0};
						};
						class T5 {
							maxT = 1000;
							color[] = {0.23, 0.31, 0.29, 0};
						};
						class T6 {
							maxT = 1500;
							color[] = {0.21, 0.29, 0.27, 0};
						};
						class T7 {
							maxT = 2000;
							color[] = {0.19, 0.23, 0.21, 0};
						};
						class T8 {
							maxT = 2300;
							color[] = {0.22, 0.19, 0.1, 0};
						};
						class T9 {
							maxT = 2500;
							color[] = {0.35, 0.2, 0.02, 0};
						};
						class T10 {
							maxT = 2600;
							color[] = {0.62, 0.29, 0.03, 0};
						};
						class T11 {
							maxT = 2650;
							color[] = {0.59, 0.35, 0.05, 0};
						};
						class T12 {
							maxT = 2700;
							color[] = {0.75, 0.37, 0.03, 0};
						};
						class T13 {
							maxT = 2750;
							color[] = {0.88, 0.34, 0.03, 0};
						};
						class T14 {
							maxT = 2800;
							color[] = {0.91, 0.5, 0.17, 0};
						};
						class T15 {
							maxT = 2850;
							color[] = {1, 0.6, 0.2, 0};
						};
						class T16 {
							maxT = 2900;
							color[] = {1, 0.71, 0.3, 0};
						};
						class T17 {
							maxT = 2950;
							color[] = {0.98, 0.83, 0.41, 0};
						};
						class T18 {
							maxT = 3000;
							color[] = {0.98, 0.91, 0.54, 0};
						};
						class T19 {
							maxT = 3100;
							color[] = {0.98, 0.99, 0.6, 0};
						};
						class T20 {
							maxT = 3300;
							color[] = {0.96, 0.99, 0.72, 0};
						};
						class T21 {
							maxT = 3600;
							color[] = {1, 0.98, 0.91, 0};
						};
						class T22 {
							maxT = 4200;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class GunClouds {
					// WeaponCloudsGun
					access = 0;
					cloudletDuration = 0.3;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 1;
					cloudletGrowUp = 1;
					cloudletFadeIn = 0.01;
					cloudletFadeOut = 1;
					cloudletAccY = 0.4;
					cloudletMinYSpeed = 0.2;
					cloudletMaxYSpeed = 0.8;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					interval = 0.05;
					size = 3;
					sourceSize = 0.5;
					timeToLive = 0;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				class MGunClouds {
					// WeaponCloudsMGun
					access = 0;
					cloudletGrowUp = 0.05;
					cloudletFadeIn = 0;
					cloudletFadeOut = 0.1;
					cloudletDuration = 0.05;
					cloudletAnimPeriod = 1;
					cloudletSize = 1;
					cloudletAlpha = 0.3;
					cloudletAccY = 0;
					cloudletMinYSpeed = -100;
					cloudletMaxYSpeed = 100;
					cloudletShape = "cloudletClouds";
					cloudletColor[] = {1, 1, 1, 0};
					timeToLive = 0;
					interval = 0.02;
					size = 0.3;
					sourceSize = 0.02;
					initT = 0;
					deltaT = 0;
					class Table {
						class T0 {
							maxT = 0;
							color[] = {1, 1, 1, 0};
						};
					};
				};
				// NewTurret
				class Turrets {};
				forceNVG = 0;
				isCopilot = 0;
				canEject = 1;
				gunnerLeftHandAnimName = "";
				gunnerRightHandAnimName = "";
				gunnerLeftLegAnimName = "";
				gunnerRightLegAnimName = "";
				gunnerDoor = "";
				preciseGetInOut = 0;
				turretFollowFreeLook = 0;
				allowTabLock = 1;
				showAllTargets = 0;
				dontCreateAI = 0;
				slingLoadOperator = 0;
				playerPosition = 0;
				allowLauncherIn = 0;
				allowLauncherOut = 0;
				class TurnIn {
					turnOffset = 0;
				};
				class TurnOut {
					// TurnIn
					turnOffset = 0;
				};
				gunnerInAction = "ManActTestDriver";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				selectionFireAnim = "zasleh";
				showCrewAim = 0;
			};
		};
		accuracy = 1.25;
		showNVGCargo[] = {0, 1};
		soundAttenuationCargo[] = {1, 0};
		class TextureSources {
			class Red {
				displayName = "Red";
				author = "Bohemia Interactive";
				textures[] = {"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_CO.paa", "\a3\Soft_F\Offroad_01\data\Offroad_01_ext_CO.paa"};
				factions[] = {"CIV_F"};
			};
			class Beige {
				displayName = "Beige";
				author = "Bohemia Interactive";
				textures[] = {"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE01_CO.paa", "\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE01_CO.paa"};
				factions[] = {"CIV_F"};
			};
			class White {
				displayName = "White";
				author = "Bohemia Interactive";
				textures[] = {"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE02_CO.paa", "\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE02_CO.paa"};
				factions[] = {"CIV_F"};
			};
			class Blue {
				displayName = "Blue";
				author = "Bohemia Interactive";
				textures[] = {"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE03_CO.paa", "\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE03_CO.paa"};
				factions[] = {"CIV_F"};
			};
			class Darkred {
				displayName = "Dark Red";
				author = "Bohemia Interactive";
				textures[] = {"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE04_CO.paa", "\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE04_CO.paa"};
				factions[] = {"CIV_F"};
			};
			class Bluecustom {
				displayName = "Blue Custom";
				author = "Bohemia Interactive";
				textures[] = {"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE05_CO.paa", "\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE05_CO.paa"};
				factions[] = {"CIV_F"};
			};
			class Guerilla_01 {
				displayName = "Guerrilla 01";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_02 {
				displayName = "Guerrilla 02";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_03 {
				displayName = "Guerrilla 03";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_04 {
				displayName = "Guerrilla 04";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_05 {
				displayName = "Guerrilla 05";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_06 {
				displayName = "Guerrilla 06";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_07 {
				displayName = "Guerrilla 07";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_08 {
				displayName = "Guerrilla 08";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_09 {
				displayName = "Guerrilla 09";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_10 {
				displayName = "Guerrilla 10";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_11 {
				displayName = "Guerrilla 11";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Guerilla_12 {
				displayName = "Guerrilla 12";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa", "\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa"};
				faction[] = {"BLU_F_F", "OPF_G_F", "IND_G_F"};
			};
			class Gendarmerie {
				displayName = "Gendarmerie";
				author = "Bohemia Interactive";
				textures[] = {"\A3\Soft_F_Exp\Offroad_01\Data\Offroad_01_ext_gen_CO.paa", "\A3\Soft_F_Exp\Offroad_01\Data\Offroad_01_ext_gen_CO.paa"};
				factions[] = {"BLU_GEN_F"};
			};
		};
		textureList[] = {"Red", 1, "Beige", 1, "White", 1, "Blue", 1, "Darkred", 1, "Bluecustom", 1, "Gendarmerie", 1};
		animationList[] = {"hidePolice",0.75,"HideServices",0.95,"BeaconsStart",0.50,"BeaconsServicesStart",0.50,"HideDoor1",0.33,"HideDoor2",0.65,"HideGlass2",0.20,"HideDoor3",0.25,"HideBackpacks",0.60,"HideBumper1",0.40};
		// Offroad_01_unarmed_base_F
		class AnimationSources {
			class hidePolice {
				displayName = "Hide police light bar";
				source = "user";
				initPhase = 1;
				author = "Bohemia Interactive";
				forceAnimatePhase = 0;
				forceAnimate[] = {"HideServices", 1};
				mass = -4;
			};
			class HideServices {
				displayName = "Hide service additions";
				author = "Bohemia Interactive";
				source = "Proxy";
				initPhase = 1;
				lockCargoAnimationPhase = 0;
				lockCargo[] = {3, 4};
				forceAnimatePhase = 0;
				forceAnimate[] = {"hideConstruction", 1, "hidebBumper1", 1, "hidebBumper2", 1};
			};
			class BeaconsStart {
				displayName = "Start police light bar";
				author = "Bohemia Interactive";
				initPhase = 0;
			};
			class BeaconsServicesStart {
				displayName = "Start service light bar";
				author = "Bohemia Interactive";
				initPhase = 0;
			};
			class HideDoor1 {
				displayName = "Hide left door";
				author = "Bohemia Interactive";
				source = "Proxy";
				initPhase = 0;
				mass = -6.5;
			};
			class HideDoor2: HideDoor1 {
				displayName = "Hide right door";
				author = "Bohemia Interactive";
				forceAnimatePhase = 1;
				forceAnimate[] = {"HideGlass2", 1};
				// HideDoor1
				source = "Proxy";
				initPhase = 0;
				mass = -6.5;
			};
			class HideGlass2 {
				displayName = "Hide right glass";
				author = "Bohemia Interactive";
				source = "Doors";
				initPhase = 0;
				mass = -0.75;
				scope = 0;
			};
			class HideDoor3: HideDoor1 {
				displayName = "Hide rear door";
				author = "Bohemia Interactive";
				mass = -4;
				// HideDoor1
				source = "Proxy";
				initPhase = 0;
			};
			class HideBackpacks {
				displayName = "Hide backpacks";
				author = "Bohemia Interactive";
				source = "Proxy";
				initPhase = 1;
				mass = -12;
			};
			class HideBumper1 {
				displayName = "Hide bumper";
				author = "Bohemia Interactive";
				source = "Proxy";
				initPhase = 1;
				forceAnimatePhase = 0;
				forceAnimate[] = {"HideBumper2", 1};
				mass = -50;
			};
			class HideBumper2: HideBumper1 {
				displayName = "Hide bumper with winch";
				author = "Bohemia Interactive";
				forceAnimate[] = {"HideBumper1", 1};
				mass = -90;
				// HideBumper1
				source = "Proxy";
				initPhase = 1;
				forceAnimatePhase = 0;
			};
			class HideConstruction {
				displayName = "Hide rear structure";
				author = "Bohemia Interactive";
				source = "Proxy";
				initPhase = 1;
				mass = -105;
				forceAnimatePhase = 0;
				forceAnimate[] = {"hideServices", 1};
			};
			class Doors {
				source = "user";
				animPeriod = 0.001;
				initPhase = 0;
			};
			class Proxy {
				source = "user";
				animPeriod = 0.001;
				initPhase = 1;
			};
			class Beacons {
				source = "user";
				animPeriod = 0.001;
				initPhase = 0;
			};
			class Destruct {
				source = "user";
				animPeriod = 0;
				initPhase = 1;
			};
			class HitLFWheel {
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel {
				hitpoint = "HitRFWheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitLBWheel: HitLFWheel {
				hitpoint = "HitLF2Wheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitRBWheel: HitLFWheel {
				hitpoint = "HitRF2Wheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitLF2Wheel: HitLFWheel {
				hitpoint = "HitLBWheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitRF2Wheel: HitLFWheel {
				hitpoint = "HitRBWheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitLMWheel: HitLFWheel {
				hitpoint = "HitLMWheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitRMWheel: HitLFWheel {
				hitpoint = "HitRMWheel";
				// HitLFWheel
				source = "Hit";
				raw = 1;
			};
			class HitGlass1 {
				source = "Hit";
				hitpoint = "HitGlass1";
				raw = 1;
			};
			class HitGlass2: HitGlass1 {
				hitpoint = "HitGlass2";
				// HitGlass1
				source = "Hit";
				raw = 1;
			};
			class HitGlass3: HitGlass1 {
				hitpoint = "HitGlass3";
				// HitGlass1
				source = "Hit";
				raw = 1;
			};
			class HitGlass4: HitGlass1 {
				hitpoint = "HitGlass4";
				// HitGlass1
				source = "Hit";
				raw = 1;
			};
			class HitGlass5: HitGlass1 {
				hitpoint = "HitGlass5";
				// HitGlass1
				source = "Hit";
				raw = 1;
			};
			class HitGlass6: HitGlass1 {
				hitpoint = "HitGlass6";
				// HitGlass1
				source = "Hit";
				raw = 1;
			};
		};
		// Offroad_01_base_F
		mapSize = 7.14;
		nameSound = "veh_car";
		class Library {
			libTextDesc = "The 4x4 pickup by Generic Motors is a perfect choice for farmers and hunters. The durable chassis and powerful engine have been designed to withstand anything from the cratered highways of Central Europe to the rugged terrain of the Mediterranean. The armed version is fitted with a .50 caliber heavy machine gun. It provides the combination of mobility and firepower to many paramilitary and guerilla forces in local conflicts around the globe.";
		};
		model = "\A3\soft_f\Offroad_01\Offroad_01_unarmed_F";
		editorSubcategory = "EdSubcat_Cars";
		picture = "\A3\soft_f\Offroad_01\Data\UI\Offroad_01_base_CA.paa";
		Icon = "\A3\soft_f\Offroad_01\Data\UI\map_offroad_01_CA.paa";
		transportMaxBackpacks = 0;
		armor = 30;
		armorLights = 0.02;
		fuelExplosionPower = 2;
		cost = 50000;
		weapons[] = {"SportCarHorn"};
		memoryPointTaskMarker = "TaskMarker_1_pos";
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1", "SlingLoadCargo2", "SlingLoadCargo3", "SlingLoadCargo4"};
		unitInfoType = "RscUnitInfoNoWeapon";
		maximumLoad = 4000;
		class TransportItems {
			class _xx_FirstAidKit {
				name = "FirstAidKit";
				count = 4;
			};
		};
		hiddenSelections[] = {"camo", "camo2"};
		hiddenSelectionsTextures[] = {"\A3\soft_f\Offroad_01\data\Offroad_01_ext_co.paa", "\A3\soft_f\Offroad_01\data\Offroad_01_ext_co.paa"};
		class HitPoints {
			class HitLFWheel {
				armor = 0.5;
				passThrough = 0;
				radius = 0.25;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				explosionShielding = 4;
			};
			class HitLF2Wheel {
				armor = 0.5;
				passThrough = 0;
				radius = 0.25;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				explosionShielding = 4;
			};
			class HitRFWheel {
				armor = 0.5;
				passThrough = 0;
				radius = 0.25;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "";
				explosionShielding = 4;
			};
			class HitRF2Wheel {
				armor = 0.5;
				passThrough = 0;
				radius = 0.25;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "";
				explosionShielding = 4;
			};
			class HitFuel {
				name = "palivo";
				armor = 2;
				radius = 0.5;
				material = -1;
				visual = "";
				passThrough = 0.5;
				explosionShielding = 1.5;
				minimalHit = 0.1;
			};
			class HitEngine {
				name = "motor";
				armor = 4;
				radius = 0.25;
				material = -1;
				visual = "";
				passThrough = 0.5;
				explosionShielding = 0.5;
			};
			class HitBody {
				visual = "camo";
				armor = 1;
				material = -1;
				name = "karoserie";
				passThrough = 1;
				explosionShielding = 1.5;
			};
			class HitGlass1 {
				armor = 0.25;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitGlass2 {
				armor = 0.25;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitRGlass {
				armor = 0.2;
				material = -1;
				name = "sklo predni P";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitLGlass {
				armor = 0.2;
				material = -1;
				name = "sklo predni L";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitGlass3 {
				armor = 0.1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitGlass4 {
				armor = 0.1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitGlass5 {
				armor = 0.1;
				material = -1;
				name = "glass5";
				visual = "glass5";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitGlass6 {
				armor = 0.1;
				material = -1;
				name = "glass6";
				visual = "glass6";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitLBWheel {
				armor = 0.2;
				material = -1;
				name = "wheel_1_4_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitLMWheel {
				armor = 0.2;
				material = -1;
				name = "wheel_1_3_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitRBWheel {
				armor = 0.2;
				material = -1;
				name = "wheel_2_4_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitRMWheel {
				armor = 0.2;
				material = -1;
				name = "wheel_2_3_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
		};
		precision = 10;
		brakeDistance = 50;
		turnCoef = 3.5;
		class PlayerSteeringCoefficients {
			turnIncreaseConst = 0.7;
			turnIncreaseLinear = 2.5;
			turnIncreaseTime = 0;
			turnDecreaseConst = 8;
			turnDecreaseLinear = 0;
			turnDecreaseTime = 0;
			maxTurnHundred = 1;
		};
		driverAction = "driver_offroad01";
		driverInAction = "driver_offroad01";
		cargoAction[] = {"passenger_low01", "passenger_flatground_leanleft", "passenger_flatground_leanright", "passenger_flatground_crosslegs", "passenger_flatground_leanleft"};
		cargoIsCoDriver[] = {1, 0};
		getInAction = "GetInOffroad";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1", "Compartment2", "Compartment2", "Compartment2", "Compartment2"};
		hideProxyInCombat = 0;
		forceHideDriver = 0;
		canHideDriver = 0;
		fireResistance = 5;
		wheelDestroyRadiusCoef = 0.75;
		attenuationEffectType = "SemiOpenCarAttenuation";
		soundGetIn[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\Offroad_01-int-openclose", 0.446684, 1};
		soundGetOut[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\Offroad_01-int-openclose", 0.446684, 1, 40};
		soundDammage[] = {"", 0.562341, 1};
		soundEngineOnInt[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_start", 0.316228, 1};
		soundEngineOnExt[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_start", 0.398107, 1, 200};
		soundEngineOffInt[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_stop", 0.316228, 1};
		soundEngineOffExt[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_stop", 0.398107, 1, 200};
		buildCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1, 1, 200};
		buildCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1, 1, 200};
		buildCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1, 1, 200};
		buildCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1, 1, 200};
		soundBuildingCrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
		WoodCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1", 1, 1, 200};
		WoodCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1", 1, 1, 200};
		WoodCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1", 1, 1, 200};
		WoodCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1", 1, 1, 200};
		soundWoodCrash[] = {"woodCrash0", 0.25, "woodCrash1", 0.25, "woodCrash2", 0.25, "woodCrash3", 0.25};
		armorCrash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1, 1, 200};
		armorCrash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1, 1, 200};
		armorCrash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1, 1, 200};
		armorCrash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1, 1, 200};
		soundArmorCrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
		Crash0[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1", 1, 1, 200};
		Crash1[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2", 1, 1, 200};
		Crash2[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3", 1, 1, 200};
		Crash3[] = {"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4", 1, 1, 200};
		soundCrashes[] = {"Crash0", 0.25, "Crash1", 0.25, "Crash2", 0.25, "Crash3", 0.25};
		class Sounds {
			class Idle_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_idle", 0.316228, 1, 100};
				frequency = "0.95	+	((rpm/	3500) factor[(200/	3500),(580/	3500)])*0.15";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(200/	3500),(350/	3500)])	*	((rpm/	3500) factor[(580/	3500),(400/	3500)]))";
			};
			class Engine {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm1", 0.316228, 1, 200};
				frequency = "0.9	+	((rpm/	3500) factor[(380/	3500),(960/	3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(380/	3500),(580/	3500)])	*	((rpm/	3500) factor[(960/	3500),(700/	3500)]))";
			};
			class Engine1_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm2", 0.354813, 1, 225};
				frequency = "0.9	+	((rpm/	3500) factor[(700/	3500),(1400/	3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(700/	3500),(970/	3500)])	*	((rpm/	3500) factor[(1400/	3500),(1100/	3500)]))";
			};
			class Engine2_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm3", 0.354813, 1, 250};
				frequency = "0.9	+	((rpm/	3500) factor[(1100/	3500),(1860/	3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(1100/	3500),(1430/	3500)])	*	((rpm/	3500) factor[(1860/	3500),(1570/	3500)]))";
			};
			class Engine3_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm4", 0.398107, 1, 275};
				frequency = "0.95	+	((rpm/	3500) factor[(1600/	3500),(2200/	3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(1600/	3500),(1860/	3500)])	*	((rpm/	3500) factor[(2200/	3500),(2050/	3500)]))";
			};
			class Engine4_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm5", 0.446684, 1, 300};
				frequency = "0.95	+	((rpm/	3500) factor[(2040/	3500),(2670/	3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(2040/	3500),(2200/	3500)])	*	((rpm/	3500) factor[(2670/	3500),(2400/	3500)]))";
			};
			class Engine5_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm6", 0.501187, 1, 300};
				frequency = "0.95	+	((rpm/	3500) factor[(2400/	3500),(3050/	3500)])*0.2";
				volume = "engineOn*camPos*(((rpm/	3500) factor[(2400/	3500),(2660/	3500)])	*	((rpm/	3500) factor[(3050/	3500),(2800/	3500)]))";
			};
			class Engine6_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_ext_rpm7", 0.562341, 1, 300};
				frequency = "0.95	+	((rpm/	3500) factor[(2700/	3500),(3500/	3500)])*0.2";
				volume = "engineOn*camPos*((rpm/	3500) factor[(2700/	3500),(3200/	3500)])";
			};
			class IdleThrust {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_idle", 0.501187, 1, 200};
				frequency = "0.95	+	((rpm/	3500) factor[(200/	3500),(580/	3500)])*0.15";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(200/	3500),(350/	3500)])	*	((rpm/	3500) factor[(580/	3500),(400/	3500)]))";
			};
			class EngineThrust {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm1", 0.562341, 1, 250};
				frequency = "0.9	+	((rpm/	3500) factor[(380/	3500),(960/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(380/	3500),(580/	3500)])	*	((rpm/	3500) factor[(960/	3500),(700/	3500)]))";
			};
			class Engine1_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm2", 0.630957, 1, 275};
				frequency = "0.9	+	((rpm/	3500) factor[(700/	3500),(1400/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(700/	3500),(970/	3500)])	*	((rpm/	3500) factor[(1400/	3500),(1100/	3500)]))";
			};
			class Engine2_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm3", 0.707946, 1, 300};
				frequency = "0.9	+	((rpm/	3500) factor[(1100/	3500),(1860/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(1100/	3500),(1430/	3500)])	*	((rpm/	3500) factor[(1860/	3500),(1570/	3500)]))";
			};
			class Engine3_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm4", 0.794328, 1, 325};
				frequency = "0.95	+	((rpm/	3500) factor[(1600/	3500),(2200/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(1600/	3500),(1860/	3500)])	*	((rpm/	3500) factor[(2200/	3500),(2050/	3500)]))";
			};
			class Engine4_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm5", 0.891251, 1, 350};
				frequency = "0.95	+	((rpm/	3500) factor[(2040/	3500),(2670/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(2040/	3500),(2200/	3500)])	*	((rpm/	3500) factor[(2670/	3500),(2400/	3500)]))";
			};
			class Engine5_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm6", 1, 1, 375};
				frequency = "0.95	+	((rpm/	3500) factor[(2400/	3500),(3050/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(2400/	3500),(2660/	3500)])	*	((rpm/	3500) factor[(3050/	3500),(2800/	3500)]))";
			};
			class Engine6_Thrust_ext {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_ext_rpm7", 1.12202, 1, 400};
				frequency = "0.95	+	((rpm/	3500) factor[(2700/	3500),(3500/	3500)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3500) factor[(2700/	3500),(3200/	3500)])";
			};
			class Idle_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_idle", 0.223872, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(200/	3500),(580/	3500)])*0.15";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(200/	3500),(350/	3500)])	*	((rpm/	3500) factor[(580/	3500),(400/	3500)]))";
			};
			class Engine_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm1", 0.251189, 1};
				frequency = "0.9	+	((rpm/	3500) factor[(380/	3500),(960/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(380/	3500),(580/	3500)])	*	((rpm/	3500) factor[(960/	3500),(700/	3500)]))";
			};
			class Engine1_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm2", 0.177828, 1};
				frequency = "0.9	+	((rpm/	3500) factor[(700/	3500),(1400/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(700/	3500),(970/	3500)])	*	((rpm/	3500) factor[(1400/	3500),(1100/	3500)]))";
			};
			class Engine2_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm3", 0.316228, 1};
				frequency = "0.9	+	((rpm/	3500) factor[(1100/	3500),(1860/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(1100/	3500),(1430/	3500)])	*	((rpm/	3500) factor[(1860/	3500),(1570/	3500)]))";
			};
			class Engine3_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm4", 0.354813, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(1600/	3500),(2200/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(1600/	3500),(1860/	3500)])	*	((rpm/	3500) factor[(2200/	3500),(2050/	3500)]))";
			};
			class Engine4_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm5", 0.398107, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(2040/	3500),(2670/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(2040/	3500),(2200/	3500)])	*	((rpm/	3500) factor[(2670/	3500),(2400/	3500)]))";
			};
			class Engine5_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm6", 0.398107, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(2400/	3500),(3050/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	3500) factor[(2400/	3500),(2660/	3500)])	*	((rpm/	3500) factor[(3050/	3500),(2800/	3500)]))";
			};
			class Engine6_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\engine_int_rpm7", 0.446684, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(2700/	3500),(3500/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*((rpm/	3500) factor[(2700/	3500),(3200/	3500)])";
			};
			class IdleThrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_idle", 0.316228, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(200/	3500),(580/	3500)])*0.15";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(200/	3500),(350/	3500)])	*	((rpm/	3500) factor[(580/	3500),(400/	3500)]))";
			};
			class EngineThrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm1", 0.354813, 1};
				frequency = "0.9	+	((rpm/	3500) factor[(380/	3500),(960/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(380/	3500),(580/	3500)])	*	((rpm/	3500) factor[(960/	3500),(700/	3500)]))";
			};
			class Engine1_Thrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm2", 0.398107, 1};
				frequency = "0.9	+	((rpm/	3500) factor[(700/	3500),(1400/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(700/	3500),(970/	3500)])	*	((rpm/	3500) factor[(1400/	3500),(1100/	3500)]))";
			};
			class Engine2_Thrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm3", 0.446684, 1};
				frequency = "0.9	+	((rpm/	3500) factor[(1100/	3500),(1860/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(1100/	3500),(1430/	3500)])	*	((rpm/	3500) factor[(1860/	3500),(1570/	3500)]))";
			};
			class Engine3_Thrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm4", 0.501187, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(1600/	3500),(2200/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(1600/	3500),(1860/	3500)])	*	((rpm/	3500) factor[(2200/	3500),(2050/	3500)]))";
			};
			class Engine4_Thrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm5", 0.562341, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(2040/	3500),(2670/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(2040/	3500),(2200/	3500)])	*	((rpm/	3500) factor[(2670/	3500),(2400/	3500)]))";
			};
			class Engine5_Thrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm6", 0.630957, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(2400/	3500),(3050/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	3500) factor[(2400/	3500),(2660/	3500)])	*	((rpm/	3500) factor[(3050/	3500),(2800/	3500)]))";
			};
			class Engine6_Thrust_int {
				sound[] = {"A3\Sounds_F\vehicles\soft\Offroad_01\exhaust_int_rpm7", 0.707946, 1};
				frequency = "0.95	+	((rpm/	3500) factor[(2700/	3500),(3500/	3500)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	3500) factor[(2700/	3500),(3200/	3500)])";
			};
			class TiresRockOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", 0.707946, 1, 60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", 0.707946, 1, 60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", 0.707946, 1, 60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", 0.707946, 1, 60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", 0.707946, 1, 60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", 0.707946, 1, 60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut {
				sound[] = {"A3\Sounds_F\vehicles\softoisesoise_ext_car_3", 0.562341, 1, 90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", 0.707946, 1};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", 0.707946, 1};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", 0.707946, 1};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", 0.707946, 1};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", 0.707946, 1};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn {
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", 0.707946, 1};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn {
				sound[] = {"A3\Sounds_F\vehicles\softoisesoise_int_car_3", 0.158489, 1};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_04", 0.707946, 1, 80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_02", 0.707946, 1, 80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_02", 0.707946, 1, 80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_ext_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_02", 0.707946, 1, 80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class breaking_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_14_dirt_breaking", 0.707946, 1, 60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_16_dirt_acceleration", 0.707946, 1, 60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_18_dirt", 0.707946, 1, 60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_ext_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_18_dirt", 0.707946, 1, 60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class breaking_int_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_04_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_int_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_02_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_int_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_02_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_int_road {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_loop_02_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class breaking_int_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_14_dirt_breaking_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_int_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_16_dirt_acceleration_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_int_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_18_dirt_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_int_dirt {
				sound[] = {"A3\Sounds_F\vehicles\softoises\slipping_tires_18_dirt_int", 0.316228, 1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
		};
		class RenderTargets {
			class LeftMirror {
				renderTarget = "rendertarget0";
				class CameraView1 {
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 0.7;
				};
			};
			class IntMirror {
				renderTarget = "rendertarget1";
				class CameraView1 {
					pointPosition = "PIP1_pos";
					pointDirection = "PIP1_dir";
					renderQuality = 2;
					renderVisionMode = 0;
					fov = 0.7;
				};
			};
		};
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "drivewheel";
		thrustDelay = 0.5;
		brakeIdleSpeed = 1.78;
		maxSpeed = 200;
		fuelCapacity = 45;
		wheelCircumference = 2.805;
		antiRollbarForceCoef = 1.9;
		antiRollbarForceLimit = 5;
		antiRollbarSpeedMin = 10;
		antiRollbarSpeedMax = 150;
		idleRpm = 400;
		redRpm = 3500;
		class complexGearbox {
			GearboxRatios[] = {"R1", -4, "N", 0, "D1", "4.5*(0.58^0)", "D2", "4.5*(0.58^1)", "D3", "4.5*(0.58^2)", "D4", "4.5*(0.58^3)", "D5", "4.5*(0.59^4)", "D6", "4.5*(0.6^5)"};
			TransmissionRatios[] = {"High", 7};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
			gearUpMaxCoef = 0.95;
			gearDownMaxCoef = 0.85;
			gearUpMinCoef = 0.65;
			gearDownMinCoef = 0.55;
			transmissionDelay = 2;
		};
		simulation = "carx";
		dampersBumpCoef = 3;
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.5;
		rearBias = 1.5;
		centreBias = 1.3;
		clutchStrength = 20;
		enginePower = 150;
		maxOmega = 450;
		peakTorque = 425;
		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 0.5;
		dampingRateZeroThrottleClutchDisengaged = 0.35;
		torqueCurve[] = {{"(0/3500)", "(0/425)"}, {"(500/3500)", "(200/425)"}, {"(1500/3500)", "(405/425)"}, {"(2000/3500)", "(425/425)"}, {"(2500/3500)", "(350/425)"}, {"(3000/3500)", "(300/425)"}, {"(6000/3500)", "(0/425)"}};
		changeGearMinEffectivity[] = {1, 0.15, 1, 1, 1, 1, 1, 1};
		switchTime = 0.31;
		latency = 1.5;
		class Wheels {
			class LF {
				boneName = "wheel_1_1_damper";
				steering = 1;
				side = "left";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				width = "0.2";
				mass = 30;
				MOI = 6;
				dampingRate = 1;
				dampingRateDamaged = 5;
				dampingRateInAir = 0.8;
				dampingRateDestroyed = 5000;
				maxBrakeTorque = 2000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0, -1, 0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.1;
				maxDroop = 0.05;
				sprungMass = 400;
				springStrength = 14400;
				springDamperRate = "1920*2";
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.5;
				latStiffY = 18;
				frictionVsSlipGraph[] = {{0, 1.75}, {0.5, 1.35}, {1, 1.2}};
			};
			class LR: LF {
				boneName = "wheel_1_2_damper";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3000;
				frictionVsSlipGraph[] = {{0, 2}, {0.5, 1.53}, {1, 1.36}};
				// LF
				side = "left";
				width = "0.2";
				mass = 30;
				MOI = 6;
				dampingRate = 1;
				dampingRateDamaged = 5;
				dampingRateInAir = 0.8;
				dampingRateDestroyed = 5000;
				maxBrakeTorque = 2000;
				suspTravelDirection[] = {0, -1, 0};
				maxCompression = 0.1;
				maxDroop = 0.05;
				sprungMass = 400;
				springStrength = 14400;
				springDamperRate = "1920*2";
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.5;
				latStiffY = 18;
			};
			class RF: LF {
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				steering = 1;
				side = "right";
				// LF
				width = "0.2";
				mass = 30;
				MOI = 6;
				dampingRate = 1;
				dampingRateDamaged = 5;
				dampingRateInAir = 0.8;
				dampingRateDestroyed = 5000;
				maxBrakeTorque = 2000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0, -1, 0};
				maxCompression = 0.1;
				maxDroop = 0.05;
				sprungMass = 400;
				springStrength = 14400;
				springDamperRate = "1920*2";
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.5;
				latStiffY = 18;
				frictionVsSlipGraph[] = {{0, 1.75}, {0.5, 1.35}, {1, 1.2}};
			};
			class RR: RF {
				boneName = "wheel_2_2_damper";
				steering = 0;
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 3000;
				frictionVsSlipGraph[] = {{0, 2.3}, {0.5, 2.1}, {1, 2}};
				// RF
				side = "right";
				// LF
				width = "0.2";
				mass = 30;
				MOI = 6;
				dampingRate = 1;
				dampingRateDamaged = 5;
				dampingRateInAir = 0.8;
				dampingRateDestroyed = 5000;
				maxBrakeTorque = 2000;
				suspTravelDirection[] = {0, -1, 0};
				maxCompression = 0.1;
				maxDroop = 0.05;
				sprungMass = 400;
				springStrength = 14400;
				springDamperRate = "1920*2";
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.5;
				latStiffY = 18;
			};
		};
		class Exhausts {
			class Exhaust1 {
				position = "exhaust1_pos";
				direction = "exhaust1_dir";
				effect = "ExhaustEffectOffroad";
			};
			class Exhaust2 {
				position = "exhaust2_pos";
				direction = "exhaust2_dir";
				effect = "ExhaustEffectOffroad";
			};
		};
		class Damage {
			tex[] = {};
			mat[] = {"A3\soft_F\Offroad_01\Data\Offroad_01_ext.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_ext_damage.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_ext_destruct.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_int_base.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_int_base_damage.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_int_base_destruct.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_int_board.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_int_board_damage.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_int_board_destruct.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_ext_plastic.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_ext_damage.rvmat", "A3\soft_F\Offroad_01\Data\Offroad_01_ext_destruct.rvmat", "A3\data_f\glass_veh.rvmat", "A3\data_f\Glass_veh_damage.rvmat", "A3\data_f\Glass_veh_damage.rvmat", "A3\data_f\glass_veh_int.rvmat", "A3\data_f\Glass_veh_damage.rvmat", "A3\data_f\Glass_veh_damage.rvmat"};
		};
		class Reflectors {
			class Left {
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				position = "Light_L";
				direction = "Light_L_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 0;
				dayLight = 0;
				flareSize = 1;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 60;
					hardLimitEnd = 120;
				};
			};
			class Right: Left {
				position = "Light_R";
				direction = "Light_R_end";
				hitpoint = "Light_R";
				selection = "Light_R";
				// Left
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 0;
				dayLight = 0;
				flareSize = 1;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 60;
					hardLimitEnd = 120;
				};
			};
			class Right2: Right {
				position = "light_R_flare";
				useFlare = 1;
				// Right
				direction = "Light_R_end";
				hitpoint = "Light_R";
				selection = "Light_R";
				// Left
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				dayLight = 0;
				flareSize = 1;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 60;
					hardLimitEnd = 120;
				};
			};
			class Left2: Left {
				position = "light_L_flare";
				useFlare = 1;
				// Left
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				direction = "Light_L_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				dayLight = 0;
				flareSize = 1;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 60;
					hardLimitEnd = 120;
				};
			};
			class Right3: Right2 {
				position = "light_R_flare2";
				flareSize = 0.3;
				// Right2
				useFlare = 1;
				// Right
				direction = "Light_R_end";
				hitpoint = "Light_R";
				selection = "Light_R";
				// Left
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				dayLight = 0;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 60;
					hardLimitEnd = 120;
				};
			};
			class Left3: Left2 {
				position = "light_L_flare2";
				flareSize = 0.3;
				// Left2
				useFlare = 1;
				// Left
				color[] = {1900, 1800, 1700};
				ambient[] = {5, 5, 5};
				direction = "Light_L_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				dayLight = 0;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 60;
					hardLimitEnd = 120;
				};
			};
		};
		aggregateReflectors[] = {{"Left", "Right", "Left2", "Right2", "Left3", "Right3"}};
		class UserActions: Desolation_Vehicle_Actions {
			class beacons_start {
				userActionID = 50;
				displayName = "Beacons On";
				displayNameDefault = "Beacons On";
				position = "temp";
				priority = 1.5;
				radius = 2;
				animPeriod = 2;
				onlyForplayer = 0;
				condition = "this animationPhase ""BeaconsStart"" < 0.5 AND Alive this AND driver this == player AND this animationPhase ""hidePolice"" < 0.5";
				statement = "this animate [""BeaconsStart"",1];";
			};
			class beacons_stop: beacons_start {
				userActionID = 51;
				displayName = "Beacons Off";
				displayNameDefault = "Beacons Off";
				condition = "this animationPhase ""BeaconsStart"" > 0.5 AND Alive this AND driver this == player AND this animationPhase ""hidePolice"" < 0.5";
				statement = "this animate [""BeaconsStart"",0];";
				// beacons_start
				position = "temp";
				priority = 1.5;
				radius = 2;
				animPeriod = 2;
				onlyForplayer = 0;
			};
		};
		// Car_F
		occludeSoundsWhenIn = 0;
		obstructSoundsWhenIn = 0;
		secondaryExplosion = -10;
		dammageHalf[] = {};
		dammageFull[] = {};
		armorStructural = 4;
		explosionShielding = 1;
		minTotalDamageThreshold = 0.01;
		crewCrashProtection = 2.75;
		crewExplosionProtection = 0.95;
		gunnerHasFlares = 0;
		steerAheadSimul = 0.5;
		steerAheadPlan = 0.35;
		predictTurnPlan = 2;
		predictTurnSimul = 1.5;
		terrainCoef = 2;
		maxFordingDepth = 0.5;
		waterResistance = 1;
		epeImpulseDamageCoef = 15;
		class ViewPilot {
			minFov = 0.25;
			maxFov = 1.25;
			initFov = 0.75;
			initAngleX = 0;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
			minMoveX = 0;
			maxMoveX = 0;
			minMoveY = 0;
			maxMoveY = 0;
			minMoveZ = 0;
			maxMoveZ = 0;
		};
		driverLeftLegAnimName = "";
		driverRightLegAnimName = "pedal_thrust";
		holdOffroadFormation = 1;
		waterLeakiness = 10;
		class NVGMarkers {
			class NVGMarker01 {
				name = "nvg_marker";
				color[] = {0.03, 0.003, 0.003, 1};
				ambient[] = {0.003, 0.0003, 0.0003, 1};
				brightness = 0.001;
				blinking = 1;
			};
		};
		viewCargoShadowDiff = 1;
		viewCargoShadowAmb = 1;
		magazines[] = {};
		threat[] = {0, 0, 0};
		insideSoundCoef = 0.9;
		soundEnviron[] = {"", 0.000562341, 1};
		soundCrash[] = {"A3\sounds_f\dummysound", 1, 1};
		extCameraPosition[] = {0.5, 2, -10};
		soundGear[] = {"", 1e-005, 1};
		collisionEffect = "collisionEffect";
		hideUnitInfo = 0;
		htMin = 60;
		htMax = 1800;
		afMax = 100;
		mfMax = 80;
		mFact = 1;
		tBody = 150;
		transportMaxWeapons = 12;
		transportMaxMagazines = 64;
		supplyRadius = -1;
		memoryPointSupply = "doplnovani";
		class TransportBackpacks {};
		class TransportMagazines {};
		class TransportWeapons {};
		brakeTorque = 6000;
		longStiff = 15000;
		latStiffX = 2000;
		latStiffY = 18000;
		wheelMask = "wheel_X_X";
		numberPhysicalWheels = 4;
		// Car
		unloadInCombat = 1;
		canFloat = 0;
		driverCanSee = "4+8+2+32";
		gunnerCanSee = "4+2+8+32";
		class PlateInfos {
			name = "spz";
			color[] = {0, 0, 0, 0.75};
		};
		selectionFireAnim = "zasleh";
		alphaTracks = 0.2;
		memoryPointTrackFLL = "Stopa PLL";
		memoryPointTrackFLR = "Stopa PLP";
		memoryPointTrackBLL = "Stopa ZLL";
		memoryPointTrackBLR = "Stopa ZLP";
		memoryPointTrackFRL = "Stopa PPL";
		memoryPointTrackFRR = "Stopa PPP";
		memoryPointTrackBRL = "Stopa ZPL";
		memoryPointTrackBRR = "Stopa ZPP";
		memoryPointCirculumReference = "circulumReference";
		gearBox[] = {-8, 0, 10, 6.15, 4.44, 3.33};
		Scudeffect = "ScudEffect";
		vehicleClass = "Car";
		waterSpeedFactor = 0.2;
		preferRoads = 1;
		formationX = 20;
		formationZ = 20;
		type = 0;
		typicalCargo[] = {"Soldier"};
		audible = 3;
		scudModel = "";
		damperSize = 0.1;
		damperForce = 1;
		damperDamping = 1;
		inputTurnCurve[] = {{0, {0, 0, 1, 1}}, {30, {0, 0, 0.2, 0.008, 0.4, 0.032, 0.6, 0.216, 0.8, 0.512, 1, 1}}};
		enableGPS = 0;
		soundEngine[] = {"", 1.77828, 0.9};
		class SpeechVariants {
			class Default {
				speechSingular[] = {"veh_vehicle_car_s"};
				speechPlural[] = {"veh_vehicle_car_p"};
			};
		};
		textSingular = "car";
		textPlural = "cars";
		memoryPointTaskMarkerOffset[] = {0, 0.3, 0};
		rightDustEffects[] = {{"GdtGrassShort", "RDustEffects"}, {"GdtGrassShort", "RGrassEffects"}, {"GdtGrassTall", "RDustEffects"}, {"GdtGrassTall", "RGrassEffects"}, {"GdtRedDirt", "RDustEffectsRed"}, {"GdtField", "RDustEffects"}, {"GdtForest", "RDustEffects"}, {"GdtVolcano", "RDustEffects"}, {"GdtVolcano", "RStonesEffects"}, {"GdtCliff", "RDustEffects"}, {"GdtVolcanoBeach", "RDustEffects"}, {"SurfRoadDirt_exp", "RDustEffectsRed"}, {"SurfRoadConcrete_exp", "RDustEffects"}, {"SurfRoadTarmac_exp", "RDustEffects"}, {"GdtStratisConcrete", "RDustEffects"}, {"GdtStratisConcrete", "RDirtEffects"}, {"GdtStratisBeach", "RDustEffects"}, {"GdtStratisBeach", "RStonesEffects"}, {"GdtStratisDirt", "RDustEffects"}, {"GdtStratisDirt", "RDirtEffects"}, {"GdtStratisSeabedCluttered", "RDustEffects"}, {"GdtStratisSeabed", "RDustEffects"}, {"GdtStratisDryGrass", "RDustEffects"}, {"GdtStratisDryGrass", "RGrassDryEffects"}, {"GdtStratisDryGrass", "RDirtEffects"}, {"GdtStratisGreenGrass", "RDustEffects"}, {"GdtStratisGreenGrass", "RGrassEffects"}, {"GdtStratisGreenGrass", "RDirtEffects"}, {"GdtStratisRocky", "RDustEffects"}, {"GdtStratisRocky", "RGrassEffects"}, {"GdtStratisRocky", "RDirtEffects"}, {"GdtStratisThistles", "RDustEffects"}, {"GdtStratisThistles", "RGrassEffects"}, {"GdtStratisThistles", "RDirtEffects"}, {"GdtConcrete", "RDustEffects"}, {"GdtConcrete", "RDirtEffects"}, {"GdtAsphalt", "RDustEffects"}, {"GdtAsphalt", "RDirtEffects"}, {"GdtRubble", "RDustEffects"}, {"GdtRubble", "RDirtEffects"}, {"GdtSoil", "RDustEffects"}, {"GdtSoil", "RDirtEffects"}, {"GdtBeach", "RDustEffects"}, {"GdtBeach", "RStonesEffects"}, {"GdtRock", "RDustEffects"}, {"GdtRock", "RDirtEffects"}, {"GdtDead", "RDustEffects"}, {"GdtDead", "RDirtEffects"}, {"Default", "RDustEffects"}, {"GdtDesert", "RDustEffects"}, {"GdtDesert", "RStonesEffects"}, {"GdtDesert1", "RDustEffects"}, {"GdtDesert1", "RSandEffects"}, {"GdtDesert1", "RDirtEffects"}, {"GdtDesert1", "RStonesEffects"}, {"GdtDesert2", "RDustEffects"}, {"GdtDesert2", "RSandEffects"}, {"GdtDesert2", "RGrassEffects"}, {"GdtDesert2", "RDirtEffects"}, {"GdtDirt", "RDustEffects"}, {"GdtDirt", "RDirtEffects"}, {"GdtGrassGreen", "RDustEffects"}, {"GdtGrassGreen", "RGrassEffects"}, {"GdtGrassGreen", "RDirtEffects"}, {"GdtGrassDry", "RDustEffects"}, {"GdtGrassDry", "RGrassDryEffects"}, {"GdtGrassDry", "RDirtEffects"}, {"GdtGrassWild", "RDustEffects"}, {"GdtGrassWild", "RGrassEffects"}, {"GdtGrassWild", "RDirtEffects"}, {"GdtWildField", "RDustEffects"}, {"GdtWildField", "RGrassEffects"}, {"GdtWildField", "RDirtEffects"}, {"GdtWeed1", "RDustEffects"}, {"GdtWeed1", "RGrassEffects"}, {"GdtWeed1", "RDirtEffects"}, {"GdtWeed2", "RDustEffects"}, {"GdtWeed2", "RGrassEffects"}, {"GdtWeed2", "RDirtEffects"}, {"GdtThorn", "RDustEffects"}, {"GdtThorn", "RGrassEffects"}, {"GdtThorn", "RDirtEffects"}, {"GdtStony", "RDustEffects"}, {"GdtStony", "RGrassEffects"}, {"GdtStony", "RDirtEffects"}, {"GdtStonyGreen", "RDustEffects"}, {"GdtStonyGreen", "RGrassEffects"}, {"GdtStonyGreen", "RDirtEffects"}, {"GdtStonyThistle", "RDustEffects"}, {"GdtStonyThistle", "RGrassEffects"}, {"GdtStonyThistle", "RDirtEffects"}, {"GdtSeabedDeep", "RDustEffects"}, {"GdtSeabed", "RDustEffects"}, {"SurfRoadDirt", "RDustEffects"}, {"SurfRoadConcrete", "RDustEffects"}, {"SurfRoadTarmac", "RDustEffects"}, {"SurfWood", "RDustEffects"}, {"SurfMetal", "RDustEffects"}, {"SurfRoofTin", "RDustEffects"}, {"SurfRoofTiles", "RDustEffects"}, {"SurfIntWood", "RDustEffects"}, {"SurfIntConcrete", "RDustEffects"}, {"SurfIntTiles", "RDustEffects"}, {"SurfIntMetal", "RDustEffects"}, {"dirtrunway", "RDustEffects"}};
		leftDustEffects[] = {{"GdtGrassShort", "LDustEffects"}, {"GdtGrassShort", "LGrassEffects"}, {"GdtGrassTall", "LDustEffects"}, {"GdtGrassTall", "LGrassEffects"}, {"GdtRedDirt", "LDustEffectsRed"}, {"GdtField", "LDustEffects"}, {"GdtForest", "LDustEffects"}, {"GdtVolcano", "LDustEffects"}, {"GdtVolcano", "LStonesEffects"}, {"GdtCliff", "LDustEffects"}, {"GdtVolcanoBeach", "LDustEffects"}, {"SurfRoadDirt_exp", "LDustEffectsRed"}, {"SurfRoadConcrete_exp", "LDustEffects"}, {"SurfRoadTarmac_exp", "LDustEffects"}, {"GdtStratisConcrete", "LDustEffects"}, {"GdtStratisConcrete", "LDirtEffects"}, {"GdtStratisBeach", "LDustEffects"}, {"GdtStratisBeach", "LStonesEffects"}, {"GdtStratisDirt", "LDustEffects"}, {"GdtStratisDirt", "LDirtEffects"}, {"GdtStratisSeabedCluttered", "LDustEffects"}, {"GdtStratisSeabed", "LDustEffects"}, {"GdtStratisDryGrass", "LDustEffects"}, {"GdtStratisDryGrass", "LGrassDryEffects"}, {"GdtStratisDryGrass", "LDirtEffects"}, {"GdtStratisGreenGrass", "LDustEffects"}, {"GdtStratisGreenGrass", "LGrassEffects"}, {"GdtStratisGreenGrass", "LDirtEffects"}, {"GdtStratisRocky", "LDustEffects"}, {"GdtStratisRocky", "LGrassEffects"}, {"GdtStratisRocky", "LDirtEffects"}, {"GdtStratisThistles", "LDustEffects"}, {"GdtStratisThistles", "LGrassEffects"}, {"GdtStratisThistles", "LDirtEffects"}, {"GdtConcrete", "LDustEffects"}, {"GdtConcrete", "LDirtEffects"}, {"GdtAsphalt", "LDustEffects"}, {"GdtAsphalt", "LDirtEffects"}, {"GdtRubble", "LDustEffects"}, {"GdtRubble", "LGrassEffects"}, {"GdtRubble", "LDirtEffects"}, {"GdtSoil", "LDustEffects"}, {"GdtSoil", "LDirtEffects"}, {"GdtBeach", "LDustEffects"}, {"GdtBeach", "LStonesEffects"}, {"GdtRock", "LDustEffects"}, {"GdtRock", "LDirtEffects"}, {"GdtDead", "LDustEffects"}, {"GdtDead", "LDirtEffects"}, {"Default", "LDustEffects"}, {"GdtDesert", "LDustEffects"}, {"GdtDesert", "LStonesEffects"}, {"GdtDesert1", "LDustEffects"}, {"GdtDesert1", "LSandEffects"}, {"GdtDesert1", "LDirtEffects"}, {"GdtDesert1", "LStonesEffects"}, {"GdtDesert2", "LDustEffects"}, {"GdtDesert2", "LSandEffects"}, {"GdtDesert2", "LGrassEffects"}, {"GdtDesert2", "LDirtEffects"}, {"GdtDirt", "LDustEffects"}, {"GdtDirt", "LDirtEffects"}, {"GdtGrassGreen", "LDustEffects"}, {"GdtGrassGreen", "LGrassEffects"}, {"GdtGrassGreen", "LDirtEffects"}, {"GdtGrassDry", "LDustEffects"}, {"GdtGrassDry", "LGrassDryEffects"}, {"GdtGrassDry", "LDirtEffects"}, {"GdtGrassWild", "LDustEffects"}, {"GdtGrassWild", "LGrassEffects"}, {"GdtGrassWild", "LDirtEffects"}, {"GdtWildField", "LDustEffects"}, {"GdtWildField", "LGrassEffects"}, {"GdtWildField", "LDirtEffects"}, {"GdtWeed1", "LDustEffects"}, {"GdtWeed1", "LGrassEffects"}, {"GdtWeed1", "LDirtEffects"}, {"GdtWeed2", "LDustEffects"}, {"GdtWeed2", "LGrassEffects"}, {"GdtWeed2", "LDirtEffects"}, {"GdtThorn", "LDustEffects"}, {"GdtThorn", "LGrassEffects"}, {"GdtThorn", "LDirtEffects"}, {"GdtStony", "LDustEffects"}, {"GdtStony", "LGrassEffects"}, {"GdtStony", "LDirtEffects"}, {"GdtStonyGreen", "LDustEffects"}, {"GdtStonyGreen", "LGrassEffects"}, {"GdtStonyGreen", "LDirtEffects"}, {"GdtStonyThistle", "LDustEffects"}, {"GdtStonyThistle", "LGrassEffects"}, {"GdtStonyThistle", "LDirtEffects"}, {"GdtSeabedDeep", "LDustEffects"}, {"GdtSeabed", "LDustEffects"}, {"SurfRoadDirt", "LDustEffects"}, {"SurfRoadConcrete", "LDustEffects"}, {"SurfRoadTarmac", "LDustEffects"}, {"SurfWood", "LDustEffects"}, {"SurfMetal", "LDustEffects"}, {"SurfRoofTin", "LDustEffects"}, {"SurfRoofTiles", "LDustEffects"}, {"SurfIntWood", "LDustEffects"}, {"SurfIntConcrete", "LDustEffects"}, {"SurfIntTiles", "LDustEffects"}, {"SurfIntMetal", "LDustEffects"}, {"dirtrunway", "LDustEffects"}};
		class DestructionEffects {
			class Light1 {
				simulation = "light";
				type = "ObjectDestructionLight";
				position = "destructionEffect1";
				intensity = 0.001;
				interval = 1;
				lifeTime = 3;
				enabled = "distToWater";
			};
			class Sound {
				simulation = "sound";
				position = "destructionEffect1";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
				type = "Fire";
			};
			class Fire1 {
				simulation = "particles";
				type = "ObjectDestructionFire1Small";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3;
			};
			class Refract1 {
				simulation = "particles";
				type = "ObjectDestructionRefractSmall";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3;
			};
			class Smoke1 {
				simulation = "particles";
				type = "ObjectDestructionSmokeSmall";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3.5;
			};
			class Sparks1 {
				simulation = "particles";
				type = "ObjectDestructionSparks";
				position = "destructionEffect1";
				intensity = 0;
				interval = 1;
				lifeTime = 0;
			};
			class FireSparks1 {
				simulation = "particles";
				type = "FireSparks";
				position = "destructionEffect2";
				intensity = 1;
				interval = 1;
				lifeTime = 2.8;
			};
			class Fire2 {
				simulation = "particles";
				type = "ObjectDestructionFire2Small";
				position = "destructionEffect2";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3;
			};
			class Smoke1_2 {
				simulation = "particles";
				type = "ObjectDestructionSmoke1_2Small";
				position = "destructionEffect2";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3.5;
			};
			class Smoke2 {
				simulation = "particles";
				type = "ObjectDestructionSmoke2";
				position = "destructionEffect2";
				intensity = 1;
				interval = 1;
				lifeTime = 3.2;
			};
		};
		sensitivityEar = 0.125;
		sensitivity = 1.75;
		// LandVehicle
		class Components {
			class TransportCountermeasuresComponent {};
		};
		selectionBrakeLights = "brzdove svetlo";
		memoryPointMissile[] = {"spice rakety", "usti hlavne"};
		memoryPointMissileDir[] = {"konec rakety", "konec hlavne"};
		engineStartSpeed = 1.5;
		leftDustEffect = "LDustEffects";
		rightDustEffect = "RDustEffects";
		leftWaterEffect = "LWaterEffects";
		rightWaterEffect = "RWaterEffects";
		leftFastWaterEffect = "LWaterEffects";
		rightFastWaterEffect = "RWaterEffects";
		tracksSpeed = 0;
		selectionLeftOffset = "PasOffsetL";
		selectionRightOffset = "PasOffsetP";
		explosionEffect = "FuelExplosion";
		class CommanderOptics {
			proxyType = "CPCommander";
			proxyIndex = 1;
			gunnerName = "Commander";
			primaryGunner = 0;
			primaryObserver = 1;
			stabilizedInAxes = 0;
			body = "obsTurret";
			gun = "obsGun";
			animationSourceBody = "obsTurret";
			animationSourceGun = "obsGun";
			animationSourceHatch = "hatchCommander";
			animationSourceCamElev = "camElev";
			soundServo[] = {"A3\sounds_f\dummysound", 0.01, 1, 10};
			gunBeg = "";
			gunEnd = "";
			minElev = -4;
			maxElev = 20;
			initElev = 0;
			minTurn = -360;
			maxTurn = 360;
			initTurn = 0;
			commanding = 2;
			outGunnerMayFire = 1;
			inGunnerMayFire = 1;
			viewGunnerInExternal = 0;
			gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
			gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
			gunnerOutOpticsColor[] = {0, 0, 0, 1};
			gunnerOutForceOptics = 0;
			gunnerOutOpticsShowCursor = 0;
			gunnerOpticsEffect[] = {};
			gunnerOutOpticsEffect[] = {};
			memoryPointGunnerOutOptics = "commander_weapon_view";
			memoryPointGunnerOptics = "commanderview";
			memoryPointsGetInGunner = "pos commander";
			memoryPointsGetInGunnerDir = "pos commander dir";
			gunnerGetInAction = "GetInHigh";
			gunnerGetOutAction = "GetOutHigh";
			memoryPointGun = "gun_muzzle";
			selectionFireAnim = "zasleh_1";
			class ViewOptics {
				initAngleX = 0;
				minAngleX = -30;
				maxAngleX = 30;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				initFov = 0.3;
				minFov = 0.07;
				maxFov = 0.35;
				minMoveX = 0;
				maxMoveX = 0;
				minMoveY = 0;
				maxMoveY = 0;
				minMoveZ = 0;
				maxMoveZ = 0;
			};
			class ViewGunner {
				// ViewCargo
				initAngleX = 5;
				minAngleX = -75;
				maxAngleX = 85;
				initAngleY = 0;
				minAngleY = -150;
				maxAngleY = 150;
				minFov = 0.25;
				maxFov = 1.25;
				initFov = 0.75;
				minMoveX = 0;
				maxMoveX = 0;
				minMoveY = 0;
				maxMoveY = 0;
				minMoveZ = 0;
				maxMoveZ = 0;
			};
			// NewTurret
			gunnerType = "";
			weapons[] = {};
			magazines[] = {};
			soundElevation[] = {"", 1, 1};
			particlesPos = "usti hlavne";
			particlesDir = "konec hlavne";
			minOutElev = -4;
			maxOutElev = 20;
			initOutElev = 0;
			minOutTurn = -60;
			maxOutTurn = 60;
			initOutTurn = 0;
			maxHorizontalRotSpeed = 1.2;
			maxVerticalRotSpeed = 1.2;
			primary = 1;
			hasGunner = 1;
			turretCanSee = 0;
			canUseScanners = 1;
			class TurretSpec {
				showHeadPhones = 0;
			};
			gunnerOpticsColor[] = {0, 0, 0, 1};
			gunnerForceOptics = 1;
			gunnerOpticsShowCursor = 0;
			turrentInfoType = "";
			gunnerFireAlsoInInternalCamera = 1;
			gunnerOutFireAlsoInInternalCamera = 1;
			gunnerUsesPilotView = 0;
			castGunnerShadow = 0;
			viewGunnerShadow = 1;
			viewGunnerShadowDiff = 1;
			viewGunnerShadowAmb = 1;
			ejectDeadGunner = 0;
			hideWeaponsGunner = 1;
			canHideGunner = -1;
			forceHideGunner = 0;
			showHMD = 0;
			lockWhenDriverOut = 0;
			lockWhenVehicleSpeed = -1;
			gunnerCompartments = "Compartment1";
			LODTurnedIn = -1;
			LODTurnedOut = -1;
			startEngine = 1;
			memoryPointsGetInGunnerPrecise = "";
			missileBeg = "spice rakety";
			missileEnd = "konec rakety";
			armorLights = 0.4;
			class Reflectors {};
			aggregateReflectors[] = {};
			class GunFire {
				// WeaponFireGun
				access = 0;
				cloudletDuration = 0.2;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 1;
				cloudletGrowUp = 0.2;
				cloudletFadeIn = 0.01;
				cloudletFadeOut = 0.5;
				cloudletAccY = 0;
				cloudletMinYSpeed = -100;
				cloudletMaxYSpeed = 100;
				cloudletShape = "cloudletFire";
				cloudletColor[] = {1, 1, 1, 0};
				interval = 0.01;
				size = 3;
				sourceSize = 0.5;
				timeToLive = 0;
				initT = 4500;
				deltaT = -3000;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {0.82, 0.95, 0.93, 0};
					};
					class T1 {
						maxT = 200;
						color[] = {0.75, 0.77, 0.9, 0};
					};
					class T2 {
						maxT = 400;
						color[] = {0.56, 0.62, 0.67, 0};
					};
					class T3 {
						maxT = 600;
						color[] = {0.39, 0.46, 0.47, 0};
					};
					class T4 {
						maxT = 800;
						color[] = {0.24, 0.31, 0.31, 0};
					};
					class T5 {
						maxT = 1000;
						color[] = {0.23, 0.31, 0.29, 0};
					};
					class T6 {
						maxT = 1500;
						color[] = {0.21, 0.29, 0.27, 0};
					};
					class T7 {
						maxT = 2000;
						color[] = {0.19, 0.23, 0.21, 0};
					};
					class T8 {
						maxT = 2300;
						color[] = {0.22, 0.19, 0.1, 0};
					};
					class T9 {
						maxT = 2500;
						color[] = {0.35, 0.2, 0.02, 0};
					};
					class T10 {
						maxT = 2600;
						color[] = {0.62, 0.29, 0.03, 0};
					};
					class T11 {
						maxT = 2650;
						color[] = {0.59, 0.35, 0.05, 0};
					};
					class T12 {
						maxT = 2700;
						color[] = {0.75, 0.37, 0.03, 0};
					};
					class T13 {
						maxT = 2750;
						color[] = {0.88, 0.34, 0.03, 0};
					};
					class T14 {
						maxT = 2800;
						color[] = {0.91, 0.5, 0.17, 0};
					};
					class T15 {
						maxT = 2850;
						color[] = {1, 0.6, 0.2, 0};
					};
					class T16 {
						maxT = 2900;
						color[] = {1, 0.71, 0.3, 0};
					};
					class T17 {
						maxT = 2950;
						color[] = {0.98, 0.83, 0.41, 0};
					};
					class T18 {
						maxT = 3000;
						color[] = {0.98, 0.91, 0.54, 0};
					};
					class T19 {
						maxT = 3100;
						color[] = {0.98, 0.99, 0.6, 0};
					};
					class T20 {
						maxT = 3300;
						color[] = {0.96, 0.99, 0.72, 0};
					};
					class T21 {
						maxT = 3600;
						color[] = {1, 0.98, 0.91, 0};
					};
					class T22 {
						maxT = 4200;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			class GunClouds {
				// WeaponCloudsGun
				access = 0;
				cloudletDuration = 0.3;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 1;
				cloudletGrowUp = 1;
				cloudletFadeIn = 0.01;
				cloudletFadeOut = 1;
				cloudletAccY = 0.4;
				cloudletMinYSpeed = 0.2;
				cloudletMaxYSpeed = 0.8;
				cloudletShape = "cloudletClouds";
				cloudletColor[] = {1, 1, 1, 0};
				interval = 0.05;
				size = 3;
				sourceSize = 0.5;
				timeToLive = 0;
				initT = 0;
				deltaT = 0;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			class MGunClouds {
				// WeaponCloudsMGun
				access = 0;
				cloudletGrowUp = 0.05;
				cloudletFadeIn = 0;
				cloudletFadeOut = 0.1;
				cloudletDuration = 0.05;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 0.3;
				cloudletAccY = 0;
				cloudletMinYSpeed = -100;
				cloudletMaxYSpeed = 100;
				cloudletShape = "cloudletClouds";
				cloudletColor[] = {1, 1, 1, 0};
				timeToLive = 0;
				interval = 0.02;
				size = 0.3;
				sourceSize = 0.02;
				initT = 0;
				deltaT = 0;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			// NewTurret
			class HitPoints {
				class HitTurret {
					armor = 0.8;
					material = 51;
					name = "turret";
					visual = "turret";
					passThrough = 1;
					explosionShielding = 1;
				};
				class HitGun {
					armor = 0.6;
					material = 52;
					name = "gun";
					visual = "gun";
					passThrough = 1;
					explosionShielding = 1;
				};
			};
			class Turrets {};
			forceNVG = 0;
			isCopilot = 0;
			canEject = 1;
			gunnerLeftHandAnimName = "";
			gunnerRightHandAnimName = "";
			gunnerLeftLegAnimName = "";
			gunnerRightLegAnimName = "";
			gunnerDoor = "";
			preciseGetInOut = 0;
			turretFollowFreeLook = 0;
			allowTabLock = 1;
			showAllTargets = 0;
			dontCreateAI = 0;
			disableSoundAttenuation = 0;
			slingLoadOperator = 0;
			playerPosition = 0;
			allowLauncherIn = 0;
			allowLauncherOut = 0;
			class TurnIn {
				turnOffset = 0;
			};
			class TurnOut {
				// TurnIn
				turnOffset = 0;
			};
			gunnerInAction = "ManActTestDriver";
			gunnerAction = "ManActTestDriver";
			showCrewAim = 0;
		};
		// Land
		wheelDamageThreshold = 0.2;
		wheelDestroyThreshold = 0.99;
		wheelDamageRadiusCoef = 0.9;
		weaponsGroup1 = 1;
		weaponsGroup2 = "2 + 		4";
		weaponsGroup3 = "8 + 	16 + 	32";
		weaponsGroup4 = "64 + 		128";
		// AllVehicles
		class SquadTitles {
			name = "clan_sign";
			color[] = {0, 0, 0, 0.75};
		};
		memoryPointDriverOptics[] = {"driverview", "pilot"};
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		memoryPointsGetInCoDriver = "pos codriver";
		memoryPointsGetInCoDriverDir = "pos codriver dir";
		memoryPointsGetInDriverPrecise = "pos driver";
		memoryPointsGetInCargoPrecise[] = {"pos cargo"};
		memoryPointsLeftWaterEffect = "waterEffectL";
		memoryPointsRightWaterEffect = "waterEffectR";
		selectionClan = "clan";
		selectionDashboard = "podsvit pristroju";
		selectionShowDamage = "poskozeni";
		selectionBackLights = "zadni svetlo";
		class NewTurret {
			body = "mainTurret";
			gun = "mainGun";
			animationSourceBody = "mainTurret";
			animationSourceGun = "mainGun";
			animationSourceHatch = "hatchGunner";
			animationSourceCamElev = "camElev";
			proxyType = "CPGunner";
			proxyIndex = 1;
			gunnerName = "Gunner";
			gunnerType = "";
			primaryGunner = 1;
			primaryObserver = 0;
			weapons[] = {};
			magazines[] = {};
			soundServo[] = {"", 0.00316228, 1};
			soundElevation[] = {"", 1, 1};
			particlesPos = "usti hlavne";
			particlesDir = "konec hlavne";
			minElev = -4;
			maxElev = 20;
			initElev = 0;
			minTurn = -360;
			maxTurn = 360;
			initTurn = 0;
			minOutElev = -4;
			maxOutElev = 20;
			initOutElev = 0;
			minOutTurn = -60;
			maxOutTurn = 60;
			initOutTurn = 0;
			maxHorizontalRotSpeed = 1.2;
			maxVerticalRotSpeed = 1.2;
			stabilizedInAxes = 3;
			primary = 1;
			hasGunner = 1;
			commanding = 1;
			gunnerGetInAction = "";
			gunnerGetOutAction = "";
			turretCanSee = 0;
			canUseScanners = 1;
			class ViewGunner {
				initAngleX = 5;
				minAngleX = -75;
				maxAngleX = 85;
				initAngleY = 0;
				minAngleY = -150;
				maxAngleY = 150;
				minFov = 0.25;
				maxFov = 1.25;
				initFov = 0.75;
				minMoveX = 0;
				maxMoveX = 0;
				minMoveY = 0;
				maxMoveY = 0;
				minMoveZ = 0;
				maxMoveZ = 0;
				continuous = 0;
			};
			// NewTurret
			class TurretSpec {
				showHeadPhones = 0;
			};
			gunnerOpticsModel = "";
			gunnerOpticsColor[] = {0, 0, 0, 1};
			gunnerForceOptics = 1;
			gunnerOpticsShowCursor = 0;
			turrentInfoType = "";
			gunnerOutOpticsModel = "";
			gunnerOutOpticsColor[] = {0, 0, 0, 1};
			gunnerOpticsEffect[] = {};
			gunnerOutOpticsEffect[] = {};
			memoryPointGunnerOutOptics = "";
			gunnerOutForceOptics = 0;
			gunnerOutOpticsShowCursor = 0;
			gunnerFireAlsoInInternalCamera = 1;
			gunnerOutFireAlsoInInternalCamera = 1;
			gunnerUsesPilotView = 0;
			castGunnerShadow = 0;
			viewGunnerShadow = 1;
			viewGunnerShadowDiff = 1;
			viewGunnerShadowAmb = 1;
			ejectDeadGunner = 0;
			hideWeaponsGunner = 1;
			canHideGunner = -1;
			forceHideGunner = 0;
			outGunnerMayFire = 0;
			inGunnerMayFire = 1;
			showHMD = 0;
			viewGunnerInExternal = 0;
			lockWhenDriverOut = 0;
			lockWhenVehicleSpeed = -1;
			gunnerCompartments = "Compartment1";
			LODTurnedIn = -1;
			LODTurnedOut = -1;
			startEngine = 1;
			memoryPointsGetInGunnerPrecise = "";
			missileBeg = "spice rakety";
			missileEnd = "konec rakety";
			armorLights = 0.4;
			class Reflectors {};
			aggregateReflectors[] = {};
			class GunFire {
				// WeaponFireGun
				access = 0;
				cloudletDuration = 0.2;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 1;
				cloudletGrowUp = 0.2;
				cloudletFadeIn = 0.01;
				cloudletFadeOut = 0.5;
				cloudletAccY = 0;
				cloudletMinYSpeed = -100;
				cloudletMaxYSpeed = 100;
				cloudletShape = "cloudletFire";
				cloudletColor[] = {1, 1, 1, 0};
				interval = 0.01;
				size = 3;
				sourceSize = 0.5;
				timeToLive = 0;
				initT = 4500;
				deltaT = -3000;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {0.82, 0.95, 0.93, 0};
					};
					class T1 {
						maxT = 200;
						color[] = {0.75, 0.77, 0.9, 0};
					};
					class T2 {
						maxT = 400;
						color[] = {0.56, 0.62, 0.67, 0};
					};
					class T3 {
						maxT = 600;
						color[] = {0.39, 0.46, 0.47, 0};
					};
					class T4 {
						maxT = 800;
						color[] = {0.24, 0.31, 0.31, 0};
					};
					class T5 {
						maxT = 1000;
						color[] = {0.23, 0.31, 0.29, 0};
					};
					class T6 {
						maxT = 1500;
						color[] = {0.21, 0.29, 0.27, 0};
					};
					class T7 {
						maxT = 2000;
						color[] = {0.19, 0.23, 0.21, 0};
					};
					class T8 {
						maxT = 2300;
						color[] = {0.22, 0.19, 0.1, 0};
					};
					class T9 {
						maxT = 2500;
						color[] = {0.35, 0.2, 0.02, 0};
					};
					class T10 {
						maxT = 2600;
						color[] = {0.62, 0.29, 0.03, 0};
					};
					class T11 {
						maxT = 2650;
						color[] = {0.59, 0.35, 0.05, 0};
					};
					class T12 {
						maxT = 2700;
						color[] = {0.75, 0.37, 0.03, 0};
					};
					class T13 {
						maxT = 2750;
						color[] = {0.88, 0.34, 0.03, 0};
					};
					class T14 {
						maxT = 2800;
						color[] = {0.91, 0.5, 0.17, 0};
					};
					class T15 {
						maxT = 2850;
						color[] = {1, 0.6, 0.2, 0};
					};
					class T16 {
						maxT = 2900;
						color[] = {1, 0.71, 0.3, 0};
					};
					class T17 {
						maxT = 2950;
						color[] = {0.98, 0.83, 0.41, 0};
					};
					class T18 {
						maxT = 3000;
						color[] = {0.98, 0.91, 0.54, 0};
					};
					class T19 {
						maxT = 3100;
						color[] = {0.98, 0.99, 0.6, 0};
					};
					class T20 {
						maxT = 3300;
						color[] = {0.96, 0.99, 0.72, 0};
					};
					class T21 {
						maxT = 3600;
						color[] = {1, 0.98, 0.91, 0};
					};
					class T22 {
						maxT = 4200;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			class GunClouds {
				// WeaponCloudsGun
				access = 0;
				cloudletDuration = 0.3;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 1;
				cloudletGrowUp = 1;
				cloudletFadeIn = 0.01;
				cloudletFadeOut = 1;
				cloudletAccY = 0.4;
				cloudletMinYSpeed = 0.2;
				cloudletMaxYSpeed = 0.8;
				cloudletShape = "cloudletClouds";
				cloudletColor[] = {1, 1, 1, 0};
				interval = 0.05;
				size = 3;
				sourceSize = 0.5;
				timeToLive = 0;
				initT = 0;
				deltaT = 0;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			class MGunClouds {
				// WeaponCloudsMGun
				access = 0;
				cloudletGrowUp = 0.05;
				cloudletFadeIn = 0;
				cloudletFadeOut = 0.1;
				cloudletDuration = 0.05;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 0.3;
				cloudletAccY = 0;
				cloudletMinYSpeed = -100;
				cloudletMaxYSpeed = 100;
				cloudletShape = "cloudletClouds";
				cloudletColor[] = {1, 1, 1, 0};
				timeToLive = 0;
				interval = 0.02;
				size = 0.3;
				sourceSize = 0.02;
				initT = 0;
				deltaT = 0;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			// NewTurret
			class HitPoints {
				class HitTurret {
					armor = 0.8;
					material = 51;
					name = "turret";
					visual = "turret";
					passThrough = 1;
					explosionShielding = 1;
				};
				class HitGun {
					armor = 0.6;
					material = 52;
					name = "gun";
					visual = "gun";
					passThrough = 1;
					explosionShielding = 1;
				};
			};
			class Turrets {};
			class ViewOptics {
				initAngleX = 0;
				minAngleX = -30;
				maxAngleX = 30;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				initFov = 0.3;
				minFov = 0.07;
				maxFov = 0.35;
				minMoveX = 0;
				maxMoveX = 0;
				minMoveY = 0;
				maxMoveY = 0;
				minMoveZ = 0;
				maxMoveZ = 0;
			};
			forceNVG = 0;
			isCopilot = 0;
			canEject = 1;
			gunnerLeftHandAnimName = "";
			gunnerRightHandAnimName = "";
			gunnerLeftLegAnimName = "";
			gunnerRightLegAnimName = "";
			gunnerDoor = "";
			preciseGetInOut = 0;
			turretFollowFreeLook = 0;
			allowTabLock = 1;
			showAllTargets = 0;
			dontCreateAI = 0;
			disableSoundAttenuation = 0;
			slingLoadOperator = 0;
			playerPosition = 0;
			allowLauncherIn = 0;
			allowLauncherOut = 0;
			class TurnIn {
				turnOffset = 0;
			};
			class TurnOut {
				// TurnIn
				turnOffset = 0;
			};
			gunnerInAction = "ManActTestDriver";
			gunnerAction = "ManActTestDriver";
			gunBeg = "usti hlavne";
			gunEnd = "konec hlavne";
			memoryPointGunnerOptics = "gunnerview";
			memoryPointsGetInGunner = "pos gunner";
			memoryPointsGetInGunnerDir = "pos gunner dir";
			memoryPointGun = "kulas";
			selectionFireAnim = "zasleh";
			showCrewAim = 0;
		};
		class ViewCargo {
			initAngleX = 5;
			minAngleX = -75;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
			minFov = 0.25;
			maxFov = 1.25;
			initFov = 0.75;
			minMoveX = 0;
			maxMoveX = 0;
			minMoveY = 0;
			maxMoveY = 0;
			minMoveZ = 0;
			maxMoveZ = 0;
		};
		class ViewOptics {
			initAngleX = 0;
			minAngleX = -30;
			maxAngleX = 30;
			initAngleY = 0;
			minAngleY = -100;
			maxAngleY = 100;
			initFov = 0.7;
			minFov = 0.42;
			maxFov = 0.85;
			minMoveX = 0;
			maxMoveX = 0;
			minMoveY = 0;
			maxMoveY = 0;
			minMoveZ = 0;
			maxMoveZ = 0;
		};
		class PilotSpec {
			showHeadPhones = 0;
		};
		class CargoSpec {
			class Cargo1 {
				showHeadPhones = 0;
			};
		};
		class MFD {};
		class SoundEvents {};
		driverDoor = "";
		cargoDoors[] = {};
		hasTerminal = 0;
		getInOutOnProxy = 0;
		preciseGetInOut = 0;
		cargoPreciseGetInOut[] = {0};
		availableForSupportTypes[] = {};
		waterPPInVehicle = 1;
		impactEffectsSea = "ImpactEffectsSea";
		impactEffectSpeedLimit = 8;
		showCrewAim = 0;
		class CargoTurret {
			class ViewGunner {
				// ViewCargo
				initAngleX = 5;
				minAngleX = -75;
				maxAngleX = 85;
				initAngleY = 0;
				minAngleY = -150;
				maxAngleY = 150;
				minFov = 0.25;
				maxFov = 1.25;
				initFov = 0.75;
				minMoveX = 0;
				maxMoveX = 0;
				minMoveY = 0;
				maxMoveY = 0;
				minMoveZ = 0;
				maxMoveZ = 0;
			};
			animationSourceBody = "";
			animationSourceGun = "";
			body = "";
			canEject = 1;
			commanding = 0;
			dontCreateAI = 1;
			gun = "";
			gunnerGetInAction = "GetInLow";
			gunnerGetOutAction = "GetOutLow";
			gunnerName = "cargo";
			hideWeaponsGunner = 0;
			isCopilot = 0;
			memoryPointsGetInGunner = "pos cargo";
			memoryPointsGetInGunnerDir = "pos cargo dir";
			primaryGunner = 0;
			proxyType = "CPCargo";
			startEngine = 0;
			turretFollowFreeLook = 0;
			viewGunnerInExternal = 1;
			disableSoundAttenuation = 1;
			outGunnerMayFire = 1;
			isPersonTurret = 1;
			showAsCargo = 1;
			maxElev = 45;
			minElev = -45;
			maxTurn = 95;
			minTurn = -95;
			// NewTurret
			animationSourceHatch = "hatchGunner";
			animationSourceCamElev = "camElev";
			proxyIndex = 1;
			gunnerType = "";
			primaryObserver = 0;
			weapons[] = {};
			magazines[] = {};
			soundServo[] = {"", 0.00316228, 1};
			soundElevation[] = {"", 1, 1};
			particlesPos = "usti hlavne";
			particlesDir = "konec hlavne";
			initElev = 0;
			initTurn = 0;
			minOutElev = -4;
			maxOutElev = 20;
			initOutElev = 0;
			minOutTurn = -60;
			maxOutTurn = 60;
			initOutTurn = 0;
			maxHorizontalRotSpeed = 1.2;
			maxVerticalRotSpeed = 1.2;
			stabilizedInAxes = 3;
			primary = 1;
			hasGunner = 1;
			turretCanSee = 0;
			canUseScanners = 1;
			class TurretSpec {
				showHeadPhones = 0;
			};
			gunnerOpticsModel = "";
			gunnerOpticsColor[] = {0, 0, 0, 1};
			gunnerForceOptics = 1;
			gunnerOpticsShowCursor = 0;
			turrentInfoType = "";
			gunnerOutOpticsModel = "";
			gunnerOutOpticsColor[] = {0, 0, 0, 1};
			gunnerOpticsEffect[] = {};
			gunnerOutOpticsEffect[] = {};
			memoryPointGunnerOutOptics = "";
			gunnerOutForceOptics = 0;
			gunnerOutOpticsShowCursor = 0;
			gunnerFireAlsoInInternalCamera = 1;
			gunnerOutFireAlsoInInternalCamera = 1;
			gunnerUsesPilotView = 0;
			castGunnerShadow = 0;
			viewGunnerShadow = 1;
			viewGunnerShadowDiff = 1;
			viewGunnerShadowAmb = 1;
			ejectDeadGunner = 0;
			canHideGunner = -1;
			forceHideGunner = 0;
			inGunnerMayFire = 1;
			showHMD = 0;
			lockWhenDriverOut = 0;
			lockWhenVehicleSpeed = -1;
			gunnerCompartments = "Compartment1";
			LODTurnedIn = -1;
			LODTurnedOut = -1;
			memoryPointsGetInGunnerPrecise = "";
			missileBeg = "spice rakety";
			missileEnd = "konec rakety";
			armorLights = 0.4;
			class Reflectors {};
			aggregateReflectors[] = {};
			class GunFire {
				// WeaponFireGun
				access = 0;
				cloudletDuration = 0.2;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 1;
				cloudletGrowUp = 0.2;
				cloudletFadeIn = 0.01;
				cloudletFadeOut = 0.5;
				cloudletAccY = 0;
				cloudletMinYSpeed = -100;
				cloudletMaxYSpeed = 100;
				cloudletShape = "cloudletFire";
				cloudletColor[] = {1, 1, 1, 0};
				interval = 0.01;
				size = 3;
				sourceSize = 0.5;
				timeToLive = 0;
				initT = 4500;
				deltaT = -3000;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {0.82, 0.95, 0.93, 0};
					};
					class T1 {
						maxT = 200;
						color[] = {0.75, 0.77, 0.9, 0};
					};
					class T2 {
						maxT = 400;
						color[] = {0.56, 0.62, 0.67, 0};
					};
					class T3 {
						maxT = 600;
						color[] = {0.39, 0.46, 0.47, 0};
					};
					class T4 {
						maxT = 800;
						color[] = {0.24, 0.31, 0.31, 0};
					};
					class T5 {
						maxT = 1000;
						color[] = {0.23, 0.31, 0.29, 0};
					};
					class T6 {
						maxT = 1500;
						color[] = {0.21, 0.29, 0.27, 0};
					};
					class T7 {
						maxT = 2000;
						color[] = {0.19, 0.23, 0.21, 0};
					};
					class T8 {
						maxT = 2300;
						color[] = {0.22, 0.19, 0.1, 0};
					};
					class T9 {
						maxT = 2500;
						color[] = {0.35, 0.2, 0.02, 0};
					};
					class T10 {
						maxT = 2600;
						color[] = {0.62, 0.29, 0.03, 0};
					};
					class T11 {
						maxT = 2650;
						color[] = {0.59, 0.35, 0.05, 0};
					};
					class T12 {
						maxT = 2700;
						color[] = {0.75, 0.37, 0.03, 0};
					};
					class T13 {
						maxT = 2750;
						color[] = {0.88, 0.34, 0.03, 0};
					};
					class T14 {
						maxT = 2800;
						color[] = {0.91, 0.5, 0.17, 0};
					};
					class T15 {
						maxT = 2850;
						color[] = {1, 0.6, 0.2, 0};
					};
					class T16 {
						maxT = 2900;
						color[] = {1, 0.71, 0.3, 0};
					};
					class T17 {
						maxT = 2950;
						color[] = {0.98, 0.83, 0.41, 0};
					};
					class T18 {
						maxT = 3000;
						color[] = {0.98, 0.91, 0.54, 0};
					};
					class T19 {
						maxT = 3100;
						color[] = {0.98, 0.99, 0.6, 0};
					};
					class T20 {
						maxT = 3300;
						color[] = {0.96, 0.99, 0.72, 0};
					};
					class T21 {
						maxT = 3600;
						color[] = {1, 0.98, 0.91, 0};
					};
					class T22 {
						maxT = 4200;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			class GunClouds {
				// WeaponCloudsGun
				access = 0;
				cloudletDuration = 0.3;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 1;
				cloudletGrowUp = 1;
				cloudletFadeIn = 0.01;
				cloudletFadeOut = 1;
				cloudletAccY = 0.4;
				cloudletMinYSpeed = 0.2;
				cloudletMaxYSpeed = 0.8;
				cloudletShape = "cloudletClouds";
				cloudletColor[] = {1, 1, 1, 0};
				interval = 0.05;
				size = 3;
				sourceSize = 0.5;
				timeToLive = 0;
				initT = 0;
				deltaT = 0;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			class MGunClouds {
				// WeaponCloudsMGun
				access = 0;
				cloudletGrowUp = 0.05;
				cloudletFadeIn = 0;
				cloudletFadeOut = 0.1;
				cloudletDuration = 0.05;
				cloudletAnimPeriod = 1;
				cloudletSize = 1;
				cloudletAlpha = 0.3;
				cloudletAccY = 0;
				cloudletMinYSpeed = -100;
				cloudletMaxYSpeed = 100;
				cloudletShape = "cloudletClouds";
				cloudletColor[] = {1, 1, 1, 0};
				timeToLive = 0;
				interval = 0.02;
				size = 0.3;
				sourceSize = 0.02;
				initT = 0;
				deltaT = 0;
				class Table {
					class T0 {
						maxT = 0;
						color[] = {1, 1, 1, 0};
					};
				};
			};
			// NewTurret
			class HitPoints {
				class HitTurret {
					armor = 0.8;
					material = 51;
					name = "turret";
					visual = "turret";
					passThrough = 1;
					explosionShielding = 1;
				};
				class HitGun {
					armor = 0.6;
					material = 52;
					name = "gun";
					visual = "gun";
					passThrough = 1;
					explosionShielding = 1;
				};
			};
			class Turrets {};
			class ViewOptics {
				initAngleX = 0;
				minAngleX = -30;
				maxAngleX = 30;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				initFov = 0.3;
				minFov = 0.07;
				maxFov = 0.35;
				minMoveX = 0;
				maxMoveX = 0;
				minMoveY = 0;
				maxMoveY = 0;
				minMoveZ = 0;
				maxMoveZ = 0;
			};
			forceNVG = 0;
			gunnerLeftHandAnimName = "";
			gunnerRightHandAnimName = "";
			gunnerLeftLegAnimName = "";
			gunnerRightLegAnimName = "";
			gunnerDoor = "";
			preciseGetInOut = 0;
			allowTabLock = 1;
			showAllTargets = 0;
			slingLoadOperator = 0;
			playerPosition = 0;
			allowLauncherIn = 0;
			allowLauncherOut = 0;
			class TurnIn {
				turnOffset = 0;
			};
			class TurnOut {
				// TurnIn
				turnOffset = 0;
			};
			gunnerInAction = "ManActTestDriver";
			gunnerAction = "ManActTestDriver";
			gunBeg = "usti hlavne";
			gunEnd = "konec hlavne";
			memoryPointGunnerOptics = "gunnerview";
			memoryPointGun = "kulas";
			selectionFireAnim = "zasleh";
			showCrewAim = 0;
		};
		curatorInfoType = "RscDisplayAttributesVehicle";
		curatorInfoTypeEmpty = "RscDisplayAttributesVehicleEmpty";
		class Attributes {
			class ObjectTexture {
				displayName = "Skin";
				tooltip = "Texture and material set applied on the object.";
				data = "ObjectTexture";
				control = "ObjectTexture";
			};
		};
		// All
		access = 0;
		reversed = 1;
		autocenter = 1;
		animated = 1;
		shadow = 1;
		featureSize = 0;
		speechSingular[] = {};
		speechPlural[] = {};
		maxDetectRange = 20;
		detectSkill = 20;
		mineAlertIconRange = 200;
		killFriendlyExpCoef = 1;
		weaponSlots = 0;
		camouflage = 2;
		spotableDarkNightLightsOff = 0.001;
		spotableNightLightsOff = 0.02;
		spotableNightLightsOn = 4;
		accuracyDarkNightLightsOff = 0.001;
		accuracyNightLightsOff = 0.006;
		accuracyNightLightsOn = 0.1;
		outsideSoundFilter = 0;
		obstructSoundLFRatio = 0;
		occludeSoundLFRatio = 0.25;
		slowSpeedForwardCoef = 0.3;
		normalSpeedForwardCoef = 0.85;
		enableManualFire = 1;
		portrait = "";
		ghostPreview = "";
		destrType = "DestructDefault";
		crewVulnerable = 1;
		damageResistance = 0.004;
		replaceDamaged = "";
		replaceDamagedLimit = 0.9;
		replaceDamagedHitpoints[] = {};
		keepInEPESceneAfterDeath = 0;
		fuelConsumptionRate = 0.01;
		groupCameraPosition[] = {0, 5, -30};
		cameraSmoothSpeed = 5;
		minFireTime = 20;
		indirectHitEnemyCoefAI = 10;
		indirectHitFriendlyCoefAI = -20;
		indirectHitCivilianCoefAI = -20;
		indirectHitUnknownCoefAI = -0.5;
		formationTime = 5;
		alwaysTarget = 0;
		irTarget = 1;
		irScanRangeMin = 0;
		irScanRangeMax = 0;
		irScanToEyeFactor = 1;
		irScanGround = 1;
		laserTarget = 0;
		laserScanner = 0;
		nvTarget = 0;
		nvScanner = 0;
		artilleryTarget = 0;
		artilleryScanner = 0;
		canUseScanners = 1;
		unitInfoTypeLite = 0;
		nightVision = 0;
		commanderCanSee = 31;
		radarType = 0;
		limitedSpeedCoef = 0.22;
		hasDriver = 1;
		driverForceOptics = 0;
		hideWeaponsDriver = 1;
		hideWeaponsCargo = 0;
		getInRadius = 2.5;
		enableWatch = 0;
		enableRadio = 0;
		lockDetectionSystem = 0;
		incomingMissileDetectionSystem = 0;
		usePreciseGetInAction = 0;
		allowTabLock = 1;
		showAllTargets = 0;
		dustFrontLeftPos = "dustFrontLeft";
		dustFrontRightPos = "dustFrontRight";
		dustBackLeftPos = "dustBackLeft";
		dustBackRightPos = "dustBackRight";
		waterResistanceCoef = 0.5;
		waterLinearDampingCoefX = 0;
		waterLinearDampingCoefY = 0;
		waterAngularDampingCoef = 0;
		showNVGDriver = 0;
		showNVGCommander = 0;
		showNVGGunner = 0;
		countsForScoreboard = 1;
		class MarkerLights {};
		class NVGMarker {
			diffuse[] = {1, 1, 1, 1};
			ambient[] = {1, 1, 1, 1};
			brightness = 1;
			blinking = 0;
			onlyInNvg = 0;
		};
		class HeadLimits {
			initAngleX = 5;
			minAngleX = -30;
			maxAngleX = 40;
			initAngleY = 0;
			minAngleY = -90;
			maxAngleY = 90;
			minAngleZ = -45;
			maxAngleZ = 45;
			rotZRadius = 0.2;
		};
		transportAmmo = 0;
		transportFuel = 0;
		transportRepair = 0;
		transportVehiclesCount = 0;
		transportVehiclesMass = 0;
		attendant = 0;
		engineer = 0;
		uavHacker = 0;
		class SoundEnvironExt {};
		class SoundEquipment {};
		class SoundBreath {};
		class SoundBreathSwimming {};
		class SoundBreathInjured {};
		class SoundHitScream {};
		class SoundInjured {};
		class SoundBreathAutomatic {};
		class SoundDrown {};
		class SoundChoke {};
		class SoundRecovered {};
		class SoundBurning {};
		class PulsationSound {};
		class SoundDrowning {};
		soundLandCrash[] = {"", 1, 1};
		soundWaterCrash[] = {"", 0.177828, 1};
		soundServo[] = {"", 0.00316228, 0.5};
		soundElevation[] = {"", 1, 0.5};
		sounddamage[] = {"", 1, 1};
		soundGearUp[] = {"", 1, 1};
		soundGearDown[] = {"", 1, 1};
		soundFlapsUp[] = {"", 1, 1};
		soundFlapsDown[] = {"", 1, 1};
		soundLandCrashes[] = {"soundLandCrash", 1};
		soundWaterCrashes[] = {"soundWaterCrash", 1};
		emptySound[] = {"", 0, 1};
		soundBushCrash[] = {"emptySound", 0};
		soundLocked[] = {"", 1, 1};
		soundIncommingMissile[] = {"", 1, 1};
		driverOpticsModel = "";
		driverOpticsEffect[] = {};
		driverOpticsColor[] = {1, 1, 1, 1};
		castDriverShadow = 0;
		castCargoShadow = 0;
		viewDriverShadow = 1;
		viewDriverShadowDiff = 1;
		viewDriverShadowAmb = 1;
		viewCargoShadow = 1;
		ejectDeadDriver = 0;
		ejectDeadCargo = 0;
		hiddenSelectionsMaterials[] = {};
		hiddenUnderwaterSelections[] = {};
		shownUnderWaterSelections[] = {};
		hiddenUnderwaterSelectionsTextures[] = {};
		class FxExplo {
			access = 1;
		};
		class GunFire {
			// WeaponFireGun
			access = 0;
			cloudletDuration = 0.2;
			cloudletAnimPeriod = 1;
			cloudletSize = 1;
			cloudletAlpha = 1;
			cloudletGrowUp = 0.2;
			cloudletFadeIn = 0.01;
			cloudletFadeOut = 0.5;
			cloudletAccY = 0;
			cloudletMinYSpeed = -100;
			cloudletMaxYSpeed = 100;
			cloudletShape = "cloudletFire";
			cloudletColor[] = {1, 1, 1, 0};
			interval = 0.01;
			size = 3;
			sourceSize = 0.5;
			timeToLive = 0;
			initT = 4500;
			deltaT = -3000;
			class Table {
				class T0 {
					maxT = 0;
					color[] = {0.82, 0.95, 0.93, 0};
				};
				class T1 {
					maxT = 200;
					color[] = {0.75, 0.77, 0.9, 0};
				};
				class T2 {
					maxT = 400;
					color[] = {0.56, 0.62, 0.67, 0};
				};
				class T3 {
					maxT = 600;
					color[] = {0.39, 0.46, 0.47, 0};
				};
				class T4 {
					maxT = 800;
					color[] = {0.24, 0.31, 0.31, 0};
				};
				class T5 {
					maxT = 1000;
					color[] = {0.23, 0.31, 0.29, 0};
				};
				class T6 {
					maxT = 1500;
					color[] = {0.21, 0.29, 0.27, 0};
				};
				class T7 {
					maxT = 2000;
					color[] = {0.19, 0.23, 0.21, 0};
				};
				class T8 {
					maxT = 2300;
					color[] = {0.22, 0.19, 0.1, 0};
				};
				class T9 {
					maxT = 2500;
					color[] = {0.35, 0.2, 0.02, 0};
				};
				class T10 {
					maxT = 2600;
					color[] = {0.62, 0.29, 0.03, 0};
				};
				class T11 {
					maxT = 2650;
					color[] = {0.59, 0.35, 0.05, 0};
				};
				class T12 {
					maxT = 2700;
					color[] = {0.75, 0.37, 0.03, 0};
				};
				class T13 {
					maxT = 2750;
					color[] = {0.88, 0.34, 0.03, 0};
				};
				class T14 {
					maxT = 2800;
					color[] = {0.91, 0.5, 0.17, 0};
				};
				class T15 {
					maxT = 2850;
					color[] = {1, 0.6, 0.2, 0};
				};
				class T16 {
					maxT = 2900;
					color[] = {1, 0.71, 0.3, 0};
				};
				class T17 {
					maxT = 2950;
					color[] = {0.98, 0.83, 0.41, 0};
				};
				class T18 {
					maxT = 3000;
					color[] = {0.98, 0.91, 0.54, 0};
				};
				class T19 {
					maxT = 3100;
					color[] = {0.98, 0.99, 0.6, 0};
				};
				class T20 {
					maxT = 3300;
					color[] = {0.96, 0.99, 0.72, 0};
				};
				class T21 {
					maxT = 3600;
					color[] = {1, 0.98, 0.91, 0};
				};
				class T22 {
					maxT = 4200;
					color[] = {1, 1, 1, 0};
				};
			};
		};
		class GunClouds {
			// WeaponCloudsGun
			access = 0;
			cloudletDuration = 0.3;
			cloudletAnimPeriod = 1;
			cloudletSize = 1;
			cloudletAlpha = 1;
			cloudletGrowUp = 1;
			cloudletFadeIn = 0.01;
			cloudletFadeOut = 1;
			cloudletAccY = 0.4;
			cloudletMinYSpeed = 0.2;
			cloudletMaxYSpeed = 0.8;
			cloudletShape = "cloudletClouds";
			cloudletColor[] = {1, 1, 1, 0};
			interval = 0.05;
			size = 3;
			sourceSize = 0.5;
			timeToLive = 0;
			initT = 0;
			deltaT = 0;
			class Table {
				class T0 {
					maxT = 0;
					color[] = {1, 1, 1, 0};
				};
			};
		};
		class MGunClouds {
			// WeaponCloudsMGun
			access = 0;
			cloudletGrowUp = 0.05;
			cloudletFadeIn = 0;
			cloudletFadeOut = 0.1;
			cloudletDuration = 0.05;
			cloudletAnimPeriod = 1;
			cloudletSize = 1;
			cloudletAlpha = 0.3;
			cloudletAccY = 0;
			cloudletMinYSpeed = -100;
			cloudletMaxYSpeed = 100;
			cloudletShape = "cloudletClouds";
			cloudletColor[] = {1, 1, 1, 0};
			timeToLive = 0;
			interval = 0.02;
			size = 0.3;
			sourceSize = 0.02;
			initT = 0;
			deltaT = 0;
			class Table {
				class T0 {
					maxT = 0;
					color[] = {1, 1, 1, 0};
				};
			};
		};
		// All
		selectionDamage = "zbytek";
		HeadAimDown = 0;
		cargoCanEject = 1;
		driverCanEject = 1;
		airCapacity = 10;
		waterDamageEngine = 0.2;
		damageTexDelay = 0;
		coefInside = 2;
		coefInsideHeur = 2;
		coefSpeedInside = 2;
		windSockExist = 0;
		slingLoadCargoMemoryPointsDir[] = {};
		damageHalf[] = {};
		damageFull[] = {};
		class camShakeGForce {
			power = 1;
			frequency = 20;
			distance = 0;
			minSpeed = 1;
			duration = 3;
		};
		minGForce = 0.2;
		maxGForce = 2;
		gForceShakeAttenuation = 0.5;
		class camShakeDamage {
			power = 0.5;
			frequency = 60;
			distance = -1;
			minSpeed = 1;
			attenuation = 0.5;
			duration = 3;
		};
		insideDetectCoef = 0.05;
	};
	class DS_Veh_Offroad_Civil_White: DS_Veh_Offroad_Civ_Base 
	{
		author = "Desolation Redux Dev Team";
		displayName = "Offroad";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\C_Offroad_01_F.jpg";
		model = "\A3\soft_f\Offroad_01\Offroad_01_unarmed_F";
		picture = "\A3\soft_f\Offroad_01\Data\UI\Offroad_01_base_CA.paa";
		Icon = "\A3\soft_f\Offroad_01\Data\UI\map_offroad_01_CA.paa";
		scope = 2;
		armor = 30;
		maximumLoad = 3000;
		class EventHandlers {
			init = "if (local (_this select 0)) then {[(_this select 0),['White',1],['hidePolice',1,'HideServices',1,'HideDoor1',1,'HideDoor2',1,'HideGlass2',1,'HideDoor3',1,'HideBackpacks',1,'HideBumper1',1], true] call bis_fnc_initVehicle;};";
			// DefaultEventHandlers
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed = "_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
	};
	class DS_Veh_Offroad_Civil_White_Doors: DS_Veh_Offroad_Civ_Base 
	{
		author = "Desolation Redux Dev Team";
		displayName = "Offroad";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\C_Offroad_01_F.jpg";
		model = "\A3\soft_f\Offroad_01\Offroad_01_unarmed_F";
		picture = "\A3\soft_f\Offroad_01\Data\UI\Offroad_01_base_CA.paa";
		Icon = "\A3\soft_f\Offroad_01\Data\UI\map_offroad_01_CA.paa";
		scope = 2;
		armor = 35;
		maximumLoad = 3500;
		class EventHandlers {
			init = "if (local (_this select 0)) then {[(_this select 0),['White',1],['hidePolice',1,'HideServices',1,'HideDoor1',0,'HideDoor2',0,'HideGlass2',1,'HideDoor3',0,'HideBackpacks',1,'HideBumper1',1,'HideBumper2',1,'HideConstruction',1], true] call bis_fnc_initVehicle;};";
			// DefaultEventHandlers
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed = "_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
	};
	class DS_Veh_Offroad_Civil_White_Inv: DS_Veh_Offroad_Civ_Base 
	{
		author = "Desolation Redux Dev Team";
		displayName = "Offroad";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\C_Offroad_01_F.jpg";
		model = "\A3\soft_f\Offroad_01\Offroad_01_unarmed_F";
		picture = "\A3\soft_f\Offroad_01\Data\UI\Offroad_01_base_CA.paa";
		Icon = "\A3\soft_f\Offroad_01\Data\UI\map_offroad_01_CA.paa";
		scope = 2;
		armor = 35;
		maximumLoad = 4500;
		class EventHandlers {
			init = "if (local (_this select 0)) then {[(_this select 0),['White',1],['hidePolice',1,'HideServices',1,'HideDoor1',0,'HideDoor2',0,'HideGlass2',1,'HideDoor3',0,'HideBackpacks',0,'HideBumper1',1,'HideBumper2',1,'HideConstruction',1], true] call bis_fnc_initVehicle;};";
			// DefaultEventHandlers
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed = "_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
	};
	class DS_Veh_Offroad_Civil_White_Armor: DS_Veh_Offroad_Civ_Base 
	{
		author = "Desolation Redux Dev Team";
		displayName = "Offroad";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\C_Offroad_01_F.jpg";
		model = "\A3\soft_f\Offroad_01\Offroad_01_unarmed_F";
		picture = "\A3\soft_f\Offroad_01\Data\UI\Offroad_01_base_CA.paa";
		Icon = "\A3\soft_f\Offroad_01\Data\UI\map_offroad_01_CA.paa";
		scope = 2;
		armor = 45;
		maximumLoad = 4500;
		class EventHandlers {
			init = "if (local (_this select 0)) then {[(_this select 0),['White',1],['hidePolice',1,'HideServices',1,'HideDoor1',0,'HideDoor2',0,'HideGlass2',0,'HideDoor3',0,'HideBackpacks',0,'HideBumper1',0,'HideBumper2',0,'HideConstruction',1], true] call bis_fnc_initVehicle;};";
			// DefaultEventHandlers
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed = "_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
	};
	class DS_Veh_Offroad_Civil_White_Cop: DS_Veh_Offroad_Civ_Base 
	{
		author = "Desolation Redux Dev Team";
		displayName = "Offroad";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\C_Offroad_01_F.jpg";
		model = "\A3\soft_f\Offroad_01\Offroad_01_unarmed_F";
		picture = "\A3\soft_f\Offroad_01\Data\UI\Offroad_01_base_CA.paa";
		Icon = "\A3\soft_f\Offroad_01\Data\UI\map_offroad_01_CA.paa";
		scope = 2;
		armor = 50;
		maximumLoad = 5000;
		class EventHandlers {
			init = "if (local (_this select 0)) then {[(_this select 0),['White',1],['hidePolice',0,'HideServices',1,'HideDoor1',0,'HideDoor2',0,'HideGlass2',0,'HideDoor3',0,'HideBackpacks',0,'HideBumper1',0,'HideBumper2',0,'HideConstruction',0], true] call bis_fnc_initVehicle;};";
			// DefaultEventHandlers
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
			killed = "_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
		};
	};
};


