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

private _return = [_this,"\a3\ui_f\data\igui\cfg\simpletasks\types\default_ca.paa"];
private _cfg = configFile >> "Cfg3DActions";
for "_i" from 0 to count(_cfg) - 1 do 
{
	if ((_this find (configName (_cfg select _i))) != -1) exitWith {_return = getArray(_cfg select _i);};
};
_return