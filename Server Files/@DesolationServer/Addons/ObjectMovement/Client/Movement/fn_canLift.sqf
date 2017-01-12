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

params["_object"];
_mass = getMass _object;
_type = typeof _object;
(!(_type isKindOf "Static") && !(_type isKindOf "Man") && (_mass <= (call compile (["maxMass","OM"] call BASE_fnc_getCfgValue))));