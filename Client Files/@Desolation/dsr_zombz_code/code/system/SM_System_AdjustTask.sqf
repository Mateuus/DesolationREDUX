/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Not me.
if (SM_System_TasksDelay isEqualTo []) then
{
	SM_System_TasksDelay = [10];
};
SM_System_TasksDelay = SM_System_TasksDelay call BIS_fnc_sortNum;
SM_System_TaskSleep = (((SM_System_TasksDelay select 0) max 0.01) min 5);

true
