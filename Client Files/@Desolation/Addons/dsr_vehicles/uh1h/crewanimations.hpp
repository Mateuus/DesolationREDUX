class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		UH1H_Cargo_EP1 = "UH1H_Cargo_EP1";
		UH1H_Pilot_EP1 = "UH1H_Pilot_EP1";
		UH1Y_Cargo01 = "UH1Y_Cargo01";
		UH1Y_Cargo02 = "UH1Y_Cargo02";
		UH1Y_Cargo03 = "UH1Y_Cargo03";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class UH1H_Cargo_EP1: Crew
		{
			file = "\dsr_vehicles\uh1h\data\anim\uh1h_cargo";
			connectTo[] = {"UH1H_KIA_Pilot_EP1",1};
			speed = "1e+010";
		};
		class UH1H_KIA_Pilot_EP1: DefaultDie
		{
			actions = "DeadActions";
			file = "\dsr_vehicles\uh1h\data\anim\uh1h_kia_pilot";
			speed = "1e+010";
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"DeadState",0.1};
		};
		class UH1H_Pilot_EP1: Crew
		{
			file = "\dsr_vehicles\uh1h\data\anim\uh1h_pilot";
			connectTo[] = {"UH1H_KIA_Pilot_EP1",1};
			speed = "1e+010";
		};
		class KIA_UH1Y_Cargo01: DefaultDie
		{
			actions = "DeadActions";
			file = "\dsr_vehicles\uh1h\data\anim\KIA_cargo_01.rtm";
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = {"DeadState",0.1};
		};
		class UH1Y_Cargo01: Crew
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_01.rtm";
			interpolateTo[] = {"KIA_UH1Y_Cargo01",0.1};
			connectTo[] = {"UH1Y_Cargo01",0.3,"UH1Y_Cargo01_V1",0.1,"UH1Y_Cargo01_V2",0.1,"UH1Y_Cargo01_V3",0.1};
			equivalentTo = "UH1Y_Cargo01";
			variantsAI[] = {"UH1Y_Cargo01",0.4,"UH1Y_Cargo01_V1",0.2,"UH1Y_Cargo01_V2",0.2,"UH1Y_Cargo01_V3",0.2};
			variantAfter[] = {5,10,20};
			speed = 0.3;
		};
		class UH1Y_Cargo01_V1: UH1Y_Cargo01
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_01nadech.rtm";
			interpolateTo[] = {"KIA_UH1Y_Cargo01",1};
			connectTo[] = {"UH1Y_Cargo01",0.1};
			speed = 0.395;
			looped = 0;
			variantAfter[] = {5,5,5};
		};
		class UH1Y_Cargo01_V2: UH1Y_Cargo01_V1
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_01poposed.rtm";
			speed = 0.588;
		};
		class UH1Y_Cargo01_V3: UH1Y_Cargo01_V1
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_01presunruky.rtm";
			speed = 0.491;
		};
		class KIA_UH1Y_Cargo02: KIA_UH1Y_Cargo01
		{
			file = "\dsr_vehicles\uh1h\data\anim\KIA_cargo_02.rtm";
		};
		class UH1Y_Cargo02: Crew
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_02.rtm";
			interpolateTo[] = {"KIA_UH1Y_Cargo02",0.1};
			connectTo[] = {"UH1Y_Cargo02",0.3,"UH1Y_Cargo02_V1",0.1,"UH1Y_Cargo02_V2",0.1,"UH1Y_Cargo02_V3",0.1};
			equivalentTo = "UH1Y_Cargo02";
			variantsAI[] = {"UH1Y_Cargo02",0.4,"UH1Y_Cargo02_V1",0.2,"UH1Y_Cargo02_V2",0.2,"UH1Y_Cargo02_V3",0.2};
			variantAfter[] = {5,10,20};
			speed = 0.3;
		};
		class UH1Y_Cargo02_V1: UH1Y_Cargo02
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_02poposed.rtm";
			interpolateTo[] = {"KIA_UH1Y_Cargo02",1};
			connectTo[] = {"UH1Y_Cargo02",0.1};
			speed = 0.652;
			looped = 0;
			variantAfter[] = {5,5,5};
		};
		class UH1Y_Cargo02_V2: UH1Y_Cargo02_V1
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_02predklon.rtm";
			speed = 0.3125;
		};
		class UH1Y_Cargo02_V3: UH1Y_Cargo02_V1
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_02presunruky.rtm";
			speed = 0.37;
		};
		class KIA_UH1Y_Cargo03: KIA_UH1Y_Cargo01
		{
			file = "\dsr_vehicles\uh1h\data\anim\KIA_cargo_03.rtm";
		};
		class UH1Y_Cargo03: Crew
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_03.rtm";
			interpolateTo[] = {"KIA_UH1Y_Cargo03",0.1};
			connectTo[] = {"UH1Y_Cargo03",0.3,"UH1Y_Cargo03_V1",0.1,"UH1Y_Cargo03_V2",0.1,"UH1Y_Cargo03_V3",0.1};
			equivalentTo = "UH1Y_Cargo03";
			variantsAI[] = {"UH1Y_Cargo03",0.4,"UH1Y_Cargo03_V1",0.1,"UH1Y_Cargo03_V2",0.25,"UH1Y_Cargo03_V3",0.25};
			variantAfter[] = {5,10,20};
			speed = 0.3;
		};
		class UH1Y_Cargo03_V1: UH1Y_Cargo03
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_03predklon.rtm";
			interpolateTo[] = {"KIA_UH1Y_Cargo03",1};
			connectTo[] = {"UH1Y_Cargo03",0.1};
			speed = 0.37;
			looped = 0;
			variantAfter[] = {5,5,5};
		};
		class UH1Y_Cargo03_V2: UH1Y_Cargo03_V1
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_03presunruky.rtm";
			speed = 0.37;
			variantAfter[] = {5,5,5};
		};
		class UH1Y_Cargo03_V3: UH1Y_Cargo03_V1
		{
			file = "\dsr_vehicles\uh1h\data\anim\cargo_03protazenizad.rtm";
			speed = 0.491;
			variantAfter[] = {5,5,5};
		};
	};
};