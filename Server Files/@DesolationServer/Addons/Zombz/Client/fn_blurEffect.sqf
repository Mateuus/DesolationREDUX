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

"dynamicblur" ppEffectEnable true;
"dynamicblur" ppEffectAdjust [1];
"dynamicblur" ppEffectCommit 0;
"dynamicblur" ppEffectAdjust [0];
"dynamicblur" ppEffectCommit (1 + random 1);

[] call SM_fnc_bloodEffect;