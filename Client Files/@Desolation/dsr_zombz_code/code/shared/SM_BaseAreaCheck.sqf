/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_position","_isNear","_config","_buildingJammerRange","_nearJammers","_nearBases"];
_position = _this;
_isNear = false;

if (SM_ExileEnabled) then
{
	_isNear = _position call ExileClient_util_world_isInTerritory;
};
if (SM_EpochEnabled) then
{
	_config = "CfgEpochClient" call EPOCH_returnConfig;
	_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
	_nearJammers = _position nearObjects ["PlotPole_EPOCH", _buildingJammerRange];
	{
		if ((_position distance _x) <= _buildingJammerRange) then
		{
			_isNear = true;
		};
	} forEach _nearJammers;
};
if (SM_UserBaseCheck) then
{
	_nearBases = [];
	switch (SM_UserBaseCheckType) do
	{
		case 1:
		{
			_nearBases = _position nearObjects [SM_UserBaseCheckMarkerObjects, SM_UserBaseCheckDistance];
		};
		case 2:
		{
			{
				if ((getmarkerType _x) in SM_UserBaseCheckMarkerObjects) then
				{
					_nearBases pushBack (getMarkerPos _x);
				};
			} forEach allMapMarkers;
		};
	};
	{
		if ((_position distance _x) <= SM_UserBaseCheckDistance) then
		{
			_isNear = true;
		};
	} forEach _nearBases;
};

_isNear
