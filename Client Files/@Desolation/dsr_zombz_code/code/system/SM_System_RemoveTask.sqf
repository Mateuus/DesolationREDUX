/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Not me.
params[["_id", 0],"_result","_threadIndex"];
_result = false;
_threadIndex = [SM_System_Tasks, _id] call SM_System_FindTask;
if !(_threadIndex isEqualTo -1) then
{
	SM_System_TasksDelay deleteAt (SM_System_TasksDelay find ((SM_System_Tasks select _threadIndex) select 0));
	[] call SM_System_AdjustTask;
	SM_System_Tasks deleteAt _threadIndex;
	_result = true;
};

_result
