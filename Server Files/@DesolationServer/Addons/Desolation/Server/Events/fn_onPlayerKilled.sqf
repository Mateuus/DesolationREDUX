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
params["_unit","_killer"];

//--- if they didn't disconnect, they died
if !(_unit getVariable ["DCed",false]) then {
	NULL_CALLBACK = compileFinal "";
	["killPlayer","NULL_CALLBACK",[_unit,_killer]] spawn DS_fnc_dbRequest; //--- send request to database
};