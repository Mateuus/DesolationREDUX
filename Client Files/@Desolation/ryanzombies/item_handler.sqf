[] spawn
{
	while {true} do
	{
		waituntil {!(isnull (finddisplay 602))};
		((findDisplay 602) displayCtrl 619) ctrlAddEventHandler ["LBDblClick", "_this call RZ_inventory_DblClick"];
		((findDisplay 602) displayCtrl 633) ctrlAddEventHandler ["LBDblClick", "_this call RZ_inventory_DblClick"];
		((findDisplay 602) displayCtrl 638) ctrlAddEventHandler ["LBDblClick", "_this call RZ_inventory_DblClick"];  
		waituntil {isnull (finddisplay 602)};
    };
};