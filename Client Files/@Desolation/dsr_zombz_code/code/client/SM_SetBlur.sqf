/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

"dynamicblur" ppEffectEnable true;
"dynamicblur" ppEffectAdjust [1];
"dynamicblur" ppEffectCommit 0;
"dynamicblur" ppEffectAdjust [0];
"dynamicblur" ppEffectCommit (1 + random 1);

[] call SM_BloodEffect;

if (SM_ExileEnabled) then
{
	ExileClientPlayerIsInCombat = true;
	ExileClientPlayerLastCombatAt = diag_tickTime;
	true call ExileClient_gui_hud_toggleCombatIcon;
};

true
