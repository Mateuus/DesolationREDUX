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
CFG_BUILDABLES = [];
_config = configFile >> "CfgBuildables";
for "_i" from 0 to count(_config)-1 do {
	_entry = _config select _i;
	if(isClass _entry) then {
		_data = [
			["parts",getArray(_entry >> "parts")],
			["name",getText(_entry >> "name")],
			["condition",getText(_entry >> "condition")],
			["description",getText(_entry >> "description")],
			["model",getText(_entry >> "model")],
			["preview",getText(_entry >> "preview")]
		];
		CFG_BUILDABLES pushBack _data;
	};
};
publicVariable "CFG_BUILDABLES";