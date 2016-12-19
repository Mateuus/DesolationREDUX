/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_variable","_defaultValue","_defaultType","_configPath","_missionClass"];
_variable = _this select 0;
_defaultValue = _this select 1;
_configPath = "";

//Check if value exists in mission
_missionClass = (str(missionConfigFile >> "SM_Zombz" >> _variable) isEqualTo "");
if !(_missionClass) then 
{
	_configPath = (missionConfigFile >> "SM_Zombz" >> _variable);
}
else
{
	_configPath = (configFile >> "SM_Zombz" >> _variable);
};

if (_configPath isEqualType "") exitWith { _defaultValue };
if ((str _configPath) isEqualTo "") exitWith { _defaultValue };

//Attempt to get the value
if (_defaultValue isEqualType 1) exitWith { (getNumber _configPath) };
if (_defaultValue isEqualType []) exitWith { (getArray _configPath) };
if (_defaultValue isEqualType true) exitWith { ((getNumber _configPath) isEqualTo 1) };
if (_defaultValue isEqualType "") exitWith { (getText _configPath) };

format["Error fetching config type for %1",_variable] call SM_Util_log;

_defaultValue