_logic = _this select 0;

_Antivirus = _logic getVariable ["Antivirus",300];
ryanzombiesantivirusduration = _Antivirus;

if(hasInterface) then {
	player execVM "\ryanzombies\item_handler.sqf";
};

if ((!isServer) and hasInterface) exitwith {};

_InfectedChance = _logic getVariable ["InfectedChance",50];
_InfectedRate = _logic getVariable ["InfectedRate",0.1];

_InfectedSymptoms = _logic getVariable ["InfectedSymptoms",1];
if (_InfectedSymptoms == 1) then {_InfectedSymptoms = 0.9;};
if (_InfectedSymptoms == 2) then {_InfectedSymptoms = 0.7;};
if (_InfectedSymptoms == 3) then {_InfectedSymptoms = 0.5;};

_InfectedDeath = _logic getVariable ["InfectedDeath",1];
if (_InfectedDeath == 1) then {_InfectedDeath = 0.9;};
if (_InfectedDeath == 2) then {_InfectedDeath = 0.7;};

ryanzombiesinfectedchance = _InfectedChance;
ryanzombiesinfectedrate = _InfectedRate;
ryanzombiesinfectedsymptoms = _InfectedSymptoms;
ryanzombiesinfecteddeath = _InfectedDeath;

_Immunity = _logic getVariable ["Immunity",[]];
if (_Immunity isEqualTo "") then {_Immunity = []};
call compile format ["_Immunity = %1",_Immunity];

_count = count _Immunity;
_index = 0;

while {_count > _index} do
{
	_unit = (_Immunity select _index);
	call compile format ["_unit = %1",_unit];
	_unit setvariable ["ryanzombiesimmunity",true,true];
	_index = _index + 1;
};