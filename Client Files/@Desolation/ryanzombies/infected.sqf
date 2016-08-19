_target = _this select 0;
_side = _this select 1;

if ((!isServer) and hasInterface) exitwith {};

if (random 100 <= ryanzombiesinfectedchance) then
{
	_target setVariable ["ryanzombiesinfected",0.01,true];
	if ((isPlayer _target) && (ryanzombiesinfectedsymptoms != 0.5)) then 
	{
		[_target,"\ryanzombies\infected_player.sqf"] remoteExecCall ["fnc_RyanZombies_execVM",_target];
	};

	_x = random 10;
	sleep _x;

	_array = ["ryanzombiescough1", "ryanzombiescough2", "ryanzombiescough3", "ryanzombiescough4", "ryanzombiescough5", "ryanzombiescough6", "ryanzombiescough7", "ryanzombiescough8", "ryanzombiescough9", "ryanzombiescough10", "ryanzombiescough11", "ryanzombiescough12", "ryanzombiescough13", "ryanzombiescough14"];
	_deatharray = ["ryanzombies\sounds\infected_death1.ogg", "ryanzombies\sounds\infected_death2.ogg"];
	_sound = 1;

	_damage1 = ryanzombiesinfectedrate/60;
	_damage2 = ryanzombiesinfectedrate/30;
	_damage3 = ryanzombiesinfectedrate/20;
	_damage4 = ryanzombiesinfectedrate/10;

	while {(alive _target) && (_target getvariable ["ryanzombiesinfected",0] > 0)} do
	{
		if !(_target getvariable ["ryanzombiesimmunity",false]) then
		{
			if (ryanzombiesinfectedsymptoms != 0.5) then
			{
				if (_sound < 1) then
				{
					_random = _array select floor random count _array;
					[_target, format ["%1",_random]] remoteExecCall ["say3D"];
					if (isPlayer _target) then {[[[1.5, 2, 10],_target] remoteExecCall ["fnc_RyanZombies_AddCamShake"]];};
				};
				if (ryanzombiesinfectedsymptoms == 0.9) then {_sound = _sound + 1} else {_sound = _sound + 0.5};
				if (_sound > 4) then {_sound = 0};
			};
			if ((_target getvariable ["ryanzombiesinfected",0]) >= 1) exitwith
			{
				_target setspeaker "NoVoice";
				if (ryanzombiesinfecteddeath == 0.9) then {_deathrandom = _deatharray select floor random count _deatharray; playsound3d [format ["%1",_deathrandom], _target];};
				sleep 0.9;
				_target playaction "gear";
				sleep 0.6;
				_target setdamage 1;
				if !(isnil "Ryanzombiesinfection") then {[_target, _side] execVM "\ryanzombies\infection.sqf"};
				sleep 5;
			};
			if (isnil "ryanzombiesdisablebleeding") then {[_target,1] remoteExecCall ["fnc_RyanZombies_Bleeding"];};
			if ((_target getvariable ["ryanzombiesinfected",0]) > 0.9) exitwith
			{
				_target setVariable ["ryanzombiesinfected",(_target getvariable ["ryanzombiesinfected",0]) + _damage1,true];
				sleep 1;
			};
			if ((_target getvariable ["ryanzombiesinfected",0]) > 0.6) exitwith
			{
				_target setVariable ["ryanzombiesinfected",(_target getvariable ["ryanzombiesinfected",0]) + _damage2,true];
				sleep 2;
			};
			if ((_target getvariable ["ryanzombiesinfected",0]) > 0.3) exitwith
			{
				_target setVariable ["ryanzombiesinfected",(_target getvariable ["ryanzombiesinfected",0]) + _damage3,true];
				sleep 3;
			};
			_target setVariable ["ryanzombiesinfected",(_target getvariable ["ryanzombiesinfected",0]) + _damage4,true];
			sleep 6;
		} else {sleep 4;};
	};
	_target setVariable ["ryanzombiesinfected",0,true];
	_target setVariable ["ryanzombiesimmunity",false,true];
};