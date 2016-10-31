/*
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/


_dThirst = 1/18; //--- (100 total thirst) (30 min till dehyration)

if(diag_tickTime > (DS_var_lastDrank + 3600)) then { // 1 hour grace period
	DS_var_Thirst = DS_var_Thirst - _dThirst;
	if(!DS_var_isDehydrating) then {
		DS_var_isDehydrating = true;
	};
} else {
	if(DS_var_isDehydrating) then {
		DS_var_isDehydrating = false;
	};
};