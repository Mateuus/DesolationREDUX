/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private["_player","_inTown","_town","_pos","_sizeX","_sizeY","_posX","_posY","_tPosX","_tPosY","_dif","_dif1","_sizeX1","_sizeY1"];

if !(SM_TownSearchEnabled) exitWith { false };

_player = _this;
_inTown = false;
{
    _town = text _x;
    _pos = getArray (configFile >> "CfgWorlds" >> worldName >> "Names" >> _town >> "position");
    if !(_pos isEqualTo []) then
    {
        _sizeX = (getNumber (configFile >> "CfgWorlds" >> worldName >> "Names" >> _town >> "radiusA")) / 2;
        _sizeY = (getNumber (configFile >> "CfgWorlds" >> worldName >> "Names" >> _town >> "radiusB")) / 1.5;
        _posX = (getPos _player) select 0;
        _posY = (getPos _player) select 1;
        _tPosX = _pos select 0;
        _tPosY = _pos select 1;
        _dif = _posX - _tPosX;
        _dif1 = _posY - _tPosY;
        _sizeX1 = (_sizeX - _sizeX) - _sizeX;
        _sizeY1 = (_sizeY - _sizeY) - _sizeY;
        if (((_dif <= _sizeX) && (_dif >= _sizeX1)) && ((_dif1 <= _sizeY) && (_dif1 >= _sizeY1))) then
        {
            _inTown = true;
        };
    };
} forEach nearestLocations [getPos _player, SM_TownSearchTypes, SM_SearchForTownRadius];

_inTown
