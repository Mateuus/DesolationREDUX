_idc = _this select 0;
_selectedIndex = _this select 1;
_itemClassName = _idc lbData _selectedIndex;
_itemDisplayName = _idc lbText _selectedIndex;
_itemType = getText (configFile >> "CfgMagazines" >> _itemClassName >> "DSInventoryItemType");//TypeOf _itemName;
_itemBuiltName = getText (configFile >> "CfgMagazines" >> _itemClassName >> "DSObjectName");
diag_log format["[DesolationDebug]itemName:%1 | displayname:%2  |  type:%3  |  builtname:%4",_itemClassName,_itemDisplayName,_itemType,_itemBuiltName];
switch (_itemType) do 
{
	case "sleeping": 
	{
		//temp build item for testing//[] call DS_fnc_objectBuild;
		player removeItem _itemClassName;
		_itemBuiltName createVehicle position player;
	};	
	case "consumable": 
	{
		player removeItem _itemClassName;
		//get action for player and play it
		//get food or drink values
		//increase values respectively
	};
	case "medical": 
	{
		player removeItem _itemClassName;
		//get action for player and play it
		//get health / infection values
		//increase values respectively
	};
	case "craftables": 
	{
		hint "you made it here to craft at least ;)";
		//get config for items that can be built. -- Create Crafting config in desolation plugins
		_itemsArray = [];
		//get items needed to crafting
		//remove all items and add new item to inventory
	};
};
