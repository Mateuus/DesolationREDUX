/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

_maxFatigue = 0;
 
 
if(DS_var_Blood <= 0) then {
	player setDamage 1;
} else {

	_bloodPercent = 50 + (DS_var_Blood / 550);
	if(_bloodPercent < 50) then {
		diag_log "Error: Blood falling into the negatives";
	} else {
		if(_bloodPercent < 65) then {
			if(random(100) < 5 && (lifeState player != "INCAPACITATED") && ((diag_tickTime - DS_var_lastKnockout) > 5)) then {
				_lvl = 65 - _bloodPercent;
				_timer = ceil(((20 / 15) * _lvl) + random((10 / 15) * _lvl));
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

//--- regen blood
if(DS_var_Hunger == 100 && DS_var_Thirst == 100 && !DS_var_isBleeding && (DS_var_Blood != 27500) && DS_var_InfectionDOT == 0) then {
	_regenStationary = 1375/36;
	_regenMoving = 725 / 144;
	_regen = _regenMoving;
	if((vehicle player) != player) then {
		_regen = _regenStationary;
	} else {
		if(speed player == 0) then {
			_regen = _regenStationary;
		};
	};
	DS_var_Blood = (DS_var_Blood + _regen) min 25000;
};


//--- starving effects
if(DS_var_isStarving) then {
	_maxFatigue = (1 - (DS_var_Hunger / 100)) max _maxFatigue;
};
//--- dehydrated effects
if(DS_var_isDehydrating) then {
	_maxFatigue = (1 - (DS_var_Thirst / 100)) max _maxFatigue;
};
if(_maxFatigue != 0) then {
	if(getFatigue player < _maxFatigue) then {
		player setFatigue _maxFatigue;
	};
};