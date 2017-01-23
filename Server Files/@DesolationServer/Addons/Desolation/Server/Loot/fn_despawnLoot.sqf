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
_building setVariable ["LOOT_PILES",[]];
