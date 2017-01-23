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
createDialog "DS_Journal_Index";

[] spawn {
	disableserialization;
	waitUntil{!isNull (findDisplay 4001) || isNull (findDisplay 4002)};
	if(!isNull (findDisplay 4001)) then {
		// set build button event
		_btn = (findDisplay 4001) displayCtrl 7;
		_btn buttonSetAction "call DS_fnc_onBuildClick";
	};
};

