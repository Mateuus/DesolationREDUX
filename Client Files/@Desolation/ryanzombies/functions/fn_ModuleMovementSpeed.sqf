_logic = _this select 0;

_SlowZombies = _logic getVariable ["SlowZombies",1];
_MediumZombies = _logic getVariable ["MediumZombies",1];
_FastZombies = _logic getVariable ["FastZombies",1];
_DemonZombies = _logic getVariable ["DemonZombies",1];
_SpiderZombies = _logic getVariable ["SpiderZombies",1];
_CrawlerZombies = _logic getVariable ["CrawlerZombies",1];
_WalkerZombies = _logic getVariable ["WalkerZombies",1];
_PlayerZombies = _logic getVariable ["PlayerZombies",1];

if (_SlowZombies != 1) then {ryanzombiesmovementspeedslow = _SlowZombies;};
if (_MediumZombies != 1) then {ryanzombiesmovementspeedmedium = _MediumZombies;};
if (_FastZombies != 1) then {ryanzombiesmovementspeedfast = _FastZombies;};
if (_DemonZombies != 1) then {ryanzombiesmovementspeeddemon = _DemonZombies;};
if (_SpiderZombies != 1) then {ryanzombiesmovementspeedspider = _SpiderZombies;};
if (_CrawlerZombies != 1) then {ryanzombiesmovementspeedcrawler = _CrawlerZombies;};
if (_WalkerZombies != 1) then {ryanzombiesmovementspeedwalker = _WalkerZombies;};
if (_PlayerZombies != 1) then {ryanzombiesmovementspeedplayer = _PlayerZombies;};