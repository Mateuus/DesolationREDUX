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
params["_client","_location"];
private["_brokenLoadout","_defaultData","_hats","_goggles","_uniforms","_uid","_unit"];

_brokenLoadout = ["U_C_DSR_Tester","H_StrawHat","G_Aviator"];
_defaultData = _client getVariable ["DDATA",_brokenLoadout];

_hats = ["H_StrawHat","H_Hat_blue","H_Hat_checker","H_Cap_tan","H_Cap_blk","H_Cap_blk_CMMG","H_Cap_brn_SPECOPS","H_Cap_tan_specops_US","H_Cap_khaki_specops_UK","H_Cap_grn","H_Cap_grn_BI","H_Cap_blk_Raven","H_Cap_oli_hs","H_Cap_press","H_Bandanna_khk","H_Bandanna_khk_hs"];
_goggles = ["G_Aviator","G_Shades_Black","G_Shades_Blue","G_Sport_Blackred","G_Tactical_Clear","G_Spectacles","G_Spectacles_Tinted","G_Shades_Green","G_Shades_Red","G_Squares","G_Squares_Tinted","G_Sport_BlackWhite","G_Sport_Blackyellow","G_Sport_Greenblack","G_Sport_Checkered","G_Sport_Red"];
_uniforms = ["U_C_DSR_Tester","U_C_Poor_2","U_C_Poloshirt_blue","U_C_Poloshirt_burgundy","U_C_Poloshirt_stripped","U_C_Poloshirt_tricolour","U_C_Poloshirt_salmon","U_C_Poloshirt_redwhite","U_C_Commoner1_1","U_NikosBody","U_OrestesBody"];

if !((_defaultData select 0) in _uniforms) then {_defaultData = _brokenLoadout;diag_log "BROKEN DATA DETECTED 1";};
if !((_defaultData select 1) in _hats) then {_defaultData = _brokenLoadout;diag_log "BROKEN DATA DETECTED 2";};
if !((_defaultData select 2) in _goggles) then {_defaultData = _brokenLoadout;diag_log "BROKEN DATA DETECTED 3";};

_uid = getplayeruid _client;

if !(_client getVariable ["ReadyToSpawn",false]) exitWith {};
_unit = (createGroup CIVILIAN) createUnit [typeof _client, _location, [],0, "NONE"];
_unit allowDamage false;
_unit hideObjectGlobal true;

_unit setVariable ["pUUID",_client getVariable "pUUID"];

_unit addMPEventHandler ["MPKilled", DS_fnc_onPlayerKilled];
[_unit,[],_defaultData] call DS_fnc_setupLoadout;

_unit hideObjectGlobal false;
_unit allowDamage true;
[_unit,_defaultData select 2] remoteExecCall ["DS_fnc_finishSpawn",_client];
waitUntil{getPlayerUID _unit == _uid && (tolower(goggles _unit) == tolower(_defaultData select 2))};
deleteVehicle _client;
//--- add default values to non-presistant vars here
NULL_CALLBACK = compileFinal "";
["createPlayer","NULL_CALLBACK",[_unit]] call DS_fnc_dbRequest; //--- send request to database