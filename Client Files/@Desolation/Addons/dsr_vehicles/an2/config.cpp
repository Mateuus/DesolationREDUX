enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxesxyz = 4,
	stabilizedinaxisy = 2,
	stabilizedinaxesboth = 3,
	destructno = 0,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DSR_AN2
	{
		units[] ={"DSR_AN2_F"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"dsr_vehicles"};
	};
};
#include "crewanimations.hpp"
class CfgVehicles
{
	class Air;
	class Plane: Air	
	{
		class Turrets
		{
			class CopilotTurret;
		};
		class AnimationSources;
		class Eventhandlers;
		class HitPoints
		{
			class HitHull;
		};
		class NewTurret;
		class Sounds;
		class ViewPilot;
		class ViewGunner;
	};
	class an2_base_ep1: Plane
	{
		weapons[] = {};
		magazines[] = {};
		//vehicleClass = "Air";
		model = "\dsr_vehicles\an2\an2.p3d";
		picture = "\dsr_vehicles\an2\data\ui\picture_an2_ca.paa";
		icon="\dsr_vehicles\an2\data\ui\icon_an2_ca.paa";
		author = "ANixon - DesolationRedux.com";
		
		//Cargo
		ejectDeadCargo = 1;
		memoryPointsGetInCargo[] = {"pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos cargo dir"};
		cargoGetInAction[] = {"GetInHigh"};
		cargoGetOutAction[] = {"GetOutHigh"};
		cargoAction[] = {"passenger_generic01_foldhands"};
		hideWeaponsCargo = 0;						// this makes the poses easier and adds some performance gain because the proxies dont need to be drawn
		cargocaneject = 1;
		cargoCompartments[] = {"Compartment1"};
		cargoIsCoDriver[] = {1,0};
		
		//Pilot
		driverAction = "AN2_Pilot_EP1";
		driverCompartments = "Compartment1";
		hideWeaponsDriver = 1;
		memoryPointsGetInDriver = "pos driver";  // only one door
		memoryPointsGetInDriverDir = "pos driver dir";  // only one door
		driverLeftHandAnimName = "stick_leftwheel";
		driverRightHandAnimName = "stick_leftwheel";
		driverLeftLegAnimName = "pedal1";
		driverRightLegAnimName = "pedal1";
		getInAction = GetInHigh;
		getOutAction = GetOutHigh;
		ejectDeadDriver = 1;
		//driverIsCommander = 1;	
		
