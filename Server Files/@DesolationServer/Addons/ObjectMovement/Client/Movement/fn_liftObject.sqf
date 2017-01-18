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

params["_object"];
if !(local _object) then {[_object,player] remoteExecCall ["OM_fnc_serverLift",2]};
if([_object] call OM_fnc_canLift) then {
	OM_var_lifted = _object;
	_object addEventHandler ["EpeContact",{
		OM_var_collisionForce = _this select 4;
	}];
	
	OM_var_EachFrameEH = addMissionEventHandler ["EachFrame",{
		_object = OM_var_lifted;
		
		_maxheight = call compile (["maxHeight","OM"] call BASE_fnc_getCfgValue); 
		_carryDistance = call compile (["carryDistance","OM"] call BASE_fnc_getCfgValue); 
		_speedUp = call compile (["liftSpeed","OM"] call BASE_fnc_getCfgValue);
		_speedDown = -1*(call compile (["liftSpeed","OM"] call BASE_fnc_getCfgValue));
		_lagComp = call compile (["lagComp","OM"] call BASE_fnc_getCfgValue);
		_maxDistToObject = call compile (["maxDistance","OM"] call BASE_fnc_getCfgValue);
		_objectNewVelocityZ = 0.168;
		_speedPushPull = call compile (["moveSpeed","OM"] call BASE_fnc_getCfgValue);
		_maxCollisionForce = call compile (["maxForce","OM"] call BASE_fnc_getCfgValue);
		_rotSpeed = call compile (["rotationSpeed","OM"] call BASE_fnc_getCfgValue);
		
		
		
		if(!isNull _object) then {
			if(OM_var_collisionForce < _maxCollisionForce) then {
				if (((player distance2d _object) > _maxDistToObject) || !(alive player)) exitWith {call OM_fnc_dropObject;};
				
			
				_playerHeight = (getPosATL player) select 2;
				_objectHeight = (getPosATL _object) select 2;
				_weaponPitch = (getCameraViewDirection player) select 2;
				
				_wantedHeight = ((((1 - (_weaponPitch/ -0.985))) * _maxheight)-1) + _playerHeight;
				
				_playerXVelocity = (velocity player) select 0;
				_playerYVelocity = (velocity player) select 1;
				_playerZVelocity = (velocity player) select 2;
				
				_objectZVelocityUp = _speedUp + _playerZVelocity;
				_objectZVelocityDown = _speedDown + _playerZVelocity;
				_objectFaceVector = [-((vectorDir _object)select 0), ((vectorDir _object)select 1),0];
				_objectXVelocity = _playerXVelocity *_lagComp;
				_objectYVelocity = _playerYVelocity *_lagComp;
				_relativeDir = (player getDir _object);
				_shortestAngle = ((((getDir player - _relativeDir) % 360) + 540) % 360) - 180;
				
				if(abs _shortestAngle > 2) then {
					if(_shortestAngle > 0) then {
						_objectXVelocity = _playerXVelocity * _lagComp + (_rotSpeed* -((vectorDir _object)select 1));
						_objectYVelocity = _playerYVelocity * _lagComp  + (_rotSpeed* ((vectorDir _object)select 0)); 
					} else {
						_objectXVelocity = _playerXVelocity * _lagComp + (_rotSpeed*((vectorDir _object)select 1));
						_objectYVelocity = _playerYVelocity * _lagComp + (_rotSpeed* -((vectorDir _object)select 0));
					};
				};
				if (player distance2d _object > _carryDistance) then {
					
					_objectForwardVelocityHolder = [_objectXVelocity,_objectYVelocity,0] vectorAdd [(sin(getDir _object)*_speedPushPull),(cos(getDir _object)*_speedPushPull),0];
					_objectXVelocity = (_objectForwardVelocityHolder)select 0;
					_objectYVelocity =  (_objectForwardVelocityHolder)select 1;
				} else {
					if (player distance2D _object < _carryDistance - 0.1) then {
						_objectForwardVelocityHolder = [_objectXVelocity,_objectYVelocity,0] vectorDiff [(sin(getDir _object)*_speedPushPull),(cos(getDir _object)*_speedPushPull),0];
						_objectXVelocity = (_objectForwardVelocityHolder)select 0;
						_objectYVelocity =  (_objectForwardVelocityHolder)select 1;
					};
				};
				if(abs (_wantedHeight-_objectHeight) > 0.03) then { 
					if (_wantedHeight > (_objectHeight)) then {
						_objectNewVelocityZ  = (_speedUp + _playerZVelocity);
					} else { 
						if(_wantedHeight < (_objectHeight)) then {
							_objectNewVelocityZ = (_speedDown + _playerZVelocity);
						};
					};
				};

				_object setVelocity [_objectXVelocity,_objectYVelocity, _objectNewVelocityZ];


				_object setDir (_object getDir player);

				 
				_object setVelocity [_objectXVelocity,_objectYVelocity, _objectNewVelocityZ];
			
			};
		};
	}];
};