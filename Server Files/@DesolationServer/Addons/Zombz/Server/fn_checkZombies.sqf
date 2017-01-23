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
	_player = _x;
	_nearZombies = _player nearEntities ["SM_Zombz_Base",1000];
	{
		_zombieAgent = _x;
		if ((isNull _zombieAgent) || !(alive _zombieAgent)) then
		{
			_deleted pushBack _forEachIndex;
		}
		else
		{
			if (local _zombieAgent) then
			{
				_zombieAgent setOwner (owner _player);
			};
		};
	} forEach _nearZombies;
	true 
} count _allPlayers;

if (_deleted isEqualTo []) exitWith { true };

{
	_zombies deleteAt (_x - _forEachIndex);
} forEach _deleted;

bis_functions_mainscope setVariable ["SM_allZombies", _zombies, true];

true
