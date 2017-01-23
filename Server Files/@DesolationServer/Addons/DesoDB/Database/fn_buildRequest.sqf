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

private["_db_function_call","_dll_function_call","_params","_return","_calltype"];

_db_function_call = {
	params[["_dbfunction","getUUID"],["_arguments",[]]];
	private["_base","_baseargs","_argEntryBase","_args","_badRequest","_entryName","_entryValue","_chars","_newchars","_request"];

	_base = "{'dllFunction': '%1', 'dllArguments': { %2 } }";
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
		if(typename _entryValue == typename []) then {
			_entryValue = str(_entryValue);
		};
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
	params[["_dllFunction","initdb"],["_arguments",[]]];
	private["_base","_argEntryBase","_args","_badRequest","_entryName","_entryValue","_chars","_newchars","_request"];

	_base = "{'dllFunction': '%1', 'dllArguments': { %2 } }";

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
		if(typename _entryValue == typename []) then {
			_entryValue = str(_entryValue);
		};
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
		diag_log str(_dllFunction);
		diag_log str(_arguments);
		diag_log "==== DESOLATION DB ERROR ====";
		"";
	};

	_request = format[_base,_dllFunction,_args];
	_request;
};
_io_function_call = {
	params[["_ioFunction","GetInitOrder"],["_arguments",[]]];
	private["_base","_baseargs","_argEntryBase","_args","_badRequest","_entryName","_entryValue","_chars","_newchars","_request"];

	_base = "{'dllFunction': '%1', 'dllArguments': { %2 } }";
	_iobase = "'extFunction': '%1', 'extArguments': { %2 }";
	
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
		if(typename _entryValue == typename []) then {
			_entryValue = str(_entryValue);
			_chars =  _entryValue splitString "";
			_newchars = [];
			_lastChar = " ";
			{
				if(_x != '"') then {
					_newchars pushback _x;
				};
				_lastChar = _x;
			} forEach _chars;
			_newchars deleteAt 0;
			_newchars deleteAt (count(_newchars)-1);
			_newchars = ["[","'"] + _newchars;
			_newchars pushBack "'";
			_newchars pushBack "]";
			_entryValue = _newchars joinString "";
			_parts = _entryValue splitString ",";
			_entryValue = _parts joinString "','";
		};
		
		_args = _args + format[_argEntryBase,_entryName,_entryValue];
	} forEach _arguments;

	if(_badRequest) exitWith {
		diag_log "==== DESOLATION DB ERROR ====";
		diag_log "BAD REQUEST SENT TO DB";
		diag_log str(_ioFunction);
		diag_log str(_arguments);
		diag_log "==== DESOLATION DB ERROR ====";
		"";
	};

	_baseargs = format[_iobase,_ioFunction,_args];
	_request = format[_base,"iocall",_baseargs];
	_request;
};
_calltype = _this select 0;
_params = +_this;
_params deleteAt 0;
if(_calltype == 0) then {
	_return = _params call _dll_function_call;
} else {
	if(_calltype == 1) then {
		_return = _params call _db_function_call;
	} else {
		_return = _params call _io_function_call;
	};
};
_return;

