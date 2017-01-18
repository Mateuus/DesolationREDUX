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
params["_crate"];

_entry = _crate getVariable "SVAR_buildParams";
_model = _entry select 2;
diag_log _model;

_pos = getposatl _crate;
_dir = getdir _crate;

deleteVehicle _crate;


_obj = _model createVehicle _pos;
_obj setdir _dir;
_obj setposatl _pos;

