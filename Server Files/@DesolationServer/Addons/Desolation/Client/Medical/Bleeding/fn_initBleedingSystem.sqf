/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
DS_var_damagedBy = [];

/*
_unit setVariable ["DS_var_BleedSources",[],true];
_unit setVariable ["DS_var_BleedSourcesInfo",[],true];
*/
{
	_bsources = _x getVariable["BLEED_SOURCES",[]];
	
	_unit = _x;
	{
		_gSelect = _x select 0;
		_gLevel = _x select 1;
		_gOffset = _x select 2;
	
		[_unit,_gLevel,_gSelect,_gOffset] call DS_fnc_createBleedSource;
	} forEach _bsources;
	
} forEach allPlayers;