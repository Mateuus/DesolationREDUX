class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		C130J_Pilot = "C130J_Pilot";
		//C130J_Cargo = "C130J_Cargo";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class C130J_Pilot_Dead: DefaultDie
		{
			actions = "DeadActions";
			file = "\dsr_vehicles\c130j\data\anim\c130pilotkia.rtm";
			speed = 0.5;
			looped = "false";
			terminal = 1;
			soundEnabled=0;
			connectTo[] = {DeadState,0.1};
		};
		class C130J_Pilot: Crew
		{
			file = "\dsr_vehicles\c130j\data\anim\c130pilot.rtm";
			interpolateTo[] = {"C130J_Pilot_Dead",1};
		};
		//class C130J_Cargo_Dead: C130J_Pilot_Dead {};
		//class C130J_Cargo: Crew
		//{
		//	file = "\dsr_vehicles\c130j\data\anim\c130pilot.rtm";
		//	interpolateTo[] = {"C130J_Cargo_Dead",1};
		//};
	};
};