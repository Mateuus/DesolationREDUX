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
	if !("dsr_scrap_metal" in (magazines _player)) exitWith
	{
		systemChat "You do not have the required sheet metal to repair!";
	};
	if !(local _target) exitWith
	{
		systemChat "You must get in the driver seat first!";
	};
	_player removeMagazine "dsr_scrap_metal";
	_target setHitPointDamage ["HitBody", 0];
	systemChat "You have succesfully repaired the body!";
	["updateVehicle","",[_target]] remoteExec ["DS_fnc_dbRequest", 2];
};