_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

_ZombieMaxHealth = _logic getVariable ["ZombieMaxHealth",1];
_DemonMaxHealth = _logic getVariable ["DemonMaxHealth",1];

if (_ZombieMaxHealth == 1) then {_ZombieMaxHealth = 0.7;};
if (_ZombieMaxHealth == 2) then {_ZombieMaxHealth = 0.5;};
if (_ZombieMaxHealth == 3) then {_ZombieMaxHealth = 0.9;};
if (_ZombieMaxHealth == 4) then {_ZombieMaxHealth = 0.97;};

if (_DemonMaxHealth == 1) then {_DemonMaxHealth = 0.7;};
if (_DemonMaxHealth == 2) then {_DemonMaxHealth = 0.5;};
if (_DemonMaxHealth == 3) then {_DemonMaxHealth = 0.9;};
if (_DemonMaxHealth == 4) then {_DemonMaxHealth = 0.97;};

ryanzombieshealth = _ZombieMaxHealth;
ryanzombieshealthdemon = _DemonMaxHealth;