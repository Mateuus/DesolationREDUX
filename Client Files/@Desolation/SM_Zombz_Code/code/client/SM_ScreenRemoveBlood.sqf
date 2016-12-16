/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

disableSerialization;

_display = uinamespace getVariable ["SM_RscHealthTextures", displayNull];

if (isNull _display) exitWith {};

_lower = _display displayctrl 1211;
_middle = _display displayctrl 1212;
_upper = _display displayctrl 1213;
_left = _display displayCtrl 1214;
_right = _display displayCtrl 1215; 

_lower ctrlsetfade 1;
_middle ctrlsetfade 1;
_upper ctrlsetfade 1;
_left ctrlSetFade 1;
_right ctrlSetFade 1;

_upper ctrlcommit 1.5;
_middle ctrlcommit 1;
_lower ctrlcommit 0.8;
_left ctrlCommit 1;
_right ctrlCommit 1;

true
