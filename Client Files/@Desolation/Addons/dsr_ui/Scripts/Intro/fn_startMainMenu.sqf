sleep 2.3;
createDialog "mainMenu";

(findDisplay 88001) displayAddEventHandler ["KeyDown",{
	_return = false;
	if((_this select 1) == 1) then {
		_return = true;
	};
	_return;
}];

((findDisplay 88001) displayCtrl 2403) ctrlAddEventHandler ["ButtonClick", {
	[] spawn opx_fnc_forceCharacterCustomization;
}];

((findDisplay 88001) displayCtrl 2402) buttonSetAction "ctrlActivate ((findDisplay 0) displayCtrl (getNumber(configFile >> 'RscDisplayMain' >> 'Controls' >> 'Exit' >> 'idc')));";
((findDisplay 88001) displayCtrl 2400) buttonSetAction "closeDialog 0;ctrlActivate ((findDisplay 0) displayCtrl 105);";