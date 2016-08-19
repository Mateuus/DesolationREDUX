_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

_Infection = _logic getVariable ["Infection",1];
if (_Infection == 1) then {_Infection = 0.9;};
if (_Infection == 2) then {_Infection = 0.7;};
if (_Infection == 3) then {_Infection = 0.5;};
if (_Infection == 4) then {_Infection = 0.4;};
if (_Infection == 5) then {_Infection = 0.3;};
if (_Infection == 6) then {_Infection = 0.1;};
if (_Infection == 7) then {_Infection = 0.05;};

_InfectionTimer = _logic getVariable ["InfectionTimer",30];

_Uniform = _logic getVariable ["Uniform",1];
if (_Uniform == 1) then {_Uniform = 0.9;};
if (_Uniform == 2) then {_Uniform = 0.7;};

ryanzombiesinfection = _Infection;
ryanzombiesinfectiontimer = _InfectionTimer;
ryanzombiesuniform = _Uniform;