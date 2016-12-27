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

params ["_zombie", "_unit", ["_offset", 0]];

((((_zombie worldToModel getPos _unit) select 1) - _offset > 0) && if !((_zombie distance _unit) >= 35) then {[vehicle _unit, "VIEW", _zombie] checkVisibility [eyePos vehicle _unit, eyePos _zombie] > 0} else { true })
