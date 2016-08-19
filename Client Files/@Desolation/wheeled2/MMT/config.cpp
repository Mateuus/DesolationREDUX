////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.53
//'now' is Tue Nov 12 17:54:53 2013 : 'file' last modified on Tue Nov 12 17:54:53 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//ndefs=4
enum {
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	STABILIZEDINAXESNONE = 0
};

//Class L:\SteamLibrary\steamapps\common\Arma 3\@Desolation\Addons\wheeled2\MMT\config.bin{
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		MMT_Driver = "MMT_Driver";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class MMT_Dead: DefaultDie
		{
			actions = "DeadActions";
			file = "\ca\wheeled2\MMT\DATA\anim\MMT_Driver.rtm";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
		};
		class Crew;
		class MMT_Driver: Crew
		{
			file = "\ca\wheeled2\MMT\DATA\anim\MMT_Driver.rtm";
			connectTo[] = {"MMT_Dead",1};
			speed = 2;
			looped = 1;
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class ManActions
	{
		MMT_Driver = "";
	};
};
class CfgPatches
{
	class CAWheeled2_MMT
	{
		units[] = {"MMT_Civ","MMT_USMC"};
		weapons[] = {};
		requiredVersion = 0.1;
	};
};
class NoDust{};
class CfgVehicles
{
	class Bicycle;
	class MMT_base: Bicycle
	{
		class Library
		{
			libTextDesc = "$STR_LIB_MMT";
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
		class Sounds
		{
			class Engine
			{
				sound[] = {"Ca\sounds\Vehicles\Wheeled\MMT\low1",0.177828,1.0,35};
				frequency = "(randomizer*0.01+1.0)*rpm";
				volume = "(3+(camPos*engineOn*((speed factor[0.1, 0.6]) min (speed factor[0.6, 0.1]))))";
			};
			class EngineHighOut
			{
				sound[] = {"Ca\sounds\Vehicles\Wheeled\MMT\high1",0.177828,1.0,50};
				frequency = "(randomizer*0.05+1.0)*rpm";
				volume = "3+(0.5+(camPos*engineOn*(speed factor[0.4, 0.9])))";
			};
			class IdleOut
			{
				sound[] = {"Ca\sounds\Vehicles\Wheeled\MMT\idle",0.17782794,1.0,35};
				frequency = "1";
				volume = "camPos*engineOn*(speed factor[0.05, 0.9])";
			};
			class TiresRockOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-rock2",0.031623,1.0,8};
				frequency = "1";
				volume = "3+(4*(camPos*rock*(speed factor[2, 20])))";
			};
			class TiresSandOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-sand2",0.031623,1.0,8};
				frequency = "1";
				volume = "3+(4*(camPos*sand*(speed factor[2, 20])))";
			};
			class TiresGrassOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-grass3",0.031623,1.0,8};
				frequency = "1";
				volume = "3+(4*(camPos*grass*(speed factor[2, 20])))";
			};
			class TiresMudOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-mud2",0.031623,1.0,8};
				frequency = "1";
				volume = "3+(4*(camPos*mud*(speed factor[2, 20])))";
			};
			class TiresGravelOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-gravel2",0.031623,1.0,8};
				frequency = "1";
				volume = "3+(4*(camPos*gravel*(speed factor[2, 20])))";
			};
			class TiresAsphaltOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-asphalt3",0.031623,1.0,8};
				frequency = "1";
				volume = "3+(4*(camPos*asphalt*(speed factor[2, 20])))";
			};
			class NoiseOut
			{
				sound[] = {"ca\sounds\Vehicles\Wheeled\Noises\ext\noise2",0.001,1.0,8};
				frequency = "1";
				volume = "camPos*(damper0 max 0.036)*(speed factor[0, 8])";
			};
			class EngineLowIn
			{
				sound[] = {"Ca\sounds\Vehicles\Wheeled\MMT\low1",0.31622776,1.0};
				frequency = "(randomizer*0.1+1)*speed";
				volume = "(1-camPos)*engineOn*((speed factor[0.1, 0.6]) min (speed factor[0.6, 0.1]))";
			};
			class EngineHighIn
			{
				sound[] = {"Ca\sounds\Vehicles\Wheeled\MMT\high1",0.31622776,1.0};
				frequency = "(randomizer*0.05+1.0)*rpm";
				volume = "(1-camPos)*engineOn*(speed factor[0.4, 0.9])";
			};
			class IdleIn
			{
				sound[] = {"Ca\sounds\Vehicles\Wheeled\MMT\idle",0.31622776,1.0};
				frequency = "1";
				volume = "(1-camPos)*engineOn*(speed factor[0.05, 0.9])";
			};
			class TiresRockIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-rock2",0.031623,1.0};
				frequency = "1";
				volume = "3+(4*(camPos*rock*(speed factor[2, 20])))";
			};
			class TiresSandIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-sand2",0.031623,1.0};
				frequency = "1";
				volume = "3+(4*(camPos*sand*(speed factor[2, 20])))";
			};
			class TiresGrassIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-grass3",0.031623,1.0};
				frequency = "1";
				volume = "3+(4*(camPos*grass*(speed factor[2, 20])))";
			};
			class TiresMudIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-mud2",0.031623,1.0};
				frequency = "1";
				volume = "3+(4*(camPos*mud*(speed factor[2, 20])))";
			};
			class TiresGravelIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-gravel2",0.031623,1.0};
				frequency = "1";
				volume = "3+(4*(camPos*gravel*(speed factor[2, 20])))";
			};
			class TiresAsphaltIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-asphalt3",0.031623,1.0};
				frequency = "1";
				volume = "3+(4*(camPos*Asphalt*(speed factor[2, 20])))";
			};
			class NoiseIn
			{
				sound[] = {"ca\sounds\Vehicles\Wheeled\Noises\ext\noise2",0.001,1.0};
				frequency = "1";
				volume = "(damper0 max 0.03)*(speed factor[0, 8])*(1-camPos)";
			};
			class Movement
			{
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
		};
		class Reflectors{};
		scope = 0;
		weapons[] = {"BikeHorn"};
		wheelCircumference = 2.28;
		model = "\ca\wheeled2\MMT\MMT";
		displayName = "[MMT]StormTrooper";
		vehicleClass = "Car";
		rarityUrban = -1;
		Picture = "\Ca\wheeled2\data\UI\Picture_MMT_CA.paa";
		Icon = "\Ca\wheeled2\data\UI\Icon_MMT_CA.paa";
		mapSize = 3;
		maxSpeed = 40;
		isBicycle = 1;
		extCameraPosition[] = {0,1,-3};
		threat[] = {0.0,0.0,0.0};
		armor = 5;
		turnCoef = 2;
		driverAction = "MMT_Driver";
		transportSoldier = 0;
		driverInAction = "BTR_Driver";
		cargoAction[] = {"BTR_Cargo01","BTR_Cargo02","BTR_Cargo03","BTR_Cargo04"};
		secondaryExplosion = 0;
		leftDustEffect = "NoDust";
		rightDustEffect = "NoDust";
		soundGear[] = {"",0.000562,1};
		SoundGetIn[] = {"",0.017783,1};
		SoundGetOut[] = {"",0.017783,1};
		soundEngineOnInt[] = {"",0.354813,1.0};
		soundEngineOnExt[] = {"",0.354813,1.0};
		soundEngineOffInt[] = {"",0.354813,1.0};
		soundEngineOffExt[] = {"",0.354813,1.0};
		buildCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_01",0.707946,1,40};
		buildCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_02",0.707946,1,40};
		buildCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_03",0.707946,1,40};
		buildCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_04",0.707946,1,40};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_wood_small_01",0.707946,1,40};
		WoodCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_wood_small_02",0.707946,1,40};
		WoodCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_wood_small_03",0.707946,1,40};
		WoodCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_wood_small_04",0.707946,1,40};
		soundWoodCrash[] = {"woodCrash0",0.25,"woodCrash1",0.25,"woodCrash2",0.25,"woodCrash3",0.25};
		ArmorCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_06",0.707946,1,40};
		ArmorCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_05",0.707946,1,40};
		ArmorCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_04",0.707946,1,40};
		ArmorCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_bicycle_03",0.707946,1,40};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		soundEngine[] = {"",1,1};
		soundEnviron[] = {"",1,1};
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		DirverCanEject = 1;
		BrakeDistance = 3;
	};
	class MMT_USMC: MMT_base
	{
		displayName = "NATO Bike";
		scope = 2;
		side = 1;
		faction = "BLU_F";
		crew = "B_Soldier_F";
		typicalCargo[] = {"B_Soldier_F"};
	};
	class MMT_Civ: MMT_base
	{
		displayName = "Civilian Bike";
		scope = 2;
		side = 3;
		faction = "CIV_F";
		crew = "C_man_1_1_F";
		typicalCargo[] = {"C_man_1_1_F"};
	};
};
//};
