/*
	Automatically swap people talking in side chat into direct chat
*/
params["_player"];

_player setUnitRecoilCoefficient (call compile (["Recoil","RSM"] call BASE_fnc_getCfgValue));
_player setCustomAimCoef (call compile (["Sway_Multiplier","RSM"] call BASE_fnc_getCfgValue));