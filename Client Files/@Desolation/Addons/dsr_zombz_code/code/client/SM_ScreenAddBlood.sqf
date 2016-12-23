/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_display"];

disableSerialization;

_display = uinamespace getVariable ["SM_RscHealthTextures", displayNull];

if (isNull _display) then 
{
	(["HealthPP_blood"] call bis_fnc_rscLayer) cutrsc ["SM_RscHealthTextures", "PLAIN"];
	_display = uiNamespace getVariable ["SM_RscHealthTextures", displayNull];
};


_lower = _display displayctrl 1211;
_middle = _display displayctrl 1212;
_upper = _display displayctrl 1213;
_left = _display displayctrl 1214;
_right = _display displayctrl 1215;

_lower ctrlsetfade 0.7;	 
_middle ctrlsetfade 0.7;  
_upper ctrlsetfade 0.7;  
_left ctrlSetFade 0.7;
_right ctrlSetFade 0.7;

_lower ctrlcommit 0.2;
_middle ctrlcommit 0.2;
_upper ctrlcommit 0.2;
_left ctrlCommit 0.2;
_right ctrlCommit 0.2;

true
