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
params["_time",["_tickCallback",{false}],["_tickCallbackParams",[]]];
player setUnconscious true;
10481 cutText ["","BLACK OUT",3];
uiSleep 3;
10481 cutText ["You are unconscious.","BLACK FADED",20];
for "_i" from 1 to _time do {
	_response = [_tickCallbackParams,_i,_time] call _tickCallback;
	if(!isNil {_response}) then {
		if(typename _response == typename true) then {
			if(_response) exitWith {};
		};
		if(typename _response == typename 0) then {
			_time = _response;
		};
	};
	uiSleep 1;
};
10481 cutText ["","BLACK IN",5];
DS_var_lastKnockout = diag_tickTime;
player setUnconscious false;
player switchMove "unconsciousoutprone";
//--- TODO: sync the switchmove