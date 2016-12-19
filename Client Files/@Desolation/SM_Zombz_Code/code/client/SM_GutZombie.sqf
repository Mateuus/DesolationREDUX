/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _zombie = _this;

["GutVariable",(netID _zombie)] call SM_Network_SendMessage;

player switchMove "AinvPknlMstpSlayWrflDnon_medic";

if !(player getVariable ["SM_HasZombieGuts", false]) then
{
	[] call SM_ScreenAddBlood;
};

uiSleep 6;

if !(player getVariable ["SM_HasZombieGuts", false]) then
{
	[] call SM_ScreenRemoveBlood;
};

["Gut",[(netId _zombie),(netId player)]] call SM_Network_SendMessage;

true
