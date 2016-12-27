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

private ["_zombieAgent","_fired","_zombiePosition","_firedPosition","_zombieVariable"];
_zombieAgent = _this select 0;
_fired = _this select 7;

if !(isPlayer _fired) exitWith {};

_zombiePosition = position _zombieAgent;
_firedPosition = position _fired;
_zombieVariable = _zombieAgent getVariable ["SM_FiredNear", []];
_zombieVariable pushBack _firedPosition;
_zombieAgent setVariable ["SM_FiredNear", _zombieVariable];

true
