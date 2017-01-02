class CfgPatches
{
	class DSR_FishingBoat
	{
		units[] ={"DSR_FishingBoat_F"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"dsr_vehicles"};
	};
};
#include "crewanimations.hpp"
class CfgVehicles
{
	class Ship
	{
		class ViewPilot;
	};
	class Ship_F: Ship
	{
		class AnimationSources;
		class Eventhandlers;
	};
	class DSR_FishingBoat_Base_F: Ship_F
	{
		displayName	= "Fishing Boat";  /// displayed in Editor
		model		= "\dsr_vehicles\fishing_boat\fishing_boat.p3d";/// simple path to model
		picture		= "\A3\Weapons_F\Data\placeholder_co.paa"; /// just some icon in command bar
		Icon		= "\A3\Weapons_F\Data\placeholder_co.paa"; /// icon in map
		cost		= 20000; /// how likely is the enemy going to target this vehicle
		accuracy	= 0.50; /// knowledge required to recognize this type of target
		vehicleClass = "Ship";
		/*
		class HitPoints
		{
			class HitBody
			{
				armor = 0.6;
				material = 50;
				name = "hull";
				visual = "zbytek";
				passThrough = 1;
			};
			class HitEngine
			{
				armor = 1.2;
				material = -1;
				name = "Engine";
				visual = "";
				passThrough = 1;
			};
			class HitFuel
			{
				armor = 0.4;
				material = 25;
				name = "fuel";
				visual = "fuel";
				passThrough = 1;
			};
		};
		*/
		simulation					= "shipx";  /// all ships should have this simulation
		maxSpeed					= 60;		/// top speed of the vehicle
		overSpeedBrakeCoef			= 0.8;		/// how much does the vehicle itself brake in case it goes faster than maxSpeed
		enginePower					= 800;		/// power of engine in kW
		engineShiftY				= -0.1;		/// relative virtual position of engine for PhysX, affects lateral ship slope during turns
		waterLeakiness				= 0.65;		/// amount of litres per second that leaks into ship if under water, destroyed or turned upside down
		turnCoef 					= 0.25; 	/// how well is the ship able to turn
		thrustDelay 				= 2.0;		/// initial delay to cause lesser slip when on 1st gear - thrust goes from zero to full in this time
		waterLinearDampingCoefY 	= 2;		/// affect how fast does the ship go through waves down - higher values make it drift more on top of waves
		waterLinearDampingCoefX 	= 2.0;		/// affects sliding of the ship in turns
		waterAngularDampingCoef 	= 1.2;		/// increase this for smoother movement, but beware too high values
		waterResistanceCoef 		= 0.015;	/// how much does water slow the ship down
		rudderForceCoef				= 0.03;		/// increase this to gain more turning on lower speeds
		rudderForceCoefAtMaxSpeed	= 0.002;	/// increase this to gain more turning on higher speeds
		idleRpm = 200;							/// revolutions per minute at which the engine idles
		redRpm = 1200;							/// maximum revolutions per minute of the engine
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-0.782,"N",0,"D1",2.0,"D2",1.85,"D3",1.75};
			TransmissionRatios[] = {"High",1.0};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		fuelExplosionPower = 1;
		brakeDistance = 3; // how many internal waypoints should the AI plan braking in advance

		class Turrets {};

		//Driver
		driverAction = "Fishing_Driver"; /// what action is going the driver take inside the vehicle. Non-existent action makes the vehicle inaccessible
		driverLeftHandAnimName 	 = "volant"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "volant"; /// according to what bone in model of car does hand move
		driverLeftLegAnimName = "";
		driverRightLegAnimName = "";
		memoryPointsGetInDriver = "pos driver"; // only one door
		memoryPointsGetInDriverDir = "pos driver dir"; // only one door
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		ejectDeadDriver = false;			/// use this if you don't have proper dead pose for the driver, it will eject him from boat if he dies

		//Cargo
		ejectDeadCargo = 0;
		memoryPointsGetInCargo[] = {"pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos cargo dir"};
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoAction[] = {"Fishing_Seat"};
		hideWeaponsCargo = 1;						// this makes the poses easier and adds some performance gain because the proxies dont need to be drawn
		//cargocaneject = 1;
		//cargoCompartments[] = {"Compartment1"};
		cargoIsCoDriver[] = {false};			/// there is no special co-driver entry point on the boat

