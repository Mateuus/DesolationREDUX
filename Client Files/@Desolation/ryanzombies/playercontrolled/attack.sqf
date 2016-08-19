_zombie = player;

if((time - (_zombie getVariable ["ryanlastzombieattack",0])) > Ryanzombiesattackspeedplayer) then 
{
	if(stance _zombie == "PRONE" || stance _zombie == "UNDEFINED") exitWith{};

	_targets = nearestobjects [_zombie, ["Man","Land","Air"], 10];   
	_target = objNull;
	if(count _targets >= 2) then 
	{
		_targets deleteAt 0;
		{
			if((alive _x) || !(_x iskindof "man")) exitWith { _target = _x };
		} foreach _targets;
	};
	
	_AttackArray = ["ryanzombies\sounds\attack1.ogg", "ryanzombies\sounds\attack2.ogg", "ryanzombies\sounds\attack3.ogg", "ryanzombies\sounds\attack4.ogg", "ryanzombies\sounds\attack5.ogg"];
	if(stance _zombie == "STAND") then
	{
		[_zombie, "AwopPercMstpSgthWnonDnon_throw"] remoteExecCall ["fnc_RyanZombies_PlayMoveNow"];
	};
	if(stance _zombie == "CROUCH") then {

		[_zombie, "AinvPknlMstpSnonWnonDnon_2"] remoteExecCall ["fnc_RyanZombies_PlayMoveNow"];
	};
	_Attack = _AttackArray select floor random count _AttackArray;
	playsound3d [format ["%1",_Attack], _zombie];

	_zombie setVariable ["ryanlastzombieattack",time];
	if(isNull _target) exitWith {};	

	_rDir = _zombie getRelDir (vehicle _target);
	if((_rDir > 0 && _rDir < 40) || (_rDir > 320 && _rDir < 360)) then
	{
		[_target,_zombie] spawn 
		{
			_target = _this select 0;
			_zombie = _this select 1;
			
			_ScreamArray = ["ryanzombiesscream1", "ryanzombiesscream2", "ryanzombiesscream3", "ryanzombiesscream4", "ryanzombiesscream5", "ryanzombiesscream6", "ryanzombiesscream7", "ryanzombiesscream8", "ryanzombiesscream9"];
			_VehicleHitArray = ["ryanzombies\sounds\vehicle_hit1.ogg", "ryanzombies\sounds\vehicle_hit2.ogg", "ryanzombies\sounds\vehicle_hit3.ogg", "ryanzombies\sounds\vehicle_hit4.ogg"];
			
			
			if (vehicle _target iskindof "man") then
			{
				if(_zombie distance _target < Ryanzombiesattackdistanceplayer) then
				{
					_target allowfleeing 1;
					sleep 0.3;
					if (_zombie distance _target < Ryanzombiesattackdistanceplayer && (alive _target) && (alive _zombie)) then
					{
						playsound3d ["ryanzombies\sounds\zombie_bite.ogg", _target];

						[_target, 10] remoteExecCall ["fnc_RyanZombies_Bleeding"];

						[_target,group _zombie] remoteExecCall ["RZ_ServerSided_AttackScriptsInfantry",2];
						
						_Scream = _ScreamArray select floor random count _ScreamArray;
						[_target, format ["%1",_Scream]] remoteExecCall ["say3d"];

						_vel = velocity _target;
						_dir = direction _zombie;
						[_target, [(_vel select 0) + (sin _dir * Ryanzombiesattackstrenthplayer), (_vel select 1) + (cos _dir * Ryanzombiesattackstrenthplayer), (_vel select 2) + random 1]] remoteExecCall ["fnc_RyanZombies_Velocity",_target];
					};
				};
				
			} else {
				if ((vehicle _target iskindof "car") && _zombie distance _target < 7) then
				{
					_target allowfleeing 1;
					sleep 0.3;
					if (_zombie distance _target < 7 && (alive _zombie)) then
					{
						_count = count (getAllHitPointsDamage _target select 0);
						_index = 0;
						_damage = random Ryanzombiesdamagecarplayer;

						while {_count > _index} do
						{
							if ((getAllHitPointsDamage _target select 0) select _index != "HitFuel") then {[_target, [_index,(_target getHitIndex _index)+_damage]] remoteExecCall ["fnc_RyanZombies_SetHitIndex",_target]};
							_index = _index + 1;
						};

						if ((getnumber (configfile >> "CfgVehicles" >> typeof _target >> "armor")) < 90) then 
						{
							if !(canmove _target) then 
							{
								{
									if (random 10 < 1) then 
									{
										_Scream = _ScreamArray select floor random count _ScreamArray; 
										[_x, format ["%1",_Scream]] remoteExecCall ["say3d"]
									}
								} foreach crew _target; 
								[crew _target,group _zombie] remoteExecCall ["RZ_ServerSided_AttackScriptsVehicle",2];
							};
						};

						_VehicleHit = _VehicleHitArray select floor random count _VehicleHitArray;
						playsound3d [format ["%1",_VehicleHit], _target];

						_vel = velocity _target;
						_dir = direction _zombie;
						[_target, [(_vel select 0) + (sin _dir * Ryanzombiesdamagecarstrenthplayer), (_vel select 1) + (cos _dir * Ryanzombiesdamagecarstrenthplayer), (_vel select 2) + random 1]] remoteExecCall ["fnc_RyanZombies_Velocity",_target];
					};
				};

				
				if ((vehicle _target iskindof "tank") && _zombie distance _target < 8) then
				{
					_target allowfleeing 1;
					sleep 0.3;
					if (_zombie distance _target < 8 && (alive _zombie)) then
					{
						_count = count (getAllHitPointsDamage _target select 0);
						_index = 0;
						_damage = random Ryanzombiesdamagetankplayer;

						while {_count > _index} do
						{
							if ((getAllHitPointsDamage _target select 0) select _index != "HitHull") then {[_target, [_index,(_target getHitIndex _index)+_damage]] remoteExecCall ["fnc_RyanZombies_SetHitIndex",_target]};
							_index = _index + 1;
						};

						_VehicleHit = _VehicleHitArray select floor random count _VehicleHitArray;
						playsound3d [format ["%1",_VehicleHit], _target];

						_vel = velocity _target;
						_dir = direction _zombie;
						[_target, [(_vel select 0) + (sin _dir * Ryanzombiesdamagetankstrenthplayer), (_vel select 1) + (cos _dir * Ryanzombiesdamagetankstrenthplayer), (_vel select 2) + random 1]] remoteExecCall ["fnc_RyanZombies_Velocity",_target];
					};
				};

				
				if ((vehicle _target iskindof "air") && _zombie distance _target < 10) then
				{
					sleep 0.3;
					if (_zombie distance _target < 10 && (alive _zombie)) then
					{
						vehicle _target setdamage (damage (vehicle _target) + Ryanzombiesdamageairplayer);

						_VehicleHit = _VehicleHitArray select floor random count _VehicleHitArray;
						playsound3d [format ["%1",_VehicleHit], _target];

						_vel = velocity _target;
						_dir = direction _zombie;
						[_target, [(_vel select 0) + (sin _dir * Ryanzombiesdamageairstrenthplayer), (_vel select 1) + (cos _dir * Ryanzombiesdamageairstrenthplayer), (_vel select 2) + random 1]] remoteExecCall ["fnc_RyanZombies_Velocity",_target];
					};
				};

				
				if ((vehicle _target iskindof "staticweapon" OR vehicle _target iskindof "ship") && _zombie distance _target < 4.5) then
				{
					sleep 0.3;
					if (_zombie distance _target < 4.5 && (alive _zombie)) then
					{
						[_target,group _zombie] remoteExecCall ["RZ_ServerSided_AttackScriptsInfantry",2];

						playsound3d ["ryanzombies\sounds\zombie_bite.ogg", _target];

						_vel = velocity _target;
						_dir = direction _zombie;
						[_target, [(_vel select 0) + (sin _dir * Ryanzombiesattackstrenthplayer), (_vel select 1) + (cos _dir * Ryanzombiesattackstrenthplayer), (_vel select 2) + random 1]] remoteExecCall ["fnc_RyanZombies_Velocity",_target];
					};
				};		
			};
		};
	};	
};