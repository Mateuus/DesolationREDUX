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

params [["_object",objNull],["_vel",[]]];
if (!(isNull _object) && !(_vel isEqualTo [])) then
{
	_object setVelocity _vel;
};

true