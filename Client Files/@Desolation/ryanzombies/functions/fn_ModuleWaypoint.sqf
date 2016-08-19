_logic = _this select 0;

if ((!isServer) and hasInterface) exitwith {};
_Waypoint = _logic getVariable ["Waypoint",1];

if ((_Waypoint == 1) OR (_Waypoint == 3)) then
{
	Ryanzombieswaypoint = 1;
	ryanzombieslogicwaypoint = createTrigger ["EmptyDetector", getposATL _logic];
};

if ((_Waypoint == 2) OR (_Waypoint == 3)) then
{
	Ryanzombieswaypointdemon = 1;
	ryanzombieslogicwaypointdemon = createTrigger ["EmptyDetector", getposATL _logic];
};