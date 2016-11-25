/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_crashTypesClasses = "true" configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes");
_crashTypes = [];
DS_HeliCrash_CrashTypes = [];
{
_crashName = configName _x;
_crashTypes pushBack (_crashName);
_variableName = format ["DS_HeliCrash_%1_locations",_crashName];
_crashLocations = getarray configClasses (configFile >> "CfgHeliCrashes" >> "CrashTypes">> _crashName >> "Locations");
missionNamespace setVariable [_variableName, _crashLocations];
DS_HeliCrash_CrashTypes pushback _variableName;
}foreach _crashTypesClasses;

