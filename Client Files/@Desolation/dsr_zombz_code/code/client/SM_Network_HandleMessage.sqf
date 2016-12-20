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
	case "ZombieReceive":
	{
		_data spawn SM_Network_ZombieReceive;
	};
	case "ExplodeHead":
	{
		_data call SM_Network_ExplodeHead;
	};
	case "FragNotification":
	{
		_data call SM_Network_FragNotification;
	};
	case "Notification":
	{
		_data call SM_Network_Notification;
	};
	case "RemoveGuts":
	{
		_data call SM_Network_RemoveGuts;
	};
	case "playSound":
	{
		_data call SM_Say3D;
	};
	default {};
};

true
