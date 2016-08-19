_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

_logic setvariable ["Dead",0];

_Side = _logic getVariable ["Side",1];
_Team = resistance;
if ((_Side == 2) OR (_Side == 0.7)) then {_Team = east;};
if ((_Side == 3) OR (_Side == 0.5)) then {_Team = west;};

_Type = _logic getVariable ["Type",1];
_Type2 = _logic getVariable ["Type2",0];
_Type3 = _logic getVariable ["Type3",0];
_Type4 = _logic getVariable ["Type4",[]];
if (_type4 isEqualTo "") then {_type4 = [];};
call compile format ["_type4 = %1",_type4];
_array = [];

_a1 = ["RyanZombieC_man_1", "RyanZombieC_man_polo_1_F", "RyanZombieC_man_polo_2_F", "RyanZombieC_man_polo_4_F", "RyanZombieC_man_polo_5_F", "RyanZombieC_man_polo_6_F", "RyanZombieC_man_p_fugitive_F", "RyanZombieC_man_w_worker_F", "RyanZombieC_scientist_F", "RyanZombieC_man_hunter_1_F", "RyanZombieC_man_pilot_F", "RyanZombieC_journalist_F", "RyanZombieC_Orestes", "RyanZombieC_Nikos", "RyanZombie15", "RyanZombie16", "RyanZombie17", "RyanZombie18", "RyanZombie19", "RyanZombie20", "RyanZombie21", "RyanZombie22", "RyanZombie23", "RyanZombie24", "RyanZombie25", "RyanZombie26", "RyanZombie27", "RyanZombie28", "RyanZombie29", "RyanZombie30", "RyanZombie31", "RyanZombie32"];
_a2 = ["RyanZombieB_Soldier_02_f", "RyanZombieB_Soldier_02_f_1", "RyanZombieB_Soldier_02_f_1_1", "RyanZombieB_Soldier_03_f", "RyanZombieB_Soldier_03_f_1", "RyanZombieB_Soldier_03_f_1_1", "RyanZombieB_Soldier_04_f", "RyanZombieB_Soldier_04_f_1", "RyanZombieB_Soldier_04_f_1_1", "RyanZombieB_Soldier_lite_F", "RyanZombieB_Soldier_lite_F_1"];
_a3 = ["RyanZombieC_man_1", "RyanZombieC_man_polo_1_F", "RyanZombieC_man_polo_2_F", "RyanZombieC_man_polo_4_F", "RyanZombieC_man_polo_5_F", "RyanZombieC_man_polo_6_F", "RyanZombieC_man_p_fugitive_F", "RyanZombieC_man_w_worker_F", "RyanZombieC_scientist_F", "RyanZombieC_man_hunter_1_F", "RyanZombieC_man_pilot_F", "RyanZombieC_journalist_F", "RyanZombieC_Orestes", "RyanZombieC_Nikos", "RyanZombie15", "RyanZombie16", "RyanZombie17", "RyanZombie18", "RyanZombie19", "RyanZombie20", "RyanZombie21", "RyanZombie22", "RyanZombie23", "RyanZombie24", "RyanZombie25", "RyanZombie26", "RyanZombie27", "RyanZombie28", "RyanZombie29", "RyanZombie30", "RyanZombie31", "RyanZombie32", "RyanZombieB_Soldier_02_f", "RyanZombieB_Soldier_02_f_1", "RyanZombieB_Soldier_02_f_1_1", "RyanZombieB_Soldier_03_f", "RyanZombieB_Soldier_03_f_1", "RyanZombieB_Soldier_03_f_1_1", "RyanZombieB_Soldier_04_f", "RyanZombieB_Soldier_04_f_1", "RyanZombieB_Soldier_04_f_1_1", "RyanZombieB_Soldier_lite_F", "RyanZombieB_Soldier_lite_F_1"];
_a4 = ["RyanZombieC_man_1medium", "RyanZombieC_man_polo_1_Fmedium", "RyanZombieC_man_polo_2_Fmedium", "RyanZombieC_man_polo_4_Fmedium", "RyanZombieC_man_polo_5_Fmedium", "RyanZombieC_man_polo_6_Fmedium", "RyanZombieC_man_p_fugitive_Fmedium", "RyanZombieC_man_w_worker_Fmedium", "RyanZombieC_scientist_Fmedium", "RyanZombieC_man_hunter_1_Fmedium", "RyanZombieC_man_pilot_Fmedium", "RyanZombieC_journalist_Fmedium", "RyanZombieC_Orestesmedium", "RyanZombieC_Nikosmedium", "RyanZombie15medium", "RyanZombie16medium", "RyanZombie17medium", "RyanZombie18medium", "RyanZombie19medium", "RyanZombie20medium", "RyanZombie21medium", "RyanZombie22medium", "RyanZombie23medium", "RyanZombie24medium", "RyanZombie25medium", "RyanZombie26medium", "RyanZombie27medium", "RyanZombie28medium", "RyanZombie29medium", "RyanZombie30medium", "RyanZombie31medium", "RyanZombie32medium"];
_a5 = ["RyanZombieB_Soldier_02_fmedium", "RyanZombieB_Soldier_02_f_1medium", "RyanZombieB_Soldier_02_f_1_1medium", "RyanZombieB_Soldier_03_fmedium", "RyanZombieB_Soldier_03_f_1medium", "RyanZombieB_Soldier_03_f_1_1medium", "RyanZombieB_Soldier_04_fmedium", "RyanZombieB_Soldier_04_f_1medium", "RyanZombieB_Soldier_04_f_1_1medium", "RyanZombieB_Soldier_lite_Fmedium", "RyanZombieB_Soldier_lite_F_1medium"];
_a6 = ["RyanZombieC_man_1medium", "RyanZombieC_man_polo_1_Fmedium", "RyanZombieC_man_polo_2_Fmedium", "RyanZombieC_man_polo_4_Fmedium", "RyanZombieC_man_polo_5_Fmedium", "RyanZombieC_man_polo_6_Fmedium", "RyanZombieC_man_p_fugitive_Fmedium", "RyanZombieC_man_w_worker_Fmedium", "RyanZombieC_scientist_Fmedium", "RyanZombieC_man_hunter_1_Fmedium", "RyanZombieC_man_pilot_Fmedium", "RyanZombieC_journalist_Fmedium", "RyanZombieC_Orestesmedium", "RyanZombieC_Nikosmedium", "RyanZombie15medium", "RyanZombie16medium", "RyanZombie17medium", "RyanZombie18medium", "RyanZombie19medium", "RyanZombie20medium", "RyanZombie21medium", "RyanZombie22medium", "RyanZombie23medium", "RyanZombie24medium", "RyanZombie25medium", "RyanZombie26medium", "RyanZombie27medium", "RyanZombie28medium", "RyanZombie29medium", "RyanZombie30medium", "RyanZombie31medium", "RyanZombie32medium", "RyanZombieB_Soldier_02_fmedium", "RyanZombieB_Soldier_02_f_1medium", "RyanZombieB_Soldier_02_f_1_1medium", "RyanZombieB_Soldier_03_fmedium", "RyanZombieB_Soldier_03_f_1medium", "RyanZombieB_Soldier_03_f_1_1medium", "RyanZombieB_Soldier_04_fmedium", "RyanZombieB_Soldier_04_f_1medium", "RyanZombieB_Soldier_04_f_1_1medium", "RyanZombieB_Soldier_lite_Fmedium", "RyanZombieB_Soldier_lite_F_1medium"];
_a7 = ["RyanZombieC_man_1slow", "RyanZombieC_man_polo_1_Fslow", "RyanZombieC_man_polo_2_Fslow", "RyanZombieC_man_polo_4_Fslow", "RyanZombieC_man_polo_5_Fslow", "RyanZombieC_man_polo_6_Fslow", "RyanZombieC_man_p_fugitive_Fslow", "RyanZombieC_man_w_worker_Fslow", "RyanZombieC_scientist_Fslow", "RyanZombieC_man_hunter_1_Fslow", "RyanZombieC_man_pilot_Fslow", "RyanZombieC_journalist_Fslow", "RyanZombieC_Orestesslow", "RyanZombieC_Nikosslow", "RyanZombie15slow", "RyanZombie16slow", "RyanZombie17slow", "RyanZombie18slow", "RyanZombie19slow", "RyanZombie20slow", "RyanZombie21slow", "RyanZombie22slow", "RyanZombie23slow", "RyanZombie24slow", "RyanZombie25slow", "RyanZombie26slow", "RyanZombie27slow", "RyanZombie28slow", "RyanZombie29slow", "RyanZombie30slow", "RyanZombie31slow", "RyanZombie32slow"];
_a8 = ["RyanZombieB_Soldier_02_fslow", "RyanZombieB_Soldier_02_f_1slow", "RyanZombieB_Soldier_02_f_1_1slow", "RyanZombieB_Soldier_03_fslow", "RyanZombieB_Soldier_03_f_1slow", "RyanZombieB_Soldier_03_f_1_1slow", "RyanZombieB_Soldier_04_fslow", "RyanZombieB_Soldier_04_f_1slow", "RyanZombieB_Soldier_04_f_1_1slow", "RyanZombieB_Soldier_lite_Fslow", "RyanZombieB_Soldier_lite_F_1slow"];
_a9 = ["RyanZombieC_man_1slow", "RyanZombieC_man_polo_1_Fslow", "RyanZombieC_man_polo_2_Fslow", "RyanZombieC_man_polo_4_Fslow", "RyanZombieC_man_polo_5_Fslow", "RyanZombieC_man_polo_6_Fslow", "RyanZombieC_man_p_fugitive_Fslow", "RyanZombieC_man_w_worker_Fslow", "RyanZombieC_scientist_Fslow", "RyanZombieC_man_hunter_1_Fslow", "RyanZombieC_man_pilot_Fslow", "RyanZombieC_journalist_Fslow", "RyanZombieC_Orestesslow", "RyanZombieC_Nikosslow", "RyanZombie15slow", "RyanZombie16slow", "RyanZombie17slow", "RyanZombie18slow", "RyanZombie19slow", "RyanZombie20slow", "RyanZombie21slow", "RyanZombie22slow", "RyanZombie23slow", "RyanZombie24slow", "RyanZombie25slow", "RyanZombie26slow", "RyanZombie27slow", "RyanZombie28slow", "RyanZombie29slow", "RyanZombie30slow", "RyanZombie31slow", "RyanZombie32slow", "RyanZombieB_Soldier_02_fslow", "RyanZombieB_Soldier_02_f_1slow", "RyanZombieB_Soldier_02_f_1_1slow", "RyanZombieB_Soldier_03_fslow", "RyanZombieB_Soldier_03_f_1slow", "RyanZombieB_Soldier_03_f_1_1slow", "RyanZombieB_Soldier_04_fslow", "RyanZombieB_Soldier_04_f_1slow", "RyanZombieB_Soldier_04_f_1_1slow", "RyanZombieB_Soldier_lite_Fslow", "RyanZombieB_Soldier_lite_F_1slow"];
_a10 = ["RyanZombieC_man_1Walker", "RyanZombieC_man_polo_1_FWalker", "RyanZombieC_man_polo_2_FWalker", "RyanZombieC_man_polo_4_FWalker", "RyanZombieC_man_polo_5_FWalker", "RyanZombieC_man_polo_6_FWalker", "RyanZombieC_man_p_fugitive_FWalker", "RyanZombieC_man_w_worker_FWalker", "RyanZombieC_scientist_FWalker", "RyanZombieC_man_hunter_1_FWalker", "RyanZombieC_man_pilot_FWalker", "RyanZombieC_journalist_FWalker", "RyanZombieC_OrestesWalker", "RyanZombieC_NikosWalker", "RyanZombie15walker", "RyanZombie16walker", "RyanZombie17walker", "RyanZombie18walker", "RyanZombie19walker", "RyanZombie20walker", "RyanZombie21walker", "RyanZombie22walker", "RyanZombie23walker", "RyanZombie24walker", "RyanZombie25walker", "RyanZombie26walker", "RyanZombie27walker", "RyanZombie28walker", "RyanZombie29walker", "RyanZombie30walker", "RyanZombie31walker", "RyanZombie32walker"];
_a11 = ["RyanZombieB_Soldier_02_fWalker", "RyanZombieB_Soldier_02_f_1Walker", "RyanZombieB_Soldier_02_f_1_1Walker", "RyanZombieB_Soldier_03_fWalker", "RyanZombieB_Soldier_03_f_1Walker", "RyanZombieB_Soldier_03_f_1_1Walker", "RyanZombieB_Soldier_04_fWalker", "RyanZombieB_Soldier_04_f_1Walker", "RyanZombieB_Soldier_04_f_1_1Walker", "RyanZombieB_Soldier_lite_FWalker", "RyanZombieB_Soldier_lite_F_1Walker"];
_a12 = ["RyanZombieC_man_1Walker", "RyanZombieC_man_polo_1_FWalker", "RyanZombieC_man_polo_2_FWalker", "RyanZombieC_man_polo_4_FWalker", "RyanZombieC_man_polo_5_FWalker", "RyanZombieC_man_polo_6_FWalker", "RyanZombieC_man_p_fugitive_FWalker", "RyanZombieC_man_w_worker_FWalker", "RyanZombieC_scientist_FWalker", "RyanZombieC_man_hunter_1_FWalker", "RyanZombieC_man_pilot_FWalker", "RyanZombieC_journalist_FWalker", "RyanZombieC_OrestesWalker", "RyanZombieC_NikosWalker", "RyanZombie15walker", "RyanZombie16walker", "RyanZombie17walker", "RyanZombie18walker", "RyanZombie19walker", "RyanZombie20walker", "RyanZombie21walker", "RyanZombie22walker", "RyanZombie23walker", "RyanZombie24walker", "RyanZombie25walker", "RyanZombie26walker", "RyanZombie27walker", "RyanZombie28walker", "RyanZombie29walker", "RyanZombie30walker", "RyanZombie31walker", "RyanZombie32walker", "RyanZombieB_Soldier_02_fWalker", "RyanZombieB_Soldier_02_f_1Walker", "RyanZombieB_Soldier_02_f_1_1Walker", "RyanZombieB_Soldier_03_fWalker", "RyanZombieB_Soldier_03_f_1Walker", "RyanZombieB_Soldier_03_f_1_1Walker", "RyanZombieB_Soldier_04_fWalker", "RyanZombieB_Soldier_04_f_1Walker", "RyanZombieB_Soldier_04_f_1_1Walker", "RyanZombieB_Soldier_lite_FWalker", "RyanZombieB_Soldier_lite_F_1Walker"];
_a13 = ["RyanZombieboss1", "RyanZombieboss2", "RyanZombieboss3", "RyanZombieboss4", "RyanZombieboss5", "RyanZombieboss6", "RyanZombieboss7", "RyanZombieboss8", "RyanZombieboss9", "RyanZombieboss10", "RyanZombieboss11", "RyanZombieboss12", "RyanZombieboss13", "RyanZombieboss14", "RyanZombieboss15", "RyanZombieboss16", "RyanZombieboss17", "RyanZombieboss18", "RyanZombieboss19", "RyanZombieboss20", "RyanZombieboss21", "RyanZombieboss22", "RyanZombieboss23", "RyanZombieboss24", "RyanZombieboss25", "RyanZombieboss26", "RyanZombieboss27", "RyanZombieboss28", "RyanZombieboss29", "RyanZombieboss30", "RyanZombieboss31", "RyanZombieboss32"];
_a14 = ["RyanZombieSpider1", "RyanZombieSpider2", "RyanZombieSpider3", "RyanZombieSpider4", "RyanZombieSpider5", "RyanZombieSpider6", "RyanZombieSpider7", "RyanZombieSpider8", "RyanZombieSpider9", "RyanZombieSpider10", "RyanZombieSpider11", "RyanZombieSpider12", "RyanZombieSpider13", "RyanZombieSpider14", "RyanZombieSpider15", "RyanZombieSpider16", "RyanZombieSpider17", "RyanZombieSpider18", "RyanZombieSpider19", "RyanZombieSpider20", "RyanZombieSpider21", "RyanZombieSpider22", "RyanZombieSpider23", "RyanZombieSpider24", "RyanZombieSpider25", "RyanZombieSpider26", "RyanZombieSpider27", "RyanZombieSpider28", "RyanZombieSpider29", "RyanZombieSpider30", "RyanZombieSpider31", "RyanZombieSpider32"];
_a15 = ["RyanZombieCrawler1", "RyanZombieCrawler2", "RyanZombieCrawler3", "RyanZombieCrawler4", "RyanZombieCrawler5", "RyanZombieCrawler6", "RyanZombieCrawler7", "RyanZombieCrawler8", "RyanZombieCrawler9", "RyanZombieCrawler10", "RyanZombieCrawler11", "RyanZombieCrawler12", "RyanZombieCrawler13", "RyanZombieCrawler14", "RyanZombieCrawler15", "RyanZombieCrawler16", "RyanZombieCrawler17", "RyanZombieCrawler18", "RyanZombieCrawler19", "RyanZombieCrawler20", "RyanZombieCrawler21", "RyanZombieCrawler22", "RyanZombieCrawler23", "RyanZombieCrawler24", "RyanZombieCrawler25", "RyanZombieCrawler26", "RyanZombieCrawler27", "RyanZombieCrawler28", "RyanZombieCrawler29", "RyanZombieCrawler30", "RyanZombieCrawler31", "RyanZombieCrawler32"];
_a16 = ["RyanZombieC_man_1", "RyanZombieC_man_polo_1_F", "RyanZombieC_man_polo_2_F", "RyanZombieC_man_polo_4_F", "RyanZombieC_man_polo_5_F", "RyanZombieC_man_polo_6_F", "RyanZombieC_man_p_fugitive_F", "RyanZombieC_man_w_worker_F", "RyanZombieC_scientist_F", "RyanZombieC_man_hunter_1_F", "RyanZombieC_man_pilot_F", "RyanZombieC_journalist_F", "RyanZombieC_Orestes", "RyanZombieC_Nikos", "RyanZombie15", "RyanZombie16", "RyanZombie17", "RyanZombie18", "RyanZombie19", "RyanZombie20", "RyanZombie21", "RyanZombie22", "RyanZombie23", "RyanZombie24", "RyanZombie25", "RyanZombie26", "RyanZombie27", "RyanZombie28", "RyanZombie29", "RyanZombie30", "RyanZombie31", "RyanZombie32", "RyanZombieB_Soldier_02_f", "RyanZombieB_Soldier_02_f_1", "RyanZombieB_Soldier_02_f_1_1", "RyanZombieB_Soldier_03_f", "RyanZombieB_Soldier_03_f_1", "RyanZombieB_Soldier_03_f_1_1", "RyanZombieB_Soldier_04_f", "RyanZombieB_Soldier_04_f_1", "RyanZombieB_Soldier_04_f_1_1", "RyanZombieB_Soldier_lite_F", "RyanZombieB_Soldier_lite_F_1", "RyanZombieC_man_1medium", "RyanZombieC_man_polo_1_Fmedium", "RyanZombieC_man_polo_2_Fmedium", "RyanZombieC_man_polo_4_Fmedium", "RyanZombieC_man_polo_5_Fmedium", "RyanZombieC_man_polo_6_Fmedium", "RyanZombieC_man_p_fugitive_Fmedium", "RyanZombieC_man_w_worker_Fmedium", "RyanZombieC_scientist_Fmedium", "RyanZombieC_man_hunter_1_Fmedium", "RyanZombieC_man_pilot_Fmedium", "RyanZombieC_journalist_Fmedium", "RyanZombieC_Orestesmedium", "RyanZombieC_Nikosmedium", "RyanZombie15medium", "RyanZombie16medium", "RyanZombie17medium", "RyanZombie18medium", "RyanZombie19medium", "RyanZombie20medium", "RyanZombie21medium", "RyanZombie22medium", "RyanZombie23medium", "RyanZombie24medium", "RyanZombie25medium", "RyanZombie26medium", "RyanZombie27medium", "RyanZombie28medium", "RyanZombie29medium", "RyanZombie30medium", "RyanZombie31medium", "RyanZombie32medium", "RyanZombieB_Soldier_02_fmedium", "RyanZombieB_Soldier_02_f_1medium", "RyanZombieB_Soldier_02_f_1_1medium", "RyanZombieB_Soldier_03_fmedium", "RyanZombieB_Soldier_03_f_1medium", "RyanZombieB_Soldier_03_f_1_1medium", "RyanZombieB_Soldier_04_fmedium", "RyanZombieB_Soldier_04_f_1medium", "RyanZombieB_Soldier_04_f_1_1medium", "RyanZombieB_Soldier_lite_Fmedium", "RyanZombieB_Soldier_lite_F_1medium", "RyanZombieC_man_1slow", "RyanZombieC_man_polo_1_Fslow", "RyanZombieC_man_polo_2_Fslow", "RyanZombieC_man_polo_4_Fslow", "RyanZombieC_man_polo_5_Fslow", "RyanZombieC_man_polo_6_Fslow", "RyanZombieC_man_p_fugitive_Fslow", "RyanZombieC_man_w_worker_Fslow", "RyanZombieC_scientist_Fslow", "RyanZombieC_man_hunter_1_Fslow", "RyanZombieC_man_pilot_Fslow", "RyanZombieC_journalist_Fslow", "RyanZombieC_Orestesslow", "RyanZombieC_Nikosslow", "RyanZombie15slow", "RyanZombie16slow", "RyanZombie17slow", "RyanZombie18slow", "RyanZombie19slow", "RyanZombie20slow", "RyanZombie21slow", "RyanZombie22slow", "RyanZombie23slow", "RyanZombie24slow", "RyanZombie25slow", "RyanZombie26slow", "RyanZombie27slow", "RyanZombie28slow", "RyanZombie29slow", "RyanZombie30slow", "RyanZombie31slow", "RyanZombie32slow", "RyanZombieB_Soldier_02_fslow", "RyanZombieB_Soldier_02_f_1slow", "RyanZombieB_Soldier_02_f_1_1slow", "RyanZombieB_Soldier_03_fslow", "RyanZombieB_Soldier_03_f_1slow", "RyanZombieB_Soldier_03_f_1_1slow", "RyanZombieB_Soldier_04_fslow", "RyanZombieB_Soldier_04_f_1slow", "RyanZombieB_Soldier_04_f_1_1slow", "RyanZombieB_Soldier_lite_Fslow", "RyanZombieB_Soldier_lite_F_1slow", "RyanZombieC_man_1Walker", "RyanZombieC_man_polo_1_FWalker", "RyanZombieC_man_polo_2_FWalker", "RyanZombieC_man_polo_4_FWalker", "RyanZombieC_man_polo_5_FWalker", "RyanZombieC_man_polo_6_FWalker", "RyanZombieC_man_p_fugitive_FWalker", "RyanZombieC_man_w_worker_FWalker", "RyanZombieC_scientist_FWalker", "RyanZombieC_man_hunter_1_FWalker", "RyanZombieC_man_pilot_FWalker", "RyanZombieC_journalist_FWalker", "RyanZombieC_OrestesWalker", "RyanZombieC_NikosWalker", "RyanZombie15walker", "RyanZombie16walker", "RyanZombie17walker", "RyanZombie18walker", "RyanZombie19walker", "RyanZombie20walker", "RyanZombie21walker", "RyanZombie22walker", "RyanZombie23walker", "RyanZombie24walker", "RyanZombie25walker", "RyanZombie26walker", "RyanZombie27walker", "RyanZombie28walker", "RyanZombie29walker", "RyanZombie30walker", "RyanZombie31walker", "RyanZombie32walker", "RyanZombieB_Soldier_02_fWalker", "RyanZombieB_Soldier_02_f_1Walker", "RyanZombieB_Soldier_02_f_1_1Walker", "RyanZombieB_Soldier_03_fWalker", "RyanZombieB_Soldier_03_f_1Walker", "RyanZombieB_Soldier_03_f_1_1Walker", "RyanZombieB_Soldier_04_fWalker", "RyanZombieB_Soldier_04_f_1Walker", "RyanZombieB_Soldier_04_f_1_1Walker", "RyanZombieB_Soldier_lite_FWalker", "RyanZombieB_Soldier_lite_F_1Walker", "RyanZombieSpider1", "RyanZombieSpider2", "RyanZombieSpider3", "RyanZombieSpider4", "RyanZombieSpider5", "RyanZombieSpider6", "RyanZombieSpider7", "RyanZombieSpider8", "RyanZombieSpider9", "RyanZombieSpider10", "RyanZombieSpider11", "RyanZombieSpider12", "RyanZombieSpider13", "RyanZombieSpider14", "RyanZombieSpider15", "RyanZombieSpider16", "RyanZombieSpider17", "RyanZombieSpider18", "RyanZombieSpider19", "RyanZombieSpider20", "RyanZombieSpider21", "RyanZombieSpider22", "RyanZombieSpider23", "RyanZombieSpider24", "RyanZombieSpider25", "RyanZombieSpider26", "RyanZombieSpider27", "RyanZombieSpider28", "RyanZombieSpider29", "RyanZombieSpider30", "RyanZombieSpider31", "RyanZombieSpider32", "RyanZombieCrawler1", "RyanZombieCrawler2", "RyanZombieCrawler3", "RyanZombieCrawler4", "RyanZombieCrawler5", "RyanZombieCrawler6", "RyanZombieCrawler7", "RyanZombieCrawler8", "RyanZombieCrawler9", "RyanZombieCrawler10", "RyanZombieCrawler11", "RyanZombieCrawler12", "RyanZombieCrawler13", "RyanZombieCrawler14", "RyanZombieCrawler15", "RyanZombieCrawler16", "RyanZombieCrawler17", "RyanZombieCrawler18", "RyanZombieCrawler19", "RyanZombieCrawler20", "RyanZombieCrawler21", "RyanZombieCrawler22", "RyanZombieCrawler23", "RyanZombieCrawler24", "RyanZombieCrawler25", "RyanZombieCrawler26", "RyanZombieCrawler27", "RyanZombieCrawler28", "RyanZombieCrawler29", "RyanZombieCrawler30", "RyanZombieCrawler31", "RyanZombieCrawler32"];
_a17 = ["RyanZombieC_man_1", "RyanZombieC_man_polo_1_F", "RyanZombieC_man_polo_2_F", "RyanZombieC_man_polo_4_F", "RyanZombieC_man_polo_5_F", "RyanZombieC_man_polo_6_F", "RyanZombieC_man_p_fugitive_F", "RyanZombieC_man_w_worker_F", "RyanZombieC_scientist_F", "RyanZombieC_man_hunter_1_F", "RyanZombieC_man_pilot_F", "RyanZombieC_journalist_F", "RyanZombieC_Orestes", "RyanZombieC_Nikos", "RyanZombie15", "RyanZombie16", "RyanZombie17", "RyanZombie18", "RyanZombie19", "RyanZombie20", "RyanZombie21", "RyanZombie22", "RyanZombie23", "RyanZombie24", "RyanZombie25", "RyanZombie26", "RyanZombie27", "RyanZombie28", "RyanZombie29", "RyanZombie30", "RyanZombie31", "RyanZombie32", "RyanZombieB_Soldier_02_f", "RyanZombieB_Soldier_02_f_1", "RyanZombieB_Soldier_02_f_1_1", "RyanZombieB_Soldier_03_f", "RyanZombieB_Soldier_03_f_1", "RyanZombieB_Soldier_03_f_1_1", "RyanZombieB_Soldier_04_f", "RyanZombieB_Soldier_04_f_1", "RyanZombieB_Soldier_04_f_1_1", "RyanZombieB_Soldier_lite_F", "RyanZombieB_Soldier_lite_F_1", "RyanZombieC_man_1medium", "RyanZombieC_man_polo_1_Fmedium", "RyanZombieC_man_polo_2_Fmedium", "RyanZombieC_man_polo_4_Fmedium", "RyanZombieC_man_polo_5_Fmedium", "RyanZombieC_man_polo_6_Fmedium", "RyanZombieC_man_p_fugitive_Fmedium", "RyanZombieC_man_w_worker_Fmedium", "RyanZombieC_scientist_Fmedium", "RyanZombieC_man_hunter_1_Fmedium", "RyanZombieC_man_pilot_Fmedium", "RyanZombieC_journalist_Fmedium", "RyanZombieC_Orestesmedium", "RyanZombieC_Nikosmedium", "RyanZombie15medium", "RyanZombie16medium", "RyanZombie17medium", "RyanZombie18medium", "RyanZombie19medium", "RyanZombie20medium", "RyanZombie21medium", "RyanZombie22medium", "RyanZombie23medium", "RyanZombie24medium", "RyanZombie25medium", "RyanZombie26medium", "RyanZombie27medium", "RyanZombie28medium", "RyanZombie29medium", "RyanZombie30medium", "RyanZombie31medium", "RyanZombie32medium", "RyanZombieB_Soldier_02_fmedium", "RyanZombieB_Soldier_02_f_1medium", "RyanZombieB_Soldier_02_f_1_1medium", "RyanZombieB_Soldier_03_fmedium", "RyanZombieB_Soldier_03_f_1medium", "RyanZombieB_Soldier_03_f_1_1medium", "RyanZombieB_Soldier_04_fmedium", "RyanZombieB_Soldier_04_f_1medium", "RyanZombieB_Soldier_04_f_1_1medium", "RyanZombieB_Soldier_lite_Fmedium", "RyanZombieB_Soldier_lite_F_1medium", "RyanZombieC_man_1slow", "RyanZombieC_man_polo_1_Fslow", "RyanZombieC_man_polo_2_Fslow", "RyanZombieC_man_polo_4_Fslow", "RyanZombieC_man_polo_5_Fslow", "RyanZombieC_man_polo_6_Fslow", "RyanZombieC_man_p_fugitive_Fslow", "RyanZombieC_man_w_worker_Fslow", "RyanZombieC_scientist_Fslow", "RyanZombieC_man_hunter_1_Fslow", "RyanZombieC_man_pilot_Fslow", "RyanZombieC_journalist_Fslow", "RyanZombieC_Orestesslow", "RyanZombieC_Nikosslow", "RyanZombie15slow", "RyanZombie16slow", "RyanZombie17slow", "RyanZombie18slow", "RyanZombie19slow", "RyanZombie20slow", "RyanZombie21slow", "RyanZombie22slow", "RyanZombie23slow", "RyanZombie24slow", "RyanZombie25slow", "RyanZombie26slow", "RyanZombie27slow", "RyanZombie28slow", "RyanZombie29slow", "RyanZombie30slow", "RyanZombie31slow", "RyanZombie32slow", "RyanZombieB_Soldier_02_fslow", "RyanZombieB_Soldier_02_f_1slow", "RyanZombieB_Soldier_02_f_1_1slow", "RyanZombieB_Soldier_03_fslow", "RyanZombieB_Soldier_03_f_1slow", "RyanZombieB_Soldier_03_f_1_1slow", "RyanZombieB_Soldier_04_fslow", "RyanZombieB_Soldier_04_f_1slow", "RyanZombieB_Soldier_04_f_1_1slow", "RyanZombieB_Soldier_lite_Fslow", "RyanZombieB_Soldier_lite_F_1slow", "RyanZombieC_man_1Walker", "RyanZombieC_man_polo_1_FWalker", "RyanZombieC_man_polo_2_FWalker", "RyanZombieC_man_polo_4_FWalker", "RyanZombieC_man_polo_5_FWalker", "RyanZombieC_man_polo_6_FWalker", "RyanZombieC_man_p_fugitive_FWalker", "RyanZombieC_man_w_worker_FWalker", "RyanZombieC_scientist_FWalker", "RyanZombieC_man_hunter_1_FWalker", "RyanZombieC_man_pilot_FWalker", "RyanZombieC_journalist_FWalker", "RyanZombieC_OrestesWalker", "RyanZombieC_NikosWalker", "RyanZombie15walker", "RyanZombie16walker", "RyanZombie17walker", "RyanZombie18walker", "RyanZombie19walker", "RyanZombie20walker", "RyanZombie21walker", "RyanZombie22walker", "RyanZombie23walker", "RyanZombie24walker", "RyanZombie25walker", "RyanZombie26walker", "RyanZombie27walker", "RyanZombie28walker", "RyanZombie29walker", "RyanZombie30walker", "RyanZombie31walker", "RyanZombie32walker", "RyanZombieB_Soldier_02_fWalker", "RyanZombieB_Soldier_02_f_1Walker", "RyanZombieB_Soldier_02_f_1_1Walker", "RyanZombieB_Soldier_03_fWalker", "RyanZombieB_Soldier_03_f_1Walker", "RyanZombieB_Soldier_03_f_1_1Walker", "RyanZombieB_Soldier_04_fWalker", "RyanZombieB_Soldier_04_f_1Walker", "RyanZombieB_Soldier_04_f_1_1Walker", "RyanZombieB_Soldier_lite_FWalker", "RyanZombieB_Soldier_lite_F_1Walker"];

