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
			class infectionThread {};
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
		"SM_Zombz_walker65",
		"SM_Zombz_walker66",
		"SM_Zombz_walker67",
		"SM_Zombz_walker68",
		"SM_Zombz_walker69",
		"SM_Zombz_walker70",
		"SM_Zombz_walker71",
		"SM_Zombz_walker72",
		"SM_Zombz_walker73",
		"SM_Zombz_walker74",
		"SM_Zombz_walker75",
		"SM_Zombz_walker76",
		"SM_Zombz_walker77",
		"SM_Zombz_walker78",
		"SM_Zombz_walker79",
		"SM_Zombz_walker80",
		"SM_Zombz_walker81",
		"SM_Zombz_walker82",
		"SM_Zombz_walker83",
		"SM_Zombz_walker84",
		"SM_Zombz_walker85",
		"SM_Zombz_walker86",
		"SM_Zombz_walker87",
		"SM_Zombz_walker88",
		"SM_Zombz_walker89",
		"SM_Zombz_walker90",
		"SM_Zombz_walker91",
		"SM_Zombz_walker92",
		"SM_Zombz_walker93",
		"SM_Zombz_walker94",
		"SM_Zombz_walker95",
		"SM_Zombz_walker96",
		"SM_Zombz_walker97",
		"SM_Zombz_walker98",
		"SM_Zombz_walker99",
		"SM_Zombz_walker100",
		"SM_Zombz_walker101",
		"SM_Zombz_walker102",
		"SM_Zombz_walker103",
		"SM_Zombz_walker104",
		"SM_Zombz_walker105",
		"SM_Zombz_walker106",
		"SM_Zombz_walker107",
		"SM_Zombz_walker108",
		"SM_Zombz_walker109",
		"SM_Zombz_walker110",
		"SM_Zombz_walker111",
		"SM_Zombz_walker112",
		"SM_Zombz_walker113",
		"SM_Zombz_walker114",
		"SM_Zombz_walker115",
		"SM_Zombz_walker116",
		"SM_Zombz_walker117",
		"SM_Zombz_walker118",
		"SM_Zombz_walker119",
		"SM_Zombz_walker120",
		"SM_Zombz_walker121",
		"SM_Zombz_walker122",
		"SM_Zombz_walker123",
		"SM_Zombz_walker124",
		"SM_Zombz_walker125",
		"SM_Zombz_walker126",
		"SM_Zombz_walker127",
		"SM_Zombz_walker128",
		"SM_Zombz_walker129",
		"SM_Zombz_walker130",
		"SM_Zombz_walker131",
		"SM_Zombz_walker132",
		"SM_Zombz_walker133",
		"SM_Zombz_walker134",
		"SM_Zombz_walker135",
		"SM_Zombz_walker136",
		"SM_Zombz_walker137",
		"SM_Zombz_walker138",
		"SM_Zombz_walker139",
		"SM_Zombz_walker140",
		"SM_Zombz_walker141",
		"SM_Zombz_walker142",
		"SM_Zombz_walker143",
		"SM_Zombz_walker144",
		"SM_Zombz_walker145",
		"SM_Zombz_walker146",
		"SM_Zombz_walker147",
		"SM_Zombz_walker149",
		"SM_Zombz_walker150",
		"SM_Zombz_walker151",
		"SM_Zombz_walker152",
		"SM_Zombz_walker153",
		"SM_Zombz_walker154",
		"SM_Zombz_walker155",
		"SM_Zombz_walker156",
		"SM_Zombz_walker157",
		"SM_Zombz_walker158",
		"SM_Zombz_walker159",
		"SM_Zombz_walker160",
		"SM_Zombz_walker161",
		"SM_Zombz_walker162",
		"SM_Zombz_walker163",
		"SM_Zombz_walker164",
		"SM_Zombz_walker165",
		"SM_Zombz_walker166",
		"SM_Zombz_walker167",
		"SM_Zombz_walker168",
		"SM_Zombz_walker169",
		"SM_Zombz_walker170",
		"SM_Zombz_walker171",
		"SM_Zombz_walker172",
		"SM_Zombz_walker173",
		"SM_Zombz_walker174",
		"SM_Zombz_walker175",
		"SM_Zombz_walker176",
		"SM_Zombz_walker177",
		"SM_Zombz_walker178",
		"SM_Zombz_walker179",
		"SM_Zombz_walker180",
		"SM_Zombz_walker181",
		"SM_Zombz_walker182",
		"SM_Zombz_walker183",
		"SM_Zombz_walker184",
		"SM_Zombz_walker185",
		"SM_Zombz_walker186",
		"SM_Zombz_walker187",
		"SM_Zombz_walker188",
		"SM_Zombz_walker189",
		"SM_Zombz_walker190",
		"SM_Zombz_walker191",
		"SM_Zombz_walker192",
		"SM_Zombz_walker193",
		"SM_Zombz_walker194",
		"SM_Zombz_walker195",
		"SM_Zombz_walker196",
		"SM_Zombz_walker197",
		"SM_Zombz_walker198",
		"SM_Zombz_walker199",
		"SM_Zombz_walker200",
		"SM_Zombz_walker201",
		"SM_Zombz_walker202",
		"SM_Zombz_walker203",
		"SM_Zombz_walker204",
		"SM_Zombz_walker205",
		"SM_Zombz_walker206",
		"SM_Zombz_walker207",
		"SM_Zombz_walker208",
		"SM_Zombz_walker209",
		"SM_Zombz_walker210",
		"SM_Zombz_walker211",
		"SM_Zombz_walker212",
		"SM_Zombz_walker213",
		"SM_Zombz_walker214",
		"SM_Zombz_walker215",
		"SM_Zombz_walker216",
		"SM_Zombz_walker217",
		"SM_Zombz_walker218",
		"SM_Zombz_walker219",
		"SM_Zombz_walker220",
		"SM_Zombz_walker221",
		"SM_Zombz_walker222",
		"SM_Zombz_walker223",
		"SM_Zombz_walker224",
		"SM_Zombz_walker225",
		"SM_Zombz_walker226",
		"SM_Zombz_walker227",
		"SM_Zombz_walker228",
		"SM_Zombz_walker229",
		"SM_Zombz_walker230",
		"SM_Zombz_walker231",
		"SM_Zombz_walker232",
		"SM_Zombz_walker233",
		"SM_Zombz_walker234",
		"SM_Zombz_walker235",
		"SM_Zombz_walker236",
		"SM_Zombz_walker237",
		"SM_Zombz_walker238",
		"SM_Zombz_walker239",
		"SM_Zombz_walker240",
		"SM_Zombz_walker241",
		"SM_Zombz_walker242",
		"SM_Zombz_walker243",
		"SM_Zombz_walker244",
		"SM_Zombz_walker245",
		"SM_Zombz_walker246",
		"SM_Zombz_walker247",
		"SM_Zombz_walker248",
		"SM_Zombz_walker249",
		"SM_Zombz_walker250",
		"SM_Zombz_walker251",
		"SM_Zombz_walker252",
		"SM_Zombz_walker253",
		"SM_Zombz_walker254",
		"SM_Zombz_walker255",
		"SM_Zombz_walker256",


		"SM_Zombz_FemaleWalker1",
		"SM_Zombz_FemaleWalker2",
		"SM_Zombz_FemaleWalker3",
		"SM_Zombz_FemaleWalker4",
		"SM_Zombz_FemaleWalker5",
		"SM_Zombz_FemaleWalker6",
		"SM_Zombz_FemaleWalker7",
		"SM_Zombz_FemaleWalker8",
		"SM_Zombz_FemaleWalker9",
		"SM_Zombz_FemaleWalker10",
		"SM_Zombz_FemaleWalker11",
		"SM_Zombz_FemaleWalker12",
		"SM_Zombz_FemaleWalker13",
		"SM_Zombz_FemaleWalker14",
		"SM_Zombz_FemaleWalker15",
		"SM_Zombz_FemaleWalker16",
		"SM_Zombz_FemaleWalker17",
		"SM_Zombz_FemaleWalker18",
		"SM_Zombz_FemaleWalker19",
		"SM_Zombz_FemaleWalker20",
		"SM_Zombz_FemaleWalker21"
	};
};