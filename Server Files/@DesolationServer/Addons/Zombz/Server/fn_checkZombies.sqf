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

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

private ["_zombies","_deleted"];

_zombies = bis_functions_mainscope getVariable ["SM_allZombies", []];

// This should only happen if there are no zombies left on the map!
if (_zombies isEqualTo []) exitWith { true };

_allPlayers = allPlayers - entities "HeadlessClient_F";

_deleted = [];
{
	_zombieAgent = objectFromNetId _x;
	if ((isNull _zombieAgent) || !(alive _zombieAgent)) then
	{
		_deleted pushBack _forEachIndex;
	}
	else
	{
		if (local _zombieAgent) then
		{
			_player = objNull;
			_distance = 1000;

			// Locate the closest player
			{
				_tmpPlayer = _x;
				_tmpDistance = _tmpPlayer distance2D _zombieAgent;
				if ((local _zombieAgent) && (_tmpDistance < _distance)) then
				{
					_player = _tmpPlayer;
					_distance = _tmpDistance;
				};
			} count _allPlayers;

			if !(isNull _player) then
			{
				// Check to make sure the zombie is not already owned by the player.
				if !((owner _zombieAgent) == (owner _player)) then
				{
					// Set the owner of the zombie to the closest player.
					_zombieAgent setOwner (owner _player);
				};
			}
			else
			{
				// No valid player found, so hide and disable the zombies behavior.
				if !(isObjectHidden _zombieAgent) then
				{
					_zombieAgent setOwner -2;
					_zombieAgent enableSimulationGlobal false;
					_zombieAgent hideObjectGlobal true;
					_zombieAgent disableAI "ALL";
				};
			};
		}
		else
		{
			_playerIsNear = false;
			_distance = 1000;
			{
				if ((_x distance _zombieAgent) <= _distance) exitWith { _playerIsNear = true; };
			} count _allPlayers;

			// No valid player found, so hide and disable the zombies behavior.
			if !(isObjectHidden _zombieAgent) then
			{
				_zombieAgent setOwner -2;
				_zombieAgent enableSimulationGlobal false;
				_zombieAgent hideObjectGlobal true;
				_zombieAgent disableAI "ALL";
			};
		};
	};
} forEach _zombies;

if (_deleted isEqualTo []) exitWith { true };

{
	_zombies deleteAt (_x - _forEachIndex);
} forEach _deleted;

bis_functions_mainscope setVariable ["SM_allZombies", _zombies, true];

true
