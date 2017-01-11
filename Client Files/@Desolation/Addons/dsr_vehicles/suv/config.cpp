enum {
	StabilizedInAxesNone = 0,
	StabilizedInAxisX = 1,
	StabilizedInAxisY = 2,
	StabilizedInAxesBoth = 3,
	StabilizedInAxesXYZ = 4
};
class DefaultEventhandlers;
class CfgPatches
{
	class CAWheeled_E_SUV
	{
		units[] ={"DSR_SUV_F"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"dsr_vehicles"};
	};
};
#include "crewanimations.hpp"
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle {};
	class Car_F: Car
	{
		class Eventhandlers;
		class AnimationSources;
	};
	class DSR_SUV_Base: Car_F
	{
		weapons[] = {"MiniCarHorn"};
		magazines[] = {};
		//vehicleClass = "Air";
		model = "\dsr_vehicles\suv\suv.p3d";
		picture = "\dsr_vehicles\suv\data\ui\picture_suv_ca.paa";
		icon="\dsr_vehicles\suv\data\ui\icon_suv_ca.paa";
		author = "ANixon - DesolationRedux.com";
		
		//Cargo
		ejectDeadCargo = 1;
		memoryPointsGetInCargo[] = {"pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos cargo dir"};
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoAction[] = {"passenger_low01","passenger_generic01_leanleft","passenger_generic01_foldhands"};
		hideWeaponsCargo = 0;						// this makes the poses easier and adds some performance gain because the proxies dont need to be drawn
		cargocaneject = 1;
		cargoCompartments[] = {"Compartment1"};
		//cargoIsCoDriver[] = {1,0};
		
		//Pilot
		driverAction = "driver_low01"; //SUV_Driver_EP1
		driverCompartments = "Compartment1";
		hideWeaponsDriver = 1;
		memoryPointsGetInDriver = "pos driver";  // only one door
		memoryPointsGetInDriverDir = "pos driver dir";  // only one door
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "drivewheel";
		driverLeftLegAnimName = "";
		driverRightLegAnimName = "";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		ejectDeadDriver = 1;
		//driverIsCommander = 1;
		
		//Engine, Physx, etc
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-4,"N",0,"D1","4.5*(0.58^0)","D2","4.5*(0.58^1)","D3","4.5*(0.58^2)","D4","4.5*(0.58^3)","D5","4.5*(0.59^4)","D6","4.5*(0.6^5)"};
			TransmissionRatios[] = {"High",7};
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
		thrustDelay = 0.5;
		brakeIdleSpeed = 1.78;
		simulation = "carx";
		dampersBumpCoef = 3.0;
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.5;
		rearBias = 1.5;
		centreBias = 1.3;
		clutchStrength = 20.0;
		dampingRateFullThrottle = 0.08;
		dampingRateZeroThrottleClutchEngaged = 0.5;
		dampingRateZeroThrottleClutchDisengaged = 0.35;
		torqueCurve[] = {{"(0/3500)","(0/425)"},{"(500/3500)","(200/425)"},{"(1500/3500)","(405/425)"},{"(2000/3500)","(425/425)"},{"(2500/3500)","(350/425)"},{"(3000/3500)","(300/425)"},{"(6000/3500)","(0/425)"}};
		changeGearMinEffectivity[] = {1,0.15,1,1,1,1,1,1};
		switchTime = 0.31;
		latency = 1.5;
		antiRollbarForceCoef = 1;
		antiRollbarForceLimit = 10;
		antiRollbarSpeedMin = 10;
		antiRollbarSpeedMax = 120;
		idleRpm = 400;
		redRpm = 3500;
		maxSpeed = 230;
		acceleration = 7.3;
		maxOmega = 450;
		enginePower = 150;
		peakTorque = 425;
		wheelCircumference = 2.805;
		fuelCapacity = 25;
		transportSoldier = 5;
		hiddenSelections[] = {"camo"};
		wheelDamageRadiusCoef = 0.9;
		wheelDestroyRadiusCoef = 0.4;
		maxFordingDepth = 0.0;
		//waterResistance = 1;
		crewCrashProtection = 0.25;
		armor = 35; 	/// just some protection against missiles, collisions and explosions
		mapSize = 20;

		class Turrets{}; /// doesn't have any gunner nor commander
		class TransportItems{};

		class Wheels
		{
			class LF
			{
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
				maxBrakeTorque = 1800;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.1;
				maxDroop = 0.145;
				sprungMass = 600;	//530
				springStrength = 15000; //13200
				springDamperRate = 2105;
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.5;
				latStiffY = 18;
				frictionVsSlipGraph[] = {{0,1.75},{0.5,1.35},{1,1.2}};
			};
			class LR: LF
			{
				boneName = "wheel_1_2_damper";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 2800;
				frictionVsSlipGraph[] = {{0,2},{0.5,1.53},{1,1.36}};
			};
			class RF: LF
			{
				boneName = "wheel_2_1_damper";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
				steering = 1;
				side = "right";
			};
			class RR: RF
			{
				boneName = "wheel_2_2_damper";
				steering = 0;
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
				maxHandBrakeTorque = 2800;
				frictionVsSlipGraph[] = {{0,2.3},{0.5,2.1},{1,2.0}};
			};
		};
		selectionBrakeLights = "brzdove svetlo";
		selectionBackLights = "zadni svetlo";
		class AnimationSources: AnimationSources
		{
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLF2Wheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRF2Wheel";
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
			class HitGlass1
			{
				source = "Hit";
				hitpoint = "HitGlass6";
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
			class HitGlass5: HitGlass1
			{
				hitpoint = "HitGlass5";
			};
			class HitGlass6: HitGlass1
			{
				hitpoint = "HitGlass6";
			};
			class HitGlass7: HitGlass1
			{
				hitpoint = "HitGlass7";
			};
			class HitGlass8: HitGlass1
			{
				hitpoint = "HitGlass8";
			};
		};
		class HitPoints
		{
			class HitLFWheel
			{
				armor = 0.1;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitLF2Wheel
			{
				armor = 0.1;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitRFWheel
			{
				armor = 0.1;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitRF2Wheel
			{
				armor = 0.1;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "";
				passThrough = 0.3;
				explosionShielding = 4;
			};
			class HitFuel
			{
				armor = 1.5;
				material = -1;
				name = "fueltank";
				visual = "";
				passThrough = 0.5;
				explosionShielding = 1.5;
				minimalHit = 0.1;
			};
			class HitEngine
			{
				armor = 0.5;
				material = -1;
				name = "engine";
				visual = "";
				passThrough = 0.5;
				explosionShielding = 0.5;
			};
			class HitBody
			{
				armor = 1.0;
				material = -1;
				name = "karoserie";
				visual = "camo";
				passThrough = 1;
				explosionShielding = 1.5;
			};
			class HitGlass1
			{
				armor = 0.25;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
				explosionShielding = 2;
			};
			class HitGlass2: HitGlass1 {name = "glass2"; visual = "glass2";};
			class HitGlass3: HitGlass1 {name = "glass3"; visual = "glass3";};
			class HitGlass4: HitGlass1 {name = "glass4"; visual = "glass4";};
			class HitGlass5: HitGlass1 {name = "glass5"; visual = "glass5";};
			class HitGlass6: HitGlass1 {name = "glass6"; visual = "glass6";};
			class HitGlass7: HitGlass1 {name = "glass7"; visual = "glass7";};
			class HitGlass8: HitGlass1 {name = "glass8"; visual = "glass8";};
		};

		#include "sounds.hpp"

		class Damage
		{
			tex[] = {};
			mat[] = 
			{
				"dsr_vehicles\suv\data\suv_body.rvmat",
				"dsr_vehicles\suv\data\suv_body_damage.rvmat",
				"dsr_vehicles\suv\data\suv_body_destruct.rvmat",
				
				"dsr_vehicles\suv\data\suv_chrom.rvmat",
				"dsr_vehicles\suv\data\suv_chrom_damage.rvmat",
				"dsr_vehicles\suv\data\suv_chrom_destruct.rvmat",

				"dsr_vehicles\suv\data\suv_glass.rvmat",
				"dsr_vehicles\suv\data\suv_glass_damage.rvmat",
				"dsr_vehicles\suv\data\suv_glass_damage.rvmat"
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust";
				direction = "exhaust_dir";
				effect = "ExhaustsEffect";
			};
			class Exhaust2
			{
				position = "exhaust2_pos";
				direction = "exhaust2_dir";
				effect = "ExhaustsEffect";
			};
		};
		#include "pip.hpp"
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[] = {1900,1800,1700};
				ambient[] = {5,5,5};
				position = "LightCarHeadL01";
				direction = "LightCarHeadL01_end";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 1;
				dayLight = 0;
				flareSize = 1.0;
				class Attenuation
				{
					start = 1.0;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			class LightCarHeadL02: LightCarHeadL01
			{
				position = "LightCarHeadL02";
				direction = "LightCarHeadL02_end";
				FlareSize = 0.5;
			};
			class LightCarHeadR01: LightCarHeadL01
			{
				position = "LightCarHeadR01";
				direction = "LightCarHeadR01_end";
				hitpoint = "Light_R";
				selection = "Light_R";
			};
			class LightCarHeadR02: LightCarHeadR01
			{
				position = "LightCarHeadR02";
				direction = "LightCarHeadR02_end";
				FlareSize = 0.5;
			};
		};
		aggregateReflectors[] = {{"LightCarHeadL01","LightCarHeadL02"},{"LightCarHeadR01","LightCarHeadR02"}};
	};
	class DSR_SUV_F: DSR_SUV_Base
	{
		displayName = "Tahoe";
		scope = 2;
		scopeCurator=2;
		side = 3;
		faction = "CIV_F";
		crew = "B_T_Pilot_F";
		typicalCargo[] = {"B_T_Pilot_F","C_man_1"};
		editorPreview = "\dsr_vehicles\suv\data\ui\picture_suv_ca.paa";
		hiddenSelectionsTextures[] ={"\dsr_vehicles\suv\data\suv_body_co.paa"};
	};
};