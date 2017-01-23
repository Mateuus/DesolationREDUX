class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		SUV_Cargo_EP1="SUV_Cargo_EP1";
		SUV_Cargo01_EP1="SUV_Cargo01_EP1";
		SUV_Cargo02_EP1="SUV_Cargo02_EP1";
		SUV_Driver_EP1="SUV_Driver_EP1";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class SUV_Cargo_EP1: Crew
		{
			file="\dsr_vehicles\suv\data\anim\SUV_Cargo";
			interpolateTo[]=
			{
				"SUV_KIA_Cargo_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Cargo_EP1: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\suv\data\anim\SUV_KIA_Cargo";
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
		class SUV_Cargo01_EP1: Crew
		{
			file="\dsr_vehicles\suv\data\anim\SUV_Cargo01";
			interpolateTo[]=
			{
				"SUV_KIA_Cargo01_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Cargo01_EP1: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\suv\data\anim\SUV_KIA_Cargo01";
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
		class SUV_Cargo02_EP1: Crew
		{
			file="\dsr_vehicles\suv\data\anim\SUV_Cargo02";
			interpolateTo[]=
			{
				"SUV_KIA_Cargo02_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Cargo02_EP1: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\suv\data\anim\SUV_KIA_Cargo02";
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
		class SUV_Driver_EP1: Crew
		{
			file="\dsr_vehicles\suv\data\anim\SUV_Driver";
			interpolateTo[]=
			{
				"SUV_KIA_Driver_EP1",
				1
			};
			speed=1e+010;
		};
		class SUV_KIA_Driver_EP1: DefaultDie
		{
			actions="DeadActions";
			file="\dsr_vehicles\suv\data\anim\SUV_KIA_Driver";
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
class CfgMovesWomen: CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		SUV_Cargo_EP1="crew";
		SUV_Cargo01_EP1="crew";
		SUV_Cargo02_EP1="crew";
		SUV_Driver_EP1="";
	};
};