class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		MMT_Driver = "MMT_Driver";
	};
};
/*
class CfgWeapons
{
	class CarHorn;
	class BikeHorn: CarHorn
	{
		cursor = "";
		cursorAim = "";
		scope = 1;
		displayName = "Horn";
		reloadTime = 0;
		drySound[] = {"ca\Wheeled2\MMT\data\sounds\bicycle_horn",1,1,100};
		canLock = 0;
		optics = 0;
		enableAttack = 0;
	};
};
*/
#define SPEED_STATIC 1e10
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		// bike crew are dropped off when dead
		class MMT_Dead: DefaultDie
		{
			actions = DeadActions;
			file=\dsr_vehicles\MMT\DATA\anim\MMT_Driver.rtm;
			speed=SPEED_STATIC;
			terminal = 1;
			soundEnabled=0;
		};
		class Crew;
		class MMT_Driver: Crew
		{
			file=\dsr_vehicles\MMT\DATA\anim\MMT_Driver.rtm;
			connectTo[]={MMT_Dead,1};
			speed=2;
			looped=1;
		};
	};
};

class CfgMovesWomen: CfgMovesBasic
{
	class ManActions
	{
		MMT_Driver = "";
	};
};