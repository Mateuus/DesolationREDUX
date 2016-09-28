/*
	fn_onHungerTick

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_dHunger = 1/12; //--- 1200s to starve to death (100 total hunger)

if(diag_tickTime > (DS_var_lastAte + 600)) then {
	DS_var_Hunger = DS_var_Hunger - _dHunger;
};	