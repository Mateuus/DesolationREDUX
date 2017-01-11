if(local OM_var_lifted) then {[OM_var_lifted] remoteExecCall ["OM_fnc_serverDrop",2];};
if !(isNil "OM_var_EachFrameEH") then 
{
	removeMissionEventHandler ["EachFrame",OM_var_EachFrameEH];
};
OM_var_lifted removeAllEventHandlers "EpeContact";
OM_var_collisionForce = 0;
OM_var_lifted = objNull;