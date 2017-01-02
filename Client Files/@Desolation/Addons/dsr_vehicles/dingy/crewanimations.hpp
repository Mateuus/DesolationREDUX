class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Dingy_Driver = "Dingy_Driver";
		Dingy_Gunner = "Dingy_Gunner";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class Dingy_Driver: Crew
		{
			file = "\dsr_vehicles\dingy\data\anim\dingy_driver.rtm";
		};
		class Dingy_Gunner: Crew
		{
			file = "\dsr_vehicles\dingy\data\anim\dingy_gunner.rtm";
		};
	};
};