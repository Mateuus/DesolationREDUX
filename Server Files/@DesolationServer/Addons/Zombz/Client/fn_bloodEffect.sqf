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

[] call SM_fnc_screenAddBlood;
[] spawn
{
	uiSleep 1.5;
	[] call SM_fnc_screenRemoveBlood;
	true
};

true