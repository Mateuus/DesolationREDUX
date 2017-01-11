
DS_VehicleBlacklist = [];
DS_liftableObjectsBlacklist = [];


_objectBlacklist = "true" configClasses (configFile >> "CfgObjectMovement" >> "CfgObjectBlacklist");
_vehicleBlacklist = "true" configClasses (configFile >> "CfgObjectMovement" >> "CfgVehicleBlacklist");
{
    DS_VehicleBlacklist pushBack (configName _x);
} foreach _vehicleBlacklist;
{
    DS_liftableObjectsBlacklist pushBack (configName _x);
} foreach _objectBlacklist;


publicVariable "DS_VehicleBlacklist";
publicVariable "DS_liftableObjectsBlacklist";
