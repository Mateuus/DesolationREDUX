/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Not me.
if !(SM_System_Tasks isEqualTo []) then
{
	{
		_x params ["_delay","_lastRan","_code","_params","_taskID","_presistant"];
		if (SM_System_TaskTimer > ((_lastRan + _delay) - SM_System_TaskSleep)) then
		{
			_params call _code;
			_x set [1, time];
			if !(_presistant) then
			{
				[_taskID] call SM_System_RemoveTask;
			};
		};
	} foreach SM_System_Tasks;
};

//Breaks a lot of shizz
//onEachFrame {};

SM_System_TaskTimer = time;

true
