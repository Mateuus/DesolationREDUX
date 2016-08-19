/*
	fn_setupLoadout
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_unit",["_equipmentArray",[]]];


if!(_equipmentArray isEqualTo [])then
{
	//--- load the chosen loadout
		removeHeadgear _unit:
		removeGoggles _unit;
		removeVest _unit;
		removeBackpack _unit;
		removeUniform _unit;
		removeAllWeapons _unit:
		removeAllAssignedItems _unit;
		
		_unit setUnitLoadout _equipmentArray;
}
else
{
	_loadout = getArray(missionConfigFile >> "CfgSpawnLoadout" >> "FreshSpawn");
	diag_log format["fresh spawn _loadout:%1",_loadout];
	if(_loadout isEqualTo [])then
	{
		_unit addMagazine "16Rnd_9x21_Mag";
		_unit addWeapon "hgun_Rook40_F";
		_unit unlinkItem "ItemMap";
		_unit unlinkItem "ItemWatch";
		_unit unlinkItem "ItemCompass";
	}
	else
	{
		_removeitems = _loadout select 7;
		{_unit unlinkItem _x;}forEach _removeItems;
		_uniform = (_loadout select 0);
		if!(_uniform isEqualTo []) then
		{
			_unit addUniform _uniform;
		};
		_vest = (_loadout select 1);
		if!(_vest isEqualTo []) then
		{
			_unit addVest _vest;
		};
		_backpack = (_loadout select 2);
		if!(_backpack isEqualTo []) then
		{
			_unit addBackPack (_backpack);
		};
		_items = count (_loadout select 3);
		_item = (_loadout select 3);
		if!(_item isEqualTo []) then
		{
			for "_i" from 0 to _items-1 do
			{
				_unit addItemCargoGlobal [_item select _i,1];
			};
		};
		_mags = count(_loadout select 4);
		_mag = (_loadout select 4);
		if!(_mag isEqualTo []) then
		{
			for "_m" from 0 to _mags-1 do{
				_unit addItem (_mag select 0);
			};
		};
		_primary = (_loadout select 5) select 0;
		if!(_primary isEqualTo []) then
		{
			_unit addWeaponGlobal _primary;
			//need to add attachment code
		};
		_handgun = (_loadout select 6) select 0;
		if!(_primary isEqualTo []) then
		{
			_unit addWeaponGlobal _handgun;
			//need to add attachment code
		};
	};
};