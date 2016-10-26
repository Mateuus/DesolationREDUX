#define _ARMA_

enum {
	stabilizedinaxisx = 1,
	stabilizedinaxesxyz = 4,
	stabilizedinaxisy = 2,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0
};

class CfgPatches
{
	class CAWheeled_2_SUV
	{
		units[] = {"DSR_SUV_F"};
		weapons[] = {};
		requiredVersion = 1.04;
		requiredAddons[] = {"dsr_vehicles"};
	};
};
#include "CrewAnimations.hpp"
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
		class NewTurret;
		class Turrets
		{
			class HitPoints;
		};
		class Eventhandlers;
		class AnimationSources;
	};
	class SUV_Base_F: Car_F
	{
		model = "\dsr_vehicles\suv\suv.p3d";  /// simple path to model
		Picture = "\dsr_vehicles\suv\data\ui\picture_suv_ca.paa"; /// just some icon in command bar
		Icon = "\dsr_vehicles\suv\data\ui\icon_suv_ca.paa"; /// icon in map
		displayName = "SUV - BigBen"; /// displayed in Editor
		hiddenSelections[] = {}; ///we want to allow changing the color of this selection
		terrainCoef 	= 6.5; 	/// different surface affects this car more, stick to tarmac
		turnCoef 		= 2.5; 	/// should match the wheel turn radius
		precision 		= 10; 	/// how much freedom has the AI for its internal waypoints - lower number means more precise but slower approach to way
		brakeDistance 	= 3.0; 	/// how many internal waypoints should the AI plan braking in advance
		acceleration 	= 20; 	/// how fast acceleration does the AI think the car has
		fireResistance 	= 5; 	/// lesser protection against fire than tanks
		armor 			= 35; 	/// just some protection against missiles, collisions and explosions
		cost			= 50000; /// how likely is the enemy going to target this vehicle
		transportMaxBackpacks 	= 3; /// just some backpacks fit the trunk by default
		transportSoldier 		= 5; /// number of cargo except driver
		hideWeaponsCargo = 1;
		wheelDamageRadiusCoef 	= 0.9; 			/// for precision tweaking of damaged wheel size
		wheelDestroyRadiusCoef 	= 0.4;			/// for tweaking of rims size to fit ground
		maxFordingDepth 		= 0.1;			/// how high water would damage the engine of the car
		waterResistance 		= 1;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.25;			/// multiplier of damage to crew of the vehicle => low number means better protection
		driverLeftHandAnimName 	= "drivewheel"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "drivewheel";	/// beware, non-existent bones may cause game crashes (even if the bones are hidden during play)
		
		//Cargo Shit
		memoryPointsGetInCargo = "pos cargo";		/// on what memory points should the cargo get in the heli
		memoryPointsGetInCargoDir = "pos cargo dir"; /// what is the direction of the cargo facing during get in animation (and opposite for get out)
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoAction[] = {"passenger_low01","passenger_generic01_leanleft","passenger_generic01_foldhands"};
		crewVulnerable = "true";
		cargocaneject = 1;	
		ejectDeadCargo = "false";
		
		//Driver Shit
		memoryPointsGetInDriver = "pos driver";  // only one door
		memoryPointsGetInDriverDir = "pos driver dir";  // only one door
		driverAction = "Driver_low01"; //SUV_Driver
		driverInAction = "GetInLow";
		DriverCanEject = 1;
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
		mapSize = 3;
		extCameraPosition[] = {0,1,-3};
		threat[] = {0.0,0.0,0.0};
		rarityUrban = -1;
		vehicleClass = "Car";
		
		secondaryExplosion = 0;
		outsideSoundFilter = true;
		leftDustEffect = "NoDust";
		rightDustEffect = "NoDust";
		
		class PlayerSteeringCoefficients /// steering sensitivity configuration
		{
			 turnIncreaseConst = 0.3; // basic sensitivity value, higher value = faster steering
			 turnIncreaseLinear = 1.0; // higher value means less sensitive steering in higher speed, more sensitive in lower speeds
			 turnIncreaseTime = 1.0; // higher value means smoother steering around the center and more sensitive when the actual steering angle gets closer to the max. steering angle
			 turnDecreaseConst = 5.0; // basic caster effect value, higher value = the faster the wheels align in the direction of travel
			 turnDecreaseLinear = 3.0; // higher value means faster wheel re-centering in higher speed, slower in lower speeds
			 turnDecreaseTime = 0.0; // higher value means stronger caster effect at the max. steering angle and weaker once the wheels are closer to centered position
			 maxTurnHundred = 0.7; // coefficient of the maximum turning angle @ 100km/h; limit goes linearly to the default max. turn. angle @ 0km/h
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust";
				direction = "exhaust_dir";
				effect = "ExhaustsEffect";
			};
		};
		class CargoTurret;
		class Turrets: Turrets
		{
			class CargoTurret_03: CargoTurret
			{
				gunnerAction = "suv_cargo_front_left_side";
				gunnerCompartments = "Compartment5";
				memoryPointsGetInGunner = "pos external1L";
				memoryPointsGetInGunnerDir = "pos external1L dir";
				gunnerName = "Passenger (Hold Front Left)";
				proxyIndex = 7;
				maxElev = 65;
				minElev = -10;
				maxTurn = 105;
				minTurn = 50;
				isPersonTurret = 0;
				ejectDeadGunner = 1;
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				class dynamicViewLimits{};
			};
			class CargoTurret_04: CargoTurret_03
			{
				gunnerAction = "suv_cargo_back_side";
				gunnerCompartments = "Compartment5";
				memoryPointsGetInGunner = "pos external2L";
				memoryPointsGetInGunnerDir = "pos external2L dir";
				gunnerName = "Passenger (Hold Middle Left)";
				proxyIndex = 8;
				maxTurn = 105;
				minTurn = 50;
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				class dynamicViewLimits{};
			};
			class CargoTurret_05: CargoTurret_04
			{
				gunnerAction = "suv_cargo_back_side";
				gunnerCompartments = "Compartment5";
				memoryPointsGetInGunner = "pos external3L";
				memoryPointsGetInGunnerDir = "pos external3L dir";
				gunnerName = "Passenger (Hold Back Left)";
				proxyIndex = 9;
				maxTurn = 105;
				minTurn = 50;
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				class dynamicViewLimits{};
			};
			class CargoTurret_06: CargoTurret
			{
				gunnerAction = "suv_cargo_front_right_side";
				gunnerCompartments = "Compartment6";
				memoryPointsGetInGunner = "pos external1R";
				memoryPointsGetInGunnerDir = "pos external1R dir";
				gunnerName = "Passenger (Hold Front Right)";
				proxyIndex = 12;
				maxElev = 65;
				minElev = -10;
				maxTurn = 105;
				minTurn = 50;
				isPersonTurret = 0;
				ejectDeadGunner = 1;
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				class dynamicViewLimits{};
			};
			class CargoTurret_07: CargoTurret_06
			{
				gunnerAction = "suv_cargo_back_side";
				gunnerCompartments = "Compartment6";
				memoryPointsGetInGunner = "pos external2R";
				memoryPointsGetInGunnerDir = "pos external2R dir";
				gunnerName = "Passenger (Hold Middle Right)";
				proxyIndex = 11;
				maxTurn = 105;
				minTurn = 50;
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				class dynamicViewLimits{};
			};
			class CargoTurret_08: CargoTurret_07
			{
				gunnerAction = "suv_cargo_back_side";
				gunnerCompartments = "Compartment6";
				memoryPointsGetInGunner = "pos external3R";
				memoryPointsGetInGunnerDir = "pos external3R dir";
				gunnerName = "Passenger (Hold Back Right)";
				proxyIndex = 10;
				maxTurn = 105;
				minTurn = 50;
				memoryPointGunnerOptics = "eye";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				class dynamicViewLimits{};
			};
		};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor = 0.125;
				passThrough = 0;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor = 0.125;
				passThrough = 0;
			};
			class HitRFWheel: HitRFWheel
			{
				armor = 0.125;
				passThrough = 0;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor = 0.125;
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = 0.2;
			};
			class HitEngine
			{
				armor = 0.5;
				material = -1;
				name = "engine";
				visual = "";
				passThrough = 0.2;
			};
			class HitBody: HitBody
			{
				name = "body";
				visual = "camo";
				passThrough = 1;
			};
			class HitGlass1: HitGlass1
			{
				armor = 0.25;
			};
			class HitGlass2: HitGlass2
			{
				armor = 0.25;
			};
			class HitGlass3: HitGlass3
			{
				armor = 0.25;
			};
			class HitGlass4: HitGlass4
			{
				armor = 0.25;
			};
		};
		#include "sounds.hpp"
		thrustDelay = 0.5;
		brakeIdleSpeed = 1.78;
		maxSpeed = 245;
		fuelCapacity = 45;
		wheelCircumference = 2.277;
		idleRpm = 1000;
		redRpm = 7000;
		antiRollbarForceCoef = 3.9;
        antiRollbarForceLimit = 40;
        antiRollbarSpeedMin = 2;
        antiRollbarSpeedMax = 150;
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-2.475,"N",0,"D1",2.367,"D2",1.67,"D3",1.238,"D4",0.99,"D5",0.802,"D6",0.601};
			TransmissionRatios[] = {"High",7};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		simulation = "carx";
		dampersBumpCoef = 3;
		differentialType = "all_limited";
		frontRearSplit = 0.5;
		frontBias = 1.9;
		rearBias = 1.9;
		centreBias = 1.9;
		clutchStrength = 80;
		enginePower = 324;
		maxOmega = 733;
		peakTorque = 666;
		dampingRateFullThrottle = 0.1;
		dampingRateZeroThrottleClutchEngaged = 2;
		dampingRateZeroThrottleClutchDisengaged = 0.35;
		torqueCurve[] = {{0,0.15},{0.25,0.65},{0.35,0.75},{0.461,1},{0.6,0.95},{0.7,0.85},{0.8,0.75},{1,0.5}};
		changeGearMinEffectivity[] = {0.95,0.15,0.95,0.95,0.95,0.95,0.95};
		switchTime = 0.31;
		latency = 1;
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
				dampingRate = 0.5;
				maxBrakeTorque = 10000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				maxCompression = 0.1;
				//maxDroop = 0.05;
				mMaxDroop = 0.2;
				sprungMass = 710;
				springStrength = 71050;
				springDamperRate = 5936;
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.3;
				latStiffY = 18;
				frictionVsSlipGraph[] = {{0,1},{0.5,1},{1,1}};
			};
			class LR: LF
			{
				boneName = "wheel_1_2_damper";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxHandBrakeTorque = 3000;
				latStiffY = 180;
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
				maxHandBrakeTorque = 3000;
				latStiffY = 180;
			};
		};
		memoryPointTrackFLL = "TrackFLL";
		memoryPointTrackFLR = "TrackFLR";
		memoryPointTrackBLL = "TrackBLL";
		memoryPointTrackBLR = "TrackBLR";
		memoryPointTrackFRL = "TrackFRL";
		memoryPointTrackFRR = "TrackFRR";
		memoryPointTrackBRL = "TrackBRL";
		memoryPointTrackBRR = "TrackBRR";
		dustFrontLeftPos = "dustFrontLeft";
		dustFrontRightPos = "dustFrontRight";
		dustBackLeftPos = "dustBackLeft";
		dustBackRightPos = "dustBackRight";
		class Damage
		{
			tex[] = {};
			mat[] = {"dsr_vehicles\suv\data\suv_body.rvmat","dsr_vehicles\suv\data\suv_body_damage.rvmat","dsr_vehicles\suv\data\suv_body_destruct.rvmat","dsr_vehicles\suv\data\suv_chrom.rvmat","dsr_vehicles\suv\data\suv_chrom_damage.rvmat","dsr_vehicles\suv\data\suv_chrom_destruct.rvmat","dsr_vehicles\suv\data\suv_glass.rvmat","dsr_vehicles\suv\data\suv_glass_damage.rvmat","dsr_vehicles\suv\data\suv_glass_damage.rvmat"};
		};
	};
	class DSR_SUV_F: SUV_Base_F
	{
		displayName = "Suburban";
		scope = 2;
		scopeCurator=2;		// scope 2 means it's available in Zeus mode (0 means hidden)
		side = 3;
		faction = "CIV_F";
		crew = "C_man_1";
		typicalCargo[] = {"C_man_1"};
		Picture = "\dsr_vehicles\suv\data\ui\picture_suv_ca.paa"; /// just some icon in command bar
		Icon = "\dsr_vehicles\suv\data\ui\icon_suv_ca.paa"; /// icon in map
	};
};