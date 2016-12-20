/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_player", objNull],["_messageType", ""],["_data", []]];

if (isNull _player) exitWith { false };

SM_ClientNetworkMessage = [_messageType, _data];
(owner _player) publicVariableClient "SM_ClientNetworkMessage";
SM_ClientNetworkMessage = nil;

true
