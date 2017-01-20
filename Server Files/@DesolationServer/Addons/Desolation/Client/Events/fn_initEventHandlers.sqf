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


player addEventHandler ["HandleDamage",{
	params["_unit","_selectionName","_damage","_shooter","_projectile","_hitPartIndex"];
	
	if(!alive _unit) exitWith {false};
	
	_allowDamage = false;
	_allowArmaDamage = true;
	
	if(_damage > 0.1) then {
		_allowDamage = true;
		
		if(!isNull _shooter) then {
			if(toLower(_projectile) find "b_" == 0) then {
				_allowArmaDamage = false;
				if !(_shooter in DS_var_damagedBy) then {
					DS_var_damagedBy pushBack _shooter;
					
					_bloodLoss = _damage * 27500;
					if(_selectionName != "head") then {
						_bloodLoss = _bloodLoss / 1.5;
					};
					DS_var_Blood = DS_var_Blood - _bloodLoss;
				};
			} else {
				if(_shooter isKindOf "LandVehicle") then {
					_bloodLoss = _damage * 825;
					DS_var_Blood = DS_var_Blood - _bloodLoss;
				} else {
					_bloodLoss = _damage * 8250;
					DS_var_Blood = DS_var_Blood - _bloodLoss;
				};
			};
		} else {
			_bloodLoss = _damage * 13750;
			DS_var_Blood = DS_var_Blood - _bloodLoss;
		};
		if(_selectionName == "legs") then {
			if(!isNil {_damage}) then {
				if(_damage > 0.5) then {
					[] spawn {
						player setHitPointDamage ["HitLegs",1];
					};
				};
			};
		};
		if(_selectionName == "head") then {
			[floor(5 + random(5))] spawn ds_fnc_knockOut;
		};
	};
	((_damage >= 1) && _allowArmaDamage && _allowDamage);
}];
player addEventHandler ["Killed",{
	call DS_fnc_stopBleeding;
	0 cutText ["You are dead","BLACK FADED",10000];
}];
player addEventHandler ["InventoryOpened",{
	DS_var_InvOpen = true;
	[] spawn ds_fnc_setupInvEvents;
	false
}];
player addEventHandler ["InventoryClosed",{
	DS_var_InvOpen = false;
	false
}];
