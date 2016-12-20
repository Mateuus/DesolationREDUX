/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _player = _this;

if !(isPlayer _player) exitWith
{
	false
};

if (_player call SM_IsSafezoneNear) exitWith
{
	format["Player %1 (%2): Failed to spawn zombies due to being in a safezone", (name _player), (getPlayerUID _player)] call SM_Util_Log;
	false
};

if (isObjectHidden _player) exitWith
{
	format["Player %1 (%2): failed to spawn zombies due to being invisable!", (name _player), (getPlayerUID _player)] call SM_Util_Log;
	false
};

if (((getPosATL _player) select 2) > 20) exitWith
{
	format["Player %1 (%2): failed to spawn zombies due to being over 20 meters above the ground!", (name _player), (getPlayerUID _player)] call SM_Util_Log;
	false
};

if ((typeOf _player) isKindOf "Exile_Unit_GhostPlayer") exitWith
{
	format["Player %1 (%2): failed to spawn zombies due to being ghost player!", (name _player), (getPlayerUID _player)] call SM_Util_Log;
	false
};

if !(alive _player) exitWith
{
	format["Player %1 (%2): failed to spawn zombies due to being dead", (name _player), (getPlayerUID _player)] call SM_Util_Log;
	false
};

true
