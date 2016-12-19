/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

private _message = _this;
if!(_this isEqualType "") then
{
	switch(SM_NotificatonType) do
	{
		case 1:
		{
			_rscLayer = "SM_Notificaton" call BIS_fnc_RscLayer;
			_rscLayer cutRsc ["SM_Notification","PLAIN",0.1];
			_display = uinamespace getVariable ["SM_Notification",displayNull];
			playSound "FD_CP_Clear_F";
			(_display displayCtrl 1000) ctrlSetText "ZOMBIE FRAGGED:";
			_type = if(SM_ExileEnabled) then {"Respect"} else {if(SM_EpochEnabled) then {"Crypto"} else {"diamonds"}};
			(_display displayCtrl 1001) ctrlSetText format["You've received %1 %2",_message,_type];
		};
		case 2:
		{
			if(SM_ExileEnabled) then
			{
				_killSummary = [];
				_killSummary pushBack ["ZOMBIE FRAGGED", _message];
				_killSummary call ExileClient_gui_hud_showKillDetails;
			};
			if(SM_EpochEnabled) then
			{
				[format["ZOMBIE FRAGGED: %1 CRYPTO RECEVIED", _message], 5] call Epoch_message;
			};
			if (!SM_EpochEnabled && !SM_ExileEnabled) then
			{
				_type = "diamonds";
				_message = format["You've received %1 %2", _message, _type];
				systemChat _message;
				hintSilent _message;
			};
		};
		default {};
	};
}
else
{
	switch(SM_NotificatonType) do
	{
		case 1:
		{
			_rscLayer = "SM_Notificaton" call BIS_fnc_RscLayer;
			_rscLayer cutRsc ["SM_Notification","PLAIN",0.1];
			_display = uinamespace getVariable ["SM_Notification",displayNull];
			playSound "FD_CP_Clear_F";
			(_display displayCtrl 1000) ctrlSetText "SM_Zombz:";
			(_display displayCtrl 1001) ctrlSetText _message;
		};
		case 2:
		{
			if(SM_ExileEnabled) then
			{
				["SuccessTitleAndText",["SM_Zombz:",_message]] call ExileClient_gui_toaster_addTemplateToast;
			};
			if(SM_EpochEnabled) then
			{
				[format["SM_Zombz: %1", _message], 5] call Epoch_message;
			};
			if (!SM_EpochEnabled && !SM_ExileEnabled) then
			{
				systemChat _message;
				hintSilent _message;
			};
		};
		default {};
	};	
};

true
