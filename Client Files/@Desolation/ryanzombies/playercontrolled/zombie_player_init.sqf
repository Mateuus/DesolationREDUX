#include "\a3\editor_f\Data\Scripts\dikCodes.h"

(_this select 0) sethit ["body",0.5];
removegoggles (_this select 0);

if (isDedicated) exitWith {};
if !(hasinterface) exitwith {};

sleep 0.5;

_zombie = _this select 0;

_facearray = ["RyanZombieFace1", "RyanZombieFace2", "RyanZombieFace3", "RyanZombieFace4", "RyanZombieFace5", "RyanZombieFace6"];
_face = selectRandom _facearray;
_zombie setface _face;

diag_log _this;

waitUntil{!isNil "BIS_fnc_init"};
waituntil {!(IsNull (findDisplay 46))};


if (player != (_this select 0)) exitWith {_zombie disableAI "ANIM";};


if (isnil "Ryanzombiesattackspeedplayer") then {Ryanzombiesattackspeedplayer = 0.8};
if (isnil "Ryanzombiesattackdistanceplayer") then {Ryanzombiesattackdistanceplayer = 2.35};
if (isnil "Ryanzombiesattackstrenthplayer") then {Ryanzombiesattackstrenthplayer = 1.5};
if (isnil "Ryanzombiesdamageplayer") then {Ryanzombiesdamageplayer = 0.15};
if (isnil "Ryanzombiesdamagecarplayer") then {Ryanzombiesdamagecarplayer = 0.02};
if (isnil "Ryanzombiesdamageairplayer") then {Ryanzombiesdamageairplayer = 0.01};
if (isnil "Ryanzombiesdamagetankplayer") then {Ryanzombiesdamagetankplayer = 0.002};
if (isnil "Ryanzombiesdamagecarstrenthplayer") then {Ryanzombiesdamagecarstrenthplayer = 1.5};
if (isnil "Ryanzombiesdamageairstrenthplayer") then {Ryanzombiesdamageairstrenthplayer = 1};
if (isnil "Ryanzombiesdamagetankstrenthplayer") then {Ryanzombiesdamagetankstrenthplayer = 0.4};

_zombie enableFatigue false;
removegoggles _zombie;

RZ_fnc_Pounce = compile preprocessfilelinenumbers "\ryanzombies\playercontrolled\pounce.sqf";
RZ_fnc_Attack = compile preprocessfilelinenumbers "\ryanzombies\playercontrolled\attack.sqf";
RZ_fnc_Taunt = compile preprocessfilelinenumbers "\ryanzombies\playercontrolled\taunt.sqf";

private ["_keyEH","_mouseEH"];


_mouseEH = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", 
{
	_ret = false;
	if ((_this select 1) == 0) then 
	{
		if((time - (player getVariable ["ryanlastzombieattack",0])) > Ryanzombiesattackspeedplayer) then 
		{
			player call RZ_fnc_Attack;
		};	
		_ret = false; // experiment
	};
	_ret
}];

_keyEH = (findDisplay 46) displayAddEventHandler ["KeyDown", 
{
	_ret = false;
	if (_this select 1 == 57) then 
	{
		if((time - (player getVariable ["ryanlastzombiepounce",0])) > 0.05) then 
		{		
			player call RZ_fnc_Pounce;
		};
		_ret = true;
	};	
	
	if (_this select 1 == 20) then 
	{
		if((time - (player getVariable ["ryanlastzombietaunt",0])) > 1) then 
		{		
			player call RZ_fnc_Taunt;
		};
		_ret = true;
	};
	_ret
}];	

//["Zombies & Demons","pounce", "Pounce", {player execvm "\ryanzombies\playercontrolled\pounce.sqf";}, {}, [DIK_SPACE, [false, false, false]],false] call CBA_fnc_addKeybind;
//["Zombies & Demons","pounce2", "Pounce Shift", {player execvm "\ryanzombies\playercontrolled\pounce.sqf";}, {}, [DIK_SPACE, [true, false, false]],false] call CBA_fnc_addKeybind;
//["Zombies & Demons","attack", "Attack", {player execvm "\ryanzombies\playercontrolled\attack.sqf";}, {}, [DIK_LCONTROL, [false, true, false]],false] call CBA_fnc_addKeybind;

_falldamage = player addEventHandler ["HandleDamage", {if ((_this select 4) == "") then { (_this select 0) setHit ["body",0.5]; damage (_this select 0)};}]; 

if !(isnil "ryanzombiesmovementspeedplayer") then {player setAnimSpeedCoef ryanzombiesmovementspeedplayer; };

RZ_Effects_Array = [];

_respawnEH = player addEventHandler ["Respawn",
{
	_zombie = _this select 0;
	if(!(alive _zombie) || !(canMove _zombie)) exitWith {}; 

	_zombie setdamage 0;
	_zombie setHit ["body",0.5];

	if !(isnil "ryanzombiesmovementspeedplayer") then {_zombie setAnimSpeedCoef ryanzombiesmovementspeedplayer; };

	_facearray = ["RyanZombieFace1", "RyanZombieFace2", "RyanZombieFace3", "RyanZombieFace4", "RyanZombieFace5"];
	_face = selectRandom _facearray;
	[_zombie, _face] remoteExecCall ["setFace"];

	ppEffectDestroy RZ_Effects_Array;

	_colors = ppEffectCreate ["colorCorrections",1600]; _blur = ppEffectCreate ["RadialBlur",1601]; _inversion = ppEffectCreate ["ColorInversion",1602];
	[_colors,_blur,_inversion] ppEffectEnable true;

	_colors ppEffectAdjust[ 1, 1, 0, [-0.06, -0.06, 0.06, 0],[-0.24, 0.05, 0.07, 1.17],[0.49, 5, 5, 5]];
	_blur ppEffectAdjust[0.09, 0, 0.26, 0.35];
	_inversion ppEffectAdjust[0.27, 0.2, 0.29];

	[_colors,_blur,_inversion] ppEffectCommit 0;

	RZ_Effects_Array = [_colors,_blur,_inversion];

	_zombie enableFatigue false;
	removegoggles _zombie;
	
}];

player setdamage 0;
player sethit ["body",0.5];



_colors = ppEffectCreate ["colorCorrections",1600]; _blur = ppEffectCreate ["RadialBlur",1601]; _inversion = ppEffectCreate ["ColorInversion",1602];
[_colors,_blur,_inversion] ppEffectEnable true;

_colors ppEffectAdjust[ 1, 1, 0, [-0.06, -0.06, 0.06, 0],[-0.24, 0.05, 0.07, 1.17],[0.49, 5, 5, 5]];
_blur ppEffectAdjust[0.09, 0, 0.26, 0.35];
_inversion ppEffectAdjust[0.27, 0.2, 0.29];

[_colors,_blur,_inversion] ppEffectCommit 0;

RZ_Effects_Array = [_colors,_blur,_inversion];