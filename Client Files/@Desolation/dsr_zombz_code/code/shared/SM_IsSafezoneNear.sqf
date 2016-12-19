/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_position","_isNear","_nearSafeZones"];
_position = _this;
_isNear = false;

if (SM_ExileEnabled) then
{
	_isNear = _position call ExileClient_util_world_isInTraderZone
};
if (SM_EpochEnabled) then
{
	_nearSafeZones = _position nearObjects ["ProtectionZone_Invisible_F",60];
	{
		if ((_position distance _x) <= 30) then
		{
			_isNear = true;
		};
	} forEach _nearSafeZones;	
};
if (SM_UserSafezoneCheck) then
{
	_nearSafeZones = [];
	switch (SM_UserSafezoneCheckType) do
	{
		case 1:
		{
			_nearSafeZones = _position nearObjects [SM_UserSafezoneCheckMarkerObjects, SM_UserSafezoneCheckDistance];
		};
		case 2:
		{
			{
				if ((getmarkerType _x) in SM_UserSafezoneCheckMarkerObjects) then
				{
					_nearSafeZones pushBack (getMarkerPos _x);
				};
			} forEach allMapMarkers;
		};
	};
	{
		if ((_position distance _x) <= SM_UserSafezoneCheckDistance) then
		{
			_isNear = true;
		};
	} forEach _nearSafeZones;
};

_isNear
