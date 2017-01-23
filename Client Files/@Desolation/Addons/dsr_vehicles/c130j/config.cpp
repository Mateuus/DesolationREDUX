enum {
	StabilizedInAxesNone = 0,
	StabilizedInAxisX = 1,
	StabilizedInAxisY = 2,
	StabilizedInAxesBoth = 3,
	StabilizedInAxesXYZ = 4
};

class CfgPatches
{
	class CAAir_E_c130j
	{
		units[] ={};
		weapons[] = {};
		requiredVersion = 1.04;
		requiredAddons[] = {"dsr_vehicles"};
	};
};
#include "crewanimations.hpp"
class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		class HitPoints;
	};
	class c130j_base: Plane
	{
		class NewTurret;
		class AnimationSources;
		class ViewPilot;
		class ViewGunner;
		class Eventhandlers;
	};
	class c130j: c130j_base
	{
		model = "dsr_vehicles\c130j\c130j.p3d";
		accuracy = 0.15;											// how hard it is to distinguish the type of the vehicle (bigger number means harder)
		icon = "dsr_vehicles\c130j\data\ui\icon_c130j_ca.paa"; 	// icon in map/editor
		picture = "dsr_vehicles\c130j\data\ui\picture_c130j_ca.paa";	// small picture in command menu
		author = "ANixon - DesolationRedux.com";
		vehicleClass = "Air";
		driverAction = "c130j_pilot";	// what is the standard pose for the pilot, defined as animation state
		//simulation = "airplane";
		cargoIsCoDriver[] = {1,0};
		getInAction = "GetInLow";
		getOutAction = "GetInLow";
		hasGunner = true;
		transportSoldier = 24;
		//getInRadius = 2.5;
		cabinOpening = "true";
		gearRetracting = 1;	//retractable landing gear
		fuelCapacity = 2000;
		hascommander = false; 
		//driverIsCommander = true;
		mapSize = 25;
		cost = 20000; 
		driverCompartments = "Compartment1";
		//Cargo Shit
		cargoCompartments[] = {"Compartment1"};
		cargoGetInAction[] = {"GetOutLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoAction[] = {"passenger_generic01_foldhands"};
		memoryPointsGetInCargo = "pos cargo";		// on what memory points should the cargo get in the heli
		memoryPointsGetInCargoDir = "pos cargo dir"; // what is the direction of the cargo facing during get in animation (and opposite for get out)
		crewVulnerable = "true";
		cargocaneject = 1;	
		ejectDeadCargo = true;
		transportMaxWeapons = 15;
		transportMaxMagazines = 45;
		transportMaxBackpacks = 10;
		//Driver Shit
		memoryPointsGetInDriver = "pos driver";  // only one door
		memoryPointsGetInDriverDir = "pos driver dir";  // only one door
		hideWeaponsCargo = 1;						// this makes the poses easier and adds some performance gain because the proxies dont need to be drawn
		cargoProxyIndexes[] = {1,2,3,4,5,6,7};		// what indexes does regular cargo sit on
		LockDetectionSystem = CM_Lock_Radar;			// this uses macros from basicDefines_A3, just add more to gain more systems for the vehicle
		incomingMissileDetectionSystem = CM_Missile;	// for example CM_Lock_Laser + CM_Lock_Radar, parser is able to evaluate that, or simply 12 in that case
		weapons[]={"CMFlareLauncher"};
		magazines[]={"300Rnd_CMFlare_Chaff_Magazine"};
		class TransportItems{};	// planes are usually not used to transport items, there could possibly be a few FAKs
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "WingVortices";// name of the effect
				position = "body_vapour_L_E"; // name of the memory point in model
			};

			class WingTipRight
			{
				effectName = "WingVortices"; // name of the effect
				position = "body_vapour_R_E";// name of the memory point in model
			};
			class BodyLeft
			{
				effectName = "BodyVortices";// name of the effect
				position = "body_vapour_L_S"; // name of the memory point in model
			};

			class BodyRight
			{
				effectName = "BodyVortices"; // name of the effect
				position = "body_vapour_R_S";// name of the memory point in model
			};
		};
		/*
		class HitPoints: HitPoints
		{
			class HitGlass1: HitGlass1
			{
				armor = 0.25;
			};
		};
		*/

		#include "sounds.hpp" 	// sounds are included in separate file to prevent cluttering
		landingSpeed = 200;		// used for AI to approach the runawy, the plane should be stable at this speed
		acceleration = 300; 	// used for AI to plan the waypoints and accelerating, doesnt affect plane performance
		maxSpeed = 648;			// maximal speed of the plane, affects even thrust and is base for both envelope and thrustCoef
		driveOnComponent[] = {"wheel_1_1","wheel_2_1","wheel_2_2","wheel_3_1","wheel_3_2"};  // array of components to be assigned special low-friction material (usually wheels)
		rudderInfluence = 0.5;		// coefficient of rudder affecting steering of the plane
		aileronSensitivity = 1;		// coefficient of ailerons affecting twisting the plane
		elevatorSensitivity = 1;	// coefficient of elevators affecting changing of plane horizontal heading
		irScanRangeMin = 500;		// defines the range of IR sight of the vehicle
		irScanRangeMax = 5000;		// defines the range of IR sight of the vehicle
		irScanToEyeFactor = 2;		// defines the effectivity of IR sight of the vehicle
		// envelope defines lift produced by the shape of the plane according to current speed relative to maxSpeed
		// the first element of the array is for zero speed, the last for 125 % of maxSpeed, the rest in between is evenly distributed
		// there may be as many elements as you wish, using 13 should be preferred as it modulates the 10% increase with reasonable error
		extCameraPosition[] = {0,5,-40};
		envelope[] = {0.0,0.1,0.5,1.5,3.1,4.3,4.9,5,4.4,2.8,1.6,0.8,0};
		// angle of incidence - difference between forward and airfold chord line - def. val is 3*PI/180 (meaning three degrees)
		angleOfIndicence = 0.05235987;
		// forces keeping plane aligned with its speed direction - the bigger force the better it changes the direction of flight
		draconicForceXCoef = 2.5;
		draconicForceYCoef = 0.5;
		draconicForceZCoef = 0.5;
		draconicTorqueXCoef = 0.15;
		draconicTorqueYCoef = 2.0;
		// rudder, elevator, aileron, thrust effectiveness; if empty old settings is used
		// effectiveness according to current speed and maxSpeed ratio
		// last value goes for 150% of max speed
		thrustCoef[]= {1.5, 1.2, 1.1, 1.0, 1.0, 1.0, 1.0, 0.9, 0.7, 0.5, 0.3, 0.1, 0.0, 0.0, 0.0, 0.0};
		elevatorCoef[]= {}; //default value is 1
		aileronCoef[]= {};  //default value is 1
		rudderCoef[]= {};   //default value is fabs(speed.Z())*InvSqrt(Square(speed.X())+Square(speed.Z()));
		//! coefficient of players controller sensitivity (does not affect AI)
		elevatorControlsSensitivityCoef = 4;
		aileronControlsSensitivityCoef = 4;
		rudderControlsSensitivityCoef = 4;
		ejectSpeed[] = {0, 0, 0};
		driverCanEject = 0;			// pilot shouldnt be able to do so as he doesnt have eject seat
		landingAoa = "rad 7"; 	// what AoA is going the IA use to land the plane
		laserScanner = 1;		// if the vehicle is able to see targets marked by laser marker
		gunAimDown = 0.029000;	// adjusts the aiming of gun relative to the axis of model
		headAimDown = 0.0000;	// adjusts the view of pilot to have crosshair centred
		memoryPointLRocket = "Rocket_1"; // use this for simulating different rocked pods in case you dont want to mess with "maverick weapon" simulation
		memoryPointRRocket = "Rocket_2"; // it is used to alternate two points/pods of fire the missiles
		flapsFrictionCoef = 2;	// sets the effectivity of using flaps to increase drag/lift
		wheelSteeringSensitivity = 2.0;
		noseDownCoef = 1;
		gearUpTime = 4.5;
		gearDownTime = 3;
		minFireTime = 30;			// how long does the pilot fire at one target before switching to another one
		threat[] = {0.1, 0.5, 0.8};		// multiplier of cost of the vehicle in eyes of soft, armoured and air enemies
		canFloat = "false";
		waterResistanceCoef = 0.004;
		waterLeakiness = 25.0;
		driverLeftHandAnimName = "stick_leftwheel";
		driverRightHandAnimName = "stick_leftwheel";
		driverLeftLegAnimName = "pedal_l";
		driverRightLegAnimName = "pedal_r";
		armor = 70;					// just some protection against missiles, collisions and explosions
		damageResistance = 0.004;	// for AI if it is worth to be shoot at
		destrType = DestructWreck;	// how does the vehicle behave while destroyed, this one changes to the Wreck lod of the model
		class Reflectors
		{
			class Left
			{
				color[] = {1900, 1800, 1700};		// approximate colour of standard lights
				ambient[] = {5, 5, 5};				// nearly a white one
				position = "L svetlo";			
				direction = "L svetlo dir";			
				hitpoint = "L svetlo";			
				selection = "L svetlo";		
				size = 1;						// size of the light point seen from distance
				innerAngle = 70;						// angle of full light
				outerAngle = 120;						// angle of some light
				coneFadeCoef = 10;						// attenuation of light between the above angles
				intensity = 1;						// strength of the light
				useFlare = true;						// does the light use flare?
				dayLight = false;					// switching light off during day saves CPU a lot
				flareSize = 1.0;						// how big is the flare
				class Attenuation
				{
					start = 1.0;
					constant = 0; 
					linear = 0; 
					quadratic = 0.25; 
					hardLimitStart = 30;		// it is good to have some limit otherwise the light would shine to infinite distance
					hardLimitEnd = 60;		// this allows adding more lights into scene
				};
			};
			class Right: Left
			{
				position = "P svetlo";
				direction = "P svetlo dir";
				hitpoint = "P svetlo";
				selection = "P svetlo";
			};	
			class Left2: Left
			{
				position = "L2 svetlo";
				direction = "L svetlo dir";
				hitpoint = "L2 svetlo";
				selection = "L2 svetlo";
			};
			class Right2: Left
			{
				position = "P2 svetlo";
				direction = "P svetlo dir";
				hitpoint = "P2 svetlo";
				selection = "P2 svetlo";
			};
		};	
		class MarkerLights
		{
			class RedStill
			{
				name = "PositionLightStill_red";
				color[] = {0.8,0.0,0.0};
				ambient[] = {0.08,0.0,0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 1;
			};
			class RedInteriorLighting
			{
				name = "PositionLightInterior_red";
				color[] = {0.8,0.0,0.0};
				ambient[] = {0.08,0.0,0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 1;
				flareSize = 0.1;
			};
			class GreenStill
			{
				name = "PositionLightStill_green";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 1;
			};	
			class WhiteStill
			{
				name = "PositionLightStill_white";
				color[] = {1.0,1.0,1.0};
				ambient[] = {0.1,0.1,0.1};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 1;
			};
			class BlueStill
			{
				name = "PositionLightStill_blue";
				color[] = {0.0,0.0,0.8};
				ambient[] = {0.0,0.0,0.08};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 1;
			};	
			class RedBlinking
			{
				name = "PositionLightBlinking_red";
				color[] = {0.9,0.15,0.1};
				ambient[] = {0.09,0.015,0.01};
				intensity = 75;
				blinking = 1;
				blinkingStartsOn = 0;
				blinkingPattern[] = {2.9,0.1};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};
			class WhiteBlinking
			{
				name = "PositionLightBlinking_white";
				color[] = {1.0,1.0,1.0};
				ambient[] = {0.1,0.1,0.1};
				intensity = 100;
				blinking = 1;
				blinkingPattern[] = {0.1,2.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.35;
				drawLightCenterSize = 0.08;
			};
		};
		class Turrets {			
			// Copilot
			class MainTurret : NewTurret {
				isCopilot = 1;
				commanding = -1;
				body = "";
				gun = "";
				animationSourceBody = "";
				animationSourceGun = "";
				hasGunner = true;
				primaryObserver = 1;
				primaryGunner = 0;
				gunnerUsesPilotView = true;
				gunnerName = "Co-Pilot";
				gunnerCompartments = "Compartment1";
				gunnerlefthandanimname = "stick_rightwheel";
				gunnerrighthandanimname = "stick_rightwheel";
				gunnerOpticsModel = "\A3\Weapons_F\empty.p3d";
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				gunnerForceOptics = false;
				gunnerAction = "c130j_pilot";
				proxyIndex = 1;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				caneject = 0;
				weapons[] = {};
				magazines[] = {};
				startEngine = false;
				minElev = -60;
				maxElev = 10;
				initElev = 0;
				minTurn = -70;
				maxTurn = 70;
				initTurn = 0;
				ejectDeadGunner = 0;
				class HitPoints{};
				class ViewPilot : ViewPilot
				{
					initFov = 1;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -170;
					maxAngleY = 170;	
				}; 
			};
			// Navigator
			class MainTurret2 : NewTurret {
				commanding = -2;
				body = "";
				gun = "";
				animationSourceBody = "";
				animationSourceGun = "";
				gunnerName = "Flight Navigator";
				gunnerCompartments = "Compartment1";
				gunnerUsesPilotView = true;
				primaryGunner = 0;
				isCopilot = 0;
				proxyIndex = 3;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				caneject = 1;
				weapons[] = {};
				magazines[] = {};
				gunnerForceOptics = false;
				gunnerAction = "passenger_generic01_foldhands";
			    hasGunner = true;
				startEngine = false;
				minElev = -60;
				maxElev = 10;
				initElev = 0;
				minTurn = -70;
				maxTurn = 70;
				initTurn = 0;
				ejectDeadGunner = 0;
				class ViewPilot : ViewPilot {
					initFov = 1;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -75;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -170;
					maxAngleY = 170;
				
				}; 
			};
			// Load Master
			class GunnerTurret : NewTurret {
				enableCopilot = false;
				commanding = -3;
				body = "";
				gun = "";
				animationSourceBody = "";
				animationSourceGun = "";
				gunnerName = "Load Master";
				gunnerCompartments = "Compartment1";
				gunnerUsesPilotView = false;
				gunnerAction = "Stand"; 
				hasGunner = true;
				primaryGunner = 0;
				isCopilot = 0;
				proxyIndex = 2;
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				caneject = 1;
				weapons[] = {};
				magazines[] = {};
				gunnerForceOptics = false;
				showAsCargo = 1;
				ejectDeadGunner = 1;
				isPersonTurret = 1;
				startEngine = false;
				minElev = -40;
				maxElev = 10;
				initElev = 0;
				minTurn = -20;
				maxTurn = 60;
				initTurn = 0;
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"dsr_vehicles\c130j\data\c130j_sklo.rvmat",
				"dsr_vehicles\c130j\data\c130j_sklo_damage.rvmat",
				"dsr_vehicles\c130j\data\c130j_sklo_damage.rvmat",

				"dsr_vehicles\c130j\data\c130j_sklo_in.rvmat",
				"dsr_vehicles\c130j\data\c130j_sklo_in_damage.rvmat",
				"dsr_vehicles\c130j\data\c130j_sklo_in_damage.rvmat",

				"dsr_vehicles\c130j\data\c130j_body.rvmat",
				"dsr_vehicles\c130j\data\c130j_body_damage.rvmat",
				"dsr_vehicles\c130j\data\c130j_body_destruct.rvmat",

				"dsr_vehicles\c130j\data\c130j_interior.rvmat",
				"dsr_vehicles\c130j\data\c130j_interior_damage.rvmat",
				"dsr_vehicles\c130j\data\c130j_interior_destruct.rvmat",

				"dsr_vehicles\c130j\data\c130j_wings.rvmat",
				"dsr_vehicles\c130j\data\c130j_wings_damage.rvmat",
				"dsr_vehicles\c130j\data\c130j_wings_destruct.rvmat",

				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"a3\data_f\default_destruct.rvmat"
			};
		};
		
		hiddenSelections[] = {"camo1", "camo2"};
		hiddenSelectionsTextures[] = {"\dsr_vehicles\c130j\data\c130j_body_un_co.paa", "\dsr_vehicles\c130j\data\c130j_wings_un_co.paa"};
		class AnimationSources
		{
			class door_2_2
			{
				source = "user";
				animPeriod = 10;
			};
			class door_2_1: door_2_2{};
			class door_1: door_2_2{};
			class ramp_bottom
			{
				source = "user";
				initPhase = 0;
				animPeriod = 10;
			};
			class ramp_top
			{
				source = "user";
				initPhase = 0;
				animPeriod = 10;
			};
		};
		class USERACTIONS
		{
			class OpenRamp
			{
				displayName = "Open Cargo Ramp";
				position = "pos_gunner";
				onlyforplayer = 1;
				radius = 6;
				condition = "(this animationPhase ""ramp_bottom"" == 0) AND Alive(this)";
				statement = "this animate [""ramp_bottom"",1];this animate [""ramp_top"",1];";
			};
			class CloseRamp: OpenRamp
			{
				displayName = "Close Cargo Ramp";
				condition = "(this animationPhase ""ramp_bottom"" == 1) AND Alive(this)";
				statement = "this animate [""ramp_bottom"",0];this animate [""ramp_top"",0];";
			};
			class OpenLdoor
			{
				displayName = "Open Left Door";
				position = "pos_gunner";
				onlyforplayer = 1;
				radius = 6;
				condition = "(this animationPhase ""door_2_1"" == 0) AND Alive(this)";
				statement = "this animate [""door_2_1"",1]";
			};
			class OpenRdoor: OpenLdoor
			{
				displayName = "Open Right Door";
				condition = "(this animationPhase ""door_2_2"" == 0) AND Alive(this)";
				statement = "this animate [""door_2_2"",1]";
			};
			class Closeldoor: OpenLdoor
			{
				displayName = "Close Left Door";
				condition = "(this animationPhase ""door_2_1"" == 1) AND Alive(this)";
				statement = "this animate [""door_2_1"",0]";
			};
			class Closerdoor: OpenLdoor
			{
				displayName = "Close Right Door";
				condition = "(this animationPhase ""door_2_2"" == 1) AND Alive(this)";
				statement = "this animate [""door_2_2"",0]";
			};
			class openfdoor: OpenLdoor
			{
				displayName = "Open Crew Door";
				condition = "(this animationPhase ""door_1"" == 0) AND Alive(this)";
				statement = "this animate [""door_1"",1]";
			};
			class closefdoor: OpenLdoor
			{
				displayName = "Close Crew Door";
				condition = "(this animationPhase ""door_1"" == 1) AND Alive(this)";
				statement = "this animate [""door_1"",0]";
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				direction = "exhaust1_dir";
				effect = "ExhaustsEffectPlane";
				position = "exhaust1";
			};
			class Exhaust2
			{
				direction = "exhaust2_dir";
				effect = "ExhaustsEffectPlane";
				position = "exhaust2";
			};
			class Exhaust3
			{
				direction = "exhaust3_dir";
				effect = "ExhaustsEffectPlane";
				position = "exhaust3";
			};
			class Exhaust4
			{
				direction = "exhaust4_dir";
				effect = "ExhaustsEffectPlane";
				position = "exhaust4";
			};
		};
		// class for helmet mounted displays, is going to be documented separately
		#include "cfgHUD.hpp"
	};
};
	class DSR_C130J_F: c130j
	{
		displayName = "UN-C130J";
		scope = 2;
		scopeCurator=2;		// scope 2 means its available in Zeus mode (0 means hidden)
		side = 3;
		faction = "CIV_F";
		crew = "B_T_Pilot_F";
		typicalCargo[] = {"B_T_Pilot_F","C_man_1"};
		editorPreview = "dsr_vehicles\c130j\data\ui\picture_c130j_ca.paa";
	};	
};