if ((_Type == 1) OR (_Type == 0.9)) then {_array = _a1;};
if ((_Type == 2) OR (_Type == 0.85)) then {_array = _a2;};
if ((_Type == 3) OR (_Type == 0.8)) then {_array = _a3;};
if ((_Type == 4) OR (_Type == 0.75)) then {_array = _a4;};
if ((_Type == 5) OR (_Type == 0.7)) then {_array = _a5;};
if ((_Type == 6) OR (_Type == 0.65)) then {_array = _a6;};
if ((_Type == 7) OR (_Type == 0.6)) then {_array = _a7;};
if ((_Type == 8) OR (_Type == 0.55)) then {_array = _a8;};
if ((_Type == 9) OR (_Type == 0.5)) then {_array = _a9;};
if (_Type == 10) then {_array = _a10;};
if (_Type == 11) then {_array = _a11;};
if (_Type == 12) then {_array = _a12;};
if ((_Type == 13) OR (_Type == 0.45)) then {_array = _a13;};
if ((_Type == 14) OR (_Type == 0.4)) then {_array = _a14;};
if ((_Type == 15) OR (_Type == 0.37)) then {_array = _a15;};
if ((_Type == 16) OR (_Type == 0.35)) then {_array = _a16;};
if ((_Type == 17) OR (_Type == 0.3)) then {_array = _a17;};

