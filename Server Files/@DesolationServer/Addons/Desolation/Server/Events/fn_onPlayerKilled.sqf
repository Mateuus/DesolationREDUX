/*
	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params["_unit","_killer"];

//--- if they didn't disconnect, they died
if !(_unit getVariable ["DCed",false]) then {
	NULL_CALLBACK = compileFinal "";
	["killPlayer","NULL_CALLBACK",[_unit,_killer]] spawn DS_fnc_dbRequest; //--- send request to database
};