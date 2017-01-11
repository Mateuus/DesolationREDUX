
params["_object","_unknown","_unlocklockAction"];


_vehicle = _object getVariable "loadableVehicle";
_objectMass =  getNumber(missionConfigFile >> "SOM_liftableObjects" >> (typeOf _object) >> "mass");
_vehicleCurrentLoad = _vehicle getVariable "vehicleLoad";

detach _object; 
_object removeAction _unlocklockAction;
_vehicle setvariable ["vehicleLoad",(_vehicleCurrentLoad - _objectMass),false];
systemChat "Object has been detached";