class dsr_objects_stockade_rampart: DSR_objects_base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Rampart";
	model = "\dsr_objects\stockade_rampart\dsr_stockade_rampart.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	mass = 150;
};
class dsr_objects_stockade_rampart_2: dsr_objects_stockade_rampart
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	displayName = "Stockade Rampart No Ramp";
	model = "\dsr_objects\stockade_rampart\dsr_stockade_rampart_2.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
};
class dsr_objects_stockade_rampart_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Rampart Preview";
	model = "\dsr_objects\stockade_rampart\dsr_stockade_rampart_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};
class dsr_objects_stockade_rampart_2_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Rampart NO RAMP Preview";
	model = "\dsr_objects\stockade_rampart\dsr_stockade_rampart_2_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};