/*
	fn_dbRequest
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_type","_identifier",["_callback",""],["_callbackParam",[]]];



_prepOutgoing = format ["%1:%2",_type,_identifier];
_preparedQuery = [0, DESOLATIONSERVERRANDOMID, _prepOutgoing] joinString ":";
_playerObj = _callbackParam select 0;
_playerUID = _playerObj getVariable["DSPlayerUID",""];
_playerName = _playerObj getVariable["DSPlayerName",""];
diag_log format["[DesolationDebug] PrepQuery:%1 and preparedQ:%2 and callbackParams:%3",_prepOutgoing,_preparedQuery,_callbackParam];

switch(_type)do{
	case "joinedAlivePlayerCheck":{//-checks aliveplayer table
		_playerAliveCheck = call compile ("extDB2" callExtension _preparedQuery);
		_inAliveDB = _playerAliveCheck select 1;
		if(_inAliveDB select 0 select 0)then{
			["load",_callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]); 
		}else{
			_type = "joinedPlayerCheck";
			_prepOutgoing = format ["%1:%2",_type,_identifier];
			_preparedQuery = [0, DESOLATIONSERVERRANDOMID, _prepOutgoing] joinString ":";
			_playerCheck = call compile ("extDB2" callExtension _preparedQuery);
			_inDB = _playerCheck select 1;
			diag_log format["playercheck for account _playerCheck:%1 | _inDB:%2, answer:%3",_playerCheck,_inDB,_inDB select 0 select 0];
			if(_inDB select 0 select 0)then{
				_type = "addNewAlivePlayer";
				_prepOutgoing = format ["%1:%2:%3",_type,_identifier,_playerName];
				_preparedQuery = [0, DESOLATIONSERVERRANDOMID,_prepOutgoing] joinString ":";
				call compile ("extDB2" callExtension _preparedQuery);
				["fresh", _callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
			}else{
				_type = "addNewAcctPlayer";
				_prepOutgoing = format ["%1:%2:%3",_type,_identifier,_playerName];
				_preparedQuery = [0, DESOLATIONSERVERRANDOMID,_prepOutgoing] joinString ":";
				call compile ("extDB2" callExtension _preparedQuery);
				_type = "addNewAlivePlayer";
				_prepOutgoing = format ["%1:%2:%3",_type,_identifier,_playerName];
				_preparedQuery = [0, DESOLATIONSERVERRANDOMID,_prepOutgoing] joinString ":";
				call compile ("extDB2" callExtension _preparedQuery);
				["fresh", _callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
			};
		};
	};
	case "loadMyPlayerStats":{
		//diag_log format["[DesolationDebug] Server loadingplayerstats preparedQ:%1",_preparedQuery];
		_loadPlayer = call compile ("extDB2" callExtension _preparedQuery);
		//diag_log format["[DesolationDebug] loadingplayerstats loadplayer:%1",_loadPlayer];
		[_loadPlayer,_callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
	};
	case "updateMyPlayer":{
		
		_prepOutgoing = format ["%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11:%12:%13:%14:%15:%16:%17",_type,_callbackParam select 1,_callbackParam select 2,_callbackParam select 3,_callbackParam select 4,_callbackParam select 5,_callbackParam select 6,_callbackParam select 7,_callbackParam select 8,_callbackParam select 9,_callbackParam select 10,_callbackParam select 11,_callbackParam select 12,_callbackParam select 13,_callbackParam select 14,_callbackParam select 15, _playerUID];
		_preparedQuery = [1, DESOLATIONSERVERRANDOMID, _prepOutgoing] joinString ":";
		//diag_log format["[DesolationDebug] Server updatemyplayer preparedQ:%1",_preparedQuery];
		call compile ("extDB2" callExtension _preparedQuery);
		//do nothing back to client or send a yes to verify stats updated?
	};
	case "onPlayerKilled":{
		//diag_log format["[DesolationDebug] dbRequest preparedQ:%1",_preparedQuery];
		call compile ("extDB2" callExtension _preparedQuery);
	};
	case "deleteAlivePlayer":{
		//diag_log format["[DesolationDebug] dbRequest preparedQ:%1",_preparedQuery];
		call compile ("extDB2" callExtension _preparedQuery);
	};
	case "claimVehicle":{
		_prepOutgoing = format ["%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11",_type,_callbackParam select 1,_callbackParam select 2,_callbackParam select 3,_callbackParam select 4,_callbackParam select 5,_callbackParam select 6,_callbackParam select 7,_callbackParam select 8,_callbackParam select 9,_callbackParam select 10];
		_preparedQuery = [1, DESOLATIONSERVERRANDOMID, _prepOutgoing] joinString ":";
		diag_log format["[DesolationDebug] dbRequest claim vehicle preparedQ:%1",_preparedQuery];
		call compile ("extDB2" callExtension _preparedQuery);
	};
};