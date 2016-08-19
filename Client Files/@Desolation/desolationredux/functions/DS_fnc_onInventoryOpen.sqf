waituntil {!(isnull (finddisplay 602))};

hint "Inventory has been opened\nAdding event to uniform listbox";
/*	//Item Info Handlers
		((findDisplay 602) displayCtrl 619) ctrlAddEventHandler ["LBSelChanged", "_this call DS_fnc_inv_onLBSelChanged"];
        ((findDisplay 602) displayCtrl 633) ctrlSetEventHandler ["LBSelChanged", "_this call DS_fnc_inv_onLBSelChanged"];
		((findDisplay 602) displayCtrl 638) ctrlAddEventHandler ["LBSelChanged", "_this call DS_fnc_inv_onLBSelChanged"];
	
	//Item Action Handlers - testing double click and build 
		((findDisplay 602) displayCtrl 619) ctrlAddEventHandler ["MouseButtonDblClick", "_this call DS_fnc_inv_onMouseButtonDblClick"];
		((findDisplay 602) displayCtrl 633) ctrlAddEventHandler ["MouseButtonDblClick", "_this call DS_fnc_inv_onMouseButtonDblClick"];
		((findDisplay 602) displayCtrl 638) ctrlAddEventHandler ["MouseButtonDblClick", "_this call DS_fnc_inv_onMouseButtonDblClick"];
		
*/