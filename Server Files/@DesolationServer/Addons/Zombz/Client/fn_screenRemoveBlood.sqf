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

disableSerialization;

_display = uinamespace getVariable ["SM_RscHealthTextures", displayNull];

if (isNull _display) exitWith {};

_lower = _display displayctrl 1211;
_middle = _display displayctrl 1212;
_upper = _display displayctrl 1213;
_left = _display displayCtrl 1214;
_right = _display displayCtrl 1215; 

_lower ctrlsetfade 1;
_middle ctrlsetfade 1;
_upper ctrlsetfade 1;
_left ctrlSetFade 1;
_right ctrlSetFade 1;

_upper ctrlcommit 1.5;
_middle ctrlcommit 1;
_lower ctrlcommit 0.8;
_left ctrlCommit 1;
_right ctrlCommit 1;

true
