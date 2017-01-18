class dsr_objects_stockade_wall: DSR_Objects_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Wall";
	model = "\dsr_objects\stockade_wall\dsr_stockade_wall.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	mass = 150;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"dsr_objects\stockade_wall\data\dsr_wood_old_co.paa"
	};
};
class dsr_objects_stockade_wall_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Wall Preview";
	model = "\dsr_objects\stockade_wall\dsr_stockade_wall_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	mass = 150;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};