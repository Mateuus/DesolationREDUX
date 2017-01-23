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

_zombies = bis_functions_mainscope getVariable ["SM_allZombies", []];

// This should almost never happen!
if (_zombies isEqualTo []) exitWith {};

{
	_zombieAgent = objectFromNetId _x;

	if (!(isNull _zombieAgent) && alive _zombieAgent) then
	{
		// I hope this holy fires on the clients that it's set on... and not the server..
		_zombieAgent addEventHandler 
		[
			"Local",
			{ 
				// But just incase, you never know with arma!
				if (isServer) exitWith {};
				_zombieAgent = _this select 0;
				_local = _this select 1;
				if (_local) then
				{
					// This should almost NEVER happen!
					if !((netId _zombieAgent) in SM_IdleZombies) then
					{
						_zombieAgent setCombatMode "RED";
						_zombieAgent allowFleeing 0;
						_zombieAgent enableAttack false;
						_zombieAgent setUnitPos "UP";
						_zombieAgent disableAI "ALL";
						_zombieAgent setSpeaker "NoVoice";
						_zombieAgent enableAI "MOVE";
						_zombieAgent enableAI "CHECKVISIBLE";
						_zombieAgent enableAI "PATH";
						_zombieAgent enableAI "ANIM";
						_zombieAgent enableAI "TEAMSWITCH";

						SM_IdleZombies pushBack (netId _zombieAgent);

						_logicFSM = player getVariable ["SM_zombieIdleFSM", -1];
						if (_logicFSM isEqualTo -1) then
						{
							_logicFSM = execFSM "dsr_zombz_code\FSM\zombieIdleManager.fsm";
							player setVariable ["SM_zombieIdleFSM", _logicFSM];
						};

						// Just incase this is being transfered from another target.
						if (isObjectHidden _zombieAgent) then
						{
							[_zombieAgent, false] remoteExecCall ["hideObjectGlobal", 2];
							[_zombieAgent, true] remoteExecCall ["enableSimulationGlobal", 2];
						};
					};
				}
				else
				{
					if ((netId _zombieAgent) in SM_IdleZombies) then
					{
						_index = [SM_IdleZombies, (netId _zombieAgent)] call SM_fnc_findIndex;

						// This should not return -1, due to we know it's in it.... via the check above...
						// You never know with arma, so error checking is almost always needed!
						if (_index != -1) then
						{
							SM_IdleZombies deleteAt _index;
						};
					};
				};
			}
		];

		_zombieAgent addEventHandler 
		[
			"HandleDamage",
			{
				_this call SM_fnc_zombieHandleDamage; 
			}
		];
	};
} forEach _zombies;

true