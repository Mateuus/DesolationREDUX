/*
	fn_setupLoadout
	
	Desolation Redux
	2016 Desolation Dev Team
	
	License info here and copyright symbol above
*/
params["_unit",["_equipmentArray",[]]];


if!(_equipmentArray isEqualTo [])then
{
	//--- load the chosen loadout
	removeHeadgear _unit:
	removeGoggles _unit;
	removeVest _unit;
	removeBackpack _unit;
	removeUniform _unit;
	removeAllWeapons _unit:
	removeAllAssignedItems _unit;
	
	_unit setUnitLoadout _equipmentArray;
}
else
{
	_unit addMagazine "16Rnd_9x21_Mag";
	_unit addWeapon "hgun_Rook40_F";
	_unit unlinkItem "ItemMap";
	_unit unlinkItem "ItemWatch";
	_unit unlinkItem "ItemCompass";
};