if ((_Type2 == 1) OR (_Type2 == 0.9)) then {_array = _array + _a1;};
if ((_Type2 == 2) OR (_Type2 == 0.85)) then {_array = _array + _a2;};
if ((_Type2 == 3) OR (_Type2 == 0.8)) then {_array = _array + _a3;};
if ((_Type2 == 4) OR (_Type2 == 0.75)) then {_array = _array + _a4;};
if ((_Type2 == 5) OR (_Type2 == 0.7)) then {_array = _array + _a5;};
if ((_Type2 == 6) OR (_Type2 == 0.65)) then {_array = _array + _a6;};
if ((_Type2 == 7) OR (_Type2 == 0.6)) then {_array = _array + _a7;};
if ((_Type2 == 8) OR (_Type2 == 0.55)) then {_array = _array + _a8;};
if ((_Type2 == 9) OR (_Type2 == 0.5)) then {_array = _array + _a9;};
if (_Type2 == 10) then {_array = _array + _a10;};
if (_Type2 == 11) then {_array = _array + _a11;};
if (_Type2 == 12) then {_array = _array + _a12;};
if ((_Type2 == 13) OR (_Type2 == 0.45)) then {_array = _array + _a13;};
if ((_Type2 == 14) OR (_Type2 == 0.4)) then {_array = _array + _a14;};
if ((_Type2 == 15) OR (_Type2 == 0.37)) then {_array = _array + _a15;};
if ((_Type2 == 16) OR (_Type2 == 0.35)) then {_array = _array + _a16;};
if ((_Type2 == 17) OR (_Type2 == 0.3)) then {_array = _array + _a17;};

