params["_object"];
_mass = getMass _object;
(!(typeof(_object) isKindOf "Static") && (_mass <= (call compile (["maxMass","OM"] call BASE_fnc_getCfgValue))));