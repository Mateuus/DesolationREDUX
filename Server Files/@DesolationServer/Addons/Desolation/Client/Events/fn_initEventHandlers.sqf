/*
	fn_initEventHandlers
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

player addEventHandler ["HandleDamage",{
	params["_unit","_selectionName","_damage","_shooter","_projectile","_hitPartIndex"];
	
	if(!isNull _shooter) then {
		DS_var_damagedBy pushBack _shooter;
	};
	false;
}];