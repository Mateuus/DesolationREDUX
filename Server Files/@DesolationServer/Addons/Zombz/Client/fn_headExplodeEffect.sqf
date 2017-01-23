/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

private ["_zombieID","_zombieAgent","_pArray","_meat","_blood"];
_zombieID = _this select 0;
_zombieAgent = objectFromNetId _zombieID;
if !(isNull _zombieAgent) then
{ 
	_zombieAgent setFace "SM_ZombzNoFace";

	_pArray = [];

	for "_i" from 0 to 2 do
	{
		_meat = "#particlesource" createVehicleLocal (getposATL _zombieAgent); 
		_meat setParticleClass "HeadMeat1"; 
		_meat setParticleParams	[["\A3\data_f\ParticleEffects\Universal\Meat_ca", 1, 0, 1],"","SpaceObject",1,5,[0, 0, 0],[0.2,0.2,2],2, 22, 1, 0.2,[4],[[0.9,0.01,0.01,1]],[0.1],0.00,0.0,"","","",0,false,0.0];
		_meat setParticleRandom [0, [0.1, 0.1, 0.0], [1.35, 1.35, 1.0], 0, 0.1, [0, 0, 0, 0], 0, 0];
		_meat setDropInterval 60;
		_meat attachTo [_zombieAgent, [0,0,0.2], "head"]; 
		_pArray pushBack _meat;
	};

	_blood = "#particlesource" createVehicleLocal (getposATL _zombieAgent); 
	_blood setParticleClass "HeadBlood1"; 
	_blood setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 4, 1],"","Billboard",1, 0.3,[0, 0, 0],[0.00,0.0,2],1, 0.127, 0.1, 0.4,[0.5,1],[[1,0,0,0.9],[1,0,0,0.45]],[0.1],0.0,0.0,"","","",0,false,0.0 ];
	_blood setDropInterval 60;
	_blood attachTo [_zombieAgent, [0,0,0.2], "head"]; 
	_pArray pushback _blood;

	// Heh
	_pArray spawn
	{
		uiSleep 5;
		{
			deleteVehicle _x;
			true
		} count _this;
	};
};

true
