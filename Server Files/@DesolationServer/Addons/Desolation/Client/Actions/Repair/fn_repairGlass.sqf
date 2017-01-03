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
	if !("dsr_items_glasspart" in (magazines _player)) exitWith
	{
		systemChat "You do not have the required glass to repair!";
	};
	if !(local _target) exitWith
	{
		systemChat "You must get in the driver seat first!";
	};
	_player removeMagazine "dsr_items_glasspart";
	_hitpoints = getAllHitPointsDamage _target;
	_names = _hitpoints select 0;
	_values = _hitpoints select 2;
	_damaged = 0;
	_mostDamaged = 0;
	{
		_value = _values select _forEachIndex;
		if (((toLower(_x) find "hit" != -1) && (toLower(_x) find "glass") != -1) && (_value > 0) && (_value > _mostDamaged)) then 
		{
			_damaged = _forEachIndex;
			_mostDamaged = _value;
		};
	} forEach _names;
	_target setHitIndex [_damaged, 0];
	systemChat "You have succesfully repaired a glass!";
	["updateVehicle","",[_target]] remoteExec ["DS_fnc_dbRequest", 2];
};