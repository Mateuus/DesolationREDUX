class CfgPatches
{
	class dsr_actions
	{
		fileName = "dsr_actions.pbo";
		requiredAddons[] = {};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		vehicles[] = {};
		author[]= {"Desolation Redux Dev Team"};
	};
};

//--- base item actions
class Action_Drink { // drinks
	text = "Drink %itemname%";
	condition = "!(isNil 'ds_fnc_drink') && !isNil 'ds_var_thirst'"; //TODO more conditions
	action = "[_classname] spawn ds_fnc_drink";
};
class Action_Eat { // foods
	text = "Eat %itemname%";
	condition = "!(isNil 'ds_fnc_eat') && !isNil 'ds_var_hunger'"; //TODO more conditions
	action = "[_classname] spawn ds_fnc_eat";
};
class Action_Use { // use item
	text = "Use %itemname%";
	condition = "false"; //TODO more conditions
	action = "hint 'use not defined';";
};

class Action_Fill { // use item
	text = "Fill %itemname%";
	condition = "false"; //TODO more conditions
	action = "hint 'use not defined';";
};
class Action_FillWater { // fill with water
	text = "Fill %itemname%";
	condition = "!(isNil 'ds_fnc_fillwater') && (toLower(_cursorStr) find 'water' != -1)";
	action = "[_classname] spawn ds_fnc_fillwater";
};
class Action_FillHydrocarbon { // fill propane or butane
	text = "Fill %itemname%";
	condition = "(_classname find '_empty' != 0) && !(isNil 'ds_fnc_fillhcarbon')";
	action = "[_classname] spawn ds_fnc_fillhcarbon";
};

class CfgMagazines {
	//--- food
	class dsr_item_beans {
		class Actions {
			class Eat : Action_Eat {};
		};
	};
	class dsr_item_cereal {
		class Actions {
			class Eat : Action_Eat {};
		};
	};
	class dsr_item_powderedmilk {
		class Actions {
			class Eat : Action_Eat {};
		};
	};
	class dsr_item_rice {
		class Actions {
			class Eat : Action_Eat {};
		};
	};
	class dsr_item_bacon {
		class Actions {
			class Eat : Action_Eat {};
		};
	};
	//--- drinks
	class dsr_item_waterbottle_full {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_waterbottle_dirty {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_waterbottle_empty {
		class Actions {
			class Fill : Action_FillWater {};
		};
	};
	class dsr_item_canteen_full {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_canteen_dirty {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_canteen_empty {
		class Actions {
			class Fill : Action_FillWater {};
		};
	};
	class dsr_item_spirit {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_franta {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_rustyspirit {
		class Actions {
			class Drink : Action_Drink {};
		};
	};
	//--- medical
	class dsr_item_splint {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usesplint') && ((player getHitPointDamage 'HitLegs') > 0)";
				action = "[_classname] spawn ds_fnc_usesplint";
			};
		};
	};
	class dsr_item_antibiotic {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_useantibotic')";
				action = "[_classname] spawn ds_fnc_useantibotic";
			};
		};
	};
	class dsr_item_bandage {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usebandage')";
				action = "[_classname] spawn ds_fnc_usebandage";
			};
		};
	};
	class dsr_item_bloodbag_empty {
		class Actions {
			class Fill : Action_Fill {
				condition = "!(isNil 'ds_fnc_fillblood')";
				action = "[_classname] spawn ds_fnc_fillblood";
			};
		};
	};
	class dsr_item_bloodbag_full {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_useblood') && !isNil 'ds_var_blood'";
				action = "[_classname] spawn ds_fnc_useblood";
			};
			class Drink : Action_Drink {};
		};
	};
	class dsr_item_defibrillator {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usedefib') && cursorObject isKindOf 'man' && !isPlayer cursorObject && !alive cursorObject";
				action = "[_classname] spawn ds_fnc_usedefib";
			};
		};
	};
	class dsr_item_disinfectant {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usedisinfectant')";
				action = "[_classname] spawn ds_fnc_usedisinfectant";
			};
		};
	};
	class dsr_item_handwarmer {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usehandwarmer')";
				action = "[_classname] spawn ds_fnc_usehandwarmer";
			};
		};
	};
	class dsr_item_painkillers {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usepainkillers')";
				action = "[_classname] spawn ds_fnc_usepainkillers";
			};
		};
	};
	class dsr_item_vitamins {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usevitamins')";
				action = "[_classname] spawn ds_fnc_usevitamins";
			};
		};
	};
	class dsr_item_waterpurificationtablets {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_usewpt')";
				action = "[_classname] spawn ds_fnc_usewpt";
			};
		};
	};
	//--- tools
	class dsr_item_butane_empty {
		class Actions {
			class Fill : Action_FillHydrocarbon {};
		};
	};
	class dsr_item_propane_empty {
		class Actions {
			class Fill : Action_FillHydrocarbon {};
		};
	};
	class dsr_item_matches {
		class Actions {
			class Use : Action_Use {
				condition = "!(isNil 'ds_fnc_lightfire')";
				action = "[_classname] spawn ds_fnc_lightfire";
			};
		};
	};
	
	//--- other
	class dsr_item_bucket_empty {
		class Actions {
			class Fill : Action_FillWater {};
		};
	};
};

class 3DDefaultActions
{
	class Prestine
	{
		condition = "_thisDamage == 0";
		code = "systemchat 'i like prestine';";
	};
	class Destroyed
	{
		condition = "_thisDamage >= 1";
		code = "systmechat 'i am destroyed';";
	};
	class Damaged
	{
		condition = "_thisDamage < 1 && _thisDamage > 0";
		code = "systemchat 'i am damaged';";
	};
};

class Cfg3DActions
{
	class action
	{
		name = "Actions";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};
	};
	class glass
	{
		name = "Glass";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};
	};
	class wheel
	{
		name = "Glass";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};
	};
	class engine
	{
		name = "Engine";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};
	};
	class fuel
	{
		name = "Fuel";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};
	};
	class body
	{
		name = "Body";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};
	};
	class avionics
	{
		name = "Avionics";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class gear
	{
		name = "Gear";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class winch
	{
		name = "Winch";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class hull
	{
		name = "Hull";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class missiles
	{
		name = "Missiles";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class turret
	{
		name = "Turret";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class gun
	{
		name = "Gun";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class transmission
	{
		name = "Transmission";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class stabilizer
	{
		name = "Stabilizer";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class rotor
	{
		name = "Rotor";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class track
	{
		name = "Totor";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class tail
	{
		name = "Tail";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class port
	{
		name = "Port";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class blade
	{
		name = "Blade";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class starter
	{
		name = "Starter";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class door
	{
		name = "Door";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class elevator
	{
		name = "Elevator";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class light
	{
		name = "Light";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class chest
	{
		name = "Chest";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class pelvis
	{
		name = "Pelvis";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class hand
	{
		name = "Hand";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class leg
	{
		name = "Leg";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class head
	{
		name = "Head";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class flap
	{
		name = "Flap";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class hatch
	{
		name = "Hatch";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class ramp
	{
		name = "Ramp";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class diaphragm
	{
		name = "Diaphragm";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class abdomen
	{
		name = "Abdomen";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class neck
	{
		name = "Neck";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
	class arm
	{
		name = "Arm";
		icon = "\a3\ui_f\data\igui\cfg\weaponcursors\gl_gs.paa";
		class Actions: 3DDefaultActions {};		
	};
};