/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Not me.
params[["_interval", 0],["_code", {}],["_params", []],["_persistive", false],["_name", "NotSet"],"_threadID"];
_threadID = SM_System_ThreadID;
SM_System_Tasks pushBack [_interval, time, _code, _params, _threadID, _persistive, _name];
SM_System_TasksDelay pushBack _interval;
[] call SM_System_AdjustTask;
SM_System_Tasks = [SM_System_Tasks, [], {_x select 4}, "ASCEND", {true}] call BIS_fnc_sortBy;
SM_System_ThreadID = SM_System_ThreadID + 1;

_threadID
