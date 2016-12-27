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
	Time multiplier server init
*/


[] spawn {
	_dayMult = parseNumber (["DayMultiplier","TM"] call BASE_fnc_getCfgValue);
	_dayStart = parseNumber (["DayTimeStart","TM"] call BASE_fnc_getCfgValue);
	_nightMult = parseNumber (["NightMultiplier","TM"] call BASE_fnc_getCfgValue);
	_nightStart = parseNumber (["NightTimeStart","TM"] call BASE_fnc_getCfgValue);
	_enabled = (["Enabled","TM"] call BASE_fnc_getCfgValue);

	if !(toLower(_enabled) isEqualTo "true") exitWith {};
	
	if(daytime > _nightStart || daytime < _dayStart) then {
		setTimeMultiplier _nightMult;
	} else {
		setTimeMultiplier _dayMult;
	};
	
	while{true} do {
		waitUntil{uiSleep 30; (daytime > _nightStart || daytime < _dayStart)};
		setTimeMultiplier _nightMult;
		waitUntil{uiSleep 30; !(daytime > _nightStart || daytime < _dayStart) };
		setTimeMultiplier _dayMult;
	};
};