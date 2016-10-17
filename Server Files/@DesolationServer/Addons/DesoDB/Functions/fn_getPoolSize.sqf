

_POOL_SIZE = getNumber(missionConfigFile >> "DB_PoolSize");
if(_POOL_SIZE == 0) then {
	diag_log "==== DESOLATION DB ERROR ====";
	diag_log "No POOL SIZE defined in Description.ext";
	diag_log "Make sure the Description.ext has: ";
	diag_log "        DB_PoolSize = [pool count]";
	diag_log "Where '[pool count]' is the # of pool threads (1-infinity)";
	diag_log "==== DESOLATION DB ERROR ====";
};
if(_POOL_SIZE == 0) then {
	_POOL_SIZE = 4;
};
_POOL_SIZE;