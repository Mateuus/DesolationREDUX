class DSR_objects_Storage_Small: DSR_Crate_Base
{
	scope = 2;
	scopeCurator = 2;
	displayName = "Wooden crate small";
	model = "\dsr_objects\storage_wood\dsr_storage_small.p3d";
	maximumLoad = 1000;
	editorSubcategory = "DSR_Objects";
};
class DSR_objects_Storage_Large: DSR_Crate_Base
{
	scope = 2;
	scopeCurator = 2;
	displayName = "Wooden crate large";
	model = "\dsr_objects\storage_wood\dsr_storage_large.p3d";
	maximumLoad = 2000;
	editorSubcategory = "DSR_Objects";
};
class dsr_objects_Storage_Small_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Wooden crate small Preview";
	model = "\dsr_objects\storage_wood\dsr_storage_small_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};
class dsr_objects_Storage_Large_preview: DSR_Crate_Base
{
	editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Axe_F.jpg";
	scope = 2;
	scopeCurator = 2;
	displayName = "Wooden crate large Preview";
	model = "\dsr_objects\storage_wood\dsr_storage_large_preview.p3d";
	icon = "iconObject_4x1";
	editorSubcategory = "DSR_Objects";
	maximumLoad = 5000;
	hiddenSelections[] = {"camo1"}; ///we want to allow changing the color of this selection
	hiddenSelectionsTextures[]=
	{
		"#(argb,2,2,1)color(0.7,0.93,0,0.6)"
	};
};