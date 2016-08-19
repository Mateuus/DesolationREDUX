_logic = _this select 0;

_Roaming = _logic getVariable ["Roaming",1];
if ((_Roaming == 2) OR (_Roaming == 3)) then {Ryanzombieslogicroam = 1;};
if ((_Roaming == 2) OR (_Roaming == 4)) then {Ryanzombieslogicroamdemon = 1;};

_Feeding = _logic getVariable ["Feeding",1];
if ((_Feeding == 2) OR (_Feeding == 3)) then {Ryanzombiesfeed = 1;};
if ((_Feeding == 2) OR (_Feeding == 4)) then {Ryanzombiesfeeddemon = 1;};

_Jumping = _logic getVariable ["Jumping",1];
if (_Jumping != 1) then {Ryanzombiesjump = 1;};
if (_Jumping == 3) then {Ryanzombiesjumpstrength = 1;};
if (_Jumping == 4) then {Ryanzombiesjumpstrength = 2;};
if (_Jumping == 5) then {Ryanzombiesjumpstrength = 3;};

_JumpingDemons = _logic getVariable ["JumpingDemons",1];
if (_JumpingDemons != 1) then {Ryanzombiesjumpdemon = 1;};
if (_JumpingDemons == 3) then {Ryanzombiesjumpdemonstrength = 1;};
if (_JumpingDemons == 4) then {Ryanzombiesjumpdemonstrength = 2;};
if (_JumpingDemons == 5) then {Ryanzombiesjumpdemonstrength = 3;};

_Throwing = _logic getVariable ["Throwing",1];
if (_Throwing != 1) then {Ryanzombiescanthrow = 1;};
if (_Throwing == 3) then {Ryanzombiescanthrowstrength = 1;};
if (_Throwing == 4) then {Ryanzombiescanthrowstrength = 2;};
if (_Throwing == 5) then {Ryanzombiescanthrowstrength = 3;};
if (_Throwing == 6) then {Ryanzombiescanthrowstrength = 4;};

_ThrowingDemons = _logic getVariable ["ThrowingDemons",1];
if (_ThrowingDemons != 1) then {Ryanzombiescanthrowdemon = 1;};
if (_ThrowingDemons == 3) then {Ryanzombiescanthrowdemonstrength = 1;};
if (_ThrowingDemons == 4) then {Ryanzombiescanthrowdemonstrength = 2;};
if (_ThrowingDemons == 5) then {Ryanzombiescanthrowdemonstrength = 3;};
if (_ThrowingDemons == 6) then {Ryanzombiescanthrowdemonstrength = 4;};

_ThrowingDistance = _logic getVariable ["ThrowingDistance",500];
Ryanzombiescanthrowdistance = _ThrowingDistance;

_ThrowingDistanceDemons = _logic getVariable ["ThrowingDistanceDemons",1000];
Ryanzombiescanthrowdistancedemon = _ThrowingDistanceDemons;

_ThrowingTank = _logic getVariable ["ThrowingTank",1];
if (_ThrowingTank != 1) then {Ryanzombiescanthrowtank = 1;};
if (_ThrowingTank == 3) then {Ryanzombiescanthrowtankstrength = 1;};
if (_ThrowingTank == 4) then {Ryanzombiescanthrowtankstrength = 2;};
if (_ThrowingTank == 5) then {Ryanzombiescanthrowtankstrength = 3;};
if (_ThrowingTank == 6) then {Ryanzombiescanthrowtankstrength = 4;};

_ThrowingTankDemons = _logic getVariable ["ThrowingTankDemons",1];
if (_ThrowingTankDemons != 1) then {Ryanzombiescanthrowtankdemon = 1;};
if (_ThrowingTankDemons == 3) then {Ryanzombiescanthrowtankdemonstrength = 1;};
if (_ThrowingTankDemons == 4) then {Ryanzombiescanthrowtankdemonstrength = 2;};
if (_ThrowingTankDemons == 5) then {Ryanzombiescanthrowtankdemonstrength = 3;};
if (_ThrowingTankDemons == 6) then {Ryanzombiescanthrowtankdemonstrength = 4;};

_ThrowingTankDistance = _logic getVariable ["ThrowingTankDistance",50];
Ryanzombiescanthrowtankdistance = _ThrowingTankDistance;

_ThrowingTankDistanceDemons = _logic getVariable ["ThrowingTankDistanceDemons",100];
Ryanzombiescanthrowtankdistancedemon = _ThrowingTankDistanceDemons;