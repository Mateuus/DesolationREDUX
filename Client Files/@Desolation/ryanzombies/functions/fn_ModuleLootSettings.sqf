_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

ryanzombiesAllLoot = 1;

_Items = _logic getVariable ["Items",[]];
if (_Items isEqualTo "") then {_Items = []};
call compile format ["_Items = %1",_Items];

_Itemschance = _logic getVariable ["Itemschance",25];
_Itemsamountmin = _logic getVariable ["Itemsamountmin",1];
_Itemsamountmax = _logic getVariable ["Itemsamountmax",1];

_Magazines = _logic getVariable ["Magazines",[]];
if (_Magazines isEqualTo "") then {_Magazines = []};
call compile format ["_Magazines = %1",_Magazines];

_Magazineschance = _logic getVariable ["Magazineschance",25];
_Magazinesamountmin = _logic getVariable ["Magazinesamountmin",1];
_Magazinesamountmax = _logic getVariable ["Magazinesamountmax",1];

_Weapons = _logic getVariable ["Weapons",[]];
if (_Weapons isEqualTo "") then {_Weapons = []};
call compile format ["_Weapons = %1",_Weapons];

_Weaponschance = _logic getVariable ["Weaponschance",5];
_Weaponsamountmin = _logic getVariable ["Weaponsamountmin",1];
_Weaponsamountmax = _logic getVariable ["Weaponsamountmax",1];

ryanzombiesitems = _Items;
ryanzombiesitemschance = _Itemschance;
ryanzombiesitemsmin = _Itemsamountmin;
ryanzombiesitemsmax = _Itemsamountmax;

ryanzombiesmagazines = _Magazines;
ryanzombiesmagazineschance = _Magazineschance;
ryanzombiesmagazinesmin = _Magazinesamountmin;
ryanzombiesmagazinesmax = _Magazinesamountmax;

ryanzombiesweapons = _Weapons;
ryanzombiesweaponschance = _Weaponschance;
ryanzombiesweaponsmin = _Weaponsamountmin;
ryanzombiesweaponsmax = _Weaponsamountmax;



_ItemsSoldier = _logic getVariable ["ItemsSoldier",[]];
if (_ItemsSoldier isEqualTo "") then {_ItemsSoldier = []};
call compile format ["_ItemsSoldier = %1",_ItemsSoldier];

_ItemschanceSoldier = _logic getVariable ["ItemschanceSoldier",25];
_ItemsamountminSoldier = _logic getVariable ["ItemsamountminSoldier",1];
_ItemsamountmaxSoldier = _logic getVariable ["ItemsamountmaxSoldier",1];

_MagazinesSoldier = _logic getVariable ["MagazinesSoldier",[]];
if (_MagazinesSoldier isEqualTo "") then {_MagazinesSoldier = []};
call compile format ["_MagazinesSoldier = %1",_MagazinesSoldier];

_MagazineschanceSoldier = _logic getVariable ["MagazineschanceSoldier",25];
_MagazinesamountminSoldier = _logic getVariable ["MagazinesamountminSoldier",1];
_MagazinesamountmaxSoldier = _logic getVariable ["MagazinesamountmaxSoldier",1];

_WeaponsSoldier = _logic getVariable ["WeaponsSoldier",[]];
if (_WeaponsSoldier isEqualTo "") then {_WeaponsSoldier = []};
call compile format ["_WeaponsSoldier = %1",_WeaponsSoldier];

_WeaponschanceSoldier = _logic getVariable ["WeaponschanceSoldier",5];
_WeaponsamountminSoldier = _logic getVariable ["WeaponsamountminSoldier",1];
_WeaponsamountmaxSoldier = _logic getVariable ["WeaponsamountmaxSoldier",1];

ryanzombiesitemsSoldier = _ItemsSoldier;
ryanzombiesitemschanceSoldier = _ItemschanceSoldier;
ryanzombiesitemsminSoldier = _ItemsamountminSoldier;
ryanzombiesitemsmaxSoldier = _ItemsamountmaxSoldier;

ryanzombiesmagazinesSoldier = _MagazinesSoldier;
ryanzombiesmagazineschanceSoldier = _MagazineschanceSoldier;
ryanzombiesmagazinesminSoldier = _MagazinesamountminSoldier;
ryanzombiesmagazinesmaxSoldier = _MagazinesamountmaxSoldier;

ryanzombiesweaponsSoldier = _WeaponsSoldier;
ryanzombiesweaponschanceSoldier = _WeaponschanceSoldier;
ryanzombiesweaponsminSoldier = _WeaponsamountminSoldier;
ryanzombiesweaponsmaxSoldier = _WeaponsamountmaxSoldier;