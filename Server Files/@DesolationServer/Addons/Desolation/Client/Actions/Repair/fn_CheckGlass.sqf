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

_hitpoints = getAllHitPointsDamage _cursor;
_names = _hitpoints select 0;
_values = _hitpoints select 2;
_damaged = false;
{
	if((toLower(_x) find "hit" != -1) && (toLower(_x) find "glass") != -1) then {
		_value = _values select _forEachIndex;
		if(_value > 0) exitWith {
			_damaged = true;
		};
	};
} forEach _names;
_damaged;