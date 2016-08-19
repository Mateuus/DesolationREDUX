_zombie = _this select 0;

if ((!isServer) and hasInterface) exitwith {};

while {alive _zombie} do
{
	sleep 30;
	_trg = createTrigger ["EmptyDetector", getposATL _zombie];
	_trg setTriggerArea [ryanzombiesdeletionradius, ryanzombiesdeletionradius, 0, false];
	if (ryanzombiesdeletion == 0.7) then {_trg setTriggerActivation ["WEST", "NOT PRESENT", false];};
	if (ryanzombiesdeletion == 0.5) then {_trg setTriggerActivation ["EAST", "NOT PRESENT", false];};
	if (ryanzombiesdeletion == 0.3) then {_trg setTriggerActivation ["GUER", "NOT PRESENT", false];};
	if (ryanzombiesdeletion == 0.1) then {_trg setTriggerActivation ["CIV", "NOT PRESENT", false];};

	sleep 1;
	if (triggeractivated _trg) then
	{
		deletevehicle _trg;
		_trg = createTrigger ["EmptyDetector", getposATL _zombie];
		_trg setTriggerArea [ryanzombiesdeletionradius, ryanzombiesdeletionradius, 0, false];
		if (ryanzombiesdeletion2 == 0.7) then {_trg setTriggerActivation ["WEST", "NOT PRESENT", false];};
		if (ryanzombiesdeletion2 == 0.5) then {_trg setTriggerActivation ["EAST", "NOT PRESENT", false];};
		if (ryanzombiesdeletion2 == 0.3) then {_trg setTriggerActivation ["GUER", "NOT PRESENT", false];};
		if (ryanzombiesdeletion2 == 0.1) then {_trg setTriggerActivation ["CIV", "NOT PRESENT", false];};

		sleep 1;
		if ((triggeractivated _trg) OR (ryanzombiesdeletion2 == 0.9)) exitwith
		{
			deletevehicle _zombie;
		};
	};
	deletevehicle _trg;
};