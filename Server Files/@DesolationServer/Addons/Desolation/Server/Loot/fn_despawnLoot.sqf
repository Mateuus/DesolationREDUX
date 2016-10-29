/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params["_building"];
private["_bLootPiles","_getLoot","_savedLoot","_data"];

_bLootPiles = (_building getVariable ["LOOT_PILES",[]]) - [objNull]; //--- get all remaining loot piles

_getLoot = {
	params["_container"];
	private["_data","_iContainData","_insideContainers","_loot"];

	_data = [];

	//--- Recursively get all data from inside containers
	_iContainData = [];
	_insideContainers = everyContainer _container;
	{
		_loot = [_x select 1] call _getLoot;
		_iContainData pushBack [_x select 0,_loot];
	} forEach _insideContainers;
	_data pushBack _iContainData;

	//--- Get non-container data

	_data pushback (magazinesAmmoCargo _container);
	_data pushBack (itemCargo _container);
	_data pushback (weaponsItemsCargo _container);
	_data pushBack (backpackCargo _container);

	_data;
};


_savedLoot = [];
// Layout: LOCATION, [ CONTAINER DATA , MAGAZINE DATA, ITEM DATA, WEAPON DATA, BACKPACK DATA]
// CONTAINER DATA: [ [CONTAINER TYPE, CONTAINER LOOT] , ... ]
{
	//--- TEMPORARY
	_data = [getposatl _x,[_x] call _getLoot];
	_savedLoot pushBack _data;
	deleteVehicle _x;
} forEach _bLootPiles;

_building setVariable ["SavedLoot",_savedLoot];
