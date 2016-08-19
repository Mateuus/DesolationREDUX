_logic = _this select 0;

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

Ryanzombiesattackspeed = _AttackSpeed;
Ryanzombiesattackdistance = _AttackDistance;
Ryanzombiesdamage = _Damage;
Ryanzombiesdamagecar = _DamageCar;
Ryanzombiesdamageair = _DamageAir;
Ryanzombiesdamagetank = _DamageTank;
Ryanzombiesattackstrenth = _Knockback;
Ryanzombiesdamagecarstrenth = _KnockbackCar;
Ryanzombiesdamageairstrenth = _KnockbackAir;
Ryanzombiesdamagetankstrenth = _KnockbackTank;