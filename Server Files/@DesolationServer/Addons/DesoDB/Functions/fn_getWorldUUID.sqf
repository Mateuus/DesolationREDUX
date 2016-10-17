

_WORLD_UUID = getText(missionConfigFile >> "DB_WorldUUID");
if(_WORLD_UUID == "") then {
	diag_log "==== DESOLATION DB ERROR ====";
	diag_log "No World UUID defined in Description.ext";
	diag_log "Make sure the Description.ext has: ";
	diag_log "        DB_WorldUUID = ""Your DB World ID Here"";";
	diag_log "Where 'Your DB World ID Here' is the ID of your world";
	diag_log "==== DESOLATION DB ERROR ====";
};
if(_WORLD_UUID find "0x" == 0) then {
	_WORLD_UUID = _WORLD_UUID select [2];
};
_WORLD_UUID;