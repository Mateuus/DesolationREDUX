class CfgPatches
{
	class DSR_UH1H
	{
		units[]  = {"DSR_UH1H_F"};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"dsr_vehicles","A3_Air_F"};
	};
};
#include "crewanimations.hpp"
class CfgVehicles
{
	class Helicopter;
	class Helicopter_Base_F: Helicopter
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class AnimationSources;
		class RotorLibHelicopterProperties;
		class ViewOptics;
		class ViewPilot;
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class NewTurret;
		class Reflectors
		{
			class Right;
		};
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitAvionics;
			class HitVRotor;
			class HitHRotor;
		};
		class EventHandlers;
	};
	class DSR_UH1H_Base: Helicopter_Base_H
	{
		//expansion = 1;
		picture = "\dsr_vehicles\uh1h\data\ui\picture_uh1h_ca.paa";
		icon = "\dsr_vehicles\uh1h\data\ui\icon_uh1h_ca.paa";
		mapSize = 14;
		model = "dsr_vehicles\uh1h\uh1h.p3d";
		displayName = "UH1H - Huey";
		destrType = DestructWreck;
		
		cargoAction[] = {"UH1H_Cargo01_EP1","UH1Y_Cargo03","UH1Y_Cargo03","UH1Y_Cargo02","UH1Y_Cargo01","UH1Y_Cargo01","UH1Y_Cargo01"};
		cargoIsCoDriver[] = {0,0};
		memoryPointsGetInCargo = "pos cargo";		/// on what memory points should the cargo get in the heli
		memoryPointsGetInCargoDir = "pos cargo dir";/// what is the direction of the cargo facing during get in animation (and opposite for get out)
		hideWeaponsCargo = 1;						/// this makes the poses easier and adds some performance gain because the proxies don't need to be drawn
		cargoProxyIndexes[] = {1,2,3,4,5,6,7};		/// what indexes does regular cargo sit on
		transportSoldier = 5;
		driverAction = "UH1H_Pilot_EP1";
		driverInAction = "UH1H_Pilot_EP1";
		driverOpticsModel = "";
		gunnerOpticsModel = "";

		maximumLoad = 2000;			/// capacity of cargo inventory for backpacks and various other items
		cargoCanEject = 1;			/// cargo should be able to grab a chute and drop out of the vehicle
		driverCanEject = 0;			/// pilot shouldn't be able to do so as he doesn't have eject seat

		//threat[] VSoft, VArmor, VAir
		threat[] = {0.4, 0, 0};

		mainRotorSpeed = 1.2;
		backRotorSpeed = 6.1;

		soundGetIn[] = {"dsr_vehicles\uh1h\data\sounds\open_close",db-10,1};
		soundGetOut[] = {"dsr_vehicles\uh1h\data\sounds\open_close",db-10,1, 40};
		soundEngineOnInt[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_start_int", db-7, 1.0};
		soundEngineOnExt[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_start_ext", db-7, 1.0, 700};
		soundEngineOffInt[] =  {"dsr_vehicles\uh1h\data\sounds\uh1h_stop_int", db-7, 1.0};
		soundEngineOffExt[] =  {"dsr_vehicles\uh1h\data\sounds\uh1h_stop_ext", db-7, 1.0, 700};

		enableManualFire = 0;

		class ViewPilot: ViewPilot 	/// describes what does the pilot see using bare eyes
		{
			initFov = 0.75; 		/// this is the standard field of view angle for soldier, bit more narrow than a real-life one
			minFov = 0.375; 		/// this is how much can people "zoom" their view via focusing on something
			maxFov = 1.1;			/// this is how wide can the field of view be
		};
		class Viewoptics: Viewoptics 	/// pilot doesn't use optics in this vehicle
		{
			initAngleX = 0; 			/// initial horizontal angle of the optics view relative to proxy position of pilot
			minAngleX = 0; 				/// maximum turn to the left relative to proxy position of pilot
			maxAngleX = 0;				/// maximum turn to the right relative to proxy position of pilot
			initAngleY = 0; 			/// initial vertical angle of the optics view relative to proxy position of pilot
			minAngleY = 0; 				/// maximum elevation down relative to proxy position of pilot
			maxAngleY = 0;				/// maximum elevation up relative to proxy position of pilot
			initFov = 0.1; 				/// the same functionality as in ViewPilot
			minFov = 0.1;  				/// the same functionality as in ViewPilot
			maxFov = 1.2; 				/// the same functionality as in ViewPilot
		};

		class Sounds
		{
	/*External uh1h */
			class Engine
			{
				sound[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_engine_ext_2", db0, 1.0, 800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_rotor_ext_1", db8, 1.0, 1400};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.6,3.14, 2.0, 0.5};
			};
			class RotorHighOut
			{
				sound[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_rotor_high_ext_1", db8, 1.0, 1600};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.9))" ;
				cone[] = {1.6,3.14, 2.0, 0.5};
			};
	/*Internal uh1h */
  			class EngineIn
			{
				sound[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_engine_int_1", db0, 1.0};
				frequency = "rotorSpeed";
			 	volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_rotor_int_1", db5, 1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
			};
			class RotorHighIn
			{
				sound[] = {"dsr_vehicles\uh1h\data\sounds\uh1h_rotor_high_int_1", db10, 1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)" ;
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
				gunnerAction = "UH1H_Pilot_EP1";
				proxyIndex = 1;
				memoryPointsGetInGunner = "pos Codriver";
				memoryPointsGetInGunnerDir = "pos Codriver dir";
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
		class AnimationSources: AnimationSources {}; 
		class Reflectors: Reflectors			/// landing lights of the heli, turned on by AI while in night and "careless" or "safe"
		{
			class Right
			{
				color[] = {7000,7500,10000};	/// defines red, green, blue and alpha components of the light
				ambient[] = {70,75,100};		/// the same definition format for colouring the environment around
				intensity = 50;					/// how much does the light shine (in some strange units, just tweak until it is satisfying), rough approximation is intensity = (brightness * 50) ^ 2
				size = 1;						/// defines the visible size of light, has not much of an effect now
				innerAngle = 15;				/// angle from light direction vector where the light is at full strength
				outerAngle = 65;				/// angle from light direction vector where the light is completely faded out
				coneFadeCoef = 10;				/// coefficient of fading the light between inner and outer cone angles

				position = "Light_R_pos";		/// name of memory point in model to take the origin of the light
				direction = "Light_R_dir";		/// name of memory point in the model to make a vector of direction of light from it's position
				hitpoint = "Light_R_hitpoint";	/// name of hitpoint selection in hitpoint lod of the model to be affected by damage
				selection = "Light_R";			/// name of selection in visual lods of the model that are going to be hidden while the light is off

				useFlare = true;				/// boolean switch if the light produces flare or not
				flareSize = 10;					/// how big is the flare, using the same metrics as intensity
				flareMaxDistance = 250;			/// maximum distance where the flare is drawn

				dayLight = false;				/// boolean switch if the light is used during day or not

				class Attenuation
				{
					start = 0;					/// offset of start of the attenuation
					constant = 0;				/// constant attenuation of the light in any distance from source
					linear = 1;					/// coefficient for linear attenuation
					quadratic = 1;				/// coefficient for attenuation with square of distance from source

					hardLimitStart = 100;		/// distance from source where the light intensity decreases for drawing
					hardLimitEnd = 200;			/// distance from source where the light is not displayed (shorter distances increase performance)
				};
			};

			class Left: Right
			{
				position = "Light_L_pos";
				direction = "Light_L_dir";
				hitpoint = "Light_L_hitpoint";
				selection = "Light_L";
			};			
		};	
		aggregateReflectors[] = {{"Left", "Right"}};	/// aggregates both sources into one to increase performance
		#include "rtd.hpp" /// Advanced FM characteristics in separate file to make the config cleaner

		armor = 25;
		damageResistance = 0.00394;
		altFullForce = 5000;	/// in what height do the engines still have full thrust
		altNoForce = 6500;		/// thrust of the engines interpolates to zero between altFullForce and altNoForce
		maxSpeed = 300;			/// what is the maximum speed of the vehicle
		maxFordingDepth = 0.55;	/// how deep could the vehicle be in water without getting some damage
		mainBladeRadius = 9.0;	/// describes the radius of main rotor - used for collision detection
		//multiplier of lift force
		liftForceCoef = 1.0;	
		//multiplier of body friction
		bodyFrictionCoef = 0.85;	
		//multiplier of bank force
		cyclicAsideForceCoef = 0.75;
		//multiplier of dive force
		cyclicForwardForceCoef = 0.75;
		//multiplier of back rotor force
		backRotorForceCoef = 1.0;
		//driveOnComponent[] = {"Wheels"};

		class HitPoints: HitPoints
		{
			class HitFuel: HitFuel
			{
				visual = "";
				radius = 0.1;
				explosionShielding = 2;
				name = "motor";
				armor = 0.4;
				passThrough = 0.5;
			};
			class HitHull: HitHull
			{
				armor = 999;
				visual = "zbytek";
				depends = "Total";
				radius = 0.01;
			};
			class HitEngine: HitEngine
			{
				visual = "";
				radius = 0.2;
				explosionShielding = 2;
			};
			class HitAvionics: HitAvionics
			{
				armor = 1;
				visual = "";
				radius = 0.5;
				explosionShielding = 2;
			};
			class HitHRotor: HitHRotor
			{
				visual = "main rotor static";
				armor = 3;
				radius = 0.3;
				explosionShielding = 2.5;
			};
			class HitVRotor: HitVRotor
			{
				visual = "tail rotor static";
				armor = 2;
				radius = 0.06;
				explosionShielding = 6;
			};
			class HitGlass1
			{
				armor = 0.45;
				material = -1;
				name = "glass1";
				convexComponent = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2: HitGlass1
			{
				name = "glass2";
				convexComponent = "glass2";
				visual = "glass2";
			};
			class HitGlass3: HitGlass1
			{
				name = "glass3";
				convexComponent = "glass3";
				visual = "glass3";
			};
			class HitGlass4: HitGlass1
			{
				name = "glass4";
				convexComponent = "glass4";
				visual = "glass4";
			};
			class HitGlass5: HitGlass1
			{
				name = "glass5";
				convexComponent = "glass5";
				visual = "glass5";
			};
		};
		class Damage
			{
			tex[] = {};
			mat[] = {
				"dsr_vehicles\uh1h\data\uh1d.rvmat",
				"dsr_vehicles\uh1h\data\uh1d.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_destruct.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_cockpit1.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_cockpit1.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_cockpit1_destruct.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_cockpit2.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_cockpit2.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_cockpit2_destruct.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_cockpit3.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_cockpit3.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_cockpit3_destruct.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_glass.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_glass_damage.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_glass_damage.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_in.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_in.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_in_destruct.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_instruments.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_instruments.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_instruments_destruct.rvmat",

				"dsr_vehicles\uh1h\data\uh1d_rotor.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_rotor.rvmat",
				"dsr_vehicles\uh1h\data\uh1d_rotor_destruct.rvmat",

				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"dsr_vehicles\uh1h\data\default_destruct.rvmat",

				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"a3\data_f\default_destruct.rvmat"
			};
		};
		hiddenSelections[]  = {"Camo1","Camo2","Camo_mlod"};

		irScanRangeMin = 100;
		irScanRangeMax = 1000;
		irScanToEyeFactor = 2;
	};
	class DSR_UH1H_F: DSR_UH1H_Base
	{
		scope = 2;
		scopeCurator = 2;
		side = 3;
		faction = "CIV_F";
		crew = "B_T_Pilot_F";
		typicalCargo[] = {"B_T_Pilot_F","C_man_1"};
		class TransportMagazines{};
		class TransportWeapons{};
		hiddenSelectionsTextures[]  = 
		{
			"dsr_vehicles\uh1h\data\uh1d_co.paa",
			"dsr_vehicles\uh1h\data\uh1d_in_co.paa",
			"dsr_vehicles\uh1h\data\default_co.paa"
		};
	};
};