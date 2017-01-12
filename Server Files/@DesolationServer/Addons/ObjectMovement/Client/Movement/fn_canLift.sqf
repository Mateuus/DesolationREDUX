params["_object"];
_mass = getMass _object;
_type = typeof _object;
(!(_type isKindOf "Static") && !(_type isKindOf "Man") && (_mass <= (call compile (["maxMass","OM"] call BASE_fnc_getCfgValue))));