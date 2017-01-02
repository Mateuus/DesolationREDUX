		attenuationEffectType = "CarAttenuation";
		insideSoundCoef = 0.35;
		soundGetIn[] = {"dsr_vehicles\suv\data\sounds\SUV_ext_door",0.56234133,1};
		soundGetOut[] = {"dsr_vehicles\suv\data\sounds\SUV_ext_door",0.56234133,1,40};
		soundDammage[] = {"",0.56234133,1};
		soundEngineOnInt[] = {"dsr_vehicles\suv\data\sounds\SUV_int_start",0.39810717,1};
		soundEngineOnExt[] = {"dsr_vehicles\suv\data\sounds\SUV_ext_start",0.4466836,1,200};
		soundEngineOffInt[] = {"dsr_vehicles\suv\data\sounds\SUV_int_stop",0.39810717,1};
		soundEngineOffExt[] = {"dsr_vehicles\suv\data\sounds\SUV_ext_stop",0.4466836,1,200};
		buildCrash0[] = {"A3\Sounds_F\vehicles\soft\noises\crash_building_01",0.70794576,1,200};
		buildCrash1[] = {"A3\Sounds_F\vehicles\soft\noises\crash_building_02",0.70794576,1,200};
		buildCrash2[] = {"A3\Sounds_F\vehicles\soft\noises\crash_building_03",0.70794576,1,200};
		buildCrash3[] = {"A3\Sounds_F\vehicles\soft\noises\crash_building_04",0.70794576,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_01",0.70794576,1,200};
		WoodCrash1[] = {"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_02",0.70794576,1,200};
		WoodCrash2[] = {"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_03",0.70794576,1,200};
		WoodCrash3[] = {"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_04",0.70794576,1,200};
		WoodCrash4[] = {"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_05",0.70794576,1,200};
		WoodCrash5[] = {"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_06",0.70794576,1,200};
		soundWoodCrash[] = {"woodCrash0",0.166,"woodCrash1",0.166,"woodCrash2",0.166,"woodCrash3",0.166,"woodCrash4",0.166,"woodCrash5",0.166};
		ArmorCrash0[] = {"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_01",0.70794576,1,200};
		ArmorCrash1[] = {"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_02",0.70794576,1,200};
		ArmorCrash2[] = {"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_03",0.70794576,1,200};
		ArmorCrash3[] = {"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_04",0.70794576,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		class Sounds
		{
			class Idle_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_idle",0.22387211,1,150};
				frequency = "0.9	+	((rpm/	7000) factor[(400/	7000),(1150/	7000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	7000) factor[(400/	7000),(700/	7000)])	*	((rpm/	7000) factor[(1100/	7000),(900/	7000)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_03",0.2818383,1,200};
				frequency = "0.8	+	((rpm/	7000) factor[(900/	7000),(2100/	7000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	7000) factor[(870/	7000),(1100/	7000)])	*	((rpm/	7000) factor[(2100/	7000),(1300/	7000)]))";
			};
			class Engine1_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_05",0.3548134,1,240};
				frequency = "0.8	+		((rpm/	7000) factor[(1300/	7000),(3100/	7000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	7000) factor[(1250/	7000),(2050/	7000)])	*	((rpm/	7000) factor[(3100/	7000),(2300/	7000)]))";
			};
			class Engine2_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_07",0.39810717,1,280};
				frequency = "0.8	+	((rpm/	7000) factor[(2200/	7000),(4100/	7000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	7000) factor[(2250/	7000),(3050/	7000)])	*	((rpm/	7000) factor[(4100/	7000),(3300/	7000)]))";
			};
			class Engine3_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_09",0.4466836,1,320};
				frequency = "0.8	+	((rpm/	7000) factor[(3300/	7000),(4900/	7000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	7000) factor[(3250/	7000),(4050/	7000)])	*	((rpm/	7000) factor[(4870/	7000),(4200/	7000)]))";
			};
			class Engine4_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_11",0.5011872,1,360};
				frequency = "0.8	+	((rpm/	7000) factor[(4200/	7000),(6200/	7000)])*0.2";
				volume = "engineOn*camPos*(((rpm/	7000) factor[(4150/	7000),(4800/	7000)])	*	((rpm/	7000) factor[(6150/	7000),(5150/	7000)]))";
			};
			class Engine5_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_13",0.56234133,1,420};
				frequency = "0.95	+	((rpm/	7000) factor[(5100/	7000),(7000/	7000)])*0.15";
				volume = "engineOn*camPos*((rpm/	7000) factor[(5100/	7000),(6100/	7000)])";
			};
			class IdleThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_idle",0.5011872,1,200};
				frequency = "0.9	+	((rpm/	7000) factor[(400/	7000),(1150/	7000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(400/	7000),(700/	7000)])	*	((rpm/	7000) factor[(1100/	7000),(900/	7000)]))";
			};
			class EngineThrust
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_03",0.56234133,1,250};
				frequency = "0.8	+	((rpm/	7000) factor[(900/	7000),(2100/	7000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(870/	7000),(1100/	7000)])	*	((rpm/	7000) factor[(2100/	7000),(1300/	7000)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_05",0.63095737,1,280};
				frequency = "0.8	+		((rpm/	7000) factor[(1300/	7000),(3100/	7000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(1250/	7000),(2050/	7000)])	*	((rpm/	7000) factor[(3100/	7000),(2300/	7000)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_07",0.70794576,1,320};
				frequency = "0.8	+	((rpm/	7000) factor[(2200/	7000),(4100/	7000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(2250/	7000),(3050/	7000)])	*	((rpm/	7000) factor[(4100/	7000),(3300/	7000)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_09",0.7943282,1,360};
				frequency = "0.8	+	((rpm/	7000) factor[(3300/	7000),(4900/	7000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(3250/	7000),(4050/	7000)])	*	((rpm/	7000) factor[(4870/	7000),(4200/	7000)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_11",1,1,400};
				frequency = "0.8	+	((rpm/	7000) factor[(4200/	7000),(6200/	7000)])*0.3";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(4150/	7000),(4800/	7000)])	*	((rpm/	7000) factor[(6150/	7000),(5150/	7000)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_13",1.2589254,1,450};
				frequency = "0.9	+	((rpm/	7000) factor[(5100/	7000),(7000/	7000)])*0.2";
				volume = "engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	7000) factor[(5100/	7000),(6100/	7000)])";
			};
			class Idle_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_idle_int",0.17782794,1};
				frequency = "0.9	+	((rpm/	7000) factor[(400/	7000),(1150/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	7000) factor[(400/	7000),(700/	7000)])	*	((rpm/	7000) factor[(1100/	7000),(900/	7000)]))";
			};
			class Engine_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_03_int",0.19952622,1};
				frequency = "0.8	+	((rpm/	7000) factor[(900/	7000),(2100/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	7000) factor[(870/	7000),(1100/	7000)])	*	((rpm/	7000) factor[(2100/	7000),(1300/	7000)]))";
			};
			class Engine1_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_05_int",0.25118864,1};
				frequency = "0.8	+		((rpm/	7000) factor[(1300/	7000),(3100/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	7000) factor[(1250/	7000),(2050/	7000)])	*	((rpm/	7000) factor[(3100/	7000),(2300/	7000)]))";
			};
			class Engine2_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_07_int",0.2818383,1};
				frequency = "0.8	+	((rpm/	7000) factor[(2200/	7000),(4100/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	7000) factor[(2250/	7000),(3050/	7000)])	*	((rpm/	7000) factor[(4100/	7000),(3300/	7000)]))";
			};
			class Engine3_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_09_int",0.31622776,1};
				frequency = "0.8	+	((rpm/	7000) factor[(3300/	7000),(4900/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	7000) factor[(3250/	7000),(4050/	7000)])	*	((rpm/	7000) factor[(4870/	7000),(4200/	7000)]))";
			};
			class Engine4_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_11_int",0.3548134,1};
				frequency = "0.8	+	((rpm/	7000) factor[(4200/	7000),(6200/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(((rpm/	7000) factor[(4150/	7000),(4800/	7000)])	*	((rpm/	7000) factor[(6150/	7000),(5150/	7000)]))";
			};
			class Engine5_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_engine_13_int",0.5011872,1};
				frequency = "0.95	+	((rpm/	7000) factor[(5100/	7000),(7000/	7000)])*0.15";
				volume = "engineOn*(1-camPos)*((rpm/	7000) factor[(5100/	7000),(6100/	7000)])";
			};
			class IdleThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_idle_int",0.31622776,1};
				frequency = "0.9	+	((rpm/	7000) factor[(400/	7000),(1150/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(400/	7000),(700/	7000)])	*	((rpm/	7000) factor[(1100/	7000),(900/	7000)]))";
			};
			class EngineThrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_03_int",0.3548134,1};
				frequency = "0.8	+	((rpm/	7000) factor[(900/	7000),(2100/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(870/	7000),(1100/	7000)])	*	((rpm/	7000) factor[(2100/	7000),(1300/	7000)]))";
			};
			class Engine1_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_05_int",0.39810717,1};
				frequency = "0.8	+		((rpm/	7000) factor[(1300/	7000),(3100/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(1250/	7000),(2050/	7000)])	*	((rpm/	7000) factor[(3100/	7000),(2300/	7000)]))";
			};
			class Engine2_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_07_int",0.4466836,1};
				frequency = "0.8	+	((rpm/	7000) factor[(2200/	7000),(4100/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(2250/	7000),(3050/	7000)])	*	((rpm/	7000) factor[(4100/	7000),(3300/	7000)]))";
			};
			class Engine3_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_09_int",0.5011872,1};
				frequency = "0.8	+	((rpm/	7000) factor[(3300/	7000),(4900/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(3250/	7000),(4050/	7000)])	*	((rpm/	7000) factor[(4870/	7000),(4200/	7000)]))";
			};
			class Engine4_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_11_int",0.56234133,1};
				frequency = "0.8	+	((rpm/	7000) factor[(4200/	7000),(6200/	7000)])*0.3";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/	7000) factor[(4150/	7000),(4800/	7000)])	*	((rpm/	7000) factor[(6150/	7000),(5150/	7000)]))";
			};
			class Engine5_Thrust_int
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\SUV_01\SUV_01_exhaust_13_int",0.63095737,1};
				frequency = "0.9	+	((rpm/	7000) factor[(5100/	7000),(7000/	7000)])*0.2";
				volume = "engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/	7000) factor[(5100/	7000),(6100/	7000)])";
			};
			class Movement
			{
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",0.70794576,1,30};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",0.70794576,1,30};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",0.70794576,1,30};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",0.70794576,1,30};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",0.70794576,1,30};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",0.70794576,1,30};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3",0.63095737,1,45};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",0.70794576,1};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",0.70794576,1};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",0.70794576,1};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",0.70794576,1};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",0.70794576,1};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",0.70794576,1};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",0.5011872,1};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",0.70794576,1,40};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,40};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,40};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_ext_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",0.70794576,1,40};
				frequency = 1;
				volume = "engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class breaking_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking",0.70794576,1,30};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration",0.70794576,1,30};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.70794576,1,30};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_ext_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",0.70794576,1,30};
				frequency = 1;
				volume = "engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class breaking_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_int_road
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class breaking_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_int_dirt
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",0.56234133,1};
				frequency = 1;
				volume = "engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
		};