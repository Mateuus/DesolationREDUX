/*
Desolation Redux
2016 Desolation Dev Team

License info here and copyright symbol above
*/

/*
	Author: StokesMagee
	Project: DSR_SM_Zombz
	Description: SM_Zombz desolation redux edition.
*/

disableSerialization;

_display = uinamespace getVariable ["SM_RscHealthTextures", displayNull];

if (isNull _display) then 
{
	(["HealthPP_blood"] call bis_fnc_rscLayer) cutrsc ["SM_RscHealthTextures", "PLAIN"];
	_display = uiNamespace getVariable ["SM_RscHealthTextures", displayNull];
};


_lower = _display displayctrl 1211;
_middle = _display displayctrl 1212;
_upper = _display displayctrl 1213;
_left = _display displayctrl 1214;
_right = _display displayctrl 1215;

_lower ctrlsetfade 0.7;	 
_middle ctrlsetfade 0.7;  
_upper ctrlsetfade 0.7;  
_left ctrlSetFade 0.7;
_right ctrlSetFade 0.7;

_lower ctrlcommit 0.2;
_middle ctrlcommit 0.2;
_upper ctrlcommit 0.2;
_left ctrlCommit 0.2;
_right ctrlCommit 0.2;

true
