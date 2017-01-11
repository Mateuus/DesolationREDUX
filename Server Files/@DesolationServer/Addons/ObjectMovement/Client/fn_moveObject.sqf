_paramArray = _this;
_object = _paramArray select 0;

player setVariable ["DSR_Lift_IsColliding",0];

_collisionDetEventId = _object addEventHandler ["EpeContact",{player setVariable ["DSR_Lift_IsColliding",(_this select 4),false]}];




player setVariable ["SOM_liftingObject", true,false];

_SOM_dropObjectAction = player addAction [ "Drop Object", {player setVariable ["SOM_liftingObject", false ,false];},nil,6,true,true,"",""];

["DS_OM_LiftObjectEVENTID", "onEachFrame", {

	params ["_object","_maxDistToObject","_lagComp","_rotSpeed","_speedPushPull","_speedUp","_speedDown","_maxheight","_maxCarryDistance","_maxCollisionForce"];
	if ((player getvariable "DSR_Lift_IsColliding") < _maxCollisionForce) then {
	_playerHeight = 0;

	_playerHeight = ((getPosATL player)select 2);
	_objectHeight = (getPosATL _object)select 2;
	_objectHeight = _objectHeight;
	_weaponPitch = (getCameraViewDirection player)select 2;
	_wantedHeight = ((((1 - (_weaponPitch/ -0.985))) * _maxheight)-1);//-298.8
	_wantedHeight = _wantedHeight + _playerHeight;
	
	
	_carryDistance = _maxCarryDistance;
	
	systemchat str(_wantedHeight);
	_playerXVelocity = (velocity player)select 0;
	_playerYVelocity = (velocity player)select 1;
	_playerZVelocity = (velocity player)select 2;

	_objectZVelocityUp = _speedUp + _playerZVelocity;
	_objectZVelocityDown = _speedDown + _playerZVelocity;

	_objectFaceVector = [-((vectorDir _object)select 0), ((vectorDir _object)select 1),0];

	_objectXVelocity = _playerXVelocity *_lagComp;
	_objectYVelocity = _playerYVelocity *_lagComp;


	_relativeDir = (player getDir _object);
	_shortestAngle = ((((getDir player - _relativeDir) % 360) + 540) % 360) - 180;  // negative = right. positive = left
	
	
	if(abs _shortestAngle > 2) then
	{
	if(_shortestAngle > 0) then
		{
			_objectXVelocity = _playerXVelocity *_lagComp + (_rotSpeed* -((vectorDir _object)select 1));
			_objectYVelocity = _playerYVelocity *_lagComp  + (_rotSpeed* ((vectorDir _object)select 0));
			
	
	} else
	{
		_objectXVelocity = _playerXVelocity + (_rotSpeed*((vectorDir _object)select 1));
		_objectYVelocity = _playerYVelocity + (_rotSpeed* -((vectorDir _object)select 0));
	};
};

	if ((player distance2d _object) > _maxDistToObject OR !(alive player)) then {player setVariable ["SOM_liftingObject", false,false];};

	

	if (player distance2d _object > _carryDistance) then 
	{
		
		_objectForwardVelocityHolder = [_objectXVelocity,_objectYVelocity,0] vectorAdd [(sin(getDir _object)*_speedPushPull),(cos(getDir _object)*_speedPushPull),0];
		_objectXVelocity = (_objectForwardVelocityHolder)select 0;
		_objectYVelocity =  (_objectForwardVelocityHolder)select 1;
	}else
	{
		if (player distance2D _object < _carryDistance - 0.1) then
		{
		_objectForwardVelocityHolder = [_objectXVelocity,_objectYVelocity,0] vectorDiff [(sin(getDir _object)*_speedPushPull),(cos(getDir _object)*_speedPushPull),0];
		_objectXVelocity = (_objectForwardVelocityHolder)select 0;
		_objectYVelocity =  (_objectForwardVelocityHolder)select 1;
		};
	};

	
	
	_objectNewVelocityZ = 0.168; //antigrav reduce stutter 0.168
	
	
	if(abs (_wantedHeight-_objectHeight) > 0.03) then
	{
	
	if (_wantedHeight > (_objectHeight)) then
	{
		_objectNewVelocityZ  = (_speedUp + _playerZVelocity); //change to a value multiplied by vertical distance and clamped
	} else 
	{ 
		if(_wantedHeight < (_objectHeight)) then 
		{
			_objectNewVelocityZ = (_speedDown + _playerZVelocity);
		};
	};
	};
	
	

	_object setVelocity [_objectXVelocity,_objectYVelocity, _objectNewVelocityZ];


	_object setDir (_object getDir player);

	 
	_object setVelocity [_objectXVelocity,_objectYVelocity, _objectNewVelocityZ];

	
	
	
	
	};
},_paramArray] call BIS_fnc_addStackedEventHandler;

waitUntil {!(player getVariable "SOM_liftingObject")};
systemchat "test5";
["DS_OM_LiftObjectEVENTID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
_object removeEventHandler ["EpeContact",_collisionDetEventId];
player removeAction _SOM_dropObjectAction;
player setVariable ["DSR_Lift_IsColliding", nil];