		//Engine, Physx, etc
		insideSoundCoef = 0.35;
		mapSize = 20;
		//hasCrew = 1;
		fuelCapacity = 800;
		//hascommander = true;
		//startEngine = 0;
		//fov = 0.7;
		simulation = "airplane";
		maxFordingDepth = 0.5;
		//enableManualFire = 0;
		accuracy = 0.15;
		cost = 20000;
		transportSoldier = 12;
		crewVulnerable = "true";	
		transportMaxWeapons = 15;
		transportMaxMagazines = 45;
		transportMaxBackpacks = 10;
		cargoProxyIndexes[] = {1,2,3,4,5,6,7,8,9};		// what indexes does regular cargo sit on
		gearRetracting = 0;
		threat[] = {0.0, 0.0, 0.0};
		// http://plane.spottingworld.com/Antonov_An-2
		airBrake = 1;
		acceleration = 200; 	// used for AI to plan the waypoints and accelerating, doesnt affect plane performance
		maxSpeed = 258;
		angleOfIndicence = 0.05;
		// landingAoa = 12*3.14/180;
		landingSpeed = 100;
		rudderInfluence = 0.25;		// coefficient of rudder affecting steering of the plane
		aileronSensitivity = 1;
		elevatorSensitivity = 0.75;
		envelope[]=
		{
		// speed relative to max. speed -> lift (G)
		//		0%  10%   20%   30%   40%   50%   60%   70%   80%   90%  100%  110%  117,5%  125%
				0.0, 0.4, 0.60, 1.80, 2.80, 3.30, 3.50, 3.20, 2.60, 2.00, 1.50, 1.00, 0.70, 0.3
		};
		// forces keeping plane aligned with its speed direction - the bigger force the better it changes the direction of flight
		draconicForceXCoef = 3;
		draconicForceYCoef = 1;
		draconicForceZCoef = 0.5;
		draconicTorqueXCoef = 3;
		draconicTorqueYCoef = 0.25;
		wheelSteeringSensitivity = 1;
		ejectSpeed[] = {0, 0, 0};
		extCameraPosition[]={0,5,-20};
		lightOnGear = 0;
		driveOnComponent[] = {"wheel_1_1","wheel_1_2","wheel_2_1"};  // array of components to be assigned special low-friction material (usually wheels)
		thrustCoef[]= {0.8, 1.0, 1.3, 1.25, 1.1, 1.0, 1.0, 0.9, 0.75, 0.65, 0.5, 0.25, 0};
		elevatorCoef[]= {}; //default value is 1
		aileronCoef[]= {};  //default value is 1
		rudderCoef[]= {};   //default value is fabs(speed.Z())*InvSqrt(Square(speed.X())+Square(speed.Z()));
		//! coefficient of players controller sensitivity (does not affect AI)
		elevatorControlsSensitivityCoef = 4;
		aileronControlsSensitivityCoef = 4;
		rudderControlsSensitivityCoef = 4;
		driverCanEject = 0;			// pilot shouldnt be able to do so as he doesnt have eject seat
		landingAoa = "rad 7"; 	// what AoA is going the IA use to land the plane
		laserScanner = 1;		// if the vehicle is able to see targets marked by laser marker
		gunAimDown = 0.029000;	// adjusts the aiming of gun relative to the axis of model
		headAimDown = 0.0000;	// adjusts the view of pilot to have crosshair centred
		flapsFrictionCoef = 5.5;	// sets the effectivity of using flaps to increase drag/lift
		noseDownCoef = 1;
		minFireTime = 30;			// how long does the pilot fire at one target before switching to another one
		canFloat = 0;
		waterResistanceCoef = 0.004;
		waterLeakiness = 25.0;
		armor = 20;					// just some protection against missiles, collisions and explosions
		damageResistance = 0.00278;	// for AI if it is worth to be shoot at
		destrType = DestructWreck;	// how does the vehicle behave while destroyed, this one changes to the Wreck lod of the model
		altFullForce = 4500;
		altNoForce = 7000;
		radarType = 1;
		LockDetectionSystem = 0;
		incomingMissiLeDetectionSystem = 0;
		irScanRangeMin=100;
		irScanRangeMax=1000;
		irScanToEyeFactor=2;
		hiddenSelections[] =  {"camo1", "camo2", "camo3", "camo4", "camo5"};
		
		class TransportItems{};
		
		#include "sounds.hpp"

