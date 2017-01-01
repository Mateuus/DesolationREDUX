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

params [["_targetNetId", ""],["_zombieAgentNetId", ""],"_zombieAgent","_target","_alreadyRunning","_targetGroup","_owner","_zombieInfo","_count","_zombieArray","_targetData","_array","_passed"];
_zombieAgent = objectFromNetId _zombieAgentNetId;

if (isNull _zombieAgent) exitWith 
{ 
	"Problem fetching zombie to update locality to" call SM_Util_log; 
};

// May cause crashes??
_target = objNull;
if (_targetNetId != "") then
{
	_target = objectFromNetId _targetNetId;
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
