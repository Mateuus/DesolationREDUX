/*
	fn_initEventHandlers
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
/*
player addEventHandler ["InventoryOpened", {
	_this call DS_fnc_onInventoryOpened;
}];
 
player addEventHandler ["Killed", { Null = _this call DS_fnc_onPlayerKilled}];
player addEventHandler ["Fired", { }];
player addEventHandler ["FiredNear", { }];
player addEventHandler ["Explosion", { }];
player addEventHandler ["HandleDamage", { }];
player addEventHandler ["Put", { }];
player addEventHandler ["Take", { }];

player addEventHandler ["InventoryClosed", { }];
*/

player addEventHandler ["HandleDamage",{
	params["_unit","_selectionName","_damage","_shooter","_projectile","_hitPartIndex"];
	
	if(!isNull _shooter) then {
		DS_var_damagedBy pushBack _shooter;
	};
	false;
}];