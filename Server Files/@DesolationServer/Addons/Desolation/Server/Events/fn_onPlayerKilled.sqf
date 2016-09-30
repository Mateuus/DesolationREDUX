/*
	fn_onPlayerKilled
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_unit","_killer"];

_unit spawn {
	waitUntil{speed _unit < 1};
	// TODO: create a blood pile below the body
};