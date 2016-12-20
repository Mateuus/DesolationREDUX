/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _zombie = _this select 0;

_zombie allowFleeing 0;
_zombie setMimic "safe";
_zombie setBehaviour "CARELESS";
_zombie setCombatMode "RED";
_zombie disableAI "FSM";
_zombie disableAI "COVER";
_zombie disableAI "CHECKVISIBLE";
_zombie disableAI "AUTOCOMBAT";
_zombie disableAI "AUTOTARGET";
_zombie disableAI "TARGET";
_zombie disableAI "AIMINGERROR";
_zombie disableAI "SUPPRESSION";
_zombie setSpeaker "NoVoice";
_zombie setunitpos "UP";
_zombie disableConversation true;

true
