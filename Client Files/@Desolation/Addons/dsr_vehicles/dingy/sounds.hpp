	attenuationEffectType = "OpenCarAttenuation"; //Attenuation in interior (Link to Attenuation.hpp in folder SOUNDS_F)

	insideSoundCoef = 1;
	soundEngineOnInt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_start", db-5, 1.0};
	soundEngineOnExt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_start", db-5, 1.0, 300};
	soundEngineOffInt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_stop", db-5, 1.0};
	soundEngineOffExt[] = {"a3\Sounds_F\vehicles\boat\Motor_Boat\engine_stop", db-5, 1.0, 300};

	/* ---- CRASHES  ---- */
	
	buildCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_01", db0, 1,200};
	buildCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_02", db0, 1,200};
	buildCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_03", db0, 1,200};
	buildCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_building_04", db0, 1,200};
	soundBuildingCrash[] = {buildCrash0, 0.25, buildCrash1, 0.25, buildCrash2, 0.25, buildCrash3, 0.25};

	WoodCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_01", db0, 1,200};
	WoodCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_02", db0, 1,200};
	WoodCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_03", db0, 1,200};
	WoodCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_04", db0, 1,200};
	WoodCrash4[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_05", db0, 1,200};
	WoodCrash5[] = {"A3\sounds_f\Vehicles\soft\noises\crash_mix_wood_06", db0, 1,200};
	soundWoodCrash[] = {woodCrash0, 0.166, woodCrash1, 0.166, woodCrash2, 0.166, woodCrash3, 0.166,woodCrash4, 0.166,woodCrash5, 0.166};

	ArmorCrash0[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_01", db0, 1,200};
	ArmorCrash1[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_02", db0, 1,200};
	ArmorCrash2[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_03", db0, 1,200};
	ArmorCrash3[] = {"A3\sounds_f\Vehicles\soft\noises\crash_vehicle_04", db0, 1,200};
	soundArmorCrash[] = {ArmorCrash0, 0.25, ArmorCrash1, 0.25, ArmorCrash2, 0.25, ArmorCrash3, 0.25};

	// warp	factor
	#define	FACTOR(val,from,to)	(val factor[from,to])
	// RANGE(val,	begin, band, end,	band)
	#define	RANGE(val,from,band0,to,band1) FACTOR2(val,from,(from+band0),to,(to+band1))
	// FACTOR2(val,	0, 400,	1200,	2000)
	#define	FACTOR2(val,from0,to0,from1,to1) (FACTOR(val,from0,to0)*FACTOR(val,to1,from1))

	// redRpm
	#define	MAX_RPM	1000
	// scaled	rpm	to 0 - 1
	#define	RPM(rpm) (rpm/MAX_RPM)

	// specialized FACTOR	for	rpm
	#define	FACTOR_RPM(from,to)	FACTOR(RPM(rpm),RPM(from),RPM(to))
	// specialized peak	for	rpm
	#define	FACTOR2_RPM(from0,to0,from1,to1) (FACTOR_RPM(from0,to0)*FACTOR_RPM(to1,from1))
	// specialized peak, different definition, version for rpm
	#define	RANGE_RPM(from,band0,to,band1) FACTOR2_RPM(from,(from+band0),to,(to+band1))
	

	#define HZ_IDLE FACTOR_RPM(100,250)
	#define HZ_RPM1 FACTOR_RPM(200,370)
	#define HZ_RPM2 FACTOR_RPM(280,480)
	#define HZ_RPM3 FACTOR_RPM(380,580)
	#define HZ_RPM4 FACTOR_RPM(490,800)
	#define HZ_RPM5 FACTOR_RPM(650,1000)
		
	#define VOLUME_IDLE FACTOR2_RPM(100,150,200,270)
	#define VOLUME_RPM1 FACTOR2_RPM(190,250,280,380)
	#define VOLUME_RPM2 FACTOR2_RPM(250,350,390,480)
	#define VOLUME_RPM3 FACTOR2_RPM(370,440,495,585)
	#define VOLUME_RPM4 FACTOR2_RPM(460,550,620,780)
	#define VOLUME_RPM5 FACTOR_RPM(600,800)

	// Sound class
	class Sounds
	{
	/*  EXTERNAL SOUNDS	SPEEDBOAT  */
		class IdleOut
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_idle", db-7, 1.0, 300};
			frequency = 0.95	+	HZ_IDLE*0.15;
			volume = engineOn*VOLUME_IDLE ;
		};
		
		class Engine //LOW
		{
		  sound[] =  {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_1", db-4, 1.0, 350};
			frequency = 0.85	+	HZ_RPM1*0.2;
			volume = engineOn*VOLUME_RPM1;
		};
		
		class EngineMidOut
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_3", db-2, 1.0, 380};
			frequency = 0.85	+	HZ_RPM2*0.2;
			volume = engineOn*VOLUME_RPM2;
		};
		
		class EngineMaxOut2
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_4", db-1, 1.0, 440};
			frequency = 0.86	+	HZ_RPM3*0.2;
			volume = engineOn*VOLUME_RPM3;
		};
		
		class EngineMaxOut3
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_5", db0, 1.0, 500};
			frequency = 0.85	+	HZ_RPM4*0.2;
			volume = engineOn*VOLUME_RPM4;
		};
		
		class EngineMaxOut4
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\Motor_Boat\engine_6", db2, 1.0, 550};
			frequency = 0.85	+	HZ_RPM5*0.2;
			volume = engineOn*VOLUME_RPM5;
		};
	
	/*  water flow according to speed of boat   */
		class WaternoiseOutW0
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1", db-3, 1.0, 150};
			frequency = "1";
			volume = "(speed factor[4, 1])";
		};

		class WaternoiseOutW1
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed", db-2, 1.0, 250};
			frequency = "1";
			volume = "((speed factor[2, 6]) min (speed factor[6, 4]))";
		};

		class WaternoiseOutW2
		{
			sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed", db0, 1.0, 350};
			frequency = "1";
			volume = "(speed factor[3, 9])"; //(camPos)*
		};
	};
