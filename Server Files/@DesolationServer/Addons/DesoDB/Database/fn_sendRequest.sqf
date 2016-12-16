#include "..\constants.hpp"

params["_request"];
private["_response","_compiledResponse","_uuid", "_finalResponse","_return","_doswitchloop","_innerdoloop"];

diag_log "DesoDB > Sending request";
_size = 1000;
_len = count(_request);
for "_i" from 0 to ceil(_len/_size) do {
	if(_i == ceil(_len/_size)) then {
		diag_log (_request select [_i*_size]);
	} else {
		diag_log (_request select [_i*_size,_size]);
	};
};

_response = "libredex" callExtension _request;
diag_log "DesoDB > Checking Response";
diag_log _response;
_compiledResponse = call compile _response;

_doswitchloop = true;
_return = "";
// do loop because there seems to be no "fall throu"
while{_doswitchloop} do {
    _doswitchloop = false;

    switch (_compiledResponse select 0) do
    {
       /*
        * TODO: handle async stuff
        * case PROTOCOL_MESSAGE_TYPE_ASYNC 
        * save uuid from select 1
        * if UUID == emptystring exit script (will be an async request without response)
        * loop callExtension with PROTOCOL_LIBARY_FUNCTION_CHECK_MESSAGE_STATE with UUID until _response != PROTOCOL_MESSAGE_NOT_EXISTING
        * loop callExtension with PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE with UUID until _response == PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG and sumup strings in _finalResponse
        * _compiledResponse =  call compile _finalResponse;
        * continue as usual if it where no async string
        * _doswitchloop = true;
        */ 
        case PROTOCOL_MESSAGE_TYPE_ASYNC: {
            _uuid = _compiledResponse select 1;
            _return = "";

            /* empty uuid means function call without retuning data e.g. updates */
            if (_uuid != "") then {
                _request = "{ 'dllfunction': '" + PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL + "', 'dllarguments': {  'dbfunction': '" + PROTOCOL_DBCALL_FUNCTION_RETURN_ASYNC_MSG + "', 'dbarguments': {  'msguuid': '" + _uuid + "' } } }";

                _innerdoloop = true;
                while{_innerdoloop} do {
                    _response = "libredex" callExtension _request;

                    if(_response == PROTOCOL_MESSAGE_NOT_EXISTING) then {
                        uiSleep 0.5;
                    } else {
                        _innerdoloop = false;
                    };
                };
                
                _compiledResponse = call compile _response;
                
                _doswitchloop = true;
            };
        };
        
        case PROTOCOL_MESSAGE_TYPE_MESSAGE: {
            _return = _compiledResponse select 1;
        };
        
        case PROTOCOL_MESSAGE_TYPE_MULTIPART: {
            _uuid = _compiledResponse select 1;
            _finalResponse = _compiledResponse select 2;
            
            _request = "{ 'dllfunction': '" + PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE + "', 'dllarguments': {  'msguuid': '" + _uuid + "' } }";
			
			diag_log "Receiving multipart message";
            _innerdoloop = true;
            while{_innerdoloop} do {
                _response = "libredex" callExtension _request;

                if(_response != PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG) then {
                    _finalResponse = _finalResponse + _response;
                } else {
                    _innerdoloop = false;
                };
            };
            
            _compiledResponse = call compile _finalResponse;
            diag_log "Message received";
            _doswitchloop = true;
        };

        case PROTOCOL_MESSAGE_TYPE_ERROR: {
            // log error
            diag_log (_compiledResponse select 1);
            
            // handle error, do something terrible like set the server on fire

            // return some information
            _return = "error";
        };
    };
};

if(isNil {_return}) exitWith {
	diag_log ("DB RESPONSE > NIL RETURN");
	"";
};
diag_log ("DB RESPONSE > " + str(_return));
_return;