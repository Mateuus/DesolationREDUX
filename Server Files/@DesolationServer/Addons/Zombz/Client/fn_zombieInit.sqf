/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

if !(["Enabled","SM"] call SM_fnc_getCfgValue) exitWith {};

private _version = getText(configFile >> "CfgPatches" >> "DSR_SM_Zombz" >> "version");
diag_log format["DSR_SM_Zombz %1: Starting Init!", _version];

_zombies = bis_functions_mainscope getVariable ["SM_allZombies",[]];

// This should almost never happen!
if (_zombies isEqualTo []) exitWith {};

{
	_zombieAgent = objectFromNetId _x;

	if !(isNull _zombieAgent) then
	{
		if (alive _zombieAgent) then
		{
			_zombieAgent addEventHandler 
			[
				"Local",
				{ 
					_zombieAgent = _this select 0;
					_local = _this select 1;
					if (_local) then
					{
						// This should almost NEVER happen!
						if !((netId _zombieAgent) in SM_IdleZombies) then
						{
							_zombieAgent disableAI "ALL";
							_zombieAgent enableAI "MOVE";
							_zombieAgent enableAI "CHECKVISIBLE";
							_zombieAgent enableAI "PATH";
							_zombieAgent setSpeaker "NoVoice";
							_zombieAgent allowFleeing 0;

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
								_zombieAgent hideObjectGlobal false;
								_zombieAgent enableSimulationGlobal true;
							};
						};
					}
					else
					{
						if ((netId _zombieAgent) in SM_IdleZombies) then
						{
							_index = [SM_IdleZombies, (netId _zombieAgent)] call SM_fnc_zombieIdleZombie;

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
	};
} forEach _zombies;

diag_log format["DSR_SM_Zombz %1: Finished Init!", _version];

true