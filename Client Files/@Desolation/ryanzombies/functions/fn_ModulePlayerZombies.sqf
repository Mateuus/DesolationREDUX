_logic = _this select 0;

_Jumping = _logic getVariable ["Jumping",1];
if (_Jumping != 1) then {Ryanzombiesjumpplayer = 1;};
if (_Jumping == 3) then {Ryanzombiesjumpstrengthplayer = 1;};
if (_Jumping == 4) then {Ryanzombiesjumpstrengthplayer = 2;};
if (_Jumping == 5) then {Ryanzombiesjumpstrengthplayer = 3;};
if (_Jumping == 6) then {Ryanzombiesjumpstrengthplayer = 4;};

_AttackSpeed = _logic getVariable ["AttackSpeed",0.8];
_AttackDistance = _logic getVariable ["AttackDistance",2.35];
_Damage = _logic getVariable ["Damage",0.15];
_DamageCar = _logic getVariable ["DamageCar",0.02];
_DamageAir = _logic getVariable ["DamageAir",0.01];
_DamageTank = _logic getVariable ["DamageTank",0.002];
_Knockback = _logic getVariable ["Knockback",1.5];
_KnockbackCar = _logic getVariable ["KnockbackCar",1.5];
_KnockbackAir = _logic getVariable ["KnockbackAir",1];
_KnockbackTank = _logic getVariable ["KnockbackTank",0.4];

Ryanzombiesattackspeedplayer = _AttackSpeed;
Ryanzombiesattackdistanceplayer = _AttackDistance;
Ryanzombiesdamageplayer = _Damage;
Ryanzombiesdamagecarplayer = _DamageCar;
Ryanzombiesdamageairplayer = _DamageAir;
Ryanzombiesdamagetankplayer = _DamageTank;
Ryanzombiesattackstrenthplayer = _Knockback;
Ryanzombiesdamagecarstrenthplayer = _KnockbackCar;
Ryanzombiesdamageairstrenthplayer = _KnockbackAir;
Ryanzombiesdamagetankstrenthplayer = _KnockbackTank;