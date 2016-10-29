/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
private["_location","_x","_y","_height","_cItems"];

diag_log "AIRDROPS > Initialized";
while{true} do {
	_location = [0,0];
	while{true} do {
		_x = random(worldSize);
		_y = random(worldSize);
		_location = [_x,_y];
		_height = getTerrainHeightASL _location;
		if(_height > 5) exitWith {};
		uiSleep 0.001;
	};
	_cItems = call DS_fnc_genCrateItems;
	//uiSleep 2700;
	diag_log ("AIRDROPS > Dropping crate @ " + str(_location));
	diag_log ("AIRDROPS > Crate Loot: " + str(_cItems));
	[_location,_cItems] call DS_fnc_DoDrop;
	uiSleep 2700; // TODO (remove this line and uncomment the line above when tested)
};