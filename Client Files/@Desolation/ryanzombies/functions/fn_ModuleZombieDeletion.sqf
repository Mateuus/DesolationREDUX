_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

_Deletion = _logic getVariable ["Deletion",1];
if (_Deletion == 1) then {_Deletion = 0.9;};
if (_Deletion == 2) then {_Deletion = 0.7;};
if (_Deletion == 3) then {_Deletion = 0.5;};
if (_Deletion == 4) then {_Deletion = 0.3;};
if (_Deletion == 5) then {_Deletion = 0.1;};

_Deletion2 = _logic getVariable ["Deletion2",1];
if (_Deletion2 == 1) then {_Deletion2 = 0.9;};
if (_Deletion2 == 2) then {_Deletion2 = 0.7;};
if (_Deletion2 == 3) then {_Deletion2 = 0.5;};
if (_Deletion2 == 4) then {_Deletion2 = 0.3;};
if (_Deletion2 == 5) then {_Deletion2 = 0.1;};

_DeletionRadius = _logic getVariable ["DeletionRadius",1000];

_DeletionDemons = _logic getVariable ["DeletionDemons",1];
if (_DeletionDemons == 1) then {_DeletionDemons = 0.9;};
if (_DeletionDemons == 2) then {_DeletionDemons = 0.7;};
if (_DeletionDemons == 3) then {_DeletionDemons = 0.5;};
if (_DeletionDemons == 4) then {_DeletionDemons = 0.3;};
if (_DeletionDemons == 5) then {_DeletionDemons = 0.1;};

_DeletionDemons2 = _logic getVariable ["DeletionDemons2",1];
if (_DeletionDemons2 == 1) then {_DeletionDemons2 = 0.9;};
if (_DeletionDemons2 == 2) then {_DeletionDemons2 = 0.7;};
if (_DeletionDemons2 == 3) then {_DeletionDemons2 = 0.5;};
if (_DeletionDemons2 == 4) then {_DeletionDemons2 = 0.3;};
if (_DeletionDemons2 == 5) then {_DeletionDemons2 = 0.1;};

_DeletionRadiusDemons = _logic getVariable ["DeletionRadiusDemons",1000];

ryanzombiesdeletion = _Deletion;
ryanzombiesdeletion2 = _Deletion2;
ryanzombiesdeletionradius = _DeletionRadius;

ryanzombiesdeletiondemons = _DeletionDemons;
ryanzombiesdeletiondemons2 = _DeletionDemons2;
ryanzombiesdeletionradiusdemons = _DeletionRadiusDemons;