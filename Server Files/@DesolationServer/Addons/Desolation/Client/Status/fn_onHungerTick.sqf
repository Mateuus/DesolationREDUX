/*
	fn_onHungerTick

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
_dHunger = 1/90; //--- (100 total hunger) (2.5 hours till starvation)

if(diag_tickTime > (DS_var_lastAte + 5400)) then { // 1.5 hour grace
	DS_var_Hunger = DS_var_Hunger - _dHunger;
	if(!DS_var_isStarving) then {
		DS_var_isStarving = true;
	};
} else {
	if(DS_var_isStarving) then {
		DS_var_isStarving = true;
	};
};