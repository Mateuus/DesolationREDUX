_vehicle = _this select 0;
_detectionRadius = sizeOf (typeOf _vehicle);

_lockableObjects = nearestObjects [getpos _vehicle, SOM_loadableObjects, _detectionRadius];
_vehicle removeAction (_this select 2);
 player setVariable ["SOM_loadingVehicle", true ,false];

_disableLoadingAction = _vehicle addAction [ "Disable Loading", {player setVariable ["SOM_loadingVehicle", false ,false];},nil,6,true,true,"","(_this distance2D player < (sizeOf (typeOf _this))+(0.5 * (sizeOf (typeOf _this)))) && (vehicle player == player) && (player getVariable 'SOM_loadingVehicle')"];


_lockableObjects = nearestObjects [getpos _vehicle, SOM_loadableObjects, _detectionRadius];
{

	if (((getpos _x)select 2) > 0.1) then
	{
	
	_x setvariable ["loadableVehicle",_vehicle,false];
		if (isnull(attachedTo _x)) then 
		{
		_lockObjectAction = _x addAction ["Lock Object",{_this call SOM_lockObject;},nil,6,true,true,"","(_this distance2D _target < 4.5) && (vehicle player == player)&&(!(player getVariable 'SOM_liftingObject'))"];
		_x setVariable ["SOM_cargolockOption", _lockObjectAction,false];
		}else 
		{
		_x removeaction _lockObjectAction;
		_unlockObjectAction = _x addAction ["Unlock Object",{_this call SOM_unlockObject;},nil,6,true,true,"","(_this distance2D _target < 4.5) && (vehicle player == player)"];
		_x setVariable ["SOM_cargoUnlockOption", _unlockObjectAction,false];
	};
};
}foreach _lockableObjects;

waitUntil {(!(player getVariable "SOM_loadingVehicle") or (player getVariable "SOM_liftingObject"))};
_vehicle removeaction _disableLoadingAction;


{

_x removeaction (_x getvariable "SOM_cargoUnlockOption");
_x removeaction (_x getvariable "SOM_cargolockOption");


}foreach _lockableObjects;


 player setVariable ["SOM_loadingVehicle", false ,false];
[_vehicle,false] call SOM_objectLoading;