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

_target = _this;
_dif0 = (boundingBoxReal _target) select 0;
_dif1 = (boundingBoxReal _target) select 1;
_distance = ((_dif0 distance _dif1) / 2);
if (_target isKindOf "Man") then
{
	_distance = (_dif0 distance _dif1);
};
if (_target isKindOf "Air") then
{
	_distance = ((_dif0 distance _dif1) / 4);
};

_distance
