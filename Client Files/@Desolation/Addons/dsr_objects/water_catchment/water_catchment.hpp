class dsr_objects_water_catchment: DSR_objects_base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Water-Catchment";
	model = "\dsr_objects\water_catchment\water_catchment.p3d";
	icon = "iconObject_4x1";
	mass = 150;
};
class dsr_objects_water_catchment_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Water-Catchment Preview";
	model = "\dsr_objects\water_catchment\water_catchment_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};