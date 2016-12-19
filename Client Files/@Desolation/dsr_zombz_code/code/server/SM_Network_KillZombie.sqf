/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _zombie = objectFromNetId _this;

if (isNull _zombie) exitWith {};
if (isPlayer _zombie) exitWith {};
if !(_zombie isKindOf "SM_Zombz_Base") exitWith {};

deleteVehicle _zombie;

true
