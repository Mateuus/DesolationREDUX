_target = _this select 0;
_side = _this select 1;

if ((!isServer) and hasInterface) exitwith {};

_uniform = uniform _target;
_backpack = backpack _target;
_vest = vest _target;
_headgear = headgear _target;
_dir = getdir _target;
_pos = getposATL _target;
_sidetarget = side group _target;
_x = [];
_array = [];

if (_side == CIVILIAN) exitwith {};
sleep Ryanzombiesinfectiontimer;

if (ryanzombiesinfection == 0.9) then
{
	_array = ["RyanZombieC_man_1", "RyanZombieC_man_polo_1_F", "RyanZombieC_man_polo_2_F", "RyanZombieC_man_polo_4_F", "RyanZombieC_man_polo_5_F", "RyanZombieC_man_polo_6_F", "RyanZombieC_man_p_fugitive_F", "RyanZombieC_man_w_worker_F", "RyanZombieC_scientist_F", "RyanZombieC_man_hunter_1_F", "RyanZombieC_man_pilot_F", "RyanZombieC_journalist_F", "RyanZombieC_Orestes", "RyanZombieC_Nikos", "RyanZombie15", "RyanZombie16", "RyanZombie17", "RyanZombie18", "RyanZombie19", "RyanZombie20", "RyanZombie21", "RyanZombie22", "RyanZombie23", "RyanZombie24", "RyanZombie25", "RyanZombie26", "RyanZombie27", "RyanZombie28", "RyanZombie29", "RyanZombie30", "RyanZombie31", "RyanZombie32"];
	if (_sidetarget == WEST) then {_x = "RyanZombieB_Soldier_BluforResurrect";};
	if (_sidetarget == EAST) then {_x = "RyanZombieB_Soldier_OpforResurrect";};
	if (_sidetarget == RESISTANCE) then {_x = "RyanZombieB_Soldier_IndepResurrect";};
};

if (ryanzombiesinfection == 0.7) then
{
	_array = ["RyanZombieC_man_1medium", "RyanZombieC_man_polo_1_Fmedium", "RyanZombieC_man_polo_2_Fmedium", "RyanZombieC_man_polo_4_Fmedium", "RyanZombieC_man_polo_5_Fmedium", "RyanZombieC_man_polo_6_Fmedium", "RyanZombieC_man_p_fugitive_Fmedium", "RyanZombieC_man_w_worker_Fmedium", "RyanZombieC_scientist_Fmedium", "RyanZombieC_man_hunter_1_Fmedium", "RyanZombieC_man_pilot_Fmedium", "RyanZombieC_journalist_Fmedium", "RyanZombieC_Orestesmedium", "RyanZombieC_Nikosmedium", "RyanZombie15medium", "RyanZombie16medium", "RyanZombie17medium", "RyanZombie18medium", "RyanZombie19medium", "RyanZombie20medium", "RyanZombie21medium", "RyanZombie22medium", "RyanZombie23medium", "RyanZombie24medium", "RyanZombie25medium", "RyanZombie26medium", "RyanZombie27medium", "RyanZombie28medium", "RyanZombie29medium", "RyanZombie30medium", "RyanZombie31medium", "RyanZombie32medium"];
	if (_sidetarget == WEST) then {_x = "RyanZombieB_Soldier_BluforResurrectmedium";};
	if (_sidetarget == EAST) then {_x = "RyanZombieB_Soldier_OpforResurrectmedium";};
	if (_sidetarget == RESISTANCE) then {_x = "RyanZombieB_Soldier_IndepResurrectmedium";};
};

if (ryanzombiesinfection == 0.5) then
{
	_array = ["RyanZombieC_man_1slow", "RyanZombieC_man_polo_1_Fslow", "RyanZombieC_man_polo_2_Fslow", "RyanZombieC_man_polo_4_Fslow", "RyanZombieC_man_polo_5_Fslow", "RyanZombieC_man_polo_6_Fslow", "RyanZombieC_man_p_fugitive_Fslow", "RyanZombieC_man_w_worker_Fslow", "RyanZombieC_scientist_Fslow", "RyanZombieC_man_hunter_1_Fslow", "RyanZombieC_man_pilot_Fslow", "RyanZombieC_journalist_Fslow", "RyanZombieC_Orestesslow", "RyanZombieC_Nikosslow", "RyanZombie15slow", "RyanZombie16slow", "RyanZombie17slow", "RyanZombie18slow", "RyanZombie19slow", "RyanZombie20slow", "RyanZombie21slow", "RyanZombie22slow", "RyanZombie23slow", "RyanZombie24slow", "RyanZombie25slow", "RyanZombie26slow", "RyanZombie27slow", "RyanZombie28slow", "RyanZombie29slow", "RyanZombie30slow", "RyanZombie31slow", "RyanZombie32slow"];
	if (_sidetarget == WEST) then {_x = "RyanZombieB_Soldier_BluforResurrectslow";};
	if (_sidetarget == EAST) then {_x = "RyanZombieB_Soldier_OpforResurrectslow";};
	if (_sidetarget == RESISTANCE) then {_x = "RyanZombieB_Soldier_IndepResurrectslow";};
};