if ((_Type3 == 1) OR (_Type3 == 0.9)) then {_array = _array + _a1;};
if ((_Type3 == 2) OR (_Type3 == 0.85)) then {_array = _array + _a2;};
if ((_Type3 == 3) OR (_Type3 == 0.8)) then {_array = _array + _a3;};
if ((_Type3 == 4) OR (_Type3 == 0.75)) then {_array = _array + _a4;};
if ((_Type3 == 5) OR (_Type3 == 0.7)) then {_array = _array + _a5;};
if ((_Type3 == 6) OR (_Type3 == 0.65)) then {_array = _array + _a6;};
if ((_Type3 == 7) OR (_Type3 == 0.6)) then {_array = _array + _a7;};
if ((_Type3 == 8) OR (_Type3 == 0.55)) then {_array = _array + _a8;};
if ((_Type3 == 9) OR (_Type3 == 0.5)) then {_array = _array + _a9;};
if (_Type3 == 10) then {_array = _array + _a10;};
if (_Type3 == 11) then {_array = _array + _a11;};
if (_Type3 == 12) then {_array = _array + _a12;};
if ((_Type3 == 13) OR (_Type3 == 0.45)) then {_array = _array + _a13;};
if ((_Type3 == 14) OR (_Type3 == 0.4)) then {_array = _array + _a14;};
if ((_Type3 == 15) OR (_Type3 == 0.37)) then {_array = _array + _a15;};
if ((_Type3 == 16) OR (_Type3 == 0.35)) then {_array = _array + _a16;};
if ((_Type3 == 17) OR (_Type3 == 0.3)) then {_array = _array + _a17;};

