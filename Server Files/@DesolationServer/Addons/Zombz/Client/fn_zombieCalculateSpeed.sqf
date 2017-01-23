/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

params [["_zombieAgent", objNull],["_zombieDefaultSpeed", 0],"_building","_zombieIsInBuilding","_zombieisFaster","_buildingBox","_box0","_box1","_xm","_ym","_zm","_xmm","_ymm","_zmm","_zombiePos","_zmx","_zmy","_zmz"];
_building = nearestBuilding _zombieAgent;
_zombieIsInBuilding = false;
if !(isNull _building) then
{
	_buildingBox = boundingBoxReal _building;
	_box0 = _building modelToWorld (_buildingBox select 0);
	_box1 = _building modelToWorld (_buildingBox select 1);
	_xm = _box0 select 0;
	_ym = _box0 select 1;
	_zm = _box0 select 2;
	_xmm = _box1 select 0;
	_ymm = _box1 select 1;
	_zmm = _box1 select 2;
	_zombiePos = getPos _zombieAgent;
	_zmx = _zombiePos select 0;
	_zmy = _zombiePos select 1;
	_zmz = _zombiePos select 2;
	if (((_zmx > _xm) && (_zmx < _xmm)) && ((_zmy > _ym) && (_zmy < _ymm)) && ((_zmz > _zm) && (_zmz < _zmm))) then
	{
		_zombieIsInBuilding = true;
		_zombieAgent setAnimSpeedCoef _zombieDefaultSpeed;
		_zombieAgent setAnimSpeedCoef (_zombieDefaultSpeed / 2);
		_zombieAgent setVariable ["SM_WasInBuilding", true, true];
	};
};

if (_zombieIsInBuilding) exitWith { true };
if (_zombieAgent getVariable ["SM_WasInBuilding", false]) then
{
	_zombieAgent setAnimSpeedCoef _zombieDefaultSpeed;
	_zombieAgent setVariable ["SM_zombieIsFaster", false];
	_zombieAgent setVariable ["SM_WasInBuilding", false, true];
};

_zombieisFaster = _zombieAgent getVariable ["SM_zombieIsFaster", false];

if !(isNull _target) then
{
	if ((_zombieAgent distance2D _target) >= 35) then
	{
		_zombieAgent setAnimSpeedCoef _zombieDefaultSpeed;
		_zombieAgent setVariable ["SM_zombieIsFaster", false];
	}
	else
	{
		if !(_zombieisFaster) then
		{
			_zombieAgent setAnimSpeedCoef (_zombieDefaultSpeed * 1.5);
			_zombieAgent setVariable ["SM_zombieIsFaster", true];
		};
	};
}
else
{
	if !(_zombieisFaster) then
	{
		_zombieAgent setAnimSpeedCoef (_zombieDefaultSpeed * 1.5);
		_zombieAgent setVariable ["SM_zombieIsFaster", true];
	};
};

true