		class Turrets 
		{
			class MainTurret : NewTurret 
			{
				body = "";
				gun = "";
				animationSourceBody = "";
				animationSourceGun = "";
				commanding = -1;
				primaryObserver = 1; 
				primaryGunner = 0;  // - make position available in editor
				isCopilot = 1;
				proxyIndex = 1;
				startEngine = false;
				ejectDeadGunner = 1;
				caneject = false;
				cabinOpening = false;
				weapons[] = {};
				magazines[] = {};
				gunnerName = "Co-Pilot";
				gunnerCompartments = "Compartment1";
				gunnerUsesPilotView = true;
				gunnergetinaction = "GetInLow";
				gunnergetoutaction = "GetOutHigh";
				gunnerForceOptics = false;
				gunnerAction = "AN2_Pilot_EP1";
				gunnerInAction = "AN2_Pilot_EP1";
				gunnerlefthandanimname = "stick_rightwheel";
				gunnerrighthandanimname = "stick_rightwheel";
				gunnerLeftLegAnimName = "pedal2";
				gunnerRightLegAnimName = "pedal2";
				memoryPointsGetInGunner = "pos driver";
				memoryPointsGetInGunnerDir = "pos driver dir";
				minElev = -60;
				maxElev = 10;
				initElev = 0;
				minTurn = -70;
				maxTurn = 70;
				initTurn = 0;
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
		};
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "WingVortices";
				position = "body_vapour_l_e";
			};
			class WingTipRight
			{
				effectName = "WingVortices";
				position = "body_vapour_r_e";
			};
			class BodyLeft
			{
				effectName = "BodyVortices";
				position = "body_vapour_l_s";
			};
			class BodyRight
			{
				effectName = "BodyVortices";
				position = "body_vapour_r_s";
			};
			class WingTipLeftTop
			{
				effectName = "WingVortices";
				position = "body_vapour_l_e_t";
			};
			class WingTipRightTop
			{
				effectName = "WingVortices";
				position = "body_vapour_r_e_t";
			};
			class BodyLeftTop
			{
				effectName = "BodyVortices";
				position = "body_vapour_l_s_t";
			};
			class BodyRightTop
			{
				effectName = "BodyVortices";
				position = "body_vapour_r_s_t";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[] = {1900, 1800, 1700};		// approximate colour of standard lights
				ambient[] = {5, 5, 5};				// nearly a white one
				position = "L svetlo";			
				direction = "konec L svetlo";			
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
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
			};
		};
		class MarkerLights
		{
			class RedStill
			{
				name = "cerveny pozicni";
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
			class RedStill2
			{
				name = "zeleny pozicni";
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
			class RedBlinking
			{
				name = "bily pozicni";
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
		};
		class Exhausts {
			class Exhaust1 
			{
				position = "exhaust";  	
				direction = "exhaust_dir";	
				effect = "ExhaustsEffectPlane";	
			};
			class Exhaust2
			{
				position = "exhaust2";  	
				direction = "exhaust2_dir";	
				effect = "ExhaustsEffectPlane";
			};			
		};
		class HitPoints: HitPoints
		{
			class HitGlass1
			{
				armor = 0.1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0.1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0.1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0.1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
		};
		class AnimationSources
		{
			class HitGlass1
			{
				source = "Hit";
				hitpoint = "HitGlass1"; // name of the hitpoint class
				raw = 1;
			};
			class HitGlass2: HitGlass1
			{
				hitpoint = "HitGlass2";
			};
			class HitGlass3: HitGlass1
			{
				hitpoint = "HitGlass3";
			};
			class HitGlass4: HitGlass1
			{
				hitpoint = "HitGlass4";
			};
			class cabindoor
			{
				source = "user"; 
				animPeriod = 1;  
				initPhase=0;
			};
		};
		class UserActions
		{	
			class opendoor
			{
				displayName="Open Door";
				position="pos cargo";
				radius=8;
				showWindow = 0;
				onlyforplayer = true;
				hideOnUse = 1;
				condition="this animationPhase ""cabindoor"" < 0.5";
				statement="this animate [""cabindoor"", 1]";
			};
			class closedoor
			{
				displayName="Close Door";
				position="pos cargo";
				radius=40;
				showWindow = 0;
				onlyforplayer = true;
				hideOnUse = 1;
				condition="this animationPhase ""cabindoor"" >= 0.5 ";
				statement="this animate [""cabindoor"", 0]";
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"dsr_vehicles\an2\data\an2_1.rvmat",
				"dsr_vehicles\an2\data\an2_1_damage.rvmat",
				"dsr_vehicles\an2\data\an2_1_destruct.rvmat",

				"dsr_vehicles\an2\data\an2_2.rvmat",
				"dsr_vehicles\an2\data\an2_2_damage.rvmat",
				"dsr_vehicles\an2\data\an2_2_destruct.rvmat",

				"dsr_vehicles\an2\data\an2_interier.rvmat",
				"dsr_vehicles\an2\data\an2_interier_damage.rvmat",
				"dsr_vehicles\an2\data\an2_interier_destruct.rvmat",

				"dsr_vehicles\an2\data\an2_cockpit.rvmat",
				"dsr_vehicles\an2\data\an2_cockpit_damage.rvmat",
				"dsr_vehicles\an2\data\an2_cockpit_destruct.rvmat",

				"dsr_vehicles\an2\data\an2_wings.rvmat",
				"dsr_vehicles\an2\data\an2_wings_damage.rvmat",
				"dsr_vehicles\an2\data\an2_wings_destruct.rvmat",

				"dsr_vehicles\an2\data\an2_window.rvmat",
				"dsr_vehicles\an2\data\an2_window_damage.rvmat",
				"dsr_vehicles\an2\data\an2_window_destruct.rvmat",

				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"a3\data_f\default_destruct.rvmat"
			};
		};
	};
	class DSR_AN2_F: an2_base_ep1
	{
		displayName = "AN2-Civilian";
		scope = 2;
		scopeCurator=2;
		side = 3;
		faction = "CIV_F";
		crew = "B_T_Pilot_F";
		typicalCargo[] = {"B_T_Pilot_F","C_man_1"};
		editorPreview = "\dsr_vehicles\an2\data\ui\picture_an2_ca.paa";
		hiddenSelectionsTextures[] ={
			"\dsr_vehicles\an2\data\an2_1_CO.paa",
			"\dsr_vehicles\an2\data\an2_2_CO.paa",
			"\dsr_vehicles\an2\data\an2_wings_CO.paa"
		};
	};
};