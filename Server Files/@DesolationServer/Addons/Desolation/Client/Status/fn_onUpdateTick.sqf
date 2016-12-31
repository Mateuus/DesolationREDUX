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
 
//--- notify server of variables (both persistant and non-persistant)

if(player getVariable ["DS_var_Blood",0] != DS_var_Blood) then {
	player setVariable ["DS_var_Blood",DS_var_Blood,true];
};
if(player getVariable ["DS_var_Thirst",0] != DS_var_Thirst) then {
	player setVariable ["DS_var_Thirst",DS_var_Thirst,true];
};
if(player getVariable ["DS_var_Hunger",0] != DS_var_Hunger) then {
	player setVariable ["DS_var_Hunger",DS_var_Hunger,true];
};

