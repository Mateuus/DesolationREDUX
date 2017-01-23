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

private ["_zombiePosition","_firedPosition","_zombieVariable"];
params ["_zombieAgent","_fired","_distance","_weapon","_muzzle","_mode","_ammo","_gunner"];

if (!(isPlayer _fired) || !(isPlayer _gunner)) exitWith { false };

_isSupp = false;
if ((primaryWeapon player) == (currentWeapon player)) then
{
	_weaponItems = primaryWeaponItems player;
	_supp = _weaponItems select 0;
	if !(_supp == "") then
	{
		_distance = _distance / 2;
		_isSupp = true;
	};
}
else
{
	if ((secondaryWeapon player) == (currentWeapon player)) then
	{
		_weaponItems = secondaryWeaponItems player;
		_supp = _weaponItems select 0;
		if !(_supp == "") then
		{
			_distance = _distance / 2;
			_isSupp = true;
		};
	};
};

if ((_isSupp) && (_distance > 20)) exitWith {};
_ammo = getText (configFile >> "CfgMagazines" >> _ammo >> "ammo");
_cal = getNumber (configFile >> "CfgAmmo" >> _ammo >> "caliber");
if (!(_isSupp) && (_distance > (150 * _cal))) exitWith {};

_firedPosition = position _fired;
_zombieVariable = _zombieAgent getVariable ["SM_FiredNear", []];
_zombieVariable pushBack _firedPosition;
_zombieAgent setVariable ["SM_FiredNear", _zombieVariable];

true
