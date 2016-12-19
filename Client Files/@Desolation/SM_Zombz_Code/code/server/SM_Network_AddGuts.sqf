/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _player = objectFromNetId (_this select 0);

_player removeMagazine "SM_Zombz_Item_Heart";

_player setVariable ["SM_HasZombieGuts", true, true];

[SM_ZombieGutsLength,SM_CleanupZombieGuts,[(_this select 0)],false,"Guts Task"] call SM_System_AddTask;

_player setObjectMaterialGlobal [0, "A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat"];

true
