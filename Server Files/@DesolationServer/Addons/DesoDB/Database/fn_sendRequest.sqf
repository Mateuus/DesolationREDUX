#include "..\constants.hpp"

params["_request"];
private["_response","_compiledResponse","_uuid", "_finalResponse","_return","_doswitchloop","_innerdoloop"];

_response = "redex" callExtension _request;
_compiledResponse = call compile _response;

_switchloop = true;

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
        case PROTOCOL_MESSAGE_TYPE_ASYNC
        {
            _uuid = _compiledResponse select 1;
            _return = "";

            /* empty uuid means function call without retuning data e.g. updates */
            if (_uuid != "") {
                _request = "{ 'dllfunction': '" + PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL + "', 'dllarguments': {  'dbfunction': '" + PROTOCOL_DBCALL_FUNCTION_RETURN_ASYNC_MSG + "', 'dbarguments': {  'msguuid': '" + _uuid + "' } }";

                _innerdoloop = true;
                while{_innerdoloop} do {
                    _response = "redex" callExtension _request;

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
        
        case PROTOCOL_MESSAGE_TYPE_MESSAGE:
        {
            _return = _compiledResponse select 1;
        };
        
        case PROTOCOL_MESSAGE_TYPE_MULTIPART:
        {
            _uuid = _compiledResponse select 1;
            _finalResponse = _compiledResponse select 2;
            
            _request = "{ 'dllfunction': '" + PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE + "', 'dllarguments': {  'msguuid': '" + _uuid + ' } }"

            _innerdoloop = true;
            while{_innerdoloop} do {
                _response = "redex" callExtension _request;

                if(_response != PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG) then {
                    _finalResponse = _finalResponse + _response;
                } else {
                    _innerdoloop = false;
                };
            };
            
            _compiledResponse = call compile _finalResponse;
            
            _doswitchloop = true;
        };

        case PROTOCOL_MESSAGE_TYPE_ERROR:
        {
            // log error
            diag_log (_compiledResponse select 1);
            
            // handle error, do something terrible like set the server on fire

            // return some information
            _return = "error";
        };
    };
};

_return