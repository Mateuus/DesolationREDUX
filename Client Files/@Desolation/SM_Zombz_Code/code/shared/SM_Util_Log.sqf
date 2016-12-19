/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

if (SM_Debug) then
{
	private _version = getText(configFile >> "CfgPatches" >> "SM_Zombz_code" >> "version");
	diag_log format["SM_Zombz %1: %2", _version, _this];

	if (hasInterface) then
	{
		systemchat format["SM_Zombz %1: %2", _version, _this];
	};
};

true
