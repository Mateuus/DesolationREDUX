class CfgPatches
{
	class DSR_Code
	{
		requiredVersion = 1;
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
		magazines[] = {};
		ammo[] = {};
		version = 1;
	};
};
class CfgFunctions
{
	class DS 
	{
		class FSMs 
		{
			file = "\DSR_Code\fsm";
			class initStatusSys 
			{
				ext = ".fsm";
			};
		};
	};
};