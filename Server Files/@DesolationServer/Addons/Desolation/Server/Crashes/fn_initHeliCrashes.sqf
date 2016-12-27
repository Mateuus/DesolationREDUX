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

_crashTypesClasses = "true" configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes");

// Commented out due to not being used?
//_crashTypes = [];
DS_HeliCrash_CrashTypes = [];
{
	_crashName = configName _x;
	//_crashTypes pushBack (_crashName);
	_variableName = format ["DS_HeliCrash_%1_locations",_crashName];
	_crashLocations = getarray (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "Locations");
	missionNamespace setVariable [_variableName, _crashLocations];
	DS_HeliCrash_CrashTypes pushback _variableName;
} foreach _crashTypesClasses;

true