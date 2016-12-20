/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_object",objNull],["_sound",""]];
if (!(_sound isEqualTo "") && !(isNull _object) && !(isNil "SM_SoundDistance")) then
{
	_object say3D [_sound, SM_SoundDistance];

	format["Sound has been played by object %1", _object] call SM_Util_Log;
};

true
