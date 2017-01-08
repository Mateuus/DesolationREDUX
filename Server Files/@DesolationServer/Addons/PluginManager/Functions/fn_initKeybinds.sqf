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

KEYBIND_DATA = [];
 
_config = configFile >> "CfgPluginKeybinds";
for "_i" from 0 to count(_config)-1 do {
	_entry = _config select _i;
	if(isClass _entry) then {
		KEYBIND_DATA pushback [
			getText(_entry >> "displayName"),
			getText(_entry >> "tag"),
			getText(_entry >> "variable"),
			getArray(_entry >> "defaultKeys"),
			getText(_entry >> "tooltip"),
			getText(_entry >> "code")
			
		];
	};
};

publicvariable "KEYBIND_DATA";