class dsr_objects_stockade_tower: DSR_objects_base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Tower";
	model = "\dsr_objects\stockade_tower\dsr_stockade_tower.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	ladders[] = { {"Start", "End" } };
	mass = 1500;
};
class dsr_objects_stockade_tower_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Stockade Tower Preview";
	model = "\dsr_objects\stockade_tower\dsr_stockade_tower_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};