if (ryanzombiesinfection == 0.4) then
{
	_array = ["RyanZombieC_man_1Walker", "RyanZombieC_man_polo_1_FWalker", "RyanZombieC_man_polo_2_FWalker", "RyanZombieC_man_polo_4_FWalker", "RyanZombieC_man_polo_5_FWalker", "RyanZombieC_man_polo_6_FWalker", "RyanZombieC_man_p_fugitive_FWalker", "RyanZombieC_man_w_worker_FWalker", "RyanZombieC_scientist_FWalker", "RyanZombieC_man_hunter_1_FWalker", "RyanZombieC_man_pilot_FWalker", "RyanZombieC_journalist_FWalker", "RyanZombieC_OrestesWalker", "RyanZombieC_NikosWalker", "RyanZombie15walker", "RyanZombie16walker", "RyanZombie17walker", "RyanZombie18walker", "RyanZombie19walker", "RyanZombie20walker", "RyanZombie21walker", "RyanZombie22walker", "RyanZombie23walker", "RyanZombie24walker", "RyanZombie25walker", "RyanZombie26walker", "RyanZombie27walker", "RyanZombie28walker", "RyanZombie29walker", "RyanZombie30walker", "RyanZombie31walker", "RyanZombie32walker"];
	if (_sidetarget == WEST) then {_x = "RyanZombieB_Soldier_BluforResurrectWalker";};
	if (_sidetarget == EAST) then {_x = "RyanZombieB_Soldier_OpforResurrectWalker";};
	if (_sidetarget == RESISTANCE) then {_x = "RyanZombieB_Soldier_IndepResurrectWalker";};
};

if (ryanzombiesinfection == 0.3) then
{
	_array = ["RyanZombieboss1", "RyanZombieboss2", "RyanZombieboss3", "RyanZombieboss4", "RyanZombieboss5", "RyanZombieboss6", "RyanZombieboss7", "RyanZombieboss8", "RyanZombieboss9", "RyanZombieboss10", "RyanZombieboss11", "RyanZombieboss12", "RyanZombieboss13", "RyanZombieboss14", "RyanZombieboss15", "RyanZombieboss16", "RyanZombieboss17", "RyanZombieboss18", "RyanZombieboss19", "RyanZombieboss20", "RyanZombieboss21", "RyanZombieboss22", "RyanZombieboss23", "RyanZombieboss24", "RyanZombieboss25", "RyanZombieboss26", "RyanZombieboss27", "RyanZombieboss28", "RyanZombieboss29", "RyanZombieboss30", "RyanZombieboss31", "RyanZombieboss32"];
	_x = selectRandom _array;
};

if (ryanzombiesinfection == 0.1) then
{
	_array = ["RyanZombieSpider1", "RyanZombieSpider2", "RyanZombieSpider3", "RyanZombieSpider4", "RyanZombieSpider5", "RyanZombieSpider6", "RyanZombieSpider7", "RyanZombieSpider8", "RyanZombieSpider9", "RyanZombieSpider10", "RyanZombieSpider11", "RyanZombieSpider12", "RyanZombieSpider13", "RyanZombieSpider14", "RyanZombieSpider15", "RyanZombieSpider16", "RyanZombieSpider17", "RyanZombieSpider18", "RyanZombieSpider19", "RyanZombieSpider20", "RyanZombieSpider21", "RyanZombieSpider22", "RyanZombieSpider23", "RyanZombieSpider24", "RyanZombieSpider25", "RyanZombieSpider26", "RyanZombieSpider27", "RyanZombieSpider28", "RyanZombieSpider29", "RyanZombieSpider30", "RyanZombieSpider31", "RyanZombieSpider32"];
	if (_sidetarget == WEST) then {_x = "RyanZombieB_Soldier_BluforResurrectSpider";};
	if (_sidetarget == EAST) then {_x = "RyanZombieB_Soldier_OpforResurrectSpider";};
	if (_sidetarget == RESISTANCE) then {_x = "RyanZombieB_Soldier_IndepResurrectSpider";};
};

if (ryanzombiesinfection == 0.05) then
{
	_array = ["RyanZombieCrawler1", "RyanZombieCrawler2", "RyanZombieCrawler3", "RyanZombieCrawler4", "RyanZombieCrawler5", "RyanZombieCrawler6", "RyanZombieCrawler7", "RyanZombieCrawler8", "RyanZombieCrawler9", "RyanZombieCrawler10", "RyanZombieCrawler11", "RyanZombieCrawler12", "RyanZombieCrawler13", "RyanZombieCrawler14", "RyanZombieCrawler15", "RyanZombieCrawler16", "RyanZombieCrawler17", "RyanZombieCrawler18", "RyanZombieCrawler19", "RyanZombieCrawler20", "RyanZombieCrawler21", "RyanZombieCrawler22", "RyanZombieCrawler23", "RyanZombieCrawler24", "RyanZombieCrawler25", "RyanZombieCrawler26", "RyanZombieCrawler27", "RyanZombieCrawler28", "RyanZombieCrawler29", "RyanZombieCrawler30", "RyanZombieCrawler31", "RyanZombieCrawler32"];
	if (_sidetarget == WEST) then {_x = "RyanZombieB_Soldier_BluforResurrectCrawler";};
	if (_sidetarget == EAST) then {_x = "RyanZombieB_Soldier_OpforResurrectCrawler";};
	if (_sidetarget == RESISTANCE) then {_x = "RyanZombieB_Soldier_IndepResurrectCrawler";};
};

if (_sidetarget == CIVILIAN) then {_x = selectRandom _array;};

if !(_x IsEqualTo []) then
{
	_grp = creategroup _side;
	format ["%1",_x] createunit [_pos, _grp, "if !(_backpack isEqualTo '') then {this addbackpack _backpack}; if !(_vest isEqualTo '') then {this addvest _vest}; if !(_headgear isEqualTo '') then {this addheadgear _headgear}; this switchmove 'AmovPpneMstpSnonWnonDnon'; this playmove 'AmovPercMstpSnonWnonDnon'; this setdir _dir; if (ryanzombiesuniform == 0.7) then {this forceadduniform _uniform; this switchmove ''};"];
	deletevehicle _target;
};