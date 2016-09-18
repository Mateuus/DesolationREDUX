/*
	Desolation Redux loot spawner
	by: @_Lystic

	Description: Handles loot spawning on buildings
*/

params["_building","_MinPiles","_buildingTypes","_Config_Options","_savedLoot"];

_building_type = typeof(_building);

_positions = getArray(configFile >> "CfgItemSpawns" >> "Buildings" >> _building_type >> "positions");
_building_table = getText(configFile >> "CfgItemSpawns" >> "Buildings" >> _building_type >> "table");

_loot_rarity = getArray(configFile >> "CfgItemSpawns" >> "lootRarity");
_loot_types = getArray(configFile >> "CfgItemSpawns" >> "lootTypes");

_Config = _Config_Options select (_buildingTypes find _building_table);

_ConfigEntry = configFile >> "CfgItemSpawns" >> "Loot" >> _building_table;

if(_savedLoot isEqualTo []) then {
	// Fresh Spawn
	_lChance = _Config select 0; // chance for building to spawn loot
	_sChance = _Config select 1; // chance for pile to spawn loot
	_tChance = _Config select 2; // chance for rarity types
	_gChance = _Config select 3; // chance for gear types


	if(random(100) <= _lChance) then {
		//--- building is spawning loot
		_spawn_positions = [];

		// spawn minumum number of piles
		for "_i" from 1 to _MinPiles do {
			if(count(_positions) == 0) exitWith {};
			_spawn_positions pushBack (_positions deleteAt floor(random(count(_positions))));
		};
		while{count(_positions) > 0} do {
			_pos = _positions deleteAt floor(random(count(_positions)));
			if(random(100) < _sChance) then {
				_spawn_positions pushBack _pos;
			};
		};

		{
			_pos = ASLtoATL(AGLtoASL(_building modelToWorld _x));
			_object = "groundWeaponHolder" createVehicle _pos;
			_object setposATL _pos;

			_number_of_items_in_pile = 1 + floor(random(3)); //TODO: make this configurable

			_spawnedGear = []; //--- keeps track of items spawned so we don't go over limit
			_spawnedCount = [];
			for "_i" from 1 to _number_of_items_in_pile do {
				_type = "";
				while{true} do {
					_max = 0;
					{_max = _max + _x;} forEach _gChance;
					_roll = random(_max);
					_value = 0;
					{
						_value = _value + _x;
						if(_roll <= _value) exitWith {
							_type = _loot_types select _forEachIndex;
						};
					} forEach _gChance;

					_exit = false;
					_index = _spawnedGear find _type;
					if(_index == -1) then {
						_spawnedGear pushback _type;
						_spawnedCount pushBack 1;
						_exit = true;
					} else {
						_count = _spawnedCount select _index;
						_limit = ["Max" + _type + "s"] call _getCFGValue;
						if(!isNil {_limit}) then {
							if(_count < _limit) then {
								_spawnedCount set[_index,_count+1];
								_exit = true;
							};
						} else {
							_spawnedCount set[_index,_count+1];
							_exit = true;
						};
					};

					if(_exit) exitWith {};
				};

				if(_i == 1) then {
					if(toLower(_type) != "handgun") then {
						_spawnedGear pushback "Handgun";
						_spawnedCount pushBack 1;
					};
					if(tolower(_type) != "weapon") then {
						_spawnedGear pushback "Weapon";
						_spawnedCount pushBack 1;
					};
				};
				_rarity = "";
				_max = 0;
				{_max = _max + _x;} forEach _tChance;
				_roll = random(_max);
				_value = 0;
				{
					_value = _value + _x;
					if(_roll <= _value) exitWith {
						_rarity = _loot_rarity select _forEachIndex;
					};
				} forEach _tChance;

				_itemArray = getArray(_ConfigEntry >> _type >> _rarity);

				_item = "";
				_max = 0;
				{_max = _max + (_x select 1);} forEach _itemArray;

				_roll = random(_max);
				_value = 0;
				{
					_value = _value + (_x select 1);
					if(_roll <= _value) exitWith {
						_item = _x select 0;
					};
				} forEach _itemArray;

				//--- TODO: rewrite this LOL

				_class = _item;
				if(isClass (configFile >> "CfgWeapons" >> _item)) then {
					if((toLower(_class) find "item" == 0) || (toLower(_class) find "h_" == 0) || (toLower(_class) find "u_" == 0) || (toLower(_class) find "v_" == 0) || (toLower(_class) find "minedetector" == 0) || (toLower(_class) find "binocular" == 0) || (toLower(_class) find "rangefinder" == 0) || (toLower(_class) find "NVGoggles" == 0) || (toLower(_class) find "laserdesignator" == 0) || (toLower(_class) find "firstaidkit" == 0) || (toLower(_class) find "medkit" == 0) || (toLower(_class) find "toolkit" == 0) || (toLower(_class) find "muzzle_" == 0) || (toLower(_class) find "optic_" == 0) || (toLower(_class) find "acc_" == 0) || (toLower(_class) find "bipod_" == 0)) then {
						_object addItemCargoGlobal [_class,1];
					} else {
						_object addWeaponCargoGlobal [_class,1];
					};
				};
				if(isClass (configFile >> "CfgVehicles" >> _item)) then {
					_object addBackpackCargoGlobal [_class,1];
				};
				if(isClass (configFile >> "CfgMagazines" >> _item)) then {
					_object addMagazineCargoGlobal [_class,1];
				};
			};
		} forEach _spawn_positions;
	};
} else {
	// Spawn saved loot



};
