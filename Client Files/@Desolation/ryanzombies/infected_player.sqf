if(player != _this) exitWith {};

sleep 3;
if (player getvariable ["ryanzombiesinfected",0] == 0) exitwith {};

_ppInfected = ppEffectCreate ["ChromAberration", 1000];
_ppInfected ppEffectEnable true;

_trg = createTrigger ["EmptyDetector", getposATL player, false];
_trg attachTo [player];

while {(alive player) && (player getvariable ["ryanzombiesinfected",0] > 0)} do
{
	if !(player getvariable ["ryanzombiesimmunity",false]) then
	{
		if ((player getvariable ["ryanzombiesinfected",0]) >= 1) exitwith
		{
			_trg say3d "ryanzombiesheart4";
			_ppInfected ppEffectAdjust [0.3, 0.3, false];
			_ppInfected ppEffectCommit 3;
			sleep 3;
		};
		if ((player getvariable ["ryanzombiesinfected",0]) > 0.85) exitwith
		{
			_trg say3d "ryanzombiesheart4";
			_ppInfected ppEffectAdjust [0.022, 0.022, false];
			_ppInfected ppEffectCommit 3;
			sleep 1;
		};
		if ((player getvariable ["ryanzombiesinfected",0]) > 0.65) exitwith
		{
			_trg say3d "ryanzombiesheart3";
			_ppInfected ppEffectAdjust [0.018, 0.018, false];
			_ppInfected ppEffectCommit 3;
			sleep 1.3;
		};
		if ((player getvariable ["ryanzombiesinfected",0]) > 0.45) exitwith
		{
			_trg say3d "ryanzombiesheart2";
			_ppInfected ppEffectAdjust [0.014, 0.014, false];
			_ppInfected ppEffectCommit 3;
			sleep 1.6;
		};
		if ((player getvariable ["ryanzombiesinfected",0]) > 0.25) exitwith
		{
			_trg say3d "ryanzombiesheart1";
			_ppInfected ppEffectAdjust [0.01, 0.01, false];
			_ppInfected ppEffectCommit 3;
			sleep 1.9;
		};
		_ppInfected ppEffectAdjust [0, 0, false];
		_ppInfected ppEffectCommit 2;
		sleep 3;
	} else {_ppInfected ppEffectAdjust [0, 0, false]; _ppInfected ppEffectCommit 2; sleep 4;};
};

player setVariable ["ryanzombiesinfected",0,true];
player setVariable ["ryanzombiesimmunity",false,true];

_ppInfected ppEffectAdjust [0, 0, false];
_ppInfected ppEffectCommit 2;

sleep 2;

deletevehicle _trg;
ppEffectDestroy _ppInfected;