_array = _array + _Type4;

_Activation = _logic getVariable ["Activation",1];
if (_Activation == 1) then {_Activation = 0.9;};
if (_Activation == 2) then {_Activation = 0.7;};
if (_Activation == 3) then {_Activation = 0.5;};
if (_Activation == 4) then {_Activation = 0.3;};
if (_Activation == 5) then {_Activation = 0.1;};

_Activation2 = _logic getVariable ["Activation2",1];
if (_Activation2 == 1) then {_Activation2 = 0.9;};
if (_Activation2 == 2) then {_Activation2 = 0.7;};
if (_Activation2 == 3) then {_Activation2 = 0.5;};
if (_Activation2 == 4) then {_Activation2 = 0.3;};
if (_Activation2 == 5) then {_Activation2 = 0.1;};

_Activation3 = _logic getVariable ["Activation3",1];
if (_Activation3 == 1) then {_Activation3 = 0.9;};
if (_Activation3 == 2) then {_Activation3 = 0.7;};
if (_Activation3 == 3) then {_Activation3 = 0.5;};
if (_Activation3 == 4) then {_Activation3 = 0.3;};
if (_Activation3 == 5) then {_Activation3 = 0.1;};

_ActivationRadius = _logic getVariable ["ActivationRadius",100];
_CurrentAmount = 0;
_AliveAmount = _logic getVariable ["AliveAmount",50];
_TotalAmount = _logic getVariable ["TotalAmount",100];
_TotalAmount = _TotalAmount - 1;
_Start = _logic getVariable ["Start",5];
_Frequency = _logic getVariable ["Frequency",60];
_Delay = _logic getVariable ["Delay",0.5];
_Density = _logic getVariable ["Density",0];
_HordeSize = _logic getVariable ["HordeSize",14];
_Randomize = _logic getVariable ["Randomize",1];
if (_Randomize == 3) then {_TotalAmount = 0.5+(random _TotalAmount);};

