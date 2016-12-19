/**
 * The Forsaken Survivors Community
 * www.theforsakensurvivors.co.uk
 * © 2016 The Forsaken Survivors Community
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-sa/4.0/
 */

params [["_zombie", objNull],"_owner","_ownerPlayer","_zombieInfo","_zombieCount","_zombiesArray","_killer","_amount","_score","_killSummary","_chance","_count","_lootToAdd","_lootHolder","_cargoType","_magazineClassNames","_magazineClassName"];
DeadZombieBodys pushBack [(netId _zombie), diag_tickTime];
SM_CurrentZombieCount = (SM_CurrentZombieCount - 1);
_owner = _zombie getVariable ["SM_ZombieOwner", ""];
if !(_owner isEqualTo "") then
{
	_ownerPlayer = objectFromNetId _owner;
	if !(isNull _ownerPlayer) then
	{
		_zombieInfo = _ownerPlayer getVariable ["SM_CurrentZombies", [0, []]];
		_zombieCount = _zombieInfo select 0;
		_zombiesArray = _zombieInfo select 1;
		if !((_zombieCount isEqualTo 0) && (_zombiesArray isEqualTo [])) then
		{
			_zombiesArray = _zombiesArray - [(netId _zombie)];
			_zombieCount = _zombieCount - 1;
			_ownerPlayer setVariable ["SM_CurrentZombies", [_zombieCount, _zombiesArray]];
		};
	};
};

if (SM_ExileEnabled) then
{
	if (SM_GivePlayerRespect) then
	{
		_killer = _this select 1;
		if (!(_zombie isEqualTo _killer) && (isPlayer _killer)) then
		{
			_amount = (round(random SM_MaxRespect)) max 1;
			_score = (_killer getVariable ["ExileScore", 0]) + _amount;
			_killer setVariable ["ExileScore", _score];
			format["setAccountScore:%1:%2", _score, getPlayerUID _killer] spawn ExileServer_system_database_query_fireAndForget;
			_killer call ExileServer_object_player_sendStatsUpdate;
		};
	};

	if (SM_GiveZombiePoptabs) then
	{
		_chance = floor(random SM_PoptabChanceHigh);
		if (_chance > SM_PopTabsChanceLow) then
		{
			_zombie setVariable ["ExileMoney", (round(random SM_MaxPoptabs)), true];
		};
	};
};

if (SM_EpochEnabled) then
{
	_killer = _this select 1;
	if (SM_GiveCrpyto) then
	{
		if (!(_zombie isEqualTo _killer) && (isPlayer _killer)) then
		{
			_amount = (round(random SM_MaxCrypto)) max 1;
			[_killer, _amount] call EPOCH_server_effectCrypto;
		};
	};
};

if (SM_MinChanceOfLoot > (random SM_MaxChanceOfLoot)) then
{
	_count = round (random SM_MaxItemDrop);
	if (_count isEqualTo 0) exitWith {};
	_lootToAdd = [];
	for "_i" from 1 to _count do
	{
		_lootToAdd pushBack (selectRandom SM_LootArray);
	};
	if (_lootToAdd isEqualTo []) exitWith {};
	_lootHolder = createVehicle["LootWeaponHolder", (getPosATL _zombie), [], 0, "CAN_COLLIDE"];
	_lootHolder attachTo [_zombie, [0,0,0]];
	{
		_cargoType = _x call SM_LootItemGetType;
		switch (_cargoType) do
		{
			case 1:
			{
				if (_x isEqualTo "Exile_Item_MountainDupe") then
				{
					_lootHolder addMagazineCargoGlobal [_x, 2];
				}
				else
				{
					_lootHolder addMagazineCargoGlobal [_x, 1];
				};
			};
			case 3:
			{
				_lootHolder addBackpackCargoGlobal [_x, 1];
			};
			case 2:
			{
				_lootHolder addWeaponCargoGlobal [_x, 1];
				_epochMeleeWeapons = ["Hatchet","CrudeHatchet","MeleeSledge","MeleeMaul","MeleeSword","WoodClub","Plunger","MeleeRod"];
				_exileMeleeWeapons = ["Exile_Melee_Axe","Exile_Melee_Shovel","Exile_Melee_SledgeHammer"];
				_allMeleeItems = _epochMeleeWeapons + _exileMeleeWeapons;
				if !(_x in _allMeleeItems) then
				{
					_magazineClassNames = getArray(configFile >> "CfgWeapons" >> _x >> "magazines");
					if (count(_magazineClassNames) > 0) then
					{
						_magazineClassName = selectRandom _magazineClassNames;
						_lootHolder addMagazineCargoGlobal [_magazineClassName, ceil(random 2)];
					};
				};
			};
			default { _lootHolder addItemCargoGlobal [_x, 1]; };
		};
	} forEach _lootToAdd;
};

if (SM_NotificationEnabled) then
{
	if !(isNil "_amount") then
	{
		[_killer, "Notification", _amount] call SM_Network_SendMessage;
	};
};

true
