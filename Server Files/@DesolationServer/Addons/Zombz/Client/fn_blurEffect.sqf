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

"dynamicblur" ppEffectEnable true;
"dynamicblur" ppEffectAdjust [1];
"dynamicblur" ppEffectCommit 0;
"dynamicblur" ppEffectAdjust [0];
"dynamicblur" ppEffectCommit (1 + random 1);

[] call SM_fnc_bloodEffect;