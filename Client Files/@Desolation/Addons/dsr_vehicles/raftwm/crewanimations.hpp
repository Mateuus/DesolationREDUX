class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Raft_Driver = "Raft_Driver";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class Raft_Driver: Crew
		{
			file = "\dsr_vehicles\raftwm\data\anim\raft_driver.rtm";
		};
	};
};