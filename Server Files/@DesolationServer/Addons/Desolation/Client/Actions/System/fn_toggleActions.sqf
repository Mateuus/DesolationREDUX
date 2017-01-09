if (isNil "DS_var_3DActionsEnabled") then
{
	DS_var_3DActionsEnabled = false;
};

if !(DS_var_3DActionsEnabled) then
{
	DS_var_3DActionsEnabled = true;
	DS_var_3DDrawEvent = missionNamespace addMissionEventHandler ["Draw3D",{ [] call DS_fnc_draw3DActions; }];
}
else
{
	DS_var_3DActionsEnabled = false;
	if (isNil "DS_var_3DDrawEvent") exitWith {};
	removeMissionEventHandler ["Draw3D", DS_var_3DDrawEvent];
	DS_var_3DDrawEvent = nil;
	DS_var_3DPartName = nil;
};

true