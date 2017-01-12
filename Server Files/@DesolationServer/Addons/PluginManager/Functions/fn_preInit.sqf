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
params["_check","_functions_forclients"];

diag_log "<PluginManager>: Preinit Called";

//--- broadcast client files
{
	publicVariable _x;
} forEach _functions_forclients;

diag_log format["<PluginManager>: Broadcasted %1 functions",count(_functions_forclients)];

//--- compile initialization list of files
_request = ["GetInitOrder"] call DB_fnc_buildIORequest;
diag_log str _request;
_order = [_request] call DB_fnc_sendRequest;

//--- broadcast config settings 
[_order] call BASE_fnc_compileCfg; 



diag_log format["<PluginManager>: Loading %1 plugins",count(_order)];

_fnclist = [];
_cfg = configFile >> "Plugins";
{
	_cfgEntry = _cfg >> _x;
	if(isClass _cfgEntry) then {
		_tag = (GetText(_cfgEntry >> "tag")) + "_";
		if(_tag != "_") then {
			{
				if( (_x find _tag) == 0) then {
					if !(_x in _fnclist) then {
						_fnclist pushBack _x;
					};
				};
			} forEach _functions_forclients;
		};
	};
} forEach _order;

BASE_var_INITORDER = _order;
BASE_var_FUNCTIONLIST = _fnclist;