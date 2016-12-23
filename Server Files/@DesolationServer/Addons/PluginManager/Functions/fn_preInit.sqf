params["_check","_functions_forclients"];

diag_log "<PluginManager>: Preinit Called";

//--- broadcast client files
{
	publicVariable _x;
} forEach _functions_forclients;

diag_log format["<PluginManager>: Broadcasted %1 functions",count(_functions_forclients)];

//--- compile initialization list of files
_request = ["GetInitOrder"] call DB_fnc_buildIORequest;
diag_log _request;
_order = call compile ([_request] call DB_fnc_sendRequest);

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