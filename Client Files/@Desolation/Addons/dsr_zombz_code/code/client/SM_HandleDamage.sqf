/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_victim", objNull],["_selection", ""],["_damage", 0],["_damager", objNull],"_hmd","_headExplode"];

if((_selection isEqualTo "head") && _damage >= 1) then
{
	if !((face _victim) isEqualTo "SM_ZombzNoFace") then 
	{
		_victim setFace "SM_ZombzNoFace";
		["ExplodeHead", [(netId _victim)]] call SM_Network_SendMessage;
	};
};

_damage
