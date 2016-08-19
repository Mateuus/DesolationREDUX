_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

_Amount = _logic getVariable ["Amount",50];
_TotalAmount = _logic getVariable ["TotalAmount",100];
_Start = _logic getVariable ["Start",5];
_Frequency = _logic getVariable ["Frequency",60];
_Delay = _logic getVariable ["Delay",0.5];
_Density = _logic getVariable ["Density",0];
_Activation = _logic getVariable ["Activation",1];
if (_Activation == 1) then {_Activation = 0.9;};
if (_Activation == 2) then {_Activation = 0.7;};
if (_Activation == 3) then {_Activation = 0.5;};
if (_Activation == 4) then {_Activation = 0.3;};

_ActivationRadius = _logic getVariable ["ActivationRadius",100];
_HordeSize = _logic getVariable ["HordeSize",14];

ryanzombiesamount = _Amount;
ryanzombiestotalamount = _TotalAmount - 1;
ryanzombiesstart = _Start;
ryanzombiesfrequency = _Frequency;
ryanzombiesdelay = _Delay;
ryanzombiesdensity = _Density;
ryanzombiesactivation = _Activation;
ryanzombiesactivationradius = _ActivationRadius;
ryanzombieshordesize = _HordeSize;