/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
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
	uiSleep 2700;
	diag_log ("AIRDROPS > Dropping crate @ " + str(_location));
	diag_log ("AIRDROPS > Crate Loot: " + str(_cItems));
	[_location,_cItems] call DS_fnc_DoDrop;
};