params["_pos","_cItems"];

_chute = "O_Parachute_02_F" createVehicle _pos;
_chute setPosATL _pos;
_crate = "DSR_Crate_Airdrop_F" createVehicle _pos;
_crate attachTo [_chute,[0,0,-1]];

_smoke = objNull;
_flare = objNull;

while{((getposatl _chute) select 2) > 4 && ((getposasl _chute) select 2) > 4} do {
	_chutepos = round(getposatl _chute select 2);
	
	_smoke1 = "SmokeShellRed" createVehicle (getposatl _crate);
	_flare1 = "F_40mm_Red" createVehicle (getposatl _crate);
	_smoke1 attachTo [_chute,[0,0,0]];
	_flare1 attachTo [_chute,[0,0,0]];
	
	uiSleep 3;
	
	if(!isNull _flare) then { deleteVehicle _flare; };
	if(!isNull _smoke) then { deleteVehicle _smoke; };
	_flare = _flare1;
	_smoke = _smoke1;
	
	uiSleep 7;
	
	if(round(getposatl _chute select 0) == _chutepos) exitWith {}; //--- chute stuck in tree
};

if(!isNull _flare) then { deleteVehicle _flare; };
if(!isNull _smoke) then { deleteVehicle _smoke; };
detach _crate;
deleteVehicle _chute;

[_crate,_cItems] call DS_fnc_addCrateItems;

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