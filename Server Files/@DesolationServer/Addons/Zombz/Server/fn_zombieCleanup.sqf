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

_zombies = bis_functions_mainscope getVariable ["SM_DeadZombies", []];

// This should only happen if there are no zombies left on the map!
if (_zombies isEqualTo []) exitWith { true };

_deleted = [];
{
	_zombieAgent = objectFromNetId (_x select 0);

	if !(isNull _zombieAgent) then
	{
		_diedAt = _x select 1;
		if ((diag_tickTime - _diedAt) >= 420) then
		{
			// Delete the loot the zombie had.
			_lootWeaponHolder = _x select 2;
			if !(isNull _lootWeaponHolder) then
			{
				deleteVehicle _lootWeaponHolder;
			};

			// Delete the zombie.
			deleteVehicle _zombieAgent;

			_deleted pushBack _forEachIndex;
		};
	};
} forEach _zombies;

if (_deleted isEqualTo []) exitWith { true };

{
	_zombies deleteAt (_x - _forEachIndex);
} forEach _deleted;

bis_functions_mainscope setVariable ["SM_DeadZombies", _zombies];

true
