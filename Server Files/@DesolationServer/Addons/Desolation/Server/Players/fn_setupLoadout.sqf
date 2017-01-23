/*
 * Desolation Redux
 * http://desolationredux.com/
 * © 2016 Desolation Dev Team
 * 
 * This work is licensed under the Arma Public License Share Alike (APL-SA) + Bohemia monetization rights.
 * To view a copy of this license, visit:
 * https://www.bistudio.com/community/licenses/arma-public-license-share-alike/
 * https://www.bistudio.com/monetization/
 */
params["_unit",["_equipmentArray",[]],["_defaultData",[]]];

if !(_equipmentArray isEqualTo []) then
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
	removeHeadgear _unit;
	removeUniform _unit;
	removeGoggles _unit;
	
	_unit addUniform (_defaultData select 0);
	_unit addHeadgear (_defaultData select 1);
	
	_unit addMagazine "16Rnd_9x21_Mag";
	_unit addWeapon "dsr_hgun_rook";
	_unit addMagazine "dsr_item_bandage";
	_unit unlinkItem "ItemMap";
	_unit unlinkItem "ItemWatch";
};