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

_this spawn {
	_server_functions = _this select 2;
	
	waitUntil {!isNil "BASE_var_INITORDER"};
	
	diag_log "<PluginManager>: Starting server";
	
	_fnclist = [];
	_plugins = [];
	_cfg = configFile >> "Plugins";
	{
		_cfgEntry = _cfg >> _x;
		if(isClass _cfgEntry) then {
			_plugin = configName _cfgEntry;
			_tag = (GetText(_cfgEntry >> "tag")) + "_";
			if(_tag != "_") then {
				{
					if( (tolower(_x) find tolower(_tag)) == 0) then {
						if !(_x in _fnclist) then {
							_fnclist pushBack _x;
							_plugins pushBack _plugin;
						};
					};
				} forEach _server_functions;
			};
		};
	} forEach BASE_var_INITORDER;
	
	[_fnclist] call BASE_fnc_setupEvents;
	
	diag_log "<PluginManager>: Starting plugins...";
	{
		if((toLower(_x) find "initserver") != -1) then {
			diag_log ((_plugins select _forEachIndex) + " > Init Server");
			[] spawn (missionNamespace getVariable [_x,{DIAG_LOG "FAILED TO FIND FUNCTION";}]);
		};
	} forEach _fnclist;
	
	call BASE_fnc_initActions;
};