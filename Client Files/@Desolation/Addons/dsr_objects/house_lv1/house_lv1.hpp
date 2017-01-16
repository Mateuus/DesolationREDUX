class DSR_objects_House_lv1: DSR_Crate_Base
{
	displayName = "House Level 1";
	scope = 2;
	scopeCurator = 2;
	model = "\dsr_objects\House_lv1\dsr_playerhouse_lv1.p3d";
	maximumLoad = 2000;
	editorSubcategory = "DSR_Objects";
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
		class Door_3_source: Door_1_source {};
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
		class OpenDoor_3: OpenDoor_1
		{
			position = Door_3_trigger;
			condition = ((this animationPhase 'Door_3_rot') < 0.5) && ((this animationPhase 'Hitzone_3_hide') < 0.99999);
			statement = ([this, 'Door_3_rot'] call BIS_fnc_DoorNoHandleOpen);
		};
		class CloseDoor_3: CloseDoor_1
		{
			position = Door_3_trigger;
			condition = ((this animationPhase 'Door_3_rot') >= 0.5) && ((this animationPhase 'Hitzone_3_hide') < 0.99999);
			statement = ([this, 'Door_3_rot'] call BIS_fnc_DoorNoHandleClose);
		};
	};
	// Here are references binding specific positions in Path lod in p3d to specific actions from "class UserActions" for AI to know when to use which doors. The actionBegin# and ActionEnd# is a hardcoded naming system.
	actionBegin1 = OpenDoor_1;
	actionEnd1 = OpenDoor_1;
	actionBegin2 = OpenDoor_2;
	actionEnd2 = OpenDoor_2;
	actionBegin3 = OpenDoor_3;
	actionEnd3 = OpenDoor_3;
	// Amount of doors of this house; a parameter for easy processing of all doors on different houses by scripts.
	numberOfDoors = 3;
};