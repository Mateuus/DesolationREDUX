class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		SUV_Cargo = "SUV_Cargo";
		SUV_Cargo01 = "SUV_Cargo01";
		SUV_Cargo02 = "SUV_Cargo02";
		SUV_Driver = "SUV_Driver";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{	
		class Crew;
		class SUV_Cargo: Crew
		{
			file="\dsr_vehicles\SUV\data\anim\SUV_Cargo.rtm";
			interpolateTo[]=
			{
				"SUV_KIA_Cargo_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Cargo: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\SUV\data\anim\SUV_KIA_Cargo.rtm";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class SUV_Cargo01: Crew
		{
			file="\dsr_vehicles\SUV\data\anim\SUV_Cargo01.rtm";
			interpolateTo[]=
			{
				"SUV_KIA_Cargo01_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Cargo01: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\SUV\data\anim\SUV_KIA_Cargo01.rtm";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class SUV_Cargo02: Crew
		{
			file="\dsr_vehicles\SUV\data\anim\SUV_Cargo02.rtm";
			interpolateTo[]=
			{
				"SUV_KIA_Cargo02_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Cargo02: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\SUV\data\anim\SUV_KIA_Cargo02.rtm";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class SUV_Driver: Crew
		{
			file="\dsr_vehicles\SUV\data\anim\SUV_Driver.rtm";
			interpolateTo[]=
			{
				"SUV_KIA_Driver_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Driver: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\SUV\data\anim\SUV_KIA_Driver.rtm";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
	};
};
class DefaultEventhandlers;