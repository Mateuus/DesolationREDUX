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

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

params ["_zombieAgent"];
_pos = getPosATL _zombieAgent;
_distance = 10;
_dir = random 360;
_distance = random (_distance * 30);

[(_pos select 0) + _distance * sin _dir, (_pos select 1) + _distance * cos _dir, _pos select 2]
