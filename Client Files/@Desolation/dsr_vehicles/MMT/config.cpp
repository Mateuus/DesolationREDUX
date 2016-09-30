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
	class CAWheeled_2_MMT
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.04;
		requiredAddons[] = {"dsr_vehicles"};
	};
};
#include "CrewAnimations.hpp"
class NoDust{};
class CfgVehicles
{
	class Bicycle;
	class MMT_base: Bicycle
	{
		model 	= "\dsr_vehicles\MMT\MMT";  /// simple path to model
		picture	= "\dsr_vehicles\MMT\data\UI\Picture_MMT_CA.paa"; /// just some icon in command bar
		Icon	= "\dsr_vehicles\MMT\data\UI\Icon_MMT_CA.paa"; /// icon in map
		displayName = "MMT - ANixon"; /// displayed in Editor
		hiddenSelections[] = {}; ///we want to allow changing the color of this selection
		terrainCoef 	= 6.5; 	/// different surface affects this car more, stick to tarmac
		turnCoef 		= 2; 	/// should match the wheel turn radius
		precision 		= 10; 	/// how much freedom has the AI for its internal waypoints - lower number means more precise but slower approach to way
		brakeDistance 	= 3.0; 	/// how many internal waypoints should the AI plan braking in advance
		acceleration 	= 15; 	/// how fast acceleration does the AI think the car has
		fireResistance 	= 5; 	/// lesser protection against fire than tanks
		armor 			= 5; 	/// just some protection against missiles, collisions and explosions
		cost			= 50000; /// how likely is the enemy going to target this vehicle
		transportMaxBackpacks 	= 0; /// just some backpacks fit the trunk by default
		transportSoldier 		= 0; /// number of cargo except driver
		wheelDamageRadiusCoef 	= 0.9; 			/// for precision tweaking of damaged wheel size
		wheelDestroyRadiusCoef 	= 0.4;			/// for tweaking of rims size to fit ground
		maxFordingDepth 		= 0.5;			/// how high water would damage the engine of the car
		waterResistance 		= 1;			/// if the depth of water is bigger than maxFordingDepth it starts to damage the engine after this time
		crewCrashProtection		= 0.25;			/// multiplier of damage to crew of the vehicle => low number means better protection
		driverLeftHandAnimName 	= "volant"; /// according to what bone in model of car does hand move
		driverRightHandAnimName = "volant";	/// beware, non-existent bones may cause game crashes (even if the bones are hidden during play)
		wheelCircumference = 2.28;
		mapSize = 3;
		maxSpeed = 35;
		isBicycle = 1;
		extCameraPosition[] = {0,1,-3};
		threat[] = {0.0,0.0,0.0};
		rarityUrban = -1;
		vehicleClass = "Car";
		weapons[] = {"BikeHorn"};
		driverAction = "MMT_Driver";
		driverInAction = "MMT_Driver";
		attenuationEffectType = "OpenCarAttenuation";
		cargoAction[] = {"MMT_Driver"};
		secondaryExplosion = 0;
		outsideSoundFilter = 0;
		DirverCanEject = 1;
		leftDustEffect = "NoDust";
		rightDustEffect = "NoDust";
		soundGear[] = {"",0.0005623413,1};
		SoundGetIn[] = {"",0.017782794,1};
		SoundGetOut[] = {"",0.017782794,1};
		soundEngineOnInt[] = {"",0.35481337,1.0};
		soundEngineOnExt[] = {"",0.35481337,1.0};
		soundEngineOffInt[] = {"",0.35481337,1.0};
		soundEngineOffExt[] = {"",0.35481337,1.0};
		buildCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_01",1,1,200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_02",1,1,200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_03",1,1,200};
		buildCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_04",1,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_01",1,1,200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_02",1,1,200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_03",1,1,200};
		WoodCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_04",1,1,200};
		WoodCrash4[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_05",1,1,200};
		WoodCrash5[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_06",1,1,200};
		soundWoodCrash[] = {"woodCrash0",0.166,"woodCrash1",0.166,"woodCrash2",0.166,"woodCrash3",0.166,"woodCrash4",0.166,"woodCrash5",0.166};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_01",1,1,200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_02",1,1,200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_03",1,1,200};
		ArmorCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_04",1,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[] = {"",0.56234133,1.0};
				limit = "0.2";
				expression = "(engineOn*(1-camPos))*thrust";
			};
			class AccelerationOut
			{
				sound[] = {"",0.56234133,1.0};
				limit = "0.2";
				expression = "(engineOn*camPos)*thrust";
			};
		};
		dammageHalf[] = {};
		dammageFull[] = {};
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"",0.316228,1,100};
				frequency = 1;
				volume = "engineOn*camPos*(((rpm/	2000) factor[(200/	2000),(400/	2000)])	*	((rpm/	2000) factor[(750/	2000),( 600/	2000)]))";
			};
			class Engine
			{
				sound[] = {"dsr_vehicles\MMT\data\sounds\low1",0.177828,1.0,35};
				frequency = "(randomizer*0.01+1.0)*rpm";
				volume = "(3+(camPos*engineOn*((speed factor[0.1, 0.6]) min (speed factor[0.6, 0.1]))))";
			};
			class Engine1_ext
			{
				sound[] = {"",0.398107,1,200};
				frequency = "0.9	+	((rpm/	2000) factor[(800/	2000),(1300/	2000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	2000) factor[(780/	2000),(1000/	2000)])	*	((rpm/	2000) factor[(1300/	2000),( 1100/	2000)]))";
			};
			class Engine2_ext
			{
				sound[] = {"",0.446684,1,250};
				frequency = "0.9	+	((rpm/	2000) factor[(1080/	2000),(1560/	2000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	2000) factor[(1100/	2000),(1280/	2000)])	*	((rpm/	2000) factor[(1570/	2000),( 1380/	2000)]))";
			};
			class Engine3_ext
			{
				sound[] = {"",0.501187,1,250};
				frequency = "0.95	+	((rpm/	2000) factor[(1380/	2000),(1860/	2000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	2000) factor[(1350/	2000),(1550/	2000)])	*	((rpm/	2000) factor[(1870/	2000),( 1630/	2000)]))";
			};
			class Engine4_ext
			{
				sound[] = {"",0.562341,1,300};
				frequency = "0.95	+	((rpm/	2000) factor[(1630/	2000),(2000/	2000)]) *0.2";
				volume = "engineOn*camPos*((rpm/	2000) factor[(1650/	2000),(1900/	2000)])";
			};
			class IdleThrust
			{
				sound[] = {"",0.562341,1,150};
				frequency = 1;
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(200/	2000),(400/	2000)])	*	((rpm/	2000) factor[(750/	2000),( 600/	2000)]))";
			};
			class EngineThrust
			{
				sound[] = {"",0.630957,1,200};
				frequency = "0.9	+	((rpm/	2000) factor[(600/	2000),(1000/	2000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(600/	2000),(730/	2000)])	*	((rpm/	2000) factor[(1020/	2000),( 800/	2000)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"",0.707946,1,250};
				frequency = "0.9	+	((rpm/	2000) factor[(800/	2000),(1300/	2000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(780/	2000),(1000/	2000)])	*	((rpm/	2000) factor[(1300/	2000),( 1100/	2000)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"",0.794328,1,300};
				frequency = "0.9	+	((rpm/	2000) factor[(1080/	2000),(1560/	2000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(1100/	2000),(1280/	2000)])	*	((rpm/	2000) factor[(1570/	2000),( 1380/	2000)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[] = {"",0.891251,1,350};
				frequency = "0.95	+	((rpm/	2000) factor[(1380/	2000),(1860/	2000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(1350/	2000),(1550/	2000)])	*	((rpm/	2000) factor[(1870/	2000),( 1630/	2000)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[] = {"",1,1,400};
				frequency = "0.95	+	((rpm/	2000) factor[(1630/	2000),(2000/	2000)]) *0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	2000) factor[(1650/	2000),(1900/	2000)])";
			};
			class Idle_int
			{
				sound[] = {"",0.251189,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(((rpm/	2000) factor[(200/	2000),(400/	2000)])	*	((rpm/	2000) factor[(750/	2000),( 600/	2000)]))";
			};
			class Engine_int
			{
				sound[] = {"",0.281838,1};
				frequency = "0.9	+	((rpm/	2000) factor[(600/	2000),(1000/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	2000) factor[(600/	2000),(730/	2000)])	*	((rpm/	2000) factor[(1020/	2000),( 800/	2000)]))";
			};
			class Engine1_int
			{
				sound[] = {"",0.316228,1};
				frequency = "0.9	+	((rpm/	2000) factor[(800/	2000),(1300/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	2000) factor[(780/	2000),(1000/	2000)])	*	((rpm/	2000) factor[(1300/	2000),( 1100/	2000)]))";
			};
			class Engine2_int
			{
				sound[] = {"",0.354813,1};
				frequency = "0.9	+	((rpm/	2000) factor[(1080/	2000),(1560/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	2000) factor[(1100/	2000),(1280/	2000)])	*	((rpm/	2000) factor[(1570/	2000),( 1380/	2000)]))";
			};
			class Engine3_int
			{
				sound[] = {"",0.398107,1};
				frequency = "0.95	+	((rpm/	2000) factor[(1380/	2000),(1860/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	2000) factor[(1350/	2000),(1550/	2000)])	*	((rpm/	2000) factor[(1870/	2000),( 1630/	2000)]))";
			};
			class Engine4_int
			{
				sound[] = {"",0.446684,1};
				frequency = "0.95	+	((rpm/	2000) factor[(1630/	2000),(2000/	2000)]) *0.2";
				volume = "engineOn*(1-camPos)*((rpm/	2000) factor[(1650/	2000),(1900/	2000)])";
			};
			class IdleThrust_Int
			{
				sound[] = {"",0.562341,1};
				frequency = 1;
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(200/	2000),(400/	2000)])	*	((rpm/	2000) factor[(750/	2000),( 600/	2000)]))";
			};
			class EngineThrust_Int
			{
				sound[] = {"",0.630957,1};
				frequency = "0.9	+	((rpm/	2000) factor[(600/	2000),(1000/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(600/	2000),(730/	2000)])	*	((rpm/	2000) factor[(1020/	2000),( 800/	2000)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"",0.707946,1};
				frequency = "0.9	+	((rpm/	2000) factor[(800/	2000),(1300/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(780/	2000),(1000/	2000)])	*	((rpm/	2000) factor[(1300/	2000),( 1100/	2000)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"",0.794328,1};
				frequency = "0.9	+	((rpm/	2000) factor[(1080/	2000),(1560/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(1100/	2000),(1280/	2000)])	*	((rpm/	2000) factor[(1570/	2000),( 1380/	2000)]))";
			};
			class Engine3_Thrust_int
			{
				sound[] = {"",0.891251,1};
				frequency = "0.95	+	((rpm/	2000) factor[(1380/	2000),(1860/	2000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	2000) factor[(1350/	2000),(1550/	2000)])	*	((rpm/	2000) factor[(1870/	2000),( 1630/	2000)]))";
			};
			class Engine4_Thrust_int
			{
				sound[] = {"",1,1};
				frequency = "0.95	+	((rpm/	2000) factor[(1630/	2000),(2000/	2000)]) *0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	2000) factor[(1650/	2000),(1900/	2000)])";
			};
			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",1,1,60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",1,1,60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",1,1,60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",1,1,60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",1,1,60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",1,1,60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\quadbike_noise_04",0.891251,1,90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 15])";
			};
			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",0.630957,1};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand2",0.630957,1};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",0.630957,1};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",0.630957,1};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",0.630957,1};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",0.501187,1};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\quadbike_noise_04",0.562341,1};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 15])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",0.707946,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.707946,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.707946,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.707946,1,80};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking",0.707946,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 10])";
			};
			class acceleration_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration",0.707946,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.707946,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.707946,1,60};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 6])";
			};
			class acceleration_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
			class breaking_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-0.15, -0.3])*(Speed Factor[2, 6])";
			};
			class acceleration_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.15, 0.3])*(Speed Factor[10, 0])";
			};
			class turn_left_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.15, 0.3])*(Speed Factor[0, 10])";
			};
			class turn_right_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.501187,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.15, -0.3])*(Speed Factor[0, 10])";
			};
		};
		class Reflectors{};
		
		class PlayerSteeringCoefficients /// steering sensitivity configuration
		{
           turnIncreaseConst  = 25.0; // basic sensitivity value, higher value = faster steering
           turnIncreaseLinear = 0.1; // higher value means less sensitive steering in higher speed, more sensitive in lower speeds
           turnIncreaseTime   = 1.0; // higher value means smoother steering around the center and more sensitive when the actual steering angle gets closer to the max. steering angle
           turnDecreaseConst  = 1.0; // basic caster effect value, higher value = the faster the wheels align in the direction of travel
           turnDecreaseLinear = 2.5; // higher value means faster wheel re-centering in higher speed, slower in lower speeds
           turnDecreaseTime   = 0.0; // higher value means stronger caster effect at the max. steering angle and weaker once the wheels are closer to centered position
           maxTurnHundred     = 0.7; // coefficient of the maximum turning angle @ 100km/h; limit goes linearly to the default max. turn. angle @ 0km/h
		};
		
		class Library
		{
			libTextDesc = "hossass";
		};
		class DestructionEffects{};
		class HitPoints
		{
			class HitRGlass
			{
				armor = 0.3;
				material = -1;
				name = "sklo predni P";
				passThrough = 0;
			};
			class HitLGlass
			{
				armor = 0.3;
				material = -1;
				name = "sklo predni L";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = 51;
				name = "karoserie";
				visual = "";
				passThrough = 1;
			};
			class HitFuel
			{
				armor = 0.3;
				material = 51;
				name = "palivo";
				passThrough = 0;
			};
			class HitFWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_damper";
				visual = "wheel_1";
				passThrough = 0;
			};
			class HitBWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_damper";
				visual = "wheel_2";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0;
			};
		};
		class AnimationSources
		{
			class Hit_wheel_1
			{
				source = "Hit";
				hitpoint = "HitFWheel";
				raw = 1;
			};
			class Hit_wheel_2: Hit_wheel_1
			{
				hitpoint = "HitBWheel";
			};
		};
	};
	class DSR_bike_F: MMT_base
	{
		displayName = "Mountain Bike";
		scope = 2;
		scopeCurator=2;		// scope 2 means it's available in Zeus mode (0 means hidden)
		side = 3;
		faction = "CIV_F";
		crew = "C_man_1";
		typicalCargo[] = {"C_man_1"};
	};
};