		//soundEngine[]={\ca\Air2\Data\Sound\C130J,db28,1};
		soundGetIn[]={"dsr_vehicles\an2\data\sound\close",db-10,1};
		soundGetOut[]={"dsr_vehicles\an2\data\sound\open",db-10,1, 40};
		soundDammage[]={"dsr_vehicles\an2\data\sound\alarm_loop1", db-5, 1};
		soundEngineOnInt[] = {"dsr_vehicles\an2\data\sound\AN2_engine_start_int", db-15, 1.0};
		soundEngineOnExt[] = {"dsr_vehicles\an2\data\sound\AN2_engine_start_ext", db-8, 1.0, 600};
		soundEngineOffInt[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_stop_int", db-15, 1.0};
		soundEngineOffExt[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_stop_ext", db-8, 1.0, 600};

		class Sounds
		{
	//	EXTERNAL SOUNDS AN2/
			class EngineLowOut
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_low_ext", db5, 1, 900};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*engineOn*(rpm factor[0.85, 0])";
			};
				class EngineHighOut
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_high_ext", db5, 1, 1100};
				frequency = "1";
				volume = "camPos*engineOn*(rpm factor[0.25, 1.0])";
			};
			class ForsageOut
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_high_ext", db3, 1.2, 1100};
				frequency = "1";
				volume = "camPos*engineOn*(thrust factor[0.5, 1.0])";
				cone[] = {1.14, 3.92, 2.5, 0.4};
			};
			class WindNoiseOut
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\ext-wind", db-60, 0.6, 150};
				frequency ="(0.1+(1.2*(speed factor[1, 100])))";
				volume = "camPos*(speed factor[1, 100])";
			};

			//	INTERNAL SOUNDS AN2/

	 		class EngineLowIn
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_low_int", db5, 1.0};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.65, 0]))";
			};
			class EngineHighIn
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_high_int", db5, 1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.25, 1.0]))";
			};
			class ForsageIn
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\AN2_engine_high_int", db5, 1.2};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[] =  {"dsr_vehicles\an2\data\sound\int-wind", db-60, 0.6};
				frequency ="(0.1+(1.2*(speed factor[1, 100])))";
				volume = "(1-camPos)*(speed factor[1, 100])";
			};
		};