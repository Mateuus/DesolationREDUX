/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_player","_currentZombiesArray","_currentZombies","_currentZombieSpawned","_deletedZombies","_deleted","_zombie"];
_player = _this;
_currentZombiesArray = _player getVariable ["SM_CurrentZombies", [0, []]];
if (_currentZombiesArray isEqualTo [0, []]) exitWith { _currentZombiesArray };
_currentZombies = _currentZombiesArray select 0;
_currentZombieSpawned = _currentZombiesArray select 1;
_deletedZombies = false;
_deleted = [];
_currentZombies = 0;

{
	_zombie = objectFromNetId _x;
	if (!(isNull _zombie) && alive _zombie) then
	{
		_currentZombies = _currentZombies + 1;
	}
	else
	{
		_deleted pushBack _forEachIndex;
		_deletedZombies = true;
	};
} forEach _currentZombieSpawned;

if (_deletedZombies) then
{
	{
		_currentZombieSpawned deleteAt (_x - _forEachIndex);
	} forEach _deleted;
	_player setVariable ["SM_CurrentZombies", [_currentZombies, _currentZombieSpawned]];
};

[_currentZombies, _currentZombieSpawned]
