params["_object"];
_mass = getMass _object;
((_mass > 0) && (_mass <= (call compile (["maxMass","OM"] call BASE_fnc_getCfgValue))));