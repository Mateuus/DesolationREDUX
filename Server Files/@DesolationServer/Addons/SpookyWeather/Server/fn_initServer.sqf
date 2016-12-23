/*
	Spooky Weather Init
*/
_fogValue = parseNumber (["FogValue","SW"] call BASE_fnc_getCfgValue);


0 setFog _fogValue;
forceWeatherChange;
999999 setFog _fogValue;