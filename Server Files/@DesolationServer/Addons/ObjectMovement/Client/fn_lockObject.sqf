

params["_object","_unknown","_lockAction"];

_vehicle = _object getVariable "loadableVehicle";
_vehicleMaxLoad =  getNumber(missionConfigFile >> "SOM_loadableVehicles" >> (typeOf _vehicle) >> "capacity");
_objectMass =  getNumber(missionConfigFile >> "SOM_liftableObjects" >> (typeOf _object) >> "mass");
_vehicleCurrentLoad = _vehicle getVariable "vehicleLoad";


if ((_objectMass+_vehicleCurrentLoad) <= _vehicleMaxLoad) then 
{
	_object enableRopeAttach false;
	_objectDir = getDir _object;
	_objectAttachmentPos = _vehicle WorldToModel position _object Vectoradd [0,0,0.44];
	_object attachto [_vehicle, _objectAttachmentPos];
	_object setDir _objectDir;
	_object removeAction _lockAction;
	_vehicle setvariable ["vehicleLoad",(_vehicleCurrentLoad + _objectMass),false];
	systemChat "Object has been attached";
} else {
	systemChat "Object cannot be attached: Not enough space!";
};