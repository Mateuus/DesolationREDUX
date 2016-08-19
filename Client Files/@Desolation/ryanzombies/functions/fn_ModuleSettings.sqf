_logic = _this select 0;

_CivilianAttacks = _logic getVariable ["CivilianAttacks",1];
if (_CivilianAttacks == 2) then {ryanzombiescivilianattacks = 1;};

_DeleteBodies = _logic getVariable ["DeleteBodies",1];
if (_DeleteBodies == 2) then {ryanzombiesdelete = 1;};

_DetectionDistance = _logic getVariable ["DetectionDistance",10000];
ryanzombieslimit = _DetectionDistance;

_ExplodingHeads = _logic getVariable ["ExplodingHeads",1];
if (_ExplodingHeads == 2) then {Ryanzombiesdamagecaliberneeded = 1.6;};
if (_ExplodingHeads == 3) then {Ryanzombiesdamagecaliberneeded = 0.9;};
if (_ExplodingHeads == 4) then {Ryanzombiesdamagecaliberneeded = 0.1;};
if (_ExplodingHeads == 5) then {Ryanzombiesdisableexplodingheads = 1;};

_GlowingEyes = _logic getVariable ["GlowingEyes",1];
if ((_GlowingEyes == 3) OR (_GlowingEyes == 4)) then {ryanzombiesglowdemondisable = 1;};
if ((_GlowingEyes == 2) OR (_GlowingEyes == 3)) then {ryanzombiesglow = 1;};

_Bleeding = _logic getVariable ["Bleeding",1];
if (_Bleeding == 2) then {ryanzombiesdisablebleeding = 1;};

_Invincibility = _logic getVariable ["Invincibility",1];
if ((_Invincibility == 2) OR (_Invincibility == 3)) then {Ryanzombiesinvincible = 1;};
if ((_Invincibility == 2) OR (_Invincibility == 4)) then {Ryanzombiesinvincibledemon = 1;};

_Sounds = _logic getVariable ["Sounds",1];
if ((_Sounds == 2) OR (_Sounds == 4)) then {ryanzombiesdisablemoaning = 1;};
if ((_Sounds == 3) OR (_Sounds == 4)) then {ryanzombiesdisableaggressive = 1;};

_JumpingSounds = _logic getVariable ["JumpingSounds",1];
if (_JumpingSounds == 2) then {ryanzombiesdisablejumping = 1;};

_StartingAnim = _logic getVariable ["StartingAnim",1];
if (_StartingAnim == 2) then {ryanzombiesstartinganim = 1;};

_ZombieScript = _logic getVariable ["ZombieScript",1];
if (_ZombieScript == 2) then {ryanzombiesdisablescript = 1;};