sleep _Start;

for "_i" from 0 to 1 step 0 do {

if ((_Activation != 0.9) OR (_Activation2 != 0.9) OR (_Activation3 != 0.9)) then
{
	for "_a" from 0 to 1 step 0 do
	{
		_trg = createTrigger ["EmptyDetector", getposATL _logic];
		_trg2 = createTrigger ["EmptyDetector", getposATL _logic];
		_trg3 = createTrigger ["EmptyDetector", getposATL _logic];

		_trg setTriggerArea [_ActivationRadius, _ActivationRadius, 0, false];
		_trg2 setTriggerArea [_ActivationRadius, _ActivationRadius, 0, false];
		_trg3 setTriggerArea [_ActivationRadius, _ActivationRadius, 0, false];

		if (_Activation == 0.7) then {_trg setTriggerActivation ["WEST", "PRESENT", false]};
		if (_Activation2 == 0.7) then {_trg2 setTriggerActivation ["WEST", "PRESENT", false]};
		if (_Activation3 == 0.7) then {_trg3 setTriggerActivation ["WEST", "PRESENT", false]};

		if (_Activation == 0.5) then {_trg setTriggerActivation ["EAST", "PRESENT", false]};
		if (_Activation2 == 0.5) then {_trg2 setTriggerActivation ["EAST", "PRESENT", false]};
		if (_Activation3 == 0.5) then {_trg3 setTriggerActivation ["EAST", "PRESENT", false]};

		if (_Activation == 0.3) then {_trg setTriggerActivation ["GUER", "PRESENT", false]};
		if (_Activation2 == 0.3) then {_trg2 setTriggerActivation ["GUER", "PRESENT", false]};
		if (_Activation3 == 0.3) then {_trg3 setTriggerActivation ["GUER", "PRESENT", false]};

		if (_Activation == 0.1) then {_trg setTriggerActivation ["CIV", "PRESENT", false]};
		if (_Activation2 == 0.1) then {_trg2 setTriggerActivation ["CIV", "PRESENT", false]};
		if (_Activation3 == 0.1) then {_trg3 setTriggerActivation ["CIV", "PRESENT", false]};

		sleep 2;

		if ((triggeractivated _trg) OR (triggeractivated _trg2) OR (triggeractivated _trg3)) exitwith {deletevehicle _trg; deletevehicle _trg2; deletevehicle _trg3};

		deletevehicle _trg;
		deletevehicle _trg2;
		deletevehicle _trg3;
		sleep 2;
	};
};

if (_CurrentAmount > _TotalAmount) exitwith {};

_grp = creategroup _Team;
sleep 1;
if !(isnull _grp) then
{
	if (_Randomize == 2) then {_HordeSize = _logic getVariable ["HordeSize",14]; _Hordesize = 0.5+(random _Hordesize);};
	for "_x" from 1 to _HordeSize step 0 do
	{
		_x = _x + 1;
		_random = selectRandom _array;
		_AliveAmount2 = _AliveAmount + (_logic getvariable ["dead",0]);
		if (_CurrentAmount > _TotalAmount) exitwith {};
		sleep _Delay;
		if (_CurrentAmount < _AliveAmount2) then {format ["%1",_random] createunit [getposATL _logic, _grp, "if (isnil 'ryanzombiesstartinganim') then {this switchmove 'AmovPercMstpSnonWnonDnon_SaluteOut'}; if (isserver) then {this setposATL [(getposATL this select 0) + random _density - random _density, (getposATL this select 1) + random _density - random _density, (getPosATL this select 2)]; if (alive this) then {_CurrentAmount = _CurrentAmount + 1; this setvariable ['_logic',_logic]; this addEventHandler ['Killed', {_amountdead = ((_this select 0) getvariable ['_logic',objNull]) getvariable ['Dead',0]; ((_this select 0) getvariable ['_logic',objNull]) setvariable ['Dead',_amountdead + 1];}];};};"];};
	};
	sleep _Frequency;
};
};