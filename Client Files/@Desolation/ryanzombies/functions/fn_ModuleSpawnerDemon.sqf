_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

_Amount = _logic getVariable ["Amount",20];
_TotalAmount = _logic getVariable ["TotalAmount",40];
_Start = _logic getVariable ["Start",5];
_Frequency = _logic getVariable ["Frequency",60];
_Delay = _logic getVariable ["Delay",0.5];
_Density = _logic getVariable ["Density",0];
_ActivationDemon = _logic getVariable ["ActivationDemon",1];
if (_ActivationDemon == 1) then {_ActivationDemon = 0.9;};
if (_ActivationDemon == 2) then {_ActivationDemon = 0.7;};
if (_ActivationDemon == 3) then {_ActivationDemon = 0.5;};
if (_ActivationDemon == 4) then {_ActivationDemon = 0.3;};

_ActivationRadiusDemon = _logic getVariable ["ActivationRadiusDemon",100];
_HordeSize = _logic getVariable ["HordeSize",14];

ryanzombiesamountdemon = _Amount;
ryanzombiestotalamountdemon = _TotalAmount - 1;
ryanzombiesstartdemon = _Start;
ryanzombiesfrequencydemon = _Frequency;
ryanzombiesdelaydemon = _Delay;
ryanzombiesdensitydemon = _Density;
ryanzombiesactivationdemon = _ActivationDemon;
ryanzombiesactivationradiusdemon = _ActivationRadiusDemon;
ryanzombieshordesizedemon = _HordeSize;