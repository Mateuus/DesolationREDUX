/*
	Desolation Redux loot spawner
	by: @_Lystic

	Description: Handles loot spawning on buildings
*/

params["_building"];


_bLootPiles = (_building getVariable ["LOOT_PILES",[]]) - [objNull]; //--- get all remaining loot piles

_savedLoot = [];
// Layout: [ CONTAINER DATA , MAGAZINE DATA, WEAPON DATA, ITEM DATA], LOCATION
{
	//--- TEMPORARY
	_x enableSimulationGlobal false;
	_x hideObjectGlobal true;
	_savedLoot pushBack _x;
} forEach _bLootPiles;
