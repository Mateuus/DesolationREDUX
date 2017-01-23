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

params ["_zombieAgent","_target","_soundLast"];

if ((animationState _zombieAgent) isEqualTo "unconscious") exitWith { _soundLast };

if ((diag_ticktime - _soundLast) >= 3) then
{
	_aggressive = selectRandom getArray (configFile >> "SM_Zombz" >> "SM_AggressiveArray"); 
	[_zombieAgent, _aggressive] remoteExecCall ["Say3D", SM_NearbyPlayers];
	_soundLast = diag_ticktime;
};

doStop _zombieAgent;

_zombieAgent setDir (_zombieAgent getDir _target);

_attackAnim = selectRandom ["ZombieAttack1", "ZombieAttack2", "ZombieAttack3"];
[_zombieAgent, _attackAnim] remoteExecCall ["switchMove", SM_NearbyPlayers];

_attack = selectRandom getArray (configFile >> "SM_Zombz" >> "SM_AttackArray");
[_zombieAgent, _attack] remoteExecCall ["say3D", SM_NearbyPlayers];

_soundLast
