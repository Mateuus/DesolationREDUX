/*
	fn_onEffectTick

	Desolation Redux
	2016 Desolation Dev Team

	License info here and copyright symbol above
*/
if(DS_var_Blood <= 0) then {
	player setDamage 1;
} else {
	_bloodPercent = (DS_var_Blood*2)/55000;
	if(_bloodPercent < 50) then {
		diag_log "BLOOD ERROR WAT THE FUK???";
	} else {
		if(_bloodPercent < 65) then {
			if(random(100) < 5) then {
				_lvl = 65 - _bloodPercent;
				_timer = ceil((20 / 15) * _lvl);
				[_timer] spawn ds_fnc_knockOut;					
			};
			
		} else {
			if(_bloodPercent < 80) then {
				if(random(100) < 10) then {
					systemchat "Debug: I feel weak";
				};
			};
		};
	};	
};