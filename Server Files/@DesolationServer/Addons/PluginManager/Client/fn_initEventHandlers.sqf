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
	initializes UI event handlers
*/

(findDisplay 46) displayAddEventHandler ["KeyDown",{
	_key = _this select 1;
	_shift = _this select 2;
	_ctrl = _this select 3;
	_alt = _this select 4;
	
	_value = false;
	{
		_code = _x select 0;
		
		_response = [_key,_shift,_ctrl,_alt] call _code;
		if(!isNil {_response}) then {
			if(typename _response == typename true) then {
				_value = _value || _response;
			};
		};
	} forEach (missionNamespace getVariable ["BASE_var_KEYDOWN",[]]);
	_value;
}];