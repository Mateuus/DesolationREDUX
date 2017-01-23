class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		AN2_Pilot_EP1 = "AN2_Pilot_EP1";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class AN2_Pilot_EP1: Crew
		{
			file = "dsr_vehicles\an2\data\anim\AN2_Pilot";
			connectTo[] = {"AN2_Pilot_EP1", 1};
			speed = 1e+010;
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		AN2_Pilot_EP1 = "";
	};
};