/*
	fn_onEat

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
params["_hungerChange"];
DS_var_lastAte = diag_tickTime;
DS_var_Hunger = (DS_var_Hunger + _hungerChange) min 100;