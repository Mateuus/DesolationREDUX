


if !(player getVariable "OM_liftingObject") then 
{
	_object = cursorObject;
	if !(typeOf _object in DS_liftableObjectsBlacklist) then
	{
		_maxMass = getNumber(missionconfigFile >> "DS_ObjectMovement_Settings" >> "maxLiftMass");
		if !( _maxMass < (getMass _object))then {
		_object setOwner (owner player);
		
		_maxDistToObject = getNumber(missionconfigFile >> "DS_ObjectMovement_Settings" >> "maxObjectDistance"); //max 2D distance from player to object before the object is detached.
		_lagComp = getNumber(missionconfigFile >> "DS_ObjectMovement_Settings" >> "lagCompensationCoefficent");
		_rotSpeed = getNumber(missionconfigFile >> "DS_ObjectMovement_Settings" >> "object_rotationSpeed");
		_speedPushPull = getNumber(missionconfigFile >> "DS_ObjectMovement_Settings" >> "object_speedPushPull");
		_speedUp = getNumber(missionconfigFile  >> "DS_ObjectMovement_Settings" >> "object_liftSpeed");
		_speedDown = - getNumber(missionconfigFile  >> "DS_ObjectMovement_Settings" >> "object_liftSpeed");
		_maxheight = getNumber(missionconfigFile  >> "DS_ObjectMovement_Settings" >> "object_maxHeight");
		_maxCarryDistance = 3;
		_maxCollisionForce = 0.5;

		_paramArray = [_object,_maxDistToObject,_lagComp,_rotSpeed,_speedPushPull,_speedUp,_speedDown,_maxheight,_maxCarryDistance,_maxCollisionForce];
		
		
		
		_paramArray call DS_fnc_OM_liftObject;
		};
		_object = objNull;
	};
};
false