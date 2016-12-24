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

params [["_victim", objNull],["_selection", ""],["_damage", 0],["_damager", objNull],"_hmd","_headExplode"];

systemchat "handling damage with damage:"
systemchat str _damage;
if((_selection isEqualTo "head") && _damage >= 1) then
{
	if !((face _victim) isEqualTo "SM_ZombzNoFace") then 
	{
		_victim setFace "SM_ZombzNoFace";
		[netId _victim] remoteExecCall ["SM_fnc_zombieExplodeHead", 2];
	};
};

_damage
