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
private["_playerObj","_dbCallback"];
//--- player is requesting to spawn in, ask the database how they should do it
_playerObj = _this select 0;
_playerObj hideObjectGlobal true;
_playerObj setVariable ["DDATA",_this select 1];

_dbCallback = "DS_fnc_dbOnSpawnResponse";
["spawnPlayer",_dbCallback,[_playerObj]] call DS_fnc_dbRequest; //--- send request to database