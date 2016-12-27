/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

params ["_zombie", "_unit", ["_offset", 0]];

((((_zombie worldToModel getPos _unit) select 1) - _offset > 0) && if !((_zombie distance _unit) >= 35) then {[vehicle _unit, "VIEW", _zombie] checkVisibility [eyePos vehicle _unit, eyePos _zombie] > 0} else { true })
