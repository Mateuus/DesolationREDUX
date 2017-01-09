/*
	fn_start
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
disableUserInput false;

call BASE_fnc_initEventHandlers;

{
	_isStartClient = [_x,"initClient"] call BASE_fnc_hasSuffix;
	if(_isStartClient) then {
		[] spawn (missionNamespace getVariable [_x,{DIAG_LOG "FAILED TO FIND FUNCTION";}]);
	};
} forEach BASE_var_Files;

[] spawn BASE_fnc_startActionManager; //--- start action management
[] spawn BASE_fnc_initKeybindUI; //--- start unmodded custom controls ui thread

0 cutRsc ["background","PLAIN",0];
//10000 cutText ["","BLACK IN",1];
