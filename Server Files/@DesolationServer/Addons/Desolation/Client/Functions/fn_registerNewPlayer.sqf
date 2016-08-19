/*
	fn_onPlayerConnected
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_unit"];


_unit addEventHandler ["HitPart",{
	(_this select 0) call {
		params["_target","_shooter","_bullet","_position","_velocity","_selections","_ammo","_direction","_radius","_surface","_direct"];
		if(count(_selections) > 0) then {
			[_shooter,_selections select 0] remoteExecCall ["DS_fnc_onHitPartReceived",_target];
		};
	};
}];