/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_zombie", objNull],["_zombieDefaultSpeed", 0],"_building","_zombieIsInBuilding","_zombieisFaster"];
_building = nearestBuilding _zombie;
_zombieIsInBuilding = false;
if !(isNull _building) then
{
	private["_buildingBox","_box0","_box1","_xm","_ym","_zm","_xmm","_ymm","_zmm","_zombiePos","_zmx","_zmy","_zmz"];
	_buildingBox = boundingBoxReal _building;
	_box0 = _building modelToWorld (_buildingBox select 0);
	_box1 = _building modelToWorld (_buildingBox select 1);
	_xm = _box0 select 0;
	_ym = _box0 select 1;
	_zm = _box0 select 2;
	_xmm = _box1 select 0;
	_ymm = _box1 select 1;
	_zmm = _box1 select 2;
	_zombiePos = getPos _zombie;
	_zmx = _zombiePos select 0;
	_zmy = _zombiePos select 1;
	_zmz = _zombiePos select 2;
	if (((_zmx > _xm) && (_zmx < _xmm)) && ((_zmy > _ym) && (_zmy < _ymm)) && ((_zmz > _zm) && (_zmz < _zmm))) then
	{
		_zombieIsInBuilding = true;
		_zombie setAnimSpeedCoef _zombieDefaultSpeed;
		_zombie setAnimSpeedCoef (_zombieDefaultSpeed / SM_ZombieInBuildingSpeedDevidor);
		_zombie setVariable ["SM_WasInBuilding", true, true];
	};
};

if (_zombieIsInBuilding) exitWith { true };
if (_zombie getVariable ["SM_WasInBuilding", false]) then
{
	_zombie setAnimSpeedCoef _zombieDefaultSpeed;
	_zombie setVariable ["SM_zombieIsFaster", false];
	_zombie setVariable ["SM_WasInBuilding", false, true];
};

_zombieisFaster = _zombie getVariable ["SM_zombieIsFaster", false];
if (SM_ZombiesFastClose) then
{
	if !(isNull _target) then
	{
		if ((_zombie distance2D _target) >= SM_ZombieSpeedDistance) then
		{
			_zombie setAnimSpeedCoef _zombieDefaultSpeed;
			_zombie setVariable ["SM_zombieIsFaster", false];
		}
		else
		{
			if !(_zombieisFaster) then
			{
				_zombie setAnimSpeedCoef (_zombieDefaultSpeed * SM_ZombieSpeedMultiplyer);
				_zombie setVariable ["SM_zombieIsFaster", true];
			};
		};
	}
	else
	{
		if !(_zombieisFaster) then
		{
			_zombie setAnimSpeedCoef (_zombieDefaultSpeed * SM_ZombieSpeedMultiplyer);
			_zombie setVariable ["SM_zombieIsFaster", true];
		};
	};
};
if !(SM_ZombiesFastClose) then
{
	if !(isNull _target) then
	{
		if ((_zombie distance2D _target) <= SM_ZombieSpeedDistance) then
		{
			_zombie setAnimSpeedCoef _zombieDefaultSpeed;
			_zombie setVariable ["SM_zombieIsFaster", false];
		}
		else
		{
			if !(_zombieisFaster) then
			{
				_zombie setAnimSpeedCoef (_zombieDefaultSpeed * SM_ZombieSpeedMultiplyer);
				_zombie setVariable ["SM_zombieIsFaster", true];
			};
		};
	}
	else
	{
		if !(_zombieisFaster) then
		{
			_zombie setAnimSpeedCoef (_zombieDefaultSpeed * SM_ZombieSpeedMultiplyer);
			_zombie setVariable ["SM_zombieIsFaster", true];
		};
	};
};

true
