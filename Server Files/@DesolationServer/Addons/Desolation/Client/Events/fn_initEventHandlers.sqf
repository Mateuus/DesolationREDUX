/*
	fn_initEventHandlers
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

player addEventHandler ["HandleDamage",{
	params["_unit","_selectionName","_damage","_shooter","_projectile","_hitPartIndex"];
	
	if(!isNull _shooter) then {
		if(toLower(_projectile) find "b_" == 0) then {
			DS_var_damagedBy pushBack _shooter;
		};
	};
}];
player addEventHandler ["InventoryOpened",{
	DS_var_InvOpen = true;
	[] spawn ds_fnc_setupInvEvents;
	false
}];
player addEventHandler ["InventoryClosed",{
	DS_var_InvOpen = false;
	false
}];
