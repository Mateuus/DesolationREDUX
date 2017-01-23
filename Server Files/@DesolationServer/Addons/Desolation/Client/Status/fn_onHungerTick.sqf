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

_dHunger = 1/90; //--- (100 total hunger) (2.5 hours till starvation)

DS_var_lastAte = DS_var_lastAte + 1;

if(DS_var_lastAte > 5400) then { // 1.5 hour grace
	DS_var_Hunger = DS_var_Hunger - _dHunger;
	if(!DS_var_isStarving) then {
		DS_var_isStarving = true;
	};
} else {
	if(DS_var_isStarving) then {
		DS_var_isStarving = false;
	};
};