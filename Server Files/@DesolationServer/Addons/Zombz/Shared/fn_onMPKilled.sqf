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

params["_zombieAgent","_killer"];

if (isServer) then
{
	_zombies = bis_functions_mainscope getVariable ["SM_DeadZombies", []];
	_zombies pushBack [(netId _zombieAgent), diag_tickTime];

	/*
		PLACEHOLDER FOR LOOT ON ZOMBIE
	*/

	bis_functions_mainscope setVariable ["SM_DeadZombies", _zombies, objNull];
};

if ((hasInterface) && (_killer isEqualTo player)) then
{
	if ((netId _zombieAgent) in SM_IdleZombies) then
	{
		_index = [SM_IdleZombies, (netId _zombieAgent)] call SM_fnc_findZombie;

		// This should almost never return -1, due to we know it's in it, because the check above said so...
		// You never know with arma...
		if (_index != -1) then
		{
			SM_IdleZombies deleteAt _index;
		};
	};

	_FSMLogic = _zombieAgent getVariable ["SM_FSMLogic",-1];
	if (_FSMLogic != -1) then
	{
		_FSMLogic setFSMVariable ["SM_TermiateFSM", true];
	};
};