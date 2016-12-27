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