#define true 1

class CfgPatches
{
	class Zombz {};
};

class Plugins
{
	class Zombz
	{
		name = "SM Zombz";
		desc = "Desolation Zombie Plugin";
		tag = "SM";
	};
};

class CfgFunctions
{
	class SM
	{
		class Client 
		{
			file = "Zombz\Client";
			isclient = true;
			class initClient {};
			class ZombieInit {};
			class zombieFindTarget {};
			class zombieCanSee {};
			class zombieFiredNear {};
			class headExplodeEffect {};
			class fetchVehicleSize {};
			class zombieStartAttack {};
			class zombieAttackTarget {};
			class targetSetVelocity {};
			class blurEffect {};
			class bloodEffect {};
			class screenAddBlood {};
			class screenRemoveBlood {};
			class zombieFindFiredNear {};
			class findIndex {};
			class zombieCalculateSpeed {};
			class zombieFindPositionWander {};
			class zombieHandleDamage {};
			class checkPlayers {};
		};

		class Server 
		{
			file = "Zombz\Server";
			isserver = true;
			class initServer {};
			class SpawnZombie {};
			class SpawnZombies {};
			class checkZombies {};
			class zombieCleanup {};
			class transferOwnership {};
			class zombieExplodeHead {};
			class FindSafePos {};
		};

		class Shared
		{
			file = "Zombz\shared";
			isclient = true;
			class Log {};
			class getCfgValue {};
			class onMPKilled {};
		};
	};
};

class ZombieSettings
{
	MaleFaces[] =
	{
		"SM_Zombie1",
		"SM_Zombie2",
		"SM_Zombie3",
		"SM_Zombie4",
		"SM_Zombie5",
		"SM_Zombie6",
		"SM_Zombie7",
		"SM_Zombie8",
		"SM_Zombie9",
		"SM_Zombie10",
		"SM_Zombie11",
		"SM_Zombie13",
		"SM_Zombie14",
		"SM_Zombie15",
		"SM_Zombie16",
		"SM_Zombie17",
		"SM_Zombie18",
		"SM_Zombie19",
		"SM_Zombie20",
		"SM_Zombie21",
		"SM_Zombie22",
		"SM_Zombie23",
		"SM_Zombie24",
		"SM_Zombie25",
		"SM_Zombie26",
		"SM_Zombie27",
		"SM_Zombie28",
		"SM_Zombie29",
		"SM_Zombie30",
		"SM_Zombie31",
		"SM_Zombie32"
	};

	FemaleFaces[] =
	{
		"SM_ZombieFemale1",
		"SM_ZombieFemale2",
		"SM_ZombieFemale3",
		"SM_ZombieFemale4",
		"SM_ZombieFemale5",
		"SM_ZombieFemale6",
		"SM_ZombieFemale7",
		"SM_ZombieFemale8",
		"SM_ZombieFemale9",
		"SM_ZombieFemale10",
		"SM_ZombieFemale11"
	};

	zombieClasses[] =
	{
		"SM_Zombz_walker1",
		"SM_Zombz_walker2",
		"SM_Zombz_walker3",
		"SM_Zombz_walker4",
		"SM_Zombz_walker5",
		"SM_Zombz_walker6",
		"SM_Zombz_walker7",
		"SM_Zombz_walker8",
		"SM_Zombz_walker9",
		"SM_Zombz_walker10",
		"SM_Zombz_walker11",
		"SM_Zombz_walker12",
		"SM_Zombz_walker13",
		"SM_Zombz_walker14",
		"SM_Zombz_walker15",
		"SM_Zombz_walker16",
		"SM_Zombz_walker17",
		"SM_Zombz_walker18",
		"SM_Zombz_walker19",
		"SM_Zombz_walker20",
		"SM_Zombz_walker21",
		"SM_Zombz_walker22",
		"SM_Zombz_walker23",
		"SM_Zombz_walker24",
		"SM_Zombz_walker25",
		"SM_Zombz_walker26",
		"SM_Zombz_walker27",
		"SM_Zombz_walker28",
		"SM_Zombz_walker29",
		"SM_Zombz_walker30",
		"SM_Zombz_walker31",
		"SM_Zombz_walker32",
		"SM_Zombz_walker33",
		"SM_Zombz_walker34",
		"SM_Zombz_walker35",
		"SM_Zombz_walker36",
		"SM_Zombz_walker37",
		"SM_Zombz_walker38",
		"SM_Zombz_walker39",
		"SM_Zombz_walker40",
		"SM_Zombz_walker41",
		"SM_Zombz_walker42",
		"SM_Zombz_walker43",
		"SM_Zombz_walker44",
		"SM_Zombz_walker45",
		"SM_Zombz_walker46",
		"SM_Zombz_walker47",
		"SM_Zombz_walker48",
		"SM_Zombz_walker49",
		"SM_Zombz_walker50",
		"SM_Zombz_walker51",
		"SM_Zombz_walker52",
		"SM_Zombz_walker53",
		"SM_Zombz_walker54",
		"SM_Zombz_walker55",
		"SM_Zombz_walker56",
		"SM_Zombz_walker57",
		"SM_Zombz_walker58",
		"SM_Zombz_walker59",
		"SM_Zombz_walker60",
		"SM_Zombz_walker61",
		"SM_Zombz_walker62",
		"SM_Zombz_walker63",
		"SM_Zombz_walker64",


		"SM_Zombz_FemaleWalker1",
		"SM_Zombz_FemaleWalker2",
		"SM_Zombz_FemaleWalker3",
		"SM_Zombz_FemaleWalker4",
		"SM_Zombz_FemaleWalker5"
	};
};