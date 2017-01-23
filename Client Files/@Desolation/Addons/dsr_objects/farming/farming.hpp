class dsr_objects_woodplot_small: DSR_objects_base {
	displayName = "Farming Plot(Small)";
	model = "dsr_objects\farming\dsr_woodplot_small.p3d";
	//editorPreview = ""
	icon = "iconObject";
	faction = "Empty";
	scope = 2;
};
class dsr_objects_woodplot_med: DSR_objects_base {
	displayName = "Farming Plot(Medium)";
	model = "dsr_objects\farming\dsr_woodplot_med.p3d";
	//editorPreview = ""
	icon = "iconObject";
	faction = "Empty";
	scope = 2;
};
class dsr_objects_woodplot_large: DSR_objects_base {
	displayName = "Farming Plot (Large)";
	model = "dsr_objects\farming\dsr_woodplot_large.p3d";
	//editorPreview = ""
	icon = "iconObject";
	faction = "Empty";
	scope = 2;
};
class dsr_objects_woodplot_small_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Farming Plot Small Preview";
	model = "\dsr_objects\farming\dsr_woodplot_small_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};
class dsr_objects_woodplot_med_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Farming Plot Med Preview";
	model = "\dsr_objects\farming\dsr_woodplot_med_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};
class dsr_objects_woodplot_large_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Farming Plot Large Preview";
	model = "\dsr_objects\farming\dsr_woodplot_large_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};