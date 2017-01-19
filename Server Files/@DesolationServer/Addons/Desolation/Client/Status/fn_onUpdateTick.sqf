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

if(player getVariable ["SVAR_DS_var_Blood",0] != DS_var_Blood) then {
	player setVariable ["SVAR_DS_var_Blood",DS_var_Blood,true];
};
if(player getVariable ["SVAR_DS_var_Thirst",0] != DS_var_Thirst) then {
	player setVariable ["SVAR_DS_var_Thirst",DS_var_Thirst,true];
};
if(player getVariable ["SVAR_DS_var_Hunger",0] != DS_var_Hunger) then {
	player setVariable ["SVAR_DS_var_Hunger",DS_var_Hunger,true];
};
if(player getVariable ["SVAR_DS_var_lastAte",0] != DS_var_lastAte) then {
	player setVariable ["SVAR_DS_var_lastAte",DS_var_lastAte,true];
};
if(player getVariable ["SVAR_DS_var_lastDrank",0] != DS_var_lastDrank) then {
	player setVariable ["SVAR_DS_var_lastDrank",DS_var_lastDrank,true];
};
if(player getVariable ["SVAR_DS_var_lastImmune",0] != DS_var_lastImmune) then {
	player setVariable ["SVAR_DS_var_lastImmune",DS_var_lastImmune,true];
};
if(player getVariable ["SVAR_DS_var_InfectionDOT",0] != SM_infectionDOT) then {
	player setVariable ["SVAR_DS_var_InfectionDOT",SM_infectionDOT,true];
};