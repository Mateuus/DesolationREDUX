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

_unit = _this select 0;
_unitID = _this select 1;
_unitUID = _this select 2;
_unitName = _this select 3;

_return = false;
if(alive _unit) then {
	//--- prevent on disconnect killed
	_unit allowDamage false;
	_unit hideObjectGlobal true;


	diag_log ("Desolation> Saving Disconnected Player (" + _unitName + ")");

	_unit setVariable ["DCed",true];
	if(alive _unit) then {
		//--- if the unit DCed while alive, they are logging out, not ded
		[_unit,false] spawn DS_fnc_requestSave;
	};
	_return = true; //keep the body in game while saving happens
};
_return;