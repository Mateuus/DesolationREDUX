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


_player = player;
_vehiclePlayer = vehicle player;
_target = cursorObject;

if !(_player == _vehiclePlayer) exitWith
{
	systemchat "Please exit the vehicle first!";
};

if (2 call DS_fnc_doAction) then
{
	if !("dsr_engine_block" in (magazines _player)) exitWith
	{
		systemChat "You do not have the required engine block to repair!";
	};
	if !(local _target) exitWith
	{
		systemChat "You must get in the driver seat first!";
	};
	_player removeMagazine "dsr_engine_block";
	_target setHitPointDamage ["HitEngine", 0];
	systemChat "You have succesfully repaired the engine block!";
	["updateVehicle","",[_target]] remoteExec ["DS_fnc_dbRequest", 2];
};