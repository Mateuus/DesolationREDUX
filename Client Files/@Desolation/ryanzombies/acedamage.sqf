_target = _this select 0;
_typeDamage = _this select 1;

_damage = 0;

switch _typeDamage do 
{	
	case 'manNormal': { _damage = Ryanzombiesdamage; };
	case 'vehNormal': { _damage = Ryanzombiesdamage/25; };
	case 'manDemon': { _damage = 0.3; };
	case 'vehDemon': { _damage = 0.03; };
};	

_selection = selectRandom ace_medical_selections;
_hitpart = _selection;

switch _selection do
{
	case "hand_l";
	case "hand_r": { _hitpart = "hands"; };
	case "leg_l";
	case "leg_r": { _hitpart = "legs"; };
};

if(isPlayer _target) then 
{
	[-2,{
		_target = _this select 0;
		_damage = _this select 1;
		_selection = _this select 2;
		_hitpart = _this select 3;
		if(player == _target) then 
		{
			[_target, _selection, (_target gethit _hitpart) + _damage, objNull, "Bullet",-1] call ace_medical_fnc_handleDamage;
			[_target, _selection, (_target gethit _hitpart) + _damage, objNull, "Bullet",-1] call ace_medical_fnc_handleDamage;
			[_target, _selection, (_target gethit _hitpart) + _damage, objNull, "Bullet",-1] call ace_medical_fnc_handleDamage;
		};
	},[_target,_damage,_selection,_hitpart]] call CBA_fnc_globalExecute;
	 
} else { // note that this damage won't be applied to AI group members of a player-led team on a server (because AIs are local to group leader) - low priority...
	[_target, _selection, (_target gethit _hitpart) + _damage, objNull, "Bullet",-1] call ace_medical_fnc_handleDamage;
	[_target, _selection, (_target gethit _hitpart) + _damage, objNull, "Bullet",-1] call ace_medical_fnc_handleDamage;
	[_target, _selection, (_target gethit _hitpart) + _damage, objNull, "Bullet",-1] call ace_medical_fnc_handleDamage;
};