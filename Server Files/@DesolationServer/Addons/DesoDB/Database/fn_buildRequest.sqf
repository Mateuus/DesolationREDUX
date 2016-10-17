private["_db_function_call","_dll_function_call","_params","_return","_calltype"];

_db_function_call = {
	params[["_dbfunction","getUUID"],["_arguments",[]]];
	private["_base","_baseargs","_argEntryBase","_args","_badRequest","_entryName","_entryValue","_chars","_newchars","_request"];

	_base = "{'dllfunction': '%1', 'dllarguments': { %2 } }";
	_dbbase = "'dbfunction': '%1', 'dbarguments': { %2 }";
	
	_argEntryBase = "'%1': %2";
	_args = "";
	_badRequest = false;
	{
		if(_forEachIndex != 0) then {
			_args = _args + ", ";
		};
		
		_entryName = _x select 0;
		if(_entryName find "'" != -1) exitWith {
			_badRequest = true;
		};
		_entryValue = _x select 1;
		if(typename _entryValue == typename "") then {
			if(_entryValue find "'" != -1) then {
				_chars = _entryValue splitString "";
				_newchars = [];
				{
					if(_x == "'") then {
						_newchars pushback '"';
					} else {
						_newchars pushBack _x;
					};
				} forEach _chars;
				_entryValue = _newchars joinString "";
			};
			_entryValue = "'" + _entryValue + "'";
		};
		_args = _args + format[_argEntryBase,_entryName,_entryValue];
	} forEach _arguments;

	if(_badRequest) exitWith {
		diag_log "==== DESOLATION DB ERROR ====";
		diag_log "BAD REQUEST SENT TO DB";
		diag_log str(_dbfunction);
		diag_log str(_arguments);
		diag_log "==== DESOLATION DB ERROR ====";
		"";
	};

	_baseargs = format[_dbbase,_dbfunction,_args];
	_request = format[_base,"dbcall",_baseargs];
	_request;
};
_dll_function_call = {
	params[["_dllfunction","initdb"],["_arguments",[]]];
	private["_base","_argEntryBase","_args","_badRequest","_entryName","_entryValue","_chars","_newchars","_request"];

	_base = "{'dllfunction': '%1', 'dllarguments': { %2 } }";

	_argEntryBase = "'%1': %2";
	_args = "";
	_badRequest = false;
	{
		if(_forEachIndex != 0) then {
			_args = _args + ", ";
		};
		
		_entryName = _x select 0;
		if(_entryName find "'" != -1) exitWith {
			_badRequest = true;
		};
		_entryValue = _x select 1;
		if(typename _entryValue == typename "") then {
			if(_entryValue find "'" != -1) then {
				_chars = _entryValue splitString "";
				_newchars = [];
				{
					if(_x == "'") then {
						_newchars pushback '"';
					} else {
						_newchars pushBack _x;
					};
				} forEach _chars;
				_entryValue = _newchars joinString "";
			};
			_entryValue = "'" + _entryValue + "'";
		};
		_args = _args + format[_argEntryBase,_entryName, _entryValue];
	} forEach _arguments;

	if(_badRequest) exitWith {
		diag_log "==== DESOLATION DB ERROR ====";
		diag_log "BAD REQUEST SENT TO DB";
		diag_log str(_dllfunction);
		diag_log str(_arguments);
		diag_log "==== DESOLATION DB ERROR ====";
		"";
	};

	_request = format[_base,_dllfunction,_args];
	_request;
};

_calltype = _this select 0;
_params = +_this;
_params deleteAt 0;
if(_calltype == 0) then {
	_return = _params call _dll_function_call;
} else {
	_return = _params call _db_function_call;
};
_return;

