class dsr_objects_stockade_gate: DSR_objects_base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Gate";
	model = "\dsr_objects\stockade_gate\dsr_stockade_gate.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	mass = 150;
	class AnimationSources
	{
		// Animation sources for doors
		class Door_1_source
		{
			source = user; // "user" = custom source = not controlled by some engine value
			initPhase = 0; // Initial value of animations based on this source
			animPeriod = 1; // Coefficient for duration of change of this animation
			sound = "GenericDoorsSound"; /// Selects sound class from CfgAnimationSourceSounds that is going to be used for sounds of doors
		};
		class Door_2_source: Door_1_source {};
	};
	class UserActions
	{
		class OpenDoor_1
		{
			displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />"; // This is displayed in the center of the screen just below crosshair. In this case it's an icon, not a text.
			displayName = "Open Door"; // Label of the action used in the action menu itself.
			position = Door_1_trigger; // Point in Memory lod in p3d around which the action is available.
			priority = 0.4; // Priority coefficient used for sorting action in the action menu.
			radius = 1.5; // Range around the above defined point in which you need to be to access the action.
			onlyForPlayer = false; // Defines if the action is available only to players or AI as well.
			condition = ((this animationPhase 'Door_1_rot') < 0.5) && ((this animationPhase 'Hitzone_2_hide') < 0.99999); // Condition for showing the action in action menu. In this case it checks if the door is closed and if the part of the house in which the door is located hasn't been destroyed yet).
			statement = ([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleOpen); // Action taken when this action is selected in the action menu. In this case it calls a function that opens the door.
		};
		class CloseDoor_1: OpenDoor_1
		{
			displayName = "Close Door";
			priority = 0.2;
			condition = ((this animationPhase 'Door_1_rot') >= 0.5) && ((this animationPhase 'Hitzone_2_hide') < 0.99999); // Checks if the door is currently open and not destroyed.
			statement = ([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleClose);
		};
		class OpenDoor_2: OpenDoor_1
		{
			position = Door_2_trigger;
			condition = ((this animationPhase 'Door_2_rot') < 0.5) && ((this animationPhase 'Hitzone_2_hide') < 0.99999);
			statement = ([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleOpen);
		};
		class CloseDoor_2: CloseDoor_1
		{
			position = Door_2_trigger;
			condition = ((this animationPhase 'Door_2_rot') >= 0.5) && ((this animationPhase 'Hitzone_2_hide') < 0.99999);
			statement = ([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleClose);
		};
	};
	// Here are references binding specific positions in Path lod in p3d to specific actions from "class UserActions" for AI to know when to use which doors. The actionBegin# and ActionEnd# is a hardcoded naming system.
	actionBegin1 = OpenDoor_1;
	actionEnd1 = OpenDoor_1;
	actionBegin2 = OpenDoor_2;
	actionEnd2 = OpenDoor_2;
	// Amount of doors of this house; a parameter for easy processing of all doors on different houses by scripts.
	numberOfDoors = 2;
};
class dsr_objects_stockade_gate_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Gate Preview";
	model = "\dsr_objects\stockade_gate\dsr_stockade_gate_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};