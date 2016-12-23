
params[["_action",0]];

_actions = ["Medic","MedicOther"];

if(!isNil 'ds_var_doingAction') then {
	if(ds_var_doingAction) exitWith {systemchat "You are already doing something!";false};
};
ds_var_cancelAction = false;
ds_var_doingAction = true;
_event = (findDisplay 46) displayAddEventHandler ["KeyDown",{
	_key = _this select 1;
	if((_key in (actionKeys "MoveForward")) || (_key in (actionKeys "MoveBack")) || (_key == 30) || (_key == 32)) then {
		ds_var_cancelAction = true;
	};
	false;
}];
_time = diag_tickTime + 6;
player playActionNow (_actions select _action);
waitUntil{diag_tickTime >= _time || ds_var_cancelAction};
[player,"amovpknlmstpsraswrfldnon"] remoteExecCall ["switchMove",-2];
(findDisplay 46) displayRemoveEventHandler ["KeyDown",_event];
ds_var_doingAction = false;
if(ds_var_cancelAction) exitWith {false};
true;


