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

DS_var_Blood = player getVariable ["SVAR_DS_var_Blood",27500];
DS_var_isBleeding = false;
DS_var_Thirst = player getVariable ["SVAR_DS_var_Thirst",100];
DS_var_isDehydrating = false;
DS_var_Hunger = player getVariable ["SVAR_DS_var_Hunger",100];
DS_var_isStarving = false;
DS_var_lastAte = diag_tickTime;
DS_var_lastDrank = diag_tickTime;
DS_var_lastKnockout = 0;