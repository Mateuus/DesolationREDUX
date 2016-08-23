/*
	fn_dbRequest
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

params["_type","_identifier",["_callback",""],["_callbackParam",[]]];

switch(_type)do{
	case "requestSpawnType":{
		_playerObj = _callbackParam select 0;
		
		["fresh", _callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
	};
	case "requestPlayerData":{
		
		_data = [];
		
		[_data,_callbackParam] call (missionNamespace getVariable [_callback,{diag_log "<REQUEST ERROR>: callback not defined?";}]);
	};
	case "updateMyPlayer":{
		diag_log "Update request received";
	};
	case "onPlayerKilled":{
		diag_log "Kill player request received";
	};
	case "deleteAlivePlayer":{
		
		diag_log "What the fuck is this for sanchez????";
		
	};
	case "claimVehicle":{
		diag_log "Vehicle claim received";
	};
};