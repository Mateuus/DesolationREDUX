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

params ["_zombieAgent"];

_firedNear = _zombieAgent getVariable ["SM_FiredNear",[]];

if (_firedNear isEqualTo []) exitWith
{
	[]
};

_distance = 1000;
_pos = [];

{
	_distanceEnemy = _zombieAgent distance _x;
	if (_distanceEnemy <= _distance) then
	{
		_distance = _distanceEnemy;
		_pos = _x;
	};
} forEach _firedNear;

_zombieAgent setVariable ["SM_FiredNear",nil];

_pos