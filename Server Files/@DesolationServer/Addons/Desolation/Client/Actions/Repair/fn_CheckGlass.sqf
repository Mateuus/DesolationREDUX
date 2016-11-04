_hitpoints = getAllHitPointsDamage _cursor;
_names = _hitpoints select 0;
_values = _hitpoints select 2;
_damaged = false;
{
	if((toLower(_x) find "hit" != -1) && (toLower(_x) find "glass") != -1) then {
		_value = _values select _forEachIndex;
		if(_value > 0) exitWith {
			_damaged = true;
		};
	};
} forEach _names;
_damaged;