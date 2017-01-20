params ["_hitPoint","_object","_index","_player"];

_configAry = "true" configClasses (configFile >> "Cfg3DActions");
_config = _configAry select _index;
_returned = getArray (_config >> "Actions" >> "Remove" >> "returned");

_lootHolder = objNull;
_nearLootHolders = _player nearObjects ["GroundWeaponHolder", 25];
_nearLootHolders append (_player nearObjects ["LootWeaponHolder", 25]);
if ((count _nearLootHolders) != 0) then
{
	_distance = 25;
	{
		_tmpDist = _player distance _x;
		if (_tmpDist < _distance) then
		{
			_lootHolder = _x;
			_distance = _tmpDist;
		};
		true
	} count _nearLootHolders;
};

if (isNull _lootHolder) then
{
	_lootHolder = createVehicle ["LootWeaponHolder", [0,0,0], [], 0, "CAN_COLLIDE"];
	_lootHolder setPosATL (getPosATL _player);
};

{
	_lootHolder addItemCargoGlobal _x;
} count _returned;

_object setOwner 2;
_object setHitPointDamage [_hitPoint, 1];

true
