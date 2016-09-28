/*
	fn_onThirstTick

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_dThirst = 1/9; //--- 900s to dehydrate to death (100 total hunger)

if(diag_tickTime > (DS_var_lastDrank + 300)) then {
	DS_var_Hunger = DS_var_Hunger - _dThirst;
};	