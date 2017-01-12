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

#include "..\constants.hpp"

params["_player"];
private["_request", "_response", "_objectList", "_objectUUID",  "_parentObjectUUID",  "_classname",  "_priority",  "_visible",  "_accesscode",  "_locked",  "_player_uuid",  "_hitpoints",  "_damage",  "_fuel",  "_fuelcargo",  "_repaircargo",  "_items",  "_magazines",  "_weapons",  "_backpacks",  "_magazinesturret",  "_variables",  "_animationstate",  "_textures",  "_direction",  "_positiontype",  "_positionx",  "_positiony",  "_positionz",  "_friendlist", "_vehicle", "_hitpointsPoints", "_hitpointsValues", "_items", "_itemValue", "_magazineList", "_magazineValue", "_weaponsList", "_weaponsValue", "_backpacksList", "_backpacksValue"];

_request = [ "{ 'dllFunction': '", PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL, "', 'dllArguments': {  'dbfunction': '", PROTOCOL_DBCALL_FUNCTION_DUMP_OBJECTS, "', 'dbarguments': {  } } }" ] joinString "";

_response = _request call DS_fnc_Send_Request;

_objectList = _resonse select 0;
_spawnedObjects = [];
_remainingObjects = [];

{
    _objectUUID = _x select 0;
    _parentObjectUUID = _x select 1;
    _classname = _x select 2;
    _priority = _x select 3;
    _visible = _x select 4;
    _accesscode = _x select 5;
    _locked = _x select 6;
    _player_uuid = _x select 7;
    _hitpoints = _x select 8;
    _damage = _x select 9;
    _fuel = _x select 10;
    _fuelcargo = _x select 11;
    _repaircargo = _x select 12;
    _items = _x select 13;
    _magazines = _x select 14;
    _weapons = _x select 15;
    _backpacks = _x select 16;
    _magazinesturret = _x select 17;
    _variables = _x select 18;
    _animationstate = _x select 19;
    _textures = _x select 20;
    _direction = _x select 21;
    _positiontype = _x select 22;
    _positionx = _x select 23;
    _positiony = _x select 24;
    _positionz = _x select 25;
    _friendlist = _x select 26;

    if ((_parentObjectUUID == "") or (_parentObjectUUID in _spawnedObjects)) then {

        _vehicle = _classname createVehicle [_positionx, _positiony, _positionz];
        // if _positiontype = 0 then ...
        _vehicle setPosASL [_positionx, _positiony, _positionz];
        _vehicle setdir _direction;

        if (_locked) then {
            _vehicle setVehicleLock "LOCKED";
        } else {
            _vehicle setVehicleLock "UNLOCKED";
        }

        if (_hitpoints != [] && _hitpoints != "") then {
            _hitpointsPoints = _hitpoints select 0;
            _hitpointsValues = _hitpoints select 2;
            {
                _value = _hitpointsValues select _forEachIndex;
                if(_x != "" && _x != "HitFuel" && _x != "HitFuelTank" && _x != "HitBody") then {
                    _vehicle setHitPointDamage [_x, _value];
                };
                if(_x == "HitBody") then {
                    if (_value > 0.5) {
                        _value = 0.5;
                    }
                    _vehicle setHitPointDamage [_x,_value];
                };
            } forEach _hitpointsPoints;
        };
        _vehicle setDamage _damage;

        _vehicle setFuel _fuel;
        _vehicle setFuelCargo _fuelcargo;
        _vehicle setRepairCargo _repaircargo;

        if (_accesscode != "") then {
            _vehicle setVariable ["accesscode", _accesscode];
        }

        if (_player_uuid != "") then {
            _vehicle setVariable ["player_uuid", _player_uuid];
        }

        if (_friendlist != [] && _friendlist != "") then {
            _vehicle setVariable ["friendlist", _friendlist];
        };

        if (_variables != [] && _variables != "") then {
            {
                if(_x select 0 != "") then {
                    _vehicle setVariable [_x select 0, _x select 1];
                };
                /*
                 * if advanced vector stuff, set vectors
                 */
            } forEach _variables;
        };

        if (_animationstate != [] && _animationstate != "") then {
            {
                if(_x select 0 != "") then {
                    _vehicle animate [_x select 0, _x select 1];
                };
            } forEach _animationstate;
        };

        if (_textures != [] && _textures != "") then {
            {
                if(_x select 0 != "") then {
                    _vehicle setObjectTexture [_x select 0, _x select 1];
                };
            } forEach _textures;
        };

        clearItemCargo _vehicle;
        clearMagazineCargo _vehicle;
        clearWeaponCargo _vehicle;
        clearBackpackCargo _vehicle;

        if (_items != [] && _items != "") then {
            _itemList = _items select 0;
            _itemValue = _items select 1;
            {
                _value = _itemValue select _forEachIndex;
                if(_x != "") then {
                    _vehicle addItemCargo [_x, _value];
                };
            } forEach _itemList;
        };

        if (_magazines != [] && _magazines != "") then {
            _magazinesList = _magazines select 0;
            _magazinesValue = _magazines select 1;
            {
                _value = _magazinesValue select _forEachIndex;
                if(_x != "") then {
                    _vehicle addMagazineCargo [_x, _value];
                };
            } forEach _magazinesList;
        };

        if (_weapons != [] && _weapons != "") then {
            _weaponsList = _weapons select 0;
            _weaponsValue = _weapons select 1;
            {
                _value = _weaponsValue select _forEachIndex;
                if(_x != "") then {
                    _vehicle addWeaponCargo [_x, _value];
                };
            } forEach _weaponsList;
        };

        if (_backpacks != [] && _backpacks != "") then {
            _backpacksList = _backpacks select 0;
            _backpacksValue = _backpacks select 1;
            {
                _value = _backpacksValue select _forEachIndex;
                if(_x != "") then {
                    _vehicle addBackpackCargo [_x, _value];
                };
            } forEach _backpacksList;
        }

        /*
         * set turret magazines from _magazinesturret
         */
        
        /*
         * search parent object and attach _vehicle to it
         */
        _arrayOne pushBack _objectUUID;
    } else {
        _remainingObjects pushBack _objectUUID;
    }
}
forEach _objectList;

/*
 * iterate ofer the _remainingObjects and spawn the missing objects until everything is spawned
 */