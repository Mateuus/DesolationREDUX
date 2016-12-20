/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

// Very basic network system...
params [["_type", ""],["_data", []]];
switch (_type) do
{
	case "UpdateLocality":
	{
		_data spawn SM_Network_UpdateLocality;
	};
	case "KillZombie":
	{
		_data call SM_Network_KillZombie;
	};
	case "AddGuts":
	{
		_data call SM_Network_AddGuts;
	};
	case "ExplodeHead":
	{
		_data call SM_Network_HandleDamage;
	};
	case "Gut":
	{
		_data call SM_Network_Gut;
	};
	case "GutVariable":
	{
		_data call SM_Network_GutVariable;
	};
	default { };
};

true
