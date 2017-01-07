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
params["_pos","_cItems"];

_chute = "O_Parachute_02_F" createVehicle _pos;
_chute setPosATL _pos;
_crate = "DSR_Crate_Airdrop_F" createVehicle _pos;
_crate attachTo [_chute,[0,0,-1]];

_smoke = objNull;
_flare = objNull;


_isDone = {((getposatl _crate) select 2) < 2 || ((getposasl _crate) select 2) < 2};
while{true} do {
	_cratePos = round((getposatl _crate) select 2);
	
	//--- attach smoke and flare to the chute (at a location that makes it look like its on top of the crate)
	_smoke1 = "SmokeShellRed" createVehicle (getposatl _crate);
	_flare1 = "F_40mm_Red" createVehicle (getposatl _crate);
	_smoke1 attachTo [_chute,[0,0,0]];
	_flare1 attachTo [_chute,[0,0,0]];
	
	_time = diag_tickTime + 3;
	waitUntil{diag_tickTime > _time || call _isDone}; //--- wait 3 seconds, if the crate is ready to drop off the chute then exit sooner
	
	//--- delete the old smoke/flare from the crate (we kept them here as they take ~3 seconds to pop and start smoking/lighting)
	if(!isNull _flare) then { deleteVehicle _flare; };
	if(!isNull _smoke) then { deleteVehicle _smoke; };
	
	//--- update flare/smoke objects for later cleanup
	_flare = _flare1;
	_smoke = _smoke1;
	
	//--- if we are ready to drop exit loop
	if(call _isDone) exitWith {};
	
	//--- wait another 7 seconds so we can time the flare replacement correctly
	_time = diag_tickTime + 7;
	waitUntil{diag_tickTime > _time || call _isDone};
	
	if(call _isDone) exitWith {};
	
	//-- if the crates Z position rounded did not change within 10 seconds, the crate must be stuck in a tree so exit out
	if(round((getposatl _crate) select 2) == _cratePos) exitWith {};
};

//--- delete flare and smoke objects
if(!isNull _flare) then { deleteVehicle _flare; };
if(!isNull _smoke) then { deleteVehicle _smoke; };

//-- detach crate and delete chute
detach _crate;
deleteVehicle _chute;

//--- add items to crate
[_crate,_cItems] call DS_fnc_addCrateItems;

//--- spawn flares around crate to make it visible at night (we may want to eventually virtualize this whole system)
_pos = getpos _crate;
_p1 = _pos vectorAdd [0,5,0];
_p2 = _pos vectorAdd [5,0,0];
_p3 = _pos vectorAdd [0,-5,0];
_p4 = _pos vectorAdd [-5,0,0];
_p1 set[2,0];
_p2 set[2,0];
_p3 set[2,0];
_p4 set[2,0];
"F_40mm_Red" createVehicle _p1;
"F_40mm_Red" createVehicle _p2;
"F_40mm_Red" createVehicle _p3;
"F_40mm_Red" createVehicle _p4;