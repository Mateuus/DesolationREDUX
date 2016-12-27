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

params["_sourcesinfo"];
// each bleed source / level increases loss by 5 per second

_numLevels = 0;

{
	_lvl = _x select 0;
	_numLevels = _numLevels + _lvl;
} forEach _sourcesinfo;

_tickLoss = (_numLevels^2) * 5;

DS_var_Blood = DS_var_Blood - _tickLoss;



// 5.5L of blood in the body
// 20% = feels weak (can't run, may stumble)
// 35% = falling unconscious
// 50% = death
// so players can lose 2.75L of blood till they die
// so the logical standpoint is to have their blood be 27500 and when it reaches 0 they die