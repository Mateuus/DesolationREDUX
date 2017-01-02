class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Fishing_Driver = "Fishing_Driver";
		Fishing_Seat = "Fishing_Seat";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class Fishing_Driver: Crew
		{
			file = "\dsr_vehicles\fishing_boat\data\anim\Driver.rtm";
		};
		class Fishing_Seat: Crew
		{
			file = "\dsr_vehicles\fishing_boat\data\anim\Cargo_Seat.rtm";
		};
	};
};