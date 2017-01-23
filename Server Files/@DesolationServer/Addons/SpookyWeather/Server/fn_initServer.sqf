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
	Spooky Weather Init
*/
_fogValue = parseNumber (["FogValue","SW"] call BASE_fnc_getCfgValue);


0 setFog _fogValue;
forceWeatherChange;
999999 setFog (_fogValue - (_fogValue/2) + random(_fogValue)); // 0.05 - 0.025 + random(0.05) (or 0.05 +- 0.025)