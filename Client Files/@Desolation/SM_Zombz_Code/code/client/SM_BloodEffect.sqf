/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

disableSerialization;

if(SM_CustomScreenEffects) then
{
	_rscLayer = "SM_ScreenEffect" call bis_fnc_rsclayer;
	_rscLayer cutRsc ["SM_ScreenEffect","PLAIN",0.6];
	_display = uinamespace getvariable ["SM_ScreenEffect",displayNull];
	(_display displayCtrl 1200) ctrlSetText (selectRandom SM_ScreenEffects);
	(_display displayCtrl 1200) ctrlSetTextColor [1,1,1,(0.1 min (random 0.45))];
};

[] call SM_ScreenAddBlood;
[] spawn
{
	uiSleep 1.5;
	[] call SM_ScreenRemoveBlood;
	true
};

true
