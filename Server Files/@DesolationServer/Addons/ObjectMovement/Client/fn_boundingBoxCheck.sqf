

params["_object","_vehicle"];

_vehicleBoundingPoint1 = (boundingBoxReal _vehicle)select 1;
_vehicleBoundingPoint2 = (boundingBoxReal _vehicle)select 0;

_vBP1X = (_vehicleBoundingPoint1)select 0;
_vBP1Y = (_vehicleBoundingPoint1)select 1;
_vBP1Z = (_vehicleBoundingPoint1)select 2;

_vBP2X = (_vehicleBoundingPoint2)select 0;
_vBP2Y = (_vehicleBoundingPoint1)select 1;
_vBP2Z = (_vehicleBoundingPoint1)select 2;

_objectPositionVehicleRelative = _vehicle worldToModel (position _object);

_oPVRX = (_objectPositionVehicleRelative)select 0;
_oPVRY = (_objectPositionVehicleRelative)select 1;
_oPVRZ = (_objectPositionVehicleRelative)select 2;

((_vBP1X < _oPVRX) && (_vBP1Y < _oPVRY) && (_vBP1Z < _oPVRZ) && (_oPVRX < _vBP2X) && (_oPVRY < _vBP2Y) && (_oPVRZ < _vBP2Z));