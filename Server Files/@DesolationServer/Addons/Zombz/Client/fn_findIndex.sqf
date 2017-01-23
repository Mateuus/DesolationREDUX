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

private["_haystack","_needle","_result","_i","_q"];
_haystack = _this select 0;
_needle = _this select 1;
_result = -1;
try
{
	for "_i" from 0 to ((count _haystack) -1) do 
	{
		_q = (_haystack select _i) find _needle;
		if (_q != -1) then
		{
			throw _i;
		};
	};
}
catch 
{
	_result = _exception;
};

_result