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

params ["_hitPoint","_object","_index","_player"];

_configAry = "true" configClasses (configFile >> "Cfg3DActions");
_config = _configAry select _index;
_returned = getArray (_config >> "Actions" >> "Remove" >> "returned");

_lootHolder = objNull;
_nearLootHolders = _player nearObjects ["GroundWeaponHolder", 5];
_nearLootHolders append (_player nearObjects ["LootWeaponHolder", 5]);
if ((count _nearLootHolders) != 0) then
{
	_distance = 5;
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
if !(local _object) then
{
	while {!local _object} do
	{
		_object setOwner 2;
		if !(isNull(driver _object)) then
		{
			(driver _object) action ["Eject", _object];
		};
	};
};
_object setHitPointDamage [_hitPoint, 1];

true
