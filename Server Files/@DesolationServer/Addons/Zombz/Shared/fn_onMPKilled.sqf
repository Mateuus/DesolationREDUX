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

params["_zombieAgent","_killer"];

if (isServer) then
{
	_zombies = bis_functions_mainscope getVariable ["SM_DeadZombies", []];
	_zombies pushBack [(netId _zombieAgent), diag_tickTime];

	/*
		PLACEHOLDER FOR LOOT ON ZOMBIE
	*/

	bis_functions_mainscope setVariable ["SM_DeadZombies", _zombies];
};

if ((hasInterface) && (_killer isEqualTo player)) then
{
	if ((netId _zombieAgent) in SM_IdleZombies) then
	{
		_index = [SM_IdleZombies, (netId _zombieAgent)] call SM_fnc_findIndex;

		// This should almost never return -1, due to we know it's in it, because the check above said so...
		// You never know with arma...
		if (_index != -1) then
		{
			SM_IdleZombies deleteAt _index;
		};
	};
};