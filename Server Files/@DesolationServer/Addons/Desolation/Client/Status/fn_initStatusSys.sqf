/*
	fn_initStatusSys

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/

//--- TEMP (eventually this will call an FSM that handles EXACTLY what is in this code)
[] spawn {
	DS_var_NextSave = diag_tickTime + 60*5;
	while{alive player} do {
		_time = diag_tickTime;
		waitUntil{diag_tickTime >= (_time+1)};
		if(diag_tickTime >= DS_var_NextSave) then {
			call ds_fnc_saveData;
		};
		call ds_fnc_onTick;
	};
};