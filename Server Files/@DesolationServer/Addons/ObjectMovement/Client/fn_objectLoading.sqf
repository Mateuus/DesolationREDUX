_vehicle = _this select 0;
_actionRadius = sizeOf (typeOf _vehicle);
_firstTimeRun = _this select 1;


if (_firstTimeRun) then {
_vehicle setvariable ["vehicleLoad",0,false];
};

_vehicle addAction ["Enable Loading",{_this call SOM_objectLocking;},nil,6,true,true,"","_this distance2D _target < (sizeOf (typeOf _this))+(0.5 * (sizeOf (typeOf _this))) && (vehicle player == player) && ((velocity _this)select 0 < 0.1) && ((velocity _this)select 1 < 0.1) && ((velocity _this)select 2 < 0.1) && (!(player getVariable 'SOM_loadingVehicle'))&&(!(player getVariable 'SOM_liftingObject'))"];