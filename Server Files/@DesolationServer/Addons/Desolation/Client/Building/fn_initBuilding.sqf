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
DS_Var_valid3DBuildIcons = [];
 
addMissionEventHandler["Draw3D",{
	{
		_text = _x select 0;
		_pos = _x select 1;
		_remaining = _x select 2;
		drawIcon3D
		[
			"",
			[1 - _remaining, _remaining, 0, 1],
			_pos,
			1*1.5,
			1*1.5,
			0,
			_text,
			2,
			0.05,
			"PuristaBold"
		];
	} count DS_Var_valid3DBuildIcons;
}];
 
while{true} do {
	_crate = cursorTarget;
	 
	_cansee = [objNull, "VIEW"] checkVisibility [eyePos player, getPosASL _crate];
	if (((player distance _crate) < 10) && (_cansee > 0.7)) exitWith
	{
		DS_Var_valid3DBuildIcons = [];
	};
	 
	_data = _object getVariable ["SVAR_buildParams", [[]];
	_requirements = _data select 0;
	 
	_crateMags = getMagazineCargo _crate;
	_crateItems = _crateMags select 0;
	_crateCounts = _crateMags select 1;
	_cratePos = getPosATL _crate;
	 
	_validIcons = [];
	_i = _i;
	{
		_class = _x select 0;
		_amount = _x select 1;
	 
		_index = _crateItems find _class;
		if (_index != -1) then
		{
			_remaining = _amount - (_crateItems select _index);
		}
		else
		{
			_remaining = 0;
		};
		_pos = _cratePos;
		_pos set [2, (_pos select 2) + (_i / 2)];
		_validIcons pushBack [((getText(configFile >> "CfgMagazines" >> _class >> "displayName")) + " | [" + _remaining + "/" + _amount + "]"), _pos, (_amount / _remaining)];
	 
		_i = _i + 1;
		true
	} count _requirements;
	 
	if !(_validIcons isEqualTo DS_Var_valid3DBuildIcons) then
	{
		DS_Var_valid3DBuildIcons = _validIcons;
	};
	uiSleep 0.1;
};