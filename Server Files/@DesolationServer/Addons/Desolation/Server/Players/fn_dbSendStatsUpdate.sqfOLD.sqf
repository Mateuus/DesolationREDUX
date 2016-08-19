/*
	fn_dbSendStatsUpdate
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/

//--- player is requesting stats update
_playerObj = _this select 0;
_playerUID = _playerObj getVariable["DSPlayerUID",""];
_playerPOS = getPosATL _playerObj;
_hitpointArray = [];
_getAllHitPoints = getAllHitPointsDamage _playerObj;
for "_i" from 0 to 10 do
{
	_getHitPointNames = _getAllHitPoints select 0 select _i;
	_getHitPointValues = _getAllHitPoints select 2 select _i;
	_hitpointArray pushback [_getHitPointNames,_getHitPointValues];
};
	
_loadedMags = [];
_primaryAmmo = [""];
_secondaryAmmo = [""];
_handgunAmmo = [""];
_uniformMags = [];
_vestMags = [];
_backpackMags = [];
_playerLoadedMags = magazinesAmmoFull _playerObj;
_loadedMagsCount = count(_playerLoadedMags)-1;
for "_l" from 0 to _loadedMagsCount do{
	_magsArray = _playerLoadedMags select _l;
	diag_log format["[DesolationDebug]  updatemyplayer _magsArray:%1",_magsArray];
	_magazine = _magsArray select 0;
	_ammoCount = _magsArray select 1;
	_isLoaded = _magsArray select 2;
	_container = _magsArray select 4;
	if (_isLoaded) then {
		if (_ammoCount > 0) then {
			switch (_magsArray select 3) do {
				case 1: {
					_primaryAmmo = [];
					_loadedMags pushBack [primaryWeapon _playerObj, _magazine, _ammoCount];
					_primaryAmmo pushBack _ammoCount;
				};
				case 2: {
					_handgunAmmo = [];
					_loadedMags pushBack [handgunWeapon _playerObj, _magazine, _ammoCount];
					_handgunAmmo pushBack _ammoCount;
				};
				case 4: {
					_secondaryAmmo = [];
					_loadedMags pushBack [secondaryWeapon _playerObj, _magazine, _ammoCount];
					_secondaryAmmo pushBack _ammoCount;
				};
			};
		};
	};
	switch(_container)do{
		case "Uniform":{
			_uniformMags pushback [_magazine, _ammoCount];
		};
		case "Vest":{
			_vestMags pushback [_magazine, _ammoCount];
		};
		case "Backpack":{
			_backpackMags pushback [_magazine, _ammoCount];
		};
	};
};
_uniformItems = (getItemCargo uniformContainer _playerObj);//[[],[]]
_vestItems = (getItemCargo vestContainer _playerObj);
_backpackItems = (getItemCargo backpackContainer _playerObj);

_uniformWeapons = [];
_uniformWeaponsArray = (getWeaponCargo uniformContainer _playerObj);
_uwNames = _uniformWeaponsArray select 0;
_uwNamesCount = count(_uwNames)-1;
if(_uwNamesCount >= 0)then
{
	for "_a" from 0 to _uwNamesCount do
	{
		_wpnName = _uwNames select _a;
		_uniformWeapons pushback [_wpnName,1];
	};
};
_vestWeapons = [];
_vestWeaponsArray = (getWeaponCargo vestContainer _playerObj);
_vwNames = _vestWeaponsArray select 0;
_vwNamesCount = count(_vwNames)-1;
if(_vwNamesCount >= 0)then
{
	for "_v" from 0 to _vwNamesCount do
	{
		_wpnName = _vwNames select _v;
		_vestWeapons pushback [_wpnName,1];
	};
};
_backpackWeapons = [];
_backpackWeaponsArray = (getWeaponCargo backpackContainer _playerObj);
_bwNames = _backpackWeaponsArray select 0;
_bwNamesCount = count(_bwNames)-1;
if(_bwNamesCount >= 0)then
{
	for "_b" from 0 to _bwNamesCount do
	{
		_wpnName = _bwNames select _b;
		_backpackWeapons pushback [_wpnName,1];
	};
};
_equipmentArray = [[(primaryWeapon _playerObj),(primaryWeaponMagazine _playerObj),(_primaryAmmo select 0),(primaryWeaponItems _playerObj)],[(secondaryWeapon _playerObj),(secondaryWeaponMagazine _playerObj),(_secondaryAmmo select 0),(secondaryWeaponItems _playerObj)],[(handgunWeapon _playerObj),(handgunMagazine _playerObj),(_handgunAmmo select 0),(handgunItems _playerObj)],(assignedItems _playerObj),[(uniform _playerObj),(vest _playerObj),(backpack _playerObj),(goggles _playerObj),(headgear _playerObj)],[_uniformItems,_uniformMags,_uniformWeapons],[_vestItems,_vestMags,_vestWeapons],[_backpackItems,_backpackMags,_backpackWeapons]];
		

//_prepOutgoing = format ["%1:%2:%3:%4:%5:%6:%7:%8",_type,_hitpointArray,_playerPOS select 0,_playerPOS select 1,_playerPOS select 2,_equipmentArray,_loadedMags,_playerUID];
["updateMyPlayer",_playerUID, "",[_playerObj,_hitpointArray,_playerPOS select 0,_playerPOS select 1,_playerPOS select 2,_equipmentArray,_loadedMags]] call DS_fnc_dbRequest; //--- send request to database