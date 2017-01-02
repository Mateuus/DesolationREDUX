		soundGetIn[]={"dsr_vehicles\c130j\data\sounds\close",db-10,1};
		soundGetOut[]={"dsr_vehicles\c130j\data\sounds\open",db-10,1, 40};
		soundDammage[]={"dsr_vehicles\c130j\data\sounds\int-alarm_loop", db-5, 1};
		soundEngineOnInt[] = {"dsr_vehicles\c130j\data\sounds\int_start_1", db-8, 1.0};
		soundEngineOnExt[] = {"dsr_vehicles\c130j\data\sounds\ext_start_1", db-8, 1.0, 700};
		soundEngineOffInt[] =  {"dsr_vehicles\c130j\data\sounds\int_stop_1", db-8, 1.0};
		soundEngineOffExt[] =  {"dsr_vehicles\c130j\data\sounds\ext_stop_1", db-8, 1.0, 700};

		class scrubLandInt
		{
			sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt", db0, 1.0, 100};
			frequency = 1;
			volume = "(scrubLand factor[0.01, 0.20])";
		};
		
		class Sounds
		{
	/*	EXTERNAL SOUNDS C130 */
			class EngineLowOut
			{
				sound[] =  {"dsr_vehicles\c130j\data\sounds\ext_engine_low", db5, 1, 900};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*engineOn*(rpm factor[0.85, 0])";
			};
			class EngineHighOut
			{
            			sound[] =  {"dsr_vehicles\c130j\data\sounds\ext_engine_hi", db5, 1, 1100};
				frequency = "1";
				volume = "camPos*engineOn*(rpm factor[0.55, 1.0])";
			};
        		class ForsageOut
        		{
				sound[] =  {"dsr_vehicles\c130j\data\sounds\ext_forsage_1", db3, 1, 1500};
				frequency = "1";
				volume = "camPos*engineOn*(thrust factor[0.5, 1.0])";
        			cone[] = {1.14, 3.92, 2.0, 0.4};
      			};
        		class WindNoiseOut
      			{
       			 	sound[] =  {"dsr_vehicles\c130j\data\sounds\ext-wind1", db-60, 0.6, 150};
				frequency ="(0.1+(1.2*(speed factor[1, 100])))";
				volume = "camPos*(speed factor[1, 100])";
     			};

			/*	INTERNAL SOUNDS C130 */

	 		class EngineLowIn
			{
				sound[] =  {"dsr_vehicles\c130j\data\sounds\int_engine_low", db0, 1.0};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
			};
			class EngineHighIn
			{
				sound[] =  {"dsr_vehicles\c130j\data\sounds\int_engine_hi", db0, 1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
			};
			class ForsageIn
			{
				sound[] =  {"dsr_vehicles\c130j\data\sounds\int_forsage_1", db3, 1.1};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[] =  {"dsr_vehicles\c130j\data\sounds\int-wind1", db-60, 0.6};
				frequency ="(0.1+(1.2*(speed factor[1, 100])))";
				volume = "(1-camPos)*(speed factor[1, 100])";
			};
		};
		
/*	
		attenuationEffectType = "HeliAttenuation"; //Attenuation in interior (Link to Attenuation.hpp in folder SOUNDS_F)

		soundGetIn[]={"A3\Sounds_F\air\Plane_Fighter_03\buzzard_getin",db0, 1, 40};
		soundGetOut[]={"A3\Sounds_F\air\Plane_Fighter_03\getout",db0, 1, 40};
		soundDammage[]={"", db-5, 1};
		soundEngineOnInt[] = {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-start_int", db-0, 1.0};
		soundEngineOnExt[] = {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-start_ext", db5, 1.0, 500};
		soundEngineOffInt[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-stop_int", db-0, 1.0};
		soundEngineOffExt[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-stop_ext", db5, 1.0, 500};
  		soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1", db-20, 1};
   		soundIncommingMissile[] = {"\A3\Sounds_F\weapons\Rockets\locked_3", db-20, 1.5};
		soundGearUp[] = {"A3\Sounds_F_EPC\CAS_02\gear_up", db-2, 1.0, 150};
		soundGearDown[] = {"A3\Sounds_F_EPC\CAS_02\gear_down", db-2, 1.0, 150};
		soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up", db-4, 1.0, 100};
		soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down", db-4, 1.0, 100};


		class scrubLandInt
		{
			sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt", db0, 1.0, 100};
			frequency = 1;
			volume = "(scrubLand factor[0.01, 0.20])";
		};

		class Sounds
		{
			class EngineLowOut
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03_low_ext", db8, 1.0, 1200};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};

			class EngineHighOut
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03_engi_ext", db8, 1.2, 1400};
				frequency = "1";
				volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};

			class ForsageOut
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-fors_ext", db5, 0.99, 1700};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[] = {3.14, 3.92, 2.0, 0.5};
			};

			class WindNoiseOut
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\noise", db-5, 1.0, 150};
				frequency ="(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};

			class EngineLowIn
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03_low_int", db0, 1.0};
				frequency = "1.0 min (rpm + 0.5)";
				volume = (1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]));
			};

			class EngineHighIn
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03_engi_int", db0, 1.2};
				frequency = "1";
				volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
			};

			class ForsageIn
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-fors_int", db0, 1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
			};

			class WindNoiseIn
			{
				sound[] =  {"A3\Sounds_F\air\Plane_Fighter_03\noise", db-6, 1.0};
				frequency ="(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
		};
*/