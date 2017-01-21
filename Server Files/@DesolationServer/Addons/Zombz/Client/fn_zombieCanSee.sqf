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

params ["_zombie", "_unit"];

_objects = [];
{
	_objs = lineIntersectsObjs [eyePos _unit, eyePos _zombie, objNull, objNull, false, _x];
	if (count(_objs) != 0) then
	{
		_objects append _objs;
	};
	true
} count [1,2,4,8,16,32];

_blackListObjects = [];
_canSee = false;
if (count(_blackListObjects) != 0) then
{
	_deleted = [];
	{
		if (toLower(_x) in _blackListObjects) then
		{
			_deleted pushBack _x;
		};
		true
	} count _objects;

	_objects = _objects - _deleted;

	if (count(_objects) == 0) then
	{
		_canSee = true;
	};
}
else
{
	_canSee = true;
};

_canSee