		transportSoldier = 4;				/// number of cargo except driver
		armor = 10;						/// just some protection against missiles, collisions and explosions
		damageResistance = 0.00318;		/// for AI if it is worth to be shoot at
		#include "sounds.hpp"			/// sounds are included from separate file to not clutter the rest of file
		class Reflectors {};			/// there are no reflectors on this boat, check Test_Car_01 for some examples
		class Damage /// damage changes material in specific places (visual in hitPoint)
		{
			tex[] = {};
			mat[] = {
				"dsr_vehicles\fishing_boat\data\fishboat_001.rvmat",
				"dsr_vehicles\fishing_boat\data\fishboat_001_damage.rvmat",
				"dsr_vehicles\fishing_boat\data\fishboat_001_destruct.rvmat",
				"dsr_vehicles\fishing_boat\data\fishboat_002.rvmat",
				"dsr_vehicles\fishing_boat\data\fishboat_002_damage.rvmat",
				"dsr_vehicles\fishing_boat\data\fishboat_002_destruct.rvmat"
			};
		};
		extCameraPosition[] 	 = {0,4.0,-14.0};			/// provides offset of external camera in {side, height, to front} format
		leftFastWaterEffect 	 = "LFastWaterEffects";		/// defines what class of water effect is going to be used while sailing fast
		rightFastWaterEffect 	 = "RFastWaterEffects";		/// defines what class of water effect is going to be used while sailing fast
		leftEngineEffect 		 = "LEngEffectsSmall"; 		/// Particle effect class for engine particles
		rightEngineEffect 		 = "REngEffectsSmall";
		waterEffectSpeed 		 = 8;						/// limit of displaying the standard water effect
		engineEffectSpeed 		 = 3;						/// limit of displaying the engine effect
		waterFastEffectSpeed 	 = 20;						/// limit where the standard water effect changes to the fast sailing one
		class ViewPilot: ViewPilot
		{
			minFov = 0.35;
			maxFov = 1.00;
			initFov = 0.75;
			initAngleX = 0;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class Exhausts
		{
		    class Exhaust1
		    {
		   		position="vyfuk start";
		   		direction="vyfuk konec";
			 	effect="ExhaustsEffect";
		    };
		};
		class Eventhandlers: Eventhandlers	/// specific event handlers to handle variants - by default are all shown, event handlers hide them
		{
			init="if (local (_this select 0)) then {[(_this select 0), """", [], nil] call bis_fnc_initVehicle;};"; // Run the VhC function to be sure to set the animation sources and textures accordingly to the properties animationList and textureList
			killed = "if (local (_this select 0)) then {[(_this select 0), nil, [], false] call bis_fnc_initVehicle;};"; // Run the VhC to set the animation sources but not the texture source "nil"
		};
		hiddenSelections[] 			 = {"camo", "camo2"}; 	/// we want to allow changing of colours, this defines on what selection are the textures used
		hiddenSelectionsTextures[]	 =
		{ /// and here are the textures, in the same order as the hidden selections
			//"\dsr_vehicles\raftwm\data\raftwm_barrels_co.paa",
			//"\dsr_vehicles\raftwm\data\raftwm_wood_co.paa"
		};
		class AnimationSources{};
	};
	class DSR_FishingBoat_F: DSR_FishingBoat_Base_F
	{
		scope			 = 2;					/// scope 2 means it is available in editor, this is one of the macros in basicdefines_a3.hpp
		scopeCurator	 = 2;						// scope 2 means it's available in Zeus mode (0 means hidden)
		displayName		 = "Fishing Boat"; 	/// how does the vehicle show itself in editor
		side			 = 3;						/// 3 stands for civilians, 0 is OPFOR, 1 is BLUFOR, 2 means guerrillas
		faction			 = CIV_F;					/// defines the faction inside of the side
		crew 			 = "C_man_1";						/// lets use the sample soldier we have as default captain of the boat
		typicalCargo[] = {"C_man_1"};
	};
};
