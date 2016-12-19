/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private ["_zombie","_face","_group"];
_zombie = _this;

if (isServer) then
{
	_zombie addMPEventHandler ["MPKilled",{ if !(isServer) exitWith {};	_this call SM_MPKilled}];

	if (_Zombie isKindOf "SM_Zombz_FemaleBase") then
	{
		_face = selectRandom SM_FaceFemaleArray;
		[_zombie, _face] remoteExecCall ["setFace", 0, _zombie];
	}
	else
	{
		_face = selectRandom SM_FacesArray;
		[_zombie, _face] remoteExecCall ["setFace", 0, _zombie];
	};

	removegoggles _zombie;
	_zombie setdamage SM_ZombieHealth;
	_zombie setDir (random 360);
	_zombie setAnimSpeedCoef (random 1);

	_zombie setHitIndex [10, 0];
	_zombie setHitPointDamage ["hitLegs", 0];

	_headGear = getText (configFile >> "CfgVehicles" >> (typeOf _zombie) >> "headgear");
	if !(_headGear isEqualTo "") then
	{
		_zombie addHeadgear _headGear;
	};
};

[_zombie] call SM_DisableAI;

_group = group _zombie;
_group setCombatMode "RED";
_group allowFleeing 0;
_group enableAttack false;

_zombie addEventHandler ["Local",{ _this call SM_DisableAI }];

if (SM_ExplodingHeadEnabled) then
{
	_zombie addEventHandler ["HandleDamage",{ _this call SM_HandleDamage }];
};


true
