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

_required = getArray (_config >> "Actions" >> "Repair" >> "required");

_playerMags = magazines _player;

_missingItems = [];
{
	_item = _x select 0;
	_neededCount = _x select 1;
	_playerCount = { _item == _x } count _playerMags;

	if (_playerCount < _neededCount) then
	{
		_itemMissingClass = getText(configFile >> "CfgMagazines" >> _item >> "displayName");
		_missingItems pushBack [_itemMissingClass, _neededCount - _playerCount];
	};
	true
} count _required;

if ((count _missingItems) != 0) exitWith
{
	_message = "You are missing: ";
	{
		_message = _message + (_x select 0) + " x" + str(_x select 1) + " ";
	} count _missingItems;
	_message remoteExecCall ["systemchat", _player];
};

{
	for "_i" from 1 to (_x select 1) do
	{
		_player removeMagazineGlobal (_x select 0);
	};
} count _required;

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
_object setHitPointDamage [_hitPoint, 0];

true
