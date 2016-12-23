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

params [["_targetNetId", ""],["_zombieAgentNetId", ""],"_zombieAgent","_target","_alreadyRunning","_targetGroup","_owner","_zombieInfo","_count","_zombieArray","_targetData","_array","_passed"];
_zombieAgent = objectFromNetId _zombieAgentNetId;
_target = objectFromNetId _targetNetId;

if (isNull _zombieAgent) exitWith 
{ 
	"Problem fetching zombie to update locality to" call SM_Util_log; 
};
if (isNull _target) exitWith 
{ 
	"Problem fetching player to update locality to" call SM_Util_log; 
	_zombieAgent setOwner -2; 
};

if (alive _zombieAgent) then
{

	_passed = _zombieAgent setOwner (owner _target);

	if !(_passed) then
	{
		SM_FailedPassedZombies pushBack _this;
	};
};

true
